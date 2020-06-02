#include <iostream>

#ifndef __KVECTOR__
#define __KVECTOR__

using namespace std;

class Kvector {
protected:
	int* m;
	int len;
public:
	static int total_len;
	Kvector(int, int);
	Kvector(const Kvector& v);
	virtual ~Kvector();
	virtual void print() const;
	void clear();
	int size();
	Kvector& operator= (const Kvector&);
	friend bool operator==(Kvector&, Kvector&);
	friend bool operator!=(Kvector&, Kvector&);
	int& operator[] (int);
	friend ostream& operator<< (ostream&, Kvector&);
};

#endif