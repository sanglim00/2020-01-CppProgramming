/* **************************
Problem : 소수
20191584 남상림
****************************/

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
int main() {
	int times, num;

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> num;
		if (isPrime(num))
			cout << 1 << endl;
		else
			cout << 0 << endl;
		
	}
}