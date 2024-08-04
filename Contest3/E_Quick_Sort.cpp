#include<bits/stdc++.h>

using namespace std;

int main() {
	int N; cin >> N;
	vector<int> X(N);
	for (int i = 0; i < N; i++) cin >> X[i];
	vector<int> left(N, 0);
	vector<int> right(N, 0);
	left[0] = 1;
	right[N - 1] = 1;
	int Max = X[0];
	for (int i = 1; i < N; i++) {
		if (Max <= X[i]) left[i] = 1;
		Max = max(Max, X[i]);
	}
	int Min = X[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		if (X[i] < Min) right[i] = 1;
		Min = min(Min, X[i]);
	}
	vector<int> result;
	for (int i = 0; i < N; i++) {
		if (left[i] && right[i]) {
			result.push_back(X[i]);
		}
	}
	cout << result.size() << " ";
	
	if (result.size() > 100) {
		for (int i = 0; i < 100; i++) cout << result[i] << " ";
	} else {
		for (int x : result) cout << x << " ";
	}
	return 0;
}
