#include"ishaan.h"
#include<dir.h>
void screen();
void data(int,int);
void clr();
int Read();//return number of quizs
int choose();
void play();
void getcur();
void putcur();
void cursor(int,char);
void File();
void getQuiz();
void date();
int no,score=0;
char name[30],file[10],curr[200],F[2];
int main()
{
	chdir("DATA");
	if(Read()==0)
	{
		int c=6500;
		printf("SORRY NO QUIZ TO PLAY\nEXITING IN       seconds");
		elaps(5,15,1);
		return 0;
	}
	do
	{
		printf("enter your name\n");
		gets(name);
	}while(strlen(name)<=0);
	getQuiz();
	fflush(stdin);
	clr();
	play();
	File();
	printf("%s got %d score",name,score);
	getch();
	return 0;
}
void clr()
{
	system("cls");
	screen();
}
void data(int ques,int score)
{
	clr();
	gotoxy(15,2);
	char s[30]="A QUIZ BY ISHAAN AGGARWAL";
	printf("QUES No %d\t\t\t %s\t\t\t\t SCORE :: %d",ques,s,score);
}
void screen()
{
	int i;
	printf("         ");
	for(i=0;i<120;i++)
	{
		printf("-");	
	}
	for(i=1;i<=40;i++)
	{
		gotoxy(8,i);
		printf("|");
		gotoxy(129,i);
		printf("|");
	}
	gotoxy(9,i);
	for(i=0;i<120;i++)
	{
		printf("-");	
	}
	gotoxy(9,4);
	for(i=0;i<120;i++)
	{
		printf("-");	
	}
	gotoxy(9,22);
	for(i=0;i<120;i++)
	{
		printf("-");	
	}
	for(i=0;i<18;i++)
	{
		gotoxy(69,23+i);
		printf("|");
	}
	gotoxy(9,31);
	for(i=0;i<120;i++)
	{
		printf("-");	
	}
	for(i=0;i<3;i++)
	{
		gotoxy(39,i+1);
		printf("|");
		gotoxy(99,i+1);
		printf("|");
	}
}
int Read()
{
	FILE *fp;
	fp=fopen("file_main.txt","r");
	fscanf(fp,"%d",&no);
	fclose(fp);
	return (no);
}
void play()
{
	int ques=0,option,choice,correct,i,count,line,j;
	FILE *fp;
	char c;
//	Read();
	getcur();
	chdir("quiz");
	fp=fopen(file,"r");
	for(j=1;j<=no;j++)
	{
		ques++;
		line=5;
		count=0;
		data(ques,score);
		while(1)
		{
			c=fgetc(fp);
			count++;
			if(c=='~')
			{
				break;
			}
			else
			{
				if(count>=110)
				{
					line++;
					count=00;
				}
				if(c==8)
				{
					count-=2;
				}
				else
				{
					gotoxy(15+count,line);
					printf("%c",c);
				}
			}
		}
		count=0;
		for(option=1;option<=4;option++)
		{
			switch(option)
			{
				case 1:line=24;i=13;break;
				case 2:line=24;i=73;break;
				case 3:line=34;i=13;break;
				case 4:line=34;i=73;break;
			}
			gotoxy(i,line);
			printf("%d.) ",option);
			while(1)
			{
				fscanf(fp,"%c",&c);
				count++;
				if(c=='~')
				{
					break;
				}
				else
				{
					if(count>=55)
					{
						line++;
						count=0;
						gotoxy(i,line);
					}
					printf("%c",c);
				}
			}
		}
		fscanf(fp,"%d",&correct);
		choice=choose();
		if(choice==correct)
		{
			score++;
		}
			clr();
	}
	system("cls");
	fclose(fp);
	putcur();
}
int choose()
{
	int l=1,m=1;
	unsigned char w;
	cursor(l,'±');
	gotoxy(0,42);
	printf("your option is: 1");
	while(1)
	{
		w=getch();
		switch(w)
		{
			case 72:
				if(l!=1&&l!=2)
				{
					m=l;
					cursor(m,' ');
					l-=2;
					cursor(l,'±');
					gotoxy(16,42);
					printf("%d",l);
				}
				break;
			case 75:
				if(l!=1&&l!=3)
				{
					m=l;
					cursor(m,' ');
					l-=1;
					cursor(l,'±');
					gotoxy(16,42);
					printf("%d",l);
				}
				break;
			case 77:
				if(l!=2&&l!=4)
				{
					m=l;
					cursor(m,' ');
					l+=1;
					cursor(l,'±');
					gotoxy(16,42);
					printf("%d",l);
				}
				break;
			case 80:
				if(l!=3&&l!=4)
				{
					m=l;
					cursor(m,' ');
					l+=2;
					cursor(l,'±');
					gotoxy(16,42);
					printf("%d",l);
				}
				break;
			case 49:
				m=l;
				l=1;
				gotoxy(16,42);
				printf("%d",l);
				cursor(m,' ');
				cursor(l,'±');
				break;
			case 50:
				m=l;
				l=2;
				gotoxy(16,42);
				printf("%d",l);
				cursor(m,' ');
				cursor(l,'±');
				break;
			case 51:
				m=l;
				l=3;
				gotoxy(16,42);
				printf("%d",l);
				cursor(m,' ');
				cursor(l,'±');
				break;
			case 52:
				m=l;
				l=4;
				gotoxy(16,42);
				printf("%d",l);
				cursor(m,' ');
				cursor(l,'±');
				break;
			case 13:
				return l;
		}
	}
}
void cursor(int l,char c)
{
	int i;
	switch(l)
	{
		case 1:gotoxy(14,30);break;
		case 2:gotoxy(74,30);break;
		case 3:gotoxy(14,40);break;
		case 4:gotoxy(74,40);break;
	}
	for(i=0;i<52;i++)
	{
		printf("%c",c);
	}
}
void File()
{
	char n[30],s[40];
	strcpy(n,name);
	strcat(n,".dat");
	FILE *fp;
	getcur();
	chdir("players");
	fp=fopen(n,"a");
	time_t t;
	time(&t);
	strcpy(s,ctime(&t));
	printf("\n%s\n",s);
	fprintf(fp,"score %d out of %d in quiz no %s on %s\n",score,no,F,s);
	fclose(fp);
	putcur();
	getcur();
	chdir("date");
	date();
	sprintf(n,"%s.dat",F);
	fp=fopen(n,"a");
	fprintf(fp,"%s\t%d/%d\n",name,score,no);
	fclose(fp);
	putcur();
	chdir("complete");
	fp=fopen(n,"a");
	fprintf(fp,"%s\t%d/%d\n",name,score,no);
	fclose(fp);
	putcur();
}
void date()
{
	char s[50],Day[5],mon[5],Year[5],Mon[5],date[10];
	time_t t;
	time(&t);
	strcpy(s,ctime(&t));
//	printf("%s\n",s);
	fflush(stdin);
	Day[0]=s[8];
	Day[1]=s[9];
	Year[0]=s[20];
	Year[1]=s[21];
	Year[2]=s[22];
	Year[3]=s[23];
	mon[0]=s[4];
	mon[1]=s[5];
	mon[2]=s[6];
//	printf("\n%s",mon);
//	printf("%c%c\t%s\t%s",Day[0],Day[1],Year,mon);
	if(strcmp(mon,"Jan")==0)
	strcpy(Mon,"01");
	else if(strcmp(mon,"Feb")==0)
	strcpy(Mon,"02");
	else if(strcmp(mon,"Mar")==0)
	strcpy(Mon,"03");
	else if(strcmp(mon,"Apr")==0)
	strcpy(Mon,"04");
	else if(strcmp(mon,"May")==0)
	strcpy(Mon,"05");
	else if(strcmp(mon,"Jun")==0)
	strcpy(Mon,"06");
	else if(strcmp(mon,"Jul")==0)
	strcpy(Mon,"07");
	else if(strcmp(mon,"Aug")==0)
	strcpy(Mon,"08");
	else if(strcmp(mon,"Sep")==0)
	strcpy(Mon,"09");
	else if(strcmp(mon,"Oct")==0)
	strcpy(Mon,"10");
	else if(strcmp(mon,"Nov")==0)
	strcpy(Mon,"11");
	else if(strcmp(mon,"Dec")==0)
	strcpy(Mon,"12");
	sprintf(date,"%c%c.%s.%s",s[8],s[9],Mon,Year);
	mkdir(date);
	chdir(date);
}
void getQuiz()
{
	FILE *fp;
	char c;
	int max=Read(),ch;
	getcur();//current working dir
	printf("\nwhich quiz do you want to open\n");
	fp=fopen("QUIZ.txt","r");
	while(c!=EOF)
	{
		c=fgetc(fp);
		printf("%c",c);
	}
	fclose(fp);
	ch=0;
	while(ch<1||ch>max)
	{
		printf("enter valid option>>");
		fflush(stdin);
		scanf("%d",&ch);
	}
	sprintf(file,"%d",ch);
	strcpy(F,file);
	strcat(file,".txt");
	chdir("main");
	fp=fopen(file,"r");
	fscanf(fp,"%d",&no);
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
