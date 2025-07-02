#include <stdio.h>
#include <stdlib.h>

//cau truc
struct Node {
    int data;
    struct Node *next;
};
//ham tao moi
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
//ham tao ds lien ket 5 phan tu
struct Node* create() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    printf("Nhap 5 ptu \n");
    for (int i = 0; i < 5; i++) {
        int data;
        printf("Nhap %d :",i+1);
        scanf("%d", &data);
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
//in
void display(struct Node* head) {
    struct Node* temp = head;
    int position = 1;
    printf("ds lien ket\n");
    while (temp != NULL) {
        printf("Node %d: %d ",position, temp->data);
        if (temp->next != NULL) {
            printf("\n ");
        }
        temp = temp->next;
        position++;
    }

}

int main(void) {
    struct Node* head = create();
    display(head);
    return 0;
}