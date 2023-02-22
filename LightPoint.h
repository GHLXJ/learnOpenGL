#pragma once
#include"Light_base.h"
class LightPoint:public Light_base
{
public:
	LightPoint(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _color);
	float constant; 
	float linear; 
	float quadratic;
};

