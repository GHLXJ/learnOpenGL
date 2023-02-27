//�汾,�������Framebuffer����
//#define GLEW_STATIC
//#include<GL/glew.h>
//#include<GLFW/glfw3.h>
//#include<iostream>
//#include"Shader.h"
//#include"Model.h"
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include"Camera.h"
//#include"Material.h"
//#include"LightDir.h"
//#include"LightPoint.h"
//#include"LightSpot.h"
//#include"Mesh.h"
////#include"Model.h"
//
//
//#pragma region Model Data
//float vertices[] = {
//		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
//		 0.5f, -0.5f, -0.5f, 1.0f, 0.0f,  0.0f,  0.0f, -1.0f,
//		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
//		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
//		-0.5f,  0.5f, -0.5f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,
//		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
//
//		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f, 1.0f, 0.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f,  0.0f,  0.0f,  1.0f,
//		-0.5f,  0.5f,  0.5f, 0.0f, 1.0f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f,  0.0f,  0.0f,  1.0f,
//
//		-0.5f,  0.5f,  0.5f, 1.0f, 0.0f,  -1.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f,  -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,  -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,  -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f,  -1.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f, 1.0f, 0.0f,  -1.0f,  0.0f,  0.0f,
//
//		 0.5f,  0.5f,  0.5f, 1.0f, 0.0f,  1.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f, 0.0f, 1.0f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f, 0.0f, 1.0f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f, 0.0f, 0.0f,  1.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f, 1.0f, 0.0f,  1.0f,  0.0f,  0.0f,
//
//		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,  0.0f, -1.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f,  0.0f, -1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f, 1.0f, 0.0f,  0.0f, -1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f, 1.0f, 0.0f,  0.0f, -1.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f,  0.0f, -1.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,  0.0f, -1.0f,  0.0f,
//
//		-0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  1.0f,  0.0f
//};
//float quadVertices[] = { // vertex attributes for a quad that fills the entire screen in Normalized Device Coordinates.
//	// positions   // texCoords
//	-1.0f,  1.0f,  0.0f, 1.0f,
//	-1.0f, -1.0f,  0.0f, 0.0f,
//	 1.0f, -1.0f,  1.0f, 0.0f,
//
//	-1.0f,  1.0f,  0.0f, 1.0f,
//	 1.0f, -1.0f,  1.0f, 0.0f,
//	 1.0f,  1.0f,  1.0f, 1.0f
//};
//glm::vec3 cubePositions[] = {
//  glm::vec3(0.0f,  0.0f,  0.0f),
//  glm::vec3(2.0f,  5.0f, -15.0f),
//  glm::vec3(-1.5f, -2.2f, -2.5f),
//  glm::vec3(-3.8f, -2.0f, -12.3f),
//  glm::vec3(2.4f, -0.4f, -3.5f),
//  glm::vec3(-1.7f,  3.0f, -7.5f),
//  glm::vec3(1.3f, -2.0f, -2.5f),
//  glm::vec3(1.5f,  2.0f, -2.5f),
//  glm::vec3(1.5f,  0.2f, -1.5f),
//  glm::vec3(-1.3f,  1.0f, -1.5f)
//};
//#pragma endregion
//#pragma region Camera Declare
////�����
//Camera camera(glm::vec3(0, 0, 3.0f), glm::radians(15.0f), glm::radians(180.0f), glm::vec3(0, 1.0f, 0));
//#pragma endregion
//#pragma region Input Declare
//double lastXpos;
//double lastYpos;
//bool firstMouse = true;
//
//void processInput(GLFWwindow* window);
////�ǵ�û��Ļ��������������ʽ�����Զ�����xPos,yPos
//void mouse_callback(GLFWwindow* window, double xPos, double yPos);
//#pragma endregion
//unsigned int LoadImageToGPU(const char* fileName, GLint internalFormat, GLenum format, int textureSlot);
//int main(int argc, char* argv[]) {
//#pragma region Open a Window
//	//glfw��ʼ��
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	//open GLFW window 
//	GLFWwindow* window = glfwCreateWindow(800, 600, "my OpenGL game", nullptr, nullptr);
//	if (window == nullptr) {
//		std::cout << "error,window is null" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	//���õ�ǰ�̵߳���Ҫ������
//	glfwMakeContextCurrent(window);
//	//�������ģʽ
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//	glfwSetCursorPosCallback(window, mouse_callback);
//	//glew ��ʼ��
//	glewExperimental = true;
//	if (glewInit() != GLEW_OK) {
//		std::cout << "error,glewInit error!";
//		glfwTerminate();
//		return 0;
//	}
//	glViewport(0, 0, 800, 600);
//	//������Ȳ���
//	glEnable(GL_DEPTH_TEST);
//	//������Ȼ���ֻ��
//	//glDepthMask(GL_FALSE);
//	//������Ȳ��ԱȽϷ�
//	//glDepthFunc(GL_ALWAYS);
//	glDepthFunc(GL_LESS);
//	//����ģ�����
//	glEnable(GL_STENCIL_TEST);
//	//����ģ�����
//	//����д�뻺��
//	glStencilMask(0xff);
//	//���ñȽ�����
//	glStencilFunc(GL_GREATER, 1, 0xff);
//	//����д������
//	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
//#pragma endregion
//#pragma region Init three kinds light
//	//ƽ�й�
//	LightDir lightDir(glm::vec3(10.0f, 10.0f, 5.0f),
//		glm::vec3(glm::radians(45.0f), glm::radians(180.0f), 0),
//		glm::vec3(1.0f, 1.0f, 1.0f)
//	);
//	//���Դ
//	LightPoint lightPoint(glm::vec3(1.0f, 2.0f, 0),
//		glm::vec3(glm::radians(45.0f), 0, 0),
//		glm::vec3(1.0f, 1.0f, 1.0f)
//	);
//	//�۹��
//	LightSpot lightSpot(glm::vec3(0, 1.0f, -0.5f),
//		glm::vec3(glm::radians(90.0f), 0, 0),
//		glm::vec3(1.0f, 1.0f, 1.0f)
//	);
//#pragma endregion
//#pragma region Init Shader Program
//	//Shader����
//	Shader* myShader = new Shader("vertexSource.vert", "fragmentSource.frag");
//	Shader* myBorderShader = new Shader("vertexBorderSource.vert", "fragmentBorderSource.frag");
//	Shader* myTestFramebufferShader = new Shader("vertexTestFramebuffer.vert", "fragmentTestFramebuffer.frag");
//#pragma endregion
//#pragma region Init Material
//	//unsigned int _diffuse_tex, unsigned int _specular_tex������,����GL_TEXTURE0 + Shader::Diffuse
//	//��GL_TEXTURE0 + Shader::Specular
//	Material* material = new Material(myShader,
//		glm::vec3(1.0f, 1.0f, 1.0f),
//		LoadImageToGPU("container2.png", GL_RGBA, GL_RGBA, Shader::Diffuse),
//		LoadImageToGPU("container2_specular.png", GL_RGBA, GL_RGBA, Shader::Specular),
//		32.0f
//	);
//#pragma endregion
//#pragma region Init Model
//	std::string path = argv[0];
//	Model model(path.substr(0, path.find_last_of('\\')) + "\\model\\nanosuit.obj");
//	unsigned int quadVAO, quadVBO;
//	glGenVertexArrays(1, &quadVAO);
//	glGenBuffers(1, &quadVBO);
//	glBindVertexArray(quadVAO);
//	glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(9);
//	glVertexAttribPointer(9, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(10);
//	glVertexAttribPointer(10, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
//	glBindVertexArray(0);
//#pragma endregion
//#pragma region Prepare MVP matrices
//	//ģ�;��󣬹۲����ͶӰ����
//	glm::mat4 modelMat;
//	glm::mat4 viewMat;
//	glm::mat4 proMat;
//	proMat = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
//#pragma endregion
//#pragma region Create My FrameBuffer
//	unsigned int fbo;
//	glGenFramebuffers(1, &fbo);
//	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
//	//����������
//	unsigned int fbo_texture;
//	glGenTextures(1, &fbo_texture);
//	//�󶨵�GL_TEXTURE2D
//	glBindTexture(GL_TEXTURE_2D, fbo_texture);
//	//Ϊfbo_texture�����ڴ�
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 800.0f, 600.0f, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
//	//�����������
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	//������fbo_texture�����
//	glBindTexture(GL_TEXTURE_2D, 0);
//	//����������֡�����
//	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fbo_texture, 0);
//
//	//������Ⱦ���帽��
//	unsigned int rbo;
//	glGenRenderbuffers(1, &rbo);
//	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
//	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 800, 600);
//	glBindRenderbuffer(GL_RENDERBUFFER, 0);
//	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
//
//	//���֡����������
//	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
//		std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
//		return -1;
//	}
//	//���ǰ֡���壬�󶨵�Ĭ��֡����
//	glBindFramebuffer(GL_FRAMEBUFFER, 0);
//#pragma endregion
//	//����ͼƬǰ��תY��
//	stbi_set_flip_vertically_on_load(true);
//	//ѭ���壬�жϴ����Ƿ�ر�
//	while (!glfwWindowShouldClose(window)) {
//		//�ӳٴ�������
//		processInput(window);
//		camera.ProcessKeyboardMovement();
//		//�����������Ȼ��壬��Ⱦ��ɫ
//		glClearColor(0, 0.5f, 0.5f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
//		//set viewMatrice
//		viewMat = camera.GetViewMatrix();
//		for (int i = 0; i < 1; i++) {
//			myShader->use();
//			//Set vertexShader -> Uniforms
//			glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
//			glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "proMat"), 1, GL_FALSE, glm::value_ptr(proMat));
//			glUniform3f(glGetUniformLocation(myShader->ID, "eyes"), camera.Position.x, camera.Position.y, camera.Position.z);
//			//������
//			glUniform3f(glGetUniformLocation(myShader->ID, "ambientColor"), 0.2f, 0.2f, 0.2f);
//			//ƽ�й�
//			glUniform3f(glGetUniformLocation(myShader->ID, "lightDir.dirToLight"), lightDir.lightDirection.x, lightDir.lightDirection.y, lightDir.lightDirection.z);
//			glUniform3f(glGetUniformLocation(myShader->ID, "lightDir.color"), lightDir.color.x, lightDir.color.y, lightDir.color.z);
//			//���Դ
//			glUniform3f(glGetUniformLocation(myShader->ID, "lightPoint.position"), lightPoint.position.x, lightPoint.position.y, lightPoint.position.z);
//			glUniform3f(glGetUniformLocation(myShader->ID, "lightPoint.color"), lightPoint.color.x, lightPoint.color.y, lightPoint.color.z);
//			glUniform1f(glGetUniformLocation(myShader->ID, "lightPoint.constant"), lightPoint.constant);
//			glUniform1f(glGetUniformLocation(myShader->ID, "lightPoint.linear"), lightPoint.linear);
//			glUniform1f(glGetUniformLocation(myShader->ID, "lightPoint.quadratic"), lightPoint.quadratic);
//			//�۹��
//			glUniform3f(glGetUniformLocation(myShader->ID, "lightSpot.position"), lightSpot.position.x, lightSpot.position.y, lightSpot.position.z);
//			glUniform3f(glGetUniformLocation(myShader->ID, "lightSpot.dirToLight"), lightSpot.lightDirection.x, lightSpot.lightDirection.y, lightSpot.lightDirection.z);
//			glUniform3f(glGetUniformLocation(myShader->ID, "lightSpot.color"), lightSpot.color.x, lightSpot.color.y, lightSpot.color.z);
//			glUniform1f(glGetUniformLocation(myShader->ID, "lightSpot.cosPhyInner"), lightSpot.cosPhyInner);
//			glUniform1f(glGetUniformLocation(myShader->ID, "lightSpot.cosPhyOuter"), lightSpot.cosPhyOuter);
//			glBindFramebuffer(GL_FRAMEBUFFER, fbo);
//			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//			glEnable(GL_DEPTH_TEST);
//			model.Draw(myShader, material);
//
//			//����֮ǰ��֡����������������Ļ
//			glBindFramebuffer(GL_FRAMEBUFFER, 0);
//			glClearColor(0, 0.5f, 0.5f, 1.0f);
//			glClear(GL_COLOR_BUFFER_BIT);
//			glDisable(GL_DEPTH_TEST);
//			myTestFramebufferShader->use();
//			glUniform1i(glGetUniformLocation(myTestFramebufferShader->ID, "screenTexture"), 0);
//			glBindVertexArray(quadVAO);
//			glActiveTexture(GL_TEXTURE0);
//			glBindTexture(GL_TEXTURE_2D, fbo_texture);	// use the color attachment texture as the texture of the quad plane
//			glDrawArrays(GL_TRIANGLES, 0, 6);
//			glEnable(GL_DEPTH_TEST);
//		}
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	//�����˳�
//	glfwTerminate();
//	return 0;
//}
//
//#pragma region Input Function Declare
//void processInput(GLFWwindow* window) {
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//	if (glfwGetKey(window, GLFW_KEY_W)) {
//		camera.speedZ = 1.0f;
//	}
//	else if (glfwGetKey(window, GLFW_KEY_S)) {
//		camera.speedZ = -1.0f;
//	}
//	else {
//		camera.speedZ = 0;
//	}
//	if (glfwGetKey(window, GLFW_KEY_D)) {
//		camera.speedX = 1.0f;
//	}
//	else if (glfwGetKey(window, GLFW_KEY_A)) {
//		camera.speedX = -1.0f;
//	}
//	else {
//		camera.speedX = 0;
//	}
//	if (glfwGetKey(window, GLFW_KEY_Q)) {
//		camera.speedY = 1.0f;
//	}
//	else if (glfwGetKey(window, GLFW_KEY_E)) {
//		camera.speedY = -1.0f;
//	}
//	else {
//		camera.speedY = 0;
//	}
//}
//
//void mouse_callback(GLFWwindow* window, double xPos, double yPos) {
//	if (firstMouse == true) {
//		lastXpos = xPos;
//		lastYpos = yPos;
//		firstMouse = false;
//	}
//	double deltaX, deltaY;
//	deltaX = xPos - lastXpos;
//	deltaY = yPos - lastYpos;
//	lastXpos = xPos;
//	lastYpos = yPos;
//	camera.ProcessMouseMovement(deltaX, deltaY);
//}
//#pragma endregion
//unsigned int  LoadImageToGPU(const char* fileName, GLint internalFormat, GLenum format, int textureSlot) {
//	unsigned int TexBuffer;
//	glGenTextures(1, &TexBuffer);
//	glActiveTexture(GL_TEXTURE0 + textureSlot);
//	glBindTexture(GL_TEXTURE_2D, TexBuffer);
//	int width, height, nrChannels;
//	unsigned char* data = stbi_load(fileName, &width, &height, &nrChannels, 0);
//	if (data) {
//		glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else {
//		std::cout << "load texture to TexBufferA error!" << std::endl;
//	}
//	stbi_image_free(data);
//	return TexBuffer;
//}