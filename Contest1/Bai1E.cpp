#include <iostream>
#include <vector>
#include <limits>

using namespace std;

long long minEnergy(int N, int C, vector<int>& H) {
    vector<long long> dp(N, numeric_limits<long long>::max());
    dp[0] = 0;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            long long energy = dp[j] + (long long)(H[i] - H[j]) * (H[i] - H[j]) + C;
            dp[i] = min(dp[i], energy);
        }
    }

    return dp[N-1];
}

int main() {
    int N, C;
    cin >> N >> C;

    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    cout << minEnergy(N, C, H) << endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <climits>

// using namespace std;

// int main() {
//     int N, C;
//     cin >> N >> C;
//     vector<int> H(N);
//     for (int i = 0; i < N; i++) {
//         cin >> H[i];
//     }

//     vector<long long> energy(N, LLONG_MAX);
//     energy[0] = 0;

//     for (int i = 0; i < N - 1; i++) {
//         for (int j = i + 1; j < N; j++) {
//             long long cost = (H[j] - H[i]) * (H[j] - H[i]);
//             cost += C;
//             energy[j] = min(energy[j], energy[i] + cost);
//         }
//     }

//     cout << energy[N - 1] << endl;

//     return 0;
// }
