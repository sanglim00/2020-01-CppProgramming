/* **************************
Problem : 해밍 코드
20191584 남상림
****************************/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[32];

void to_bin(int n) {
	for (int i = 31; i >= 0; i--) {
		if (i == 31 || i == 30 || i == 28 || i == 24 || i == 16) {
			arr[i] = NULL;
		}
		else {
			arr[i] = n % 2;
			n /= 2;
		}
	}
}
void to_dec(int* arr) {
	int n = 1;
	unsigned int sum = 0;
	for (int i = 31; i >= 0; i--) {
		if (arr[i] == 1) sum += n;
		n *= 2;
	}
	cout << sum << endl;
}

void getEncodedValue(int* arr) {
	int cnt = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0;
	
	//p1
	for (int i = 31; i > 0; i -= 2) {
		if (arr[i] == 1)cnt += 1;
	}
	//p2
	for (int i = 30; i >= 0; i -= 4) {
		if (arr[i] == 1)cnt2 += 1;
		if (arr[i - 1] == 1)cnt2 += 1;
	}
	//p3
	for (int i = 28; i > 0; i -= 8) {
		if (arr[i] == 1)cnt3 += 1;
		if (arr[i-1] == 1)cnt3 += 1;
		if (arr[i-2] == 1)cnt3 += 1;
		if (arr[i-3] == 1)cnt3 += 1;
	}
	//p4
	for (int i = 24; i > 16; i--) {
		if (arr[i] == 1) cnt4 += 1;
	}
	for (int i = 8; i > 0; i--) {
		if (arr[i] == 1)cnt4 += 1;
	}
	//p5
	for (int i = 16; i > 0; i--) {
		if (arr[i] == 1)cnt5 += 1;
	}

	if (cnt % 2 == 1) arr[31] = 1;
	else arr[31] = 0;
	if (cnt2 % 2 == 1) arr[30] = 1;
	else arr[30] = 0;
	if (cnt3 % 2 == 1) arr[28] = 1;
	else arr[28] = 0;
	if (cnt4 % 2 == 1) arr[24] = 1;
	else arr[24] = 0;
	if (cnt5 % 2 == 1) arr[16] = 1;
	else arr[16] = 0;
	
	to_dec(arr);
}
void getDecodedeValue() {

}

int main() {
	int times;
	int k, num;

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> k >> num;

		to_bin(num);
		
		if (k == 0) getEncodedValue(arr);
		else if (k == 1) getDecodedeValue();
	}
}