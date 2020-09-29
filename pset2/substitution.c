#include <stdio.h>
#include <cs50.h>
#include <string.h>

void key_validator(string key);
void substitue_letters(string key);
int main(int argc, string argv[])
{
    key_validator(argv[1]);
}

void key_validator(string key)
{
    bool isUnique = true;

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.");
        isUnique = false;
        return;
    }
    else
    {
        for (int i = 0; i < strlen(key); i++)
        {
            if (!(key[i] >= 'A' && key[i] <= 'Z') && !(key[i] >= 'a' && key[i] <= 'z'))
            {
                isUnique = false;
            }
            else
            {
                for (int j = i + 1; j < strlen(key); j++)
                {
                    if (key[i] == key[j])
                    {
                        isUnique = false;
                    }
                }
            }
            if (!isUnique)
            {
                printf("Usage: ./substitution key\n");
                return;
            }
        }
    }
    if (isUnique)
    {
        substitue_letters(key);
    }
}

void substitue_letters(string key)
{

    char subs[strlen(key)][2];
    char letter_a = 'A';
    string plaintext = get_string("plaintext:");
    char ciphertext[40] = "";

    for (int i = 0; i < strlen(key); i++)
    {
        if (key[i] >= 'A' && key[i] <= 'Z')
        {
            subs[i][0] = letter_a;
            subs[i][1] = key[i];
            letter_a++;
        }
        else if (key[i] >= 'a' && key[i] <= 'z')
        {
            subs[i][0] = letter_a + 32;
            subs[i][1] = key[i];
            letter_a++;
        }
    }

    for (int k = 0; k < strlen(plaintext); k++)
    {
        for (int j = 0; j <= strlen(key); j++)
        {
            if ((plaintext[k] >= 'A' && plaintext[k] <= 'Z') || (plaintext[k] >= 'a' && plaintext[k] <= 'z'))
            {
                if (subs[j][0] == plaintext[k] || subs[j][0] + 32 == plaintext[k] || subs[j][0] - 32 == plaintext[k])
                {
                    if (plaintext[k] >= 'a' && subs[j][1] <= 'a')
                    {
                        char toAdd = subs[j][1] + 32;
                        strncat(ciphertext, &toAdd, 1);
                    }
                    else if (plaintext[k] <= 'a' && subs[j][1] >= 'a')
                    {
                        char toAdd = subs[j][1] - 32;
                        strncat(ciphertext, &toAdd, 1);
                    }
                    else
                    {
                        strncat(ciphertext, &subs[j][1], 1);
                    }
                    break;
                }
            }

            else if (j == strlen(key))
            {
                strncat(ciphertext, &plaintext[k], 1);
            }
        }
    }
    printf("ciphertext: %s", ciphertext);
}