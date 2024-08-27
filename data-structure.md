<br></br>
<!-- 2024-02-20 -->
# 2024-08-20  2차시 - 정렬

---------------------------

## 정렬 : 크기순으로 나열하는 것

컴퓨터 과학에서....
정렬의 기준을 Record 라고 하고 이는 Field 로 구성됨
특정 Record 를 식별하려고 사용되는 Field 를 Key 라고 함
정렬을 레코드 들을 키 값의 순서고 재배열 하는 것

예시 : 학생들의 레코드
![레코드](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQ6wFwlRS_VmgFfOLTIuUEOX8d8AEBQpAaaYQ&s)

## 정렬의 종류

* 복잡도 밑 효율성에 따라
  * 단순 but 비효율
    * 삽입정렬, 선택정려르 버블정렬 등
  * 복잡 but 효율
    * 퀵 정렬, 힙 정렬, 합병 정렬, 기수 정렬 등
* 정렬 대상의 주기억 장치 적재 여부에 따라
  * 내부정렬
  * 외부정렬
* 안정성에 따라
  * 동일한 키 값을 갖는 레코드 들이 정렬 후 에도 유지 되는지

## 알고리즘 성능 평가

프로그램의 수행기산은 수행환경에 따라 유동적임

* 언어, 하드웨어, OS, 컴파일러
* 문자열 구현방법, 인자 전달방법
* 입력 크기 & 특성

> 알고리즘의 수행시간은 __반복문이 수행되는 횟수로__ 측정함

### 시간 복잡도 Time Complexity

* 알고리즘 실행 중 수행하는 기본적인 연산의 수를 입력의 크기에 대한 함수로 표현
  * 가장 널리 사용되는 알고리즘 수행시간 기준
* 기본적인 연산

#### 시간 복잡도가 높다?

> 입력의 크기가 증가할 때 알고리즘 수행시간이 더 빠르게 증가
> 시간 복잡도가 낮다고 해서 언제나 더 빠르게 동작하는 것은 아님

### 입력의 종류와 형태에 따른 수행 시간의 변화

입력에 따른 수행시간 변화를 고려하기 위해 __최선, 최악, 평균__ 수행시간 사용
일반적으로 최악 수행시간 사용

### 시간복잡도는 계산 하기 어려움

* 빅오 표기법 : 최악의 경우
* 세타 표기법 :




<br></br>
<!-- 2024-02-22 -->
# 2024-08-22  3차시 - 정렬2

## 선택 정렬 Selection Sort

리스트에서 __최솟값을 선택__하여 첫번째 요소와 교환하는 정렬 기법

1. 두개의 리스트를 사용한 선택정렬
    * 배열이 하나 더 필요함
    * 메모리 효율적이지 않음
2. 제자리 정렬
    * 메모리 효율적임

### 제자리 선택정렬 코드 - "20240822_code.c"

```
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
        least = i;      //최솟값을 첫번째 요소라고 가정
        for (j = i + 1 ; j < n ; j++) {
            if (list[j] < list[least])      //최솟값 비교
                SWAP(list[i], list[j], temp);
                least = j;
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
```

[참고: https://gmlwjd9405.github.io/2018/05/06/algorithm-selection-sort.html](https://gmlwjd9405.github.io/2018/05/06/algorithm-selection-sort.html)

### 이 코드의 시간복잡도 분석

* 비교 횟수
  * if 가 이중 for 문 안에 있다 -> n^2
* 이동 횟수
  * SWAP이 for 문 안에 있는데 SWAP 은 3개의 연산 -> 3 * (n - 1)
* 안정성?




<br></br>
<!-- 2024-02-27 -->
# 2024-08-27  4차시 - 삽입

## 삽입정렬

리스트의 모든 요소를 앞에서 부터 이미 __정렬된 부분과 비교하여 자신의 위치를 찾아 삽입__ 하는 정렬.

![삽입정렬](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEg4AjYYdhM_rfCeM5yHNwQVu1RPgo0wBizOKq0ESl-n8F2AI5JgWr4DKAxI-Lphlt2LlZoLCtZv1bxHYnwoU0qefj38SWF2iOURAA3pvkVyoTZevA7i7PnKNDQzAHDgz0Tl6jtp3v0AaXA/s1600/%EC%82%AC%EC%9A%A9%EC%9E%90+%EC%A7%80%EC%A0%95+12.gif)

### 삽입정렬 코드 - "20240827_code.c"

```
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
```

### 삽입정렬 성능분석

### 포트폴리오 퀴즈

* 배열 [3, 7, 9 , 4 , 1, 6]




<br></br>
<!-- 2024-02-27 -->
# 2024-08-27  5차시 - 버블정렬

## 버블 정렬

서로 __인접한 두 원소__ 를 검사하여 정렬하는 알고리즘

![버블정렬](https://img1.daumcdn.net/thumb/R800x0/?scode=mtistory2&fname=https%3A%2F%2Ft1.daumcdn.net%2Fcfile%2Ftistory%2F275F9A4A545095BD01)


### 버블정렬 코드 - "20240827_code_A.c"

```
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
```