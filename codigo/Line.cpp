#include <iostream>
#include "Line.h"
#include <cmath>

Line::Line()
{
}

Line::Line(int p1, int p2)
{
	this->p1=p1;
	this->p2=p2;
}


void Line::init(int p1, int p2)
{
	this->p1=p1;
	this->p2=p2;
}

int Line::getP1()
{
	return p1;
}

int Line::getP2()
{
	return p2;
}

void Line::setP1(int point)
{
	p1=point;
}

void Line::setP2(int point)
{
	p2=point;
}

Line::~Line()
{

}
