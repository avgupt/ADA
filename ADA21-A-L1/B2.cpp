#include <algorithm>
#include <iostream>
#include <iomanip> 
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

#define ll double
#define point pair<ll, ll>

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
        return 1e9;
    } else if (end - start == 2) {
        return calcPerimeter(poles[start], poles[start+1], poles[start+2]);
    }

    ll mid = (long long)(start + end) / 2;
    pair<ll, ll> midPoint = poles[mid];

    ll per1 = calcMinPerimeter(start, mid - 1);
    ll per2 = calcMinPerimeter(mid, end);
    ll minPer = min(per1, per2);

    // cout << minPer << endl;
    
    vector<point> strip;

    for (long long q = start; q <= end; q++) {
        pair<ll, ll> p = poles[q];
        if (abs(p.first - midPoint.first) <= minPer / 2) {
            strip.push_back(p);
        }
    }
    sort(strip.begin(), strip.end(), sortbysec);
    for (long long j = 0; j < strip.size(); j++) {
        for (long long k = 1; k <= 8 && j+k < strip.size(); k++) {
            for (long long l = k+1; l <= 8 && j+l < strip.size(); l++) {
                minPer = min(minPer, calcPerimeter(strip[j], strip[j+k], strip[j+l]));
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