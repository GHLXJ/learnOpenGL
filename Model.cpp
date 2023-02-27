#include "Model.h"
//#include "stb_image.h"
Model::Model(std::string path)
{
	loadModel(path);
}

void Model::Draw(Shader* shader, Material* material)
{
	/*for (unsigned int i = 0; i < meshes.size(); i++)
	{
		for (size_t j = 0; j <meshes[i].textures.size() ; j++)
		{
			std::cout << meshes[i].textures[j].path << meshes[i].textures[j].type << meshes[i].textures[j].id << std::endl;
		}
		std::cout << std::endl;
	}*/
	for (unsigned int i = 0; i < meshes.size(); i++)
	{
		meshes[i].Draw(shader, material);
	}
}

void Model::loadModel(std::string path)
{
	//importer:Assimp��Ҫ������
	Assimp::Importer importer;
	//����scene�ڵ�
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
		//std::cout << i << std::endl;
	}
	for (unsigned int i = 0; i < node->mNumChildren; i++) {
		processNode(node->mChildren[i], scene);
		//std::cout << i << std::endl;
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
		//std::cout <<":" << mesh->mMaterialIndex << std::endl;
		//���material
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
	//std::cout << material->GetTextureCount(type) << std::endl;
	for (unsigned int i = 0; i < material->GetTextureCount(type); i++)
	{
		aiString str;
		//ʹ��GetTexture��ȡÿ��������ļ�λ��:ֻ��ÿ��������ļ������ƺ��ļ���ʽ abc.xyz
		material->GetTexture(type,i,&str);
		//std::cout << str.C_Str() << std::endl;
		//�Ż�,������������һ����������Ĳ���
		bool skip = false;
		for (unsigned int j = 0; j < texture_hasLoaded.size(); j++) {
			if (std::strcmp(texture_hasLoaded[j].path.c_str(), std::string(str.C_Str()).c_str())==0) {
				//std::cout << texture_hasLoaded[j].path.data() << ":" << str.C_Str()<<std::endl;
				textures.push_back(texture_hasLoaded[j]);
				//std::cout << texture_hasLoaded[j].id <<":"<< texture_hasLoaded[j].path.data() << std::endl;
				//std::cout << "textures.push_back(texture_hasLoaded[j]);" << std::endl;
				skip = true;
				break;
			}
		}
		if (!skip) {
			texture temptexture;
			temptexture.id = TextureFromFile(str.C_Str(), directory);
			temptexture.type = texClass.c_str();
			temptexture.path = str.C_Str();
			//std::cout << temptexture.id <<":"<< temptexture .path.data()<<std::endl;
			textures.push_back(temptexture);
			texture_hasLoaded.push_back(temptexture);
		}
	}
	//std::cout << material->GetTextureCount(type) << std::endl;
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
		//formatĬ��ֵ
		GLenum format = GL_RGB;
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;
		//glActiveTexture(GL_TEXTURE0);
		//û��ָ��Ҫ�󶨵�texture_2dͨ��,����ֻ��Ҫ����textureID
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		//�������
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		//��Ĭ��
		glBindTexture(GL_TEXTURE_2D, 0);
		stbi_image_free(data);
		//glBindTexture(GL_TEXTURE_2D, 0);
	}
	else
	{
		std::cout << "Texture failed to load at path: " << path << std::endl;
		stbi_image_free(data);
	}

	return textureID;
}
