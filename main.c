#include <stdio.h>
#include <stdlib.h>


void dec_to_binary(int n) {
    int bits[32];
    int i = 0;

    if (n == 0){
        printf("0");
        return;
    }

    while (n > 0) {
        bits[i] = n % 2;
        n /= 2;
        i++;
    }

    

    // reverse array
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bits[j]);
    }
    printf("\n");


}

void dec_to_hexadecimal(int n) {
    char hex_digits[] = "0123456789ABCDEF";
    char hex[32];
    int i = 0;

    if (n == 0) {
        printf("0");
        return;
    }

    while (n > 0) {
        hex[i] = hex_digits[n % 16];
        n /= 16;
        i++;
    }

    for (int j = i -1; j >=  0; j--) {
        printf("%c", hex[j]);
    }

}




int main() {

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    
    printf("--------------------------------\n");
    printf("Welcome to the value converter!\n");
    printf("--------------------------------\n");
    printf("Please select an option!\n");
    printf("--------------------------------\n");
    printf("(1) Decimal to Binary\n");
    printf("(2) Decimal to Binary\n");
    printf("(3) Decimal to Binary\n");
    printf("(4) Decimal to Binary\n");
    printf("--------------------------------\n");



    int value;
    char line[100];

    while (1) {
        printf("Please enter a value: ");
        if (!fgets(line, sizeof(line), stdin)) {
            //fgets failed (EOF or error)
            printf("Error reading input.\n");
            return 1;
        }

        // Try to parse integer
        if (sscanf(line, "%d", &value) == 1) {
            break; // success
        }

        // failed to parse integer
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        
        printf("Invalid input. Please enter a number.\n");

    }

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf("--------------------------------\n");
    printf("You entered value: %d\n", value);
    printf("--------------------------------\n");


    printf("Binary: ");
    dec_to_binary(value);

    printf("--------------------------------\n");

    printf("Hexadeimal: 0x");
    dec_to_hexadecimal(value);
    printf("\n");

    printf("--------------------------------\n");
    

    return 0;
}
