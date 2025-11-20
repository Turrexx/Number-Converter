#include <stdio.h>
#include <stdlib.h>

void print_main_menu() {
    printf("--------------------------------\n");
    printf("Welcome to the value converter!\n");
    printf("--------------------------------\n");
    printf("Please select an option!\n");
    printf("--------------------------------\n");
    printf("(1) Decimal to Binary\n");
    printf("(2) Decimal to Hexadecimal\n");
    printf("(3) Hexadecimal to Binary\n");
    printf("(4) Hexadecimal to Decimal\n");
    printf("(5) Binary to Decimal\n");
    printf("(6) Binary to Hexadecimal\n");
    printf("--------------------------------\n");
}

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

    print_main_menu();
    
    
    int selection;
    char line[100];
    // Option selection for type of conversion.
    while (1) {
        printf("Select 1, 2, 3, etc. : ");
	if (!fgets(line, sizeof(line), stdin)) {
            //fgets failed (EOF or error)                                                             printf("Error reading input.\n");
            return 1;
        }
        // Try to parse integer
        if (sscanf(line, "%d", &selection) == 1 && selection >= 1 && selection <=6) {
            break; // success
        }
        //failed to parse a proper selection

        //Clear Screen
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        //Re-display menu
        print_main_menu();
        //Display error message
        printf("Invalid input. Please enter number 1-6: ");
    }
    int value;
    char extra; //Used to check no character values in decimal input
    //Option 1
    if (selection == 1) {
        //Clear screen
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        // Print decimal to binary menu
        printf("--------------------------------\n");
        printf("------Decimal to binary---------\n");
        printf("--------------------------------\n");
        printf("Please enter a decimal value.\n");
        printf("--------------------------------\n");
        printf("Value: ");
        // Check for proper input
        while (1) {
            //scan for value input.
            if (!fgets(line, sizeof(line), stdin)) {
                //fgets failed (EOF or error)
                printf("Error reading input.\n");
                return 1;
                }
            // Try to parse integer
            if (sscanf(line, " %d %c", &value) == 1) {
                break; // success
            }
            
            // failed to parse integer
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
            // Reprint Menu
            printf("--------------------------------\n");
            printf("------Decimal to binary---------\n");
            printf("--------------------------------\n");
            printf("Please enter a decimal value.\n");
            printf("--------------------------------\n");
            // Print error message
            printf("Invalid input, please enter only a decimal value.\n");
            printf("Value: ");
            
        }
    
        // Proper input found - plug value into function
        // Clear screen
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        // Print result menu
        printf("--------------------------------\n");
        printf("You entered value: %d\n", value);
        printf("--------------------------------\n");
        printf("Binary: ");
        dec_to_binary(value);
        printf("--------------------------------\n");

    }


    
    

  

    return 0;
}
