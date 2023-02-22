#pragma once
#include"Light_base.h"
#include<glm/gtx/rotate_vector.hpp>
class LightSpot:public Light_base
{
public:
	LightSpot(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _color);
	void updateLightDir();
	float cosPhyInner;
	float cosPhyOuter;
};

