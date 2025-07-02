#include <stdio.h>
#include <stdlib.h>

//cau truc node
struct Node {
    int data;
    struct Node *next;

};
//ham tao node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation error");
        exit(-1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}
//ham node lien ket va nhap vao
struct Node* createLinkedList(int size) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < size; i++) {
        int data;
        printf(" %d-th node:", i + 1);
        scanf("%d", &data);
        struct Node* node = createNode(data);
        if (head == NULL) {
            head = node;
            temp = node;

        }
        else {
            temp->next = node;
            temp = node;
        }


    }
    return head;
}
//ham tinh do dai
int getlength(struct Node* head) {
    int length = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;

    }
    return length;
}
int main(void) {
    int n=0;
    while (n<=0) {
        printf("Please enter a number: ");
        scanf("%d", &n);
        if (n<=0) {
            printf("Nhap lai\n");
        }
    }
    struct Node* head = createLinkedList(n);
    int length = getlength(head);
    printf("The linked lenghth id: %d\n",length);
    return 0;
}