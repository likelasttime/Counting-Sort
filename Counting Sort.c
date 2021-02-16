#include<stdio.h>
#define LEN 8

int main() {
    int maxValue=0;
    int data[LEN];
    int count[LEN] = { 0, };
    int temp[LEN] = { 0, };

    for (int i = 0; i < LEN; i++) {         
        scanf_s("%d", &data[i]);        // 데이터 입력받기
    }


    for (int i = 0; i < LEN; i++) {
        if (maxValue < data[i]) maxValue = data[i];         // counts배열의 크기 구하기
        count[data[i]] += 1;            // 발생 횟수 세기
    }

    // 각 항목 위치 설정을 위한 카운트 조정
    for (int i = 1; i <= maxValue; i++) {
        count[i] = count[i] + count[i - 1];
    }

    // 카운트를 사용하여 각 항목 위치 결정
    for (int i = LEN - 1; i >= 0; i--) {
        temp[--count[data[i]]] = data[i];
    }

    // 출력
    for (int i = 0; i < LEN; i++) { 
        printf("%d", temp[i]);
    }
    

}