#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // INT_MAX, INT_MIN

using namespace std;

int N;
char op[] = "abcd";

int cnt = 0;
int result = 0;
void cal(int num, char op) {

	switch (op) {
	case 'a': result += num; break;
	case 'b': result -= num; break;
	case 'c': result *= num; break;
	case 'd':
		if (num < 0) {
			num = num * (-1);
			result = (result / num) * (-1); // ³ª´« ¸ò ±¸ÇÏ°í -
			break;
		}
		else {
			result = result / num;
			break;
		}
	default:
		return;
	}

}
int main() {
	cin >> N;
	vector<int> numbers(N);
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	vector<char> operators(N - 1);
	for (int i = 0; i < 4; i++) {
		int temp;
		cin >> temp;
		for (int j = 0; j < temp; j++) {
			operators[cnt++] = op[i];
		}
	}


	int max = INT_MIN;
	int min = INT_MAX;

	do {
		result = numbers[0];
		for (int i = 0; i < N - 1; i++) {
			cal(numbers[i + 1], operators[i]);
		}

		if (max < result) {
			max = result;
		}
		if (min > result) {
			min = result;
		}
		
	} while (next_permutation(operators.begin(), operators.end()));


	cout << max << "\n" << min;

	return 0;
}