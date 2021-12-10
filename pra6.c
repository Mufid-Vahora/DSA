#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}*root=NULL;
struct Node* createTree(int [],int [],int ,int ,int *);

void Postorder(struct Node*);
void Preorder(struct Node* );
void Inorder(struct Node* );


struct Node* createTree(int inorder[],int preorder[],int start,int end,int *index)
{
    struct Node *t;
    if(start>end)
    {
        return NULL;
    }
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=preorder[(*index)++];
    t->lchild=NULL;
    t->rchild=NULL;
    int p;
    for(p=start;p<=end;p++){
        if(inorder[p]==t->data){
            break;
        }
    }
    t->lchild=createTree(inorder,preorder,start,p-1,index);
    t->rchild=createTree(inorder,preorder,p+1,end,index);
    return t;
}
void Postorder(struct Node* s)
{
    if(s!=NULL)
    {
        Postorder(s->lchild);
        Postorder(s->rchild);
        printf("%d ",s->data);
    }
}
void Inorder(struct Node* s){
   if(s!=NULL)
    {
        Inorder(s->lchild);
        printf("%d ",s->data);
        Inorder(s->rchild);
    } 
}
void Preorder(struct Node* s){
   if(s!=NULL)
    {
        printf("%d ",s->data);
        Preorder(s->lchild);
        Preorder(s->rchild);
    } 
}
int main()
{
    int n,i,k;
    printf("\nEnter the total no. of nodes:");
    scanf("%d",&n);
    int inorder[n],preorder[n];
    printf("\nEnter inorder traversal:");
    for(i=0;i<n;i++){
        scanf("%d",&inorder[i]);
    }
    printf("\nEnter preorder traversal:");
    for(i=0;i<n;i++){
        scanf("%d",&preorder[i]);
    }
    k=0;
    root=createTree(inorder,preorder,0,n-1,&k);
    printf("\nPostorder traversal is\n");
    Postorder(root);
    printf("\nInorder traversal is\n");
    Inorder(root);
    printf("\nPreorder traversal is\n");
    Preorder(root);
    return 0;
}