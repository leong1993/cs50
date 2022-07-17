#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool isNotLetter(string text, int length);
bool isRepeat(string text, int length);
string toUpper(string text, int length);
int translate(string plaintext, string text);

int main(int argc, string argv[]) 
{   
    //one input only?
    //26?
    //all letter?
    //any digit cant same
    if (argc != 2)
    {
        printf("%s KEY\n", argv[0]);
        return 1;
    }
    string text = argv[1];
    string plaintext;
    int textCharacters = strlen(text);  //check 26 characters??
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        text[i] = toupper(text[i]);
    }
    printf("%i\n", textCharacters); 
    printf("%i\n", argc);
    printf("%s\n", text);
    if ((argc != 2) || (textCharacters != 26) || (isNotLetter(text, textCharacters)) || (isRepeat(text, textCharacters)))
    {
        printf("%s KEY\n", argv[0]);
        return 1;
    } 
    else 
    {
        plaintext = get_string("plaintext:  "); 
    }
    translate(plaintext, text);
    return 0;
} 

bool isNotLetter(string text, int length)
{   
    
    for (int i = 0; i < length; i++) 
    {
        if (isalpha(text[i]) == 0) // isalpha = 0 for not alphabet
        {
            return true;
            break;
        }

    }
    return false;
}

bool isRepeat(string text, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (text[i] == text[j])
            {
                return true;
            }
        }
    }
    return false;
} 

int translate(string plaintext, string text)
{
    char lowertext[30]; 
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        lowertext[i] = tolower(text[i]);
        
    }
    
    printf("ciphertext: "); 
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            int temp = plaintext[i] - 'A';
            printf("%c", text[temp]);
        } 
        else if (islower(plaintext[i]))
        {
            int temp = plaintext[i] - 'a';
            printf("%c", lowertext[temp]);
        }
        else if (isspace(plaintext[i]) || ispunct(plaintext[i]) || isdigit(plaintext[i])) 
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}
 

