#include<stdio.h>
#include<string.h>

int priority[255];
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
    s->arr[(s->top)--]='\0';
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
void chuyenDoiTT_HT(char* str, char* result){
    Stack s;
    init(&s);
    int len = 0;
    for(int i=0; i<strlen(str); i++){
        //   Nếu là số thì thêm vào biểu thức hâu tố
        if(str[i]>='0' && str[i]<='9' || str[i]==' '){
            result[len++]=str[i];
        } // Nếu là '(' thì pop stack cho đến khi gặp dấu '('
        else if (str[i] == ')'){
            for(int i=0; i<=s.top; i++){
            }
            while (s.arr[s.top] != '('){
                result[len++]=pop(&s);
            }
            pop(&s);

        } // Nếu là '(' thì push vào stack
        else if (str[i] == '('){
            push(&s,str[i]);
        } // Nếu là các phép toán thì xét với đỉnh stack, nếu đỉnh stack có độ ưu tiên lớn hơn thì được ra trước, không thì push lên stack
        else if (str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
            if (!isEmty(s) && s.arr[s.top] != '(' && priority[str[i]] <= priority[s.arr[s.top]]){
                while(!isEmty(s) && s.arr[s.top] != '(' && priority[str[i]] <= priority[s.arr[s.top]]){
                    result[len++]=pop(&s);
                }
            }
            push(&s,str[i]);
        }
    }
    // Viết vào hậu tố cho đến khi hết stack
    while(!isEmty(s)){
        result[len++]=pop(&s);
    }
    result[len]='\0';
}
int main(){
    priority['*'] = priority ['/'] = 1;
    priority['+'] = priority ['-'] = 0;
    char str[1000];
    printf("Nhap vao bieu thuc: ");
    gets(str);
    char result[1000];
    chuyenDoiTT_HT(str,result);
    puts(result);
    return 0;
}
