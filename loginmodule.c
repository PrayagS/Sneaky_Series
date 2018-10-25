#include <stdio.h>
#include <string.h>
#include <conio.h>

int checku = 0, checkp = 0; // GLOBAL VARIABLES

void login(int count);
void signup(int count);

int main()
{
	printf("1. Login\n\n2. Sign Up\n\n");
	int choicel;
	printf("Enter your choice : ");
	scanf("%d",&choicel);
	FILE *fp;
	int count=0; // NO. OF USERS
	fp = fopen("login.txt", "r");
	char ch2;
	ch2 = fgetc(fp);
	while(ch2 != EOF)
	{
		ch2 = fgetc(fp);
		if (ch2 == '\n')
		{
			++count;
		}
	}
	fclose(fp);
	count+=2;
	if (choicel == 1)
	{
		login(count);
		while (checku == 0 || checkp == 0)
		{
			printf("\n\nYour username or password is wrong. Please try again.\n\n");
			login(count);
		}
	}
	else 
	{
		signup(count);
	}
	return 0;
}

void login(int count)
{
	FILE *fp;
	int i=1;
	char ch, ch1, string[50], username[20], password[20], category[2];
	printf("\nEnter your username :\n");
	scanf("%s",username);
	printf("Enter your password :\n");
	ch = getch();
	password[0] = ch;
	while(ch!=13 && i<20)
	{
		if (i == 1)
		{
			printf("*");
		}
		ch = getch();
		if (ch == 8)
		{
			continue;
		}
		else if (ch != 13)
		{
			printf("*");
			password[i] = ch;
			++i;
		}	
	}
	password[i]='\0';
	char* token;
	fp = fopen("login.txt", "r");
	fscanf(fp, "%s", string);
	int j=1;
	while(j <= count)
	{
		token = strtok(string, ",");
		int i=1;
		 while(i <= 2)
		 {
		 	if (i == 1)
		 	{
		 		if (strcmp(username, token) == 0)
		 		{
		 			checku = 1;
		 		}
		 	}
		 	if (i == 2)
		 	{
		 		if (strcmp(password, token) == 0)
		 		{
		 			checkp = 1;
		 		}
		 	}
		 	else
		 	{
		 		if (strcmp(token, "a") == 0)
		 		{
		 			ch1 = 'a'; // ADMIN MENU CALL
		 		}
		 		else
		 		{
		 			ch1 = 'u'; // USER MENU CALL
		 		}
		 	}
		 	if (checku == 1 && checkp == 1)
		 	{
		 		printf("\n\nWelcome %s\n\n",username);
		 		break;
		 	}
		 	i=i+1;
		 	token = strtok(NULL, ",");
		 }
		 if (checku == 1 && checkp == 1)
		 {
		 	break;
		 }
		 fscanf(fp, "%s", string);
		++j;
	}	
	fclose(fp);
}

void signup(int count)
{
	int i=1;
	char username[20], password[20], ch;
	printf("\nEnter your username\n");
	scanf("%s",username);
	printf("\nEnter your password :\n");
	ch = getch();
	password[0] = ch;
	while(ch!=13 && i<20)
	{
		if (i == 1)
		{
			printf("*");
		}
		ch = getch();
		if (ch == 8)
		{
			continue;
		}
		else if (ch != 13)
		{
			printf("*");
			password[i] = ch;
			++i;
		}	
	}
	password[i]='\0';
	FILE *fp, *fpa;
	char* token; 
	char string[50];
	int checke=0;
	fp = fopen("login.txt", "r");
	for (int i = 0; i < count; ++i)
	{
		fscanf(fp, "%s", string);
		token = strtok(string, ",");
		if (strcmp(token, username) == 0)
		{
			checke = 1;
			break;
		}
	}
	fclose(fp);
	if (checke == 1)
	{
		printf("\n\nUsername already exists. Please use another one.\n");
		signup(count);
	}
	else
	{
		fpa = fopen("login.txt", "a");
		fprintf(fpa, "\n%s,%s,u",username,password);
		fclose(fpa);
	}
	printf("\n\nThanks for using Sneaky Series. Hope you have a good time!\n\n");
	++count;
}
