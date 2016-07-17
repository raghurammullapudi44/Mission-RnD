#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

char *malloc_char(char ip[]);

struct sll * convert_to_list(char *);

struct sll * insert_in_list(int,struct sll *);

struct sll * swap_list(struct sll *);

void swap(int *,int *);

int ll_cmp(struct sll *,struct ll *);

struct test
{
	char input[44];
	char output[44];
}testDB[10]={{"12345678","21436587"},
			{"0123456","1032546"},
			{"44445","44445"},
			{"001234","002143"},
			{"0012345","0021435"},
			{"123400","214300"},
			{"0000001","0000001"},
			{"12340056","21430065"},
			{"01111","10111"},
			{"101011","010111"}};
			

struct sll
{
	int data;
	struct sll *ptr;
};

char * malloc_char(char ip[])
{
	int i;
	char *a;
	a=(char *)malloc(sizeof(char)*1);
	for(i=0;ip[i]!='\0';i++)
	{
		a=(char *)realloc(a,sizeof(char)*(i+1));
		a[i]=ip[i];
	}
	a[i]='\0';
	return a;
}

int ll_cmp(struct sll *ihead,struct sll *ohead)
{
	int count=0,count1=0;

	struct sll *temp=ihead;

	while(temp)
	{
		temp=temp->ptr;
		count++;
	}
	while(ihead)
	{
		if(ihead->data==ohead->data)
			count1++;
		ihead=ihead->ptr;
		ohead=ohead->ptr;
	}
	if(count==count1)
		return 0;
	else
		return  1;
}

struct sll * convert_to_list(char a[])
{
	int i=0;
	struct sll *head=NULL;

	while(a[i]!='\0')
	{
		head=insert_in_list(a[i]-'0',head);
		i++;
	}
	return head;
}



struct sll * insert_in_list(int n,struct sll *head)
{
	if(head==NULL)
	{
		head=(struct sll *)malloc(sizeof(struct sll));
		head->data=n;
		head->ptr=NULL;
		//printf("%d ",head->data);
		return head;
	}
	else
	{
		struct sll *temp,*temp1;
		temp=(struct sll *)malloc(sizeof(struct sll));

		temp->data=n;
		temp->ptr=NULL;

		temp1=head;

		while(temp1->ptr!=NULL)
			temp1=temp1->ptr;

		temp1->ptr=temp;

		//printf("%d ",temp->data);

		return head;
	}
}

struct sll * swap_list(struct sll * head)
{
	struct sll *temp,*temp1;
	temp=head;
	temp1=temp->ptr;

	while(temp->ptr!=NULL && temp1->ptr!=NULL)
	{
		swap(&temp->data,&temp1->data);
		temp=temp->ptr->ptr;
		temp1=temp1->ptr->ptr;
	}
	if(temp!=NULL && temp1!=NULL)
	{
		swap(&temp->data,&temp1->data);
	}
	return head;
}

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
	
void testcases()
{
	int i,check;
	char *a,*op;

	for(i=0;i<10;i++)
	{
		struct sll *ihead,*ohead,*j;

		a=malloc_char(testDB[i].input);

		op=malloc_char(testDB[i].output);

		ihead=swap_list(convert_to_list(a));

		ohead=convert_to_list(op);

		/*for(j=ihead;j!=NULL;j=j->ptr)
			printf("%d ",j->data);

		for(j=ohead;j!=NULL;j=j->ptr)
			printf("%d ",j->data);*/

		check=ll_cmp(ihead,ohead);

		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");
	}
}

int main()
{
	testcases();
	getchar();
	return 0;
}
