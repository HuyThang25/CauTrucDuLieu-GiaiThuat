#include <stdio.h>
typedef struct {
    char arr[100];
    int top;
}Stack;
void init(Stack* s){
    s->top = -1;
    s->arr[0] ='\0';
}
int isEmty(Stack s){
    return s.top==-1;
}
char pop(Stack* s){
    if (isEmty(*s)) return -1;
    char tmp = s->arr[s->top];
    s->arr[s->top--]='\0';
    return tmp;
}
int isFull(Stack s){
    return s.top == 99;
}
int  push(Stack* s, char c){
    if(isFull(*s)) return 0;
    s->arr[++s->top] = c;
    return 1;
}
int laHopLe(char* str){
    Stack s;
    init(&s);
    for (int i=0; i<strlen(str); i++){
        if (str[i]=='('){
                push(&s,str[i]);

            }
        else if (str[i]==')'){
            if (pop(&s)==-1){
                return 0;
            }
        }
    }
    return isEmty(s);
}
int main(){
    char str[1000];
    printf("Nhap vao bieu thuc: ");
    gets(str);
    if (laHopLe(str)){
        printf("Bieu thuc hop le");
    }
    else{
        printf("Bieu thuc khong hop le");
    }
    return 0;
}

