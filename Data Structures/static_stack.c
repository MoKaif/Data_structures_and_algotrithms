#include<stdio.h>
# define size 5
struct stack
{
    int item[size];
    int top;
}s;
int item[size];
int top;


int empty()
{
    if(s.top==-1)
    return 1;
    else
    return 0;
}

int full()
{
    if(s.top==size-1)
        return 1;
    else
        return 0;
}

void push(int x)
{
    if(full())
        printf("\n Stack Overflow");
    else
    {
        s.top++;
        s.item[s.top]=x;
    }
}

void pop()
{
    if(empty()==1)
    {
       printf("\nStack is empty");
        s.top--; 
    }      
    else if(s.top == -2)
    {
        printf("\n Stack Underflow");
    }
    else
    {
        printf("\nPopped element: %d",s.item[s.top]);
        s.top--;
    }
        
}

void display()
{
    int i;
    if(empty()==1)
        printf("\nStack Is Empty");
    else
    {
        for(i=0;i<=s.top;i++)
        {
            printf("%d\t",s.item[i]);
        }
    }
}

int main()
{
    int x,c;
    s.top=-1;

    do
    {

        printf("\n Enter your Choice from below. Press 4 to Exit:  \n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("\n Enter element to be pushed: \n");
                scanf("%d",&x);
                push(x);
                break;
            case 2: 
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n Stack Ended...");
                break;
            default:
                printf("\n Please select the correct Option");
                break;
        }
    }while(c!=4);
    return 0;
}