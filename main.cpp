#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include"Shader.h"
#include"Model.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include"Camera.h"
#include"Material.h"
#include"LightDir.h"
#include"LightPoint.h"
#include"LightSpot.h"
#include"Mesh.h"
//#include"Model.h"


#pragma region Model Data
float vertices[] = {
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 0.0f,  0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
		-0.5f,  0.5f, -0.5f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,

		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 0.0f,  0.0f,  0.0f,  1.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f,  0.0f,  0.0f,  1.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f,  0.0f,  0.0f,  1.0f,
		-0.5f,  0.5f,  0.5f, 0.0f, 1.0f,  0.0f,  0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f,  0.0f,  0.0f,  1.0f,

		-0.5f,  0.5f,  0.5f, 1.0f, 0.0f,  -1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f,  -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,  -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,  -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f,  -1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f, 1.0f, 0.0f,  -1.0f,  0.0f,  0.0f,

		 0.5f,  0.5f,  0.5f, 1.0f, 0.0f,  1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f, 0.0f, 1.0f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f, 0.0f, 1.0f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f,  0.5f, 0.0f, 0.0f,  1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 0.0f,  1.0f,  0.0f,  0.0f,

		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 0.0f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 0.0f,  0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f,  0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,  0.0f, -1.0f,  0.0f,

		-0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  1.0f,  0.0f
};

glm::vec3 cubePositions[] = {
  glm::vec3(0.0f,  0.0f,  0.0f),
  glm::vec3(2.0f,  5.0f, -15.0f),
  glm::vec3(-1.5f, -2.2f, -2.5f),
  glm::vec3(-3.8f, -2.0f, -12.3f),
  glm::vec3(2.4f, -0.4f, -3.5f),
  glm::vec3(-1.7f,  3.0f, -7.5f),
  glm::vec3(1.3f, -2.0f, -2.5f),
  glm::vec3(1.5f,  2.0f, -2.5f),
  glm::vec3(1.5f,  0.2f, -1.5f),
  glm::vec3(-1.3f,  1.0f, -1.5f)
};
#pragma endregion
#pragma region Camera Declare
//�����
Camera camera(glm::vec3(0, 0, 3.0f), glm::radians(15.0f), glm::radians(180.0f), glm::vec3(0, 1.0f, 0));
#pragma endregion
#pragma region Input Declare
double lastXpos;
double lastYpos;
bool firstMouse = true;

void processInput(GLFWwindow* window);
//�ǵ�û��Ļ��������������ʽ�����Զ�����xPos,yPos
void mouse_callback(GLFWwindow* window, double xPos, double yPos);
#pragma endregion
unsigned int LoadImageToGPU(const char* fileName, GLint internalFormat, GLenum format, int textureSlot);
int main(int argc,char* argv[]) {
	#pragma region Open a Window
	//glfw��ʼ��
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//open GLFW window 
	GLFWwindow* window = glfwCreateWindow(800, 600, "my OpenGL game", nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "error,window is null"<<std::endl;
		glfwTerminate();
		return -1;
	}
	//���õ�ǰ�̵߳���Ҫ������
	glfwMakeContextCurrent(window);
	//�������ģʽ
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, mouse_callback);
	//glew ��ʼ��
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		std::cout << "error,glewInit error!";
		glfwTerminate();
		return 0;
	}
	glViewport(0, 0, 800, 600);
#pragma endregion
	#pragma region Init three kinds light
	//ƽ�й�
	LightDir lightDir(glm::vec3(10.0f,10.0f,5.0f),
		glm::vec3(glm::radians(45.0f), glm::radians(180.0f), 0),
		glm::vec3(1.0f,1.0f,1.0f)
		);
	//���Դ
	LightPoint lightPoint(glm::vec3(1.0f, 2.0f, 0),
		glm::vec3(glm::radians(45.0f), 0, 0),
		glm::vec3(1.0f, 1.0f, 1.0f)
	);
	//�۹��
	LightSpot lightSpot(glm::vec3(0, 1.0f, -0.5f),
		glm::vec3(glm::radians(90.0f), 0, 0),
		glm::vec3(1.0f, 1.0f, 1.0f)
	);
#pragma endregion
	#pragma region Init Shader Program
	//Shader����
	Shader* myShader = new Shader("vertexSource.vert", "fragmentSource.frag");
#pragma endregion
	#pragma region Init Material
	//unsigned int _diffuse_tex, unsigned int _specular_tex������,����GL_TEXTURE0 + Shader::Diffuse
	//��GL_TEXTURE0 + Shader::Specular
	Material* material = new Material(myShader,
		glm::vec3(1.0f, 1.0f, 1.0f),
		LoadImageToGPU("container2.png",GL_RGBA,GL_RGBA,Shader::Diffuse),
		LoadImageToGPU("container2_specular.png", GL_RGBA, GL_RGBA, Shader::Specular), 
		32.0f
	);
#pragma endregion
	//������Ȳ���
	glEnable(GL_DEPTH_TEST);
	//������Ȼ���ֻ��
	//glDepthMask(GL_FALSE);
	//������Ȳ��ԱȽϷ�
	//glDepthFunc(GL_ALWAYS);
	glDepthFunc(GL_LESS);
	//����ģ�����

	#pragma region Init Model
	//Mesh mesh(vertices);
	std::string path = argv[0];
	Model model(path.substr(0,path.find_last_of('\\'))+"\\model\\nanosuit.obj");
	//std::cout << path.substr(0, path.find_last_of('\\')) + "\\model\\nanosuit.obj";
#pragma endregion
	//����ͼƬǰ��תY��
	stbi_set_flip_vertically_on_load(true);
	#pragma region Prepare MVP matrices
	//ģ�;��󣬹۲����ͶӰ����
	glm::mat4 modelMat;
	glm::mat4 viewMat;
	glm::mat4 proMat;
	proMat = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
#pragma endregion
	//ѭ���壬�жϴ����Ƿ�ر�
	while (!glfwWindowShouldClose(window)) {
		//�ӳٴ�������
		processInput(window);
		camera.ProcessKeyboardMovement();
		//�����������Ȼ��壬��Ⱦ��ɫ
		glClearColor(0,0.5f,0.5f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		//set viewMatrice
		viewMat = camera.GetViewMatrix();
		//for (int i = 0; i < 1; i++) {
		//	//Set Model matrix
		//	modelMat = glm::translate(glm::mat4(1.0f), cubePositions[i]);
		//	// Set View and Projection Matrices here if you want.
		//	// 
		//	
		//	//Set Material -> Shader Program
		//	myShader->use();
		//	//�ٴ�ָ��GL_TEXTURE_2D����������GL_TEXTURE_2D:Set Material -> Textures
		//	glActiveTexture(GL_TEXTURE0 + Shader::Diffuse);
		//	glBindTexture(GL_TEXTURE_2D, material->diffuse_tex);
		//	glActiveTexture(GL_TEXTURE0 + Shader::Specular);
		//	glBindTexture(GL_TEXTURE_2D, material->specular_tex);
		//	//set lightColor objColor
		//	glUniform3f(glGetUniformLocation(myShader->ID,"objColor"),1.0f,1.0f,1.0f);
		//	//������
		//	glUniform3f(glGetUniformLocation(myShader->ID, "ambientColor"), 0.2f, 0.2f, 0.2f);
		//	//Set vertexShader -> Uniforms
		//	glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat));
		//	glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		//	glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "proMat"), 1, GL_FALSE, glm::value_ptr(proMat));
		//	glUniform3f(glGetUniformLocation(myShader->ID, "eyes"), camera.Position.x, camera.Position.y, camera.Position.z);
		//	//ƽ�й�
		//	glUniform3f(glGetUniformLocation(myShader->ID,"lightDir.dirToLight"), lightDir.lightDirection.x, lightDir.lightDirection.y, lightDir.lightDirection.z);
		//	glUniform3f(glGetUniformLocation(myShader->ID, "lightDir.color"), lightDir.color.x, lightDir.color.y, lightDir.color.z);
		//	//���Դ
		//	glUniform3f(glGetUniformLocation(myShader->ID, "lightPoint.position"), lightPoint.position.x, lightPoint.position.y, lightPoint.position.z);
		//	glUniform3f(glGetUniformLocation(myShader->ID, "lightPoint.color"), lightPoint.color.x, lightPoint.color.y, lightPoint.color.z);
		//	glUniform1f(glGetUniformLocation(myShader->ID, "lightPoint.constant"), lightPoint.constant);
		//	glUniform1f(glGetUniformLocation(myShader->ID, "lightPoint.linear"), lightPoint.linear);
		//	glUniform1f(glGetUniformLocation(myShader->ID, "lightPoint.quadratic"), lightPoint.quadratic);
		//	//�۹��
		//	glUniform3f(glGetUniformLocation(myShader->ID, "lightSpot.position"), lightSpot.position.x, lightSpot.position.y, lightSpot.position.z);
		//	glUniform3f(glGetUniformLocation(myShader->ID, "lightSpot.dirToLight"), lightSpot.lightDirection.x, lightSpot.lightDirection.y, lightSpot.lightDirection.z);
		//	glUniform3f(glGetUniformLocation(myShader->ID, "lightSpot.color"), lightSpot.color.x, lightSpot.color.y, lightSpot.color.z);
		//	glUniform1f(glGetUniformLocation(myShader->ID, "lightSpot.cosPhyInner"), lightSpot.cosPhyInner);
		//	glUniform1f(glGetUniformLocation(myShader->ID, "lightSpot.cosPhyOuter"), lightSpot.cosPhyOuter);
		//	//set material Uniform
		//	//material->setUniform1i("material.diffuse_tex", Shader::Diffuse);
		//	//material->setUniform1i("material.specular_tex", Shader::Specular);
		//	material->setUniform1f("material.shininess",material->shininess);
		//	//��VAO,EBO֮ǰ���ڴ�VAO�ϣ����Բ����ٰ�:Set Model
		//	//glBindVertexArray(VAO);
		//	//Draw Call
		//	//���˲²�:glDrawArrays��VAO��Shader֮�������ã�����ʲô�����ж��ֲ²�
		//	//glDrawArrays(GL_TRIANGLES, 0, 36);
		//	//mesh.Draw(myShader,material);
		//	model.Draw(myShader, material);
		//}


		for (int i = 0; i < 1; i++) {
			//������
			glUniform3f(glGetUniformLocation(myShader->ID, "ambientColor"), 0.2f, 0.2f, 0.2f);
			//Set vertexShader -> Uniforms
			glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat));
			glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
			glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "proMat"), 1, GL_FALSE, glm::value_ptr(proMat));
			glUniform3f(glGetUniformLocation(myShader->ID, "eyes"), camera.Position.x, camera.Position.y, camera.Position.z);
			//ƽ�й�
			glUniform3f(glGetUniformLocation(myShader->ID,"lightDir.dirToLight"), lightDir.lightDirection.x, lightDir.lightDirection.y, lightDir.lightDirection.z);
			glUniform3f(glGetUniformLocation(myShader->ID, "lightDir.color"), lightDir.color.x, lightDir.color.y, lightDir.color.z);
			//���Դ
			glUniform3f(glGetUniformLocation(myShader->ID, "lightPoint.position"), lightPoint.position.x, lightPoint.position.y, lightPoint.position.z);
			glUniform3f(glGetUniformLocation(myShader->ID, "lightPoint.color"), lightPoint.color.x, lightPoint.color.y, lightPoint.color.z);
			glUniform1f(glGetUniformLocation(myShader->ID, "lightPoint.constant"), lightPoint.constant);
			glUniform1f(glGetUniformLocation(myShader->ID, "lightPoint.linear"), lightPoint.linear);
			glUniform1f(glGetUniformLocation(myShader->ID, "lightPoint.quadratic"), lightPoint.quadratic);
			//�۹��
			glUniform3f(glGetUniformLocation(myShader->ID, "lightSpot.position"), lightSpot.position.x, lightSpot.position.y, lightSpot.position.z);
			glUniform3f(glGetUniformLocation(myShader->ID, "lightSpot.dirToLight"), lightSpot.lightDirection.x, lightSpot.lightDirection.y, lightSpot.lightDirection.z);
			glUniform3f(glGetUniformLocation(myShader->ID, "lightSpot.color"), lightSpot.color.x, lightSpot.color.y, lightSpot.color.z);
			glUniform1f(glGetUniformLocation(myShader->ID, "lightSpot.cosPhyInner"), lightSpot.cosPhyInner);
			glUniform1f(glGetUniformLocation(myShader->ID, "lightSpot.cosPhyOuter"), lightSpot.cosPhyOuter);
			model.Draw(myShader, material);
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	//�����˳�
	glfwTerminate();
	return 0;
}

#pragma region Input Function Declare
void processInput(GLFWwindow* window) {
	if(glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS)
		glfwSetWindowShouldClose(window,true);
	if (glfwGetKey(window, GLFW_KEY_W)) {
		camera.speedZ = 1.0f;
	}
	else if(glfwGetKey(window, GLFW_KEY_S)){
		camera.speedZ = -1.0f;
	}
	else {
		camera.speedZ = 0;
	}
	if (glfwGetKey(window, GLFW_KEY_D)) {
		camera.speedX = 1.0f;
	}
	else if (glfwGetKey(window, GLFW_KEY_A)) {
		camera.speedX = -1.0f;
	}
	else {
		camera.speedX = 0;
	}
	if (glfwGetKey(window, GLFW_KEY_Q)) {
		camera.speedY = 1.0f;
	}
	else if (glfwGetKey(window, GLFW_KEY_E)) {
		camera.speedY = -1.0f;
	}
	else {
		camera.speedY = 0;
	}
}

void mouse_callback(GLFWwindow* window, double xPos, double yPos) {
	if (firstMouse == true) {
		lastXpos = xPos;
		lastYpos = yPos;
		firstMouse = false;
	} 
	double deltaX, deltaY; 
	deltaX = xPos - lastXpos;
	deltaY = yPos - lastYpos;
	lastXpos = xPos;
	lastYpos = yPos;
	camera.ProcessMouseMovement(deltaX, deltaY);
}
#pragma endregion
unsigned int  LoadImageToGPU(const char* fileName, GLint internalFormat, GLenum format, int textureSlot) {
	unsigned int TexBuffer;
	glGenTextures(1, &TexBuffer);
	glActiveTexture(GL_TEXTURE0 + textureSlot);
	glBindTexture(GL_TEXTURE_2D, TexBuffer);
	int width, height, nrChannels;
	unsigned char* data = stbi_load(fileName, &width, &height, &nrChannels, 0);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "load texture to TexBufferA error!" << std::endl;
	}
	stbi_image_free(data);
	return TexBuffer;
}