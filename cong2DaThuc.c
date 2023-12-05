#include <stdio.h>

typedef struct {
    int heSo;
    int luyThua;
} Data;
typedef struct Node{
    Data data;
    struct Node* next;
}Node;
typedef struct {
    Node* pHead;
    Node* pTail;
}List;
void init(List* l){
    l->pHead=NULL;
    l->pTail=NULL;
}
Data nhapData(){
    Data d;
    scanf("%d",&d.heSo);
    scanf("%d",&d.luyThua);
    return d;
}
Node* taoNode(Data data){
    Node* pNode= (Node*)malloc(sizeof(Node));
    pNode->next=NULL;
    pNode->data=data;
    return pNode;
}
void themVaoCuoi(List* l, Node* pNode){
    if (pNode==NULL) {printf("Thong tin khong the khoi tao.\n");return;}
    if (l->pHead==NULL){
        l->pHead=pNode;
        l->pTail=pNode;
    }
    else{
        l->pTail->next=pNode;
        l->pTail=pNode;
    }
}
void hienThiNode(Data sv){
    if (sv.luyThua == 0){
        printf("%d",sv.heSo);
    }
    else if (sv.luyThua ==  1){
        printf("%dx",sv.heSo);
    }
    else {
        printf("%dx^%d",sv.heSo,sv.luyThua);
    }
}
void hienThiDaThuc(List* l){
    if (l->pHead==NULL){
        printf("Da thuc rong\n");
    }
    else{
        Node* i = l->pHead;
        hienThiNode(i->data);
        i = i->next;
        for (; i!=NULL; i=i->next){
            printf(" + ");
            hienThiNode(i->data);
        }
        printf("\n");
    }
}
void taoDaThuc(List *l, int n){
    for (int i=0; i<n; i++){
        themVaoCuoi(l,taoNode(nhapData()));
    }
}
void xoaDaThuc(List* l){
    while (l->pHead!=NULL){
        Node* pNode=l->pHead;
        l->pHead=l->pHead->next;
        free(pNode);
    }
    init(l);
}
void add(List* a, List* b, List*c){
    Node* p = a->pHead;
    Node* q = b->pHead;
    Data tmp;
    while (p != NULL && q != NULL){
        if (p->data.luyThua == q->data.luyThua){
            tmp.heSo = p->data.heSo + q->data.heSo;
            if (tmp.heSo!=0){
                tmp.luyThua = p->data.luyThua;
                themVaoCuoi(c,taoNode(tmp));
            }
            p = p->next;
            q = q->next;
        }
        else if (p->data.luyThua > q->data.luyThua){
            themVaoCuoi(c,taoNode(p->data));
            p = p->next;
        }
        else{
            themVaoCuoi(c,taoNode(q->data));
            q = q->next;
        }
    }
    if (p == NULL){
        while (q != NULL){
            themVaoCuoi(c,taoNode(q->data));
            q = q->next;
        }
    }
    else{
        while (p != NULL){
            themVaoCuoi(c,taoNode(p->data));
            p = p->next;
        }
    }
}
int main(){
    /* Tạo đa thức 1  */
    List daThuc1;
    init(&daThuc1);
    int n;
    printf("Nhap vao so phan tu da thuc 1: ");
    scanf("%d",&n);
    printf("Nhap vao cac he so va so mu: \n");
    taoDaThuc(&daThuc1,n);
    hienThiDaThuc(&daThuc1);

    /* Tạo đa thức 2  */
    List daThuc2;
    init(&daThuc2);
    int m;
    printf("Nhap vao so phan tu da thuc 1: ");
    scanf("%d",&m);
    printf("Nhap vao cac he so va so mu: \n");
    taoDaThuc(&daThuc2,m);
    hienThiDaThuc(&daThuc2);


    /* Tạo đa thức kết quả  */
    List result;
    init(&result);
    add(&daThuc1,&daThuc2,&result);
    printf("Tong hai da thuc tren = ");
    hienThiDaThuc(&result);

    xoaDaThuc(&result);
    xoaDaThuc(&daThuc1);
    xoaDaThuc(&daThuc2);
    return 0;
}
