#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int compare_string(char arr[9]){
    int result =0;         // 판단 결과를 저장할 변수 (초기값: 0=섞임)
    int distin =1;         // 일치 여부 확인 플래그 (1=일치, 0=불일치)
    
    // ============ 오름차순 패턴 ============
    // 음: C D E F G A B C (한 옥타브)
    char compare_arr[9]={"cdefgabC"};  // 오름차순 비교 배열
    
    // 입력된 배열과 오름차순 배열 비교
    for (int i=0;i<8;i++){
        if (compare_arr[i]!=arr[i]){  // 한 글자라도 다르면
            distin =0;                 // 불일치 표시
        }
    }
    
    // 오름차순 패턴과 일치하면 result를 1로 설정
    if (distin==1){
        result=1;  // 1 = ascending (오름차순)
    }
    
    // ============ 내림차순 패턴 ============
    distin=1;                           // 플래그 다시 초기화
    char reverse_compare_arr[9]={"Cbagfedc"};  // 내림차순 비교 배열
    
    // 입력된 배열과 내림차순 배열 비교
    for (int i=0;i<8;i++){
        if (reverse_compare_arr[i]!=arr[i]){  // 한 글자라도 다르면
            distin =0;                         // 불일치 표시
        }
    }
    
    // 내림차순 패턴과 일치하면 result를 2로 설정
    if (distin==1){
        result=2;  // 2 = descending (내림차순)
    }
    
    return result;  // 판단 결과 반환
}

int main (void){
    printf("음 입력: ");
    char arr[9];  // 8글자의 음을 입력받을 배열 (null terminator 포함하여 9)
    scanf("%s",&arr);  // 사용자로부터 음의 높낮이 입력 (예: "cdefgabC")
    
    // compare_string 함수를 통해 입력된 음의 패턴을 분류
    int distinction=compare_string(arr);
    
    // ============ 결과에 따른 출력 ============
    switch (distinction){
        case 0:
            printf("mixed");           // 0: 오름차순도, 내림차순도 아님 (섞임)
            break;
        case 1:
            printf("ascending");       // 1: 오름차순 패턴
            break;
        case 2:
            printf("descending");      // 2: 내림차순 패턴
            break;
        default:
            break;
    }
    
    return 0;
}