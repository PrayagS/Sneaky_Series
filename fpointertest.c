#include<stdio.h>

int main()
{
	FILE *fp;
	int check=0;
	// char *check;
	fp=fopen("guest_score.dat", "r");
	// if(c=getc(fp)!=EOF)
		fscanf(fp,"%d", &check);
		// fscanf(fp,"%s", check);
		// fscanf(fp,"%s", check);
		// fscanf(fp,"%s", check);
		// fscanf(fp,"%s", check);
		// fscanf(fp,"%s", check);
		// fscanf(fp,"%s", check);
	fclose(fp);
	printf("%d", check);
	return 0;
}