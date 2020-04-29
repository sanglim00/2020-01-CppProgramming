/* **************************
Problem : 괄호
20191584 남상림
****************************/
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

bool match(char a, char b) {
	switch (a) {
	case '(':
		if (b == ')')
			return true;
		else
			return false;
		break;
	case '{':
		if (b == '}')
			return true;
		else
			return false;
		break;
	case '[':
		if (b == ']')
			return true;
		else
			return false;
		break;
	}
}
int main() {
	int times, answer;
	string str;
	stack<char> STK;
	char temp;

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> str;
		char* buffer = new char[str.length()+1];
		str.copy(buffer, str.length() + 1);
		for (int j = 0; j < str.length(); j++) {
			if (buffer[j] == '(' || buffer[j] == '{' || buffer[j] == '[') STK.push(buffer[i]);
			else if (buffer[j] == ')' || buffer[j] == '}' || buffer[j] == ']') {
				if (STK.empty()) answer = 0;
				else {
					temp = STK.top();
					STK.pop();
					if (match(temp, buffer[j]) == false) answer = 0;
					else answer = 1;
				}
			}
		}
		if (STK.empty()) answer = 1;
		else answer = 0;
		cout << answer << endl;
		
	}
}
