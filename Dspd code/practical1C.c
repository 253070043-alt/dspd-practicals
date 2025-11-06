#include <stdio.h>
#include <string.h>
struct student {
int roll;
char name[50];
int age;
float avg_marks;
};
void swap(struct student s[], int i, int j) {
struct student temp;
temp = s[i];
s[i] = s[j];
s[j] = temp;
}
void sort(struct student s[], int n) {
int i, j;
for (i = 0; i < n - 1; i++) {
for (j = 0; j < n - i - 1; j++) {
if (s[j].avg_marks < s[j + 1].avg_marks) {
swap(s, j, j + 1);
}
}
}
}
int main() {
int n, i;
printf("Enter number of students: ");
scanf("%d", &n);
struct student s[100];
for (i = 0; i < n; i++) {
printf("Enter roll name age avg_marks for student %d:\n", i + 1);
scanf("%d %s %d %f", &s[i].roll, s[i].name, &s[i].age, &s[i].avg_marks);
}
sort(s, n);
printf("Sorted list:\n");
for (i = 0; i < n; i++) {
printf("%d %s %d %.2f\n", s[i].roll, s[i].name, s[i].age, s[i].avg_marks);
}
return 0;
}
