#include  <stdio.h>
#include  <stdlib.h>    /* exit(  ) で必要 */
#include  <string.h>    /* strlen(  ) で必要 */

#define MAX_LEN 256     /* １行の最大文字数 -1 */

int main(int argc, char const *argv[]);

int main(int argc, char const *argv[]) {
    FILE *fp;
    char string[MAX_LEN];            /* 文字列を読み込む配列 */
    int n = 1;                       /*行番号用カウンタ */
    int countChars; // count commented characters
    int countComments; // count the number of comments

    // File fail to open
    if ((fp = fopen("temperature_converter.c", "r")) == NULL) {
        fprintf(stderr, "Fail to open file!\n");
        exit (2);                    /* メッセージを表示して終了 */
    }

      /* ファイルから失敗するまで行単位で文字を読み込み */
    while ((fgets(string, MAX_LEN - 1, fp)) != NULL) {
        int arrLength = strlen(string) - 1;
        string[strlen(string) - 1] = '\0';     /* 余分な改行コードを削除 */
        // printf("%d:", n++);                    /*行番号を表示し */
        // puts(string);                          /*読み込んだ行を表示 */
        printf("Content: %s\n", string);
        int commentStatement = 1; // true=0, false=1
        for (int i = 0; i < arrLength; i++) {
            if (string[i] == '/') {
                if (string[i+1] == '/') {
                    printf("found a single line comment!\n");
                }
            }
        }

        //
        // if (string[0] == '/') {
        //     if (string[1] == '/') {
        //         printf("found a single line comment!\n");
        //     }
        // }
    }
    fclose(fp);                                /* ファイルを閉じる */
    return 0;

}
