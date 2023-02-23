#pragma once
#include<glm/glm.hpp>
#include<string>
#include<vector>
#include"Shader.h"
#include"Material.h"

struct vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 TexCoords;
};
struct texture {
	unsigned int id;
	std::string type;
	std::string path;
};
class Mesh
{
public:
	Mesh(float vertexs[]);
	Mesh(std::vector<vertex> vertexs,std::vector<unsigned int> indices,std::vector<texture> textures);
	std::vector<vertex> vertexs;
	//EBO索引
	std::vector<unsigned int> indices;
	std::vector<texture> textures;
	void Draw(Shader* shader , Material* material);
private:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	//构造函数内部调用
	void setMesh();
};

