#include<stdio.h>
#include<string.h>
int main()
{
	char pass[50], check[50]="pass";
	int i=1; char ch;
	ch=getch();
	if(isalpha(ch) || isdigit(ch) || ch=='!' || ch=='@' || ch=='#' || ch=='$' || 
	ch=='%' || ch=='^' || ch=='&' || ch=='*' || ch=='(' || ch==')' || ch=='[' || ch==']' ||  ch=='{' || ch=='}' ||
	ch=='\\' || ch=='|' || ch==':' || ch==';' || ch=='"' || ch=='\'' || ch=='<' || ch=='>' || ch=="," 
	|| ch=='.' || ch=='/' || ch=='?' || ch=='-' || ch=='_' || ch=='=' || ch=='+')
	{
		pass[0]=ch;
	}

	while(pass[i-1]!=13)
	{
		ch=getch();
		if(isalpha(ch) || isdigit(ch) || ch=='!' || ch=='@' || ch=='#' || ch=='$' || 
			ch=='%' || ch=='^' || ch=='&' || ch=='*' || ch=='(' || ch==')' || ch=='[' || ch==']' ||  ch=='{' || ch=='}' ||
			ch=='\\' || ch=='|' || ch==':' || ch==';' || ch=='"' || ch=='\'' || ch=='<' || ch=='>' || ch=="," 
			|| ch=='.' || ch=='/' || ch=='?' || ch=='-' || ch=='_' || ch=='=' || ch=='+')
		{
			pass[i]=ch;
			i++;
		}
		if(ch=='8')
		{
			i--;
		}
	}
	return 0;
	
}