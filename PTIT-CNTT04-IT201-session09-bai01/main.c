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
        return 1;
    }
    node->data = data;
    node->next = NULL;
return node;

}
//ham tao node lien ket vs 5 ptu nhap vao
struct Node* createLinkedList() {
    struct Node* head = NULL;
    struct Node* current  = NULL;
    printf("Nhap 5 phan tu cho danh sach lien ket:");
    for (int i = 0; i < 5; i++) {
        int data;
        printf("%d:",i+1);
        scanf("%d", &data);
        struct Node* node = createNode(data);
        if (head == NULL) {
            head = node;
            current = node;
        }else {
            current->next = node;
            current = node;
        }
    }
    return head;
}


int main(void) {
    struct Node* head = createLinkedList();


    return 0;
}