//Josh Fermin

#include <iostream>
using namespace std
#include "point.h"
#include <math.h>

point::point() {
	x=0;
	y=0;
	}
	
point::point(double x_in, double y_in){
	x = x_in;
	y = y_in;
	}
	
void point::translate(double x_in, double y_in){
	x += x_in;
	y += y_in;
	}

double point::get_x() const {
	return x;
	}

double point::get_y() const {
	return y;
	}

void point::scale(double m){
	x = m*x;
	y = m*y;
	}

void point::set_x(double ToSetX){
	x=ToSetX;
	}
	
void point::set_y(double ToSetY){
	y=ToSetY;
	}

void point::reflect_x(){
	y = -1 * y;
	}
	
void point::reflect_y(){
	x = -1 * x;
	}

void point::rotate(double r){
	double oldx = x;
	x = (x*cos(r)) - (y*sin(r));
	double x = oldx;
	y = (x*sin(r)) + (y*cos(r));
	}
	
bool point::operator == (const point& p){
		return(x == p.x && y == p.y);
		}
		
istream& operator >>(istream& ins, point& target) 
{
	ins >> target.x >> target.y; 
	return ins;
}

ostream& operator <<(ostream& outs, const point& source)
{
	outs << "(" << source.x << ", " << source.y << ")";
	return outs;
}

/*
point::point()

double point::get_x(){
	
	}

double point::get_y(){
	
	}

void point::set_x(){
	
	}

void point::set_y(){
	
	}

void point::scale(double m){
	
	}

void point::reflect_x(){
	
	}

void point::reflect_y(){
	
	}

void point::rotate(double r){
	
	}
*/
