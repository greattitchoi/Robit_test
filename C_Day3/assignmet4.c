#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main (void){
    int *arr;
    int num;
    int result=0;   //예외처리 검증
    printf("몇개의 원소를 할당하시겠습니까? : ");
    result=scanf("%d",&num);
    if (result==1){
    arr=(int*)malloc(sizeof(int)*num);
    for (int i=0;i<num;i++){
        printf("정수형 데이터: ");
        scanf("%d",&arr[i]);
    }
    int max=arr[0], min=arr[0],sum=0;
    for (int i=0;i<num;i++){
        if (max<=arr[i]){
            max=arr[i];
        }
        if (min>=arr[i]){
            min=arr[i];
        }
        sum+=arr[i];
    }
    printf("최댓값: %d\n",max);
    printf("최솟값: %d\n",min);
    printf("전체합: %d\n",sum);
    printf("평균: %f",sum/(float)num);
    free(arr);  // 반드시 필요!
    return 0;
}
    else{
        printf("ERROR");
    }
}