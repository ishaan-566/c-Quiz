#include"ishaan.h"
#include<dir.h>
void removeComplete();
void updateQuizMain();
void getcur();
void putcur();
void removeConfi();
void removeMain();
void removePlayers();
void removeQuiz();
void removeDate();
void login();
int num();
char curr[200000],cur[200000],st[200000],str[40];
int main()
{
	chdir("DATA");
	getcur();
	login();
	putcur();
	char s[50];
	printf("\n are you sure you want to delete if else enter the following string HELLO123hello\n");
	scanf("%s",s);
	if(strcmp(s,"HELLO123hello")!=0)
	{
		printf("wrong string");
		return 0;
	}
	int n,i;
	strcpy(str,"java Mainn ");
	getcur();
	strcpy(cur,curr);
	printf("Removing Complete Directory\n\n");
	removeComplete();
	getcur();	
	chdir("confi");
	printf("Removing Confi Directory\n\n");
	removeConfi();
	putcur();
	removeDate();
	printf("\nRemoving Date Directory\n\n");
	removeMain();
	printf("Removing Main Directory\n\n");
	updateQuizMain();
	printf("Number of quiz updated\n\n");
	removePlayers();
	printf("Removing Players Directory\n\n");
	removeQuiz();
	printf("Removing Quiz Directory\n\n");
	getch();
	return 0;
}
int accessQuizMain()
{
	int n;
	FILE *fp;
	fp=fopen("file_main.txt","r");	
	fscanf(fp,"%d",&n);
	fclose(fp);
	return n;
}
void getcur()
{
	getcwd(curr,200000);
}
void putcur()
{
	chdir(curr);
}
void removeConfi()
{
	if(remove("account.ishaan")==0)
	{
		printf("account data deleted\n\n");
	}
	if(remove("log.ishaan")==0)
	{
		printf("log data deleted\n\n");
	}
	FILE *fp;
	fp=fopen("user_number.ishaan","w");
	fprintf(fp,"1");
	printf("Number of accounts updated\n\n");	
}
void updateQuizMain()
{
	FILE *fp;
	fp=fopen("quiz_main.txt","w");
	fprintf(fp,"0");
}
void removeComplete()
{
	chdir("complete");
	getcur();
	strcpy(st,str);
	strcat(st,curr);
	strcpy(curr,cur);
	putcur();
	system(st);
	mkdir("complete");
}
void removeMain()
{
	chdir("main");
	getcur();
	strcpy(st,str);
	strcat(st,curr);
	strcpy(curr,cur);
	putcur();
	system(st);
	mkdir("main");
}
void removePlayers()
{
	chdir("players");
	getcur();
	strcpy(st,str);
	strcat(st,curr);
	strcpy(curr,cur);
	putcur();
	system(st);
	mkdir("players");
}
void removeQuiz()
{
	chdir("quiz");
	getcur();
	strcpy(st,str);
	strcat(st,curr);
	strcpy(curr,cur);
	putcur();
	system(st);
	mkdir("quiz");
}
void removeDate()
{
	chdir("date");
	getcur();
	strcpy(st,str);
	strcat(st,curr);
	strcpy(curr,cur);
	putcur();
	system(st);
	mkdir("date");
}
void login()
{
	FILE *fp;
	char n1[20],n2[20],p1[20],p2[20],s[40];
	int flag=0,n;
	getcur();
	chdir("confi");
	A:
	n=2*(num()-1);
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
int num()
{
	int number;
	FILE *fp;
	fp=fopen("user_number.ishaan","r");
	fscanf(fp,"%d",&number);
	fclose(fp);
	return number;
}
