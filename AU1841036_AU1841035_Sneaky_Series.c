
//Group Members :
// Yashraj Kakkad - AU1841036
// E-mail - kakkad.m@ahduni.edu.in
// Prayag Savsani - AU1841035
// E-mail - prayag.s@ahduni.edu.in

//If using Dev-C++, please enable C99 features. Else, GCC works fine.

//We have not yet finished coding the quiz performance report and admin functions for generating user performance
//Rest of the program is fully functional - series cracker is the main highlight of the project.
//The series cracker can crack most of the standard series asked in competitive exams using computations. 
//It doesn't store any data and is purely based on logic
//To help you test the program better, we have given some sample questions in questions.txt file attached for you to enter in the program


#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>

//Startup functions
void startupcolors(); //Generates random color combinations during startup
void entry(); //Sneaky series title moving entry
void gotoxy(int x, int y);
//Login functions
void start();
void login(int count); //Backspace is supported, program is multi-user
void signup(int count);
//Menu functions
void menu();
void adminmenu(); //Pending part
void learn();
void quiz();
void seriescracker();
void userperformance();
float averagetime(float time);
void admintopic(char *user, int topic);
void usertopicgraph(char *user,int correct,int wrong);
void admintopicgraph(char user[][30], float *accuracy);
void adminUserReport(char *user);
//void addquiz();
void sendmessage(int w, int x, int y, int z); //You can send message to admin if series cracker doesn't crack your series
void displaymessage();
//Quiz functions
int qidtotopic(int qid);
void getquestions(); //Retains questions from quiz
void getstatus(); //Ensures quiz questions never gets repeated (slightly pending)
void quiztimer();
void updatestatus(char *usr, int qid, char stat);
void recordscores(char *sfile, char *tfile, int score, int time); //Writes quiz scores in that user's file
void usergraph(char *sfile, char *tfile);
//E-learning functions
void learnhome(int section);
void elearn(int section);
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
void ag_progression(float w, float x, float y, float z, float* t1, float* t2, int *code);
void prime(float w, float x, float y, float z, float* t1, float* t2, int *code);
void da_progression(float w, float x, float y, float z, float* t1, float* t2, int *code);
void exp_series(float w, float x, float y, float z, float* t1, float* t2, int *code);
void fibonacci(float w, float x, float y, float z, float* t1, float* t2, int *code);
void sumrelation(float w, float x, float y, float z, float* t1, float* t2, int *code);
void sumproduct(float w, float x, float y, float z, float* t1, float* t2, int *code);
void square_series(float w, float x, float y, float z, float* t1, float* t2, int *code);
void cube_series(float w, float x, float y, float z, float* t1, float* t2, int *code);
void factorial_series(float w, float x, float y, float z, float* t1, float* t2, int *code);
void squaresum_series(float w, float x, float y, float z, float* t1, float* t2, int *code);
void productpretwo_series(float w, float x, float y, float z, float* t1, float* t2, int *code);
void userquestions(float w,float x, float y, float z, float a, float b, int check);
float factorial(float x);
//Function to set the background and foreground colors randomly
void setcolor();
int qidtotopic(int qid);
struct question //Quiz functions will store data in these structure arrays
{
  float n[6];
  char code[5];
  char diff;
  char status;
}q[90], q0[25], q1[35], q2[30];

int check=0;
int choiceq;
char username[30];

int main()
{
  startupcolors();
  entry();
  start();
  return 0;
}

void start()
{
    int usercount = 0;
    FILE *fpc;
    fpc = fopen("login.txt","r");
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
    char choicel;
    setcolor();
    starttop:
    system("cls");
    gotoxy(50,12);
    printf("1. Login");
    gotoxy(50,13);
    printf("2. Sign Up");
    gotoxy(45, 16);
    printf("Enter your choice : ");
    choicel=getche();
    if (choicel=='1')
    {
        login(usercount);
    }
    else if(choicel=='2')
    {
        signup(usercount);
    }
    else
    {
      gotoxy(45, 17);
      printf("Invalid input. Please try again!");
      Sleep(2000);
      goto starttop;
    }
}

void login(int count)
{
    int checku = 0, checkp = 0, fail=0;
    char password[30];
    setcolor();
    logintop:
    system("cls");
    gotoxy(45,12);
    printf("Enter your username : ");
    scanf("%s",username);
    gotoxy(45,13);
    printf("Enter your password : ");
    char ch;
    int i=0;
//    ch = getch();
//    password[0] = ch;
    while((ch=getch())!=13 && i<30)
    {
//        ch = getch();
        if (ch == 8 && i>0)
        {
            i--;
            printf("\b \b");
            continue;
        }
        // else if(ch == 8)
        // {
        //   //Do nothing
        // }
        else if (ch != 8)
        {
            password[i] = ch;
            putchar('*');
            ++i;
        }   
    }
    password[i]='\0';
    char string[50], *token, ch2 = 'u';
    FILE *fp;
    fp = fopen("login.txt","r");
    fscanf(fp,"%s",string);
    int j = 1;
    while (j<=count)
    {
        token = strtok(string,",");
                if (strcmp(username,token) == 0)
                {
                    token = strtok(NULL,",");
                    if (strcmp(password,token) == 0)
                    {
                        {
                          gotoxy(50,15);
                          printf("Welcome %s",username);
                          Sleep(2000);
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
  //                  goto logintop;
                    fscanf(fp,"%s",string);
                    ++j;
                }            
        }
       if(fail>0)
       {
        gotoxy(42, 15);
        printf("Your username or password is wrong.");
        Sleep(2000);
        goto logintop;
       } 
}

void signup(int count)
{
    int i=0;
    char password[30], ch;
    setcolor();
    system("cls");
    gotoxy(30,10);
    printf("Enter your username: ");
    scanf("%s",username);
    gotoxy(30,11);
    printf("Enter your password: ");
    // ch = getch();
    // password[0] = ch;
    while((ch=getch())!=13 && i<20)
    {
        // ch = getch();
        if (ch == 8 && i>0)
        {
          i--;
          printf("\b \b");
          continue;
        }
        else if (ch != 8)
        {
            password[i] = ch;
            putchar('*');
            ++i;
        }   
    }
    if(i==0)
    {
      gotoxy(30,13);
      printf("Please enter a valid password.");
      Sleep(2000);
      signup(count);
    }
    password[i]='\0';
    FILE *fp2, *fpa, *fptr;
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
      gotoxy(40,14);
        printf("Username already exists. Please use another one.");
        Sleep(2000);
        signup(count);
    }
    else
    {
      fpa = fopen("login.txt", "a");
      fprintf(fpa, "\n%s,%s,u",username,password);
        fclose(fpa);
        gotoxy(38,14);
        printf("Thanks for using Sneaky Series. Hope you have a good time!");
        fp2=fopen("performance.csv", "a");
        fprintf(fp2,"%s,",username);
        for(int i=0; i<89; i++)
        {
          fprintf(fp2,"n,");
        }  
        fprintf(fp2,"n\n");
        fclose(fp2);
        fptr=fopen("Track_Topic.txt", "a");
        fprintf(fptr, "\n%s,1",username);
        fclose(fptr);
        Sleep(2000);
        menu();
    }
    ++count;
}

void menu()
{
  int choice;
  setcolor();
  menubegin:
  system("cls");
  gotoxy(15,9);
  printf("1. E-learning - Get guidance on cracking any series problem");
  gotoxy(15,10);
  printf("2. Quiz - Think you know it all?");
  gotoxy(15,11);
  printf("3. Series Cracker - If you need help with a problem, we might be able to help you out");
  gotoxy(15,12);
  printf("4. Generate performance report");
  gotoxy(25,13);
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
      gotoxy(35,18);
        printf("Invalid input. Please try again!");
      goto menubegin;
  }
}
void adminmenu()
{
  int topic1, topic2;
  char choice, usern[30];
  setcolor();
  adminmenubegin:
  system("cls");
  gotoxy(40,12);
  printf("1. Generate performance of users of a particular topic");
  gotoxy(40,13);
  printf("2. Generate performance report for a particular user");
  gotoxy(40,14);
  printf("3. Compare topics on the basis of performance of users");
  gotoxy(40,15);
  printf("4. Read messages sent by users");
  gotoxy(44,16);
  printf("Select your choice: ");
  choice=getche();
  switch(choice)
  {
    case '1':
      printf("1. Progressions\n2. Advanced Progressions\n3. Standard series (prime numbers, fibonacci series, factorials)\n4. Squares and Cubes\n5. Relation with previous terms\n6.Multiple series and combinations of different series\n");
      printf("\nEnter your choice : ");
      scanf("%d",&topic1);
      system("cls");
      admintopic("ALL",topic1);
      break;
    case '2':
      system("cls");
      printf("Enter the username : ");
      scanf("%s",usern);
      adminUserReport(usern);
      break;
    case '3':
      printf("1. Progressions\n2. Advanced Progressions\n3. Standard series (prime numbers, fibonacci series, factorials)\n4. Squares and Cubes\n5. Relation with previous terms\n6.Multiple series and combinations of different series\n");
      printf("\nEnter two topic IDs to compare : ");
      scanf("%d %d",&topic1,&topic2);
      admintopic("ALL",topic1);
      admintopic("ALL",topic2);
      break;
    case '4':
      displaymessage();
      break; 
    default:
      printf("Invalid input. Please try again.");
      Sleep(1000);
      goto adminmenubegin;
  }
}
void learn()
{
  int selection, truser=0, trcount = 0;
  char choice, *token, string[30], ch1;
  FILE *fpt;
  fpt = fopen("Track_Topic.txt","r");
  ch1 = fgetc(fpt);
  while (ch1 != EOF)
  {
      ch1 = fgetc(fpt);
      if (ch1 == '\n')
      {
          ++trcount;
      }
  }
  rewind(fpt);
  trcount+=1;
  setcolor();
  learnbegin:
  system("cls");
  gotoxy(30,9);  
  printf("1. Continue from where you left.");
  gotoxy(30,10);
  printf("2. Jump to a topic.");
  gotoxy(30,11);
  printf("3. Start over");
  gotoxy(30,12);    
  printf("Select your choice: ");
  choice=getche();
  switch(choice)
  {
    case '1':
      fscanf(fpt,"%s",string);
      token = strtok(string,",");
      int f = 0;
      while(f < trcount)
      {
        if (strcmp(token,username) == 0)
        {
          ++truser;
        }
        fscanf(fpt,"%s",string);
        token = strtok(string,",");
        ++f;
      }
      rewind(fpt);
      fscanf(fpt,"%s",string);
      token = strtok(string,",");
      int k=0;
      while(k < trcount)
      {
        if (strcmp(token,username) == 0)
        {
          truser--;
          if (truser == 0)
          {
            token = strtok(NULL,",");
            break;
          }
        }
        fscanf(fpt,"%s",string);
        token = strtok(string,",");
        ++k;
      }
      if (token != NULL)
      {
        selection = atoi(token);
      }
      else
      {
        selection = 1;
      }
      fclose(fpt);
      learnhome(selection);
      break;
    case '2':
      setcolor();
      system("cls");
      gotoxy(35,13);
      printf("1. Progressions");
      gotoxy(35,14);
      printf("2. Advanced Progressions");
      gotoxy(35,15);
      printf("3. Standard Series");
      gotoxy(35,16);
      printf("4. Squares and Cubes");
      gotoxy(35,17);
      printf("5. Series having relation with previous terms");
      gotoxy(35,18);
      printf("6. Multiple series and combination of different series");
      gotoxy(40,19);
      printf("Select your choice: ");
      scanf("%d", &selection);
      learnhome(selection);  
      break;
    case '3':
      selection=1;
      learnhome(selection);    
      break;
    default:
      goto learnbegin;
  }
}
void quiz()
{
  static int x=0;
  float a[2];
  int score=0;
  getstatus();
  getquestions();   
  quiztop:
  setcolor();
  system("cls");
  gotoxy(30,9);
  printf("How strong you think you are?");
  gotoxy(30,11);
  printf("1. Take it easy, I'm new");
  gotoxy(30,12);
  printf("2. I know a few things pretty well.");
  gotoxy(30,13);
  printf("3. Bring it on. I'm a series god!");
  gotoxy(30,16);
  printf("Enter your choice: ");
  scanf("%d", &choiceq);
  //Generate random number
  time_t t;
  srand((unsigned) time(&t));
  int r[5];
  clock_t t1; 
  t1 = clock();   
  if(choiceq==1)
  {
    system("cls");
    for(int i=0; i<5; i++)
    {
      gotoxy(45,5);
      printf("Question %d of 5\n",i+1);
      gotoxy(40,7);
      printf("Enter the next two terms : ");
      r[i]=rand()%25;
      if(q0[r[i]].status == '0' || q0[r[i]].status == '1')
      {
        i--;
        continue;
      }
      //updatestatus(username,r[i],);
      gotoxy(10,11);
      printf("%.2f",q0[r[i]].n[0]);
      gotoxy(25,11);
      printf("%.2f",q0[r[i]].n[1]);
      gotoxy(40,11);
      printf("%.2f",q0[r[i]].n[2]);
      gotoxy(55,11);
      printf("%.2f",q0[r[i]].n[3]);
      for(int i=0; i<2; i++)
      {
        gotoxy(55+15*(i+1),12);
        printf("___");
        // quiztimer();
        gotoxy(55+15*(i+1),11);
        scanf("%f", &a[i]);
      }
      // Sleep(2000);
      if(a[0]==q0[r[i]].n[4] && a[1]==q0[r[i]].n[5])
      {
        score++;
        q0[r[i]].status = '1';
      }
      else
      {
        q0[r[i]].status = '0';
      }
      updatestatus(username,r[i],q0[r[i]].status);
      system("cls");
    }
  }
  else if(choiceq==2)
  {
    system("cls");
    for(int i=0; i<5; i++)
    {
      gotoxy(45,5);
      printf("Question %d of 5\n",i+1);
      gotoxy(40,7);
      printf("Enter the next two terms : ");
      r[i]=rand()%35;
      if(q1[r[i]].status == '0' && q1[r[i]].status == '1')
      {
        i--;
        system("cls");
        continue;
      }
//      updatestatus(username,r[i]);
      gotoxy(10,11);
      printf("%.2f",q1[r[i]].n[0]);
      gotoxy(25,11);
      printf("%.2f",q1[r[i]].n[1]);
      gotoxy(40,11);
      printf("%.2f",q1[r[i]].n[2]);
      gotoxy(55,11);
      printf("%.2f",q1[r[i]].n[3]);
      for(int i=0; i<2; i++)
      {
        gotoxy(55+15*(i+1),12);
        printf("___");
        // quiztimer();
        gotoxy(55+15*(i+1),11);
        scanf("%f", &a[i]);
      }
      // Sleep(2000);
      if(a[0]==q1[r[i]].n[4] && a[1]==q1[r[i]].n[5])
      {
        score++;
        q1[r[i]].status = '1';
      }
      else
      {
        q1[r[i]].status = '0';
      }
      updatestatus(username,r[i],q1[r[i]].status);      
      system("cls");
    }
  }

  else if(choiceq==3)
  {
    system("cls");
    for(int i=0; i<5; i++)
    {
      gotoxy(45,5);
      printf("Question %d of 5\n",i+1);
      gotoxy(40,7);
      printf("Enter the next two terms : ");
      r[i]=rand()%30;
      if(q2[r[i]].status == '0' && q2[r[i]].status == '1')
      {
        i--;
        system("cls");
        continue;
      }
  //    updatestatus(username,r[i]);
      gotoxy(10,11);
      printf("%.2f",q2[r[i]].n[0]);
      gotoxy(25,11);
      printf("%.2f",q2[r[i]].n[1]);
      gotoxy(40,11);
      printf("%.2f",q2[r[i]].n[2]);
      gotoxy(55,11);
      printf("%.2f",q2[r[i]].n[3]);
      for(int i=0; i<2; i++)
      {
        gotoxy(55+15*(i+1),12);
        printf("___");
        // quiztimer();
        gotoxy(55+15*(i+1),11);
        scanf("%f", &a[i]);
      }
      if(a[0]==q2[r[i]].n[4] && a[1]==q2[r[i]].n[5])
      {
        score++;
        q2[r[i]].status = '1';
      }
      else
      {
        q2[r[i]].status = '0';
      }
      updatestatus(username,r[i],q2[r[i]].status);      
      system("cls");
    }
  }
  else
  {
    printf("Invalid input, please try again!");
    goto quiztop;
  }
  t1 = clock() - t1;
  double time_taken = ((double)t1)/CLOCKS_PER_SEC;  
  printf("Your score is %d\n",score);
  FILE *userp;
  char fsname[45], ftname[45], gsname[45], gtname[45];
  if (x == 0)
  {
    strcpy(fsname,username);
    strcat(fsname,"_score.dat");
    strcpy(ftname,username);
    strcat(ftname,"_time.dat");
    strcpy(gsname,username);
    strcat(gsname,"_score.png");
    strcpy(gtname,username);
    strcat(gtname,"_time.png");
  }
  recordscores(fsname,ftname,score,time_taken);
  usergraph(fsname,ftname);
  printf("Time taken to complete the quiz is %lf seconds\n\n", time_taken);
  printf("Average time of all quizzes so far is: %f\n",averagetime(time_taken));
  system(gsname);
  system(gtname);
  Sleep(2000);
  int choicex;
  printf("1. Take another quiz\n2. Go back to main menu\n\n");
  printf("Enter your choice : ");
  scanf("%d",&choicex);
  if (choicex == 1)
  {
    score=0;
    ++x;
    goto quiztop;
  }
  else
  {
    menu();
  }
}
void getquestions()
{
  FILE *fp;
  int i=0, j=0, k=0, l=0;
  char str[300], *token;
  fp=fopen("quizdatabase.csv", "r");
  for (int n = 0; n < 90; ++n)
  {
    fscanf(fp,"%s",str);
    token = strtok(str,",");
    if (n == 0)
    {
      strcpy(q[n].code,"A001");;
    }
    else
    {
      strcpy(q[n].code,token);
    }
    token = strtok(NULL,",");
    q[n].diff = *token;
    for (int m = 0; m < 6; ++m)
    {
      token = strtok(NULL,",");
      q[n].n[m] = atoi(token);
    }
    switch(q[n].diff)
    {
      case '0':
        q0[j]=q[n];
        j++;
        break;
      case '1':
        q1[k]=q[n];
        k++;
        break;
      case '2':
        q2[l]=q[n];
        l++;
        break;
    }
  }
  fclose(fp);
}
void getstatus()
{
  char *token;
  int count=0;
    char str[300];
  FILE *fp;
  fp=fopen("performance.csv", "r");
  fscanf(fp, "%s", str);
  token=strtok(str,",");
  while (strcmp(token,username) != 0)
  {
    fscanf(fp, "%s", str);
    token=strtok(str,",");
  }
  int i = 0;
  while(i < 90)
  {
    token=strtok(NULL, ",");
    q[i].status=*token;
    if(q[i].status=='n')
      count++;
    ++i;
  }
  if(count<5)
  {
    for(int i=0; i<90; i++)
    {
      q[i].status='n';
    }
  }
  fclose(fp);
}
void seriescracker()
{
  int code;
  char choice;
  float t[6];
  enterseries:
  setcolor();
  system("cls");
  check=0;
  gotoxy(25,7);
  printf("Enter the four terms here: ");
  gotoxy(25,11);
  printf("___");
  gotoxy(45,11);
  printf("___");
  gotoxy(65,11);
  printf("___");
  gotoxy(85,11);
  printf("___");
  for(int i=0; i<4; i++)
  {
    gotoxy(25+20*i,10);
    scanf("%f", &t[i]);
  }
  a_progression(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    g_progression(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    h_progression(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    ag_progression(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    prime(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    exp_series(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    fibonacci(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    sumproduct(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
  if(check==0)
    factorial_series(t[0],t[1],t[2],t[3],&t[4],&t[5],&code);
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
  {
    gotoxy(35, 15);
    printf("Next terms: ");
    gotoxy(40,17);
    printf("%.2f",t[4]);
    gotoxy(80,17);
    printf("%.2f",t[5]);
    gotoxy(40,18);
    printf("_____");
    gotoxy(80,18);
    printf("_____");
  }
  userquestions(t[0],t[1],t[2],t[3],t[4],t[5],check);
  seriescrackerchoice:
  gotoxy(40,19); 
  printf("1. Enter another series");
  gotoxy(40,20);
  printf("2. Learn this topic");
  gotoxy(40,21);
  printf("3. Back to main menu");
  gotoxy(40,22);
  printf("Enter your choice: ");
  choice=getche();
  switch(choice)
  {
  case '1':
    goto enterseries;
    break;
  case '2':
    learnhome(code);
    break;
  case '3':
    menu();
  default:
    gotoxy(40,23);
    printf("Invalid input. Please try again");
    goto seriescrackerchoice;
  }
}
void userperformance()
{
  int choice, topic2, topic1;
  setcolor();
  system("cls");
  gotoxy(37,12);
  printf("1. Generate report of a particular topic");
  gotoxy(37,13);
  printf("2. Compare topics based on time taken to solve questions and accuracy");
  gotoxy(40,15);
  printf("Enter your choice: ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
      printf("1. Progressions\n2. Advanced Progressions\n3. Standard series (prime numbers, fibonacci series, factorials)\n4. Squares and Cubes\n5. Relation with previous terms\n6.Multiple series and combinations of different series\n");
      printf("\nEnter your choice : ");
      scanf("%d",&topic1);
      admintopic(username,topic1); 
      break;
    case 2:
      printf("1. Progressions\n2. Advanced Progressions\n3. Standard series (prime numbers, fibonacci series, factorials)\n4. Squares and Cubes\n5. Relation with previous terms\n6.Multiple series and combinations of different series\n");
      printf("\nEnter two topic IDs to compare : ");
      scanf("%d %d",&topic1,&topic2);
      admintopic(username,topic1);
      admintopic(username,topic2);
      break; 
  }
}
void a_progression(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  if((z-y) == (y-x) && (y-x) == (x-w))
  {
    check=1;
    gotoxy(0,13);
    printf("The series is an arithmetic progression with common difference %f\n", x-w);
    float u[2];
    u[0]=z+(z-y);
    u[1]=u[0]+(z-y);
    *t1 = u[0];
    *t2 = u[1];
    *code=1;
  }
}
void g_progression(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  if((x/w)==(y/x) && (y/x)==(z/y))
  {
    check=1;
    gotoxy(0,13);
    printf("The series is an geometric progression with common ratio %f\n", x/w);
    float u[2];
    u[0]=z*(x/w);
    u[1]=u[0]*x/w;
    *t1 = u[0];
    *t2 = u[1];
    *code=1;
  }
}
void ag_progression(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  float d=sqrt(pow(x,2)-w*y);
  float r=y/(x+d);
  if(z==((x+2*d)*pow(r,2)))
  {
    check=1;
    gotoxy(0,13);
    printf("The series is an arithmetico-geometric progression with common difference %f and common ratio %f", d, r);
    float u[2];
    u[0]=(x+3*d)*pow(r,3);
    u[1]=(x+4*d)*pow(r,4);
    *t1 = u[0];
    *t2 = u[1];
    *code=2;
  }
}
void h_progression(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  if(1/x-1/w==1/y-1/x && 1/z-1/y==1/y-1/x)
  {
    check=1;
    gotoxy(0,13);
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
    gotoxy(0,13);
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
    gotoxy(0,13);
    printf("The given series has difference between consecutive terms in an arithmetic progression\n");
    float u[2];
    u[0]=z+(z-y)+(z-y)-(y-x);
    u[1]=u[0]+(u[0]-z)+(z-y)-(y-x);
    *t1 = u[0];
    *t2 = u[1];
    *code = 2;
  }
}
void exp_series(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  if(w!=1 || y<0)
    return;
  float Y=sqrt(y*factorial(2));
  float Z=cbrt(z*factorial(3));
  if(Z==x && ((Y==x) || Y==(-1*x)))
  {
    check=1;
    gotoxy(0,13);
    printf("The given series is an exponential series for x = %f", x);
    float u[2];
    u[0]=pow(x,4)/factorial(4);
    u[1]=pow(x,5)/factorial(5);
    *t1 = u[0];
    *t2 = u[1];
    *code=6;
  }
}

void fibonacci(float w, float x, float y, float z, float* t1, float* t2, int *code)
{
  if(y==w+x && z==y+x)
  {
    check=1;
    gotoxy(0,13);
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
    gotoxy(0,13);
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
    gotoxy(0,13);
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
    gotoxy(0,13);
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
    gotoxy(0,13);
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
  for (int i = 0; i < 115; ++i)
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
    gotoxy(0,13);
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
    w1 = w - i;
    x1 = x - i;
    y1 = y - i;
    z1 = z - i;
    w1 = sqrt(w1);
    x1 = sqrt(x1);
    y1 = sqrt(y1);
    z1 = sqrt(z1);
    if ((z1-y1) == (y1-x1) && (y1-x1) == (x1-w1))
    {
      gotoxy(0,13);
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
      gotoxy(0,13);
      printf("The given series is of the general form k*x(n-1)*x(n-2) where k is %d\n", i);
      u[0] = i*z*y;
      u[1] = i*z*u[0];
      *t1 = u[0];
      *t2 = u[1];
      *code=5;
    }
  }
}
void userquestions(float w,float x, float y, float z, float a, float b, int check)
{
  FILE *uq;
  uq=fopen("userquestions.csv","a");
  if(check==0)
  {
    fprintf(uq,"%f,%f,%f,%f\n",w,x,y,z);
  }
  else
  {
    fprintf(uq,"%f,%f,%f,%f,%f,%f",w,x,y,z,a,b);
  }
  fclose(uq);
}
void learnhome(int section)
{
  char anykey, prog;
  FILE *trreset;
  elearn(section);
  if(section!=6)
  {
    Lnavigation(section);    
  }  
  else
  {
    printf("Press any key to go back to main menu. ");
    trreset=fopen("Track_Topic.txt", "a");
    fprintf(trreset, "\n%s,1",username);
    fclose(trreset);
    anykey=getche();
//    section=1;
    menu();    
  }
  // switch(section)
  // {
  //   case 1:
  //     Lprogressions();
  //     Lnavigation(section);
  //     break;
  //   case 2:
  //     Ladvancedprogressions();
  //     Lnavigation(section);
  //     break;
  //   case 3:
  //     Lstandardseries();
  //     Lnavigation(section);
  //     break;
  //   case 4:
  //     Lsquaresandcubes();
  //     Lnavigation(section);
  //     break;
  //   case 5:
  //     Lpreviousterms();
  //     Lnavigation(section);
  //     break;
  //   case 6:
  //     Lmultipleseries();
  //     printf("Press any key to go back to main menu. ");
  //     trreset=fopen("Track_Topic.txt", "a");
  //     fprintf(trreset, "\n%s,1",username);
  //     fclose(trreset);
  //     anykey=getche();
  //     menu();
  //     break;
  // }
}
void Lprogressions()
{
  setcolor();
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
  setcolor();
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
  setcolor();
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
  setcolor();
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
  setcolor();
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
  setcolor();
  system("cls");
  printf("Multiple series and combinations of different series\n");
  FILE *fp;
  char c;
  fp=fopen("multipleseries.txt", "r");
  while((c=getc(fp))!=EOF)
    putchar(c);
  fclose(fp);  
}
void elearn(int section)
{
  setcolor();
  system("cls");
  char *flname;
  flname=(char*)calloc(27,sizeof(char));
  switch(section)
  {
    case 1:
      printf("Progressions\n");
      flname="progressions.txt";
      break;
    case 2:
      printf("Advanced Progressions\n");
      flname="advancedprogressions.txt";
      break;
    case 3:
      printf("Standard Series\n");
      flname="standardseries.txt";
      break;
    case 4:
      printf("Squares and Cubes\n");
      flname="squaresandcubes.txt";
      break;
    case 5:
      printf("Series based on previous terms\n");
      flname="previousterms.txt";
      break;  
    case 6:
      printf("Multiple series and combinations of different series\n");
      flname="multipleseries.txt";
  }
  FILE *fp;
  char c;
  fp=fopen(flname, "r");
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
  if(choice=='0')
  {
    FILE *fptrack;
    char string[30], *token;
    fptrack = fopen("Track_Topic.txt","a");
    fprintf(fptrack, "\n%s,%d",username,section);
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
      s[(strlen(s)-1)] = '\0';
      fprintf(fp, "%s\n%s\n%d,%d,%d,%d\n\n",username, s, w, x, y, z);  
      fclose(fp);
      printf("Thank you. Your message has been sent along with the problem you entered!\n");
      Sleep(2000); 
      break;
    case 'N':
    case 'n':
      break;
    default:
      printf("Invalid input. Please try again!\n");
      goto sendmessagebegin;
  }
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
        system("color 07");
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
void setcolor()
{
  time_t t;
  int color;
  srand((unsigned) time(&t));
  color=rand()%10;
  switch(color)
  {
    case 0:
      system("color 07");
      break;
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
  }
}
void updatestatus(char *usr, int qid, char stat)
{
  FILE *upd;
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
        fseek(upd,-2*(89-qid)-1,1);
              fputc(stat,upd);
      fseek(upd,0,1);
      break;
      // printf("%c",getc(upd));
      // fseek(upd,-1,1);
      // Sleep(2000);
      // fseek(upd,-1,1);
    }
  }
  fclose(upd);
}
void recordscores(char *sfile, char *tfile, int score, int time)
{
  FILE *rscore, *rtime;
  int Tindex=0, lines=0;
//  int Ttime,Tscore;
  char *DIFF =(char*)calloc(11,sizeof(char));  //This is because string initialization can only be done during declaration
  rscore=fopen(sfile,"r");
//  rtime=fopen(tfile,"r");
  char *token, *stemp;
  int i=0;
  char ch;
  // while(!feof(rscore))
  // {
  //   fscanf(rscore,"%d,%s,%d,%d",Tindex,DIFF,Ttime,Tscore);
  // }
  while((ch=fgetc(rscore)) != EOF)
  {
    if (ch == '\n')
    {
      ++lines;
    }
  }
  rewind(rscore);
  // if (lines != 0)
  // {
  //   for (i=0; i < (3*(lines-1)+1); ++i)
  //   {
  //     fscanf(rscore,"%s",stemp);
  //   }
    Tindex = lines-1;
  // }
  int index=Tindex;
  fclose(rscore);
  rscore=fopen(sfile,"a");
  rtime=fopen(tfile,"a");
  switch(choiceq)
  {
    case 1:
      DIFF="Easy";
      break;
    case 2:
      DIFF="Medium";
      break;
    case 3:
      DIFF="Difficult";
  }
  fprintf(rscore,"%d %s %d\n", (index+1),DIFF,score);
  fprintf(rtime,"%d %s %d\n", (index+1),DIFF,time);
  fclose(rscore);
  fclose(rtime);
  free(DIFF);
  Sleep(1000);
}
void usergraph(char *sfile, char *tfile)
{
  FILE *scr;
  scr=fopen("script.gp", "w");
  fprintf(scr,"set yrange [0:*]\nset term png\nset output \"%s_score.png\"\nset boxwidth 0.5\nset style fill solid\nplot \"%s\" using 1:3:xtic(2) with boxes",username,sfile);
  fclose(scr);
  system("gnuplot -p script.gp");
  scr=fopen("script2.gp","w");
  fprintf(scr,"set yrange [0:*]\nset term png\nset output \"%s_time.png\"\nset boxwidth 0.5\nset style fill solid\nplot \"%s\" using 1:3:xtic(2) with boxes",username,tfile);
  fclose(scr);
  system("gnuplot -p script2.gp");
//  graph=fopen("graph.dat", "w");

  // int nentries=0;
  // char c;
  // while((c=getc(ugraph))!=EOF)
  // {
  //   if(c='\n')
  //     nentries++;
  // }
  // rewind(ugraph);
  // char fdiff[11];
  // int fscore;
  // if (nentries<5)
  // {
  //   for(int i=1; i<nentries; i++)
  //   {
  //     fscanf(ugraph,"%s %d", fdiff, fscore);
  //     fprintf(graph,"%d %s %d\n", i, fdiff, fscore);
  //   }
  // }
  // else
  // {

  // }
}

void displaymessage()
{
  FILE *fp;
  fp = fopen("messages.txt","r");
  char ch, s[1000], anykey, *token;
  int i=0, lines=0;
  while((ch=fgetc(fp)) != EOF)
  {
    if (ch == '\n')
    {
      ++lines;
    }
  }      
  rewind(fp);
  system("cls");
  printf("Username\tMessage\t\t\t\t\t\tSeries\n\n");
  for (int i = 0; i < lines; ++i)
  { 
    fgets(s,1000,fp);
    token = strtok(s,"|");
    printf("%s\t\t",token);
    token = strtok(NULL,"|");
    printf("%s\t\t",token);
    for (int j = 0; j < 4; ++j)
    {
      token = strtok(NULL,"|");
      if (j == 3)
      {
        printf("%s",token);
      }
      else
      {
        printf("%s, ",token);
      }
    }
    printf("\n\n");
  }
  Sleep(2000);
  anykey = getche();
  if (anykey)
  {
    adminmenu();
  }
}

int qidtotopic(int qid)
{
  int t=qid/15;
  if(t==0)
    return 1;
  else if(t==1)
    return 2;
  else if(t==2)
    return 3;
  else if(t==3)
    return 4;
  else if(t==4)
    return 5;
  else
    return 6;
}
float averagetime(float time)
{
  FILE *at;
  char str[50];
  at=fopen("timetrack.txt","a");
  fprintf(at,"%s,%f\n",username,time);
  fclose(at);
  at=fopen("timetrack.txt","r");
  char ch, *token;
  int count=0, i=0;
  while((ch=getc(at))!=EOF)
    if(ch=='\n')
      count++;
  rewind(at);
  float t[count], tsum=0;
  while(i<count)
  {
    fscanf(at,"%s",str);
    token=strtok(str,",");
    token=strtok(NULL,",");
    t[i]=strtof(token,NULL);
    tsum+=t[i];
    i++;
  }
  float tav=tsum/i;
  return tav;
}
void admintopic(char *user, int topic)
{
  FILE *fp, *readuser;
  float acc[1000];
  char users[20][30];
  readuser = fopen("login.txt","r");
  fp = fopen("performance.csv","r");
  float correct=0, wrong=0;
  char s[300], *token, score[90], s1[300], *token1;
  while ((fscanf(readuser,"%s",s1)) != EOF)
  {
    correct=0, wrong=0;
    token1 = strtok(s1,",");
    rewind(fp);
    while ((fscanf(fp,"%s",s)) != EOF)
    {
      token = strtok(s,",");
      if (strcmp(token,token1) == 0)
      {
        for (int i = 0; i < 90; ++i)
        {
          token = strtok(NULL,",");
          if (qidtotopic(i) == topic)
          {
            if (*token != 'n')
            {
              if (*token == '0')
              {
                ++wrong;
              }
              else
              {
                ++correct;
              }
            }
          }
        }
      }
    }
    if (strcmp(user,"ALL") == 0)
    {
      static int i=0;
      printf("Username - %s\n",token1);
      printf("Topic ID - %d\n",topic);
      printf("Correct = %f Wrong = %f\n",correct,wrong);
      if(correct==0 && wrong ==0)
        continue;
      float accuracy = (correct/(correct+wrong))*100;
      acc[i]=accuracy;
      strcpy(users[i],token1);
      i++;
      printf("%f\n", accuracy);
      // admintopicgraph(users,acc); //Sends the list of accuracy of every user
      continue;
    }
    if (strcmp(token1,user) != 0)
    {
      continue;
    }
    printf("Topic ID - %d\n",topic);
    printf("Correct = %f Wrong = %f\n",correct,wrong);
    float accuracy = (correct/(correct+wrong))*100;
    printf("%f\n", accuracy);
    usertopicgraph(user,correct,wrong);
  }
  Sleep(1000);
  admintopicgraph(users,acc);
  fclose(fp);
  fclose(readuser);
}

void adminUserReport(char *user)
{
  FILE *fp, *readuser;
  readuser = fopen("login.txt","r");
  fp = fopen("performance.csv","r");
  float correct=0, wrong=0;
  char s[300], *token, score[90], s1[300], *token1;
  while ((fscanf(readuser,"%s",s1)) != EOF)
  {
    correct=0, wrong=0;
    token1 = strtok(s1,",");
    rewind(fp);
    while ((fscanf(fp,"%s",s)) != EOF)
    {
      token = strtok(s,",");
      if (strcmp(token,token1) == 0)
      {
        for (int i = 0; i < 90; ++i)
        {
          token = strtok(NULL,",");
          if (*token != 'n')
          {
            if (*token == '0')
            {
              ++wrong;
            }
            else
            {
              ++correct;
            }
          }
        }
        break;
      }
    }
    if (strcmp(token1,user) != 0)
    {
      continue;
    }
    printf("Correct = %f Wrong = %f\n",correct,wrong);
    float accuracy = (correct/(correct+wrong))*100;
    printf("%f\n", accuracy);
    usertopicgraph(user,correct,wrong);
  }
  Sleep(1000);
  fclose(fp);
  fclose(readuser);
}
void admintopicgraph(char user[][30], float *accuracy)
{
  FILE *tgraph;
  tgraph=fopen("topicgraph.dat", "w");
  int i=0;
  while(user[i][0]!='\0')
  {
    fprintf(tgraph,"%d %s %f\n",i,user[i],accuracy[i]);
    ++i;
  }
  fclose(tgraph);
  tgraph=fopen("script.gp","w");
  fprintf(tgraph,"set yrange [0:100]\nset term png\nset output \"admintopic.png\"\nset boxwidth 0.5\nset style fill solid\nplot \"topicgraph.dat\" using 1:3:xtic(2) with boxes");
  fclose(tgraph);
  system("gnuplot -p script.gp");
  system("admintopic.png");
}
void usertopicgraph(char *user,int correct,int wrong)
{
  FILE *ugraph;
  ugraph=fopen("topicgraph.dat","w");
  fprintf(ugraph,"0 Correct %d\n1 Incorrect %d",correct,wrong);
  fclose(ugraph);
  ugraph=fopen("script.gp","w");
  fprintf(ugraph,"set yrange [0:*]\nset term png\nset output \"%stopic.png\"\nset xlabel \"%s\"\nset boxwidth 0.5\nset style fill solid\nplot \"topicgraph.dat\" using 1:3:xtic(2) with boxes",user,user);
  fclose(ugraph);
  system("gnuplot -p script.gp");
  char gname[40];
  strcpy(gname,user);
  strcat(gname,"topic.png");
  system(gname);
}

void quiztimer()
{
	int countdown = 5; // No. of seconds after which we show the warning 
	int time_diff = 0, seconds = 0;
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
	gotoxy(45,15);
	printf("Time's UP!!\n");
}