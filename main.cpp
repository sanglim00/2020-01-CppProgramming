#include <iostream>
#include "Avector.h"
#include "Bvector.h"

using namespace std;

int main(int argc, char* argv[]) {
	Avector a1(7, 4, "stu");
	Avector a2(a1);
	cout << "a1 == a2 " << (a1 == a2) << endl;
	a1[0] = 0;
	a2[1] = 5;
	a2.setTable("ijk");
	a1.print();
	a2.print();
	cout << "a1.size() : " << a1.size() << endl;
	cout << "a2.size() : " << a2.size() << endl;
	cout << "a1 : " << a1 << endl;
	cout << "a2 : " << a2 << endl;
	a1.clear();
	a1.print();
	cout << "a1.size() : " << a1.size() << endl;
	cout << "a1 : " << a1 << endl;
	a1 = a2;
	a1.print();
	cout << "a1.size() : " << a1.size() << endl;
	cout << "a1 : " << a1 << endl;
}