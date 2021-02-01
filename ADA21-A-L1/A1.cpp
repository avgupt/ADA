#include <iostream>

using namespace std;

int main () {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;

        int A[N], B[N];

        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) cin >> B[i];

        int indices[N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i] == B[j]) {
                    indices[i] = j;
                }
            }
        }

        int intersections = 0;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (indices[j] > indices[i]) intersections++;
            }
        }  

        cout << intersections << endl;
    }
}