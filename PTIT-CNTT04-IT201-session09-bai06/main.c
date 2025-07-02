#include <stdio.h>
#include <stdlib.h>

//cau truc
struct Node {
    int data;
    struct Node *next;
};
//ham tao
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation error");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}
struct Node* createLinkedList(int size) {
    struct Node* head =  NULL;
    struct Node* current = NULL;
    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < size; i++) {
        int data;
        printf("%d: ",i+1);
        scanf("%d", &data);
        struct Node* node = createNode(data);
        if (head == NULL) {
            head = node;
            current = node;
        } else {
                current->next = node;
            current = current->next;
        }
    }
    return head;
}
//xoa
struct Node* deleteNode(struct Node* head) {
    if (head == NULL) {
        return head;
    }
    struct Node* current = head;
    head = head->next;
    return head;
}
//in
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    int count = 1;
    printf("Linked List:\n");
    while (current != NULL) {
        printf("%d ", current->data);
        if (current->next == NULL) {
            printf("\n");
        }
        current = current->next;
        count++;

    }
    printf("\n");
}
int main(void) {
    int n=0;
    while (n<=0) {
        printf("Please input a number:");
        scanf("%d", &n);
        if (n<=0) {
            printf("Nhap lai\n");
        }
    }
    struct Node* head = createLinkedList(n);
    head = deleteNode(head);
    printLinkedList(head);
    return 0;
}