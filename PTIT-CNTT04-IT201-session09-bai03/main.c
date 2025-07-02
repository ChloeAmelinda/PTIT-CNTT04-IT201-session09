#include <stdio.h>
#include <stdlib.h>

//cau truc node
struct Node {
    int data;
    struct Node *next;
};
//ham tao Node
struct Noxde* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation error");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}
//ham tao node vs 5 lien ket nhap vao
struct Node* createLinkedList() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    printf("Nhap 5 ptu cho danh sach lien ket:\n");
    for (int i = 0; i < 5; i++) {
        int data;
        printf("Nhap phan tu thu %d: ",i+1);
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
//tim kiem
int searchLinked(struct Node* head, int x) {
    struct Node* temp = head;
    int position  =1;
    while (temp != NULL) {
        if (temp->data == x) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;

}
int main(void) {
    struct Node* head = createLinkedList();
    int search = 0;
    while (search <=0 ) {
        printf("Nhap so nguyen duong bat ki :");
        scanf("%d", &search);
        if (search < 0 ) {
            printf("nhap lai \n");
        }
    }
    int result = searchLinked(head, search);
    if (result != -1) {
        printf("true\n");
    }else {
        printf("false\n");
    }

    return 0;
}