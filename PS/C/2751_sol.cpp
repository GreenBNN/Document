#include<iostream>
#include<vector>
#include<algorithm>

// N 개의 수가 주어졌을 때
// 오름차순 정렬 N < |1000000|
using namespace std;


int main() {
    int N;
    vector<int> num;

    cin >> N;

    int tmp;
    for(int i = 0; i< N;i++ ) {
        cin >>  tmp;
        num.push_back(tmp);
    }
    sort(num.begin(), num.end());

    for(int i= 0 ; i<N;i++) {
        cout << num[i] << '\n';
    }

    return 0;
}