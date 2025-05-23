#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<long long> weights;

ll recurse_apples(int index, ll sum1, ll sum2) {
    cout << index << " s1: " << sum1 <<" s2: " << sum2 << endl;
	// We've added all apples- return the absolute difference
	if (index == n) { 
        cout << "dif:" << abs(sum1 - sum2) <<  endl;
        return abs(sum1 - sum2); }
    int x = min(recurse_apples(index + 1, sum1 + weights[index], sum2),
    recurse_apples(index + 1, sum1, sum2 + weights[index]));
    cout << x << endl;
	// Try adding the current apple to either the first or second set
	return x;
}

int main() {
	cin >> n;
	weights.resize(n);
	for (int i = 0; i < n; i++) { cin >> weights[i]; }

	// Solve the problem starting at apple 0 with both sets being empty
	cout << recurse_apples(0, 0, 0) << endl;
}