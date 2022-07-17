#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
// 
int temp;
int rows = 27;
int columns = 2;
int points[27][2] = {{'A', 1}, {'B', 3}, {'C', 3}, {'D', 2}, {'E',1}, {'F',4}, {'G',2}, {'H',4}, {'I',1}, {'J',8}, 
                {'K',5}, {'L',1}, {'M',3}, {'N',1}, {'O',1}, {'P',3}, {'Q',10}, {'R',1}, {'S',1}, {'T',1}, 
                {'U',1}, {'V',4}, {'W',4}, {'X',8}, {'Y',4}, {'Z',10}, {' ',0}};
                
int letter[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
                
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    
    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    } else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    } else 
    {
        printf("Tie!\n");
    }
    
}

int compute_score(string word)
{
    int total = 0;
    // TODO: Compute and return score for string
    //change all input to upper
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        word[i] = toupper(word[i]);
    }
    // A = [0][0] 1 = [0][1]
    // B = [1][0] 3 = [1][1]
    // C = [2][0] 3 = [2][1]
    
    
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        int j = 0;
        while (word[i] != points[j][0])
        {
            j++;
            if (j > 25)
            {
                break;
            }
        }
        total += points[j][1];
        
    }
    
    return total;
    // compare to 
}
