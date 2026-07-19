#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void type1 (int num);
void type2 (int num);
void type3 (int num);
void type4 (int num);

int main (void){
    int num;
    int type;
    printf("사이즈(홀수 제외)와 종류를 입력하시오.(ex. 5 1): ");
    scanf ("%d %d",&num,&type);
    switch (type){
        case 1:
            type1(num);
            break;
        case 2:
            type2(num);
            break;
        case 3:
            type3(num);
            break;
        case 4:
            type4(num);
            break;
        default:
            printf("조건에 맞지 않습니다.");
    }
    return 0;
}
void type1 (int num){
    // 홀수만 처리
    if (num%2==1){
        // 위쪽 절반 (점점 커지는 삼각형)
        // 0부터 num/2+1까지 반복
        for (int i=0;i<num/2+1;i++){
            // 각 행마다 별의 개수 증가
            for (int j=0;j<num/2+1;j++){
                // i >= j일 때만 별(*) 출력, 아니면 공백( ) 출력
                // 이렇게 하면 좌측 삼각형 모양이 됨
                (i>=j)?printf("*"):printf(" ");
            }
            printf("\n");
        }
        
        // 아래쪽 절반 (점점 작아지는 삼각형)
        // num/2-1부터 0까지 역순 반복
        for (int i=num/2-1;i>=0;i--){
            // 각 행마다 별의 개수 감소
            for (int j=0;j<num/2;j++){
                (i>=j)?printf("*"):printf(" ");
            }
            printf("\n");
        }
    }
}

void type2(int num){
   if (num%2==1){
        // 위쪽 절반
        // 행(i)과 열(j)이 일정 값 이상일 때 별 출력
        for (int i=1;i<=num/2+1;i++){
            for (int j=1;j<=num/2+1;j++){
                // i+j >= num/2+2일 때 별 출력
                // 이 조건으로 우측 삼각형이 만들어짐
                (i+j>=num/2+2)?printf("*"):printf(" ");
            }
            printf("\n");
        }
        
        // 아래쪽 절반
        for (int i=num/2;i>=1;i--){
            for (int j=1;j<=num/2+1;j++){
                (i+j>=num/2+2)?printf("*"):printf(" ");
            }
            printf("\n");
        }
   }
}

void type3(int num){
    if(num%2==1){
        // 위쪽 절반
        for (int i=1;i<=num/2+1;i++){
            // num 개의 열을 순회
            for (int j=1;j<=num;j++){
                // 두 가지 조건을 모두 만족할 때 별 출력:
                // 1) i+j <= num+1 : 대각선 위쪽
                // 2) i <= j : 열이 행보다 크거나 같을 때
                (i+j<=num+1 && i<=j)?printf("*"):printf(" ");
            }
            printf("\n");
        }
        
        // 아래쪽 절반
        for (int i=num/2;i>=1;i--){
            for (int j=1;j<=num;j++){
                (i+j<=num+1 && i<=j)?printf("*"):printf(" ");
            }
            printf("\n");
        }
    }
}

void type4(int num){
    // 위쪽 절반 (점점 넓어지는 다이아몬드)
    for (int i=1;i<=num/2+1;i++){
        // num개의 열을 순회
        for (int j=1;j<=num;j++){
            // j >= i && j <= num/2+1일 때 별 출력
            // 이 조건으로 중앙을 기준으로 한 다이아몬드 모양이 됨
            (j>=i && j<=num/2+1)?printf("*"):printf(" ");
        }
        printf("\n");
    }
    
    // 아래쪽 절반 (점점 좁아지는 다이아몬드)
    for (int i=num/2;i>=1;i--){
        for (int j=1;j<=num;j++){
            // num/2+1 <= j && i+j <= num+1일 때 별 출력
            // 이 조건으로 대칭적인 다이아몬드 하단이 만들어짐
            (num/2+1<=j && i+j<=num+1)?printf("*"):printf(" ");
        }
        printf("\n");
    }
}