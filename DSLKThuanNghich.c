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
int xoaNodeTheoData(List* l, int d){//char ten[]){
    Node* vt=layDiaChiTheoTen(l,d);
    if(vt==NULL) return 0;
    if (l->pHead!=vt)
        vt->prev->next=vt->next;
    else l->pHead=l->pHead->next;
    if (l->pTail!=vt)
        vt->next->prev=vt->prev;
    else l->pTail=l->pTail->prev;
    free(vt);
    return 1;
}
void xoaNodeTheoDiaChi(List* l, Node* vt){
    if (l->pHead!=vt)
        vt->prev->next=vt->next;
    else l->pHead=l->pHead->next;
    if (l->pTail!=vt)
        vt->next->prev=vt->prev;
    else l->pTail=l->pTail->prev;
    free(vt);
}
int suaNode(List* l, int d){
    Node* vt=layDiaChiTheoTen(l,d);
    if(vt==NULL) return 0;
    printf("Nhap gia tri thay the: ");
    vt->data=nhapData();
    return 1;
}
void hoanDoi2Node(List* l, Node* p1, Node* p2){
    //Trường hợp hai node cùng vị trí
    if (p1==p2) return;
    //Trường hợp 2 node cạnh nhau
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
        hoanDoi2Node(l,p2,p1 );
    }
    //Trường hợp hai node ở hai vị trí xa nhau
    else{
        Node* tmpHead = l->pHead;
        Node* tmpTail = l->pTail;
        if(p1==tmpHead)
            l->pHead = p2;
        else
            p1->prev->next=p2;
        if (p1==tmpTail)
            l->pTail=p2;
        else
            p1->next->prev=p2;
        if (p2==tmpHead)
            l->pHead=p1;
        else
            p2->prev->next=p1;
        if (p2==tmpTail)
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
/*void daoNguocDS(List* l){
    if (l->pHead==l->pTail) return;
    for(Node* i=l->pHead->next; i!=NULL; i=i->next){
        Node* tmp =i->prev->next;
        i->prev->next=i->prev->prev;
        i->prev->prev=tmp;
    }
    Node* tmp=l->pHead;
    l->pHead=l->pTail;
    l->pTail=tmp;
}*/
void xoaPhanTuTrung(List* l){
    Node* i=l->pHead;
    while(i!=l->pTail){
        Node* j=i;
        while(j->next!=NULL){
            if (i->data.giaTri==j->next->data.giaTri){
                xoaNodeTheoDiaChi(l,j->next);
            }
            else j=j->next;
        }
        i=i->next;
        if (i==NULL) break;
    }
}
void hienThi(List* l){
    if (l->pTail==NULL){
        printf("Trong\n");
    }
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
void in(int a, int b, int c){
    printf("%d %d %d",a,b,c);
}
int main(){
    List l;
    init(&l);
    themNodeVaoCuoi(&l,taoNode(nhapData()));
    themNodeVaoCuoi(&l,taoNode(nhapData()));
    themNodeVaoCuoi(&l,taoNode(nhapData()));
    themNodeVaoCuoi(&l,taoNode(nhapData()));
    themNodeVaoCuoi(&l,taoNode(nhapData()));
    themNodeVaoCuoi(&l,taoNode(nhapData()));
    xoaPhanTuTrung(&l);
    hienThi(&l);
    xoaDanhSach(&l);
    return 0;
}
