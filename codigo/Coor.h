#ifndef COOR_H
#define COOR_H

class Coor
{

private:

	double x;
	double y;
	double z;

public:

	Coor(double=0, double=0, double=0);
	void init(double x, double y, double z);
	void setX(double val);
	void setY(double val);
	void setZ(double val);
	double getX();
	double getY();
	double getZ();
};

#endif