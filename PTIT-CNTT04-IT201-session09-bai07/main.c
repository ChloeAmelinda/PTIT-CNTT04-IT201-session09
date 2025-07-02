#include <stdio.h>
#include <stdlib.h>

//cau truc
struct Node {
    int data;
    struct Node *next;
};
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
struct Node* createList(int size) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    printf("Enter the elements of the list\n");
    for (int i = 0; i < size; i++) {
        int data;
        printf("%d:",i+1);
        scanf("%d",&data);
        struct Node* node = createNode(data);
        if (head == NULL) {
            head = node;
            temp = node;
        }else {
            temp->next = node;
            temp = node;
        }
    }
    return head;

}
//them
struct Node* add(struct  Node* head,int data,int pos) {
    if (pos ==1) {
        struct Node* temp = createNode(data);
        temp->next = head;
        head = temp;
        return head;
    }
    struct Node* current = head;
    struct Node* prev = NULL;
    int currentPos = 1;
    while (current != NULL && currentPos< pos) {
        prev = current;
        current = current->next;
        currentPos++;
    }
    struct Node* newNode = createNode(data);
    if (prev != NULL) {
        prev->next = newNode;
        newNode->next = current;
    }else {
        newNode->next = current;
        head = newNode;

    }
    return head;
}
//in
void printList(struct Node* head) {
    struct Node* temp = head;
    int position=1;
    printf("The elements of the list are:\n");
    if (head != NULL) {
        while (temp != NULL) {
            printf("%d ",temp->data);
            if (temp->next != NULL) {
                printf(", ");
            }
            temp = temp->next;

        }
        printf("\n");
    }else {
        printf("NULL");
    }
}
int main(void) {
    int n=0;
    while (n<=0) {
        printf("Please input a number:");
        scanf("%d", &n);
        if (n<=0) {
            printf("Nhap lai");


        }
    }
    struct Node* head = createList(n);
    int newdata,pos;
    printf("enter a number to add:");
    scanf("%d",&newdata);
    printf("Enter the position:");
    scanf("%d",&pos);

    head = add(head,newdata,pos);
    printList(head);
    printf("\n");
    return 0;
}