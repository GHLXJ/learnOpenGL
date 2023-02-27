#version 330 core

out vec4 FragColor;
in vec2 TexCoord;
in vec3 normal;
in vec3 fragPos;
//lightColor objColor
uniform vec3 objColor;
uniform vec3 ambientColor;
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
//定向光(平行光)
struct LightDir{
	vec3 dirToLight;
	vec3 color;
};
uniform LightDir lightDir;
vec3 CalcDirLight(){
	vec3 result;
	//diffuse
	float diffuseIntensity = max(dot(normalize(lightDir.dirToLight),normalize(normal)),0);
	vec3 diffuse = diffuseIntensity * lightDir.color * texture(material.diffuse_tex,TexCoord).rgb;
	//specular
	vec3 R = reflect(normalize(-lightDir.dirToLight),normal);
	float specularIntensity = pow(max(dot(R,normalize(eyes - fragPos)),0),material.shininess);
	vec3 specular = specularIntensity * lightDir.color * texture(material.specular_tex,TexCoord).rgb;
	result = diffuse + specular;
	return result;
}
//点光源
struct LightPoint{
	vec3 position;
	vec3 color;
	float constant;
	float linear;
	float quadratic;
};
uniform LightPoint lightPoint;
vec3 CalcPointLight(){
	vec3 result;
	//attenuation衰减
	float dist = length(lightPoint.position - fragPos);
	float attenuation = 1.0f/(lightPoint.constant+dist*lightPoint.linear+dist*dist*lightPoint.quadratic);
	//diffuse
	float diffuseIntensity = max(dot(normalize(lightPoint.position - fragPos),normalize(normal)),0);
	vec3 diffuse = diffuseIntensity * lightPoint.color * texture(material.diffuse_tex,TexCoord).rgb;
	//specular
	//vec3 R = reflect(normalize(-lightDir.dirToLight),normal);
	vec3 R = reflect(normalize(fragPos - lightPoint.position),normal);
	float specularIntensity = pow(max(dot(R,normalize(eyes - fragPos)),0),material.shininess);
	vec3 specular = specularIntensity * lightPoint.color * texture(material.specular_tex,TexCoord).rgb;
	result = (diffuse + specular)*attenuation;
	return result;
}
//聚光灯,没有基于距离的衰减
struct LightSpot{
	vec3 position;
	vec3 dirToLight;
	vec3 color;
	float cosPhyInner;
	float cosPhyOuter;
};
uniform LightSpot lightSpot;
vec3 CalcSpotLight(){
	vec3 result;
	//spotRatio软化边缘
	float spotRatio;
	float cosThe = dot(normalize(-lightSpot.dirToLight),normalize(fragPos - lightSpot.position));
	if(cosThe>lightSpot.cosPhyInner){
		spotRatio = 1.0f;
	}
	else if(cosThe>lightSpot.cosPhyOuter){
		spotRatio = (cosThe - lightSpot.cosPhyOuter)/(lightSpot.cosPhyInner - lightSpot.cosPhyOuter );
	}
	else{
		spotRatio = 0.0f;
	}
	//diffuse
	//float diffuseIntensity = max(dot(normalize(lightDir.dirToLight),normalize(normal)),0);
	float diffuseIntensity = max(dot(normalize(lightSpot.position - fragPos),normalize(normal)),0);
	vec3 diffuse = diffuseIntensity * lightSpot.color * texture(material.diffuse_tex,TexCoord).rgb;
	//specular
	vec3 R = reflect(normalize(-lightSpot.dirToLight),normal);
	float specularIntensity =pow(max(dot(R,normalize(eyes - fragPos)),0),material.shininess);
	vec3 specular = specularIntensity * lightSpot.color * texture(material.specular_tex,TexCoord).rgb;
	result = (diffuse + specular) * spotRatio;
	return result;
}


void main() {
	//FragColor = vec4(CalcDirLight() + CalcSpotLight() + CalcSpotLight() + ambientColor * texture(material.diffuse_tex,TexCoord).rgb ,1.0f);
	FragColor = vec4(CalcDirLight() + CalcSpotLight() + CalcSpotLight(),1.0f)+ vec4(1.0f,1.0f,1.0f,1.0f) * texture(material.diffuse_tex,TexCoord);
	//depth z值当片段颜色显示
	//FragColor = vec4(vec3(gl_FragCoord.z),1.0f);
	//FragColor = vec4(1.0f,1.0f,0.2f,1.0f);
	//FragColor = vec4(CalcDirLight() + CalcSpotLight() + CalcSpotLight(),1.0f);
	//FragColor =  texture(material.diffuse_tex,TexCoord)+ texture(material.specular_tex,TexCoord);
	//FragColor =  texture(material.diffuse_tex,TexCoord);
}