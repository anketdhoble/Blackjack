/*
 * log.cpp
 *
 *  Created on: 19-Mar-2019
 *      Author: Anket
 */
#include <iostream>
#include <fstream>
#include <time.h>
#include "log.h"
using namespace std;


void log::setData(const int &round,const int &won,const int &lost,vector<string> &roundStatus)
{
	ofstream myfile;
	myfile.open("Pontoon_Log.txt",ios::app);
	 if (myfile.is_open())
	  {
	    myfile << "Rounds: "<<round<<"\n";
	    myfile << "Won:"<<won<<"\n";
	    myfile << "Lost: "<<lost<<"\n";
	    myfile <<"--\n";
	    for(size_t i=0;i<roundStatus.size();i++)
	    {
	    	 myfile << "Round"<<i+1<<":"<<roundStatus[i]<<"\n";
	    }

	    myfile.close();
	  }
	  else cout << "Unable to open file";
}

void log::setStartTime() const
{
	 time_t rawtime;
	  struct tm * timeinfo;

	  time (&rawtime);
	  timeinfo = localtime (&rawtime);
	 // printf ("Current local time and date: %s", asctime(timeinfo));
	ofstream myfile;
		myfile.open("Pontoon_Log.txt",ios::trunc);
		 if (myfile.is_open())
		  {
			 myfile << "Game started at:"<< asctime(timeinfo);
		  }
		 else
			 cout << "Unable to open file";
}
void log::setEndTime() const
{
	time_t rawtime;
	struct tm * timeinfo;

	time (&rawtime);
	timeinfo = localtime (&rawtime);
	// printf ("Current local time and date: %s", asctime(timeinfo));
	ofstream myfile;
	myfile.open("Pontoon_Log.txt",ios::app);
	if (myfile.is_open())
	{
		myfile << "Game finished at:" << asctime(timeinfo);
	}
	else
		cout << "Unable to open file";
}
void log::printLog() const
{
	string line;
	  ifstream myfile ("Pontoon_Log.txt");
	  if (myfile.is_open())
	  {
	    while ( getline (myfile,line) )
	    {
	      cout << line << '\n';
	    }
	    myfile.close();
	  }

	  else cout << "Unable to open file";
}
