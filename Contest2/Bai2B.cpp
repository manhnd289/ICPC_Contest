#include <bits/stdc++.h>
using namespace std;

void generateNumbersWithTwoDigits(set<long long>& numbers, long long current, int digit1, int digit2, int N) {
    if (current > N) return;
    numbers.insert(current);
    if (current > 0) {
        generateNumbersWithTwoDigits(numbers, current * 10 + digit1, digit1, digit2, N);
        generateNumbersWithTwoDigits(numbers, current * 10 + digit2, digit1, digit2, N);
    }
}

int countNumbersWithAtMostTwoDistinctDigits(int N) {
    set<long long> numbers;

    for (int digit1 = 0; digit1 <= 9; ++digit1) {
        generateNumbersWithTwoDigits(numbers, digit1, digit1, digit1, N);
        for (int digit2 = digit1 + 1; digit2 <= 9; ++digit2) {
            generateNumbersWithTwoDigits(numbers, digit1, digit1, digit2, N);
            generateNumbersWithTwoDigits(numbers, digit2, digit1, digit2, N);
        }
    }

    return numbers.size() - 1; // Trừ đi 1 để loại bỏ số 0
}

int main() {
    int N;
    cin >> N;
    cout << countNumbersWithAtMostTwoDistinctDigits(N) << endl;
    return 0;
}
