#ifndef SLICER_H
#define SLICER_H
#pragma once

#define DBL_MAX    1.7976931348623157E+308

double * list_of_sectors(double x1, double y1, double x2, double y2); /*slices input rectangle in 9*/

double * narrow_sector(double * input_sector, double input_points[], int n, int mode);

#endif 
