#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*###### 문자열 입력 받기, 커서 움직이기, double linkedList 
            stack, 덱 등 박스 두 개 사용하기 ######*/

typedef struct node {
    char data;
    struct node* next;
    struct node* prev;
}node;

void print(node* n) {
    node* temp = n;
    temp = temp->next;
    while (temp) {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node* head = (node*)malloc(sizeof(node));
    head->data = '!';
    head->prev = head->next = NULL;
    node* cur = head;
    char t;
    while ((t = getchar()) != '\n') {
        node* newnode = (node*)malloc(sizeof(node));
        newnode->data = t;
        newnode->prev = cur;
        newnode->next = NULL;
        cur->next = newnode;
        cur = newnode;
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char c;
        scanf(" %c", &c);
        switch (c) {
        case 'L': {
            if (cur->prev) cur = cur->prev;
            break;
        }case 'D': {
            if (cur->next) cur = cur->next;
            break;
        }case 'B': {
            if (cur->prev == NULL) continue;
            node* del = (node*)malloc(sizeof(node));
            del = cur;
            cur = del->prev;
            if (del->next) {
                cur->next = del->next;
                del->next->prev = cur;
                del->prev = NULL;
            }
            else { cur->next = NULL; }
            free(del);
            break;
        }case 'P': {
            char tmp;
            scanf(" %c", &tmp);
            node* newnode = (node*)malloc(sizeof(node));
            newnode->data = tmp;
            newnode->prev = cur;
            if (cur->next) {
                newnode->next = cur->next;
                cur->next->prev = newnode;
            }
            else {
                newnode->next = NULL;
            }
            cur->next = newnode;
            cur = cur->next;
            break;
        }
        }
    }
    head = head->next;
    while (head) {
        printf("%c", head->data);
        head = head->next;
    }

}