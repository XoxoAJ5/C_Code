#include <stdio.h>
/*Structure for the items in vending machine*/
typedef struct {
    char name[10];
    float price;
    int stock;
} Item;

void retbalance();

int main() {
    float balance = 5.00;

    /*initialized the items in the vending machines*/
    Item machines[3] = {
        {"Cola", 1.50, 5},
        {"Chips", 3.2, 7},
        {"water", 1.00, 4}
    };

    
    while (1) {
        retbalance();

    }
    return 0;
}

void retbalance() {
/*For loop that goes through each of the items in the vending machine and prints it out*/
    for (int i = 0; i < 3; i++){
        printf("%s, %.2f, %d\n", machines[i].name, machines[i].price, machines[i].stock);
    };
}