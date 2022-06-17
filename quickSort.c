#include<stdio.h>

void nhapMang(int a[], int n){
    for(int i=0; i<n; i++){
        scanf("%d",a+i);
    }
}
void inMang(int a[], int n){
    for (int i=0; i<n; i++){
        printf("%5d ",a[i]);
    }
    printf("\n");
}
void swap(int* a, int* b){
    int tmp =*a;
    *a=*b;
    *b=tmp;
}
void quickSort(int a[], int left, int right){
    int x=a[(left+right)/2];
    int i=left, j=right;
    do{
        while (a[i]<x) {
            i++;
        }
        while (a[j]>x){
            j--;
        }
        if (i<=j){
            swap(a+i,a+j);
            i++;
            j--;
        }
    } while(i<=j) ;
    if (left<j) quickSort(a,left,j);
    if (i<right) quickSort(a,i,right);

}
int main(){
    int n;
    scanf("%d ",&n);
    int a[n];
    nhapMang(a,n);
    quickSort(a,0,n-1);
    inMang(a,n);
    return 0;
}
