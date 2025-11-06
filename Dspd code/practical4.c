#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int main() {
    struct Node *head = NULL, *temp, *newNode;
    int value, count = 0;
    while (1) {
        printf("Enter an element (0 to stop): ");
        scanf("%d", &value);
        if (value == 0)
            break;
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        count++;
        if (temp->next != NULL)
            printf(" => ");
        temp = temp->next;
    }
    printf("\nNumber of nodes: %d\n", count);
    return 0;
}
