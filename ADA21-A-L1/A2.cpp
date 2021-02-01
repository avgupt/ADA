#include <iostream>
#include <unordered_map>

using namespace std;

#define ll long long

ll temp[1000001];

ll merge(ll* indices, ll left, ll mid, ll right) {
    ll inversions = 0;
    

    ll leftPtr = left, rightPtr = mid;
    ll i = left;
    while (leftPtr <= mid - 1 && rightPtr <= right) {
        if (indices[leftPtr] <= indices[rightPtr]) {
            temp[i] = indices[leftPtr];
            leftPtr++;
        } else {
            temp[i] = indices[rightPtr];
            rightPtr++;
            
            inversions += mid - leftPtr;
        }
        i++;
    }

    while (leftPtr <= mid - 1) {
        temp[i++] = indices[leftPtr++];
    }

    while (rightPtr <= right) {
        temp[i++] = indices[rightPtr++];
    }

    for (ll i = left; i <= right; i++) {
        indices[i] = temp[i];
    }

    return inversions;
}

ll split(ll* indices, ll left, ll right) {
    ll mid = (left + right) / 2, inversions = 0;

    if (left < right) {
        inversions += split(indices, left, mid);
        inversions += split(indices, mid + 1, right);
        inversions += merge(indices, left, mid + 1, right);
    }
    return inversions;
}

int main() {
    ll T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        
        ll A[N], B[N];
        for (ll i = 0; i < N; i++) cin >> A[i];
        for (ll i = 0; i < N; i++) cin >> B[i];

        unordered_map<ll, ll> indices_map;
        for (ll i = 0; i < N; i++) indices_map[B[i]] = i; 

        ll indices[N];
        for (ll i = 0; i < N; i++) indices[i] = indices_map[A[i]];

        cout << split(indices, 0, N-1) << endl;
    }
}