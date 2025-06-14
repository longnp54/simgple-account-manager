#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"
#define _CRT_SECURE_NO_WARNINGS
// Khởi tạo biến toàn cục head trong file .c
Account* head = NULL;

void addAccount(char* service, char* username, char* password) {
    Account* newAccount = (Account*)malloc(sizeof(Account));
    strcpy(newAccount->service, service);
    strcpy(newAccount->username, username);
    strcpy(newAccount->password, password);
    newAccount->next = head;
    newAccount->prev = NULL;
    if (head != NULL) {
        head->prev = newAccount;
    }
    head = newAccount;
}

void deleteAccount(char* service) {
    Account* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->service, service) == 0) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            }
            else {
                head = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
            printf("Account for service %s deleted.\n", service);
            return;
        }
        temp = temp->next;
    }
    printf("Account for service %s not found.\n", service);
}

void updateAccount(char* service, char* newUsername, char* newPassword) {
    Account* account = searchAccount(service);
    if (account != NULL) {
        strcpy(account->username, newUsername);
        strcpy(account->password, newPassword);
        printf("Account for service %s updated.\n", service);
    }
    else {
        printf("Account for service %s not found.\n", service);
    }
}

Account* searchAccount(char* service) {
    Account* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->service, service) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void displayAccounts() {
    Account* temp = head;
    while (temp != NULL) {
        printf("Service: %s, Username: %s, Password: %s\n", temp->service, temp->username, temp->password);
        temp = temp->next;
    }
}

void forEachAccount(AccountCallback callback) {
    Account* temp = head;
    while (temp != NULL) {
        callback(temp);
        temp = temp->next;
    }
}
