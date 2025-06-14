#include <stdio.h>
#include <stdlib.h>
#include "account.h"
#include "menu.h"
#define _CRT_SECURE_NO_WARNINGS
// Khai báo hàm callback
void displayAccountCallback(Account* account);

// Khai báo các hàm xử lý
void addAccountHandler();
void deleteAccountHandler();
void updateAccountHandler();
void searchAccountHandler();
void displayAccountsHandler();

void showMenu() {
    printf("1. Add Account\n");
    printf("2. Delete Account\n");
    printf("3. Update Account\n");
    printf("4. Search Account\n");
    printf("5. Display Accounts\n");
    printf("6. Exit\n");
}

void handleMenuChoice(int choice) {
    // Khai báo mảng con trỏ hàm
    MenuFunction menuFunctions[] = {
        addAccountHandler,
        deleteAccountHandler,
        updateAccountHandler,
        searchAccountHandler,
        displayAccountsHandler
    };

    if (choice >= 1 && choice <= 5) {
        menuFunctions[choice - 1]();
    }
    else if (choice == 6) {
        exit(0);
    }
    else {
        printf("Invalid choice!\n");
    }
}

void addAccountHandler() {
    char service[50], username[50], password[50];
    printf("Enter service: ");
    scanf("%s", service);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    addAccount(service, username, password);
}

void deleteAccountHandler() {
    char service[50];
    printf("Enter service to delete: ");
    scanf("%s ", service);
    deleteAccount(service);
}

void updateAccountHandler() {
    char service[50], username[50], password[50];
    printf("Enter service to update: ");
    scanf("%s", service);
    printf("Enter new username: ");
    scanf("%s", username);
    printf("Enter new password: ");
    scanf("%s", password);
    updateAccount(service, username, password);
}

void searchAccountHandler() {
    char service[50];
    Account* account;
    printf("Enter service to search: ");
    scanf("%s", service);
    account = searchAccount(service);
    if (account != NULL) {
        printf("Service: %s, Username: %s, Password: %s\n", account->service, account->username, account->password);
    }
    else {
        printf("Account for service %s not found.\n", service);
    }
}

void displayAccountsHandler() {
    forEachAccount(displayAccountCallback);
}

void displayAccountCallback(Account* account) {
    printf("Service: %s, Username: %s, Password: %s\n", account->service, account->username, account->password);
}
