#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
class Camera
{
public:
	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 worldup);
	Camera(glm::vec3 position, float pitch, float yaw, glm::vec3 worldup);
	glm::mat4 GetViewMatrix();
	void ProcessMouseMovement(float deltaX, float deltaY);
	void ProcessKeyboardMovement();
	glm::vec3 Position; 
	glm::vec3 Forward; 
	glm::vec3 Right; 
	glm::vec3 Up; 
	glm::vec3 WorldUp;
	double Pitch; 
	double Yaw;
	float SenseX = 0.0005f;
	float SenseY = 0.0005f;
	float speedX = 0;
	float speedY = 0;
	float speedZ = 0;
	float speedTimesX = 0.008;
	float speedTimesY = 0.025;
	float speedTimesZ = 0.05;
private:
	void UpdateCameraVectors();
};

