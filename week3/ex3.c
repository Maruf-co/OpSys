#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void print_list(Node* n){
    while (n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

void insert_node(struct Node** head_ref, int new_data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void delete_node(struct Node** head_ref, int key){
    Node *temp = *head_ref;
    Node *prev;
    if (temp != NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;

    prev->next = temp->next;

    free(temp);
}

int main(){
    Node* head = NULL;


    insert_node(&head, 12);
    insert_node(&head, 4);
    insert_node(&head, 1);
    insert_node(&head, 5);
    insert_node(&head, 3);
    insert_node(&head, 7);
    insert_node(&head, 11);
    insert_node(&head, 2);
    insert_node(&head, 6);
    insert_node(&head, 10);
    insert_node(&head, 9);
    insert_node(&head, 8);

    print_list(head);

    delete_node(&head, 8);
    delete_node(&head, 12);
    delete_node(&head, 5);

    print_list(head);

}
