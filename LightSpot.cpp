#include "LightSpot.h"

LightSpot::LightSpot(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _color):
	Light_base(_position, _rotation, _color)
{
	cosPhyInner = 0.9f;
	cosPhyOuter = 0.85f;
	updateLightDir();
}
void LightSpot::updateLightDir()
{
	lightDirection = glm::vec3(0, 0, 1.0f);
	lightDirection = glm::rotateZ(lightDirection, rotation.z);
	lightDirection = glm::rotateX(lightDirection, rotation.x);
	lightDirection = glm::rotateY(lightDirection, rotation.y);
	//与入射光相反的方向向量
	lightDirection *= -1.0f;
}
