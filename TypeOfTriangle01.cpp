/* **************************
Problem : 삼각형의 종류 01
20191584 남상림
****************************/
#include <iostream>

using namespace std;

int main() {
	int times;
	int a, b, c;

	cin >> times;
	for (int i = 0; i < times; i++) {

		cin >> a >> b >> c;
		if (a + b <= c)
			cout << 0 << endl;
		else if (a == b && a== c && b==c)
			cout << 1 << endl;
		else if (a * a + b * b == c * c)
			cout << 2 << endl;
		else if ((a == b && a!=c && b!=c) || (b == c && b!=a &&c!= a))
			cout << 3 << endl;
		else
			cout << 4 << endl;
	}
}