#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
void startup();
void startupcolors();
void entry();
void gotoxy(int x, int y);
int main()
{
	startupcolors();
	Sleep(50);
	system("color 07");
//	startup();
	entry();
	return 0;

}

void gotoxy(int x, int y) 
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
COORD position={x,y};
SetConsoleCursorPosition(h,position);
}

void entry()
{
	for(int j=1; j<=12; j++)
	{
		gotoxy(40, j);
		for(int i=0; i<30;i++)
			printf("%c", 219);
		gotoxy(47,j+1);
		printf("Sneaky Series!");
		gotoxy(40,j+2);
		for(int i=0; i<30;i++)
			printf("%c", 219);		
		Sleep(50);
		gotoxy(40, j);
		if(j==12)
			break;
		for(int i=0; i<30; i++)
			printf(" ");
		gotoxy(47,j+1);
		printf("               ");
		gotoxy(40,j+2);
		for(int i=0; i<30;i++)
			printf(" ");		

	}
}
void startupcolors()
{
	time_t t;
	int color;
	srand((unsigned) time(&t));
	for(int i=0; i<10; i++)
	{
		color=rand()%16;
		switch(color)
		{
			case 0:
				system("color");
				Sleep(100);
				break;
			case 1:
				system("color 10");
				Sleep(100);
				break;	
			case 2:
				system("color 20");
				Sleep(100);
				break;
			case 3:
				system("color 30");
				Sleep(100);
				break;
			case 4:
				system("color 40");
				Sleep(100);
				break;
			case 5:
				system("color 50");
				Sleep(100);
				break;
			case 6:
				system("color 60");
				Sleep(100);
				break;
			case 7:
				system("color 70");
				Sleep(100);
				break;
			case 8:
				system("color 80");
				Sleep(100);
				break;
			case 9:
				system("color 90");
				Sleep(100);
				break;
			case 10:
				system("color A0");
				Sleep(100);
				break;
			case 11:
				system("color B0");
				Sleep(100);
				break;
			case 12:
				system("color C0");
				Sleep(100);
				break;
			case 13:
				system("color D0");
				Sleep(100);
				break;
			case 14:
				system("color E0");
				Sleep(100);
				break;
			case 15:
				system("color F0");
				Sleep(100);
				break;
		}	
	}		
}

void startup()
{

}