#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int stack[SIZE];
int top = -1;
int pop();
void display();
int peek();
void push(int value);
int isPalindrome();
int main() {
while (1) {
int choice, value;
printf("\nEnter value of your choice:\n");
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Display\n");
printf("4. Peek\n");
printf("5. Check Palindrome\n");
printf("6. Exit\n");
printf("Choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter value to push: ");
scanf("%d", &value);
push(value);
break;
case 2:
value = pop();
if (value != -1)
printf("Popped value: %d\n", value);
break;
case 3:
display();
break;
case 4:
value = peek();
if (value != -1)
printf("Top element: %d\n", value);
break;
case 5:
if (isPalindrome())
printf("Stack elements form a palindrome.\n");
else
printf("Stack elements do not form a palindrome.\n");
break;
case 6:
printf("Exiting program.\n");
exit(0);
default:
printf("Invalid choice! Try again.\n");
}
}
return 0;
}
void push(int value) {
if (top == SIZE - 1) {
printf("Stack Overflow!\n");
} else {
stack[++top] = value;
printf("%d pushed onto stack.\n", value);
}
}
int pop() {
if (top == -1) {
printf("Stack Underflow!\n");
return -1;
} else {
return stack[top--];
}
}
void display() {
int i = 0;
if (top == -1) {
printf("Stack is empty.\n");
} else {
printf("Stack elements: ");
for (i = 0; i <= top; i++) {
printf("%d ", stack[i]);
}
printf("\n");
}
}
int peek() {
if (top == -1) {
printf("Stack is empty.\n");
return -1;
} else {
return stack[top];
}
}
int isPalindrome() {
int i = 0;
int j = top;
while (i < j) {
if (stack[i] != stack[j])
return 0;
i++;
j--;
}
return 1;
}
