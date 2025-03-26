#include <iostream>
using namespace std;

const int N = 256;

int A[N];
void initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = i % 500;
    }
}

int common_algorithms()
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
    }
    return sum;
}

int multilink()
{
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < N; i += 2)
    {
        sum1 += A[i];
        sum2 += A[i + 1];
    }
    int sum = sum1 + sum2;
    return sum;
}

int recursion_sum(int *arr, int size)
{
    if (size == 1)
    {
        return arr[0];
    }

    // 将数组的后半部分加到前半部分
    int half_size = size / 2;
    for (int i = 0; i < half_size; i++)
    {
        arr[i] += arr[i + half_size];
    }

    // 递归处理前半部分
    return recursion_sum(arr, half_size);
}

int recursion_wrapper()
{
    int temp[N];
    for (int i = 0; i < N; i++)
    {
        temp[i] = A[i];
    }
    return recursion_sum(temp, N);
}

int main()
{
    initialize(N);

    // 调用普通算法
    int sum_common = common_algorithms();
    cout << "普通算法结果: " << sum_common << endl;

    // // 调用双路并行算法
    // int sum_multi = multilink();
    // cout << "双路并行算法结果: " << sum_multi << endl;

    // // 调用递归算法
    // int sum_recursive = recursion_wrapper();
    // cout << "递归算法结果: " << sum_recursive << endl;
}