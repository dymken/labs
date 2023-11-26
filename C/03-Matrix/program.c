#include <stdio.h>
#define N 3
#define M 4

int* create_matrix() {
	static int result[M][N] = {{31, 12, 23}, {14, 23, 32}, {25, 114, 41}, {13, 22, 0}};
	/*static int result[M][N];
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N; i++) {
			result[j][i] = rand();
		}
	}*/
	return result;
}

void print_matrix(int* matrix) {
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N; i++) {
			printf("%6i", *(matrix + j * N + i));
		}
		printf("\n");
	}
}
// [M-1][0] -> [M-2][1] -> [M-3][2] -> [M-i-1][i]          i = (0, min(M,N))
int find_min(int* matrix) {
	int min = *matrix;
	for (int j = 0; j < M; j++) {          // by rows
		for (int i = 0; i < N; i++) {      // by columns
			if (j < M - i - 1) {
				if (min > *(matrix + j * N + i))
					min = *(matrix + j * N + i);
			}
		}
	}
	return min;
}

int find_max(int* matrix) {
	int max = *matrix;
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N; i++) {
			if (j > M - i - 1) {
				if (max < *(matrix + j * N + i))
					max = *(matrix + j * N + i);
			}
		}
	}
	return max;
}

int main(void) {
	int* a;
	a = create_matrix();
	print_matrix(a);
	int min = find_min(a);
	int max = find_max(a);
	printf("min = %i, max = %i", min, max);
}