// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// int bfs(int N, int ST, int EN, int u, int d) {
//     vector<int> dist(N + 1, -1);
//     queue<int> q;
    
//     q.push(ST);
//     dist[ST] = 0;
    
//     while (!q.empty()) {
//         int current = q.front();
//         q.pop();
        
//         if (current == EN) {
//             return dist[current];
//         }
        
//         int up = current + u;
//         int down = current - d;
        
//         if (up <= N && dist[up] == -1) {
//             q.push(up);
//             dist[up] = dist[current] + 1;
//         }
        
//         if (down >= 1 && dist[down] == -1) {
//             q.push(down);
//             dist[down] = dist[current] + 1;
//         }
//     }
    
//     return -1;
// }

// int main() {
//     int N, ST, EN, u, d;
//     cin >> N >> ST >> EN >> u >> d;
    
//     int result = bfs(N, ST, EN, u, d);
//     cout << result << endl;
    
//     return 0;
// }

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, ST, EN, u, d;
    cin >> N >> ST >> EN >> u >> d;

    // Khởi tạo các biến
    vector<bool> visited(N + 1, false);
    queue<pair<int, int>> q;  // Cặp <tầng hiện tại, số bước di chuyển>

    // Bắt đầu từ tầng ST
    q.push({ST, 0});
    visited[ST] = true;

    while (!q.empty()) {
        auto [currentFloor, steps] = q.front();
        q.pop();

        // Kiểm tra điều kiện dừng
        if (currentFloor == EN) {
            cout << steps << endl;
            return 0;
        }

        // Trường hợp di chuyển lên
        int nextFloorUp = currentFloor + u;
        if (nextFloorUp <= N && !visited[nextFloorUp]) {
            visited[nextFloorUp] = true;
            q.push({nextFloorUp, steps + 1});
        }

        // Trường hợp di chuyển xuống
        int nextFloorDown = currentFloor - d;
        if (nextFloorDown >= 1 && !visited[nextFloorDown]) {
            visited[nextFloorDown] = true;
            q.push({nextFloorDown, steps + 1});
        }
    }

    // Nếu không tìm được đường đi
    cout << -1 << endl;
    return 0;
}
