#ifndef __WD_MINEDITDIST_H__
#define __WD_MINEDITDIST_H__
#include <string>
#include <iostream>
using namespace std;

class MinEditDist
{
public:
	MinEditDist(){}
	int editDistance(const std::string &lhs, const std::string &rhs);

private:
	int nBytesCode(const char ch);
	int length(const string & str);
	int triple_min(const int &a, const int &b, const int &c);
};


#endif