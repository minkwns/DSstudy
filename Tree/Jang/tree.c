#include "stdio.h"
#include "stdlib.h"

int sum[100];
typedef struct
{
    int key;
}element;

typedef struct treeNode {
    element key;
    struct treeNode* left;
    struct treeNode* right;
}treeNode;

treeNode* insertKey(treeNode* p, element key)
{
    treeNode* newNode;
    if (p == NULL) 
    {
        newNode = (treeNode*)malloc(sizeof(treeNode));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    // 이진 트리에서 삽입할 자리 탐색
    else {
        if (p->key.key > key.key)
            p->left = insertKey(p->left, key);
        else if (p->key.key < key.key)
            p->right = insertKey(p->right, key);
        else
        {
            printf("same key in binary search tree\n");
            exit(-1);
        }
        return p; // 삽입한 자리 반환
    }
}
void insert(treeNode** root, element key)
{
    *root = insertKey(*root, key);
}
void displayInorder(treeNode* root) //중위탐색 
{
    if (root) 
    {
        displayInorder(root->left);
        printf(" %d ", root->key);
        displayInorder(root->right);
    }
}

int main(void)
{
    element e;
    treeNode* root = NULL, * temp = NULL;
    
    int num, i, key;
    printf("input size of tree : ");
    scanf_s("%d", &num);
    for (i = 0; i < num; i++)
    {
        printf("input %dst key : ", i + 1);
        scanf_s("%d", &e.key);
        insert(&root, e);
    }
    
    printf("tree's displayinorder keys are ");
    displayInorder(root);
    return 0;
}