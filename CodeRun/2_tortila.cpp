#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;

    cin >> N >> M;

    vector<vector<int>> weight_table(N, vector<int>(M));
    vector<vector<int>> min_table(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> weight_table[i][j];
        }
    }

    min_table[0][0] = weight_table[0][0];
    for (int i = 1; i < N; i++) {
        min_table[i][0] = min_table[i - 1][0] + weight_table[i][0];
    }
    for (int j = 1; j < M; j++) {
        min_table[0][j] = min_table[0][j - 1] + weight_table[0][j];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            min_table[i][j] = min(min_table[i][j - 1], min_table[i - 1][j]) + weight_table[i][j];
        }
    }

    cout << min_table[N - 1][M - 1] << endl;

    return 0;
}