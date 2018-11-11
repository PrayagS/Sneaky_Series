#include<stdio.h>
#include<windows.h>
#include<string.h>
int main()
{
	char username[30]="panparag";
	char fname[45]=strcat(username,"_per.dat");
	FILE *userp;
	userp=fopen(fname, "a");
	fprintf(userp,"Easy, ")
	return 0;
}