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
	void setAlignment(glm::mat4 newAlignment);
	glm::mat4 getAlignment();
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
	glm::mat4 alignment;


};

