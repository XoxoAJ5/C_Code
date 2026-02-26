#include <stdio.h>

int main(){
    int count;
    printf("please enter a positive integer: ");
    scanf("%d", &count);
    printf("\n");
    while (count < 10) {
        if (count % 2 == 0){
            count ++ ;
        } else {
            printf("your number is %d\n", count);
            count ++ ;
        }
    }
    return 0;
}
