/*
 * dealer.h
 *
 *  Created on: 11-Mar-2019
 *      Author: Anket
 */

#ifndef DEALER_H_
#define DEALER_H_
#include "deck.h"

class dealer:public deck
{
	int handSize=0;
	int handSum=0;
	string face;
	string suit;
	int cardNumber=0;
	int cardValue;

public:
	virtual ~dealer()
	{

	}
	virtual void addCard() override ;
	virtual void printCard() const override ;
	virtual void setTotalSum(const int &) override ;
	virtual int getTotalSum() const override;
	virtual void setHandSize() override;
	virtual int getHandSize() const override;
	virtual void validate() override;
};




#endif /* DEALER_H_ */
