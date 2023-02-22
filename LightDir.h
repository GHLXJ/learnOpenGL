#pragma once
#include"Light_base.h"
#include<glm/gtx/rotate_vector.hpp>
class LightDir:public Light_base
{
public:
	LightDir(glm::vec3 _position, glm::vec3 _rotation,glm::vec3 _color);
	void updateLightDir();

};

