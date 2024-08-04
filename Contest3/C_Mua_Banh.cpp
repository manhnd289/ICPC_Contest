#include<bits/stdc++.h>

using namespace std;

int main() {
	int N; cin >> N;
	for (int x = 0; x <= 100; x++) {
		for (int y = 0; y <= 100; y++) {
			int sum = x * 7 + y * 4;
			if (sum > N) continue;
			else if (sum == N) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}
