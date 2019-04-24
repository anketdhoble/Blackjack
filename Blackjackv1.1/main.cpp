/*
 * main.cpp
 *
 *  Created on: 17-Mar-2019
 *      Author: Anket
 */

#include<iostream>
//#include <conio.h>
#include "player.h"
#include "dealer.h"
#include "log.h"
#include <vector>
using namespace std;

int main()
{
	//int cout=0;
	int rounds=0;
	int won=0;
	int lost=0;
	vector<string> roundStatus;
	string playgame;
	string in;
	string status;
	string dCheck;

	do
	{
		system("CLS");
	player p;
	//dealer d;
	log l;
	l.cardCount=0;
	rounds++;
	if(rounds==1)
	{
		l.setStartTime();
	}
	p.validate();
	l.validate();
	do
	{
		cout<<"\n[s]tick or [t]wist?";
		cin>>in;
		if(in=="s" || in=="t")
		{
			break;
		}
		else
		{
			cout<<"\nEntered choice is invalid\n";
		}
	}while(1);
	cout<<endl;

	if(in == "t")
	{
		do
		{
			p.validate();
			if(p.getTotalSum()>21 || p.getHandSize()==6)
			{
				cout<<"BUST!!\n";
				status="bust";
				roundStatus.push_back("Lost");
				lost++;
				break;
			}
			else
			{
				do
				{
					cout<<"\n[s]tick or [t]wist?";
					cin>>in;
					if(in=="s" || in=="t")
					{
						break;
					}
					else
					{
						cout<<"\nEntered choice is invalid\n";
					}
				}while(1);
				cout<<endl;
			}

		}while(in == "t");
	}


	if(status=="bust")
	{
		cout<<"\nBad luck, the bank won\n";
	}
	else
	{
		l.printCard();
		do{



			if(l.getTotalSum()>21 || l.getHandSize()==5)
			{
				cout<<"\nWell done, you won!!!\n";
				roundStatus.push_back("Won");
				//status="burst";
				won++;
				break;
			}
			else
			{
				if(p.getTotalSum() > l.getTotalSum())
				{
					dCheck="true";
					l.validate();
				}
				else if(p.getTotalSum()==l.getTotalSum() && l.getTotalSum()>10)
				{
					if(p.getHandSize()>=l.getHandSize())
					{
						cout<<"Well done, you won!!!\n";
						dCheck="false";
						roundStatus.push_back("Won");
						won++;
						break;
					}
					else
					{
						cout<<"Better luck next time !!\n";
						dCheck="false";
						roundStatus.push_back("Lost");
						lost++;
						break;
					}
				}
				else if(p.getTotalSum()==l.getTotalSum() && l.getTotalSum()<=10)
				{
					dCheck="true";
					l.validate();
				}
				else
				{
					cout<<"\n\nBetter Luck next time!!";
					dCheck="false";
					roundStatus.push_back("Lost");
					lost++;
					break;
				}
			}


		}while(dCheck=="true");

	}
//	cout<<"\ndo you want to play again ([y]es/[n]o)?";
//	cin>>playgame;

		do{
			//cout<<"\nEntered choice is invalid\n";
			cout<<"\ndo you want to play again ([y]es/[n]o)?";
			cin>>playgame;
			if(playgame=="y" || playgame=="n")
			{
				break;
			}
			else
			{
				cout<<"\nEntered choice is invalid\n";
			}

		}while(1);



	status="";


	if(playgame=="n")
	{
		l.setEndTime();
		l.setData(rounds,won,lost,roundStatus);
		l.printLog();
		cout<<"Thanks, Bye!!";
	}
	//cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	//cout<<"card count"<<l.getcardCount();

	}while(playgame=="y");




//system("PAUSE");

}

