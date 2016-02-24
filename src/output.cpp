#include <fstream> 
#include "output.h"
#include "basic_math.h"

using namespace std;
void generate_output (int counter, double input_points[], double result_x, double result_y, int mode)
{
	ofstream outFile;
	
	/*just to collect all data in one place, including input*/
	/*might slow down the process if input file is big and hdd is slow, but this is just for gnuplot drawing which will be used on small amounts of data*/
	outFile.open("data_2_points.txt"); 
	for (int i = 0; i < counter*2; i+=2)	   
	{
		outFile << input_points[i] << " " << input_points[i+1] << endl;
	}
	outFile.close();
	
	outFile.open("data_3_result.txt", std::ios_base::app | std::ios_base::out);
	outFile << endl << result_x <<" " << result_y;
	outFile.close();
	
	/*generating lines from input points to result in chosen metric for gnuplot*/
	outFile.open("data_1_lines.txt", std::ios_base::app | std::ios_base::out);
	double 	temp_affin_x, temp_affin_y,
			temp_x, temp_y;
	for (int i = 0; i < counter*2; i+=2)
	{
		switch (mode)
		{
			case 1:
				outFile << input_points[i] << " " << input_points[i+1] << endl 
				<< result_x << " " << result_y << endl << endl;
			break;
			
			case 2: case 4:
				temp_x = input_points[i];
				temp_y = result_y;	//no algorythm or optimization purpose, just to make this (and next, mainly) mode more obvious
				
				outFile << result_x			<< " " << result_y			<< endl 
						<< temp_x			<< " " << temp_y 			<< endl << endl;
						
				outFile << temp_x			<< " " << temp_y			<< endl 
						<< input_points[i]	<< " " << input_points[i+1] << endl << endl << endl;
			break;
			
			case 3:
				temp_affin_x = get_affin_x(result_x, result_y);					//same as previous: slide by [x] from start 
				temp_affin_y = get_affin_y(input_points[i], input_points[i+1]);	//and by [y] from destination
				temp_x = get_dekart_x(temp_affin_x, temp_affin_y);
				temp_y = get_dekart_y(temp_affin_x, temp_affin_y); 				//generating temp point coordiates
				
				outFile << result_x			<< " " << result_y			<< endl 
						<< temp_x			<< " " << temp_y 			<< endl << endl;
						
				outFile << temp_x			<< " " << temp_y			<< endl 
						<< input_points[i]	<< " " << input_points[i+1] << endl << endl << endl;
			break;
		}
	}
	outFile.close();
}

