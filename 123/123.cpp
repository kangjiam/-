#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j;
    scanf_s("%d", &n);
    int *array = (int*)malloc(sizeof(int) * n);
    int max = 0, number = 0;//max用来输出最大子列和，number是统计子列中负数的个数
    int sum;
    for (i = 0; i < n; i++)
    {
        scanf_s("%d", &array[i]);
        //scanf("%d",array+i);两种写法等价
        max += array[i];
        if (array[i] < 0) number++;
    }
    if (number == n)
    {
        printf("0");
        return 0;
    }//如果都是负数，则返回0
    for (i = 0; i < n; i++)
    {
        if (array[i] <= 0) continue;
        sum = 0;
        for (j = i; j < n; j++)
        {
            sum += array[j];
            if (sum > max)
            {
                max = sum;
            }
        }
    }
    printf("%d", max);
    return 0;
}
