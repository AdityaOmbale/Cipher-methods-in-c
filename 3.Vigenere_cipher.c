#include <stdio.h>
#include <ctype.h>
#include <string.h>

void vigenereCipher(char*text, char *key, int mode) {
    int textLength = strlen(text);
    int keyLength = strlen(key);

    for (int i = 0, j = 0; i < textLength; ++i) {
        if (isalpha(text[i])) {//if plain text ia alphabetic
            int offset = isupper(text[i]) ? 'A' : 'a';// ternary operator
            int keyIndex = tolower(key[j % keyLength]) - 'a';//index representing position of key
            int shift = (mode == 0) ? keyIndex : 26 - keyIndex;// 0=encrypt & 1=decrypt
            text[i] = (text[i] - offset + shift) % 26 + offset;//main encryption or decryption done here!
            ++j;
        }
    }
}

int main() {
    char text[1000];
    char key[100];
    int choice;
    printf("Vigenere Polyalphabetic Cipher");
    printf("\nEnter Plaintext (for encrypt or decrypt): ");
    fgets(text, sizeof(text), stdin);
    //Reads a line of text from standard input, storing it in the "text" variable.
    
    printf("Enter key: ");
    scanf("%s", key);

    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Choose operation:");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            vigenereCipher(text, key, 0); 
            printf("Encrypted text: %s\n", text);//Encrypted text
            break;
        case 2:
            vigenereCipher(text, key, 1); 
            printf("Decrypted text: %s\n", text);//Decrypted text
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
