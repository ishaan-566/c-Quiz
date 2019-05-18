#include<windows.h>
#include<unistd.h>
#include<time.h>
#include<stdio.h>
#include<conio.h>
#include<dir.h>
void gotoxy(int x,int y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void delay(int delay)
{
	int now=time(NULL),later=now+delay;
	while(now<later)
	now=time(NULL);
}
int rnd(int n)
{
	int loc;
	srand(time(0));
	loc=rand()%n+1;
	return loc;
}
void printa(int *a,int n)
{
	int i;
	for(i=0;i<n;++i)
	printf("%d\t",*(a+i));
}
int elaps(int n,int x,int y)
{
	time_t start = 0;
	time_t end = 0;
	time_t elapsed = 0;
	start = time(NULL);  // grab start time
	// show the question
    // do whatever until the questions are all over
	do
	{
		end = time(NULL);  // grab the end time
		elapsed = start - end;
		gotoxy(x,y);
		printf("%d",elapsed+n);
	}
	while(-elapsed!=n);// compute elapsed time
	return (-elapsed);
}
int inArray(int *a,int n,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(a[i]==n)
		{
			return 1;
			break;
		}
	}
	return 0;
}
