#include <iostream> 
#include <vector> 

using namespace std;

/*######## VLR LVR RVL 노드 처리하는 방법 #########*/

struct node {
    char data;
    struct node* left_child, * right_child;
};
typedef struct node* tree_pointer;

tree_pointer create_tree_node(char data);
void recursive_inorder(tree_pointer ptr);
void recursive_preorder(tree_pointer ptr);
void recursive_postorder(tree_pointer ptr);


// 노드를 만들기
tree_pointer create_tree_node(char data) {
    tree_pointer ptr = (tree_pointer)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->left_child = NULL;
    ptr->right_child = NULL;
    return ptr;
}

void main() {

    tree_pointer root;

    int N;
    
    cin >> N;

    tree_pointer ptr, ptr1, ptr2;

    for (int i = 0; i < N; i++) {
    
        char a, b, c;
        cin >> a >> b >> c;

        ptr = create_tree_node(a);
        ptr1 = create_tree_node(b);
        ptr2 = create_tree_node(c);

        ptr->left_child = ptr1;
        ptr->right_child = ptr2;

        if (i == 0) {
            root = ptr;
        }
    }

    recursive_preorder(root);
    recursive_inorder(root);
    recursive_postorder(root);


}

// 14_Trees pg 27 - 29
void recursive_inorder(tree_pointer ptr) { // 재귀함수를 사용해 LVR 출력 
    if (ptr->data == '.')
        return;
    if (ptr) {
        recursive_inorder(ptr->left_child);
        printf("%c ", ptr->data);
        recursive_inorder(ptr->right_child);
    }
}
void recursive_preorder(tree_pointer ptr) { // 재귀함수를 사용해  VLR 출력
    if (ptr->data == '.')
        return;
    if (ptr) {
        printf("%c ", ptr->data);
        recursive_preorder(ptr->left_child);
        recursive_preorder(ptr->right_child);
    }
}
void recursive_postorder(tree_pointer ptr) { // 재귀함수를 사용해  LRV 출력
    if (ptr->data == '.')
        return;
    if (ptr) {
        recursive_postorder(ptr->left_child);
        recursive_postorder(ptr->right_child);
        printf("%c ", ptr->data);
    }
}
