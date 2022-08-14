#include<iostream>
#include<vector>
#include<algorithm>

// 소문자 N 개의 단어
// 길이가 짧은 것 > 같으면 사전 순으로

using namespace std;

bool compare(string a, string b) {
    int aLen = a.length();
    int bLen = b.length();
    if(aLen == bLen) { // 같을 때 사전순 
        return a < b;  
    }
    return aLen < bLen;  
}

int main() {
    int N;
    cin >>N;

    vector<string> terms;
    string tmp;
    for(int i =0 ; i< N; i++) {
        cin >> tmp;
        terms.push_back(tmp);
    }

    sort(terms.begin(), terms.end(), compare);

    for(int i=0; i<N; i++){
       if (i != 0 &&terms[i] == terms[i - 1]) {
			continue;
		}
		cout << terms[i] << "\n";
    }
    return 0;
}