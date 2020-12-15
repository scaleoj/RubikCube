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

glm::vec4 MiniCube::GetTop()
{
	return top;
}

glm::vec4 MiniCube::GetBottom()
{
	return bottom;
}

glm::vec4 MiniCube::GetLeft()
{
	return left;
}

glm::vec4 MiniCube::GetRight()
{
	return right;
}

glm::vec4 MiniCube::GetFront()
{
	return front;
}

glm::vec4 MiniCube::GetBack()
{
	return back;
}

std::string MiniCube::ConvertVectorToString(glm::vec4 color)
{
	std::string result = "";

	if (color.x > 0.5f)
	{
		if (color.y > 0.5f)
		{
			if (color.z > 0.5f)
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
			if (color.z > 0.5f)
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
		if (color.y > 0.5f)
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


