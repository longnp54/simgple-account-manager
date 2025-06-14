#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct Account {
    char service[50];
    char username[50];
    char password[50];
    struct Account* next;
    struct Account* prev;
} Account;

typedef void (*AccountCallback)(Account*);
typedef void (*MenuFunction)();

void addAccount(char* service, char* username, char* password);
void deleteAccount(char* service);
void updateAccount(char* service, char* newUsername, char* newPassword);
Account* searchAccount(char* service);
void displayAccounts();
void forEachAccount(AccountCallback callback);

#endif // ACCOUNT_H

