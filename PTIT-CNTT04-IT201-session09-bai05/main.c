#include <stdio.h>
#include <stdlib.h>

//cau truc
struct Node {
    int data;
    struct Node *next;
};
//ham tao Node
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
//ham tao lien ket vs nhap ptu
struct Node* createLinkedList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    printf("Enter the number of nodes you want to add: \n");
    for (int i = 0; i < n; i++) {
        int data;
        printf("%d: ",i+1);
        scanf("%d", &data);
        struct Node* node = createNode(data);
        if (head == NULL) {
            head = node;
            temp = node;
        }
        else {
            temp->next = node;
            temp = temp->next;
        }
    }
    return head;

}
//them dau mang
struct Node* addNodes(struct Node* head, int n) {
    struct Node* newNode = createNode(n);
    newNode->next = head;
    head = newNode;
    return head;
}

//in
void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    int count = 1;
    while (temp != NULL) {
        printf("%d ", temp->data);
        if (temp->next == NULL) {
            printf("\n");
        }
        temp = temp->next;
        count++;
    }

    printf("\n");

}
int main(void) {
    int n=0;
    while (n<=0) {
        printf("Please enter a number: ");
        scanf("%d", &n);
        if (n<=0) {
            printf("Nhap lai \n");

        }
    }
    struct Node* head = createLinkedList(n);
    int newdata;
    printf("Enter the number to add: ");
    scanf("%d", &newdata);
    head = addNodes(head, newdata);
    printLinkedList(head);
    return 0;
}