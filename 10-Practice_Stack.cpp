#include<iostream>
#include<stack>
using namespace std;

int evaluation(string postfix) {
	stack<int> s;
	for (int i = 0; i < postfix.size(); i++) {
		char tok = postfix[i];

		if (isdigit(tok)) {
			s.push(tok - '0'); // ex. '3'(51) - '0'(48) = '3'(3)
		}
		else {
			int op1 = s.top(); s.pop(); // C++의 pop()은 리턴값이 없다.
			int op2 = s.top(); s.pop();
			switch (tok)
			{
			case '+':  s.push(op2 + op1);  break;
			case '-':  s.push(op2 - op1);  break;
			case '*':  s.push(op2 * op1);  break;
			case '/':  s.push(op2 / op1);  break;
			}
		}
	}
	int result = s.top(); s.pop();
	return result;
}

int main()
{
	cout << evaluation("34+2*7/") << endl;
}