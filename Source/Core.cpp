#include "Dolly/Core.hpp"

// Getters

int Dolly::Core::GetX() const
{
	return x;
}

int Dolly::Core::GetY() const
{
	return y;
}

unsigned int Dolly::Core::GetWidth() const
{
	return width;
}

unsigned int Dolly::Core::GetHeight() const
{
	return height;
}

// Setters

void Dolly::Core::SetX(int _x)
{
	this->x = _x;
}

void Dolly::Core::SetY(int _y)
{
	this->y = _y;
}

void Dolly::Core::SetWidth(unsigned int _width)
{
	this->width = _width;
}

void Dolly::Core::SetHeight(unsigned int _height)
{
	this->height = _height;
}
