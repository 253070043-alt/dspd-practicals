#include <stdio.h>
#include<stdlib.h>
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;
void display() {
int i;
if (front == -1 || front > rear) {
printf("Queue is empty.\n");
return;
}
printf("Queue elements: ");
 for (i = front; i <= rear; i++) {
 printf("%d ", queue[i]);
}
printf("\n");
}
void enqueue(int value) {
if (rear == MAX - 1) {
printf("Queue Overflow! Cannot insert %d\n", value);
return;
}
if (front == -1)
front = 0;
rear++;
queue[rear] = value;
printf("%d enqueued to the queue.\n", value);
display();
}
void dequeue() {
if (front == -1 || front > rear) {
printf("Queue Underflow! No elements to dequeue.\n");
 return;
}
printf("%d dequeued from the queue.\n", queue[front]);
front++;
if (front > rear) {
front = rear = -1;
 }
}
void status() {
if (front == -1 || front > rear) {
printf("Queue isEmpty! No elements to dequeue.\n");
 return;
}else if (rear == MAX - 1) {
printf("Queue isFull! Cannot insert %d\n");
return;
}else{
printf("queue has space");
}
}
int main() {
 int choice, value;
while (1) {
printf("\nMenu:\n");
printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Status\n5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch(choice) {
case 1:
printf("Enter value to enqueue: ");
scanf("%d", &value);
enqueue(value);
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
status();
break;
case 5:
printf("Exiting program.\n");
return 0;
default:
printf("Invalid choice! Try again.\n");
}
}
return 0;
}
