#include "MiniCube.h"

MiniCube::MiniCube()
{
	left = "re";
	right = "pu";
	front = "gr";
	back = "bl";
	bottom = "wh";
	top = "ye";
	rotateHelp = "";
};


void MiniCube::rotateX(bool direction)
{
	if (direction)
	{
		rotateHelp = top;
		top = back;
		back = bottom;
		bottom = front;
		front = rotateHelp;
	}
	else
	{
		rotateHelp = bottom;
		bottom = back;
		back = top;
		top = front;
		front = rotateHelp;
	}
}

void MiniCube::rotateY(bool direction)
{
	if (direction)
	{
		rotateHelp = left;
		left = back;
		back = right;
		right = front;
		front = rotateHelp;
	}
	else
	{
		rotateHelp = right;
		right = back;
		back = left;
		left = front;
		front = rotateHelp;
	}
}

void MiniCube::rotateZ(bool direction)
{
	if (direction)
	{
		rotateHelp = top;
		top = right;
		right = bottom;
		bottom = left;
		left = rotateHelp;
	}
	else
	{
		rotateHelp = bottom;
		bottom = right;
		right = top;
		top = left;
		left = rotateHelp;
	}
}

std::string MiniCube::GetTop()
{
	return top;
}

std::string MiniCube::GetBottom()
{
	return bottom;
}

std::string MiniCube::GetLeft()
{
	return left;
}

std::string MiniCube::GetRight()
{
	return right;
}

std::string MiniCube::GetFront()
{
	return front;
}

std::string MiniCube::GetBack()
{
	return back;
}


