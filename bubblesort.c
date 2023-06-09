#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
void swap(struct Node *a, struct Node *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
void bubbleSort(struct Node *head) {
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;
    if (head == NULL)
        return;
    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main() {
    struct Node *head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);

    printf("Linked List before sorting: ");
    printList(head);

    bubbleSort(head);

    printf("\nLinked List after sorting: ");
    printList(head);

    return 0;
}

//bubble_sort_brute_force_logic_2
