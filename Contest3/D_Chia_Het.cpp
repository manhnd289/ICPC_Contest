#include<bits/stdc++.h>

using namespace std;

long long solve(int N, int M, vector<int> &A) {
	unordered_map<int, long long> mod_count;
	long long prefix_sum = 0;
	long long count = 0;
	mod_count[0] = 1;
	for (int i = 0; i < N; i++) {
		prefix_sum += A[i];
		int mod = ((prefix_sum % M) + M) % M;
		if (mod_count.find(mod) != mod_count.end()) {
			count += mod_count[mod];
			mod_count[mod] += 1;
		} else {
			mod_count[mod] = 1;
		}
	}
	return count;
}

int main() {
	int N, M; cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	cout << solve(N, M, A);
	return 0;
}
