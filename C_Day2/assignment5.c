#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main (void){
    int min, max;              // 범위의 최솟값과 최댓값
    int square_num_index=0;    // 완전제곱수 배열의 현재 인덱스
    int arr[100]={0,};         // 완전제곱수를 저장할 배열
    
    printf("min: ");
    scanf("%d",&min);
    printf("max: ");
    scanf("%d",&max);
    
    // ============ 1단계: min부터 max까지의 범위에서 완전제곱수 찾기 ============
    for(int i=min;i<=max;i++){
        // 각 숫자 i에 대해 j*j == i인지 확인
        for (float j=2;j<=i;j++){
            if (i==j*j){  // i가 완전제곱수면
                //printf("%d ",i);
                arr[square_num_index]=i;  // 배열에 저장
                square_num_index+=1;      // 인덱스 증가
                break;                    // 내부 반복문 종료
            }
        }
    }

    // ============ 2단계: 완전제곱수로 나누어떨어지지 않는 수의 개수 세기 ============
    int num=0;  // 조건을 만족하는 수의 개수
    
    for(int i=min; i<=max; i++){
        int is_divisible = 0;  // 나누어떨어지는지 확인하는 플래그 (0=나누어떨어지지 않음, 1=나누어떨어짐)
        
        // 찾은 모든 완전제곱수로 i가 나누어떨어지는지 확인
        for(int j=0; j<square_num_index; j++){
            if(arr[j] != 0 && i % arr[j] == 0){  // i가 arr[j]로 나누어떨어지면
                is_divisible = 1;  // 플래그를 1로 설정
                break;             // 확인 종료 (이미 나누어떨어짐을 알았으므로)
            }
        }
        
        // 완전제곱수로 나누어떨어지지 않으면 개수 증가
        if(!is_divisible){
            //printf("%d ", i);
            num+=1;  // 개수 1 증가
        }
    }
    
    printf("제곱 ㄴㄴ수: %d개",num);  // 완전제곱수로 나누어떨어지지 않는 수의 개수 출력
    printf("\n");

    // ============ 3단계: 조건을 만족하는 모든 수 출력 ============
    for(int i=min; i<=max; i++){
        int is_divisible = 0;  // 나누어떨어지는지 확인하는 플래그
        
        // 찾은 모든 완전제곱수로 i가 나누어떨어지는지 확인
        for(int j=0; j<square_num_index; j++){
            if(arr[j] != 0 && i % arr[j] == 0){  // i가 arr[j]로 나누어떨어지면
                is_divisible = 1;  // 플래그를 1로 설정
                break;             // 확인 종료
            }
        }
        
        // 완전제곱수로 나누어떨어지지 않으면 출력
        if(!is_divisible){
            printf("%d ", i);  // 해당 숫자를 화면에 출력
        }
    }
    
    return 0;
}