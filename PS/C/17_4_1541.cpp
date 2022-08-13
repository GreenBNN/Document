#include <iostream>
#include <string>
#include <algorithm>

// 식이 주어짐 숫자와 +. - 으로 이루어짐
// 5자리 수 이상 수 X, 연속 연산자 X
// 괄호를 쳐서 식의 값을 최소로 만들기


using namespace std;
string input;
bool flag = false;
int temp;
int sum = 0;
int main()
{
	cin >> input;

	for (int i = 0; i <= input.length(); i++) {
		if (input[i] == '-' || input[i] == '+' || i == input.length() ) {
			if (flag == false) { // -가 안떴을 때
				sum += temp;
				temp = 0;
			}
			else { // -가 떴을 때
				sum -= temp;
				temp = 0;
			}

			if (input[i] == '-') {
				flag = true;
			}
		}
		else { // 숫자일 때 
			temp *= 10;
			temp += input[i] - '0';
		}

	}
	cout << sum;

}