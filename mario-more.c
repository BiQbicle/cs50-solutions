#include <stdio.h>

unsigned short get_height()
{
    unsigned short height;
    printf("What Is The Size Of The Triangle? ");
    while (scanf("%hu", &height) != 1 || height < 1 || height > 10000)
    {
        printf("What Is The Size Of The Triangle? ");

        while (getchar() != '\n')
        {
            continue;
        }
    }
    return height;
}

int main(void)
{
    const unsigned short HEIGHT = get_height();
    const char AIR_BLOCK = ' ';

    for (short row = 1; row <= HEIGHT; row++)
    {
        short air_block_count = HEIGHT - row;
        for (short x = 0; x < air_block_count; x++)
        {
            printf("%c", AIR_BLOCK);
        }
        short brick_block_count = row - 1;
        for (short y = 0; y <= brick_block_count; y++)
        {
            printf("#");
        }
        printf(" ");
        for (short y = 0; y <= brick_block_count; y++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}