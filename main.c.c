#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void quiz_insert();
void quiz_answer();
void delay(float s);
void pattern();

int choice,n=5,i,j,p,length;
int max,marks=1,count,value,*pointer;
long int id;
time_t t;

char ch,mailid[50],demooption[5],democrctoption[5], buffer[30];
char q[100],k[1],l[1],num[5],option1[50],option2[50],option3[50],option4[50];
char name[100],password[100],userpassword[100];

FILE *fp[5];
FILE *limit;
FILE *answer;
FILE *studentstatus;
FILE *Number;
FILE *admin;

int main()
{
    
    fp[0] = fopen("Demo0.txt", "r");
    democrctoption[0] ='b';
    democrctoption[1] ='d';
    democrctoption[2] ='a';
    democrctoption[3] ='c';
    democrctoption[4] ='c';

    if (fp[0]==NULL)
    {
        fp[0]=fopen("Demo0.txt", "w+");
        fputs("1.Which of the following is non-linear data structure?\na.Array\t\tb.Graph\nc.Linked List\td.Stack\n",fp[0]);
        fp[1]=fopen("Demo1.txt", "w+");
        fputs("2.What is the Inorder traversal method?\na.root,left,right\tb.right,root,left\nc.right,left,root\td.left,root,right\n",fp[1]);
        fp[2]=fopen("Demo2.txt", "w+");
        fputs("3.Which principle is used in STACK?\na.LIFO\tb.FIFO\nc.FOFI\td.LOFI\n",fp[2]);
        fp[3]=fopen("Demo3.txt", "w+");
        fputs("4.What is the time complexity for all operations in BST\na.O(n)\t\tb.log n\nc.O(log n)\td.O(n^2)\n",fp[3]);
        fp[4]=fopen("Demo4.txt", "w+");
        fputs("5.How can we initialize an array in C language?\na.int arr[2]=(10, 20)\tb.int arr(2)={10, 20}\nc.int arr[2] = {10, 20}\td.int arr(2) = (10, 20)\n",fp[4]);
        fclose(fp[0]);
        fclose(fp[1]);
        fclose(fp[2]);
        fclose(fp[3]);
        fclose(fp[4]);
    }

    system("cls");
    pattern();
    system("cls");
    printf("\tOnline Quiz Conduct System\n");
    
    do
    {    
        printf("\n1.Login as Admin\n");
        printf("2.Login as Student\n");
        printf("3.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: admin=fopen("adminpassword.txt", "r");
                    if(admin==NULL)
                    {
                        admin=fopen("adminpassword.txt", "w");
                        printf("\nCreate a new password: ");
                        gets(k);
                        gets(password);
                        fputs(password,admin);
                        printf("\n\tPassword Creating ...");

                        for (i = 0; i <3; i++)
                        {
                            
                            delay(1);
                            printf("..");
                            delay(1);
                            printf("\b!\b");
                            printf("\b!\b");
                            printf("\b!\b");
                        }
                            system("cls");
                            printf("\tPassword Created successfully....!!");
                            fclose(admin);
                    }
                    
                    else
                    {
                        admin=fopen("adminpassword.txt", "r");
                        printf("\nPassword: ");
                        gets(k);
                        gets(userpassword);
                        fscanf(admin, "%[^\n]", password);
                        printf("\n\tVerifying Password ...");
                        
                        for (i = 0; i <3; i++)
                        {
                           
                            delay(1);
                            printf("..");
                            delay(1);
                            printf("\b!\b");
                            printf("\b!\b");
                            printf("\b!\b");
                        }
                                       
                        system("cls");
                       printf("\tOnline Quiz Conduct System\n");
                        value=strcmp(password,userpassword);

                        if(value==0)
                        {
                            do
                            {
                                printf("\n1.Write the Question paper\n");
                                printf("2.Check Statistics\n");
                                printf("3.Exit\n");
                                printf("\nEnter your choice: ");
                                scanf("%d",&choice);

                                switch(choice)
                                {
                                    case 1: quiz_insert();
                                             printf("\tQuestions Creating ...");
                                                for (i = 0; i <3; i++)
                                                {
                                                    delay(1.5);
                                                    printf("..");
                                                    delay(1.5);
                                                    printf("\b!\b");   
                                                    printf("\b!\b");
                                                    printf("\b!\b");
                                                }

                                                system("cls");
                                                printf("\n\tQuestions Created Successfully");
                                                exit(0);
                                            break;

                                    case 2: 
                                            printf("\tStatistics are loading ...");
                                        
                                            for (i = 0; i <3; i++)
                                            {
                                                delay(1.5);
                                                printf("..");
                                                delay(1.5);
                                                printf("\b!\b");   
                                                printf("\b!\b");
                                                printf("\b!\b");
                                            }

                                            system("cls");
                                            studentstatus=fopen("studentstatus.XLS", "r");

                                            if (studentstatus==NULL) 
                                            {
                                                printf("\tNo one Attempted the quiz yet.\n");
                                                exit(0);
                                                break;
                                            }

                                            else
                                            {
                                                /*while((ch=fgetc(studentstatus))!=EOF)
                                                    printf("%c",ch); */      
                                                    printf("Excel File is Created.....");
                                                    printf("\nPlease Check the file studentstaus.xls");                                         
                                                exit(0);
                                                break;
                                            }                                         
                                    case 3: 
                                            printf("\tEXITING  ...");
                                        
                                            for (i = 0; i <3; i++)
                                            {
                                                delay(1.5);
                                                printf("..");
                                                delay(1.5);
                                                printf("\b!\b");   
                                                printf("\b!\b");
                                                printf("\b!\b");                                
                                            }  
                                            system("cls");
                                            printf("\tExited Successfully");
                                            exit(0);

                                    default: printf("\tPlease select 1 to 3 Only....!!!\n");
                                }
                            
                            }while(choice!=3);
                        }

                        else                    
                            printf("\nEntered wrong password.\n"); 
                    }                                                   
                    break;

            case 2: printf("\nEnter your name : ");
                    gets(l);
                    gets(name);
                    printf("Enter your student ID : ");
                    scanf("%ld",&id);
                    printf("Enter your email address : ");
                    scanf("%s",mailid);
                
                    quiz_answer();
                    break;

            case 3: 
                    printf("\tEXITING  ...");
                    
                    for (i = 0; i <3; i++)
                    {
                        delay(1.5);
                        printf("..");
                        delay(1.5);
                        printf("\b!\b");   
                        printf("\b!\b");
                        printf("\b!\b");
                    }

                    system("cls");
                    printf("\n\tExited Successfully");
                    exit(0);

            default: printf("\tPlease from 1 to 3 Only!!!");         
        }

    } while (choice!=3);
}

void quiz_insert()
{
    printf("Enter the number of questions: ");
    scanf("%d",&max);

    limit = fopen("limit.txt","w");
    fprintf(limit,"%d\n",max);

    FILE *question[max];
    char crctans[max];
    FILE *answer[max];
    
    for ( i = 1; i <= max; i++)
    {
        printf("\nEnter the question no.%d :\n",i);
        char filename[20];
        sprintf(filename,"question%d.txt",i);
        question[i] =fopen(filename,"w");
        gets(k);
        gets(q);

        printf("Enter the Option A: ");
        gets(option1);

        printf("Enter the Option B: ");
        gets(option2);

        printf("Enter the Option C: ");
        gets(option3);

        printf("Enter the Option D: ");
        gets(option4);

        printf("Select the correct option (a/b/c/d): ");
        scanf("\n%c",&crctans[i-1]);

        answer[i-1] = fopen("correct.txt","a");
        fprintf(answer[i-1],"%c",crctans[i-1]);
        sprintf(num,"%d.",i);
        fputs(num,question[i]);

        fputs(q,question[i]);
        fputs("\n",question[i]);

        fputs("a)",question[i]);
        fputs(option1,question[i]);
        fputs("\t\t\t\t",question[i]);

        fputs("b)",question[i]);
        fputs(option2,question[i]);
        fputs("\n",question[i]);

        fputs("c)",question[i]);
        fputs(option3,question[i]);
        fputs("\t\t\t\t",question[i]);

        fputs("d)",question[i]); 
        fputs(option4,question[i]);
    }
    
}
void quiz_answer()
{
    limit=fopen("limit.txt", "r");

    if (limit!=NULL)
        fscanf(limit,"%d",&max);
    
    FILE *correctans;
    char correctanswer[max];

    if (limit==NULL)
    {
        marks=0;
        int demoans[5];
        printf("\tThere are 5 Demo Questions in the given Quiz.\n\n");
        printf("\tDemo Questions are loading ...");

        for (i = 0; i <3; i++)
        {
            delay(2);
            printf("..");
            delay(2);
            printf("\b!\b");   
            printf("\b!\b");
            printf("\b!\b");
        }

        system("cls");
        
        for ( i = 0; i < n; i++)
        {
            char filename[20];
            sprintf(filename,"Demo%d.txt",i);
            fp[i] = fopen(filename,"r");
           
            while((ch=fgetc(fp[i]))!=EOF)
            {
                printf("%c",ch);
            }

            printf("Enter your option : ");
            scanf("\n%c",&demooption[i]);
            printf("\tNext Question is loading ...");
            
            for (j = 0; j<3; j++)
            {
                // delay of one second
                delay(1.5);
                printf("..");
                delay(1.5);
                printf("\b!\b");   
                printf("\b!\b");
                printf("\b!\b");
            }  

            system("cls");

            if(demooption[i]==democrctoption[i])
            {
                marks++;
            }
            fclose(fp[i]); 
        }

        printf("\tMarks are loading ...");

        for (i = 0; i <3; i++)
        {
            delay(2);
            printf("..");
            delay(2);
            printf("\b!\b");   
            printf("\b!\b");
            printf("\b!\b");
        }
        
        system("cls");
        printf("Marks you scored is %d",marks);
        exit(0);
    }

    else
    {
        char ans[max];
        FILE *q[max];
        marks=0;
        printf("\tThere are %d questions in the given quiz\n\n",max);
        
        printf("\tQuestions are loading ...");

        for (i = 0; i <3; i++)
        {
            delay(2);
            printf("..");
            delay(2);
            printf("\b!\b");   
            printf("\b!\b");
            printf("\b!\b");
        }

        system("cls");
        
        for ( i = 1; i <= max; i++)
        {
            char filename[20];
            sprintf(filename,"question%d.txt",i);
            q[i] = fopen(filename,"r");

            while((ch=fgetc(q[i]))!=EOF)
            {
                printf("%c",ch);
            }

            printf("\nEnter your option : ");
            scanf("\n%c",&ans[i-1]);  
            
            if(i!=max)
            {
                printf("\t Next Question is loading ...");
                
                for (j= 0; j <3; j++)
                {
                    delay(1);
                    printf("..");
                    delay(1);
                    printf("\b!\b");   
                    printf("\b!\b");
                    printf("\b!\b");
                }
                
                system("cls");

            }  
           
            time(&t);

            correctans= fopen("correct.txt", "r");
            fscanf(correctans, "%s",correctanswer);

            if(ans[i-1]==correctanswer[i-1])
            {
                marks++;
            }

            fclose(q[i]);
        }

            studentstatus= fopen("studentstatus.XLS", "r");

            if (studentstatus==NULL)
            {
                studentstatus=fopen("studentstatus.XLS", "w");
                fputs(" NO.\t Name\tID\tmailid\tMarks\tAnswers\tTime",studentstatus);
                  count=1;
                fputs("\n",studentstatus);
                Number = fopen("count.txt", "w");
                fprintf(Number,"%d",count);
                fclose(Number);
                studentstatus=fopen("studentstatus.XLS", "a");
                fprintf(studentstatus,"%d.\t",count);
                fputs(name,studentstatus);
                fputs("\t",studentstatus);
                fprintf(studentstatus,"%ld",id);
                fputs("\t",studentstatus);
                fputs(mailid,studentstatus);
                fputs("\t",studentstatus);
                fprintf(studentstatus,"%d",marks);
                fputs("\t",studentstatus);

                for ( i = 1; i <= max; i++)                
                    fprintf(studentstatus,"%c ",ans[i-1]);                

                fputs("\t",studentstatus);
                fputs(ctime(&t),studentstatus);
                count=count+1;
                Number= fopen("count.txt", "w");
                fprintf(Number,"%d",count);
                
            }

            else
            {
                Number= fopen("count.txt", "r");
                fscanf(Number,"%d",&count);
                fclose(Number);
                studentstatus=fopen("studentstatus.XLS", "a");
                fputs("\n",studentstatus);
                fprintf(studentstatus,"%d.\t ",count);
                fputs(name,studentstatus);
                fputs("\t",studentstatus);
                fprintf(studentstatus,"%ld",id);
                fputs("\t",studentstatus);
                fputs(mailid,studentstatus);
                fputs("\t",studentstatus);
                fprintf(studentstatus,"%d",marks);
                fputs("\t",studentstatus);

                for ( i = 1; i <= max; i++)
                {
                    fprintf(studentstatus,"%c ",ans[i-1]);
                }

                fputs("\t",studentstatus);
                fputs(ctime(&t),studentstatus);
                count=count+1;
                Number= fopen("count.txt", "w");
                fprintf(Number,"%d",count);
                
            }
             
            printf("\tMarks are loading ...");

            for (i = 0; i <3; i++)
            {
                // delay of one second
                delay(2);
                printf("..");
                delay(2);
                printf("\b!\b");
                printf("\b!\b");
                printf("\b!\b");
            }

            system("cls");
            printf("\t\nMarks you scored:%d",marks);
            exit(0);
            
    }   //    printf("%s",correctanswer);

}

void delay(float s)
{
    int ms = 1000 * s;
    clock_t t = clock();
    while (clock() < t + ms) ;
}

void pattern()
{
   int x; double y;
   char text1[]=    "\n \t\t\t Welcome To Online Quiz Conduct System";
   char text2[]=    "\n \t\t\t\t\t By ";
   char text3[]=    "\n \t\t\t\t\t GROUP 11...... ";
   
    printf("\n\n");

    for(x=0; text1[x]!=NULL; x++)
   {
        printf("%c",text1[x]);
        delay(0.1);   
   }
   
   printf("\n");
    
    for(x=0; text2[x]!=NULL; x++)
   {
     printf("%c",text2[x]);
      delay(0.1);
   }
   
   printf("\n");
    for(x=0; text3[x]!=NULL; x++)
   {
     printf("%c",text3[x]);
     delay(0.1);
   }
}