#include <stdio.h>
#include <cs50.h>

void printHush(char character, int counter);
int main(void)
{
    char hash = '#';
    char space = ' ';
    int height = get_int("What height\n");
    int counter = 1;
    do
    {
        printHush(space, height - counter);
        printHush(hash, counter);
        printf(" ");
        printHush(hash, counter);
        printf("\n");
        counter = counter + 1;

    } while (counter <= height);

}

void printHush(char character, int counter) {
    for ( int i = 0; i < counter; i++ )
    {
        printf("%c", character);
    }
};

