/* **************************
Problem : 패리티 비트
20191584 남상림
****************************/

#include <iostream>

using namespace std;

int arr[32];
unsigned int sum = 0;

void to_bin(int n) {
	for (int i = 31; i >= 0; i--) {
		arr[i] = n % 2;
		n /= 2;
	}
}
void to_dec(int *arr) {
	int n = 1;
	for (int i = 31; i >= 0; i--) {
		if (arr[i] == 1)
			sum += n;
		n *= 2;
	}
	cout << sum << endl;
}
int main() {
	int times, num;
	int count = 0;

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> num;
		to_bin(num);

		for (int j = 0; j < 32; j++) {
			if (arr[j] == 1)
				count += 1;
		}
		if (count % 2 == 1) {
			arr[0] = 1;
			to_dec(arr);
		}
		else
			cout << num << endl;
		count = 0;
	}
}