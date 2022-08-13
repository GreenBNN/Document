#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* leftChild;
    struct node* rightChild;
};
typedef struct node* treePointer;

void insertNode(treePointer* node, int k);
treePointer modifiedSearch(treePointer node, int k);
void inorder(treePointer ptr);

int main() {
    treePointer tree = NULL;

    int arr[9] = { 0 };
    int sum = 0;
    int temp = 0;
    int a, b;

    for (int i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }


    for (int i = 0; i < 9; i++) {
        for (int j = 8; j > i; j--) {
            temp = arr[i] + arr[j];
            if (sum - temp == 100) {
                a = i;
                b = j;
                break;
            }
        }
    }

    arr[a] = 0;
    arr[b] = 0;
    for (int i = 0; i < 9; i++) {
        if (arr[i] != 0) {
            insertNode(&tree, arr[i]);
        }
    }

    inorder(tree);

    return 0;
}

void inorder(treePointer ptr) {
    if (ptr) {
        inorder(ptr->leftChild);
        printf("%d\n", ptr->data);        
        inorder(ptr->rightChild);
    }
}

treePointer modifiedSearch(treePointer node, int k) {

    treePointer parent = NULL;
    while (node) {
        // if we found a node with key k, we return NULL
        if (k == node->data) return NULL;
        parent = node;
        if (k < node->data) node = node->leftChild;
        else node = node->rightChild;
    }
    return parent;
}

void insertNode(treePointer *node, int k) {
    treePointer ptr;
    treePointer temp = modifiedSearch(*node, k);
    if (temp || !(*node)) {
        // k is not in the tree
        ptr = (treePointer)malloc(sizeof(*ptr));
        ptr->data = k;
        ptr->leftChild = NULL;
        ptr->rightChild = NULL;
        if (*node) {
            if (k < temp->data) temp->leftChild = ptr;
            else temp->rightChild = ptr;
        }
        else *node = ptr;
    }
    else {
    }
}

