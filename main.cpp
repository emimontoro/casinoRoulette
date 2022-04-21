#include <cstdlib>
#include <ctime>
#include <iostream>
#include "player.hh"


using namespace std;
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
         cout << "Invalid player" << endl;
   }//returns the value that determinates if the player won or not the bet
   return result;
}


int main(){
  srand((unsigned)time(0));

	Player *players[6];//amount of players that are going to bet

	for (int i = 0; i < 6; i++ ){
		players[i] = new Player(char('A'+i));//dynamic array for players from A to F
	}



  int number;//value to store the Roulette output in each spin
	int result;//value to store the status of your bet in that spin

	cout<<endl<<"_________Starting Simulation_________"<<endl;
   	for (int i = 0; i < 10000; i++){
			number = (rand()%37);//generate a number between 0 and 36
			cout<<endl<<" _Spin number "<<i+1<<"_"<<endl;
			cout <<"<<Roulette result= " <<number <<">>"<< endl<<endl;

		for (int i = 0; i < 6; i++ ){
			result = computeBet(number,char('A'+i));

			players[i]->generateBet();
			cout <<"Player "<<players[i]->getName()<<" -> Betted: "<<players[i]->getBet()<<endl;

			players[i]->updateBets(result);//updates the bets list by the given result

		}



   	}
	cout<<endl<<"_________No more Spins_________"<<endl;
	int earnings = 0;//to store each players earnings
	cout<<endl<<endl <<"SUMMARY: "<<endl<<endl;
	for (int i = 0; i < 6; i++ ){
			cout<<"Player "<<players[i]->getName()<<" BALANCE: "<< players[i]->getEarnings()<<endl;
			earnings += players[i]->getEarnings();

		}

	cout<<endl<<endl <<"GROUP BALANCE: "<< earnings<<endl;
    return 0;
}
