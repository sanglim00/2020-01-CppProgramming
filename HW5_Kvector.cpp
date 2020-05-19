//20 inheritance ½Ç½À

#include <iostream>
#include <ostream>
#include <cassert>

using namespace std;

class Kvector {
protected:
	int* m;
	int len;
public:
	static int total_len;
	Kvector(int sz = 0, int value = 0);
	Kvector(const Kvector& v);
	~Kvector();
	void print();
	void print() const;
	void clear();
	int size();
	Kvector& operator= (Kvector&);
	friend bool operator==(Kvector&, Kvector&);
	friend bool operator!=(Kvector&, Kvector&);
	int& operator[] (int);
	friend ostream& operator<< (ostream&, Kvector&);
};

Kvector& Kvector::operator= (Kvector& v) {
	if (&v != this) {
		delete[] m;
		len = v.len;
		m = new int[len];
		for (int i = 0; i < len; i++) m[i] = v.m[i];
	}
	return *this;
}
bool operator==(Kvector& a, Kvector& b) {
	if (a.len == b.len) {
		for (int i = 0; i < a.len; i++) {
			if (a.m[i] != b.m[i]) return false;
			else return true;
		}
	}
	else return false;

}
bool operator!=(Kvector& a, Kvector& b) {
	if (a.len == b.len) {
		for (int i = 0; i < a.len; i++) {
			if (a.m[i] == b.m[i]) return true;
			else return false;
		}
	}
	else return true;
}

int& Kvector::operator[](int idx) {
	assert(0 <= idx && idx < size());
	return m[idx];
}

ostream& operator<<(ostream& os, Kvector& v) {
	for (int i = 0; i < v.len; i++) os << v.m[i] << " ";
	return os;
}
Kvector::Kvector(int sz, int value) {
	total_len += sz;
	if (sz == 0) m = NULL;
	else {
		this->len = sz;
		m = new int[sz];
		for (int i = 0; i < sizeof(m); i++) m[i] = value;
	}
	cout << this << " : Kvector(int, int) \n";
}
Kvector::Kvector(const Kvector& v) {
	total_len += v.len;
	this->len = v.len;
	m = new int[len];
	for (int i = 0; i < len; i++) m[i] = v.m[i];
	cout << this << " : Kvector(Kvector&) \n";
}
Kvector::~Kvector() {
	total_len -= this->len;
	cout << this << " : ~Kvector() \n";
	delete[] m;
}
int Kvector::total_len = 0;

void Kvector::print() {
	for (int i = 0; i < len; i++) cout << m[i] << " ";
	cout << '\n';
}
void Kvector::print() const {
	for (int i = 0; i < len; i++) cout << m[i] << " ";
	cout << '\n';
}

void Kvector::clear() {
	delete[] m;
	m = NULL;
	len = 0;
}
int Kvector::size() { return len; }

#define N 3
class Avector : public Kvector {
	char table[N];
public:
	Avector(int sz = 0, int v = 0, const char* t = "abc"):Kvector(sz, v) {
		cout << this << " : Avector (" << sz << "," << v << "," << t << ")" << endl;
		for (int i = 0; i < N; i++) table[i] = t[i];
	}
	void setTable(const char* t) {
		for (int i = 0; i < N; i++) table[i] = t[i];
	}
friend ostream& operator<<(ostream& os,const Avector& v);
};
ostream& operator<<(ostream& os, const Avector& v) {
	for (int i = 0; i < v.len; i++) os << v.table[v.m[i] % N] << " ";
	return os;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "usage : ./avctor pqr" << endl;
		return 1;
	}
	Avector v1(3); v1.print();
	Avector v2(2, 1, "xyz"); v2.print();
	Avector v3(v2); v3.print();

	cout << "v1 == v2 " << (v1 == v2) << endl;
	cout << "v3 == v2 " << (v3 == v2) << endl;
	v3 = v2 = v1;

	cout << "v1 = " << v1 << endl;
	v1.print();
	cout << "v2 = " << v2 << endl;
	v2.print();
	cout << "v3 = " << v3 << endl;
	v3.print();
	cout << "v3 != v2 " << (v3 != v2) << endl;

	v1[2] = 2;
	v2[0] = v1[2];
	v1.setTable(argv[1]);
	cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;

	v1.print();
	v2.print();
	v3.print();
	return 0;
}