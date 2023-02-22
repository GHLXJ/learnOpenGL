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
////相机类
//Camera camera(glm::vec3(0, 0, 3.0f), glm::radians(15.0f), glm::radians(180.0f), glm::vec3(0, 1.0f, 0));
//#pragma endregion
//#pragma region Input Declare
//double lastXpos;
//double lastYpos;
//bool firstMouse = true;
//
//void processInput(GLFWwindow* window);
////记得没错的话声明必须这个格式才能自动填入xPos,yPos
//void mouse_callback(GLFWwindow* window, double xPos, double yPos);
//#pragma endregion
//unsigned int LoadImageToGPU(const char* fileName, GLint internalFormat, GLenum format, int textureSlot);
//int main() {
//#pragma region Open a Window
//	//glfw初始化
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
//	//设置当前线程的主要上下文
//	glfwMakeContextCurrent(window);
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//	glfwSetCursorPosCallback(window, mouse_callback);
//	//glew 初始化
//	glewExperimental = true;
//	if (glewInit() != GLEW_OK) {
//		std::cout << "error,glewInit error!";
//		glfwTerminate();
//		return 0;
//	}
//	glViewport(0, 0, 800, 600);
//#pragma endregion
//#pragma region Init three kinds light
//	//平行光
//	LightDir lightDir = LightDir(glm::vec3(10.0f, 10.0f, 5.0f),
//		glm::vec3(0, 0, 0),
//		glm::vec3(1.0f, 1.0f, 1.0f)
//	);
//	//点光源
//	LightPoint lightPoint = LightPoint(glm::vec3(1.0f, 2.0f, 0),
//		glm::vec3(glm::radians(45.0f), 0, 0),
//		glm::vec3(1.0f, 1.0f, 1.0f)
//	);
//	//聚光灯
//	LightSpot lightSpot = LightSpot(glm::vec3(0, 2.0f, -4.0f),
//		glm::vec3(glm::radians(90.0f), 0, 0),
//		glm::vec3(1.0f, 1.0f, 1.0f)
//	);
//#pragma endregion
//#pragma region Init Shader Program
//	//Shader对象
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
//	// VAO,上方位置：array buffer （下方位置：E buffer）
//	unsigned int VAO;
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//	//VBO 绑定在VAO上方位置
//	unsigned int VBO;
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	//将自定义顶点数据拷贝到GL_ARRAY_BUFFER
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	// 3D
//	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(3);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(sizeof(float) * 3));
//	glEnableVertexAttribArray(2);
//	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(sizeof(float) * 5));
//	glEnableVertexAttribArray(4);
//#pragma endregion
//	//导入图片前翻转Y轴
//	stbi_set_flip_vertically_on_load(true);
//#pragma region Load Image to GPU
//	/*unsigned int TexBufferA = LoadImageToGPU("container.jpg", GL_RGB, GL_RGB,0);*/
//	/*unsigned int TexBufferB = LoadImageToGPU("awesomeface.png", GL_RGB, GL_RGB, 3);*/
//#pragma endregion
//#pragma region Prepare MVP matrices
////模型矩阵，观察矩阵，投影矩阵
//	glm::mat4 modelMat;
//	glm::mat4 viewMat;
//	glm::mat4 proMat;
//	proMat = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
//#pragma endregion
//	//循环体，判断窗口是否关闭
//	while (!glfwWindowShouldClose(window)) {
//		//延迟处理输入
//		processInput(window);
//		camera.ProcessKeyboardMovement();
//		//清屏并清除深度缓冲，渲染纯色
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
//			//再次指定GL_TEXTURE_2D内索引并绑定GL_TEXTURE_2D:Set Material -> Textures
//			glActiveTexture(GL_TEXTURE0);
//			/*glBindTexture(GL_TEXTURE_2D, TexBufferA);*/
//			glBindTexture(GL_TEXTURE_2D, material2->diffuse_tex);
//			glActiveTexture(GL_TEXTURE0 + 1);
//			glBindTexture(GL_TEXTURE_2D, material2->specular_tex);
//			//set lightColor objColor
//			glUniform3f(glGetUniformLocation(myShader->ID, "objColor"), 1.0f, 1.0f, 1.0f);
//			glUniform3f(glGetUniformLocation(myShader->ID, "ambientColor"), 0.1f, 0.1f, 0.1f);
//			//Set Material -> Uniforms
//			//两个glUniform1i最后参数0和3与pragma region Load Image to GPU有关
//			glUniform1i(glGetUniformLocation(myShader->ID, "ourTextureA"), 0);
//			glUniform1i(glGetUniformLocation(myShader->ID, "ourTextureB"), 1);
//			glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat));
//			glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
//			glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "proMat"), 1, GL_FALSE, glm::value_ptr(proMat));
//			//glUniform3f(glGetUniformLocation(myShader->ID, "lightColor"), 1.0f, 1.0f, 1.0f);
//			//glUniform3f(glGetUniformLocation(myShader->ID, "lightPos"), 10.0f, 10.0f, 10.0f);
//			//不同光切换lightColor，lightPos
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
//			// 0 定值可封装
//			material->setUniform1i("material.diffuse_tex", Shader::Diffuse);
//			material->setUniform1i("material.specular_tex", Shader::Specular);
//			material->setUniform1f("material.shininess", material2->shininess);
//			//绑定VAO,EBO之前绑定在此VAO上，可以不用再绑定:Set Model
//			glBindVertexArray(VAO);
//			//Draw Call
//			//个人猜测:glDrawArrays在VAO和Shader之间起到作用，具体什么作用有多种猜测
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//
//	//正常退出
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