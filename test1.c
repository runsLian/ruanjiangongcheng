#include<stdio.h>
#include<stdlib.h>
int main(){//给定一个数组，计算该数组最大子数组
    int a;
    printf("输入数组个数\n");
    scanf("%d", &a);
    int v[a];
    printf("请输入数组中元素值\n");
    for (int i = 0; i <a; i++)
    {
        printf("输入数组中第%d个数", i+1);
        scanf("%d", &v[i]);
    }
    for ( int i = 0; i < a; i++)
    {
        printf("数组中第%d个数为%d\n", i + 1, v[i]);
    }
    int max = 0;
    for (int i = 0; i < a; i++) 
    {
        int sum = v[i];
        if (max<sum)
        {
            max = sum;
        }
        
        for (int j = i + 1; j < a; j++)
        {
            sum += v[j];
            if (sum > max)
            {
                max = sum;
            }
        }
     }
    printf("最大子数组之和为%d", max);
}