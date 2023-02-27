#include "Material.h"
#include<GL/glew.h>
Material::Material(Shader* _shader, glm::vec3 _ambient, glm::vec3 _diffuse, glm::vec3 _specular, float _shininess):
	shader(_shader),ambient(_ambient),diffuse(_diffuse),specular(_specular),shininess(_shininess)
{

}

Material::Material(Shader* _shader, glm::vec3 _ambient, unsigned int _diffuse_tex, unsigned int _specular_tex, float _shininess):
	shader(_shader), ambient(_ambient), diffuse_tex(_diffuse_tex), specular_tex(_specular_tex), shininess(_shininess)
{

}

void Material::setUniform3f(const char* paramNameString, glm::vec3 param)
{
	//shader->use();
	glUniform3f(glGetUniformLocation(shader->ID,paramNameString),param.x,param.y,param.z);
}

void Material::setUniform1f(const char* paramNameString, float param)
{
	//shader->use();
	glUniform1f(glGetUniformLocation(shader->ID, paramNameString), param);
}

void Material::setUniform1i(const char* paraNameString, unsigned int param)
{
	//shader->use();
	glUniform1i(glGetUniformLocation(shader->ID,paraNameString),param);
}
