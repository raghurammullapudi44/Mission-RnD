#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a_amp(char *,char *);

char changecase(char *);

struct test
{
	char input[20];
	char output[20];
}testDB[10]={{{"mullapudi"},{"MULLAPUDI"}},
		{{"ANIL"},{"anil"}},
		{{"suresh"},{"SURESH"}},
		{{"RAGHU"},{"raghu"}},
		{{"ram "},{"RAM "}},					
		{{" Raghu12 Ram"},{" rAGHU12 rAM"}},
		{{"raja sri"},{"RAJA SRI"}},
		{{"Rajasri\0    "},{"rAJASRI"}},
		{{"     "},{"     "}},					
		{{"VV"},{"vv"}}};

int a_cmp(char a[],char b[])
{
	if(strcmp(a,b)==0)
		return 0;
	else
		return 1;
}


char changecase(char a[])
{
	int i=0;
	
	for(i=0;a[i]!='\0';i++)
	{
			if((a[i]>='A' && a[i]<='Z'))
				a[i]=a[i]+32;
			else if((a[i]>='a' && a[i]<='z'))
				a[i]=a[i]-32;
	}
}
	
		
void testcases()
{
	int i,check,len1;
	char *a;
	
	for(i=0;i<10;i++)
	{

		changecase(testDB[i].input);

		for(len1=0;testDB[i].input[len1]!='\0';len1++);

		if(len1==0)
			check=0;
		else
			check=a_cmp(testDB[i].input,testDB[i].output);

		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");
	}

}

int main()
{
	testcases();
	return 0;
}


