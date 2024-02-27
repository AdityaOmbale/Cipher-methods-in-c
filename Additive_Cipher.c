#include <stdio.h>
#include <ctype.h>

// Function to encrypt a character based on its type (lowercase, uppercase, or digit)
void encryptCharacter(char text[], int key) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];
        if (isalnum(ch)) {
            // Lowercase
            if (islower(ch)) {
                ch = (ch - 'a' + key%26 ) % 26 + 'a';
            }
            // Uppercase
            if (isupper(ch)) {
                ch = (ch - 'A' + key%26 ) % 26 + 'A';
            }
            // Numbers.
            if (isdigit(ch)) {
                ch = (ch - '0' + key%26 ) % 10 + '0';
            }
        } else if (ch == ' ') {
            // Skip spaces without encryption.
            continue;
        } else {
            printf("Invalid Message");
            return; // Exit the function in case of an invalid
        }
        // Update the character in the original string.
        text[i] = ch;
    }
}

// Function to decrypt a character based on its type (lowercase, uppercase, or digit)
char decryptChar(char ch, int key) {
    if (islower(ch)) {
        return (ch - 'a' - key%26 + 26) % 26 + 'a';
    } else if (isupper(ch)) {
        return (ch - 'A' - key%26  + 26) % 26 + 'A';
    } else if (isdigit(ch)) {
        return (ch - '0' - key%26 + 10) % 10 + '0';
    } else {
        // Invalid characters.
        printf("Invalid Message");
        return ch;
    }
}

// Function to decrypt the entire string
void decryptString(char text[], int key) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] != ' ') {  // Skip spaces without decryption.
            text[i] = decryptChar(text[i], key);
        }
    }
}

int main() {
    char text[500], innerChoice;
    int choice,key; 

    printf("SUBSTITUTION CIPHER\n");
    printf("1. CAESAR CIPHER\n");
    printf("Enter a choice (1): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("1. CAESAR CIPHER.\n");

            printf("e. For Encryption.\n");
            printf("d. For Decryption.\n");

            // Condition for case 1
             printf("Enter inner choice for case 1 (e or d): ");
            scanf(" %c", &innerChoice);

            switch (innerChoice) {
                case 'e':
                    
                        // Taking user input for encryption.
                    printf("Enter a message to encrypt: ");
                    scanf(" %[^\n]s", text); // Allowing spaces between words.

                    printf("Enter the key for encryption: ");
                    scanf("%d", &key);

                    // Encrypting the entire string using the function.
                     encryptCharacter(text, key);

                     printf("Encrypted message: %s\n", text);
                     
                    break;
                case 'd':
                   
                    // Taking user input for decryption.
                    printf("\nEnter a message to decrypt: ");
                    scanf(" %[^\n]s", text); // Allowing spaces between words.

                    printf("Enter the key for decryption: ");
                    scanf("%d", &key);
    
                    // Decrypting the entire string using the function.
                    decryptString(text, key);

                    printf("Decrypted message: %s", text);
                    break;
                    default:
                    printf("Invalid inner choice for case 1\n");
                    break;
            }
            break;

        case 2:
            printf("2. MULTIPLICATIVE CIPHER\n");

            break;

        case 3:
            printf("3. AFFINE CIPHER\n");

            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
