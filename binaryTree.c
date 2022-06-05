#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>

typedef int Data;
typedef struct Node{
    Data data;
    struct Node* left;
    struct Node* right;
}Node;
typedef struct{
    Node* pHead;
}BinaryTree;
Data inputData(){
    Data d;
    scanf("%d",&d);
    return d;
}
Node* createNode(Data d){
    Node* pNode = (Node*)malloc(sizeof(Node));
    pNode->data=d;
    pNode->left=NULL;
    pNode->right=NULL;
    return pNode;
}
int getIntRandom(int min, int max){
    return rand()%(max-min)+ min;
}
void createBinaryTree(BinaryTree* b,Node** pNode, int level){
    if (level<=0) return;
    if (b->pHead==NULL) {
        b->pHead=createNode(inputData());
        *(pNode)=b->pHead;
    }
    else{
        *(pNode)=createNode(inputData());
        createBinaryTree(b,&((*pNode)->left),level-1);
        createBinaryTree(b,&((*pNode)->right),level-1);
    }
}
void init(BinaryTree* b){
    b->pHead=NULL;
}
void preorderTravelal(Node* pNode){
    if (pNode==NULL){
        return;
    }
    printf("%d ",pNode->data);
    preorderTravelal(pNode->left);
    preorderTravelal(pNode->right);
}
void inorderTravelal(Node* pNode){
    if (pNode==NULL){
        return;
    }
    preorderTravelal(pNode->left);
    printf("%d ",pNode->data);
    preorderTravelal(pNode->right);
}
void postorderTravelal(Node* pNode){
    if (pNode==NULL){
        return;
    }
    preorderTravelal(pNode->left);
    preorderTravelal(pNode->right);
    printf("%d ",pNode->data);
}
int isValueExist(Node* pNode, int value){
    if (pNode==NULL) return 0;
    if (pNode->data==value) return 1;
    return (isValueExist(pNode->left,value) || isValueExist(pNode->right,value));
}
int isValueExistBinarySearchTree(Node* pNode, int value){
    if (pNode==NULL) return 0;
    if (value == pNode->data) return 1;
    else if (value < pNode->data){
        return isValueExistBinarySearchTree(pNode->left,value);
    }
    else {
        return isValueExistBinarySearchTree(pNode->right,value);
    }
}
int isBinarySearchTree(Node* pNode){
    if (pNode==NULL) return 1;
    if (pNode->left != NULL && pNode->left->data >= pNode->data) return 0;
    if (pNode->right != NULL && pNode->right->data <= pNode->data) return 0;
    return (isBinarySearchTree(pNode->left) && isBinarySearchTree(pNode->right));
}
void insertNodeIntoBinarySearchTree(Node* pNode, Node* insertedNode){
    if (pNode==NULL) return;
    if (insertedNode->data < pNode->data){
        if (pNode->left == NULL){
            pNode->left = insertedNode;
        }
        else{
            insertNodeIntoBinarySearchTree(pNode->left,insertedNode);
        }
    }
    else {
        if (pNode->right == NULL){
            pNode->right = insertedNode;
        }
        else{
            insertNodeIntoBinarySearchTree(pNode->right,insertedNode);
        }
    }
}
void deleteBinaryTree(Node* pNode){
    if (pNode==NULL) return;
    deleteBinaryTree(pNode->left);
    deleteBinaryTree(pNode->right);
    free(pNode);
}
int main(){
    srand(time(NULL));
    BinaryTree b;
    init(&b);
    int n;
    scanf("%d",&n);
    b.pHead=createNode(getIntRandom(0,100));
    n--;
    while(n--){
        int x=getIntRandom(0,100);
        //if(isValueExistBinarySearchTree(b.pHead,x)) n++;
        //else
        insertNodeIntoBinarySearchTree(b.pHead,createNode(x));
    }

    preorderTravelal(b.pHead);
    printf("\n");
    inorderTravelal(b.pHead);
    printf("\n");
    postorderTravelal(b.pHead);
    printf("\n");
    printf("%d",isBinarySearchTree(b.pHead));
    deleteBinaryTree(b.pHead);
    return 0;
}
