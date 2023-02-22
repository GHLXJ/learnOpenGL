//#define GLEW_STATIC
//#include<GL/glew.h>
//#include<GLFW/glfw3.h>
//#include<iostream>
//#include"Shader.h"
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
//
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
//int main() {
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
//#pragma endregion
//#pragma region Init three kinds light
//	//ƽ�й�
//	LightDir lightDir = LightDir(glm::vec3(10.0f, 10.0f, 5.0f),
//		glm::vec3(0, 0, 0),
//		glm::vec3(1.0f, 1.0f, 1.0f)
//	);
//	//���Դ
//	LightPoint lightPoint = LightPoint(glm::vec3(1.0f, 2.0f, 0),
//		glm::vec3(glm::radians(45.0f), 0, 0),
//		glm::vec3(1.0f, 1.0f, 1.0f)
//	);
//	//�۹��
//	LightSpot lightSpot = LightSpot(glm::vec3(0, 2.0f, -4.0f),
//		glm::vec3(glm::radians(90.0f), 0, 0),
//		glm::vec3(1.0f, 1.0f, 1.0f)
//	);
//#pragma endregion
//#pragma region Init Shader Program
//	//Shader����
//	Shader* myShader = new Shader("vertexSource.vert", "fragmentSource.frag");
//#pragma endregion
//#pragma region Init Material
//	Material* material = new Material(myShader,
//		glm::vec3(1.0f, 1.0f, 1.0f),
//		glm::vec3(1.0f, 1.0f, 1.0f),
//		glm::vec3(1.0f, 1.0f, 1.0f),
//		32.0f
//	);
//	Material* material2 = new Material(myShader,
//		glm::vec3(1.0f, 1.0f, 1.0f),
//		LoadImageToGPU("container2.png", GL_RGBA, GL_RGBA, Shader::Diffuse),
//		LoadImageToGPU("container2_specular.png", GL_RGBA, GL_RGBA, Shader::Specular),
//		32.0f
//	);
//#pragma endregion
//	glEnable(GL_DEPTH_TEST);
//#pragma region Init and Load  Model To VAO,VBO
//	// VAO,�Ϸ�λ�ã�array buffer ���·�λ�ã�E buffer��
//	unsigned int VAO;
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//	//VBO ����VAO�Ϸ�λ��
//	unsigned int VBO;
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	//���Զ��嶥�����ݿ�����GL_ARRAY_BUFFER
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	// 3D
//	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(3);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(sizeof(float) * 3));
//	glEnableVertexAttribArray(2);
//	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(sizeof(float) * 5));
//	glEnableVertexAttribArray(4);
//#pragma endregion
//	//����ͼƬǰ��תY��
//	stbi_set_flip_vertically_on_load(true);
//#pragma region Load Image to GPU
//	/*unsigned int TexBufferA = LoadImageToGPU("container.jpg", GL_RGB, GL_RGB,0);*/
//	/*unsigned int TexBufferB = LoadImageToGPU("awesomeface.png", GL_RGB, GL_RGB, 3);*/
//#pragma endregion
//#pragma region Prepare MVP matrices
////ģ�;��󣬹۲����ͶӰ����
//	glm::mat4 modelMat;
//	glm::mat4 viewMat;
//	glm::mat4 proMat;
//	proMat = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
//#pragma endregion
//	//ѭ���壬�жϴ����Ƿ�ر�
//	while (!glfwWindowShouldClose(window)) {
//		//�ӳٴ�������
//		processInput(window);
//		camera.ProcessKeyboardMovement();
//		//�����������Ȼ��壬��Ⱦ��ɫ
//		glClearColor(0, 0.5f, 0.5f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		//set viewMatrice
//		viewMat = camera.GetViewMatrix();
//		for (int i = 0; i < 10; i++) {
//			//Set Model matrix
//			modelMat = glm::translate(glm::mat4(1.0f), cubePositions[i]);
//			// Set View and Projection Matrices here if you want.
//			// 
//
//			//Set Material -> Shader Program
//			myShader->use();
//			//�ٴ�ָ��GL_TEXTURE_2D����������GL_TEXTURE_2D:Set Material -> Textures
//			glActiveTexture(GL_TEXTURE0);
//			/*glBindTexture(GL_TEXTURE_2D, TexBufferA);*/
//			glBindTexture(GL_TEXTURE_2D, material2->diffuse_tex);
//			glActiveTexture(GL_TEXTURE0 + 1);
//			glBindTexture(GL_TEXTURE_2D, material2->specular_tex);
//			//set lightColor objColor
//			glUniform3f(glGetUniformLocation(myShader->ID, "objColor"), 1.0f, 1.0f, 1.0f);
//			glUniform3f(glGetUniformLocation(myShader->ID, "ambientColor"), 0.1f, 0.1f, 0.1f);
//			//Set Material -> Uniforms
//			//����glUniform1i������0��3��pragma region Load Image to GPU�й�
//			glUniform1i(glGetUniformLocation(myShader->ID, "ourTextureA"), 0);
//			glUniform1i(glGetUniformLocation(myShader->ID, "ourTextureB"), 1);
//			glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat));
//			glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
//			glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "proMat"), 1, GL_FALSE, glm::value_ptr(proMat));
//			//glUniform3f(glGetUniformLocation(myShader->ID, "lightColor"), 1.0f, 1.0f, 1.0f);
//			//glUniform3f(glGetUniformLocation(myShader->ID, "lightPos"), 10.0f, 10.0f, 10.0f);
//			//��ͬ���л�lightColor��lightPos
//			//lightDir
//			/*glUniform3f(glGetUniformLocation(myShader->ID, "lightColor"), lightDir.color.x, lightDir.color.y, lightDir.color.z);
//			glUniform3f(glGetUniformLocation(myShader->ID, "lightPos"), lightDir.position.x, lightDir.position.y, lightDir.position.z);
//			glUniform3f(glGetUniformLocation(myShader->ID, "lightDirection"), lightDir.lightDirection.x,lightDir.lightDirection.y, lightDir.lightDirection.z);*/
//			//lightPoint
//			/*glUniform3f(glGetUniformLocation(myShader->ID, "lightColor"), lightPoint.color.x, lightPoint.color.y, lightPoint.color.z);
//			glUniform3f(glGetUniformLocation(myShader->ID, "lightPos"), lightPoint.position.x, lightPoint.position.y, lightPoint.position.z);
//			glUniform3f(glGetUniformLocation(myShader->ID, "lightDirection"), lightPoint.lightDirection.x, lightPoint.lightDirection.y, lightPoint.lightDirection.z);
//			glUniform1f(glGetUniformLocation(myShader->ID, "lightPoint.constant"), lightPoint.constant);
//			glUniform1f(glGetUniformLocation(myShader->ID, "lightPoint.linear"), lightPoint.linear);
//			glUniform1f(glGetUniformLocation(myShader->ID, "lightPoint.quadratic"), lightPoint.quadratic);*/
//			//lightSpot
//			glUniform3f(glGetUniformLocation(myShader->ID, "lightColor"), lightSpot.color.x, lightSpot.color.y, lightSpot.color.z);
//			glUniform3f(glGetUniformLocation(myShader->ID, "lightPos"), lightSpot.position.x, lightSpot.position.y, lightSpot.position.z);
//			glUniform3f(glGetUniformLocation(myShader->ID, "lightDirection"), lightSpot.lightDirection.x, lightSpot.lightDirection.y, lightSpot.lightDirection.z);
//			glUniform1f(glGetUniformLocation(myShader->ID, "lightSpot.cosPhyInner"), lightSpot.cosPhyInner);
//			glUniform1f(glGetUniformLocation(myShader->ID, "lightSpot.cosPhyOuter"), lightSpot.cosPhyOuter);
//			//
//			glUniform3f(glGetUniformLocation(myShader->ID, "eyes"), camera.Position.x, camera.Position.y, camera.Position.z);
//			material->setUniform3f("material.diffuse", material->diffuse);
//			material->setUniform3f("material.ambient", material2->ambient);
//			// 0 ��ֵ�ɷ�װ
//			material->setUniform1i("material.diffuse_tex", Shader::Diffuse);
//			material->setUniform1i("material.specular_tex", Shader::Specular);
//			material->setUniform1f("material.shininess", material2->shininess);
//			//��VAO,EBO֮ǰ���ڴ�VAO�ϣ����Բ����ٰ�:Set Model
//			glBindVertexArray(VAO);
//			//Draw Call
//			//���˲²�:glDrawArrays��VAO��Shader֮�������ã�����ʲô�����ж��ֲ²�
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
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