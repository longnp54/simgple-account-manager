#include <stdio.h>
#include <stdlib.h>
#include "account.h"
#include "menu.h"
#define _CRT_SECURE_NO_WARNINGS
int main() {
    int choice;
    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        handleMenuChoice(choice);
    }
    return 0;
}
