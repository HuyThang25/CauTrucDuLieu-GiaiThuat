#include<stdio.h>
#include<malloc.h>

typedef struct {
    int giaTri;
} Data;
typedef struct Node {
    Data data;
    struct Node* next;
    struct Node* prev;
} Node;
typedef struct {
    Node* pHead;
    Node* pTail;
} List;
void init(List* l){
    l->pHead = NULL;
    l->pTail = NULL;
}
Data nhapData(){
    Data data;
    scanf("%d",&data.giaTri);
    return data;
}
Node* taoNode(Data data){
    Node* pNode = (Node*)malloc(sizeof(Node));
    pNode->next=NULL;
    pNode->prev=NULL;
    pNode->data=data;
    return pNode;
}
void themNodeVaoDau(List* l, Node* pNode){
    if (pNode==NULL) {printf("Thong tin khong the khoi tao.\n");return;}
    if (l->pHead == NULL){
        pNode->next=NULL;
        pNode->prev=NULL;
        l->pHead=pNode;
        l->pTail=pNode;
        return;
    }
    pNode->next = l->pHead;
    l->pHead->prev = pNode;
    pNode->prev = NULL;
    l->pHead = pNode;
}
void themNodeVaoCuoi(List* l, Node* pNode){
    if (pNode==NULL) {printf("Thong tin khong the khoi tao.\n");return;}
    if (l->pHead == NULL){
        pNode->next=NULL;
        pNode->prev=NULL;
        l->pHead=pNode;
        l->pTail=pNode;
        return;
    }
    l->pTail->next=pNode;
    pNode->next=NULL;
    pNode->prev = l->pTail;
    l->pTail=pNode;
}
Node* layDiaChiTheoTen(List* l, int d){ //char ten[]){
    for (Node* i=l->pHead; i!=NULL; i=i->next){
        //if (strcmp(i->data.hoTen,ten)==0)
        if (d==i->data.giaTri) return i;
    }
    return NULL;
}
int chenNodeVaoTruoc(List* l, int d){ //char ten[]){
    Node* vt=layDiaChiTheoTen(l,d);
    if(vt==NULL) return 0;
    printf("Nhap gia tri muon them:\n");
    Node* pNode = taoNode(nhapData());
    if (pNode==NULL) return -1;
    pNode->next=vt;
    if (l->pHead==vt) l->pHead=pNode;
    else vt->prev->next=pNode;
    pNode->prev=vt->prev;
    vt->prev=pNode;
    return 1;
}
int chenNodeVaoSau(List* l, int d){ //char ten[]){
    Node* vt=layDiaChiTheoTen(l,d);
    if(vt==NULL) return 0;
    printf("Nhap gia tri muon them:\n");
    Node* pNode = taoNode(nhapData());
    if (pNode==NULL) return -1;
    if (l->pTail==vt) l->pTail=pNode;
    else vt->next->prev=pNode;
    pNode->next=vt->next;
    vt->next=pNode;
    pNode->prev=vt;
    return 1;
}
int xoaNode(List* l, int d){//char ten[]){
    Node* vt=layDiaChiTheoTen(l,d);
    if(vt==NULL) return 0;
    if (l->pHead==l->pTail)
        init(l);
    else{
        if (l->pHead!=vt)
            vt->prev->next=vt->next;
        else l->pHead=l->pHead->next;
        if (l->pTail!=vt)
            vt->next->prev=vt->prev;
        else l->pTail=l->pTail->prev;
        free(vt);
    }
    return 1;
}
int suaNode(List* l, int d){
    Node* vt=layDiaChiTheoTen(l,d);
    if(vt==NULL) return 0;
    printf("Nhap gia tri thay the: ");
    vt->data=nhapData();
    return 1;
}
void hoanDoi2Node(List* l, Node* p1, Node* p2){
    if (p1==p2) return;
    if (p1->next==p2){
        if(p1==l->pHead)
            l->pHead=p2;
        else
            p1->prev->next=p2;
        if(p2==l->pTail)
            l->pTail=p1;
        else
            p2->next->prev=p1;
        p2->prev=p1->prev;
        p1->next=p2->next;
        p2->next=p1;
        p1->prev=p2;
    }
    else if (p1->prev==p2){
        hoanDoi2Node(l,p2,p1);
    }
    else{
        if (p1==l->pHead)
            l->pHead=p2;
        else
            p1->prev->next=p2;
        p1->next->prev =p2;
        p2->prev->next=p1;
        if (p2==l->pTail)
            l->pTail=p1;
        else
            p2->next->prev=p1;
        Node tmp=(*p2);
        p2->next=p1->next;
        p2->prev=p1->prev;
        p1->next=tmp.next;
        p1->prev=tmp.prev;
    }
}
void hienThi(List* l){
    for(Node* i=l->pHead; i!=NULL; i=i->next){
        printf("%d ",i->data);
    }
    printf("\n");
}
void xoaDanhSach(List* l){
    while (l->pHead!=NULL){
        Node* pNode=l->pHead;
        l->pHead=l->pHead->next;
        free(pNode);
    }
    init(l);
}
int main(){
    List l;
    init(&l);
    themNodeVaoCuoi(&l,taoNode(nhapData()));
    themNodeVaoCuoi(&l,taoNode(nhapData()));
    themNodeVaoCuoi(&l,taoNode(nhapData()));
    themNodeVaoCuoi(&l,taoNode(nhapData()));
    themNodeVaoCuoi(&l,taoNode(nhapData()));
    while(1){hoanDoi2Node(&l,layDiaChiTheoTen(&l,nhapData().giaTri),layDiaChiTheoTen(&l,nhapData().giaTri));
    hienThi(&l);}
    //printf("%d",l.pHead->prev->prev->data);
    xoaDanhSach(&l);
    return 0;
}
