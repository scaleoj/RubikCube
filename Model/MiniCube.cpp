#include "MiniCube.h"

MiniCube::MiniCube()
{
	left = { 1.0f, 0.0f, 0.0f, 1.0f }; //red
	right = { 1.0f, 0.0f, 1.0f, 1.0f }; //purple
	front = { 0.0f, 1.0f, 0.0f, 1.0f }; //green
	back = { 0.0f, 0.0f, 1.0f, 1.0f }; //blue
	bottom = { 1.0f, 1.0f, 1.0f, 1.0f }; //white
	top = { 1.0f, 1.0f, 0.0f, 1.0f }; //yellow
	rotateHelp = { 0.0f, 0.0f, 0.0f, 1.0f };
}

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

std::string MiniCube::GetFacingString(int side)
{
	std::string result = "";

	switch (side)
	{
	case 0:
		result = ConvertVectorToString(GetTop());
		break;
	case 1:
		result = ConvertVectorToString(GetLeft());
		break;
	case 2:
		result = ConvertVectorToString(GetFront());
		break;
	case 3:
		result = ConvertVectorToString(GetRight());
		break;
	case 4:
		result = ConvertVectorToString(GetBottom());
		break;
	case 5:
		result = ConvertVectorToString(GetBack());
		break;
	default:
		break;
	}
	
	return result;
}

std::vector<float> MiniCube::GetTop()
{
	return top;
}

std::vector<float> MiniCube::GetBottom()
{
	return bottom;
}

std::vector<float> MiniCube::GetLeft()
{
	return left;
}

std::vector<float> MiniCube::GetRight()
{
	return right;
}

std::vector<float> MiniCube::GetFront()
{
	return front;
}

std::vector<float> MiniCube::GetBack()
{
	return back;
}

std::string MiniCube::ConvertVectorToString(std::vector<float> color)
{
	std::string result = "";

	if (color.at(0) > 0.5f)
	{
		if (color.at(1) > 0.5f)
		{
			if (color.at(2) > 0.5f)
			{
				result = "wh";
			}
			else
			{
				result = "ye";
			}
		}
		else
		{
			if (color.at(2) > 0.5f)
			{
				result = "pu";
			}
			else
			{
				result = "re";
			}
		}
	}
	else
	{
		if (color.at(1) > 0.5f)
		{
			result = "gr";
		}
		else
		{
			result = "bl";
		}
	}

	return result;
}


