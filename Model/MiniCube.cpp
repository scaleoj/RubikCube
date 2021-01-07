#include "MiniCube.h"

MiniCube::MiniCube()
{
	left = { 1.0f, 0.0f, 0.0f}; //red
	right = { 0.6f, 0.4f, 1.0f}; //purple
	front = { 0.0f, 1.0f, 0.0f}; //green
	back = { 0.0f, 0.0f, 1.0f}; //blue
	bottom = { 0.9f, 0.9f, 0.9f}; //white
	top = { 1.0f, 1.0f, 0.0f}; //yellow
	rotateHelp = { 0.0f, 0.0f, 0.0f};

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


glm::vec3 MiniCube::GetFacingData(int direction, int sideType)
{
	glm::vec3 result;
	switch (sideType)
	{
	case 0:
		if (direction == 1)
		{
			result = left;
			
		}
		else
		{
			result = right;
		}
		break;
	case 1:
		if (direction == 1)
		{
			result = top;
		}
		else
		{
			result = bottom;
		}
		break;
	case 2:
		if (direction == -1)
		{
			result = front;
		}
		else
		{
			result = back;
		}
		break;
	default:
		break;
	}

	return result;
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

glm::vec3 MiniCube::GetTop()
{
	return top;
}

glm::vec3 MiniCube::GetBottom()
{
	return bottom;
}

glm::vec3 MiniCube::GetLeft()
{
	return left;
}

glm::vec3 MiniCube::GetRight()
{
	return right;
}

glm::vec3 MiniCube::GetFront()
{
	return front;
}

glm::vec3 MiniCube::GetBack()
{
	return back;
}

std::string MiniCube::ConvertVectorToString(glm::vec3 color)
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


