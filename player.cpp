#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

#include "player.hh"


//create the player
Player::Player(char theName){
	name = theName;
	earnings = 0;
	bet = 0;
	bets = new list<int>();
	createBets();
}

Player::~Player(){
	delete bets;
}

char Player::getName(){
	return name;
}

int Player::getBet(){
	return bet;
}

int Player::getEarnings(){
	return earnings;
}

void Player::createBets(){
	for (int i = 1; i < 5; i++)
		bets->push_back(i);
}

void Player::regenBets(){
	bets->clear();
	createBets();
}

void Player::checkBets(){//checks if my list will be able to throw out a bet according to the exercise

	if (bets->size() == 0){//first to check so we don't get error accesing an element in bets
		regenBets();
	}
	if ((bets->size() == 1) && (bets->front() < 5)){//no way it get passed 4000 with only 1 elem
		regenBets();
	}

	if ((bets->front() + bets->back()) >= 4000){
		regenBets();
	}

}

void Player::generateBet(){//get the next bet according to the list size and the algorithm given
	checkBets();
	if (sizeof(bets) > 1){
		bet = bets->front() + bets->back(); //in case i win i have to add to my bet list what i last betted
	}
	else{
		bet = bets->front();
	}
}

void Player::updateBets(int result){//keep a track of your earnings depending of the bet and result of the roulette
	if (result){
		earnings += bet;
		cout<<"Player "<<name<<" ***WON***"<<endl<<endl;
		bets->push_back(bet);
		
	}
	else{//cut the first and laste elem of the list (incase bets has more than one element)
		earnings -= bet;
		cout<<"Player "<<name<<" ***LOST***"<<endl<<endl;
		if (bets->size() == 1){
			regenBets();
		}
		else{
			bets->pop_front();
			bets->pop_back();
		}
	}
}


