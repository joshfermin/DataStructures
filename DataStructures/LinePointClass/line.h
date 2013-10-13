#ifndef LINE_H_
#define LINE_H_ 
#include <iostream>
#include "point.h"

;class line
{
	
	public:
		line();
		line(point A);
		line(point B, point C);
		
		double slope() const;
		
		void operator = (const line& lineToCopy);
		
		void translate (double X, double Y);
		
		void reflect_x();
		void reflect_y();
		
		
	// for cin - dont include namespace std
	friend std::istream& operator >> (std::istream& ins, line& target);
	// for cout
	friend std::ostream& operator << (std::ostream& outs, const line& source);
	
	friend bool operator == (const line &firstLine, const line &secondLine);
	
	private:
		point p1;
		point p2;

// make slope constant

};

bool operator == (const line &firstLine, const line &secondLine);

#endif

// lines equal - slopes equal, same y intercept
