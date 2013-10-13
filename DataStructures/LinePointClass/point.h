//Josh Fermin

#ifndef POINT_H_
#define POINT_H_ 

#include <iostream>

;class point
{
	
	public:
		point();
		point(double x_in, double y_in);
			// or point(double x_in = 0, double y_in = 0);
			
		void translate(double x_in, double y_in);
		double get_x() const;
		double get_y() const;
		
		void scale(double m);
		
		void set_x(double ToSetX);
		void set_y(double ToSetY);
		
		void reflect_x();
		void reflect_y();
		
		void rotate(double r);
		
		bool operator == (const point& p);
		
		
	//for cin - dont include namespace std
	friend std::istream& operator >> (std::istream& ins, point& target);
	//for cout
	friend std::ostream& operator << (std::ostream& outs, const point& source);
	
	private:
		double x;
		double y;
		
};

#endif
