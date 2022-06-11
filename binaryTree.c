#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

typedef int Data;
typedef struct Node{
    Data data;
    struct Node* left;
    struct Node* right;
}Node;
typedef struct{
    Node* root;
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
    if (b->root==NULL) {
        b->root=createNode(inputData());
        *(pNode)=b->root;
    }
    else{
        *(pNode)=createNode(inputData());
        createBinaryTree(b,&((*pNode)->left),level-1);
        createBinaryTree(b,&((*pNode)->right),level-1);
    }
}
void init(BinaryTree* b){
    b->root=NULL;
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
    inorderTravelal(pNode->left);
    printf("%d ",pNode->data);
    inorderTravelal(pNode->right);
}
void postorderTravelal(Node* pNode){
    if (pNode==NULL){
        return;
    }
    postorderTravelal(pNode->left);
    postorderTravelal(pNode->right);
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
Node* findNodeByValue(Node* root, int value){
    if (root == NULL) return NULL;
    if (value == root->data) return root;
    if (value < root->data){
        return findNodeByValue(root->left, value);
    }
    else {
        return findNodeByValue(root->right,value);
    }
}
Node* findPreNodeByValue(Node* root, int value){
    if (root == NULL || root->data == value) return NULL;
    if (root->left != NULL && root->left->data == value) return root;
    if (root->right != NULL && root->right->data == value) return root;
    if (value < root->data) return findPreNodeByValue(root->left,value);
    if (value > root->data) return findPreNodeByValue(root->right,value);
}
Node* findMinValueRightNode(Node* root){
    if (root->left == NULL) return root;
    return findMinValueRightNode(root->left);
}
Node* findMaxValueLeftNode(Node* root){
    if (root->right == NULL) return root;
    return findMaxValueLeftNode(root->right);
}
int removeNode(Node** root, int value){
    Node* delNode = findNodeByValue(*root,value);
    if (delNode == NULL) return 0;
    Node* successorNode=NULL;
        //Tìm kiếm node thế
    //Trường hợp node cần xoá có 2 node con
    if (delNode->left != NULL && delNode->right != NULL){
        Node* successorNode1 = findMaxValueLeftNode(delNode->left);
        Node* successorNode2 = findMinValueRightNode(delNode->right);
        printf("Node co the thay the: %d %d\n",successorNode1->data,successorNode2->data);
        printf("Chon Node: ");
        int chon;
        scanf("%d",&chon);
        successorNode= chon==successorNode1->data? successorNode1 : successorNode2;
    }
    //Trương hơp node cần xoá có 1 node con hoặc không có node nào
    else {
        successorNode = delNode;
    }
    int valueOfSuccessorNode =  successorNode->data;
    Node* presuccessorNode = findPreNodeByValue(*root,valueOfSuccessorNode);
        //Xoá Node
    //Trường hợp Node cần xoá ở đầu và có nhiều nhất là 1 Node con
    if (presuccessorNode==NULL){
        *root= delNode->left==NULL ? delNode->right : delNode->right;
    }
    //Trường hợp Node cần xoá không ở đầu và có nhiều nhất là 1 Node con
    else if (delNode == successorNode){
        if (presuccessorNode->left==successorNode) presuccessorNode->left= delNode->left==NULL ? delNode->right : delNode->right;
        else presuccessorNode->right= delNode->left==NULL ? delNode->right : delNode->right;
    }
    //Trường hợp Node cần xoá có 2 Node con
    else{
        if (presuccessorNode->left==successorNode) presuccessorNode->left=successorNode->left;
        else presuccessorNode->right=successorNode->right;
        delNode->data=valueOfSuccessorNode;
    }
    free(successorNode);
    return 1;

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
    if (pNode!=NULL){
        deleteBinaryTree(pNode->left);
        deleteBinaryTree(pNode->right);
        free(pNode);
    }
}
void displayBinaryTree(Node* root){
}
void displayMenu(){
    printf("1. Tao cay nhi phan tim kiem.\n");
    printf("2. Chen Node vao cay.\n");
    printf("3. Xoa Node.\n");
    printf("4. In cay nhi phan tim kiem theo Pre-order.\n");
    printf("5. In cay nhi phan tim kiem theo In-order.\n");
    printf("6. In cay nhi phan tim kiem theo Post-order.\n");
    printf("7. Thoat.\n");
}
int main(){
    srand(time(NULL));
    BinaryTree b;
    init(&b);
    displayMenu();
    while(1){
            printf("Option: ");
        char chon=getchar();
        switch(chon){
            case '1':{
                deleteBinaryTree(b.root);
                init(&b);
                int n;
                printf("Nhap so node: ");
                scanf("%d",&n);
                b.root=createNode(getIntRandom(0,100));
                n--;
                while(n--){
                    int x=getIntRandom(0,100);
                    if(isValueExistBinarySearchTree(b.root,x)) n++;
                    else
                        insertNodeIntoBinarySearchTree(b.root,createNode(x));
                }
                break;
            }
            case '2':{
                int value;
                printf("Nhap gia tri muon chen: ");
                scanf("%d",&value);
                if (isValueExistBinarySearchTree(b.root,value)){
                    printf("Gia ti da ton tai.\n");
                }
                else{
                    insertNodeIntoBinarySearchTree(b.root,createNode(value));
                    printf("Them thanh cong.\n");
                }
                printf("Bam bat ky de tiep tuc.\n");
                getch();
                break;
            }
            case '3':{
                int value;
                printf("Nhap gia tri can xoa: ");
                scanf("%d",&value);
                int check = removeNode(&b.root,value);
                if (check) printf("Xoa thanh cong.\n");
                else printf("Khong ton tai gia tri.\n");
                printf("Bam bat ky de tiep tuc.\n");
                getch();
                break;
            }
            case '4':{
                printf("Pre-Order: ");
                preorderTravelal(b.root);
                printf("\n");
                printf("Bam bat ky de tiep tuc.\n");
                getch();
                break;
            }
            case '5':{
                printf("In-Order: ");
                inorderTravelal(b.root);
                printf("\n");
                printf("Bam bat ky de tiep tuc.\n");
                getch();
                break;
            }
            case '6':{
                printf("Post-Order: ");
                postorderTravelal(b.root);
                printf("\n");
                printf("Bam bat ky de tiep tuc.\n");
                getch();
                break;
            }
            case '7':
                deleteBinaryTree(b.root);
                return 0;
            default :
                printf("Chi chon tu 1->6.\n");
                printf("Bam bat ky de tiep tuc.\n");
                getch();
                break;
        }
    }

    return 0;
}
