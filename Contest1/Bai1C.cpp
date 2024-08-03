#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

bool isSafe(vector<int>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || (abs(board[i] - col) == abs(i - row))) {
            return false;
        }
    }
    return true;
}

void solve(vector<int>& board, int row, int N) {
    if (row == N) {
        ++cnt;
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solve(board, row + 1, N);
            board[row] = -1;
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> board(N, -1);
    solve(board, 0, N);

    cout << cnt << endl;

    return 0;
}
