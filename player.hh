
#ifndef PLAYERDB_PLAYER_HH
#define PLAYERDB_PLAYER_HH
#include <list>

using namespace std;

class Player{
//private:
	char name;
	int earnings;
	list<int> *bets;
	int bet;


public:
	Player(char theName);

	~Player();

	char getName();

	int getBet();

	int getEarnings();

	void checkBets();

	int lenToZero();

	void createBets();

	void regenBets();

	void generateBet ();

	void updateBets(int result);

	int endResult(int* players);
};


#endif
