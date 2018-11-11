#include<stdio.h>

int main()
{

	return 0;
}
void setcolor()
{
	time_t t;
	int color;
	srand((unsigned) time(&t));
	color=rand()%10;
	switch(color)
	{
		case 1:
			system("color 0A");
			break;
		case 2:
			system("color 17");
			break;
		case 3:
			system("color 2A");
			break;
		case 4:
			system("color 3F");
			break;
		case 5:
			system("color 4E");
			break;
		case 6:
			system("color 5B");
			break;
		case 7:
			system("color 6E");
			break;
		case 8:
			system("color 7C");
			break;
		case 9:
			system("color 9E");
			break;

	}
}