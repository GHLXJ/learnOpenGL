#include "LightPoint.h"

LightPoint::LightPoint(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _color):
	Light_base(_position, _rotation, _color)
{
	constant = 1.0f; 
	linear = 0.09f; 
	quadratic = 0.032f;
}
