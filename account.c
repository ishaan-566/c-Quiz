#include<stdio.h>
#include<string.h>
#include<dir.h>
#include<time.h>
void dateTime(char*);
void num();
void update();
int number;
int main()
{
	FILE *fp;
	char name[20],na[20];
	char password[20],test[20];
	int i;
	chdir("DATA/confi");
	num();
	B:
		fp=fopen("account.ishaan","r");
		printf("Enter your name>>");
		fflush(stdin);
		scanf("%s",name);
		for(i=1;i<=2*number;i++)
		{
			fscanf(fp,"%s",na);
			if(i%2==1)
			{
				if(strcmp(name,na)==0)
				{
					printf("user already exist\ntry again\n");
					fclose(fp);
					goto B;
				}
			}
		}
	fclose(fp);
	fp=fopen("account.ishaan","a");
	A:
		printf("Enter password>>");
		scanf("%s",&password);
		printf("Re-Enter your password>>");
		scanf("%s",&test);
		if(strcmp(password,test)!=0)
		{
			printf("password did not match\ntry again\n");
			goto A;
		}
	fprintf(fp,"%s\t%s\n",name,password);
	dateTime(name);
	printf("user entered successfully");
	update();
	fclose(fp);
	getch();
	return 0;
}
void dateTime(char* name)
{
	time_t t;
	char s[30];
	time(&t);
	strcpy(s,ctime(&t));
	FILE *fp;	
	fp=fopen("log.ishaan","a");
	fprintf(fp,"%s created account on %s\n",name,s);
	fclose(fp);
}
void num()
{
	FILE *fp;
	fp=fopen("user_number.ishaan","r");
	fscanf(fp,"%d",&number);
	fclose(fp);
}
void update()
{
	number++;
	FILE *fp;
	fp=fopen("user_number.ishaan","w");
	fprintf(fp,"%d",number);
	fclose(fp);
}
