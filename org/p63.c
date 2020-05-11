#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#define LOOP_MAX 1000000

int main (void){
	int i;
	int array[LOOP_MAX];
	int pointer[LOOP_MAX];
	int *p;


	clock_t array_start, array_end , pointer_start, pointer_end;
	double cpu_time_used_array;
	double cpu_time_used_array2;
	double cpu_time_used_pointer;
	double cpu_time_used_pointer2;

	struct timespec wall_time_array_start ;
	struct timespec wall_time_array_end ;
	struct timespec wall_time_pointer_start ;
	struct timespec wall_time_pointer_end ;

	time_t array_start_timet; 
	//array_start_timet = time ( &array_start_timet);
	time_t array_end_timet; 
	//array_start_timet = time ( &array_start_timet);
	time_t p_start_timet; 
	time_t p_end_timet; 



	array_start = clock;
	clock_gettime(CLOCK_REALTIME , &wall_time_array_start);	
	array_start_timet = time ( &array_start_timet);
	clock_t a_start = clock();
	for ( i = 0 ; i < LOOP_MAX ; i++){
		array [i] = i + i * i;
		printf("# array [ %d ] = %d \n", i , array[i]); 
		
	}
	clock_t a_end = clock();
	array_end_timet = time ( &array_end_timet);
	array_end = clock;
	clock_gettime(CLOCK_REALTIME , &wall_time_array_end);	
	
	pointer_start = clock;
	clock_gettime(CLOCK_REALTIME , &wall_time_pointer_start);	
	p_start_timet = time ( &p_start_timet);
	clock_t p_start = clock();
	for ( i = 0 ; i < LOOP_MAX ; i++){
		*(pointer + i) = i + i * i;
		printf("#  *(p + %d)  %d \n", i , *(pointer+i) ); 
	}
	clock_t p_end = clock();
	p_end_timet = time ( &p_end_timet);
	pointer_end = clock;

	double elapsed_a = (double)(a_end - a_start ) * 1000.0 / CLOCKS_PER_SEC;
	double elapsed_p = (double)(p_end - p_start ) * 1000.0 / CLOCKS_PER_SEC;

	printf ("### Time elapsed in ms : array : %lf\n" , elapsed_a);
	printf ("### Time elapsed in ms : pointer : %lf\n" , elapsed_p);

	printf ("#### array loop start time %lf\n", array_start_timet);
	printf ("#### array loop end time %lf\n", array_end_timet);
	printf ("#### pointer loop start time %lf\n", p_start_timet);
	printf ("#### pointer loop end time %lf\n", p_end_timet);


	clock_gettime(CLOCK_REALTIME , &wall_time_pointer_end);	

	cpu_time_used_array = (double)(array_end - array_start) / CLOCKS_PER_SEC;
	cpu_time_used_array2 = (double)(array_end - array_start) ;
	printf ("#### array loop cpu time %f\n", cpu_time_used_array2);

	cpu_time_used_pointer = (double)(pointer_end - pointer_start) / CLOCKS_PER_SEC;
	cpu_time_used_pointer2 = (double)(pointer_end - pointer_start) ;
	printf ("#### pointer loop cpu time %f\n", cpu_time_used_pointer2 );


	//printf ("#### array loop wall time %lf\n", (double)(wall_time_array_end.tv_sec + wall_time_array_end.tv_uesc*1e-6 )- (double)( wall_time_array_start.tv_sec + wall_time_array_start.tv_usec * 1e-6 ) );
	printf ("#### pointer loop wall time %lf\n", wall_time_pointer_end.tv_sec - wall_time_pointer_start.tv_sec );


	return 0;
}
