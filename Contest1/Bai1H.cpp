#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        int maxA = 0;

        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            if (A[i] > maxA) {
                maxA = A[i];
            }
        }

        if (N == 1) {
            cout << A[0] << endl;
            continue;
        }

        vector<int> freq(maxA + 1, 0);

        for (int num : A) {
            freq[num]++;
        }

        int result = 1;
        for (int g = maxA; g >= 1; --g) {
            int count = 0;
            for (int k = g; k <= maxA; k += g) {
                count += freq[k];
            }
            if (count > 1) {
                result = g;
                break;
            }
        }

        cout << result << endl;
    }

    return 0;
}