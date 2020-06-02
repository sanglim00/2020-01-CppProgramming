#include <iostream>
#include "Avector.h"

using namespace std;

Avector::Avector(int sz, int v, const char* t) :Kvector(sz, v) {
	cout << this << " : Avector (" << sz << ", " << v << ", " << t << ")"<<endl;
	for(int i =0; i<N; i++) table[i] = t[i];
}
void Avector::setTable(const char* t) {
	for (int i = 0; i < N; i++) table[i] = t[i];
}
void Avector::print() const {
	cout << "Avector with table " << table << endl;
	for (int i = 0; i < len; i++) cout << m[i] << " ";
	cout << endl;
}
ostream& operator<< (ostream& os, const Avector& v) {
	for (int i = 0; i < v.len; i++) os << v.table[v.m[i] % N] << " ";
	return os;
}
