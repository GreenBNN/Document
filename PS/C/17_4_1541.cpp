#include <iostream>
#include <string>
#include <algorithm>

// ���� �־��� ���ڿ� +. - ���� �̷����
// 5�ڸ� �� �̻� �� X, ���� ������ X
// ��ȣ�� �ļ� ���� ���� �ּҷ� �����


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
			if (flag == false) { // -�� �ȶ��� ��
				sum += temp;
				temp = 0;
			}
			else { // -�� ���� ��
				sum -= temp;
				temp = 0;
			}

			if (input[i] == '-') {
				flag = true;
			}
		}
		else { // ������ �� 
			temp *= 10;
			temp += input[i] - '0';
		}

	}
	cout << sum;

}