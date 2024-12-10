#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define maxsize 5
void enqueue();
void dequeue();
void display();
int front=-1,rear=-1;
int queue[maxsize];
void main()
{
int choice;
clrscr();
while(1)
{
printf("\n1.insert an element \n 2.delete an element \n 3.display queue \n 4.exit \n");
printf("enter your choice: \n");
scanf("%d",&choice);
switch(choice)
{
case 1:enqueue();
break;
case 2:dequeue();
break;
case 3:display();
break;
case 4:exit(0);
break;
default:printf("enter the valid choice! \n");
}
}
}
void enqueue()
{
int item;
printf("enter the element:");
scanf("%d",&item);
if(rear==maxsize-1)
{
printf("queue overflow \n");
return;
}

else if(front==-1 && rear==-1)
{
front=0;
rear=0;
queue[rear]=item;
}
else
{
rear=rear+1;
queue[rear]=item;
printf("value inserted \n");
}
}
void dequeue()
{
if(front==-1 || front>rear)
{
printf("queue underflow");
return;
}
printf("value deleted:%d \n",queue[front]);
if(front==rear)
{
front=-1;
rear=-1;
}
else
{
front=front+1;
}
}
void display()
{
int i;
if(rear==-1)
{
printf("queue is empty \n");
}
else
{
printf("queue elements are: \n");
for(i=front;i<=rear;i++)
{
printf("%d",queue[i]);
}
printf("\n");
}
}
