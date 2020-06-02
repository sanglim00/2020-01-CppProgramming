#include <iostream>
#include "Kvector.h"

class Bvector : public Kvector {
protected:
	unsigned int* u_m;
	const int NBITS;
public:
	Bvector(int nbits = 32);
	Bvector(const Bvector& e);
	bool bit(int pos) const;
	void set(int pos);
	void reset(int pos);
	int size()const { return NBITS; }
	void clear() { for (int i = 0; i < len; i++) m[i] = 0; }
	void print() const;
	bool operator[] (int idx) const { return bit(idx); }
	Bvector& operator=(const Bvector& v);
	friend ostream& operator<< (ostream& os, const Bvector& v);
};