#include <stdio.h>
int main() {
int n,i,even_sum=0,odd_sum=0;
printf("Enter number of elements: ");
scanf("%d",&n);
int arr[n];
for(i=0;i<n;i++) {
printf("Enter element %d: ",i+1);
scanf("%d",&arr[i]);
}
for(i=0;i<n;i++) {
if(i%2==0)
even_sum+=arr[i];
else
odd_sum+=arr[i];
}
printf("Sum of elements at even positions: %d\n",even_sum);
printf("Sum of elements at odd positions: %d\n",odd_sum);
return 0;
}
