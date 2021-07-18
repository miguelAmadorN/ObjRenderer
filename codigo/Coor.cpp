#include <iostream>
#include "Coor.h"

Coor::Coor(double x, double y, double z)
{
	this->x=x;
	this->y=y;
	this->z=z;
}

void Coor::init(double x, double y, double z)
{
	this->x=x;
	this->y=y;
	this->z=z;
}

void Coor::setX(double val)
{
	this->x=val;
}


void Coor::setY(double val)
{
	this->y=val;
}

void Coor::setZ(double val)
{
	this->z=val;
}

double Coor::getX()
{
	return x;
}

double Coor::getY()
{
	return y;
}

double Coor::getZ()
{
	return z;
}
