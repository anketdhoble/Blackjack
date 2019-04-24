/*
 * player.cpp
 *
 *  Created on: 11-Mar-2019
 *      Author: Anket
 */

#include <iostream>
#include <string>
#include "player.h"
using namespace std;

defineCard players[5];


void player::addCard()
{

	cardNumber=getcardCount();
	face=getFace(cardNumber);
	suit=getSuit(cardNumber);
	cardValue=getCardValue(cardNumber);
	players[handSize].face=face;
	players[handSize].suit=suit;
	players[handSize].pointsValue=cardValue;
	setTotalSum(cardValue);
	setcardCount();
	setHandSize();
	//cout<<"111111111111111111111CArd Number : "<<getcardCount()<<endl;
	//printCard();
}
void player::validate()
{

		if(getHandSize()==0)
		{
			addCard();
			addCard();
			printCard();
		}
		else if(getTotalSum() <= 21  )
		{
			addCard();
			printCard();
		}
//		else if(getTotalSum() == 21)
//		{
//			cout<<"value is 21";
//
//		}
//		else if(getTotalSum() > 21)
//		{
//			cout<<"you are burst";
//		}
}
void player::printCard() const
{
	cout<<"\nYour hand is :\n"<<endl;
	for(int i=0;i<handSize;i++)
	{
		cout<<players[i].face<<" of "<<players[i].suit<<endl;
	}
	cout<<"Value = "<<getTotalSum()<<endl;
}
void player::setTotalSum(const int &totalSum)
{
	handSum+=totalSum;
}
int player::getTotalSum() const
{
	return handSum;
}
void player::setHandSize()
{
	handSize++;
}
int player::getHandSize() const
{
	return handSize;
}


