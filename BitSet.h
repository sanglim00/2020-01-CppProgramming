#include <iostream>
#include "Bvector.h"

using namespace std;

class IncompatibleException : public exception {
public:
	int sz1, sz2;
	IncompatibleException(int sz1, int sz2):sz1(sz1), sz2(sz2){}
};

class BitSet : public Bvector {
public :
	BitSet(int sz = 32);
	void insert(int v);
	friend BitSet operator+ (const BitSet& v1, const BitSet& v2);
	friend ostream& operator<< (ostream& os, const BitSet& s);
};