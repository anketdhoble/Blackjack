/*
 * deck.h
 *
 *  Created on: 10-Mar-2019
 *      Author: Anket
 */

#ifndef DECK_H_
#define DECK_H_
#include <string>
#include "defineCard.h"
using namespace std;

class deck
{
	std::string faces[13]={"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	std::string suits[4] = { "Diamonds", "Clubs", "Hearts", "Spades" };
	//std::string Status[3] = { "In Play", "In Deck", "Discard Pile" };
	int CardValue[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };


public:
	virtual ~deck()
	{

	}
	static int cardCount;
	deck();
	void orignalDeck();
	void shuffleDeck() const;
	string getFace(const int &);
	string getSuit(const int &);
	int getCardValue(const int &);
	void setcardCount();
	int getcardCount() const;

	virtual void addCard() = 0;
	virtual void printCard() const= 0;
	virtual void setTotalSum(const int &) = 0;
	virtual int getTotalSum() const= 0;
	virtual void setHandSize() = 0;
	virtual int getHandSize() const=0;
	virtual void validate() =0;
};




#endif /* DECK_H_ */
