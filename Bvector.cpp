#include <iostream>
#include "Bvector.h"

using namespace std;

Bvector::Bvector(int nbits) : Kvector((nbits + 31) / 32, 0), NBITS(nbits) {
	cout << this << " : Bvector (" << nbits << ")" << endl;
	u_m = (unsigned int*)m;		//bitwise 연산자 사용 하려면 unsigned type으로
}
Bvector::Bvector(const Bvector& e) : Kvector(e), NBITS(e.NBITS) {
	cout << this << " : Bvector (*" << &e << ")" << endl;
	u_m = (unsigned int*)m;
}
Bvector& Bvector::operator=(const Bvector& v) {
	cout << "Bvector :: operator= " << &v << endl;
	if (NBITS == v.NBITS) {	//크기가 다르면 치환이 일어나지 않는다
		for (int i = 0; i < len; i++) m[i] = v.m[i];		//bit단위로 복사하는것보다  훨씬 빠르다
	}
	return *this;
}
void Bvector::print() const {	//Kvector의 virtual function
	cout << "Bvector with " << NBITS << " bits" << endl;
	for (int i = 0; i < NBITS; i++) cout << bit(i) << " ";
	cout << endl;
}
ostream& operator<<(ostream& os, const Bvector& v) {
	for (int i = 0; i < v.NBITS; i++) os << v.bit(i) << " ";
	return os;
}
bool Bvector :: bit(int pos) const {
	if (pos >= NBITS) return false;
	unsigned int element = u_m[pos / 32];
	int pos_bit = pos % 32;
	unsigned int mask = 1 << pos_bit;
	int value = element & mask;
	return value;		//value == 0이면 false, 아니면 true를 return
}
void Bvector::reset(int pos) {
	if (pos >= NBITS) return ;
	unsigned int &element = u_m[pos / 32];
	int pos_bit = pos % 32;
	unsigned int mask = 1 << pos_bit;
	mask = ~mask;
	element &= mask;
}
void Bvector::set(int pos) {
	if (pos >= NBITS) return;
	unsigned int& element = u_m[pos / 32];
	int pos_bit = pos % 32;
	unsigned int mask = 1 << pos_bit;
	element |= mask;
}
