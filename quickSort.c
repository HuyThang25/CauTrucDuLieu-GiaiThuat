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
    // Phân mảng thành 2 phần: phần 1 là những số nhỏ hơn x; phần 2 là những số lớn hơn x
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
    //Sắp xếp tiếp những phần 1 và 2
    if (left<j) quickSort(a,left,j);
    if (i<right) quickSort(a,i,right);
}
int main(){
    int n;
    scanf("%d ",&n);
    int a[n];
    nhapMang(a,n);
    inMang(a,n);
    quickSort(a,0,n-1);
    inMang(a,n);
    return 0;
}
