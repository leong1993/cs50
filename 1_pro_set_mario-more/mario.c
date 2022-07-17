#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    int n;
    
    do  
    {
        n = get_int("height?\n");
    }
        
    while (n > 8 || n < 1);
    // n = 5
    // first loop 4
    // second loop 1
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            printf(" ");    
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");    
        }
        for (int l = 0; l < 2; l++)
        {
            printf(" ");
        }
        for (int a = 0; a < i + 1; a++)
        {
            printf("#");
        }
        printf("\n");
    }
}