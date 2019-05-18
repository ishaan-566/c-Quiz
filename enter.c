#include<stdio.h>
#include<string.h>
#include<dir.h>
#include<time.h>
void login();
void option(FILE *fp);
void answer(FILE *fp);
void file_main();
void file_main_read();
void create();
void get_file_name();
int ques=0;
char file[10],quiz[99],curr[200];
void getcur();//get current working dirctory an store in curr
void putcur();//restore location in curr as CWD
int num();//return number of users
int main()
{
	FILE *fp,*fo;
	char s[100],c,ch;
	int i,flag=0;
	chdir("DATA");
	login();
	fflush(stdin);
	putcur();
	fo=fopen("file_main.txt","r");
	fscanf(fo,"%d",&i);
	fclose(fo);
//	
//	fo=fopen("file_main.txt","r");
//	fscanf(fo,"%s",quiz);
//	fclose(fo);
	while(1)
	{
		if(i==0)
		{
			printf("\nThere is no quiz present at the time creating one\n");
			system("pause");
			ch='2';
		}
		else
		{
			printf("\nwhat do you want\n\t1.append an existing quiz\n\t2.create a quiz");
			ch=getch();
		}
		switch(ch)
		{
			case '1':
				getcur();
				get_file_name();
				chdir("quiz");
				fp=fopen(file,"a");
				flag=1;
				break;
			case '2':
				do
				{
					printf("\n Enter quiz name:\n");
					gets(s);
				}while(strlen(s)<1);
//				file_main_read();
				fp=fopen("QUIZ.txt","a");
				sprintf(quiz,"%d",++i);
				fo=fopen("file_main.txt","w");
				fprintf(fo,"%d",i);
				fclose(fo);
				fprintf(fp,"%s . %s\n",quiz,s);
				fclose(fp);
				strcat(quiz,".txt");
				getcur();
				chdir("quiz");
				fp=fopen(quiz,"w");
				strcpy(file,quiz);
				flag=1;
				break;
			default:
				printf("enter valid option\n");
		}
		if(flag==1)
		{
			break;
		}
	}
	system("cls");	
	while(1)
	{
		printf("do you want to add a question ?(y/n)");
		if(getch()=='y')
		{
			ques++;
			printf("\nenter ques no %d\n",ques);
			while(1)
			{
				c=getche();
				if(c==27)
				{
					break;
				}
				if(c==13)
				{
					fprintf(fp,"~");
					option(fp);
					answer(fp);
					printf("\nentered successfully");
					break;
				}
				else
				{
					fprintf(fp,"%c",c);
				}
			}
			printf("\n");
			fprintf(fp,"\n");
		}
		else
		{
			putcur();
			break;
		}
	}
	fclose(fp);
//	fp=fopen("test.txt","r");
	printf("\n_______________________");
	getcur();
	chdir("main");
	fp=fopen(file,"w");
	fprintf(fp,"%d",ques);
	fclose(fp);
	putcur();
	getch();
	return 0;
}
void option(FILE *fp)
{
	int i,len,j;
	char s[500]; 
	for(i=1;i<=4;i++)
	{
		printf("\nEnter option %d >>",i);
		gets(s);
		fprintf(fp,"%s~",s);
	}
}
void answer(FILE *fp)
{
	char ch;
	printf("\nwhat is the correct option number>>>");
	while(1)
	{
		ch=getche();
		if(ch=='1'||ch=='2'||ch=='3'||ch=='4')
		{
			break;
		}
		else
		{
			printf("\nenter a valid option");
		}
	}
	fprintf(fp,"%c\n",ch);
}
//void file_main_read()
//{
//	FILE *fp;
//	getcur();
//	chdir("main");
//	fp=fopen(file,"w");
//	fprintf(fp,"%d",ques);
//	putcur();
//	fclose(fp);
//}
void login()
{
	FILE *fp;
	char n1[20],n2[20],p1[20],p2[20],s[40];
	int flag=0,n;
	getcur();
	chdir("confi");
	A:
	n=2*num();
	fp=fopen("account.ishaan","r");
	printf("\nEnter your username---");
	scanf("%s",n1);
	while(n)
	{
		fscanf(fp,"%s",n2);
		if(n%2==0)
		{
			if(strcmp(n1,n2)==0)
			{
				fscanf(fp,"%s",p2);
				flag=1;
				break;
			}		
		}
		n--;
		flag=0;
	}
	if(flag==0)
	{	
		system("cls");
		fclose(fp);
		printf("\nUser did not exist");
		goto A;
	}
	fclose(fp);
	B:
	printf("Enter your password--");
	scanf("%s",p1);
	if(strcmp(p1,p2)!=0)
	{
		printf("password did not match\n");
		goto B;
	}
	fp=fopen("log.ishaan","a");
	time_t t;
	time(&t);
	strcpy(s,ctime(&t));
	fprintf(fp,"%s logged in on %s",n1,s);
	fclose(fp);
	printf("\nLOGIN SUCCESSFUL");
}
void get_file_name()
{
	FILE *fp;
	char c;
	//chdir("DATA");
	getcur();
	printf("\nwhich quiz do you want to open\n");
	fp=fopen("QUIZ.txt","r");
	while(c!=EOF)
	{
		c=fgetc(fp);
		printf("%c",c);
	}
	gets(file);
	fclose(fp);
	strcat(file,".txt");
	chdir("main");
	fp=fopen(file,"r");
	fscanf(fp,"%d",&ques);
	fclose(fp);
	putcur();
}
void getcur()
{
	getcwd(curr,200);
}
void putcur()
{
	chdir(curr);
}
int num()
{
	int number;
	FILE *fp;
	fp=fopen("user_number.ishaan","r");
	fscanf(fp,"%d",&number);
	fclose(fp);
	return number;
}
