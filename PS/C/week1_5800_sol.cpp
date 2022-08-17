#include<iostream>
#include<vector>
#include<algorithm>

// 반의 수 K, 학생 수 N
// 반마다 학생의 수학 성적 주어짐
// 최고, 최저, 내림차순정렬 가장 큰 인접 점수 차이 출력
using namespace std;

int main() {
    int k, n, st;
    int MIN, MAX, ans;
    vector<int> arr;
    cin >> k;
    for (int i = 1; i <= k; i++){
        cin >> n;
        arr.clear();
        for (int j = 0; j < n; j++){
            cin >> st;
            arr.push_back(st);
        }
        sort(arr.begin(), arr.end());
        MIN = arr[0];
        MAX = arr[arr.size()-1];
        ans = 0;
        for (int j = 1; j < n; j++){
            ans = max(ans, arr[j]-arr[j-1]);
        }
        cout << "Class " << i << "\n" << "Max " << MAX << ", Min " << MIN << ", Largest gap " << ans << "\n";
    }
}