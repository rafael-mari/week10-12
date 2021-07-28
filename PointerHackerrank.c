#include <stdio.h>

void update(int *a,int *b) {
    int m = *a;
    int n= *b;  
    int sum = m+n; //The variable sum is equal to the sum of the 2 integers entered by the user
    int diff = m-n; //The diff sum is equal to the difference between the 2 integers entered by the user
    if(diff < 0){ //We need the absolute value of the difference so if the difference is less than 0 multiply it by -1
        diff=diff*-1;
    }
    *a=sum;
    *b=diff;
}

int main() {
    int a, b;
    int *sum = &a, *diff = &b;
    
    scanf("%d %d", &a, &b); //read the integers entered
    update(sum, diff); //update to the new values
    printf("%d\n%d", a, b); //print the result of both operations

    return 0;
}
