#include<stdio.h>
int array[50];

void insertion_sort(int n){
    int temp , k;
    for(int j=1 ; j<n ; j++){
        temp = array[j];
        k = j-1 ;
        while( (k>=0) && (array[k]>temp) ){
            array[k+1] = array[k];
            k = k-1 ;
        }
        array[k+1] = temp ;
        for(int i=0 ; i<n ; i++){
        printf("%d\t",array[i]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("enter the number of elements in array:");
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        printf("%d : ",i+1);
        scanf("%d",&array[i]);
    }
    insertion_sort(n);
    printf("the sorted array will be:\n");
    for(int i=0 ; i<n ; i++){
        printf("%d\t",array[i]);
    }
return 0;
}
