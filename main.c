//Made by: Tanish Roy
//Oct 15, 2020


#include <stdio.h>
#include <stdlib.h>	
#include <time.h>

int twoDiceSum() //This function is meant to simulute two dice rolling
{                //Does this by creating two dice variables and generating
  int d1, d2;    //Dice Values between 1 and 6, inclusive

  d1 = rand() % (6) + 1;
  d2 = rand() % (6) + 1;

  return d1 + d2;
}

void tickMarker(int num_ticks, char tickType) //This function helps with
{                                             //printing the required
    int i;                                    //number of ticks
                                              
    for (i = 0; i < num_ticks; i++)           //useful for graphing
    {
        printf("%c", tickType);
    }
    printf("\n");
}



int main()
{
  srand((unsigned int) time(NULL));

  int diceSum, numRolls, i, maxLen, rollFrequency[11] = {0};   //array intialization  for storing roll frequency; 

  maxLen = 0; //maxlen is used for formatting graph borders horizontally

  printf("Please enter the number of rolls: "); //User promt
  scanf("%i", &numRolls);                       //Scans user input for number of rolls

  

  for (i = 0; i < numRolls; i++) //Rolling dice number of user inputed times
  {
    diceSum = twoDiceSum(); //Setting diceSum to return of 2 dice function
    rollFrequency[diceSum - 2] += 1; //Index of roll frequency is always two behind roll number
  }                                  // eg. rolled 12, stored at index 12-2 or 10 in rollFrequency array

  printf("\n\n");
  
  printf("*Legend*\n");
  printf("1 # represents one roll\n");

  printf("\n");

  printf("Two Dice Roll Sum vs Frequency Graph\n\n");
  
  for (int i = 0; i < 11; i ++) //Detrminging the maxlength of the bars of graph (used for formatting)
  {
    if (rollFrequency[i] > maxLen)
    {
      maxLen = rollFrequency[i];
    }
  }

  tickMarker(maxLen + 11, '-'); //Using tickMarker function to draw top horizontal border

  for (int i = 0; i < 11; i ++)
  {
    printf("| %i ", i + 2);  // printing the number rolled (is allways two more than the index it is stored)
    tickMarker(rollFrequency[i], '#'); //Using tickMarker function to draw bar for graph
  }
  
  tickMarker(maxLen + 11, '-'); //Using tickMarker function to draw bottom horizontal border

  printf("\n\n");
  printf("Num Rolls Table Format: \n"); //Creating table heading
  printf("\n");
  printf("Roll Sum | Num Rolls\n");
  printf("-----------------------\n"); 

  for (int i = 0; i < 11; i ++) //Printing table values
  {
    if (i + 2 > 9) //This is becuase less spaces are required for numbers like 10, 11 and 12 compared to 1 digit numbers
    {
      printf("%i       | %i \n", i + 2, rollFrequency[i]);
    }
    else
    {
      printf("%i        | %i \n", i + 2, rollFrequency[i]);
    }
    
  }

}