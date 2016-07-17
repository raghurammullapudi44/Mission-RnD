#include<stdio.h>
#include<stdlib.h>

int a_amp(int *,int *);

int * vowel(char *);

struct test
{
	char input[20];
	int output[2];
}testDB[10]={{{"mullApudi"},{4,5}},
		{{"raghu"},{2,3}},
		{{"ram"},{1,2}},
		{{"mullaPudi raghu ram"},{7,10}},
		{{"suresh"},{2,4}},
		{{"baBu"},{2,2}},
		{{"    "},{0,0}},
		{{"    a"},{1,0}},
		{{"b    "},{0,1}},
		{{"AeIoU\0    "},{5,0}}};


int a_cmp(int a[],int b[])
{
	int i,count=0;
	for(i=0;i<2;i++)
		if(a[i]==b[i])
			count++;
	if(count==2)
		return 0;
	else
		return 1;
}


int * vowel(char a[])
{
	int i,*b;
	
	b=(int *)malloc(sizeof(int)*2);
		b[0]=0;
		b[1]=0;

	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]>=65 && a[i]<=122)
		{
			if(a[i]>=65 && a[i]<=90)
				a[i]=a[i]+32;
			
			if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u')
				++b[0];
			else
				++b[1];
		}
	}
return b;
}

void testcases()
{
	int i,check,*b,j;
	
	for(i=0;i<10;i++)
	{
		b=vowel(testDB[i].input);

		check=a_cmp(b,testDB[i].output);

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








































































































































































