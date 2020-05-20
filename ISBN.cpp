/***************************
Problem : 국제 표준 도서번호
20191584 남상림
****************************/

#include <iostream>
#include <string>

using namespace std;

bool checkSum(string str, int cks) {
	bool ans;
	if (str[cks + 1] == 0) ans = true;
	else ans = false;

	int checj = isdigit(str[cks]) ? str[cks] - '0' : (str[cks] == 'X' ? 10 : -1);

	int sum = 0;
	for (int i = 0, j = 10; i < cks && j > 1; i++) {
		if (isdigit(str[i])) sum += j-- * (str[i] - '0');
	}
	int temp;
	temp = (11 - (sum % 11)) % 11;
	return ans && checj == temp;
}

bool checkNoErr(string str, int start, int num, int& end) {
	bool ans;
	if (isdigit(str[start])) ans = true;
	else ans = false;
	end = start;
	while (isdigit(str[end])) {
		++end;
	}
	if (ans && str[end] == '-' && end - start < num + 1) return true;
	else 
		return false;

}

void checkISBN(string str) {
	int Country, Publisher, BookNum;
	if (checkNoErr(str, 0, 5, Country) && checkNoErr(str, Country + 1, 7, Publisher) && checkNoErr(str, Publisher + 1, 6, BookNum) && checkSum(str, BookNum + 1) && (BookNum == 11))
		cout << 1 << endl;
	else
		cout << 0 << endl;
}

int main() {
	int times;
	string str;
	cin >> times;

	for (int i = 0; i < times; i++) {
		cin >> str;
		checkISBN(str);
		
	}
	return 0;
}