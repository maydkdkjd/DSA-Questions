#include <iostream>
using namespace std;

int main() {
    int arr[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;

    for(int i = 0; i < n; i = i + 2) {
        int a = arr[i];
        int b = arr[i + 1];

        ans =  a ^ b ^ ans;
    }
    cout << ans;
}