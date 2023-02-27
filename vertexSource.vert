#version 330 core

//加入mesh 后
layout (location = 0) in vec3 aPos;
layout(location = 1)in vec3 aNormal;
layout(location = 2)in vec2 aTexCoord;
//layout(location = ?)in vec3 aColor;

//uniform mat4 transform;
uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 proMat;

out vec4 vectexColor;
out vec2 TexCoord;
out vec3 normal;
out vec3 fragPos;

void main(){
	//mat4 * vec4顺序不能颠倒
	gl_Position = proMat * viewMat * modelMat * vec4(aPos.x, aPos.y, aPos.z, 1.0) ;
	TexCoord = aTexCoord;
	fragPos = vec3(modelMat *vec4(aPos.x, aPos.y, aPos.z, 1.0));
	normal = normalize(mat3(transpose(inverse(modelMat))) * aNormal);

}