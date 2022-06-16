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
//Hàm trộn hai mảng (Mảng 1 từ left dến mid-1) (Mảng 2 từ mid dến right-1)
void merge(int a[], int left, int mid , int right){
    int lengthOfArrLeft=mid-left, lengthOfArrRight= right-mid;
    int arrLeft[lengthOfArrLeft],arrRight[lengthOfArrRight];
    for (int i=0; i<lengthOfArrLeft; i++){
        arrLeft[i]= a[i+left];
    }
    for (int i=0; i<lengthOfArrRight; i++){
        arrRight[i]= a[i+mid];
    }
    int i=0, j=0;
    int k=left;
    while (i<lengthOfArrLeft && j<lengthOfArrRight){
        if (arrRight[j]<arrLeft[i]){
            a[k++]=arrRight[j++];
        }
        else {
            a[k++]=arrLeft[i++];
        }
    }
    for (; i<lengthOfArrLeft; i++){
        a[k++]=arrLeft[i];
    }
    for (; j<lengthOfArrRight; j++){
        a[k++]=arrRight[j];
    }
}
void mergeSort(int a[], int left, int right){
    if (left+1 >= right) return;
    int mid = (left+right)/2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
}
int main(){
    int n;
    scanf("%d ",&n);
    int a[n];
    nhapMang(a,n);
    mergeSort(a,0,n);
    inMang(a,n);
    return 0;
}
