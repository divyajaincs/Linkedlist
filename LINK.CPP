#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
//int s=0;
struct node *head;
void delete_bet(int);
void insert_atbeg(int);
void traversal(int);
void insert_atend(int);
void insert_after(int,int);
void delete_beg();
void delete_end();
void delete_after(int);
void reverse(int);
void insert_before(int,int);
void delete_before(int);
void reversal();
void duplicate();
void sort();
void swap();
struct node *rec(struct node *);
void main()
{
int ch,ele,val,count;
clrscr();
printf("1:insertion at begin\n");
printf("2:traversal\n");
printf("3:insertion at end\n");
printf("4:insertion after node\n");
printf("5:insertion before node\n");
printf("6:deletion at begin\n");
printf("7:deletion at end\n");
printf("8:deletion after node\n");
printf("9:deletion before node\n");
printf("10:reversal\n");
printf("11:duplicate\n");
printf("12:sort\n");
printf("13:swap\n");
printf("14:exit");
do
{
printf("enter your choice");
scanf("%d",&ch);
switch(ch)
{
case 1 : printf("enter element");
	 scanf("%d",&ele);
	 insert_atbeg(ele);
		 break;
case 2 :    struct node *p;
	  p=head;
	  if(p==NULL)
	  printf("stack is empty");
	  else
	  traversal(count);
	  break;
case 3 :
	  printf("enetr ele.");
	  scanf("%d",&ele);
	  insert_atend(ele);
		 break;
case 4 :
	  printf("enter ele. which you want to insert");
	  scanf("%d",&ele);
	  printf("enter value after you insert node");
	  scanf("%d",&val);
	  insert_after(ele,val);
	  break;
case 5 :
	  printf("enter ele. which you want to insert");
	  scanf("%d",&ele);
	  printf("enter value before you insert node");
	  scanf("%d",&val);
	  insert_before(ele,val);
	  break;
case 6 :
	 delete_beg();
	  break;
case 7 :
	    delete_end();
	   break;
case 8 :   printf("enter value after you delete node");
	  scanf("%d",&val);
	  delete_after(val);
	   break;
case 9 :  printf("enter value before you delete node");
	  scanf("%d",&val);
	  delete_before(val);
	   break;
case 10 :  reversal();
	   break;
case 11:
	  duplicate();
	  break;
case 12:
	 sort();
	   break;
case 13:
	swap();
	break;
case 14:
	  rec(head);
	  break;
case 15:
	 printf("enter ele you want to delete");
	 scanf("%d",&ele);
	delete_bet(ele);
	break;
/*case 16 :
	  reverse();
	  break; */
case 17:
	  exit(1);
	   break;

}
}
while(ch!=17);
getch();
}
void insert_atbeg(int item)
{
struct node *ptr;
ptr=(struct node *)malloc(sizeof(struct node));
ptr->data=item;
ptr->next=head;
head=ptr;
}
void traversal(int c)
{
c=0;
struct node *p;
p=head;
while(p!=NULL)
{
printf("%d\n",p->data);
p=p->next;
c++;
}
printf("total no of nodes are=%d",c);
reverse(c);
}
void insert_atend(int item)
{
struct node *p,*q;
q=(struct node *)malloc(sizeof(struct node));
p=head;
while(p->next!=NULL)
{
p=p->next;
}
q->data=item;
p->next=q;
q->next=NULL;
}
void delete_beg()
{
struct node *d;
d=head;
printf("deleted element=%d",d->data);
head=d->next;
}
void delete_end()
{
struct node *e;
e=head;
while(e->next!=NULL)
{
e=e->next;
}
printf("deleted element=%d",e->data);
e=NULL;
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
printf("deleted element=%d",p->data);
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
void duplicate()
{
struct node *p,*q;
p=head;
while(p!=NULL)
{
q=p;
while(q->next!=NULL)
{
if(p->data==q->next->data)
{
q->next=q->next->next;
q->next->next=NULL;
}
else
{
q=q->next;
}
}
p=p->next;
}
}
void insert_before(int a,int b)
{
struct node *p,*q;
p=head;
q=(struct node *)malloc(sizeof(struct node));
q->data=a;
while(p->next->data!=b)
{
p=p->next;
}
q->next=p->next;
p->next=q;
}
void reversal()
{
struct node *q,*r,*s;
q=head;
r=NULL;
while(q!=NULL)
{
s=r;
r=q;
q=q->next;
r->next=s;
}
head=r;
while(r!=NULL)
{
printf("%d",r->data);
r=r->next;
}
}
void delete_before(int f)
{
struct node *b;
b=head;
while(b->next->next->data!=f)
{
b=b->next;
}
printf("deleted element is =%d ",b->next->data);
b->next=b->next->next;
b->next->next=NULL;
}
void sort()
{
struct node *p,*q,*temp;
p=head;
temp=(struct node *)malloc(sizeof(struct node));
while(p->next!=NULL)
{
q=p;
while(q->next!=NULL)
{
if(p->data>q->next->data)
{
temp->data=q->next->data;
q->next->data=p->data;
p->data=temp->data;
}
else
q=q->next;
}
p=p->next;
}
}
void swap()
{
struct node *p,*q,*temp;
p=head;
temp=(struct node *)malloc(sizeof(struct node));
while(p->next!=NULL&&p!=NULL)
{
q=p->next;
while(q->next!=NULL)
{
temp->data=q->data;
q->data=p->data;
p->data=temp->data;
break;
}
//q=q->next;
p=p->next->next;
}
}
struct node *rec(struct node *head)
{
//struct node *p;
if(head==NULL)
return head;
printf("%d\n",head->data);
rec(head->next);
printf("%d\n",head->data);
}
void delete_bet(int t)
{
struct node *t1,*t2;
t2=(struct node *)malloc (sizeof(struct node));
t1=head;
while(t1->data!=t)
{
t2=t1;
t1=t1->next;
}
t2->next=t1->next;
free(t1);
}
void reverse(int t)
{
struct node *p[50],*temp;
int i;
for(i=0;i<=t;i++)
{
p[i]=(struct node *)malloc(sizeof(struct node));
}
temp=head;
for(i=0;i<=t;i++)
{
p[i]=temp;
temp=temp->next;
}
head=p[i];
printf("reverse of list is:");
for(i=t;i>=0;i--)
{
printf("%d\n",p[i]->data);
p[i]->next=p[i];
}
p[i]->next=NULL;
head=p[0];
}







