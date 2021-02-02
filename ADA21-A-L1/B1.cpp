#include <algorithm>
#include <iostream>
#include <iomanip> 
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

#define ll double
#define point pair<ll ll>

vector<pair<double, double>> poles;
vector<pair<double, double>> temp;

bool sortbyfirst(const pair<ll,ll> &a, const pair<ll,ll> &b) { 
    return (a.first < b.first) || (a.first == b.first && a.second < b.second); 
}

bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b) { 
    return (a.second < b.second); 
} 

ll calcDist(pair<ll, ll> p1, pair<ll, ll> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

ll calcPerimeter(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3) {
    return calcDist(p1, p2) + calcDist(p2, p3) + calcDist(p3, p1);
}

ll calcMinPerimeter(ll start, ll end) {
    if (end - start < 2) {
        sort(poles.begin() + start, poles.begin() + end + 1, sortbysec);
        return 1e9;
    } else if (end - start == 2) {
        sort(poles.begin() + start, poles.begin() + end + 1, sortbysec);
        return calcPerimeter(poles[start], poles[start+1], poles[start+2]);
    }

    ll mid = (long long)(start + end) / 2;
    pair<ll, ll> midPoint = poles[mid];

    ll per1 = calcMinPerimeter(start, mid - 1);
    ll per2 = calcMinPerimeter(mid, end);
    ll minPer = min(per1, per2);

    // cout << minPer << endl;
    
    long long ptr1 = start;
    long long ptr2 = mid;
    long long i = 0;
    for (; i <= end - start && ptr1 < mid && ptr2 <= end; i++) {
        if (poles[ptr1].second <= poles[ptr2].second) {
            temp[i] = poles[ptr1++];
        } else {
            temp[i] = poles[ptr2++];
        }
    }

    for (;i <= end - start && ptr1 < mid; i++) {
        temp[i] = poles[ptr1++];
    }
    for (;i <= end - start && ptr2 <= end; i++) {
        temp[i] = poles[ptr2++];
    }

    for (long long i = 0; i <= end - start; i++) {
        poles[start + i] = temp[i];
    }

    i = 0;
    for (long long q = start; q <= end; q++) {
        pair<ll, ll> p = poles[q];
        if (abs(p.first - midPoint.first) <= minPer / 2) {
            temp[i++] = p;
        }
    }

    for (long long j = 0; j < i; j++) {
        for (long long k = 1; k <= 15 && j+k < i; k++) {
            for (long long l = k+1; l <= 16 && j+l < i; l++) {
                minPer = min(minPer, calcPerimeter(temp[j], temp[j+k], temp[j+l]));
                // cout << minPer << " " << poles[j].first << " " << poles[j+k].first << poles[j+l].first << endl;
            }
        }
    }

    return minPer;
}


int main() {

    long long n;
    cin >> n;
    ll f, s;
    for (long long i = 0; i < n; i++) {
        cin >> f >> s;
        poles.push_back({f, s});
    }

    sort(poles.begin(), poles.end());
    temp.resize(n+1);
    cout << setprecision(15);
    cout << calcMinPerimeter(0, n-1) << endl;



}