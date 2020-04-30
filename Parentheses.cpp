/* **************************
Problem : 괄호
20191584 남상림
****************************/
#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool match(char a, char b) {
    switch (a) {
    case '(':
        if (b == ')') return true;
        else return false;
        break;
    case '{':
        if (b == '}') return true;
        else return false;
        break;
    case '[':
        if (b == ']') return true;
        else return false;
        break;
    default:
        return false;
    }
}
int main() {
    int times; 

    cin >> times;
    for (int i = 0; i < times; i++) {
       
        int answer = 0;
        string str;
        stack<char> STK;

        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '(' || str[j] == '[' || str[j] == '{') STK.push(str[j]);
            else {
                if (STK.empty()) { answer = 0; break; }
                else {
                    if (match(STK.top(), str[j])) { STK.pop(); answer = 1; }
                    else if (!match(STK.top(), str[j])) { STK.pop(); answer = 0; break; }
                }
            }
        }
        if (!STK.empty()) answer = 0;
        cout << answer << endl;

    }
}
