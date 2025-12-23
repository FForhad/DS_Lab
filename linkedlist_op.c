#include<stdio.h>

struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);
    insertAfter(head->; next, 5);
    printf("Linked list: ");
    printList(head);

    printf("\nAfter deleting an element: ");

    deleteNode(&head, 3);

    printList(head);

    int item_to_find = 3;
    if (searchNode(&head, item_to_find))
    {
        printf("\n%d is found", item_to_find);
    }
    else
    {
        printf("\n%d is not found", item_to_find);
    }
    sortLinkedList(&head);
    printf("\nSorted List: ");
    printList(head);
}
