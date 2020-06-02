#include <iostream>
#include "Kvector.h"

using namespace std;

#define N 3
class Avector : public Kvector {
	char table[N];
public:
	Avector(int, int, const char*);
	void setTable(const char* t);
	void print() const;
	friend ostream& operator<<(ostream& os, const Avector& v);
};