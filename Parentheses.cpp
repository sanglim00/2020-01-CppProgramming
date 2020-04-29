/* **************************
Problem : 괄호
20191584 남상림
****************************/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

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
			if (buffer[j] == ')' || buffer[j] == '}' || buffer[j] == ']') {
				if (STK.empty()) answer = 0;
				else {
					temp = STK.top();
					STK.pop();
					if (temp!= buffer[j]) answer = 0;
					else answer = 1;
				}
			}
		}
		if (STK.empty()) answer = 1;
		else answer = 0;
		cout << answer << endl;
		
	}
}
