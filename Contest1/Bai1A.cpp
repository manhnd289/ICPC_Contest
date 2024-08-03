#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.length();
    vector<int> rev(n + 1, 0);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        int l = a - 1;
        int r = n - a;
        rev[l] += 1;
        if (r + 1 <= n) rev[r + 1] -= 1;
    }

    int curr_rev = 0;
    for (int i = 0; i < n; i++) {
        curr_rev += rev[i];
        if (curr_rev % 2 == 1) {
            int j = n - i - 1;
            if (i < j) {
                swap(s[i], s[j]);
            }
        }
    }

    cout << s << endl;
    return 0;
}
