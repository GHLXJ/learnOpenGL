#pragma once
#include<string>
#include<iostream>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
//与计算切线和次切线有关
#include <assimp/postprocess.h>
#include"Mesh.h"
#include<vector>
#include<glm/glm.hpp>
#include"Shader.h"
#include"Material.h"
#include"GL/glew.h"
#include "stb_image.h"
class Model
{
public:
	Model(std::string path);
	void Draw(Shader* shader, Material* material);
	std::vector<Mesh> meshes;
	std::string directory;
private:
	void loadModel(std::string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<texture> loadMaterialTexture(aiMaterial* material,aiTextureType type,std::string texClass);
	unsigned int TextureFromFile(const char* c_str, std::string directory, bool gamma = false);
	std::vector<texture> texture_hasLoaded;
};

