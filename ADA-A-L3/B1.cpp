#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, B;
    cin >> n >> B;
    int a, b;
    int ans = 0;
    while(n--) {
        cin >> a >> b;
        int profit = a*B*B+b*B;
        if (profit > ans) ans = profit;
    }
    cout << ans << endl;
    return 0;
}
