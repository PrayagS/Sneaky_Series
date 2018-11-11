#include<stdio.h>
#include<string.h>
int main()
{
	FILE *upd;
	char usr[30]="jarvis2";
	int qid=32;
	char stat='0';
//  char status=stat+'0';
	upd=fopen("performance.csv", "r+");
	char *token, str[250];
	while(fscanf(upd,"%s",str)!=EOF)
	{
    	token=strtok(str,",");
    	if(!strcmp(token,usr))
    	{
      // for(int i=0; i<=qid; i++)
      // {
      //   token=strtok(NULL,",");
      // }
//      printf("\n%s\n",token);
      	fseek(upd,-2*(89-qid),1);
//      	char ch=getc(upd);
//      	printf("%c", ch);
      // printf("%c",getc(upd));
      // fseek(upd,-1,1);
      // Sleep(2000);
      // fseek(upd,-1,1);
    	fputc(stat,upd);
    	fseek(upd,0,1);
      break;
    }
  }
  fclose(upd);

	return 0;
}