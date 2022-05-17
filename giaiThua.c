#include <stdio.h>

unsigned long long giaiThua(int n){
    if (n==1) return 1;
    return giaiThua(n-1)*n;
}
int main(){
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++){
        int n;
        scanf("%d",&n);
        printf("%llu\n",giaiThua(n));
    }
    return 0;
}
