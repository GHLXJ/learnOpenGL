#include "Mesh.h"
#include<GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<iostream>

Mesh::Mesh(float vertexs[])
{
	this->vertexs.resize(36);
	memcpy(&(this->vertexs[0]), vertexs,36 * 8 * sizeof(float));

	setMesh();
}

Mesh::Mesh(std::vector<vertex> vertexs, std::vector<unsigned int> indices, std::vector<texture> textures)
{
	this->vertexs = vertexs;
	this->indices = indices;
	this->textures = textures;

	setMesh();
}

void Mesh::Draw(Shader* shader, Material* material)
{
	for (unsigned int i = 0; i < textures.size(); i++)
	{
		//贴图
		if (textures[i].type == "texture_diffuse") {
			glActiveTexture(GL_TEXTURE0 + Shader::Diffuse);
			glBindTexture(GL_IMAGE_2D, textures[i].id);
			material->setUniform1i("material.tex_diffuse", Shader::Diffuse);
		}
		else if (textures[i].type == "texture_specular") {
			glActiveTexture(GL_TEXTURE0 + Shader::Specular);
			glBindTexture(GL_IMAGE_2D, textures[i].id);
			material->setUniform1i("material.tex_specular", Shader::Specular);
		}
		//std::cout << textures[i].path.data() << std::endl;
	}
	shader->use();
	//set vertex and fragment Shader uniform
	//Set Model matrix
	glUniformMatrix4fv(glGetUniformLocation(shader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f))));
	//set lightColor objColor
	glUniform3f(glGetUniformLocation(shader->ID,"objColor"),1.0f,1.0f,1.0f);
	//set material Uniform
	material->setUniform1i("material.diffuse_tex", Shader::Diffuse);
	material->setUniform1i("material.specular_tex", Shader::Specular);
	material->setUniform1f("material.shininess", material->shininess);
	//Bind VAO
	glBindVertexArray(VAO);
	//Draw Call
	//个人猜测:glDrawArrays在VAO和Shader之间起到作用，具体什么作用有多种猜测
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	//解绑
	glBindVertexArray(0);
	glActiveTexture(GL_TEXTURE0);
}

void Mesh::setMesh()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * vertexs.size(), &vertexs[0], GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(3 * sizeof(GL_FLOAT)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(6 * sizeof(GL_FLOAT)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
}
