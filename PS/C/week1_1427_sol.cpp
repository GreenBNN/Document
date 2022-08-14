#include<iostream>
#include<vector>
#include<algorithm>

// 장렬할 수 N < 1000000000
// 숫자를 내림차순으로 정렬한 수 출력

using namespace std; 
int main() {
    string arr;
    cin >> arr;
    sort(arr.begin(), arr.end(), greater<char>());
    cout << arr;

    return 0;
}
