/*
 * log.h
 *
 *  Created on: 19-Mar-2019
 *      Author: Anket
 */

#ifndef LOG_H_
#define LOG_H_
#include "dealer.h"
#include <vector>

class log:public dealer
{
public:
//	virtual ~log()
//	{
//
//	}
	void setData(const int &,const int &,const int &,vector<string> &);
	void showData() const;
	void setStartTime() const;
	void setEndTime() const;
    void printLog() const;

};




#endif /* LOG_H_ */
