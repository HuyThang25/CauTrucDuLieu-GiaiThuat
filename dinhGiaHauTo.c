#include<stdio.h>
#include<string.h>

typedef struct {
    int arr[100];
    int top;
}Stack;
void init(Stack* s){
    s->top = -1;
}
int isEmty(Stack s){
    return s.top==-1;
}
int pop(Stack* s){
    if (isEmty(*s)) return -1;
    int tmp = s->arr[s->top];
    s->top--;
    return tmp;
}
int isFull(Stack s){
    return s.top == 99;
}
int  push(Stack* s, int n){
    if(isFull(*s)) return 0;
    s->arr[++s->top] = n;
    return 1;
}
int thucHienPhepToan(int a, int b, char phepToan){
    switch (phepToan){
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    }
}
int dinhGiaHauTo(char* str){
    Stack s;
    init(&s);
    int number = 0;
    int a,b;
    for(int i=0; i<strlen(str); i++){
        if (str[i]==' '){
            number = 0;
        }
        else if (str[i]>='0' && str[i]<='9'){
            number = number*10 + (str[i]-'0');
            if (str[i+1]<'0' || str[i+1]>'9'){
                push(&s,number);
            }
        }
        else {
            b = pop(&s);
            a = pop(&s);
            push(&s,thucHienPhepToan(a,b,str[i]));
        }
    }
    return pop(&s);
}
int main(){
    char str[1000];
    printf("Nhap vao bieu thuc: ");
    gets(str);
    printf("Ket qua = %d",dinhGiaHauTo(str));
    return 0;
}
