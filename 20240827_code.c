#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

void insSort(int list[], int n)
{
    for ( int i = 1 ; i < n - 1 ; i++) {    //인덱스 0은 정렬된 것으로 간주.
        int j, key;
        key = list[i];  //삽입될 위치 i의 값 복사
        j = i - 1;  //현재 정렬된 부분은 i - 1 까지 이므로 i - 1 부터 역순으로 조사.
        while ( j >= 0 && list[j] > key ) { //배열인덱스가 정상적이고 key 보다 정렬된 배열에 있는 값이 크면 뒤 부터 한칸씩 밀기.
            list[j + 1] = list[j];
            j -= 1;
        }
        list[j + 1] = key;  //인덱스 j의 값이 key보다 작으므로 j + 1 이 key값이 됨.
    }
}

int main()
{
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for (i = 0 ; i < n ; i++)
        list[i] = rand() % 100; // 난수 발생 범위 0 ~ 99
    printf("** Insertion Sort **\n\n");
    printf("Before Sorting\n");
    for (i = 0 ; i < n ; i++) // 정렬 전
        printf("%d ", list[i]);
    insSort(list, n); // 정렬
    printf("\n\nAfter Sorting\n");
    for (i = 0 ; i < n ; i++) // 정렬 후
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}