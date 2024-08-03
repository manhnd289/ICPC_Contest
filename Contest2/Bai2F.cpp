#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);

    // Xác định vị trí số 1 trong mảng để từ vị trí này lan ra 2 phía
    int pos_one = -1;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] == 1) pos_one = i;
    }
    
    /*
    Mỗi bước chỉ cần chuyển đổi nhiều nhất K-1 phần tử vì đã có 1 phần tử là 1
    Bên trái: [0,pos_one] có pos_one phần tử cần chuyển đổi nên sẽ có công thức pos_one/(K-1)
              Cộng thêm K-2 = K-1-1 với mục đích nếu pos_one/(K-1) bị dư ra bất kỳ phần tử nào -> Thêm 1 bước nữa
              (K-2) là đủ để làm tròn lên khi có dư còn khi chia hết thì dư ra K-2 = (K-1)-1
    Bên phải: [pos_one,N-1] có N-1-pos_one phần tử cần chuyển đổi (không tính pos_one).
    */

    int total_steps = 0;
    
    int left_steps = (pos_one + K - 1 - 1) / (K - 1);
    int right_steps = (N - pos_one - 1 + K - 2) / (K - 1);
    total_steps = left_steps + right_steps;

    // int left = pos, right = pos;
    // while(left > 0){
    //     total_steps++;
    //     left = max(0, left - k + 1);
    // }
    // while(right < n-1){
    //     total_steps++;
    //     right = min(n-1, right + k - 1);
    // }

    cout << total_steps << endl;

    

    return 0;
}
