/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort_numbers(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &n);

    if (n < 1 || n > 5) {
        printf("輸入錯誤，請輸入 1 到 5 之間的數字。\n");
        return 1;
    }

    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        printf("無法開啟檔案！\n");
        return 1;
    }

    srand((unsigned int)time(NULL));

    time_t now = time(NULL);
    char *time_str = ctime(&now);
    for (int i = 0; time_str[i] != '\0'; i++) {
        if (time_str[i] == '\n') {
            time_str[i] = '\0';
            break;
        }
    }

    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "= %s =\n", time_str);

    for (int row = 1; row <= 5; row++) {
        fprintf(fp, "[%d]: ", row);

        if (row <= n) {
            int nums[7];
            int count = 0;

            while (count < 7) {
                int r = (rand() % 69) + 1;
                int duplicate = 0;
                for (int k = 0; k < count; k++) {
                    if (nums[k] == r) {
                        duplicate = 1;
                        break;
                    }
                }
                if (!duplicate) {
                    nums[count] = r;
                    count++;
                }
            }

            sort_numbers(nums, 6);

            for (int k = 0; k < 7; k++) {
                fprintf(fp, "%02d", nums[k]);
                if (k < 6) {
                    fprintf(fp, " ");
                }
            }
            fprintf(fp, "\n");
        } else {
            fprintf(fp, "-- -- -- -- -- -- --\n");
        }
    }

    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);

    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    return 0;
}