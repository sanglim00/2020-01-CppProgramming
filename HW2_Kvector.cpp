//Kvector 만들기
//Kvector class 의 멤버 함수들을 class 외부에 구현하라.
//(1) 생성자 Kvector(int sz, int value) : sz 개의 정수 배열을 m 에 할당받아 모든 원소의 값을 value 로 초기화한다.
//sz 가 0인 경우는 m 은 NULL 이 된다.
//(2) 깊은 복사를 구현하는 복사 생성자

#include <iostream>

using namespace std;

class Kvector {
private :
	int* m;
	int len;
public :
	Kvector(int sz = 0, int value = 0);
	Kvector(Kvector& v);
	~Kvector();
	void print();
	void clear();
	int size();
};
Kvector::Kvector(int sz = 0, int value = 0) {
	len = sz;
	if (sz == 0) m = NULL;
	else if(sz>0){
		m = new int[sz];
		for (int i = 0; i < sizeof(m); i++) m[i] = value;
	}
	cout << this << " : Kvector(int) \n";
}
Kvector::Kvector(Kvector& v) {
	len = v.size();
	m = new int[len];
	for (int i = 0; i < sizeof(m); i++) m[i] = v.m[i];
	cout << this << " : Kvector(Kvector&) \n";
}
Kvector::~Kvector() {
	cout << this << " : ~Kvector() \n";
	delete[] m;
}
void Kvector::print() {
	for (int i = 0; i < len; i++) cout << m[i] << " ";
	cout << endl;
}
void Kvector::clear() {
	delete[] m;
	m = NULL;
	len = 0;
}
int Kvector::size() {
	return len;
}

int main() {
	Kvector v1(3); v1.print();
	Kvector v2(2, 9); v2.print();
	Kvector v3(v2); v3.print();

	v2.clear();
	v2.print();
	v3.print();
	return 0;
}