/*
 * dealer.cpp
 *
 *  Created on: 11-Mar-2019
 *      Author: Anket
 */

#ifndef DEALER_CPP_
#define DEALER_CPP_

#include <iostream>
#include <string>
#include "dealer.h"
using namespace std;

defineCard dealers[5];

void dealer::addCard()
{
	cardNumber=getcardCount();
	face=getFace(cardNumber);
	suit=getSuit(cardNumber);
	cardValue=getCardValue(cardNumber);
	dealers[handSize].face=face;
	dealers[handSize].suit=suit;
	dealers[handSize].pointsValue=cardValue;
	setTotalSum(cardValue);
	setcardCount();
	setHandSize();
	//cout<<"111111111111111111111CArd Number : "<<getcardCount()<<endl;
}
void dealer::validate()
{

	if(getHandSize()==0)
	{
		addCard();
		addCard();
	}
	else if(getTotalSum() < 21 &&  getHandSize() < 5  )
	{
//		printCard();
		cout<<"The bank draws a card... \n"<<endl;
		addCard();
		printCard();
	}
//	else if(getTotalSum() == 21)
//	{
//		cout<<"value is 21";
//	}
//	else if(getTotalSum() > 21)
//	{
//		cout<<"you are burst";
//	}
}
void dealer::printCard() const
{
	cout<<"Bank hand is :\n"<<endl;

	for(int i=0;i<handSize;i++)
	{
		cout<<dealers[i].face<<" of "<<dealers[i].suit<<endl;
	}
	cout<<"Value = "<<getTotalSum()<<endl;
	cout<<"\n";
}
void dealer::setTotalSum(const int &totalSum)
{
	handSum+=totalSum;
}
int dealer::getTotalSum() const
{
	return handSum;
}
void dealer::setHandSize()
{
	handSize++;
}
int dealer::getHandSize() const
{
	return handSize;
}




#endif /* DEALER_CPP_ */
