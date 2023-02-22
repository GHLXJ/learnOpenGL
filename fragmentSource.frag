#version 330 core

out vec4 FragColor;
//uniform vec4 myFragColor;
in vec4 vectexColor;
in vec2 TexCoord;
in vec3 normal;
in vec3 fragPos;
uniform sampler2D ourTextureA;
uniform sampler2D ourTextureB;
//lightColor objColor
uniform vec3 objColor;
uniform vec3 ambientColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 lightDirection;
uniform vec3 eyes;

struct Material{
	vec3 ambient;
	vec3 diffuse;
	sampler2D diffuse_tex;
	vec3 specular;
	sampler2D specular_tex;
	float shininess;
};
uniform Material material;
struct LightPoint{
	float constant;
	float linear;
	float quadratic;
};
uniform LightPoint lightPoint;
struct LightSpot{
	float cosPhyInner;
	float cosPhyOuter;
};
uniform LightSpot lightSpot;

void main() {
	//diffuse
	//与入射光相反的方向向量
	//vec3 lightDir = normalize(lightPos - fragPos);//未添加平行光等光前
	//vec3 diffuseColor = lightColor * max(dot(lightDir,normal),0);
	//vec3 reflectDir = reflect(-lightDir,normal);
	//lightDir,lightPoint,lightSpot
	//lightDir
	//vec3 diffuseColor = lightColor * max(dot(lightDirection,normal),0);
	//vec3 reflectDir = reflect(-lightDirection,normal);
	//lightPoint
	//float dist = length(lightPos - fragPos);
	//float attenuation = 1.0/ (lightPoint.constant + lightPoint.linear * dist + lightPoint.quadratic * (dist * dist));
	//vec3 lightDir = normalize(lightPos - fragPos);
	//vec3 diffuseColor = lightColor * max(dot(lightDir,normal),0);
	//vec3 reflectDir = reflect(-lightDir,normal);
	//lightSpot
	vec3 lightDir = normalize(lightPos - fragPos);
	vec3 diffuseColor = lightColor * max(dot(lightDir,normal),0);
	vec3 reflectDir = reflect(-lightDir,normal);
	float cosThe = dot(normalize(-lightDirection),normalize(fragPos - lightPos));
	float spotRatio;
	if(cosThe>lightSpot.cosPhyInner){
		spotRatio = 1;
	}else if(cosThe>lightSpot.cosPhyOuter){
		spotRatio = (cosThe - lightSpot.cosPhyOuter)/(lightSpot.cosPhyInner - lightSpot.cosPhyOuter);
	}
	else{
		spotRatio = 0;
	}
	//vec3 diffuse = texture(material.diffuse_tex,TexCoord).rgb * material.diffuse * diffuseColor;
	vec3 diffuse = texture(material.diffuse_tex,TexCoord).rgb * diffuseColor;
	//specular
	vec3 eyesDir = normalize(eyes - fragPos);
	vec3 specularColor = lightColor * pow(max(dot(reflectDir,eyesDir),0),material.shininess);
	//vec3 specular = material.specular *specularColor;
	vec3 specular = texture(material.specular_tex,TexCoord).rgb *specularColor;
	vec3 ambient = material.ambient * ambientColor;
	//FragColor = glm::vec4(objColor*(ambient + diffuse + specular),1.0f)*texture(ourTextureA,TexCoord) * texture(ourTextureB,TexCoord);
	//FragColor = glm::vec4(objColor*(ambient + diffuse + specular),1.0f)* texture(ourTextureB,TexCoord);
	//FragColor = glm::vec4(objColor*(ambient + diffuse + specular),1.0f); //未添加平行光等光前
	//lightPoint
	//FragColor = glm::vec4(objColor*(ambient + (diffuse + specular)*attenuation),1.0f);
	//lightSpot
	FragColor = glm::vec4(objColor*(ambient + (diffuse + specular)*spotRatio),1.0f);

}