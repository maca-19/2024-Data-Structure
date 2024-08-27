#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

void bubSort(int list[], int n)
{
    int temp;
    for (int i = n - 1 ; i > 0 ; i--) {     //최댓값이 맨 오른쪽 이므로 n - 1 부터 시작
        for(int j = 0 ;  j < i ; j++) {     //맨 왼쪽 부터 최댓값 - 1 까지 비교
            if(list[j] > list[i]) {
                SWAP(list[j], list[i], temp);
            }
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
    bubSort(list, n); // 정렬
    printf("\n\nAfter Sorting\n");
    for (i = 0 ; i < n ; i++) // 정렬 후
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}