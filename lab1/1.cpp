#include <iostream>

using namespace std;

const int N = 10;

int A[N][N];
int B[N];
int sum_common[N];
int sum_optimized[N];

// 初始化矩阵和向量
void initialize(int n) {
    for (int i = 0; i < n; i++) {
        B[i] = i;
        for (int j = 0; j < n; j++) {
            A[i][j] = i + j;
        }
    }
}

// 平凡算法实现 - 按行遍历
void common_algorithm(int n, int result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = 0;
        for (int j = 0; j < n; j++) {
            result[i] += B[j] * A[j][i];
        }
    }
}

// 优化算法实现 - 按列遍历，提高缓存命中率
void optimized_algorithm(int n, int result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = 0;
    }
    
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            result[i] += A[j][i] * B[j];
        }
    }
}
void print_results(int n, int result[]) {
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    initialize(N);
    
	// //平凡
    // common_algorithm(N, sum_common);
    // cout << "平凡算法结果: ";
    // print_results(N, sum_common);


	// 优化算法
	optimized_algorithm(N, sum_optimized);
	cout << "优化算法结果: ";
	print_results(N, sum_optimized);
	  
    return 0;
}