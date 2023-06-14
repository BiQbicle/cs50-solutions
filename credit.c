#include <stdio.h>
#include <string.h>

long long get_number_proomt() {
    long long change_owed;
    printf("Enter a credit card: ");
    while (scanf("%lld", &change_owed) != 1 || change_owed < 1) {
        printf("Enter a credit card: ");

        while (getchar() != '\n') {
            continue;
        }
    }
    return change_owed;
}

int luhn_algorithm(long long number) {
    int sum = 0;
    int digit_count = 0;
    int is_second = 0;

    while (number > 0) {
        // getting the last digit
        int digit = number % 10;

        if (is_second) {
            digit *= 2;
            if (digit > 9) {
                digit = digit % 10 + digit / 10;
            }
        }

        sum += digit;

        is_second = !is_second;
        number /= 10;
        digit_count++;
    }
    return sum % 10 == 0 && digit_count >= 13;
}

int main() {
    long long credit_card_number = get_number_proomt();

    if (luhn_algorithm(credit_card_number)) {
        char card_number_str[20];
        sprintf(card_number_str, "%lld", credit_card_number);

        int length = strlen(card_number_str);

        if (length == 15 &&
            (card_number_str[0] == '3' &&
             (card_number_str[1] == '4' || card_number_str[1] == '7'))) {
            printf("American Express\n");
        } else if ((length == 13 || length == 16 || length == 19) &&
                   card_number_str[0] == '4') {
            printf("Visa card\n");
        } else if (length == 16 && card_number_str[0] == '5' &&
                   card_number_str[1] >= '1' && card_number_str[1] <= '5') {
            printf("Mastercard card\n");
        } else {
            printf("The card is valid\n"); 
        }
    } else {
        printf("Invalid\n");
    }

    return 0;
}

/*
Input: - long long
4111111111111111

2897346982378633

Output: - char* (aka string)
Valid, VISA

Invalid

---
*/