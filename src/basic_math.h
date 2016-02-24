#ifndef BASIC_MATH_H
#define BASIC_MATH_H
#pragma once

extern double c11, c12, c21, c22;

double distance_euclid(double x1, double y1, double x2, double y2);

double distance_ny(double x1, double y1, double x2, double y2);

double distance_l_inf(double x1, double y1, double x2, double y2);

void set_affin_vectors(double a);

double get_affin_x(double x, double y);

double get_affin_y(double x, double y);

double get_dekart_x(double affin_x, double affin_y);

double get_dekart_y(double affin_x, double affin_y);

double distance_affin(double x1, double y1, double x2, double y2);

double sum_of_lengths(double x0, double y0, double input_points[], int n, int mode);

#endif 
