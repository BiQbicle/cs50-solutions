#include <stdio.h>

int get_change_owed() {
    int change_owed;
    printf("How Much Change Do You Owe? ");
    while (scanf("%d", &change_owed) != 1 || change_owed < 1 ||
           change_owed > 10000) {
        printf("How Much Change Do You Owe? ");

        while (getchar() != '\n') {
            continue;
        }
    }
    return change_owed;
}

int main(void) {
    const unsigned short QUARTER = 25;
    const unsigned short DIME = 10;
    const unsigned short NICKEL = 5;
    const unsigned short PENNY = 1;

    int total_change_owed = get_change_owed();
    unsigned short cent_count = 0;

    while (total_change_owed > 0) {
        if (total_change_owed >= QUARTER) {
            cent_count++;
            total_change_owed = (total_change_owed - QUARTER);
        } else if (total_change_owed >= DIME) {
            cent_count++;
            total_change_owed = (total_change_owed - DIME);
        } else if (total_change_owed >= NICKEL) {
            cent_count++;
            total_change_owed = (total_change_owed - NICKEL);
        } else if (total_change_owed >= PENNY) {
            cent_count++;
            total_change_owed = (total_change_owed - PENNY);
        }
    }
    printf("%d", cent_count);

    return 0;
}

/*

72

25:1
25:1

10:1
10:1

1:1
1:1


*/