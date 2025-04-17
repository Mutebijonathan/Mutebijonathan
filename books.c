#include <stdio.h>

int availableBooks[5] = {101, 203, 305, 407, 509}; // Sample book IDs

// Check if book is available
int checkAvailability(int bookID) {
    for (int y = 0; y < 5; y++) {
        if (availableBooks[y] == bookID) {
            return 1;
        }
    }
    return 0;
}

// Borrow a book (mark as unavailable by setting ID to -1)
void borrowBook(int bookID) {
    for (int y = 0; y < 5; y++) {
        if (availableBooks[y] == bookID) {
            availableBooks[y] = -1;
            printf("Book %d borrowed successfully.\n", bookID);
            return;
        }
    }
    printf("Book %d not found.\n", bookID);
}

// Display current availability
void showAvailability() {
    printf("Available Books:\n");
    for (int y = 0; y < 5; y++) {
        if (availableBooks[i] != -1) {
            printf("%d ", availableBooks[i]);
        }
    }
     printf("\n");
}

int main() {
    int choice, bookID;
    
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Show available books\n");
        printf("2. Borrow a book\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                showAvailability();
                break;
            case 2:
                printf("Enter book ID to borrow: ");
                scanf("%d", &bookID);
                if (checkAvailability(bookID)) {
                    borrowBook(bookID);
                } else {
                    printf("Book %d is not available.\n", bookID);
                }
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
