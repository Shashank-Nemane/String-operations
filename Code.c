#include <stdio.h>

#define GAME "COD_"

int Length(char s[]) {
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void stringcopy(char d[], char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        d[i] = s[i];
        i++;
    }
    d[i] = '\0';
}

void stringconcat(char d[], char s[]) {
    int i = 0, j = 0;
    while (d[i] != '\0') i++;
    while (s[j] != '\0') d[i++] = s[j++];
    d[i] = '\0';
}

int stringcompare(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' || b[i] != '\0') {
        if (a[i] != b[i])
            return 1;
        i++;
    }
    return 0;
}

void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void createaccount() {

    char username[50];
    char final_username[50];
    char password[50];
    char confirm[50];

username_again:

    printf("\nEnter username (3–12 alphabets only): ");
    fgets(username, sizeof(username), stdin);

    int u = Length(username);

    if (username[u - 1] == '\n') {
        username[u - 1] = '\0';
        u--;
    } else {
        clearBuffer();  
    }

    if (u < 3 || u > 12) {
        printf("Invalid username length.\n");
        goto username_again;
    }

password_again:

    printf("Enter password (6–16 characters): ");
    fgets(password, sizeof(password), stdin);

    int p = Length(password);

    if (password[p - 1] == '\n') {
        password[p - 1] = '\0';
        p--;
    }

    if (p < 6 || p > 16) {
        printf("Password must be 6-16 characters long.\n");
        goto password_again;
    }

    printf("Confirm password: ");
    fgets(confirm, sizeof(confirm), stdin);

    int c = Length(confirm);

    if (confirm[c - 1] == '\n') {
        confirm[c - 1] = '\0';
        c--;
    }

    if (stringcompare(password, confirm)) {
        printf("Passwords do not match.\n");
        goto password_again;
    }

    stringcopy(final_username, GAME);
    stringconcat(final_username, username);

    printf("\nAccount Created Successfully!\n");
    printf("Username: %s\n", final_username);
    printf("Password: %s\n", password);
}

int main() {

    int choice;

    printf("Welcome to COD Mobile");

start:

    printf("\n1. Create Account\n2. Exit\nChoose: ");
    scanf("%d", &choice);

    clearBuffer(); 

    switch (choice) {
        case 1:
            createaccount();
            break;

        case 2:
     printf("Thank you for visiting us!");
            return 0;

        default:
            printf("Invalid option.\n");
            goto start;
    }
}

