#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

#include "player.hh"

#define DEFAULT_SPINS 10000
#define PLAYERS_AMOUNT 6


//colors array of int that represents the diferents colors of a number by index in a Roulette
//-1::green | 0::red | 1::black
int colors[37] = {-1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0};


//Bet Functions

int isRed (int number){
	return (colors[number] == 0);
}

int isBlack (int number){
	return colors[number];
}

int isEven (int number){
	return (number % 2 == 0) && (number != 0);
}

int isOdd (int number){
	return (!(isEven(number)) && (number != 0));
}

int isHigh (int number){
	return (number >= 19);
}

int isLow (int number){
	return ((number > 0) && (number < 19));
}

//computeBet receives a number and a class player
//and decides by the player name whitch function
//is going to run by the player choice of bet
int computeBet(int number, char player){
	int result;
	switch(player) {
      case 'A' :
         result = isRed(number);
         break;
      case 'B' :
		result = isBlack(number);
         break;
      case 'C' :
         result = isHigh(number);
         break;
      case 'D' :
         result = isLow(number);
         break;
	  case 'E' :
         result = isEven(number);
         break;
      case 'F' :
         result = isOdd(number);
         break;
      default :
         std::cout << "Invalid player" << std::endl;
   }//returns the value that determinates if the player won or not the bet
   return result;
}


int main(int argc, char *argv[]){
	std::ofstream myfile;//we are going to write down each number of the roulette simulation
    myfile.open ("roulette_play.txt");
    myfile << "Roulette numbers:\n\t";
    
	srand((unsigned)time(0));

	Player *players[PLAYERS_AMOUNT];//amount of players that are going to bet

	for (int i = 0; i < PLAYERS_AMOUNT; i++ ){
		players[i] = new Player(char('A'+i));//dynamic array for players from A to F
	}


	
    int number;//value to store the Roulette output in each spin
	int result;//value to store the status of your bet in that spin

	
	std::cout<<std::endl<<"_________Starting Simulation_________"<<std::endl;

	//I could have and option to pass the amount of spins by running the program
	//or with a cin, the same goes for the players
   	for (int i = 0; i < DEFAULT_SPINS; i++){
		   //i can add a case if it's decide to play with a fisical roulette to add numbers manually
			number = (rand()%37);//generate a number between 0 and 36
			std::cout<<std::endl<<" _Spin number "<<i+1<<"_"<<std::endl;
			std::cout <<"<<Roulette result= " <<number <<">>"<< std::endl<<std::endl;
			
			myfile << number << "_";

		for (int i = 0; i < PLAYERS_AMOUNT; i++ ){
			result = computeBet(number,char('A'+i));

			players[i]->generateBet();
			std::cout <<"Player "<<players[i]->getName()<<" -> Betted: "<<players[i]->getBet()<<std::endl;

			players[i]->updateBets(result);//updates the bets list by the given result

		}



   	}
	std::cout<<std::endl<<"_________No more Spins_________"<<std::endl;
	int earnings = 0;//to store each players earnings

	std::cout<<std::endl<<std::endl <<"SUMMARY: "<<std::endl<<std::endl;
	myfile <<std::endl<<std::endl<<"___PLAYERS SUMMARY___ "<<std::endl<<std::endl;
	
	for (int i = 0; i < PLAYERS_AMOUNT; i++ ){
			std::cout<<"Player "<<players[i]->getName()<<" BALANCE: "<< players[i]->getEarnings()<<std::endl;
			
			myfile <<"Player "<<players[i]->getName()<<" BALANCE: "<< players[i]->getEarnings()<<std::endl;

			earnings += players[i]->getEarnings();

			delete players[i];//free the given memory

		}

	std::cout<<std::endl<<std::endl <<"GROUP BALANCE: "<< earnings<<std::endl;

	myfile<<std::endl<<std::endl <<"GROUP BALANCE: "<< earnings<<std::endl;
	myfile.close();

	
		

    return 0;
}
