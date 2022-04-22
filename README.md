# Casino Roulette Simulator
### The roulette will be simulating 10 000 spins
## Rules:
### Players Bets
* Player ‘A’ bets for Red.
* Player ‘B’ bets for Black.
* Player ‘C’ bets for greater.
* Player ‘D’ bets for less than.
* Player ‘E’ bets for even.
* Player ‘F’ bets for odd.

### Bets
* Minimum bet: 5.
* Maximum bet: 4000.


###### Each player has infinite amount of money. This means that the summary at the end can be negative.	

## 

* When the program start each player will start with a paper that has written 1-2-3-4.
* For each bet the player will grab the first and last element written and bet the sum of does numbers. In case of having only one number in the paper he will bet that number ( following the rules of minimum and maximum).
* In case of losing the bet the player has to erase the first and last number of the list. But if he wins he has to write down the last bet at the end of the already existing list.
* If the player erase every number in the list or can’t form a bet that satisfy the max and min he will get back to the beginning with a 1-2-3-4 list.

## To Compile:
``` make```

## To Run
``` ./main```

#### After you run the code a file named "roulette_play.txt" will be generated. 
#### This file contains the numbers from each of the 10,000 spins, a Summary from the earnings of each player and the total earnings of the 6 players simulating they played as a group.


