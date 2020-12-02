#include <string>

#pragma once
class MiniCube
{
public:
	MiniCube();
	void rotateX(bool direction);
	void rotateY(bool direction);
	void rotateZ(bool direction);

private:
	std::string left;
	std::string right;
	std::string front;
	std::string back;
	std::string bottom;
	std::string top;
	std::string rotateHelp;
};

