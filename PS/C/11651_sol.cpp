#include<iostream>
#include<vector>
#include<algorithm>

// N 개의 좌표점 y 증가 > x 증가 순 정렬

using namespace std;

// sort 함수와 관련된 함수로 
// 현재 원소 a, 다음 원소 b 가 있을 때
// false 가 나오면 둘 자리가 swap 하게 된다.
bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    else {
        return a.second < b.second;
    }
}
int main() {
    int N;
    vector<pair<int, int>> dots;

    cin >> N;

    int a, b;
    for(int i =0 ;i < N;i++ ){
        cin >> a >> b;
        dots.push_back(make_pair(a,b));
    }
    
    sort(dots.begin(), dots.end(), compare);
    
    for(int i =0  ;i<N;i++) {
        cout << dots[i].first << ' ' << dots[i].second << '\n';
    }

    return 0;
}