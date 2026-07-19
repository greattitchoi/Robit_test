#include <stdio.h>

// 두 문자열이 같은지 비교 (위치부터 길이만큼)
int compare_string(char input[200], int start, char sub[50], int sub_len) {
    for (int i = 0; i < sub_len; i++) {
        if (input[start + i] != sub[i]) {
            return 0;
        }
    }
    return 1;
}

// 문자열 길이 구하기
int get_length(char str[200]) {
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        len++;
    }
    return len;
}

int main() {
    char inputStr[200];
    char subStr[50];
    int positions[100];  // 찾은 위치를 저장할 배열
    int position_count = 0;
    int input_len;
    int sub_len;
    int i;
    int j;
    
    printf("최대 99개 문자 입력 <inputStr> : ");
    scanf("%s", inputStr);
    
    printf("찾는 문자열 <subStr> : ");
    scanf("%s", subStr);
    
    // 문자열 길이 구하기
    input_len = get_length(inputStr);
    sub_len = get_length(subStr);
    
    // 찾을 문자열이 입력 문자열보다 길면 찾을 수 없음
    if (sub_len > input_len) {
        printf("%s의 위치 : 찾을 수 없음\n", subStr);
        return 0;
    }
    
    // 입력 문자열에서 찾을 문자열의 위치 찾기
    for (i = 0; i <= input_len - sub_len; i++) {
        // i번째 위치부터 찾을 문자열과 비교
        if (compare_string(inputStr, i, subStr, sub_len) == 1) {
            positions[position_count] = i + 1;  // 1부터 시작하는 위치
            position_count++;
        }
    }
    
    // 결과 출력
    printf("%s의 위치 : ", subStr);
    
    if (position_count == 0) {
        printf("찾을 수 없음\n");
    } else {
        for (i = 0; i < position_count; i++) {
            if (i > 0) printf(", ");
            printf("%d", positions[i]);
        }
        printf("\n");
    }
    
    return 0;
}