#include <string>
#include <vector>

#pragma once
class MiniCube
{
public:
	MiniCube();
	void rotateX(bool direction);
	void rotateY(bool direction);
	void rotateZ(bool direction);
	std::string GetFacingString(int side);
	std::vector<float> GetTop();
	std::vector<float> GetBottom();
	std::vector<float> GetLeft();
	std::vector<float> GetRight();
	std::vector<float> GetFront();
	std::vector<float> GetBack();

private:
	std::vector<float> left;
	std::vector<float> right;
	std::vector<float> front;
	std::vector<float> back;
	std::vector<float> bottom;
	std::vector<float> top;
	std::vector<float> rotateHelp;
	std::string ConvertVectorToString(std::vector<float> color);

};

