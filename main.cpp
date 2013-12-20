/*
	print out random strings 
	
	usage:
	
	./generate [lines] [length_one_line]
	
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>

using namespace std;

int main(int argc, char* argv[]){
	srand (time(NULL));
	int line_length, rand_length;
	float rnumber;
	int chindex, jindex;
	int lines;
	if ( argc == 1){	// generate 
		lines = 1;			// default 1 lines
		rand_length = -1;	// default line length random
	} else if (argc == 2) {		// generate [lines]
		lines = atoi( argv[1]);	
		rand_length = -1;			// default line length random
	} else {					// generate [lines] [length of one line]
		lines = atoi( argv[1]);	
		rand_length = 1;
		line_length = atoi( argv[2] );
	}
	
	for (unsigned long line_index = 0; line_index < lines; line_index++)
	{
		if ( rand_length < 0){	//random length
			float x = rand();
			line_length = (int) floor( 10000 * x / RAND_MAX ) % 33 + 10;
		} 
		
		for(int index=0; index< line_length; index++){
			rnumber = rand();
			chindex = (int) floor( 10000*rnumber/RAND_MAX ) %3;
			rnumber = rand();
			switch ( chindex){
				case 1:
					chindex = (int) floor( 10000*rnumber/RAND_MAX ) %26 + 65;
				break;
				case 2:
					chindex = (int) floor( 10000*rnumber/RAND_MAX ) %26 + 97;
				break;
				case 0:
					chindex = (int) floor( 10000*rnumber/RAND_MAX ) %10 + 48;
				break;
			}
			std::cout << char(chindex);
		}
		std::cout << "\n";
	}
	return 0;
}

