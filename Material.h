#pragma once
#include"Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Material
{
public:
	Shader* shader;
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	unsigned int diffuse_tex;
	unsigned int specular_tex;
	float shininess;
	//���ֲ�ͬ�Ĺ��캯��
	Material(Shader* _shader,glm::vec3 _ambient, glm::vec3 _diffuse, glm::vec3 specular, float shininess);
	Material(Shader* _shader, glm::vec3 _ambient, unsigned int _diffuse_tex, unsigned int _specular_tex, float _shininess);
	//��װgl������uniform�ĺ�����Ŀ���Ǽ�
	void setUniform3f(const char* paramNameString,glm::vec3 param);
	void setUniform1f(const char* paramNameString,float param);
	void setUniform1i(const char* paraNameString, unsigned int param);
};

