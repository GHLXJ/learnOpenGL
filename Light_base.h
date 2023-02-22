#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
class Light_base
{
public:
	Light_base(glm::vec3 _position, glm::vec3 _rotation,glm::vec3 _color);
	glm::vec3 position;
	// 光朝向由旋转角计算出
	glm::vec3 rotation;
	glm::vec3 lightDirection = glm::vec3(0,0,1.0f);
	glm::vec3 color;
};

