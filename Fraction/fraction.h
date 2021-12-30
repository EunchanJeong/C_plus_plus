#include <iostream>

using namespace std;

#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
	// data members
	private:
		int numer;
		int denom;

	// public member functions
	public:
		// constructors
		Fraction(int num, int den);
		Fraction();
		Fraction(const Fraction& fract);
		~Fraction();

		// Accessors
		int getNumber() const;
		int getDenom() const;
		void print() const;

		// Mutators
		void setNumer(int num);
		void setDenom(int den);

		// Helping private memver functions
	private:
		void normalize();
		int gcd(int n, int m);
};
#endif
