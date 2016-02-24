#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "slicer.h"
#include "output.h"

int runmode = 0;

int main(int argc, const char* argv[])
{
	int n = 0, i = 0, shortest_dist;
	double search_array[9], border_sector[4], sharpness = 0.000001;
	
	/*there it'll get console option, 1 is for Euclidis metric, 2 is for NY, 3 is for custom affin NY, 4 is for l_inf*/
	if ( argc > 1 && atoi(argv[1]) > 0 && atoi(argv[1]) < 5) 
    	runmode = atoi( argv[1] );
	else runmode = 1;
	
	std::ifstream myfile("input.txt");
	
	std::string linecounterline;
	while (std::getline(myfile, linecounterline)) //count rows with input points
		n++;
	double points[n*2];
	
	//printf("%d rows found\n\n", n);
	
	myfile.clear();                 // clear fail and eof bits
	myfile.seekg(0, std::ios::beg); // back to start
	for (i = 0; i < n*2; i++)
		myfile >> points[i];
	
	/*printf("001 Input coordinates:\n"); //debug
	for(i=0; i < n; i++)
	{
		printf("%f ", points[i*2]);
		printf("%f \n", points[i*2+1]);
	}
	printf("\n");*/
	
	/*finding first sector corners*/
	double min_x = points[0], min_y = points[1], max_x = points[0], max_y = points[1];
	for(i = 1; i < n; i++)
	{
		if (points[i*2] < min_x) min_x=points[i*2];
		if (points[i*2] > max_x) max_x=points[i*2];
		
		if (points[i*2+1] < min_y) min_y=points[i*2+1];
		if (points[i*2+1] > max_y) max_y=points[i*2+1];
	}
	
	/*printf("002 min_x = %f, min_y = %f\n", min_x, min_y);*/	/*debug*/
	/*printf("003 max_x = %f, max_y = %f\n\n", max_x, max_y);*/
	
	double * test_array;
	test_array = list_of_sectors(min_x, min_y, max_x, max_y);
	
	/*printf("004 min_x = %f, min_y = %f\n", min_x, min_y);*/	/*debug*/
	/*printf("005 max_x = %f, max_y = %f\n\n", max_x, max_y);*/
	
	/*printf("006 It got min and max coordinates and sliced to sectors:\n");
	for (i = 0; i < 20; i = i+2)
	printf("%f %f\n", test_array[i], test_array[i+1]);
	printf("\n");*/
	
	border_sector[0] = min_x; border_sector[1] = min_y;
	border_sector[2] = max_x; border_sector[3] = max_y;
	
	/*printf("007 min_x = %f, min_y = %f\n", min_x, min_y);*/	/*debug*/
	/*printf("008 max_x = %f, max_y = %f\n\n", max_x, max_y);*/
	
	double * sector_to_narrow = border_sector; i = 0;
	//for(i = 0; i < 16; i++)
	i = 0;
	do
	{
		sector_to_narrow = narrow_sector(sector_to_narrow, points, n, runmode);
		i++;
		
		/*printf("_%d sector narrowed:", i);*/  //uncomment this to demonstrate current step
		/*printf("\n%f %f\n%f %f\n\n", 
				sector_to_narrow[0], 			//uncomment this to demonstrate current sector
				sector_to_narrow[1], 
				sector_to_narrow[2], 
				sector_to_narrow[3]      );*/
		/*printf("%f %f\n", sector_to_narrow[2] - sector_to_narrow[0],		//uncomment this to demonstrate current sector size
							sector_to_narrow[3] - sector_to_narrow[1]);*/ 

	}	while ( sector_to_narrow[2] - sector_to_narrow[0] > sharpness ||
				sector_to_narrow[3] - sector_to_narrow[1] > sharpness    ); 
	
	generate_output (n, points, sector_to_narrow[0], sector_to_narrow[1], runmode);
	      
	/*printf("000 Finished");*/  /*debug*/
	//scanf("%d", i);
	return 0;
}

