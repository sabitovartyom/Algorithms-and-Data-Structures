#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void trace(const std::vector<std::vector<int>>& max_table, int i, int j){
	if (i == 0 && j == 0) {
		return;
	} else if (i == 0) {
		trace(max_table, i, j-1);
		std::cout << 'R';
	} else if (j == 0) {
		trace(max_table, i-1, j);
		std::cout << 'D';
	} else if (max_table[i-1][j] > max_table[i][j-1]){
		trace(max_table, i-1, j);
		std::cout << 'D';
	} else {
		trace(max_table, i, j-1);
		std::cout << 'R';
	}
}

int main() 
{
	int N, M;
	std::cin >> N >> M;
	std::vector<std::vector<int>> weight_table(N, std::vector<int>(M));
	std::vector<std::vector<int>> max_table(N, std::vector<int>(M));


	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			std::cin >> weight_table[i][j];
		}
	}

	max_table[0][0] = weight_table[0][0];

	for (int i = 1; i < N; i++){
		max_table[i][0] = max_table[i-1][0] + weight_table[i][0];
	}

	for (int j = 1; j < M; j++){
		max_table[0][j] = max_table[0][j-1] + weight_table[0][j];
	}

	for (int i = 1; i < N; i++){
		for (int j = 1; j < M; j++){
			max_table[i][j] = std::max(max_table[i][j-1], max_table[i-1][j]) + weight_table[i][j];
		} 
	}

	std::cout << max_table[N-1][M-1] << std::endl;
	trace(max_table, N-1, M-1);
	return 0;
}