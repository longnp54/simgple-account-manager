# Password Manager

A simple command-line password manager application built in C that demonstrates advanced C programming concepts including pointer manipulation, function pointers, callbacks, and data structures.

## Overview

This application allows users to store, retrieve, update, and delete account credentials (service name, username, and password) using a doubly-linked list data structure. The project demonstrates core C programming concepts and serves as a learning tool for understanding advanced C techniques.

## Features

- Add new account credentials
- Delete existing accounts
- Update username and password for existing accounts
- Search for accounts by service name
- Display all stored accounts

## Usage Guide

### Building and Running

This project can be built using Visual Studio or any C compiler:

```bash
# Using GCC
gcc main.c menu.c account.c -o password_manager

# Run the application
./password_manager
```

### Menu Options

After launching the application, you'll see a menu with the following options:

1. **Add Account** - Store new service credentials
   - Enter the service name, username, and password when prompted

2. **Delete Account** - Remove existing credentials
   - Enter the service name of the account you want to delete

3. **Update Account** - Change username/password for a service
   - Enter the service name and then provide the new username and password

4. **Search Account** - Find credentials by service name
   - Enter the service name to display its associated username and password

5. **Display Accounts** - Show all stored credentials
   - Lists all accounts currently stored in memory

6. **Exit** - Terminate the application

### User Flow

1. When launched, the application displays the menu of available options
2. Select an option by entering the corresponding number (1-6)
3. Follow the prompts to provide necessary information
4. After completing an action, the menu is displayed again for the next operation
5. To exit the application, select option 6

## Functionality Description

The password manager provides a simple command-line interface for managing your account credentials:

### Account Management
- **Adding Accounts**: Users can store credentials for different services by providing the service name, username, and password.
- **Deleting Accounts**: Remove stored credentials by specifying the service name.
- **Updating Accounts**: Change the username and password for an existing service.
- **Searching**: Look up credentials by entering the service name.
- **Displaying All Accounts**: List all stored credentials in the current session.

All data is stored in memory using a doubly-linked list structure, allowing for efficient insertion, deletion, and traversal operations.

## Project Structure

- `main.c` - Entry point with the main loop
- `menu.c` - Menu handling and user interaction
- `menu.h` - Menu function declarations
- `account.c` - Account management implementation
- `account.h` - Account structures and function declarations

## Technical Implementation

### Core Data Structure

The password manager uses a doubly-linked list to store account information:

```c
typedef struct Account {
    char service[50];
    char username[50];
    char password[50];
    struct Account* next;
    struct Account* prev;
} Account;
```

### Advanced C Concepts Demonstrated

#### 1. Function Pointers and Callbacks

The project uses function pointers for menu handling and callback functions for account operations:

```c
typedef void (*AccountCallback)(Account*);
typedef void (*MenuFunction)();

// Function pointer array for menu options
MenuFunction menuFunctions[] = {
    addAccountHandler,
    deleteAccountHandler,
    updateAccountHandler,
    searchAccountHandler,
    displayAccountsHandler
};
```

#### 2. Pointer Manipulation

Extensive use of pointers for managing the linked list:

```c
void addAccount(char* service, char* username, char* password) {
    Account* newAccount = (Account*)malloc(sizeof(Account));
    // ... pointer manipulation for linked list insertion
}
```

#### 3. Memory Management

Dynamic memory allocation and proper cleanup:

```c
// Allocation
Account* newAccount = (Account*)malloc(sizeof(Account));

// Deallocation
free(temp);
```

#### 4. Generic Iteration with Callbacks

The `forEachAccount` function demonstrates the callback pattern:

```c
void forEachAccount(AccountCallback callback) {
    Account* temp = head;
    while (temp != NULL) {
        callback(temp);
        temp = temp->next;
    }
}
```

## Educational Value

This project serves as a practical example for learning:

- Data structures implementation in C
- Pointer manipulation and memory management
- Function pointers and callback mechanisms
- Modular code organization with header files
- Command-line interface design

## Limitations

- No password encryption (educational purposes only)
- In-memory storage (data is lost when the program exits)
- No input validation

## Future Improvements

- Add password encryption
- Implement file persistence
- Add input validation and error handling
- Enhance the user interface

## License

Feel free to use and modify this code for educational purposes.