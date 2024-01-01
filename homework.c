#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void encrypt(char message[], int key) {
    int i;
    char ch;

    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = (ch + key - 'a' + 26) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch + key - 'A' + 26) % 26 + 'A';
        }

        message[i] = ch;
    }
}

void decrypt(char message[], int key) {
    // The decryption is the same as encryption, but with a negative key
    encrypt(message, -key);
}

int main() {
    char message[100];
    int key;
    int loop = 1;
    srand(time(NULL));
    key = rand() % 13 + 1;
while (loop)
{
    int option;
    printf("1 - encrypt\n2 - decrypt\n3 - exit \n >  ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
        encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    case 2:
     printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
     decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    case 3:
    loop = 0;
    break;
    default:
        printf("invalid input");
    }
}


    return 0;
}
