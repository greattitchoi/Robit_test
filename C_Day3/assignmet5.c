#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main (void){
    int N;
    int result;         //예외처리 검증
    printf("행과 열이 될 N을 입력해주세요: ");
    result=scanf("%d",&N);
    if (result==1){
    int **arr = (int**) malloc(sizeof(int*) * N);
    for(int i = 0; i < N; i++){
        arr[i] = (int*) malloc(sizeof(int) * N);
        for(int j = 0; j < N; j++){
            arr[i][j] = 0;
        }
    }
    int num=1;
    int i=0;
    int m=0,k=0;
    while (num<=N*N){
        if (i<N){
            for (int m=0;m<=i;m++){
                arr[m][i-m]=num;
                num+=1;
            }
        }
        else{ //i=5
            for (int m=i+1-N;m<N;m++){
                if(i-m >= 0 && i-m < N){  // ✓ 범위 체크
                    arr[m][i-m] = num;
                    num++;
                }
            }
        }
        
        i+=1;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < N; i++){
        free(arr[i]);  // 각 행 먼저
    }
    free(arr);  // 배열 자체
}
    else{
        printf("ERROR");
    }
}