#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int x, y, z, v, flag;
    char a, b;
    int count, N, second;
    srand(time(NULL)); 
    printf("请输入四则运算题目个数：");
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        do
        {
            x = rand() % 100 + 1;
            y = rand() % 100 + 1;
            z = rand() % 100 + 1;
            second = x / y;
            count = second - z;
        } while (count < 0);
        switch (x % 4)
        {
            case 0:
                a = '+';
                break;
            case 1:
                a = '-';
                break;
            case 2:
                a = '*';
                break;
            case 3:
                a = '/';
                break;
            default:
                break;
        }
        switch (y % 4)
        {
            case 0:
                b = '+';
                flag = 0;
                break;
            case 1:
                b = '-';
                flag = 0;
                break;
            case 2:
                b = '*';
                if ((a == '*') || (a == '/'))
                    flag = 0;
                else
                    flag = 1;//bc优先计算
                break;
            case 3:
                b = '/';
                if ((a == '*') || (a == '/'))
                    flag = 0;
                else
                    flag = 1;//bc先
                break;
            default:
            break;
        }
        if(flag==0)
        {
            v = 0;
            switch (a)
            {
                case '+':
                  v = x+y;
                  break;
                case '-':
                  v = x-y;
                  break;
                case '*':
                  v = x*y;
                  break;
                case '/':
                  v = x/y;
                  break;
                default:
                  break;
            }
            switch (b)
            {
                case '+':
                    v += z;
                    break;
                case '-':
                    v -= z;
                    break;
                case '*':
                    v *= z;
                    break;
                case '/':
                    v /= z;
                    break;
                default:
                    break;
            }
        }
        else
        {
            v = 0;
            switch (b)
            {
                case '+':
                    v = y + z;
                    break;
                case '-':
                    v = y - z;
                    break;
                case '*':
                    v = y * z;
                    break;
                case '/':
                    v = y / z;
                    break;
                default:
                  break;
            }
            switch (a)
            {
                case '+':
                    v = x + v;
                    break;
                case '-':
                    v = x - v;
                    break;
                case '*':
                    v = x * v;
                    break;
                case '/':
                    v = x / v;
                    break;
                default:
                  break;
            }
        }
        printf("%d %c %d %c %d = %d\n", x, a, y, b, z, v);
    }
    printf("出题完成，感谢使用");
}

