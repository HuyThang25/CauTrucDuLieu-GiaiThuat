#include<stdio.h>

void backTrack(char source, char tmp, char destination, int n){
    if(n==1){
        printf("%c -> %c\n",source,destination);
        return;
    }
    backTrack(source, destination, tmp, n-1);
    backTrack(source, tmp , destination, 1);
    backTrack(tmp, source, destination,n-1);
}
int main(){
    int n;
    printf("Nhap vao so dia: ");
    scanf("%d",&n);
    backTrack('A','B','C',n);
    return;
}
