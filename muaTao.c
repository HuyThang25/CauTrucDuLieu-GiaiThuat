#include <stdio.h>
#include <stdlib.h>

void nhapMang(int a[], int n){
    for(int i=1; i<=n; i++){
        scanf("%d",a+i);
    }
}
void muaTao(int a[], int n, int k, int * min, int gia, int luong, int so){
    if (luong == k && so>=n) {
        if (*min==0 || *min > gia) *min = gia;
        return;
    }
    if (luong > k) return;
    for (int i=1; i<=n; i++){
        if (a[i]!=-1)
            muaTao(a,n,k,min,gia+a[i],luong+i,so+1);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++){
        int n,k;
        scanf("%d %d ",&n,&k);
        int a[k+1];
        nhapMang(a,k);
        int min=0;
        muaTao(a,n,k,&min,0,0,0);
        printf("%d ",min==0? -1:min);
    }
    return 0;
}
