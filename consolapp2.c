#include <stdio.h>
#include <stdlib.h>

// Задание №1. Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.

void Foo(int n) 
{

 if (n != 0)
    Foo(n / 2);
 else return;

 printf("%d", n % 2);
 return;
}

int main()
{
    int n;
    printf("Введите десятичное число: ");
    scanf("%d", &n);
    Foo(n);
    return 0;
}

// Задание №2. Реализовать функцию возведения числа [a] в степень [b]: Рекурсивно.
/* Рекурсивно, используя свойство чётности степени (то есть, если степень, в которую нужно возвести число, чётная, основание возводится в квадрат,
а показатель делится на два, а если степень нечётная - результат умножается на основание, а показатель уменьшается на единицу)*/


int recFoo(int a, int b)
{
    if (b == 0)
        return 1;
    int c = (b%2) ? a : 1;
    int d = recFoo(a, b / 2);
    return c * d * d;
}

int main()
{
    int a = 5;
    int b = 7;
    printf("5^7 : %d \n", recFoo(5,7));
    return 0;
}

// Задание№3. Реализовать нахождение количества маршрутов шахматного короля с препятствиями
/*(где единица - это наличие препятствия, а ноль - свободная для хода клетка)*/

int RoutesNumber(int x, int y, int** avl)
{
    if (get2dInt(avl, y,x) == 1) return 0;
    if (x == 0 && y == 0) return 0;
    else if (x == 0)
    {
        if (RoutesNumber(x, y=y-1, avl) == 0 && y != 1)
        return 0;
        else
        {
            return 1;
        }
    }
    else if (y == 0)
    {
        if (RoutesNumber(x=x-1,y,avl) == 0 && x != 1) return 0;
        return 0;
    }
    return RoutesNumber(x, y=y-1,avl)+RoutesNumber(x=x-1,y,avl);
}

int main()
{
    const int SIZE = 6;
    int** board = init2dIntArray(board, SIZE, SIZE);
    set2dInt(board, row=0, col=2, value=1);
    set2dInt(board, row=2, col=1, value=1);
    set2dInt(board, row=2, col=2, value=1);
    print2dIntArray(board, SIZE, SIZE, offset=5);
    printf("\n");
    for (int y=0; y<SIZE; ++y)
    {
        for (int x=0; x<SIZE, ++x)
        {
            printf("%5d", RoutesNumber(x,y,board));
        }
        printf("\n");
    }
    return 0;
}


