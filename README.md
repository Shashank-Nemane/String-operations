Problem statement: 

Develop a program to implement following operations on string (without
using built in functions, write user defined functions):
∙ Comparison of two strings
∙ Copy of one string into another
∙ Finding the length of the string
∙ Concatenating two strings into one

Research: 

Links:
https://www.geeksforgeeks.org/c/string-functions-in-c/


What is a string?
A string is an array of characters terminated by a special character '\0' (null character). This null character marks the end of the string and is essential for proper string manipulation.

Operations on string using built in functions is easier ,as there is a string.h header file which contains multiple functions such as :

strlen()
The strlen() function is used to find the length of a string. It returns the number of characters in a string, excluding the null terminator ('\0').

strcpy()
The strcpy() function copies a string from the source to the destination. It copies the entire string, including the null terminator.
strcat()
The strcat() function is used to concatenate (append) one string to the end of another. It appends the source string to the destination string, replacing the null terminator of the destination with the source string’s content.


strcmp()

It is a built-in function used to copy one string into another.


Analysis:

For performing string operations without using in built functions and string.h header file is more complex and time consuming.
For each function mentioned above we would need to create a user defined function with logic of those functions.
For comparing two strings instead of strcmp() we would need to compare each character of string manually using loops, and use while for checking if the string ended.

Comparing strings:

For comparing two strings instead of strcmp() we would need to compare each character of string manually using loops, and use while for checking if the string ended.

Copying strings:

For copying strings, we would use a while loop and put the condition as not null.
Then pass the character of the source string into the destination string, increasing ‘i’ counter to every character passed.

String length:

Here we increase the ‘i’ counter till the source string is null.
Therefore checking each character till the string ends.

String concate:

Here we check the length of the destination string by increasing the ‘i’ counter till the string is null.Then we copy the characters of source string in destination strings index which is after its own length, till the source string is null.

Ideate:
A simple login system can be built for a game where players create an account with a restricted username and a secure password. The username must follow limits such as 3–12 characters and only alphanumeric characters, and once entered, the system automatically concatenates the game name (e.g., “MythRiders”) with the username before storing it, forming a final ID like MythRiders_username. 
During signup, the password is checked for length (6–16 characters)  
For login, the user enters the same username and password, the game name is attached again for comparison, and the system verifies whether the stored  password matches, allowing access only when the credentials are the same.




BUILT:

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
            return 0;
        i++;
    }
    return 1;
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

   if (!stringcompare(password, confirm)) {
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





TEST:

Case 1:Correct input

Welcome to COD Mobile
1. Create Account
2. Exit
Choose: 1

Enter username (3–12 alphabets only): Shashank
Enter password:(6-16 characters only Shanks
Confirm password: Shanks

Account Created:
Username: COD_Shashank
Password: Shanks

Case 2: Invalid input
Welcome to COD Mobile
1. Create Account
2. Exit
Choose: 1

Enter username (3–12 alphabets only): vbfgjghdghdghsfgjhfgjh
Invalid username length.

Enter username (3–12 alphabets only): Shashank
Enter password (6–16 characters): hfdjjggjgjjjdjjgjgjjgjjgjjgjjg
Password must be 6-16 characters long.
Enter password (6–16 characters): Shanks
Confirm password: Shanks

Account Created Successfully!
Username: COD_Shashank
Password: Shanks

