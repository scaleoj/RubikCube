#include <string>
#include <glm/gtc/type_ptr.hpp>

#pragma once
class MiniCube
{
public:
	MiniCube();
	void rotateX(bool direction);
	void rotateY(bool direction);
	void rotateZ(bool direction);
	glm::vec3 GetFacingData(int direction, int sideType);
	std::string GetFacingString(int side);
	glm::vec3 GetTop();
	glm::vec3 GetBottom();
	glm::vec3 GetLeft();
	glm::vec3 GetRight();
	glm::vec3 GetFront();
	glm::vec3 GetBack();

private:
	glm::vec3 left;
	//std::vector<float> left;
	glm::vec3 right;
	glm::vec3 front;
	glm::vec3 back;
	glm::vec3 bottom;
	glm::vec3 top;
	glm::vec3 rotateHelp;
	std::string ConvertVectorToString(glm::vec3 color);

};

