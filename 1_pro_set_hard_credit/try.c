#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //nuber % 10
    //reminder = last digit
    //put reminder in arrary
    //number / 10
    int digitArray[20];
    int i = 0;
    
    long int cardNumber = 0;
    
    do
    {
        cardNumber = get_long("What is your card Number?\n");    
    }
    
    while (cardNumber < 0);

    while (cardNumber > 0)
    {
        int tempReminder = cardNumber % 10;
        digitArray [i] = tempReminder;
        cardNumber /= 10;
        i++;
        }
    
    
    for (int j = 0; j < i; j++) 
    {     
        printf("%d\n", digitArray[j]);
    }
    
}
