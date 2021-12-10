#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define size 20
//Initialization of a Stack
char stack[size];
int top=0;
char pol[100];
int toP=-1;
int rank=0;

void polpush(char x);
void push(char x);
char pop();
int pre(char x);
int r(char x);

//function for conversion
void ans()
{
    char inputS[100],nextchar,temp; 
    int i=0,j=0;

    printf("Enter the input string:");
    
    //Scanning the infix
    scanf("%s",inputS);

    for(i=0;i<inputS[i]!='\0';i++)
    {
        if(top<0)
        {
            printf("Invalid!!");
            break;
        }
        else{
            nextchar=inputS[i];
                //from stack[top] is'(' till nextchar is')' pop all the elements 
                // after pop, push those elements in pol
                if(nextchar==(')'))
                {
                    while(stack[top]!='(')
                    {
                
                        temp=pop();
                        polpush(temp);
                        rank=rank+r(temp);
                    }
                    pop();
                }
    else{
        //pop all the elements until precedence of stack[top] // is greater than nextchar!!
        //then push those elements to pol
        //Then push nextchar to stack
    if(pre(nextchar)<pre(stack[top]))
    {
        while(pre(nextchar)<pre(stack[top]) && stack[top]!='(') 
        {
            temp=pop();
            polpush(temp);
            rank=rank+r(temp);
        }
    push(nextchar);
    }
    else{
        // if the precedence of stack[top] is less than the nextchar then push that in stack
        push(nextchar);
        }
    }
        printf("%c\t\t%s\t\t%s\t\t%d\n", nextchar, stack, pol, rank); }
    }
}


    //push function for pol
void polpush(char x)
{
    toP++;
    pol[toP]=x;
}

    //push function for stack
void push(char x)
{


    if(top==size-1)
    {
        printf("Overflow/nNo more characters can be pushed into Stack."); 
        exit(0);
    }
    else
    {
        top++;
        stack[top]=x;
    }
}


    //pop function for stack
char pop()
{
    if(top==-1)
    {
     printf("Underflow\nNo more characters can be deleted from the Stack.");
     exit(0);
    }
    else{
        char temp=stack[top];
        stack[top]='\0';
        top--;
        return temp;
        }
}
        
        
//rank function
int r(char x)
{
    //For operators
        if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
        {
            return -1;
        }
    //for operands
        return 1;
}
        
//precedence function
int pre(char x)
{
    //For operators
    if(x=='+'||x=='-')
    {
     return 1;
    }
    else if(x=='*'||x=='/')
    {
    return 2;
    }
    else if(x=='^')
    {
    return 3;
    }
        //For Operands
    else if((x>='a' && x<='z')||(x>='A' && x<='Z'))
            { 
                return 4;
            }
}
            
            
            
void main()
{
    stack[0] ='(';
    ans();

    printf("\n\nTOP: %d\nRANK: %d\n", top, rank);
    printf("POSTFIX EXPRESSION: %s", pol);
}