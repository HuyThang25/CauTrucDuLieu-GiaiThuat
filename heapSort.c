#include<stdio.h>
// Tư tưởng của thuật toán này là coi mảng là một cây hoành chỉnh với node thứ i thì có 2 node con là 2*i và 2*i+1
// Thực hiện đẩy các node có giá trị lớn hơn từ dưới lá dần lên trên đầu
// Khi thực hiện xong thì root sẽ là node lớn nhất
// Chuyển root xuống cuối mảng và không xét phần tử đó nữa (chỉ xét mảng từ 0 đến n-2)
// Làm tương tự như thế cho đến khi mảng còn 1 phần tử.
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
    int indexOfMax = root;  // Biến lưu địa chỉ của node có giá trị lớn nhất trong 3 node
    if (left < n && a[left]>=a[indexOfMax]){
        indexOfMax = left;

    }
    if (right < n && a[right]>=a[indexOfMax]){
        indexOfMax = right;
    }
    if (indexOfMax!=root){
        swap(a+indexOfMax,a+root);  // Đảo giá trị của node lớn nhất cho root
        heapify(a,n,indexOfMax); // Tiếp tục chuyển xuống node có giá trị lớn nhất trước đó để làm tương tự
    }
}
void heapSort(int a[], int n){
    // Thực hiện đẩy giá trị lớn nhất của cây lên root của cây, đồng thời thì cững sắp xếp các node cha luôn lớn các node con
    for(int i=n/2-1; i>=0; i--){
        heapify(a,n,i);
    }
    for(int i=n-1; i>=0; i--){
        //Đảo phần tử lớn nhất xuống cuối
        swap(a,a+i);
        //Lại vun giá trị lớn nhất lên root và không xét phần tử cuối nữa
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
