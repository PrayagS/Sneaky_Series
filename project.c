#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<unistd.h>

//Login functions
void start();
void login(int count);
void signup(int count);
//Menu functions
void menu();
void adminmenu();
void learn();
void quiz();
void seriescracker();
void userperformance();
void addquiz();
void sendmessage(int w, int x, int y, int z);
//Quiz functions
void getquestions();
void getstatus();
//E-learning functions
void learnhome(int section);
void Lprogressions();
void Ladvancedprogressions();
void Lstandardseries();
void Lsquaresandcubes();
void Lpreviousterms();
void Lmultipleseries();
void Lnavigation(int section);
//Series cracker functions
void a_progression(float w, float x, float y, float z, float* t1, float* t2, int *code);
void g_progression(float w, float x, float y, float z, float* t1, float* t2, int *code);
void h_progression(float w, float x, float y, float z, float* t1, float* t2, int *code);
void prime(float w, float x, float y, float z, float* t1, float* t2, int *code);
void da_progression(float w, float x, float y, float z, float* t1, float* t2, int *code);
void fibonacci(float w, float x, float y, float z, float* t1, float* t2, int *code);
void sumrelation(float w, float x, float y, float z, float* t1, float* t2, int *code);
void sumproduct(float w, float x, float y, float z, float* t1, float* t2, int *code);
void square_series(float w, float x, float y, float z, float* t1, float* t2, int *code);
void cube_series(float w, float x, float y, float z, float* t1, float* t2, int *code);
void factorial_series(float w, float x, float y, float z, float* t1, float* t2, int *code);
void squaresum_series(float w, float x, float y, float z, float* t1, float* t2, int *code);
void productpretwo_series(float w, float x, float y, float z, float* t1, float* t2, int *code);
float factorial(float x);

struct question
{
  float n[6];
  char code[5];
  int diff;
  char status;
}q[90], q0[30], q1[30], q2[30];

int check=0;
char username[30];

int main()
{
  start();
  return 0;
}

void start()
{
    FILE *fpc;
    fpc = fopen("login.txt","r");
    int usercount = 0;
    char ch1;
    ch1 = fgetc(fpc);
    while (ch1 != EOF)
    {
        ch1 = fgetc(fpc);
        if (ch1 == '\n')
        {
            ++usercount;
        }
    }
    fclose(fpc);
    usercount+=1;
    int choicel;
    printf("1. Login\n2. Sign Up\n\n");
    printf("Enter your choice : \n");
    scanf("%d",&choicel);
    if (choicel == 1)
    {
        login(usercount);
    }
    else
    {
        signup(usercount);
    }
}

void login(int count)
{
    int checku = 0, checkp = 0, fail=0;
    char password[30];
    logintop:
    system("cls");
    printf("Enter your username : \n");
    scanf("%s",username);
    printf("\nEnter your password : \n");
    char ch;
    int i=1;
    ch = getch();
    password[0] = ch;
    while(ch!=13 && i<30)
    {
        ch = getch();
        if (ch == 8)
        {
            i--;
            continue;
        }
        else if (ch != 13)
        {
            password[i] = ch;
            ++i;
        }   
    }
    password[i]='\0';
    char string[50], *token, ch2 = 'u';
    FILE *fp;
    fp = fopen("login.txt","r");
    fscanf(fp,"%s",string);
    int j = 1;
    while (j <= count)
    {
        token = strtok(string,",");
                if (strcmp(username,token) == 0)
                {
                    token = strtok(NULL,",");
                    if (strcmp(password,token) == 0)
                    {
                        {
                            printf("\nWelcome %s",username);
                            sleep(2);
                            token = strtok(NULL,",");
                            if (*token == ch2)
                            {
                                menu();
                            }
                            else
                            {
                                adminmenu();
                            }
                            break;
                        }
                    }
                    else
                    {
                      fail++;
                      break;
                    }
                }
                else
                {
                    fail++;
                    //goto logintop;
                    fscanf(fp,"%s",string);
                    ++j;
                }            
        }
       if(fail>0)
       {
        printf("\nYour username or password is wrong.\n\n");
        sleep(2);
        goto logintop;
       } 
}
void signup(int count)
{
    int i=1;
    char password[30], ch;
    system("cls");
    printf("Enter your username\n");
    scanf("%s",username);
    printf("\nEnter your password :\n");
    ch = getch();
    password[0] = ch;
    while(ch!=13 && i<20)
    {
        ch = getch();
        if (ch == 8)
        {
          if(i>0)
            i--;
            continue;
        }
        else if (ch != 13)
        {
            password[i] = ch;
            ++i;
        }   
    }
    password[i]='\0';
    FILE *fp2, *fpa;
    char* token; 
    char string[50];
    int checke=0;
    fp2 = fopen("login.txt", "r");
    for (int i = 0; i < count; ++i)
    {
        fscanf(fp2, "%s", string);
        token = strtok(string, ",");
        if (strcmp(token, username) == 0)
        {
            checke = 1;
            break;
        }
    }
    fclose(fp2);
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
        printf("\n\nThanks for using Sneaky Series. Hope you have a good time!\n\n");
        fp2=fopen("performance.csv", "a");
        fprintf(fp2,"%s,",username);
        for(int i=0; i<89; i++)
        {
        	fprintf(fp2,"n,");
        }
  
        fprintf(fp2,"n\n");
        fclose(fp2);
        sleep(2);
        menu();
    }

    ++count;
}

void menu()
{
  int choice;
  menubegin:
  system("cls");
  printf("1. E-learning - Get guidance on cracking any series problem\n2. Quiz - Think you know it all?\n3. Series Cracker - If you need help with a problem, we might be able to help you out\n4. Generate performance report\n");
  printf("Select your choice: ");
  scanf("%d", &choice);
  switch(choice)
  {
    case 1:
      learn();
      break;
    case 2:
      quiz();
      break;
    case 3:
      seriescracker();
      break;
    case 4:
      userperformance();
      break;
    default:
      printf("Invalid input. Please try again!");
      goto menubegin;
  }
}
void adminmenu()
{
  int choice;
  adminmenubegin:
  system("cls");
  printf("1. Generate performance of users of a particular topic.\n2. Generate performance report for a particular user.\n3. Compare topics on the basis of performance of users\n4. Add problems for quiz\n5. Read messages sent by users\n");
  printf("Select your choice: ");
  choice=getche();
  switch(choice)
  {
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    default:
      printf("Invalid input. Please try again.");
      sleep(1);
      goto adminmenubegin;
  }
}
void learn()
{
  int choice, selection;
  FILE *fpt;
  learnbegin:
  system("cls");
  printf("Select your choice: \n");
  printf("1. Continue from where you left.\n2. Jump to a topic.\n3. Start over");    
  scanf("%d", &choice);
  // choice=getche();
  switch(choice)
  {
    case 1:
      fpt = fopen("Track_Topic.txt","r");
      fscanf(fpt,"%d",&selection);
      printf("\n%d\n",selection);
      learnhome(selection);
      break;
    case 2:
      system("cls");
      printf("1. Progressions\n2. Advanced Progressions\n3. Standard Series\n4. Squares and Cubes\n5. Series having relation with previous terms\n6. Multiple series and combination of different series");
      printf("\nSelect your choice: ");
      scanf("%d", &selection);
      learnhome(selection);  
      break;
    case 3:
      selection=1;
      learnhome(selection);    
      break;
    default:
      goto learnbegin;
  }
}
void quiz()
{
  int choice;
  static check=0;
  system("cls");
  getreference();
  if(check==0)
  {
  	getquestions();
  	check++;  	
  }
  getstatus();
  printf("How strong you think you are?\n\n");
  printf("1. Take it easy, I'm new\n2. I know a few things pretty well.\n3. Bring it on. I'm a series god!\n\n");
  printf("Enter your choice: ");
  // scanf("%d", &choice);
  choice=getche();
  //functions for quiz
  if(choice==0)
  {
  	for(int i=0; i<30; i++)
  	{
  		
  	}
  }

}
void getquestions()
{
	FILE *fp, *fp2;
	int i=0, j=0, k=0, l=0;
	char str[300];
	// char qcode[5];
	// int diff;
	// float a,b,c,d,e,f;
	fp=fopen("quizdatabase.csv", "r");
	while(feof(fp))
	{
		fscanf(fp, "%s, %d, %f, %f, %f, %f, %f, %f", q[i].code, q[i].diff, q[i].n[0], q[i].n[1], q[i].n[2], q[i].n[3], q[i].n[4], q[i].n[5]);
		switch(q[i].diff)
		{
			case 0:
				q0[j]=q[i];
				j++;
				break;
			case 1:
				q1[k]=q[i];
				k++;
				break;
			case 2:
				q2[l]=q[i];
				l++;
				break;
		}
	}
	fclose(fp);
}
void getstatus()
{
	char *token;
	FILE *fp;
	fp=fopen("performance.csv", "r");
	fscanf(fp, "%s", str);
	token=strtok(str,",");
	if(strcmp(token, username)==0)
	{
		for(int i=0; i<90; i++)
		{
			token=strtok(NULL, ",");
			q[i].status=*token;
		}
	}
	while(feof(fp2))
	{
		fscanf(fp2, "%s", str);
		token=strtok(NULL,",");
		if(strcmp(token, username)==0)
		{
			for(int i=0; i<90; i++)
			{
				token=strtok(NULL, ",");
				q[i].status=*token;
			}
			break;
		}		
	}
	fclose(fp);
}
void seriescracker()
{
  int choice, code;
  float t[6];
  enterseries:
  system("cls");
  check=0;
  for(int i=0; i<4; i++)
  {
    printf("Enter number %d: ",i+1);
    scanf("%f", &t[i]);
  }
  a_progression(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    g_progression(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    h_progression(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    prime(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    fibonacci(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    sumproduct(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    square_series(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    cube_series(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    squaresum_series(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    productpretwo_series(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    da_progression(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    sumrelation(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    sendmessage(t[0],t[1],t[2],t[3]); //Change this
  if(check==1)
    printf("Next terms: %f, %f\n", t[4], t[5]);
  // printf("Do you wish to try another series? Y/n");
  // scanf("%d", &repeat);
  // if(repeat=='Y' || repeat=='y') 
  seriescrackerchoice: 
  printf("1. Enter another series\n2. Learn this topic\n3. Back to main menu\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  switch(choice)
  {
    case 1:
      goto enterseries;
      break;
    case 2:
      learnhome(code);
      break;
    case 3:
      menu();
    default:
      printf("Invalid input. Please try again");
      goto seriescrackerchoice;
  }
}
void userperformance()
{
  int choice;
  system("cls");
  printf("1. Generate report of a particular topic.\n2. Compare topics based on time taken to solve questions and accuracy\n\n");
  printf("Enter your choice: ");
  switch(choice)
  {
    case 1:
      break;
    case 2:
      break; 
  }
}
void a_progression(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  if((z-y) == (y-x) && (y-x) == (x-w))
  {
    check=1;
    printf("The series is an arithmetic progression with common difference %f\n", x-w);
    float u[2];
    u[0]=z+(z-y);
    u[1]=u[0]+(z-y);
    *t1 = u[0];
    *t2 = u[1];
    *code=1;
  }
  // else
  // {
  //   g_progression(w, x, y, z, &t1, &t2);
  // }
}
void g_progression(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  if((x/w)==(y/x) && (y/x)==(z/y))
  {
    check=1;
    printf("The series is an geometric progression with common ratio %f\n", x/w);
    float u[2];
    u[0]=z*(x/w);
    u[1]=u[0]*x/w;
    *t1 = u[0];
    *t2 = u[1];
    *code=1;
  }
}
void h_progression(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  if(1/x-1/w==1/y-1/x && 1/z-1/y==1/y-1/x)
  {
    check=1;
    printf("The series is a harmonic progression with common ratio %f\n", 1/x-1/w);
    float u[2];
    u[0]=1/z+(1/z-1/y);
    u[0]=1/u[0];
    u[1]=1/u[0]+(1/z-1/y);
    u[1]=1/u[1];
    *t1 = u[0];
    *t2 = u[1];
    *code=1;
  }
}
// void ag_progression(float w, float x, float y, float z, float* t1, float* t2)
// {
//   if()
// }
void prime(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  int n[4];
  n[0]=w;
  n[1]=x;
  n[2]=y;
  n[3]=z;
  float root;
  int temp;
  int pcheck=1;
  for(int i=0; i<4; i++)
  {
    if(pcheck==0)
      break;
    if(n[i]==0 || n[i]==1)
    {
      pcheck=0;
      break;
    }
    root=sqrt(n[i]); //Using Euclid's first lemma - if p divides n^2, p also divides n
    temp=2;
    while(temp<root)
    {
      if(n[i]%temp==0)
      {
        pcheck=0;
        break;
      }
      temp++;
    }
  }
  int j=0;
  float u[2];
  if(pcheck==1)
  {
    check=1;
    printf("The given series is a prime series.\n");
    for(int i=z+1; i<=101+z; i++)
    {
      root=sqrt(i);
      temp=2;
      while(temp<root)
      {
        if(i%temp==0)
          break;
        temp++;
      }
      if(i%temp==0)
        continue;
      u[j]=i;
      j++;
      if(j>1)
        break;
    }
  *t1 = u[0];
  *t2 = u[1];
  *code=3;
  }
}
void da_progression(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  if(((y-x)-(x-w))==((z-y)-(y-x)))
  {
    check=1;
    printf("The given series has difference between consecutive terms in an arithmetic progression\n");
    float u[2];
    u[0]=z+(z-y)+(z-y)-(y-x);
    u[1]=u[0]+(u[0]-z)+(z-y)-(y-x);
    *t1 = u[0];
    *t2 = u[1];
    *code = 2;
  }
}
void fibonacci(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  if(y==w+x && z==y+x)
  {
    check=1;
    printf("The given series is a Fibonacci series\n");
    float u[2];
    u[0]=z+y;
    u[1]=u[0]+z;
    *t1 = u[0];
    *t2 = u[1];
    *code = 3;
  }
}
void sumrelation(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  int i,j;
  for(i=-100; i<=100; i++)
  {
    if(check==1)
    {
      i--;
      break;
    }
    for(j=-100; j<=100; j++)
    {
      if(y==i*x+j*w)
      {
        if(z==i*y+j*x)
        {
          check=1;
          break;
        }
      }
    }
  }
  if(check==1)
  {
    printf("The given series has a relation with previous terms: x(n) = %d*x(n-1)+%d*x(n-2)\n", i, j);
    float u[2];
    u[0]=i*z+j*y;
    u[1]=i*u[0]+j*z;
    *t1 = u[0];
    *t2 = u[1];
    *code = 5;    
  }
}
void sumproduct(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  int i, j;
  for(i=-100; i<=100; i++)
  {
    if(check==1)
      break;
    for(j=-100; j<=100; j++)
    {
      if(x==i*w+j)
      {
        if(y==i*x+j)
        {
          if(z==i*y+j)
          {
            check=1;
            break;
          }
        }
      }  
    }
  }
  if(check==1)
  {
    printf("The given series has a relation with previous terms: x(n) = %d*x(n-1)+%d\n", i, j);
    float u[2];
    u[0]=i*z+j;
    u[1]=i*u[0]+j;
    *t1 = u[0];
    *t2 = u[1];    
    *code=5; 
  }
}
void square_series(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  float w1, x1, y1, z1, u[2];
  w1 = sqrt(w);
  x1 = sqrt(x);
  y1 = sqrt(y);
  z1 = sqrt(z);
  if ((z1-y1) == (y1-x1) == (x1-w1))
  {
    check=1;
    printf("The given series is square of an arithmetic progression\n");
    u[0] = z1+(z1-y1);
    u[1] = u[0]+(z1-y1);
    *t1 = pow(u[0],2);
    *t2 = pow(u[1],2);
    *code=4;
  } 
}

void cube_series(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  float w1, x1, y1, z1, u[2];
  w1 = cbrt(w);
  x1 = cbrt(x);
  y1 = cbrt(y);
  z1 = cbrt(z);
  if ((z1-y1) == (y1-x1) == (x1-w1))
  {
    check=1;
    printf("The given series is cube of arithmetic progression.\n");
    u[0] = z1+(z1-y1);
    u[1] = u[0]+(z1-y1);
    *t1 = pow(u[0],3);
    *t2 = pow(u[1],3);
    *code=4;
  }
}

float factorial(float x)
{
  float fact = 1;
  for (int i = 1; i <= x; ++i)
  {
    fact = fact * i;
  }
  return fact;
}

void factorial_series(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  int flags[4], w1, x1, y1, z1;
  for (int i = 0; i < 4; ++i)
  {
    flags[i] = 0;
  }
  for (int i = 0; i < 8; ++i)
  {
    if (w == factorial(i))
    {
      flags[0] = 1;
      w1 = i;
    }
    if (x == factorial(i))
    {
      flags[1] = 1;
      x1 = i;
    }
    if (y == factorial(i))
    {
      flags[2] = 1;
      y1 = i;
    }
    if (z == factorial(i))
    {
      flags[3] = 1;
      z1 = i;
    }
    else
    {
      continue;
    }
  }
  if (flags[0] == 1 && flags[1] == 1 && flags[2] == 1 && flags[3] == 1 && (z1-y1) == (y1-x1) && (y1-x1) == (x1-w1)) 
  {
    check=1;
    printf("The given series is a factorial series.\n");
    float a = z1+1, b=z1+2;
    *t1 = factorial(a);
    *t2 = factorial(b);
    *code=3;
  }
}

void squaresum_series(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  float w1, x1, y1, z1, u[2];
  for (int i = -100; i <= 100; ++i)
  {
    // if (i < 0)
    // {
    //   w1 = w + abs(i);
    //   x1 = x + abs(i);
    //   y1 = y + abs(i);
    //   z1 = z + abs(i);
    // }
    // else
    // {
      w1 = w - i;
      x1 = x - i;
      y1 = y - i;
      z1 = z - i;
    // }
    w1 = sqrt(w1);
    x1 = sqrt(x1);
    y1 = sqrt(y1);
    z1 = sqrt(z1);
    if ((z1-y1) == (y1-x1) && (y1-x1) == (x1-w1))
    {
      printf("The given series is of the general form n^2+k where k is %d\n", i);
      u[0] = pow((z1+1),2) + i;
      u[1] = pow((z1+2),2) + i;
      *t1 = u[0];
      *t2 = u[1];
      *code=6;
      break;
    }     
  }
}

void productpretwo_series(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  float u[2];
  for (int i = -100; i <= 100; ++i)
  {
    if (y == (i*w*x) && z == (i*y*x))
    {
      check=1;
      printf("The given series is of the general form k*x(n-1)*x(n-2) where k is %d\n", i);
      u[0] = i*z*y;
      u[1] = i*z*u[0];
      *t1 = u[0];
      *t2 = u[1];
      *code=5;
    }
  }
}
void learnhome(int section)
{
  char anykey, prog;
  switch(section)
  {
    case 1:
      Lprogressions();
      Lnavigation(section);
      break;
    case 2:
      Ladvancedprogressions();
      Lnavigation(section);
      break;
    case 3:
      Lstandardseries();
      Lnavigation(section);
      break;
    case 4:
      Lsquaresandcubes();
      Lnavigation(section);
      break;
    case 5:
      Lpreviousterms();
      Lnavigation(section);
      break;
    case 6:
      Lmultipleseries();
      printf("Press any key to go back to main menu. ");
      anykey=getche();
      menu();
      break;
  }
}
void Lprogressions()
{
  system("cls");
  printf("Progressions\n");
  FILE *fp;
  char c;
  fp=fopen("progressions.txt", "r");
  while((c=getc(fp))!=EOF)
    putchar(c);
  fclose(fp);
}
void Ladvancedprogressions()
{
  system("cls");
  printf("Advanced Progressions\n");
  FILE *fp;
  char c;
  fp=fopen("advancedprogressions.txt", "r");
  while((c=getc(fp))!=EOF)
    putchar(c);
  fclose(fp);  
}
void Lstandardseries()
{
  system("cls");
  printf("Standard Series\n");
  FILE *fp;
  char c;
  fp=fopen("standardseries.txt", "r");
  while((c=getc(fp))!=EOF)
    putchar(c);
  fclose(fp);  
}
void Lsquaresandcubes()
{
  system("cls");
  printf("Squares and Cubes\n");
  FILE *fp;
  char c;
  fp=fopen("squaresandcubes.txt", "r");
  while((c=getc(fp))!=EOF)
    putchar(c);
  fclose(fp);  
}
void Lpreviousterms()
{
  system("cls");
  printf("Series based on previous terms\n");
  FILE *fp;
  char c;
  fp=fopen("previousterms.txt", "r");
  while((c=getc(fp))!=EOF)
    putchar(c);
  fclose(fp);  
}
void Lmultipleseries()
{
  system("cls");
  printf("Multiple series and combinations of different series\n");
  FILE *fp;
  char c;
  fp=fopen("multipleseries.txt", "r");
  while((c=getc(fp))!=EOF)
    putchar(c);
  fclose(fp);  
}
void Lnavigation(int section)
{
  char choice;
  printf("\n\nPress 0 to go back to main menu\n");
  printf("Press any other key to continue");
  // scanf("%s", &choice);
  choice=getche();
  if(choice==10)
    learnhome(section+1);
  // choice=getchar();
  if(choice=='0')
  {
  	FILE *fptrack;
  	fptrack = fopen("Track_Topic.txt","w");
  	fprintf(fptrack, "%d", section);
  	fclose(fptrack);
    menu();
  }	
  else
    learnhome(section+1);

}
void sendmessage(int w, int x, int y, int z)
{
  int choice, i=0;
  char s[1000];
  FILE *fp;
  printf("\nOops. Seems like the program isn't equipped to crack this series yet.\n");
  sendmessagebegin:
  printf("Do you wish to send a message to admin?y\\N \n");
  choice=getche();
  switch(choice)
  {
    case 'Y':
    case 'y':
      fp=fopen("messages.txt", "a");
      // fprintf(fp, "%s , ",username);
      printf("Enter your message here. When completed, press return twice: ");
      do
      {
        s[i]=getchar();
        if(s[i]==10)
        {
          if(i>1 && s[i-1]==10)
          {
            s[i-1]='\0';
            break;
          }
        }
        i++;
      }while(1);
      printf("\n%c\n",s[0]);
      for (int i = 1; i < strlen(s); ++i)
      {
      	s[i-1] = s[i];
      }
      fprintf(fp, "%s, %s, %d, %d, %d, %d\n",username, s, w, x, y, z); 
      fclose(fp);
      printf("Thank you. Your message has been sent along with the problem you entered!\n"); 
      break;
    case 'N':
    case 'n':
      break;
    default:
      printf("Invalid input. Please try again!\n");
      goto sendmessagebegin;
  }


}