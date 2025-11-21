#include <stdio.h>
#include <stdlib.h>

void clear_screen() {
// clear screen
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

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

// Option 1
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

// Option 2
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
    hex[i] = '\0'; 

    printf("0x");
    for (int j = i -1; j >=  0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
}

// Option 3
void hex_to_binary(int n) {

}

// Option 4
void hex_to_decimal(int n) {

}

// Option 5
void binary_to_decimal(int n) {

}

// Option 6
void binary_to_hex(int n) {

}



int main() {
    int selection;  // Selection of what type of conversion
    char line[100];  // To scan the input
    clear_screen();
    print_main_menu();
    printf("Select 1, 2, 3, etc. : ");
    
    // Get input for conversion type
    while (1) {
	if (!fgets(line, sizeof(line), stdin)) {
        //fgets failed (EOF or error)                                                             
        printf("Error reading input.\n");
        return 1;
        }
        // Try to parse integer
        if (sscanf(line, " %d", &selection) == 1 && selection >= 1 && selection <=6) {
            break; // success
        }
        //failed to parse a proper selection
        clear_screen();
        //Re-display menu
        print_main_menu();
        //Display error message
        printf("Invalid input. Please enter number 1-6: ");
    }
    int value = 0;
    char extra; // For checking invalid decimal input (example = 134f)

    // Option 1 - D-B
    if (selection == 1) {
        clear_screen();
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
            if (sscanf(line, " %d %c", &value, &extra) == 1) {
                break; // success, will now print result screen
            }
            
            // failed to parse integer
            clear_screen();
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
        clear_screen();
        // Print result menu
        printf("--------------------------------\n");
        printf("You entered value: %d\n", value);
        printf("--------------------------------\n");
        printf("Binary: ");
        dec_to_binary(value);
        printf("--------------------------------\n");

    }
    
    // Option 2 - D-H
    if (selection == 2) {
        clear_screen();

        // Print decimal to hex menu
        printf("--------------------------------\n");
        printf("------Decimal to Hexadecimal---------\n");
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
            if (sscanf(line, " %d %c", &value, &extra) == 1) {
                break; // success, will now print result screen
            }
            
            // failed to parse integer
            clear_screen();
            // Reprint Menu
            printf("--------------------------------\n");
            printf("------Decimal to Hexadecimal---------\n");
            printf("--------------------------------\n");
            printf("Please enter a decimal value.\n");
            printf("--------------------------------\n");
            // Print error message
            printf("Invalid input, please enter only a decimal value.\n");
            printf("Value: ");
        }
    
        // Proper input found - plug value into function
        clear_screen();
        // Print result menu
        printf("--------------------------------\n");
        printf("You entered value: %d\n", value);
        printf("--------------------------------\n");
        printf("Hexadecimal: ");
        dec_to_hexadecimal(value);
        printf("--------------------------------\n");
    }
    
    // Option 3 - H-B
    if (selection == 3) {
        clear_screen();

        // Print hex to binary menu
        printf("--------------------------------\n");
        printf("------Hexadecimal to Binary---------\n");
        printf("--------------------------------\n");
        printf("Please enter a hex value.\n");
        printf("--------------------------------\n");
        printf("Value: ");
        printf("--------------------------------\n");
        printf("Hexadecimal to Binary will go here.\n  Program will exit.");
    }
    
    // Option 4 - H-D
    if (selection == 4) {
        clear_screen();

        // Print hex to decimal menu
        printf("--------------------------------\n");
        printf("------Hexadecimal to Decimal---------\n");
        printf("--------------------------------\n");
        printf("Please enter a hex value.\n");
        printf("--------------------------------\n");
        printf("Value: ");
        printf("--------------------------------\n");
        printf("Hexadecimal to Decimal will go here.\n  Program will exit.");
    }
    
    // Option 5 - B-D
    if (selection == 5) {
        clear_screen();

        // Print binary to decimal menu
        printf("--------------------------------\n");
        printf("------Binary to Decimal---------\n");
        printf("--------------------------------\n");
        printf("Please enter a binary value.\n");
        printf("--------------------------------\n");
        printf("Value: ");
        printf("--------------------------------\n");
        printf("Binary to Decimal will go here.\n  Program will exit.");
    }
    
    // Option 6 - B-H
    if (selection == 6) {
        clear_screen();

        // Print decimal to hex menu
        printf("--------------------------------\n");
        printf("------Binary to Hexadecimal---------\n");
        printf("--------------------------------\n");
        printf("Please enter a binary value.\n");
        printf("--------------------------------\n");
        printf("Value: ");
        printf("--------------------------------\n");
        printf("Binary to Hexadecimal will go here.\n  Program will exit.");
    }

  

    return 0;
}
