#include <stdio.h>
#include <cs50.h>
#include <string.h>
// #include <math.h>

void key_validator(string key);
int main(int argc, string argv[])
{
    // validate the key
    key_validator(argv[1]);

    // non-alphabetic chars ( use ascii again)

    // non-unique

    //get plain text

    //decode

    // print
}

void key_validator(string key)
{
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.");
    }
    else
    {
        for (int i = 0; i < strlen(key); i++)
        {
            if (!((key[i] >= 'a' && key[i] <= 'z') || (key[i] >= 'A' && key[i] <= 'Z')))
            {
                printf("Usage: ./substitution key\n");
                return;
            }
        }
    }
}