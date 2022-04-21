#include <cstdlib>
#include <ctime>
#include <iostream>
#include "player.hh"


using namespace std;

int colors[37] = {-1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0};

//colors is an array that represents the color of a number in a roulette
//red is represented with a 1, black with 0 and green with -1

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
   }
   return result;
}


int main()
{
    srand((unsigned)time(0));

	Player *players[6];// =new Player(6); 

	for (int i = 0; i < 6; i++ ){
		players[i] = new Player(char('A'+i));//from A to F
	}
	//cout << players[5].getName() <<endl;

	
    int number;
	int result;


   	for (int i = 0; i<= 4; i++){
		number = (rand()%37);//generate a number between 0 and 36
     	cout <<"salio" <<number << endl;
		for (int i = 0; i < 6; i++ ){
			result = computeBet(number,char('A'+i));
			cout<<"result: "<< result<<endl;

			players[i]->generateBet();
			cout <<players[i]->getName()<<" Betted: "<<players[i]->getBet()<<endl;

			players[i]->updateBets(result);// this gens seg fault

		}
		cout << endl<<endl;

		
   	}
	
	int earnings = 0;
	for (int i = 0; i < 6; i++ ){
			
			earnings += players[i]->getEarnings();
			
		}
	//cout << colors[30]<<endl;
	cout<<endl<<endl <<"global earnings: "<< earnings<<endl;
    return 0;
}
