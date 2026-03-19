#include <stdio.h>
void swap(int*a , int*b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
int main() {
    int a[100],b,i,j;
    printf("Enter size: ");
    scanf("%d",&b);
    printf("\nEnter Elements: ");
    for(i=0;i<b;i++){
        scanf("%d",&a[i]);
    }
    printf("data before bubble sort: ");
    for(i=0;i<b;i++){
        printf("%d",a[i]);
        }
    for(j=0;j<b-1;j++){
    for(i=0;i<b-1-i;i++){
        if(a[i]>a[i+1]){
            swap(&a[i],&a[i+1]);
          }
        }
        
    }
        printf("\nAfter Bubble Sort: ");
        for(i=0;i<b;i++){
            printf("%d",a[i]);
    }
    return 0;
}
