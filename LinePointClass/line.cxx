#include <cassert>
#include <iostream>
using namespace std
#include "line.h"
#include "point.h"
#include <math.h>

line::line(){
	p1.set_y(0);
	p1.set_x(0);
	p2.set_y(0);
	p2.set_x(10);
	}

line::line(point A){
	p1.set_y(0);
	p1.set_x(0);
	p2 = A;
	}

line::line(point B, point C){
	p1 = B;
	p2 = C;
	}

double line::slope() const {
	if (p1.get_x() - p2.get_x() == 0)
		return 999999.99; // represents infinity
	else if (p1.get_x() != p2.get_x())
		return (p2.get_y() - p1.get_y()) / (p2.get_x() - p1.get_x());
	else
		return 0;
}

bool operator == (const line &firstLine, const line &secondLine) {
		return ((firstLine.slope()-secondLine.slope()<.000001) && ((firstLine.p1.get_y() - (firstLine.slope() * firstLine.p1.get_x())) - (secondLine.p1.get_y() - (secondLine.slope() * secondLine.p1.get_x())<.0000001)));
		}

void line::reflect_x(){
	p1.set_y(-1 * p1.get_y());
	p2.set_y(-1 * p2.get_y());
	}

void line::reflect_y(){
	p1.set_x(-1 * p1.get_x());
	p2.set_x(-1 * p2.get_x());
	}

void line::operator = (const line& lineToCopy){
	p1 = lineToCopy.p1;
	p2 = lineToCopy.p2; 
	}


/*
double line::y_intercept() const{
	return p1.get_y() - l1.slope()*p1.get_x();
	}

void line::operator = (const line& lineToCopy) 
{
	p1 = lineToCopy.p1;
}
*/


void line::translate(double X, double Y){
	p1.set_x(p1.get_x() + X);
	p1.set_y(p1.get_y() + Y);
	p2.set_x(p2.get_x() + X);
	p2.set_y(p2.get_y() + Y);
	}


istream& operator >> (istream& ins, line& target) 
{
	ins >> target.p1 >> target.p2;
	return ins;
}

ostream& operator << (ostream& outs, const line& source)
{
	//outs << source.p1 << ", " << source.p2;
	if (source.p1.get_x() == source.p2.get_x())
	{
		outs << "x = " << source.p2.get_x();
		return outs;
	}
	else if (source.p1.get_y() == source.p2.get_y())
	{
		outs << "y = " << source.p2.get_y();
		return outs;
	}
	else
	{
		outs << "y = " << source.slope() << "x + " << source.p1.get_y() - source.slope() * source.p1.get_x();
		return outs;
	}
}

/*line::line(){
	x1 = x1;
	y1 = 0;
	x2 = x2;
	y2 = 0;
	}
	
line::line(double x_2, double y_2){
	x1 = 0;
	y1 = 0;
	x2 = x_2;
	y2 = y_2;
	}

line::line(double x1_1, double y1_1, double x2_2, double y2_2){
	x1 = x1_1;
	y1 = y1_1;
	y2 = y2_2;
	x2 = x2_2;
	}



*/

