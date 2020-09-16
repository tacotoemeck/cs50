#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars = get_float("Change owed: ");
    float cents = round(dollars * 100.00);
    int coinCount = 0;
    do
    {
        if (cents >= 25)
        {
            cents -= 25;
            coinCount++;
        }
        else if (cents >= 10)
        {
            cents -= 10;
            coinCount++;
        }
        else if (cents >= 5)
        {
            cents -= 5;
            coinCount++;
        }
        else if (cents >= 1)
        {
            cents -= 1;
            coinCount++;
        }
    } while (cents > 0);

    printf("%i", coinCount);
}
