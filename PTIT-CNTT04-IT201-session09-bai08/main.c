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
//ham xoa
struct Node* deleteNode(struct Node* head, int pos) {
    if (head == NULL || pos <1) {
        return head;
    }
    if (pos ==1) {
        struct Node* temp = head;
        head = head->next;
        return head;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    int count = 1;
    while (temp != NULL && count< pos) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (prev != NULL && temp != NULL) {
        prev->next = temp->next;
    }
    return head;
}
//ham i
void printList(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty\n");
    }else {
        while (temp != NULL) {
            printf("%d ",temp->data);
            if (temp->next != NULL) {
                printf(", ");
            }
            temp = temp->next;
        }
        printf("\n");
    }
}
int main(void) {
    int n=0;
    while (n<=0) {
        printf("Please enter the number of nodes\n");
        scanf("%d",&n);
        if (n<=0) {
            printf("Please enter a valid number\n");
        }
    }
    struct Node* head = createList(n);
int pos;
    printf("Enter the position to be deleted\n");
    scanf("%d",&pos);
    head = deleteNode(head,pos);
    printList(head);
    return 0;
}