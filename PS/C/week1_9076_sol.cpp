#include<iostream>
#include<vector>
#include<algorithm> 


using namespace std;
int main () {

    int N;
    int arr[5];

    cin >> N;
    for(int i = 0; i<N;i++ ){

        for(int k = 0; k< 5;k++ ) {
            cin >> arr[k];
        }
        
        sort(arr, arr+5);

        int sum = 0;
        if(arr[3]-arr[1] >= 4) {
            cout << "KIN" << '\n';
        }
        else {
            for(int j =1; j< 4;j++ ) {
            sum += arr[j];
            }
            cout << sum << '\n';
        }
    }
    return 0;
}