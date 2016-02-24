#include <math.h>
#include "basic_math.h"
#include <algorithm>

double 	c11 = 1,  c12 = 1,
		c21 = -1, c22 = 1; /*TODO: add ability to set custom affin coordinates as console key*/

double distance_euclid(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

double distance_ny(double x1, double y1, double x2, double y2)
{
    return (fabs(x1-x2) + fabs(y1-y2));
}

void set_affin_vectors(double a)
{
    double x = sqrt(1/(a*a+1));
    c11 =  x; c12 = a*x;
    c21 = -x; c22 = a*x;
}

double get_affin_x(double x, double y)
{
    return (c22*x - c12*y)/(c11*c22 - c21*c12);
}

double get_affin_y(double x, double y)
{
    return (c11*y - c21*x)/(c11*c22 - c21*c12);
}

double get_dekart_x(double affin_x, double affin_y)
{
	return c11*affin_x + c12*affin_y;
}

double get_dekart_y(double affin_x, double affin_y)
{
	return c21*affin_x + c22*affin_y;
}

double distance_affin(double x1, double y1, double x2, double y2)
{
    return fabs(get_affin_x(x1,y1) - get_affin_x(x2,y2) ) + fabs(get_affin_y(x1,y1) - get_affin_y(x2,y2) );
    /*return distance_ny(get_affin_x(x1,y1), fabs(get_affin_y(x1,y1), get_affin_x(x2,y2), get_affin_y(x2,y2) );*/
}

double distance_l_inf(double x1, double y1, double x2, double y2)
{
	return std::max( fabs(x1 - x2) , fabs(y1 - y2));
}

double sum_of_lengths(double x0, double y0, double input_points[], int n, int mode)
{
	int i;
	double output = 0;
	for (i = 0; i < n; i++)
	{
		switch (mode)
		{
			case 1:
				output += distance_euclid    (x0, y0, input_points[i*2], input_points[i*2+1]);
			break;
			
			case 2:
				output += distance_ny        (x0, y0, input_points[i*2], input_points[i*2+1]);
			break;
			
			case 3:
				output += distance_affin     (x0, y0, input_points[i*2], input_points[i*2+1]);
			break;
			
			case 4:
				output += distance_l_inf     (x0, y0, input_points[i*2], input_points[i*2+1]);
			break;
		}
	}
	return output;
}
