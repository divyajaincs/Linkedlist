#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>
struct node
{
int data;
struct node *next;
} ;
struct node *head;
void insert_atbeg(int);
void traversal();
void insert_atend(int);

//void reversal();
void delete_atbeg();

void delete_atend();
void insert_after(int,int);
void delete_after(int);
void main()
{
clrscr();
int ch,ele,val;
head=NULL;
printf("1:insertion at begin\n");
printf("2:traversal\n");
printf("3 insertion at end\n");
//printf("4: reversal\n");
printf("5:deletion at begin\n");
printf("6:deletion at end\n");
printf("7:insertion after node\n");
printf("8:deletion after node \n");
printf("9:exit");
do
{
printf("enter your choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
	printf("enter ele you want to insert ");
	scanf("%d",&ele);
	insert_atbeg(ele);
	break;

case 2:
	    traversal();
	      break;
case 3:
	printf("enter ele you want to insert ");
	scanf("%d",&ele);
	insert_atend(ele);
	break;
/*case 4 :
	reversal();
	  break;
	  */
case 5:
	delete_atbeg();
	break;
case 6 :
	delete_atend();
	break;

case 7:   printf("enter ele you want to insert ");
	scanf("%d",&ele);
	printf("enter elenent after you want to insert ");
	scanf("%d",&val);
       insert_after(ele,val);
       break;
case 8:
	 printf("enter elenent after you want to delete");
	scanf("%d",&val);
      delete_after(val);
      break;
 case 9 : exit(1);
	break;
}
}
while(ch!=9);
getch();
}
void insert_atbeg(int item)
{
struct node *q,*p;
p=head;
q=(struct node*)malloc(sizeof(struct node));
q->data=item;
q->next=head;
while(p->next!=head)
{
p=p->next;
}
head=q;
p->next=q;
}
void traversal()
{
struct node *p;
p=head;
while(p->next!=head)
{
printf("%d",p->data);
p=p->next;
}
printf("\n");
}
void insert_atend(int item)
{
struct node *q,*p;
p=head;
q=(struct node*)malloc(sizeof(struct node));
q->data=item;
while(p->next!=head)
{
p=p->next;
}
p->next=q;
q->next=head;
}
void delete_atbeg()
{
struct node *p,*q;
p=head;
q=head;
while(p->next!=head)
{
p=p->next;
}
p->next=q->next;
head=q->next;
}
void delete_atend()
{
struct node *p;
p=head;
while(p->next->next!=head)
{
p=p->next;
}
p->next=head;
}
void delete_after(int e)
{
struct node *p;
p=head;
while(p->data!=e)
{
p=p->next;
}
p->next=p->next->next;
printf("deleted element=%d",p->next->data);
}
void insert_after(int b,int v)
{
struct node *r,*p;
p=(struct node *)malloc(sizeof(struct node));
r=head;
while(r!=NULL)
{
if(r->data==v)
{
p->data=b;
p->next=r->next;
r->next=p;
printf("insertion completed");
break;
}
else
r=r->next;
}
}