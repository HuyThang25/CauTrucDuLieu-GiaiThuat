#include <stdio.h>

int x[100], a[100], b[100], c[100],q,count=0;
void inNghiem(){
    printf("(");
    for(int i=1; i<=8; i++){
        printf("%d,%d ",i,x[i]);
    }
    printf(")\n");
}
void try(j){
    for(int i=1; i<=8; i++){
        if (a[i] && b[i+j] && c[i-j]){
            x[j]=i;
            a[i]=0;
            b[i+j]=0;
            c[i-j]=0;
            if (j<8){
                try(j+1);
            }
            else{
                count++;
                inNghiem();
            }
            a[i]=1;
            b[i+j]=1;
            c[i-j]=1;
        }
    }
}
int main(){
    for (int i = 1; i<=8; i++) a[i] = 1;
    for (int i = 2; i<=16; i++) b[i] = 1;
    for (int i = -7; i<=7; i++) c[i] = 1;
    try(1);
    //printf("%d",count);
    return 0;
}
