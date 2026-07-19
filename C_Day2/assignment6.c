#include <stdio.h>

// 명령어가 add인지 확인
int is_add(char cmd[10]) {
    if (cmd[0] == 'a' && cmd[1] == 'd' && cmd[2] == 'd' && cmd[3] == '\0') {
        return 1;
    }
    return 0;
}

// 명령어가 remove인지 확인
int is_remove(char cmd[10]) {
    if (cmd[0] == 'r' && cmd[1] == 'e' && cmd[2] == 'm' && cmd[3] == 'o' && cmd[4] == 'v' && cmd[5] == 'e' && cmd[6] == '\0') {
        return 1;
    }
    return 0;
}

// 명령어가 check인지 확인
int is_check(char cmd[10]) {
    if (cmd[0] == 'c' && cmd[1] == 'h' && cmd[2] == 'e' && cmd[3] == 'c' && cmd[4] == 'k' && cmd[5] == '\0') {
        return 1;
    }
    return 0;
}

// 명령어가 toggle인지 확인
int is_toggle(char cmd[10]) {
    if (cmd[0] == 't' && cmd[1] == 'o' && cmd[2] == 'g' && cmd[3] == 'g' && cmd[4] == 'l' && cmd[5] == 'e' && cmd[6] == '\0') {
        return 1;
    }
    return 0;
}

// 명령어가 all인지 확인
int is_all(char cmd[10]) {
    if (cmd[0] == 'a' && cmd[1] == 'l' && cmd[2] == 'l' && cmd[3] == '\0') {
        return 1;
    }
    return 0;
}

// 명령어가 empty인지 확인
int is_empty(char cmd[10]) {
    if (cmd[0] == 'e' && cmd[1] == 'm' && cmd[2] == 'p' && cmd[3] == 't' && cmd[4] == 'y' && cmd[5] == '\0') {
        return 1;
    }
    return 0;
}

// 문자열을 정수로 변환
int string_to_int(char str[10]) {
    int num = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

// 집합 출력
void print_set(int set[21]) {
    printf("집합: { ");
    int first = 1;
    for (int i = 1; i <= 20; i++) {
        if (set[i] == 1) {
            if (first == 0) printf(", ");
            printf("%d", i);
            first = 0;
        }
    }
    printf(" }\n\n");
}

int main() {
    int set[21] = {0};  // 1~20의 원소 유무를 저장
    char cmd[10];
    char arg[10];
    int x;
    int i;
    printf("연산을 선택하세요. (1<=X<=20)\nadd X\nremove X\ncheck X\ntoggle X\nall 0\nempty 0\n\n");
    while (1) {
        printf("Input : ");
        
        // scanf로 명령어와 인자 입력받기
        scanf("%s %s", cmd, arg);
        
        // 명령어 처리
        if (is_add(cmd) == 1) {
            x = string_to_int(arg);
            if (x >= 1 && x <= 20) {
                set[x] = 1;
            }
        }
        else if (is_remove(cmd) == 1) {
            x = string_to_int(arg);
            if (x >= 1 && x <= 20) {
                set[x] = 0;
            }
        }
        else if (is_check(cmd) == 1) {
            x = string_to_int(arg);
            // check 결과 출력
            printf("%d\n", set[x]);
            print_set(set);
            continue;
        }
        else if (is_toggle(cmd) == 1) {
            x = string_to_int(arg);
            if (x >= 1 && x <= 20) {
                if (set[x] == 0) {
                    set[x] = 1;
                } else {
                    set[x] = 0;
                }
            }
        }
        else if (is_all(cmd) == 1) {
            for (i = 1; i <= 20; i++) {
                set[i] = 1;
            }
        }
        else if (is_empty(cmd) == 1) {
            for (i = 1; i <= 20; i++) {
                set[i] = 0;
            }
        }
        
        // 현재 집합 출력
        print_set(set);
    }
    
    return 0;
}