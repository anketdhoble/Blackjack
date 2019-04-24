/*
 * deck.cpp
 *
 *  Created on: 10-Mar-2019
 *      Author: Anket
 */
#include <iostream>
#include <string>
#include <ctime>
#include "deck.h"
using namespace std;

defineCard Deck[53];

int deck::cardCount=0;

deck::deck()
{
	orignalDeck();
	shuffleDeck();

}

void deck::orignalDeck()
{
	int New_Suit=0;
		for (int x = 0; x < 52; x++)
		{

			Deck[x].face = faces[x % 13];
			Deck[x].suit = suits[New_Suit];
			Deck[x].pointsValue = CardValue[x % 13];
			//Deck[x].cardStatus = 1;
			if ((x + 1) % 13 == 0) //it is used to change the suit after the 13 cards of each suit
			{
				New_Suit++;
			}
		}
		//cout << "Straight deck of cards.." << endl << endl;
		for (int x = 0; x < 52; x ++)
		{
			//cout << Deck[x].face << " of " << Deck[x].suit << "   " << Deck[x + 1].face << " of " << Deck[x + 1].suit << "  " << Deck[x + 2].face << " of " << Deck[x + 2].suit << "   " << Deck[x + 3].face << " of " << Deck[x + 3].suit << endl;
			//cout << Deck[x].face << " of " << Deck[x].suit << " : Value of " << Deck[x].pointsValue << " : " << Status[Deck[x].cardStatus] << endl;
		}

}

void deck::shuffleDeck() const
{
	srand(time(0));
	for (int x = 0; x < 600; x++)
			{

				int a = (rand() % 52)+1;
				//cout<<"---------------a="<<a<<endl;

				int b = (rand() % 52)+1;
				//cout<<"---------------b="<<b<<endl;

				Deck[52].face = Deck[a].face;
				Deck[52].suit = Deck[a].suit;
				Deck[52].pointsValue = Deck[a].pointsValue;
				//Deck[52].cardStatus = Deck[a].cardStatus;

				Deck[a].face = Deck[b].face;
				Deck[a].suit = Deck[b].suit;
				Deck[a].pointsValue = Deck[b].pointsValue;
				//Deck[a].cardStatus = Deck[b].cardStatus;

				Deck[b].face = Deck[52].face;
				Deck[b].suit = Deck[52].suit;
				Deck[b].pointsValue = Deck[52].pointsValue;
				//Deck[b].cardStatus = Deck[52].cardStatus;
			}

			//cout << endl << "Shuffled deck of cards.." << endl << endl;

			for (int x = 0; x < 52; x ++)
			{
				//cout << Deck[x].face << " of " << Deck[x].suit << "   " << Deck[x + 1].face << " of " << Deck[x + 1].suit << "   " << Deck[x + 2].face << " of " << Deck[x + 2].suit << "   " << Deck[x + 3].face << " of " << Deck[x + 3].suit << endl;
				//cout << Deck[x].face << " of " << Deck[x].suit << " : Value of " << Deck[x].pointsValue << " : " << Status[Deck[x].cardStatus] << endl;
			}
}

string deck::getFace(const int &cardNumber)
{
	return Deck[cardNumber].face;
}

string deck::getSuit(const int &cardNumber)
{
	return Deck[cardNumber].suit;
}
int deck::getCardValue(const int &cardNumber)
{
	return Deck[cardNumber].pointsValue;
}

void deck::setcardCount()
{
	cardCount+=1;
}
int deck::getcardCount() const
{
	return cardCount;
}

