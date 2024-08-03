#include <bits/stdc++.h>
using namespace std;

vector<int> findMaxMinSubarray(const vector<int>& A) {
    int N = A.size();
    vector<int> result(N);
    
    for (int X = 1; X <= N; ++X) {
        deque<int> dq;
        int maxMin = INT_MIN;
        
        for (int i = 0; i < N; ++i) {
            while (!dq.empty() && dq.front() <= i - X) {
                dq.pop_front();
            }
            
            while (!dq.empty() && A[dq.back()] >= A[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if (i >= X - 1) {
                maxMin = max(maxMin, A[dq.front()]);
            }
        }
        
        result[X-1] = maxMin;
    }
    
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<int> result = findMaxMinSubarray(A);
    
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}

// vector<int> solve(const vector<int>& A) {
//     int N = A.size();
//     vector<int> S(N);
//     deque<int> dq;

//     for (int X = 1; X <= N; X++) {
        
//         dq.clear();
//         for (int i = 0; i < N; i++) {
            
//             if (!dq.empty() && dq.front() == i - X)
//                 dq.pop_front();
                
//             while (!dq.empty() && A[dq.back()] > A[i])
//                 dq.pop_back();
            
//             dq.push_back(i);
            
//             if (i >= X - 1)
//                 S[X-1] = max(S[X-1], A[dq.front()]);
//         }
//     }

//     return S;
// }

// int main() {
//     int N;
//     cin >> N;
//     vector<int> A(N);
//     for (int i = 0; i < N; i++) {
//         cin >> A[i];
//     }

//     vector<int> result = solve(A);
//     for (int x : result) {
//         cout << x << " ";
//     }
//     cout << endl;

//     return 0;
// }