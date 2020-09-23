#include <stdio.h>
#include <cs50.h>
#include <string.h>
// #include <math.h>

void key_validator(string key);
int main(int argc, string argv[])
{
    // validate the key
    key_validator(argv[1]);
}

void key_validator(string key)
{
    bool isUnique = true;

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.");
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
}

// void check_for_non_unique_chars(string key, int i)
// {

//     return isUnique;
// }

// #include <stdio.h>
// #include <cs50.h>
// #include <string.h>
// // #include <math.h>

// void key_validator(string key);
// void check_for_non_unique_chars(string key);
// int main(int argc, string argv[])
// {
//     // validate the key
//     key_validator(argv[1]);
// }

// void key_validator(string key)
// {
//     if (strlen(key) != 26)
//     {
//         printf("Key must contain 26 characters.");
//     }
//     else
//     {
//         for (int i = 0; i < strlen(key); i++)
//         {
//             if (!(key[i] >= 'A' && key[i] <= 'Z') && !(key[i] >= 'a' && key[i] <= 'z'))
//             {
//                 printf("Usage: ./substitution key\n");
//                 return;
//             }
//         }
//         check_for_non_unique_chars(key);
//     }
// }

// void check_for_non_unique_chars(string key)
// {
//     for (int i = 0; i < strlen(key) - 1; i++)
//     {
//         for (int j = i + 1; j < strlen(key); j++)
//         {
//             if (key[i] == key[j])
//             {
//                 printf("Usage: ./substitution key\n");
//                 return;
//             }
//         }
//     }
//     printf("all clear yo!");
// }

// #include <stdio.h>
// #include <cs50.h>
// #include <string.h>
// // #include <math.h>

// void key_validator(string key);
// void check_for_non_unique_chars(string key, int i);
// int main(int argc, string argv[])
// {
//     // validate the key
//     key_validator(argv[1]);
// }

// void key_validator(string key)
// {
//     if (strlen(key) != 26)
//     {
//         printf("Key must contain 26 characters.");
//     }
//     else
//     {
//         for (int i = 0; i < strlen(key); i++)
//         {
//             if (!(key[i] >= 'A' && key[i] <= 'Z') && !(key[i] >= 'a' && key[i] <= 'z'))
//             {
//                 printf("Usage: ./substitution key\n");
//                 return;
//             }
//             else
//             {
//                 check_for_non_unique_chars(key, i);
//             }
//         }
//     }
// }

// void check_for_non_unique_chars(string key, int i)
// {

//     for (int j = i + 1; j < strlen(key); j++)
//     {
//         if (key[i] == key[j])
//         {
//             printf("Usage: ./substitution key\n");
//             return;
//         }
//     }

// }