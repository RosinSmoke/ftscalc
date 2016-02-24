#include "basic_math.h"
#include "slicer.h"

double * list_of_sectors(double x1, double y1, double x2, double y2) /*slices input rectangle in 3x3 grid*/ 
{
    double half_of_sector_x = (x2-x1)/6 , half_of_sector_y = (y2-y1)/6;
    double * output = new double[20]; /*9 centers of 9 sectors + sample of its half in the first 2 values*/
									  /*TODO: add changeable grid size and separate variables for half-sectors*/
									  /*will increase accuracy to <grid_size>^( (-1)*<step_number> ) on each iteration*/
    output[0] = half_of_sector_x; output[1] = half_of_sector_y;

	//printf("list_of_sectors counted these sector centers:\n"); /*debug*/
    output[2]  = x1 + 1*half_of_sector_x; output[3]  = y1 + 1*half_of_sector_y;
    output[4]  = x1 + 3*half_of_sector_x; output[5]  = y1 + 1*half_of_sector_y;
    output[6]  = x1 + 5*half_of_sector_x; output[7]  = y1 + 1*half_of_sector_y;
    
    output[8]  = x1 + 1*half_of_sector_x; output[9]  = y1 + 3*half_of_sector_y;
    output[10] = x1 + 3*half_of_sector_x; output[11] = y1 + 3*half_of_sector_y;
    output[12] = x1 + 5*half_of_sector_x; output[13] = y1 + 3*half_of_sector_y;

    output[14] = x1 + 1*half_of_sector_x; output[15] = y1 + 5*half_of_sector_y;
    output[16] = x1 + 3*half_of_sector_x; output[17] = y1 + 5*half_of_sector_y;
    output[18] = x1 + 5*half_of_sector_x; output[19] = y1 + 5*half_of_sector_y;

    return output;
}

double * narrow_sector(double * input_sector, double input_points[], int n, int mode)
{
    double * output_sector = new double[4];
    double * gained_sectors = list_of_sectors(input_sector[0], input_sector[1], input_sector[2], input_sector[3]);
    int ns_i, sector_number = 0; 
	double shortest_dist = DBL_MAX, temp;

    for(ns_i = 0; ns_i < 9; ns_i++)
    {
		temp = sum_of_lengths(gained_sectors[(ns_i+1)*2], gained_sectors[(ns_i+1)*2+1], input_points, n, mode);
		if ( temp < shortest_dist) 
		{
			shortest_dist = temp;
			sector_number = ns_i;
		}
    }

    output_sector[0] = gained_sectors[(sector_number+1)*2] - gained_sectors[0];   /*forming result rectangle coordinates*/
    output_sector[1] = gained_sectors[(sector_number+1)*2+1] - gained_sectors[1]; /*probably could just output one corner and half-sectors and save some memory*/
    output_sector[2] = gained_sectors[(sector_number+1)*2] + gained_sectors[0];
    output_sector[3] = gained_sectors[(sector_number+1)*2+1] + gained_sectors[1];
    return output_sector;
}


