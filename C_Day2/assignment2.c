#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main (void){
    printf("입력\n");
    int arr[8];                 //메인 배열
    for (int i=0;i<8;i++){
        printf("%d : ",i);      //배열 입력
        scanf("%d",&arr[i]);
    }

    int max=arr[0];      // 최댓값을 저장할 변수
    int max_index=0;     // 최댓값의 위치를 저장할 변수
    
    // 배열의 뒤쪽부터 정렬 시작 (i = 7부터 0까지)
    // 각 반복마다 남은 배열에서 최댓값을 찾아 맨 뒤로 이동
    for (int i=7;i>=0;i--){
        
        // 0번 인덱스부터 i번 인덱스까지의 범위에서 최댓값 찾기
        for (int j=0;j<=i;j++){
            // 현재 arr[j]가 max보다 크거나 같으면 최댓값 업데이트
            if(max<=arr[j]){
                max=arr[j];           // 최댓값 갱신
                max_index=j;          // 최댓값의 위치 갱신
            }
        }
        
        // 찾은 최댓값을 배열의 i번째 위치로 이동
        arr[max_index]=arr[i];  // 기존 i번째 값을 최댓값이 있던 위치에 저장
        arr[i]=max;             // 최댓값을 i번째 위치에 저장 (정렬 완료)
        
        // 현재 정렬 상태를 화면에 출력 (정렬 과정 시각화)
        printf("%d %d %d %d %d %d %d %d\n",
               arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]);
        
        // 다음 반복을 위해 초기값 재설정
        max=arr[0];       // 최댓값을 첫 번째 요소로 초기화
        max_index=0;      // 최댓값의 위치를 0으로 초기화
    }
    
    // 인덱스와 함께 정렬된 배열의 모든 요소 출력
    for (int i=0;i<8;i++){
        printf("%d : %d\n",i,arr[i]);  // 인덱스와 값을 함께 출력
    }
    
    return 0;
}