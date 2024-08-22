#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

void selSort(int list[], int n)
{
    int i, j, least, temp;
    for (i = 0 ; i < n - 1 ; i++) {     //마지막 인덱스는 자신과 비교할 필요 없음 -> n - 1 까지 반복
        for (j = i + 1 ; j < n ; j++) {
            if (list[j] < list[i])      //최솟값 비교
                SWAP(list[i], list[j], temp);
        }
    }
}

int main()
{
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for (i = 0 ; i < n ; i++)
        list[i] = rand() % 100; // 난수 발생 범위 0 ~ 99
    printf("** Selection Sort **\n\n");
    printf("Before Sorting\n");
    for (i = 0 ; i < n ; i++) // 정렬 전
        printf("%d ", list[i]);
    selSort(list, n); // 정렬
    printf("\n\nAfter Sorting\n");
    for (i = 0 ; i < n ; i++) // 정렬 후
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}