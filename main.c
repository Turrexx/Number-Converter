#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


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

void print_menu(const char *from, const char *to) {
    printf("--------------------------------\n");
    printf("----- %s to %s-----\n", from, to);
    printf("--------------------------------\n");
    printf("--Please enter a %s value.--\n", from);
    printf("--------------------------------\n");
    printf("Value: ");
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
int hex_to_binary(const char *hex) {
    char binary[512] = "";
    
    // hex to bin lookup table
    const char *hex_to_bin[] = {
        "0000", "0001", "0010", "0011",
        "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011",
        "1100", "1101", "1110", "1111"
    };

    // Loop over hex input
    int len = strlen(hex);
    for (int i = 0; i < len; i++) {
        char c = toupper(hex[i]);
        int index;
        
        // If number, subract ascii value by 0's ascii value
        // to get index
        if (c >= '0' && c <= '9')
            index = c - '0';
        // If letter, subtract by A's ascii value
        // and add 10 to account for hex value     
        else if (c >= 'A' && c <= 'F')
            index = 10 + (c - 'A');
        else {
            printf("Invalid hex digit: %c\n", c);
            return 1;
        }
        // For each iteration, add new binary string obtained from lookup table index
        strcat(binary, hex_to_bin[index]);
    }
    // Then print the entire string
    printf("Hex: %s\n", hex);
    printf("Binary: %s\n", binary);
    return 0;
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
        print_menu("Decimal", "Binary");
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
            printf("***Invalid input, please enter only a decimal value.***\n");
            print_menu("Decimal", "Binary");
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
        print_menu("Decimal", "Hexadecimal");
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
            printf("Invalid input, please enter only a decimal value.\n");
            print_menu("Decimal", "Hexadecimal");
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
        char hex_input[100];

        // Print hex to binary menu
        print_menu("Hexadecimal", "Binary");
        while (1) {
            //scan for hex input.
            if (!fgets(line, sizeof(line), stdin)) {
                //fgets failed (EOF or error)
                printf("Error reading input.\n");
                return 1;
                }
            // Read string
            if (sscanf(line, "%s", hex_input) == 1) {
                break; // success, will now print result screen
            }
            // failed to parse integer
            clear_screen();
            // Reprint Menu
            printf("Invalid input, please enter a hex value.\n");
            print_menu("Hexadecimal", "Binary");
        
    }
        clear_screen();
        // Print result menu
        printf("--------------------------------\n");
        printf("You entered value: %s\n", hex_input);
        printf("--------------------------------\n");
        printf("Binary: ");
        hex_to_binary(hex_input);
        printf("--------------------------------\n");
}
    
    // Option 4 - H-D
    if (selection == 4) {
        clear_screen();

        // Print hex to decimal menu
        print_menu("Hexadecimal", "Decimal");
    }
    
    // Option 5 - B-D
    if (selection == 5) {
        clear_screen();

        // Print binary to decimal menu
        print_menu("Binary", "Decimal");
    }
    
    // Option 6 - B-H
    if (selection == 6) {
        clear_screen();

        // Print decimal to hex menu
        print_menu("Binary", "Decimal");
    }



    return 0;
}
