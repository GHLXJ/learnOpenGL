#version 330 core

//layout (location = 0) in vec3 aPos;
layout (location = 3) in vec3 aPos;
layout(location = 1)in vec3 aColor;
layout(location = 2)in vec2 aTexCoord;
layout(location = 4)in vec3 aNormal;
//uniform mat4 transform;
uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 proMat;

out vec4 vectexColor;
out vec2 TexCoord;
out vec3 normal;
out vec3 fragPos;

void main(){
	//mat4 * vec4Ë³Ðò²»ÄÜµßµ¹
	gl_Position = proMat * viewMat * modelMat * vec4(aPos.x, aPos.y, aPos.z, 1.0) ;
	vectexColor = vec4(aColor.x,aColor.y,aColor.z,1.0);
	TexCoord = aTexCoord;
	fragPos = vec3(modelMat *vec4(aPos.x, aPos.y, aPos.z, 1.0));
	normal = normalize(mat3(transpose(inverse(modelMat))) * aNormal);

}