#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;
int fib(int n);
int count1 = 0;
int count2 = 0;
int main() {
    int n;
    cin >> n;
    fib(n);
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    for (int i = 2; i < n; i++) {
        v.push_back(v[i - 1] + v[i - 2]);
        count2++;
    }
    cout << count1 << " " << count2;


}
    
int fib(int n) {
    if (n == 1 || n == 2) {
        count1++;
        return 1;
    }
    else return (fib(n - 1) + fib(n - 2));
}