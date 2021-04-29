#include <iostream>
#define N 9

using namespace std;

void ispis(int matrica[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << matrica[i][j] << " ";
		}
		cout << endl;
	}
}

bool valid(int matrica[N][N], int row, int col, int x) {
	for (int i = 0; i < N; i++) {
		if (matrica[i][col] == x)
			return false;
	}
	for (int i = 0; i < N; i++) {
		if (matrica[row][i] == x)
			return false;
	}
	int rowStart = row - row % 3;
	int colStart = col - col % 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matrica[rowStart + i][colStart + j] == x)
				return false;
		}
	}
	return true;
}

bool solvable(int matrica[N][N], int row, int col){
	if (col == N && row == N - 1)
		return true;
	if (col == N) {
		col = 0;
		row++;
	}
	if (matrica[row][col] > 0)
		return solvable(matrica, row, col + 1);
	for (int i = 1; i <= N; i++) {
		if (valid(matrica, row, col, i)) {
			matrica[row][col] = i;
			if (solvable(matrica, row, col + 1))
				return true;
		}
		matrica[row][col] = 0;
	}
	return false;
}

int main() {
	int matrica[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
					   { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
					   { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
					   { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
					   { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
					   { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
					   { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
					   { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
					   { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
	if (solvable(matrica, 0, 0))
		ispis(matrica);
	else
		cout << "No solution" << endl;
	system("PAUSE");
	return 0;
}