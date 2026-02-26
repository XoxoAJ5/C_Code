#include <stdio.h>
#include <windows.h>

typedef struct {
    char name[10];
    float cost;
} vendingitem;

int main() {
    float balance = 0.00;
    vendingitem list[3] = {{"Item A", 1.50}, {"Item B", 2.50}, {"Item C", 3.50}};
    int inp;
    while(1) {
        printf("Items in vending Machine:\n");
        printf("%s\n%s\n%s\n", list[0].name, list[1].name, list[2].name);
        Sleep(2);
        printf("What do you want to do?\ntype in 1 to quit, 2 to insert a quarter, 3 to insert a dollar, any other character to continue\n");
        scanf("%d", &inp);
        printf("\n");
        if (inp == 1){
            break;
        } else if (inp == 2){
            balance += 0.25;
            printf("Your current balance is %.2f\n", balance);
        } else if (inp == 3){
            balance += 1.00;
            printf("Your current balance is %.2f\n", balance);
        } else {
            printf("What item would you like to buy?\nPress 1 for item 1, 2 for item 2, 3 for item 3\n");
            int inp2;
            scanf("%d", &inp2);
            printf("\n");
            switch (inp2) {
                case 1:
                    balance -= list[0].cost;
                    if (balance >= 0) {
                        printf("Dispensing...");
                        printf("Bought item 1\n");
                        printf("Current Balance: %.2f\n", balance);
                        printf("\n");
                    } else {
                        balance += list[0].cost;
                        printf("Error\n");
                        printf("%.2f\n", balance);
                        printf("\n");
                    } break;
                case 2:
                    balance -= list[1].cost;
                    if (balance >= 0) {
                        printf("Dispensing...\n");
                        printf("Bought item 2\n");
                        printf("Current Balance: %.2f\n", balance);
                        printf("\n");
                    } else {
                        balance += list[1].cost;
                        printf("Error\n");
                        printf("%.2f\n", balance);
                        printf("\n");
                    } break;
                case 3:
                    balance -= list[2].cost;
                    if (balance >= 0) {
                        printf("Dispensing...\n");
                        printf("Bought item 3\n");
                        printf("Current Balance: %.2f\n", balance);
                        printf("\n");
                    } else {
                        balance += list[2].cost;
                        printf("Error\n");
                        printf("%.2f\n", balance);
                        printf("\n");
                    } break;
                }
            }
        }
    return 0;
}