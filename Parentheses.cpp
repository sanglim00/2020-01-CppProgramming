/* **************************
Problem : °ýÈ£
20191584 ³²»ó¸²
****************************/
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main() {
	int times, count = 0;
	string str;
	vector<char> vector;

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> str;
		char* buffer = new char[str.length()];
		str.copy(buffer, str.length() + 1);
		for (int j = 0; j < str.length(); j++) {
			if (buffer[j] == '(' || buffer[j] == '{' || buffer[j] == '[') {
				vector.push_back(buffer[j]); 
				count++;
			}
			else if (buffer[j] == ')' || buffer[j] == '}' || buffer[j] == ']') {
				count--;
				int k = 0;
				while(k != vector.size()){
					if (vector.at(k) == buffer[j]) {
						vector.erase(vector.begin() + k);
						break;
					}
					k++;
				}
			}
		}if (vector.empty() && count == 0) cout << 1 << endl;
		else cout << 0 << endl;
		
	}
}