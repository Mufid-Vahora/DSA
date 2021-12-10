#include <stdio.h> 
#include <stdlib.h> 
#define max 4 
void pqins(int); 
void pqdel(); 
void pqdisplay(); 
int que[3][max]; //taking row as priority 
int f[3] = {0, 0, 0}; 
int r[3] = {-1, -1, -1}; 
int pr, itm; 


int main() 
    {    
        int ch; 
        
        while (1){

    printf("\n************Queue Operations************\n");  printf("\t1---->Queue Insert.\n"); 
    printf("\t2---->Queue Delete.\n"); 
    printf("\t3---->Queue Display.\n"); 
    printf("\t4---->Exit.\n"); 
    printf("\nEnter your choice:"); 
    scanf("%d", &ch); 
 
 
    switch (ch) {
    case 1: 
        printf("Enter the priority of element(1-3):");  scanf("%d", &pr); 
        if (pr > 0 && pr < 4){ 
            pqins(pr - 1); 
        } 
        else { 
        printf("Invalid priority."); 
        } 
    break; 
 
    case 2: 
        pqdel(); 
    break; 
 
    case 3: 
        pqdisplay(); 
    break; 
    case 4: 
        exit(0); 
    } 
    } 
} 


void pqins(int pr) {
 
 int item; 
    if (r[pr] == max - 1) {

        printf("\nQueue is full.\n"); 
        } 
    else { 
 
    printf("\nEnter element to enter:"); 
    scanf("%d", &itm); 
    r[pr]++; 
    que[pr][r[pr]] = itm; 
    break;
 } 
} 


void pqdel(){ 
 int i; 
 
 for (i = 0; i < 3; i++) { 
    if (r[i] != f[i] - 1) { 
 
        printf("The deleted element is %d of %d.", que[i][f[i]], i + 1);  f[i]++; 
    break; 
    } 
 } 
}



void pqdisplay() 
{ 
 int i, j; 
    
    for (i = 0; i < 3; i++){

        if (r[i] == f[i] - 1) {

            printf("\nQueue %d is empty.", i + 1);  } 
        else{ 
            printf("\nThe elements in Queue are %d\n", i + 1);  for (j = f[i]; j <= r[i]; j++) 
            { 
                printf("%d ", que[i][j]); 
            } 
        printf("\n"); 
        } 
    } 
    break;
}
