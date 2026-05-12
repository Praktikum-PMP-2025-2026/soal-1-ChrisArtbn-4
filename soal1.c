/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 05 - Foundation of Algorithm
 *   Hari dan Tanggal    : Selasa, 12 Mei 2026
 *   Nama (NIM)          : 13224043
 *   Nama File           : dinasti_langit.c
 *   Deskripsi           : 
     Program yang membaca silsilah keluarga dengan preorder, inorder, dan postorder traversal
 */

#include <stdio.h>
#include <stdlib.h> 

struct Node{
    int item;
    struct Node* left;
    struct Node* right;
};

struct Node* buatnode(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->item = item;
    newNode->left = NULL;   
    newNode->right = NULL;
    return newNode;
}

struct Node* buattree(int arr[], int i , int N){
    if (i >= N)
    return NULL;

    struct Node* root = buatnode(arr[i]);
    root->left = buattree(arr, 2*i + 1, N);
    root->right = buattree(arr, 2*i + 2, N);
    return root;
}

void preorder(struct Node* root){
    if (root == NULL)
    return;
    printf("%d ", root->item);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root){
    if (root == NULL)
    return;
    inorder(root->left);
    printf("%d ", root->item);
    inorder(root->right);
}

void postorder(struct Node* root){
    if (root == NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->item);
}

int main(){
    int N;
    scanf("%d", &N);
    int *arr = (int*)malloc(N*sizeof(int));
    for (int i = 0; i < N; i++){
       scanf("%d", &arr[i]);
    }

    struct Node* root = buattree(arr, 0, N);

    printf("PRE ");
    preorder(root);
    printf("\n");
    printf("IN ");
    inorder(root);
    printf("\n");
    printf("POST ");
    postorder(root);
    printf("\n");

    return 0;
}

/** Referensi
* https://www.scribd.com/document/993874669/Binary-Tree-From-Array-C-Program
* https://www.geeksforgeeks.org/c/preorder-tree-traversal-of-binary-tree-in-c/
*/
