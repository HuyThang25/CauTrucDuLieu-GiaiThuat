#include<stdio.h>

void nhapMang(int a[], int n){
    for(int i=0; i<n; i++){
        scanf("%d",a+i);
    }
}
void inMang(int a[], int n){
    for (int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void swap(int* a, int* b){
    int tmp =*a;
    *a=*b;
    *b=tmp;
}
/*
// Hàm chuyển giá trị lớn nhất lên đầu mảng
void heapify(int a[], int n, int i){
    int root= i;
    int left = 2*i+1;
    int right = 2*i+2;
    if (left < n) {
        heapify(a,n,left);
    }
    if (right < n){
        heapify(a,n,right);
    }
    if (left < n && a[left]>a[root]){
        swap(a+left,a+root);
    }
    if (right < n && a[right]>a[root]){
        swap(a+right,a+root);
    }
}

void heapSort(int a[], int n){
    for (int i=n-1; i>=0;  i--){\
        // Đưa giá trị lớn nhất trong i+1 phần tử lên đầu
        heapify(a,i+1,0);
        //
        swap(a,a+i);
    }
}
*/
void heapify(int a[], int n, int i){
    int root= i;
    int left = 2*i+1;
    int right = 2*i+2;
    int indexOfMax = root; // Chỉ số của phần tử có giá trị to nhất trong 3 node
    if (left < n && a[left]>=a[indexOfMax]){
        indexOfMax = left;

    }
    if (right < n && a[right]>=a[indexOfMax]){
        indexOfMax = right;
    }
    if (indexOfMax!=root){
        swap(a+indexOfMax,a+root);
        heapify(a,n,indexOfMax);
    }
}
void heapSort(int a[], int n){
    // Săp xếp cây sao cho các node cha có giá trị lớn hơn tất cả các node con của nó
    for(int i=n/2-1; i>=0; i--){
        heapify(a,n,i);
    }
    for(int i=n-1; i>=0; i--){
        //Đảo phần tử lớn nhất xuống cuối
        swap(a,a+i);
        // Săp xếp cây sao cho các node cha có giá trị lớn hơn tất cả các node con của nó(Do trước đó đã được sắp xếp mà chỉ đổi một phần tử lên đầu lên chỉ cần sử dụng hàm dưới 1 lần)
        heapify(a,i,0);
    }
}
int main(){
    int n;
    scanf("%d ",&n);
    int a[n];
    nhapMang(a,n);
    heapSort(a,n);
    inMang(a,n);
    return 0;
}
