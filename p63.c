#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#define LOOP_MAX 1000000

int main (void){
	unsigned long int i;
	int array[LOOP_MAX];
	int pointer[LOOP_MAX];
	int *p;

	clock_t a_start = clock();
	for ( i = 0 ; i < LOOP_MAX ; i++){
		array [i] = i + i * i;
		array [i] = (i + i * i) / (i+1) - array[i];
		printf("# array [ %d ] = %d \n", i , array[i]); 
		
	}
	clock_t a_end = clock();
	
	clock_t p_start = clock();
	for ( i = 0 ; i < LOOP_MAX ; i++){
		*(pointer + i) = i + i * i;
		*(pointer + i) = (i + i * i) / (i+1) - *(pointer+i);
		printf("#  *(p + %d)  %d \n", i , *(pointer+i) ); 
	}
	clock_t p_end = clock();

	double elapsed_a = (double)(a_end - a_start ) * 1000.0 / CLOCKS_PER_SEC;
	double elapsed_p = (double)(p_end - p_start ) * 1000.0 / CLOCKS_PER_SEC;

	printf ("### Time elapsed in ms : array : %lf\n" , elapsed_a);
	printf ("### Time elapsed in ms : pointer : %lf\n" , elapsed_p);

	return 0;
}
