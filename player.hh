
#ifndef PLAYERDB_PLAYER_HH
#define PLAYERDB_PLAYER_HH
#include <list>

using namespace std;

//class for each player
class Player{
private:
	char name;
	int earnings;
	list<int> *bets;
	int bet;


public:
	//Constructor
	Player(char theName);
	//Destructor
	~Player();


	//Get from class
	char getName();

	int getBet();

	int getEarnings();


	//Bets functions
	void checkBets();

	void createBets();

	void regenBets();

	void generateBet ();

	void updateBets(int result);

};


#endif
