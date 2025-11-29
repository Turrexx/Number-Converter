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
    printf("----- %s to %s -----\n", from, to);
    printf("--------------------------------\n");
}

void print_result(const char *from, const char*to, char *input) {
    printf("--------------------------------\n");
    printf("----- %s to %s -----\n", from, to);
    printf("--------------------------------\n");
    printf("You entered value: %s\n", input);
    printf("--------------------------------\n");
    printf("%s: ", to);
}

int get_dec_input(const char *from, const char *to) {
    char line[100];
    int dec_input;
    char extra; // For checking invalid decimal input (example = 134f)
    

    while (1) {
        printf("Please enter a decimal value: ");

        if (!fgets(line, sizeof(line), stdin)) {
            printf("Input error - Please try again.");
            clearerr(stdin);
            continue;
        }
        // CHeck for valid input
        if (sscanf(line, " %d %c", &dec_input, &extra) == 1) {
            return dec_input;
        }
        clear_screen();
        print_menu(from, to);
        printf("Invalid input.\n");

    }

}

void get_hex_input(char *input, const char *from, const char *to) {
    char line[100];
    
    while (1) {
        printf("Please enter a hex value: ");

        if (!fgets(line, sizeof(line), stdin)) {
            printf("Input error - Please try again.");
            clearerr(stdin);
            continue;
        }
        // Check for valid input
        if (sscanf(line, "%99s", input) == 1) {
            int valid = 1; // valid by default

            for (int i = 0; input[i] != '\0'; i++) {
                if (!isxdigit((unsigned char)input[i])) { // if not 0-9A-F
                    valid = 0;  // set to invalid
                    break;
                }
            }
            if (valid) {
                return;
            }
        }
        clear_screen();
        print_menu(from, to);
        printf("Invalid input.\n");

    }

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
void hex_to_binary(const char *hex) {
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
            return;
        }
        // For each iteration, add new binary string obtained from lookup table index
        strcat(binary, hex_to_bin[index]);
    }
    // Then print the entire string
    
    printf("%s\n", binary);
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
    char extra; // For checking invalid decimal input (example = 134f)
    char line[100];  // To scan the input
    clear_screen();
    print_main_menu();
    printf("Select 1, 2, 3, etc. : ");
    
    // Get input for conversion type
    while (1) {
	if (!fgets(line, sizeof(line), stdin)) {
            printf("Input error - Please try again.");
            clearerr(stdin);
            continue;
    }
        // Try to parse integer
        if (sscanf(line, " %d %s", &selection, &extra) == 1 && selection >= 1 && selection <=6) {
            break; // success
        }
        //failed to parse a proper selection
        clear_screen();
        //Re-display menu
        print_main_menu();
        //Display error message
        printf("Invalid input. Please enter number 1-6: ");
    }
    


    switch (selection) {

    case 1: {
        clear_screen();
        // Print decimal to binary menu
        print_menu("Decimal", "Binary");

        // Get decimal input
        int dec_value = get_dec_input("Decimal", "Binary");
        
        // Proper input found - plug value into function
        clear_screen();
        // Print result menu
        char input_str[50];
        sprintf(input_str, "%d", dec_value);  //convert to string for result printing.
        print_result("Decimal", "Binary", input_str);
        dec_to_binary(dec_value);
        printf("--------------------------------\n");
        break;
    }

    case 2: {
        clear_screen();
        // Print decimal to hex menu
        print_menu("Decimal", "Hexadecimal");
        
        // Get decimal input
        int dec_value = get_dec_input("Decimal", "Hexadecimal");
        
        // Proper input found - plug value into function
        clear_screen();
        // Print result menu
        char input_str[50];
        sprintf(input_str, "%d", dec_value);
        print_result("Decimal", "Hexadecimal", input_str);
        dec_to_hexadecimal(dec_value);
        printf("--------------------------------\n");
        break;
    }

    case 3: {
        clear_screen();
        char hex_input[100];

        // Print hex to binary menu
        print_menu("Hexadecimal", "Binary");
        get_hex_input(hex_input, "Hexadecimal", "Binary");
        clear_screen();
        // Print result menu
        print_result("Hexadecimal", "Binary", hex_input);
        hex_to_binary(hex_input);
        printf("--------------------------------\n");
        break;
    }

    case 4: {
        clear_screen();

        // Print hex to decimal menu
        print_menu("Hexadecimal", "Decimal");
        break;
    }

    case 5: {
        clear_screen();

        // Print binary to decimal menu
        print_menu("Binary", "Decimal");
        break;
    }

    case 6: {
        clear_screen();

        // Print decimal to hex menu
        print_menu("Binary", "Hexadecimal");
        break;
    }

    default: {
        printf("Invalid selection.\n");
    }
}


    return 0;
}
