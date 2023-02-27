#include "Model.h"
Model::Model(std::string path)
{
	loadModel(path);
}

void Model::Draw(Shader* shader, Material* material)
{
	for (unsigned int i = 0; i < meshes.size(); i++)
	{
		meshes[i].Draw(shader, material);
	}
}

void Model::loadModel(std::string path)
{
	//importer:Assimp主要功能类
	Assimp::Importer importer;
	//创建scene节点
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
		std::cout << "ERROR:ASSIMP::" << importer.GetErrorString() << std::endl;
		return;
	}
	directory = path.substr(0, path.find_last_of('\\'));
	processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode* node, const aiScene* scene)
{
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* currMesh = scene->mMeshes[node->mMeshes[i]];
		meshes.push_back(processMesh(currMesh, scene));
	}
	for (unsigned int i = 0; i < node->mNumChildren; i++) {
		processNode(node->mChildren[i], scene);
	}
}

Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
	std::vector<vertex> tempVertices;
	std::vector<unsigned int> tempIndices;
	std::vector<texture> tempTextures;
	
	for (unsigned i = 0; i < mesh->mNumVertices; i++)
	{
		vertex tempVertex;
		tempVertex.position.x = mesh->mVertices[i].x;
		tempVertex.position.y = mesh->mVertices[i].y;
		tempVertex.position.z = mesh->mVertices[i].z;
		
		tempVertex.normal.x = mesh->mNormals[i].x;
		tempVertex.normal.y = mesh->mNormals[i].y;
		tempVertex.normal.z = mesh->mNormals[i].z;
		if (mesh->mTextureCoords[0]) {
			tempVertex.TexCoords.x = mesh->mTextureCoords[0][i].x;
			tempVertex.TexCoords.y = mesh->mTextureCoords[0][i].y;
		}
		else {
			tempVertex.TexCoords = glm::vec2(0, 0);
		}
		tempVertices.push_back(tempVertex);
	}
	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		for (unsigned int j = 0; j < mesh->mFaces[i].mNumIndices; j++) {
			tempIndices.push_back(mesh->mFaces[i].mIndices[j]);
		}
	}
	if (mesh->mMaterialIndex >= 0) {
		//获得material
		aiMaterial* material= scene->mMaterials[mesh->mMaterialIndex];
		std::vector<texture> diffTexs = loadMaterialTexture(material,aiTextureType_DIFFUSE,"texture_diffuse");
		tempTextures.insert(tempTextures.end(),diffTexs.begin(), diffTexs.end());
		std::vector<texture> specuTexs = loadMaterialTexture(material, aiTextureType_SPECULAR, "texture_specular");
		tempTextures.insert(tempTextures.end(), specuTexs.begin(), specuTexs.end());
	}

	return Mesh(tempVertices,tempIndices, tempTextures);
}

std::vector<texture> Model::loadMaterialTexture(aiMaterial* material, aiTextureType type, std::string texClass)
{
	std::vector<texture> textures;
	for (unsigned int i = 0; i < material->GetTextureCount(type); i++)
	{
		aiString str;
		//使用GetTexture获取每个纹理的文件位置:只是每个纹理的文件的名称和文件格式 abc.xyz
		material->GetTexture(type,i,&str);
		//优化,加载纹理并不是一个开销不大的操作
		bool skip = false;
		for (unsigned int j = 0; j < texture_hasLoaded.size(); j++) {
			if (std::strcmp(texture_hasLoaded[j].path.c_str(), std::string(str.C_Str()).c_str())==0) {
				textures.push_back(texture_hasLoaded[j]);
				skip = true;
				break;
			}
		}
		if (!skip) {
			texture temptexture;
			temptexture.id = TextureFromFile(str.C_Str(), directory);
			temptexture.type = texClass.c_str();
			temptexture.path = str.C_Str();
			textures.push_back(temptexture);
			texture_hasLoaded.push_back(temptexture);
		}
	}
	return textures;
}

unsigned int Model::TextureFromFile(const char* path, std::string directory, bool gamma )
{
	std::string filename = std::string(path);
	filename = directory + '\\' + filename;

	unsigned int textureID;
	glGenTextures(1, &textureID);

	int width, height, nrComponents;
	unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
	if (data)
	{
		//format默认值
		GLenum format = GL_RGB;
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;
		glActiveTexture(GL_TEXTURE0);
		// 其实可以不指定要绑定的texture_2d通道,这里只需要返回textureID
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		//纹理过滤
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		//绑定默认
		glBindTexture(GL_TEXTURE_2D, 0);
		stbi_image_free(data);
	}
	else
	{
		std::cout << "Texture failed to load at path: " << path << std::endl;
		stbi_image_free(data);
	}
	return textureID;
}
