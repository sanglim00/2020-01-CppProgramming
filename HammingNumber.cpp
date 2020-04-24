/* **************************
Problem : 해밍수
20191584 남상림
****************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void Hamming(int num) {
	vector<long int> hamming;

	for (int i = 0; i < 30; i++) {
		hamming.push_back(pow(2, i));
		for (int j = 0; j < 19; j++) {
			hamming.push_back(pow(3, j));
			for (int k = 0; k < 13; k++) {
				hamming.push_back(pow(5, k));
				hamming.push_back(pow(2, i)*pow(3, j)* pow(5, k));
			}
		}
	}
	sort(hamming.begin(), hamming.end());
	hamming.erase(unique(hamming.begin(), hamming.end()), hamming.end());

	cout << hamming[num] << endl;

}
int main() {
	int times, num;
	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> num;
		Hamming(num);
	}
	return 0;
}
