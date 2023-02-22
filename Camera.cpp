#include "Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 worldup) {
	Position = position; 
	WorldUp = worldup; 
	Forward = glm::normalize(target - position); 
	Right = glm::normalize(glm:: cross(Forward, WorldUp)); 
	Up = glm::normalize(glm::cross(Forward, Right));
}

Camera::Camera(glm::vec3 position, float pitch, float yaw, glm::vec3 worldup) {
	Position = position; 
	WorldUp = worldup; 
	Pitch = pitch;
	Yaw = yaw;
	Forward.x = glm::cos(Pitch) * glm::sin(Yaw); 
	Forward.y = glm::sin(Pitch); 		   
	Forward.z = glm::cos(Pitch) * glm::cos(Yaw); 
	Right = glm::normalize(glm::cross(Forward, WorldUp)); 
	Up = glm:: normalize(glm::cross(Forward, Right));
}

glm::mat4 Camera::GetViewMatrix(){
	return glm::lookAt(Position, Position + Forward, WorldUp);
}

void Camera::ProcessMouseMovement(float deltaX, float deltaY) {
	Pitch -= deltaY * SenseX;
	Yaw -= deltaX * SenseY;
	UpdateCameraVectors();
}
void Camera::ProcessKeyboardMovement() {
	Position += Forward * speedZ * speedTimesZ + Right * speedX * speedTimesX + Up * speedY * speedTimesY;
}

void Camera::UpdateCameraVectors() {
	Forward.x = glm::cos(Pitch) * glm::sin(Yaw);
	Forward.y = glm::sin(Pitch);
	Forward.z = glm::cos(Pitch) * glm::cos(Yaw);
	Right = glm::normalize(glm::cross(Forward, WorldUp));
	Up = glm::normalize(glm::cross(Right, Forward));
}
