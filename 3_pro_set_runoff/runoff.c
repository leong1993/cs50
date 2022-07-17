#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];
// make a trial array
int trial[8][3] = {{2, 0, 1}, {2, 1, 0}, {1, 0, 2}, {1, 2, 0}, {0, 2, 1}, {0, 2, 1}, {0, 2, 1}, {2, 0, 1}};

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
     
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }
    printf("\n");
    
    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();
        
        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        // if(min != 0)        //try
        // {
        //     break;
        // }                   //try
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name); 
                }
            }
            break;
        }



        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    } 
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    //candidates[i].name
    //preferences[MAX_VOTERS][MAX_CANDIDATES]
    for (int i = 0; i < candidate_count; i++) 
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    
    
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[preferences[i][j]].eliminated == false)
            {
                candidates[preferences[i][j]].votes ++;
                printf("%s, %i\n", candidates[preferences[i][j]].name, candidates[preferences[i][j]].votes); 
                break;
            }

        }
    
    } 
    return; 
}
// Print the winner of the election, if there is one
bool print_winner(void)
{
    int temp = 0, count = 0, temp1 = 0;
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > temp)
        {
            temp = candidates[i].votes; //save maxnumber
            temp1 = i;
        }
    }
    if (temp > (voter_count / 2))
    {
        for (int i = 0; i < candidate_count; i++)
        {
            if (temp == candidates[i].votes)
            {
                count ++;
            }
        }
    } 
    else
    {
        return false;
    }
    if (count == 1)
    {
        printf("%s\n", candidates[temp1].name);
        return true;
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = voter_count;
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < min && candidates[i].eliminated == false)
        {
            min = candidates[i].votes;
            
        }
    }
    printf("min: %i\n", min);
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    
    int count = 0, eli = 0;
    for (int k = 0; k < candidate_count; k++)
    {
        if (candidates[k].eliminated == false)
        {
            eli ++;
        }
    }
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == min)
        {
            count ++;
        }
    }
    
    if (count == eli)
    {
        return true;
    } 
    else
    {
        return false;
    } 
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
