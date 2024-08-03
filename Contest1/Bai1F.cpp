#include <bits/stdc++.h>
using namespace std;

// int main() {
//     int N;
//     cin >> N;

//     vector<unordered_set<int>> preferences(N);

//     // Đọc dữ liệu đầu vào
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < 5; j++) {
//             int food;
//             cin >> food;
//             preferences[i].insert(food);
//         }
//     }

//     int incompatiblePairs = 0;

//     // Kiểm tra từng cặp học sinh
//     for (int i = 0; i < N; i++) {
//         for (int j = i + 1; j < N; j++) {
//             bool compatible = false;
//             for (int food : preferences[i]) {
//                 if (preferences[j].count(food) > 0) {
//                     compatible = true;
//                     break;
//                 }
//             }
//             if (!compatible) {
//                 incompatiblePairs++;
//             }
//         }
//     }

//     // In kết quả
//     cout << incompatiblePairs << endl;

//     return 0;
// }

int main() {
    int N;
    cin >> N;
    vector<vector<int>> favorites(N, vector<int>(5));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> favorites[i][j];
        }
    }
    
    unordered_map<int, vector<int>> dishMap;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 5; ++j) {
            dishMap[favorites[i][j]].push_back(i);
        }
    }
    
    unordered_set<int> compatible;
    for (const auto& pair : dishMap) {
        const auto& students = pair.second;
        for (int i = 0; i < students.size(); ++i) {
            for (int j = i + 1; j < students.size(); ++j) {
                int small = min(students[i], students[j]);
                int large = max(students[i], students[j]);
                compatible.insert(small * N + large);
            }
        }
    }
    
    long totalPairs = static_cast<long>(N) * (N - 1) / 2;
    long incompatiblePairs = totalPairs - compatible.size();
    
    cout << incompatiblePairs << endl;

    return 0;
}