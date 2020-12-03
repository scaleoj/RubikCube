#include "Model.h"
#include <iostream>

void Model::Initialize()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				MiniCube cube;
				m_model[i][j][k] = cube;
			}
		}
	}
}

void Model::RotateX(bool direction, int disc)
{
	if (disc > 2)
	{
		std::cout << "Error: Wrong Disc Dimension on X-Rotation" << std::endl;
		return;
	}

	MiniCube tempO;
	MiniCube tempI;
	if (direction) //positive rotation on X-Axis direction from zero point
	{
		tempO = m_model[disc][0][0];
		tempI = m_model[disc][1][0];
		m_model[disc][0][0] = m_model[disc][2][0];
		m_model[disc][2][0] = m_model[disc][2][2];
		m_model[disc][2][2] = m_model[disc][0][2];
		m_model[disc][0][2] = tempO;
		m_model[disc][1][0] = m_model[disc][2][1];
		m_model[disc][2][1] = m_model[disc][1][2];
		m_model[disc][1][2] = m_model[disc][0][1];	
		m_model[disc][0][1] = tempI;

	}
	else //negative rotation in on X-Axis from zero point
	{
		tempO = m_model[disc][0][0];
		tempI = m_model[disc][1][0];
		m_model[disc][0][0] = m_model[disc][0][2];
		m_model[disc][0][2] = m_model[disc][2][2];
		m_model[disc][2][2] = m_model[disc][2][0];
		m_model[disc][2][0] = tempO;
		m_model[disc][1][0] = m_model[disc][0][1];
		m_model[disc][0][1] = m_model[disc][1][2];
		m_model[disc][1][2] = m_model[disc][2][1];
		m_model[disc][2][1] = tempI;
	}


	m_model[disc][2][0].rotateX(direction);
	m_model[disc][2][2].rotateX(direction);
	m_model[disc][0][2].rotateX(direction);
	m_model[disc][0][0].rotateX(direction);
	m_model[disc][2][1].rotateX(direction);
	m_model[disc][1][2].rotateX(direction);
	m_model[disc][0][1].rotateX(direction);
	m_model[disc][1][0].rotateX(direction);
}

void Model::RotateY(bool direction, int disc)
{
	if (disc > 2)
	{
		std::cout << "Error: Wrong Disc Dimension on Y-Rotation" << std::endl;
		return;
	}

	MiniCube tempO;
	MiniCube tempI;
	if (direction) //positive rotation on Y-Axis from zero point
	{
		tempO = m_model[0][disc][0];
		tempI = m_model[1][disc][0];
		m_model[0][disc][0] = m_model[2][disc][0];
		m_model[2][disc][0] = m_model[2][disc][2];
		m_model[2][disc][2] = m_model[0][disc][2];
		m_model[0][disc][2] = tempO;
		m_model[1][disc][0] = m_model[2][disc][1];
		m_model[2][disc][1] = m_model[1][disc][2];
		m_model[1][disc][2] = m_model[0][disc][1];
		m_model[0][disc][1] = tempI;

	}
	else //negative rotation on Y Axis from zero point
	{
		tempO = m_model[0][disc][0];
		tempI = m_model[1][disc][0];
		m_model[0][disc][0] = m_model[0][disc][2];
		m_model[0][disc][2] = m_model[2][disc][2];
		m_model[2][disc][2] = m_model[2][disc][0];
		m_model[2][disc][0] = tempO;
		m_model[1][disc][0] = m_model[0][disc][1];
		m_model[0][disc][1] = m_model[1][disc][2];
		m_model[1][disc][2] = m_model[2][disc][1];
		m_model[2][disc][1] = tempI;
	}

	m_model[0][disc][0].rotateY(direction);
	m_model[2][disc][0].rotateY(direction);
	m_model[2][disc][2].rotateY(direction);
	m_model[0][disc][2].rotateY(direction);
	m_model[1][disc][0].rotateY(direction);
	m_model[2][disc][1].rotateY(direction);
	m_model[1][disc][2].rotateY(direction);
	m_model[0][disc][1].rotateY(direction);
}

void Model::RotateZ(bool direction, int disc)
{
	if (disc > 2)
	{
		std::cout << "Error: Wrong Disc Dimension on Z-Rotation" << std::endl;
		return;
	}

	MiniCube tempO;
	MiniCube tempI;
	if (direction) //positive rotation on Z-Axis from zero point
	{
		tempO = m_model[0][0][disc];
		tempI = m_model[1][0][disc];
		m_model[0][0][disc] = m_model[2][0][disc];
		m_model[2][0][disc] = m_model[2][2][disc];
		m_model[2][2][disc] = m_model[0][2][disc];
		m_model[0][2][disc] = tempO;
		m_model[1][0][disc] = m_model[2][1][disc];
		m_model[2][1][disc] = m_model[1][2][disc];
		m_model[1][2][disc] = m_model[0][1][disc];
		m_model[0][1][disc] = tempI;
	}
	else //negative rotation on Z-Axis from zero point
	{
		tempO = m_model[0][0][disc];
		tempI = m_model[1][0][disc];
		m_model[0][0][disc] = m_model[0][2][disc];
		m_model[0][2][disc] = m_model[2][2][disc];
		m_model[2][2][disc] = m_model[2][0][disc];
		m_model[2][0][disc] = tempO;
		m_model[1][0][disc] = m_model[0][1][disc];
		m_model[0][1][disc] = m_model[1][2][disc];
		m_model[1][2][disc] = m_model[2][1][disc];
		m_model[2][1][disc] = tempI;
	}

	m_model[0][0][disc].rotateZ(direction);
	m_model[0][2][disc].rotateZ(direction);;
	m_model[2][2][disc].rotateZ(direction);;
	m_model[2][0][disc].rotateZ(direction);;
	m_model[1][0][disc].rotateZ(direction);;
	m_model[0][1][disc].rotateZ(direction);;
	m_model[1][2][disc].rotateZ(direction);;
	m_model[2][1][disc].rotateZ(direction);;
}

void Model::PrintModel()
{
	std::cout << "[--][--][--][" + m_model[0][0][2].GetTop() + "][" + m_model[1][0][2].GetTop() + "][" + m_model[2][0][2].GetTop() + "][--][--][--]" << std::endl;
	std::cout << "[--][--][--][" + m_model[0][0][1].GetTop() + "][" + m_model[1][0][1].GetTop() + "][" + m_model[2][0][1].GetTop() + "][--][--][--]" << std::endl;
	std::cout << "[--][--][--][" + m_model[0][0][0].GetTop() + "][" + m_model[1][0][0].GetTop() + "][" + m_model[2][0][0].GetTop() + "][--][--][--]" << std::endl;

	std::cout << "[" + m_model[0][0][2].GetLeft() + "][" + m_model[0][0][1].GetLeft() + "][" + m_model[0][0][0].GetLeft() + "][" + m_model[0][0][0].GetFront() + "][" + m_model[1][0][0].GetFront() + "][" + m_model[2][0][0].GetFront() + "][" + m_model[2][0][0].GetRight() + "][" + m_model[2][0][1].GetRight() + "][" + m_model[2][0][2].GetRight() + "]" << std::endl;
	std::cout << "[" + m_model[0][1][2].GetLeft() + "][" + m_model[0][1][1].GetLeft() + "][" + m_model[0][1][0].GetLeft() + "][" + m_model[0][1][0].GetFront() + "][" + m_model[1][1][0].GetFront() + "][" + m_model[2][1][0].GetFront() + "][" + m_model[2][1][0].GetRight() + "][" + m_model[2][1][1].GetRight() + "][" + m_model[2][1][2].GetRight() + "]" << std::endl;
	std::cout << "[" + m_model[0][2][2].GetLeft() + "][" + m_model[0][2][1].GetLeft() + "][" + m_model[0][2][0].GetLeft() + "][" + m_model[0][2][0].GetFront() + "][" + m_model[1][2][0].GetFront() + "][" + m_model[2][2][0].GetFront() + "][" + m_model[2][2][0].GetRight() + "][" + m_model[2][2][1].GetRight() + "][" + m_model[2][2][2].GetRight() + "]" << std::endl;

	std::cout << "[--][--][--][" + m_model[0][2][0].GetBottom() + "][" + m_model[1][2][0].GetBottom() + "][" + m_model[2][2][0].GetBottom() + "][--][--][--]" << std::endl;
	std::cout << "[--][--][--][" + m_model[0][2][1].GetBottom() + "][" + m_model[1][2][1].GetBottom() + "][" + m_model[2][2][1].GetBottom() + "][--][--][--]" << std::endl;
	std::cout << "[--][--][--][" + m_model[0][2][2].GetBottom() + "][" + m_model[1][2][2].GetBottom() + "][" + m_model[2][2][2].GetBottom() + "][--][--][--]" << std::endl;

	std::cout << "[--][--][--][" + m_model[0][2][2].GetBack() + "][" + m_model[1][2][2].GetBack() + "][" + m_model[2][2][2].GetBack() + "][--][--][--]" << std::endl;
	std::cout << "[--][--][--][" + m_model[0][1][2].GetBack() + "][" + m_model[1][1][2].GetBack() + "][" + m_model[2][1][2].GetBack() + "][--][--][--]" << std::endl;
	std::cout << "[--][--][--][" + m_model[0][0][2].GetBack() + "][" + m_model[1][0][2].GetBack() + "][" + m_model[2][0][2].GetBack() + "][--][--][--]" << std::endl;
	std::cout << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << std::endl;
}

