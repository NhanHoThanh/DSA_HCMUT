#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <iostream>
#include <string>
#include <math.h>

using namespace std;
extern int MAXSIZE;

class Restaurant
{

public:
	Restaurant(){};
	~Restaurant(){};
	virtual void RED(string name, int energy) = 0;
	virtual void BLUE(int num) = 0;
	virtual void PURPLE() = 0;
	virtual void REVERSAL() = 0;
	virtual void UNLIMITED_VOID() = 0;
	virtual void DOMAIN_EXPANSION() = 0;
	virtual void LIGHT(int num) = 0;

public:
	class customer
	{
	public:
		string name;
		int energy;
		customer *prev;
		customer *next;

	public:
		customer() {}
		customer(string na, int e, customer *p, customer *ne) : name(na), energy(e), prev(p), next(ne) {}
		void print()
		{
			cout << name << "-" << energy << endl;
		}
	};
};
#endif