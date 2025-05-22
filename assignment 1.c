#include <stdio.h>
#include <stdlib.h>

struct Book {
    char title[100];
    char author[100];
    float price;
};

int main() {
    struct Book b;

    // Input book details
    printf("Enter book title: ");
    gets(b.title);  // ⚠️ Unsafe, for educational/demo purposes only

    printf("Enter author name: ");
    gets(b.author); // ⚠️ Unsafe, for educational/demo purposes only

    printf("Enter book price: ");
    scanf("%f", &b.price);

    // Write to file
    FILE *fptr = fopen("book1.txt", "w");
    if (fptr == NULL) return 1;
    fprintf(fptr, "%s\n%s\n%.2f\n", b.title, b.author, b.price);
    fclose(fptr);

    // Read from file
    struct Book rb;
    fptr = fopen("book1.txt", "r");
    fgets(rb.title, sizeof(rb.title), fptr);
    fgets(rb.author, sizeof(rb.author), fptr);
    fscanf(fptr, "%f", &rb.price);
    fclose(fptr);

    printf("\nTitle: %sAuthor: %sPrice: %.2f\n", rb.title, rb.author, rb.price);
    return 0;
}
