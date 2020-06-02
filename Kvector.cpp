#include <iostream>
#include "Kvector.h"
#include <cassert>

using namespace std;

Kvector::Kvector(int sz = 0, int value = 0) : len(sz) {
	cout << this << " : Kvector (" << sz << ", " << value << ")" << endl;
	if (!sz) { m = NULL; return; }
	m = new int[sz];
	for (int i = 0; i < sz; i++)m[i] = value;
}
Kvector::Kvector(const Kvector& v) {
	cout << this << " : Kvector (*" << &v << ")" << endl;
	len = v.len;
	if (!len) { m = NULL; return; }
	m = new int[len];
	for (int i = 0; i < len; i++) m[i] = v.m[i];
}
Kvector::~Kvector() {
	cout << this << " : ~Kvector() \n";
	delete[] m;
}

void Kvector::print() const {
	for (int i = 0; i < len; i++) cout << m[i] << " ";
	cout << '\n';
}

int Kvector::size() { return len; }

Kvector& Kvector::operator= (const Kvector& v) {
	cout << "Kvector :: operator= " << &v << endl;
	delete[] m;
	m = new int[len];
	for (int i = 0; i < len; i++)m[i] = v.m[i];
	return *this;
}
bool operator==(Kvector& a, Kvector& b) {
	if (a.len != b.len) return false;
	for (int i = 0; i < a.len; i++) 
		if (a.m[i] != b.m[i]) return false;
	return true;
}
bool operator!=(Kvector& a, Kvector& b) {
	return !(a == b);
}

int& Kvector::operator[](int idx) {
	assert(0 <= idx && idx < size());
	return m[idx];
}

ostream& operator<<(ostream& os, Kvector& v) {
	for (int i = 0; i < v.len; i++) os << v.m[i] << " ";
	return os;
}

int Kvector::total_len = 0;

void Kvector::clear() {
	delete[] m;
	m = NULL;
	len = 0;
}