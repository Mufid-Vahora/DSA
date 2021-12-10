#include <stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#define max 5 
int Q[max]; 
int F=-1,R=-1; 
void ins(int x); 
void dele(); 
void dis(); 
int main() 
{ 
 int ch,x; 
 while(1){ 
 printf("\t\tMENU\n"); 
 printf("\t1---->INSERTION IN A QUEUE.\n");  printf("\t2---->DELETION FROM A QUEUE.\n");  printf("\t3---->DISPLAY OF QUEUE.\n");  printf("\t4---->EXIT.\n"); 
 printf("\nEnter your choice:"); 
 scanf("%d",&ch); 
 switch(ch){ 
 case 1: 
 printf("\nEnter element to insert:");  scanf("%d",&x); 
 ins(x); 
 break;
 case 2: 
 dele(); 
 break; 
 case 3: 
 dis(); 
 break; 
 case 4: 
 exit(0); 
 default: 
 printf("\nWrong choice!!!"); 
 break; 
 } 
} 
 return 0; 
} 
void ins(int x){ 
 if((R==max-1 && F==0)||(F==R+1)){ 
 printf("Overflow\nNo more elements can be inserted.\n");  } 
 else{ 
 if(F==-1 && R==-1){ 
 //For Empty Queue 
 F=0; 
 R=0; 
 Q[R]=x; 
 } 
 else{ 
 if(R==max-1){
 //Since circular circular queue the rear is, 
 //changed to starting index to continue insertion of elements.  R=0; 
 Q[R]=x; 
 printf("The element %d is inserted.\n",x); 
 } 
 else{ 
  
 R=R+1; 
 Q[R]=x; 
 printf("The element %d is inserted.\n",x); 
 } 
 } 
 } 
 } 
void dele(){ 
 if(F==-1){ 
 printf("Underflow\nNo more elements can be deleted.\n");  } 
 else{ 
 Q[F]=0; 
 if(F==R){ 
 F=-1; 
 R=-1; 
 } 
 else if(F==max-1){ 
 F=0;
 } 
 else{ 
 ++F; 
 } 
 printf("The Item is deleted.\n");  } 
} 
void dis(){ 
 int i=0; 
 if(F==-1){ 
 printf("Queue is empty.\n");  printf("Front is: %d\n",F);  printf("Rear is: %d\n",R);  } 
 else{ 
 for(i=0;i<max;i++){ 
 if(Q[i]==0){ 
 printf("_ "); 
 } 
 else{ 
 printf("%d ",Q[i]); 
 } 
 } 
 printf("\nFront is: %d\n",F);  printf("Rear is: %d\n",R);  } 
}
