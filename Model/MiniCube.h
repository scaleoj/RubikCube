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
	std::string GetFacingString(int side);
	glm::vec4 GetTop();
	glm::vec4 GetBottom();
	glm::vec4 GetLeft();
	glm::vec4 GetRight();
	glm::vec4 GetFront();
	glm::vec4 GetBack();

private:
	glm::vec4 left;
	//std::vector<float> left;
	glm::vec4 right;
	glm::vec4 front;
	glm::vec4 back;
	glm::vec4 bottom;
	glm::vec4 top;
	glm::vec4 rotateHelp;
	std::string ConvertVectorToString(glm::vec4 color);

};

