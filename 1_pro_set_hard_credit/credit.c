#include <cs50.h>
#include <stdio.h>

long getDigit();
int check, count, sum1, sum2, total;


int main(void)
{
    long cardDigit = getDigit();
    long countDigit = cardDigit;

    int no1, no2, no3, no4, no5, no6, no7, no8;
    //get each even digit
    no1 = ((cardDigit % 100) / 10) * 2;
    no2 = ((cardDigit % 10000) / 1000) * 2;
    no3 = ((cardDigit % 1000000) / 100000) * 2;
    no4 = ((cardDigit % 100000000) / 10000000) * 2;
    no5 = ((cardDigit % 10000000000) / 1000000000) * 2;
    no6 = ((cardDigit % 1000000000000) / 100000000000) * 2;
    no7 = ((cardDigit % 100000000000000) / 10000000000000) * 2;
    no8 = ((cardDigit % 10000000000000000) / 1000000000000000) * 2;
    
    
    //add first and second digit
    no1 = (no1 % 10) + (no1 / 10 % 10);
    no2 = (no2 % 10) + (no2 / 10 % 10);
    no3 = (no3 % 10) + (no3 / 10 % 10);
    no4 = (no4 % 10) + (no4 / 10 % 10);
    no5 = (no5 % 10) + (no5 / 10 % 10);
    no6 = (no6 % 10) + (no6 / 10 % 10);
    no7 = (no7 % 10) + (no7 / 10 % 10);
    no8 = (no8 % 10) + (no8 / 10 % 10);
    
    sum1 = no1 + no2 + no3 + no4 + no5 + no6 + no7 + no8;
    int no9, no10, no11, no12, no13, no14, no15, no16;
    
    no9 = (cardDigit % 10);
    no10 = ((cardDigit % 1000) / 100);
    no11 = ((cardDigit % 100000) / 10000);
    no12 = ((cardDigit % 10000000) / 1000000);
    no13 = ((cardDigit % 1000000000) / 100000000);
    no14 = ((cardDigit % 100000000000) / 10000000000);
    no15 = ((cardDigit % 10000000000000) / 1000000000000);
    no16 = ((cardDigit % 1000000000000000) / 100000000000000);
    
    sum2 = no9 + no10 + no11 + no12 + no13 + no14 + no15 + no16;
    
    total = sum1 + sum2;
    
    int totalLastDigit = (total % 10);
    
    
    
    //count how many digit
    while (countDigit > 0)
    {
        countDigit /= 10;
        count++;
    }
    
    //AE 15 digit ; 34 / 37
    //Master 16 digit ; 51 / 52 / 53 / 54 / 55
    //Visa 13/16 digit ; 4
    long AE = cardDigit / 10000000000000; //15
    long Master = cardDigit / 100000000000000; //16
    long Visa = cardDigit / 1000000000000; //13
    long Visa1 = cardDigit / 1000000000000000; 
    

    if ((count == 15 && totalLastDigit == 0) && (AE == 34 || AE == 37))
    {
        printf("AMEX\n");    
    } 
    else if ((count == 16 && totalLastDigit == 0) && (Master == 51 || Master == 52 || Master == 53 || Master == 54 || Master == 55))
    {
        printf("MASTERCARD\n");
    } 
    else if ((totalLastDigit == 0) && (Visa == 4 || Visa1 == 4) && (count == 13 || count == 16))
    {
        printf("VISA\n");
    } 
    else 
    {
        printf("INVALID\n");
    }
}

long getDigit(void)
{
    long cardNumber = 0;

    do
    {
        cardNumber = get_long_long("What is your card Number?\n");
    }

    while (cardNumber < 0);
    return cardNumber;
}