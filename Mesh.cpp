#include "Mesh.h"
#include<GL/glew.h>

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
		if (textures[i].type == "texture_diffuse") {
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_IMAGE_2D, textures[i].id);
			material->setUniform1i("material.tex_diffuse", 0);
		}
		else if (textures[i].type == "texture_specular") {
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_IMAGE_2D, textures[i].id);
			material->setUniform1i("material.tex_specular", 1);
		}
	}
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	//½â°ó
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
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(3*sizeof(GL_FLOAT)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(6 * sizeof(GL_FLOAT)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
}
