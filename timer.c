#include <stdio.h>
#include <time.h>

int main()
{
	int countdown = 30, time_diff = 0, seconds = 0;
	clock_t start, counter;
	start = clock();
	int time_left = countdown - seconds;
	while (time_left > 0)
	{
		counter = clock();
		time_diff = counter - start;
		seconds = time_diff/(CLOCKS_PER_SEC);
		time_left = countdown - seconds;
	}
	printf("Time's UP!!\n");
	return 0;	
}