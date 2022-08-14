#include<iostream>
#include<vector>
#include<algorithm>

// 총 8 문제를 품
// 가장 높은 점수 5개의 합이 점수
// 점수는 다 다름

using namespace std; 
int main() {
    vector<pair<int,int>> arr;
    vector<int> arr2;
    int a;
    
    for(int i =0 ; i<8; i++ ){
        cin >> a;
        arr.push_back(make_pair(a, i));
    }
    sort(arr.begin(), arr.end());

    int sum = 0;
    for(int i = 7; i>2;i-- ) {
        sum += arr[i].first;
        arr2.push_back(arr[i].second );
    }
    sort(arr2.begin(), arr2.end());
    cout <<sum << '\n';

    for(int i =0  ;i < 5;i++ ) {
        cout << arr2[i]+1 << ' ';
    }

    return 0;
}
