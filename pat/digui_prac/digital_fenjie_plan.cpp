#include <iostream>

// 递归函数，计算将 n 表示成至少两个正整数之和的方案数
int partition(int n, int maxPart)
{
    // 如果 n 为 0，表示找到了一种有效的划分方案
    if (n == 0)
    {
        return 1;
    }
    // 如果 n 小于 0 或者 maxPart 小于等于 0，说明这种划分不合法
    if (n < 0 || maxPart <= 0)
    {
        return 0;
    }
    // 不包含 maxPart 的划分方案数 + 包含 maxPart 的划分方案数
    return partition(n, maxPart - 1) + partition(n - maxPart, maxPart);
}

// 计算将 n 表示成至少两个正整数之和的方案数的函数
int waysToPartition(int n)
{
    // 当 n 为 1 时，无法表示成至少两个正整数之和，所以方案数为 0
    if (n == 1)
    {
        return 0;
    }
    // 调用递归函数，初始的最大划分部分为 n - 1
    return partition(n, n - 1);
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << waysToPartition(n) << std::endl;
    return 0;
}