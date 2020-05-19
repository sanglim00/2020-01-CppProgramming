/* **************************
Problem : IPv4주소변환
20191584 남상림
****************************/
#include <iostream>
#include <string>

using namespace std;
int arr[32];
int Ar[32];

void to_bin() {
	unsigned int n;
	cin >> n;
	for (int i = 31; i >= 0; i--) {
		arr[i] = n % 2;
		n /= 2;
	}
}

void to_dec(int* arr) {
	unsigned int n = 1, sum =0;
	for (int i = 31; i >= 0; i--) {
		if (arr[i] == 1) sum += n;
		n *= 2;
	}
	cout << sum << endl;
}
void to_32bit(string str) {
	size_t sz;
	int a = stoi(str, &sz);
	for (int i = 7; i>=0 ; i--) {
		Ar[i] = a % 2;
		a /= 2;
	}
	str = str.substr(sz + 1);
	int b = stoi(str, &sz);
	for (int i = 15; i >=8; i--) {
		Ar[i] = b % 2;
		b /= 2;
	}
	str = str.substr(sz + 1);
	int c = stoi(str, &sz);
	for (int i = 23; i>=16; i--) {
		Ar[i] = c % 2;
		c /= 2;
	}
	str = str.substr(sz + 1);
	int d = stoi(str, &sz);
	for (int i = 31; i >=24; i--) {
		Ar[i] = d % 2;
		d /= 2;
	}
	to_dec(Ar);
}

void to_IPv4() {
	unsigned int n = 1;
	unsigned int sum = 0, sum2 = 0, sum3 = 0, sum4 = 0;
	for (int i = 7; i >=0; i--) {
		if (arr[i] == 1) sum += n;
		n *= 2;
	}
	n = 1;
	for (int i = 15; i >= 8; i--) {
		if (arr[i] == 1) sum2 += n;
		n *= 2;
	}
	n = 1;
	for (int i = 23; i >= 16; i--) {
		if (arr[i] == 1) sum3 += n;
		n *= 2;
	}
	n = 1;
	for (int i = 31; i >= 24; i--) {
		if (arr[i] == 1) sum4 += n;
		n *= 2;
	}
	cout << sum << '.' << sum2 << '.' << sum3 << '.' << sum4 << endl;
}

int main() {
	int times, k;
	string str;

	cin >> times;
	for (int i = 0; i < times; i++) {

		cin >> k ;
		if (k == 1) {
			cin >> str;
			to_32bit(str);
		}
		else if (k == 2) { 
			to_bin();
			to_IPv4();
		}
	}
}
