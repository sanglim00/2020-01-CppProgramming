//실습: Kvector class 에(1)=, (2) == , (3) != , (4)[], (5) << 연산자들을 class 외부에 구현하라.
//(1) = 대입 연산자는 깊은 복사로 구현해야 한다.
//(2) 연산 결과는 0 혹은 1이다.
//(3) == 연산자를 호출하여 구현해야 한다.
//(4) v[1] = 10; 과 같이 v[1] 가 대입 연산자의 LHS 에 사용될 수 있어야 한다.
//(5) cout << v << w 의 형태로 사용될 수 있어야 한다.

#include <iostream>
#include <ostream>
#include <cassert>

using namespace std;

class Kvector {
private:
	int* m;
	int len;
public:
	static int total_len;
	Kvector(int sz = 0, int value = 0) ;
	Kvector(const Kvector& v) ;
	~Kvector();
	void print();
	void print() const;
	void clear();
	int size();
	Kvector& operator= (Kvector&);
	friend bool operator==(Kvector& , Kvector& );
	friend bool operator!=(Kvector& , Kvector& );
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
bool operator!=(Kvector& a, Kvector& b){
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

int main() {
	Kvector v1(3); v1.print();
	Kvector v2(2, 9); v2.print();
	Kvector v3(v2); v3.print();
	cout << (v1 == v2) << endl;
	cout << (v3 == v2) << endl;
	v3 = v2 = v1;
	cout << v1 << endl;
	cout << v2 << endl;
	cout << v3 << endl;
	cout << (v3 != v2) << endl;
	v1[2] = 2;
	v2[0] = v1[2];
	cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
	return 0;
}