#include<stdio.h>
#include<stdlib.h>

struct SubNode
{
    int input;
    struct SubNode *next1, *next2, *next3, *next4;
}*sublistfirst1 = '\0', *sublistfirst2 = '\0', *sublistfirst3 = '\0', *sublistfirst4 = '\0';

struct Node
{
    int data;
    struct SubNode sublistfirst;
    struct Node *next;
}*first = '\0';

void create(int a[], int n)
{
    int i;
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = '\0';
    last = first;
    
    for(i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = '\0';
        last->next = t;
        last = t;
    }
    
    struct SubNode *t1, *t2, *t3, *t4, *end1, *end2, *end3, *end4;
    sublistfirst1 = (struct SubNode *)malloc(sizeof(struct SubNode));
    sublistfirst1->input = a[0];
    sublistfirst1->next1 = '\0';
    end1 = sublistfirst1;
    for(i=4; i<n;)
    {
        t1 = (struct SubNode *)malloc(sizeof(struct SubNode));
        t1->input = a[i];
        t1->next1 = '\0';
        end1->next1 = t1;
        end1 = t1;
        i = i + 4;
    }
    
    sublistfirst2 = (struct SubNode *)malloc(sizeof(struct SubNode));
    sublistfirst2->input = a[1];
    sublistfirst2->next2 = '\0';
    end2 = sublistfirst2;
    for(i=5; i<n;)
    {
        t2 = (struct SubNode *)malloc(sizeof(struct SubNode));
        t2->input = a[i];
        t2->next2 = '\0';
        end2->next2 = t2;
        end2 = t2;
        i = i + 4;
    }
    
    sublistfirst3 = (struct SubNode *)malloc(sizeof(struct SubNode));
    sublistfirst3->input = a[2];
    sublistfirst3->next3 = '\0';
    end3 = sublistfirst3;
    for(i=6; i<n;)
    {
        t3 = (struct SubNode *)malloc(sizeof(struct SubNode));
        t3->input = a[i];
        t3->next3 = '\0';
        end3->next3 = t3;
        end3 = t3;
        i = i + 4;
    }
    
    sublistfirst4 = (struct SubNode *)malloc(sizeof(struct SubNode));
    sublistfirst4->input = a[3];
    sublistfirst4->next4 = '\0';
    end4 = sublistfirst4;
    for(i=7; i<n;)
    {
        t4 = (struct SubNode *)malloc(sizeof(struct SubNode));
        t4->input = a[i];
        t4->next4 = '\0';
        end4->next4 = t4;
        end4 = t4;
        i = i + 4;
    }
}
    
void display(struct Node *p)
{
    while(p!='\0')
    {
        printf("%d -> ",p->data);
        p = p->next;
    }
    printf("NULL\n\n");
}

void displaysub1(struct SubNode *p1)
{
    while(p1!='\0')
    {
        printf("%d -> ",p1->input);
        p1 = p1->next1;
    }
    printf("NULL\n\n");
}

void displaysub2(struct SubNode *p2)
{
    while(p2!='\0')
    {
        printf("%d -> ",p2->input);
        p2 = p2->next2;
    }
    printf("NULL\n\n");
}

void displaysub3(struct SubNode *p3)
{
    while(p3!='\0')
    {
        printf("%d -> ",p3->input);
        p3 = p3->next3;
    }
    printf("NULL\n\n");
}

void displaysub4(struct SubNode *p4)
{
    while(p4!='\0')
    {
        printf("%d -> ",p4->input);
        p4 = p4->next4;
    }
    printf("NULL\n\n");
}

int main()
{
    struct Node *temp;
    int n;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    int a[n];
    for(int j=0; j<n; j++)
    {
        a[j] = j+1;
    }
    create(a,n);
    display(first);
    displaysub1(sublistfirst1);
    displaysub2(sublistfirst2);
    displaysub3(sublistfirst3);
    displaysub4(sublistfirst4);
    return 0;
}