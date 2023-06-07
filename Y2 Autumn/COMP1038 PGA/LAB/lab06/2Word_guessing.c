#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main(void)
{
    char ans; 
    char c;
    do{
        // 输入number以及words
        int num;
        printf("Number of words: ");
        scanf("%d", &num);

        int i;
        char arr[num][31];
        for (i=0;i<num;i++){
            printf("Enter word: ");
            scanf("%s", arr[i]);
        }

        // 生成随机数
        srand((unsigned)time(NULL));
        int rnd = rand()%num;   // [0,num]
        printf("\nrnd = %d\n", rnd);
        int len = strlen(arr[rnd]);
        printf("len = %d\n", len);

        // 生成空白数组
        char blk[31];
        for (i=0; i<31; i++){   // initilization
            blk[i] = '\0';
        }
        for (i=0; i<len; i++){
            blk[i] = '_';
        }

        // test printing
        printf("%s\n", blk);

        // guess loop
        char guess;
        int live = 5, cnt = 0;  // cnt来计算一个字符在单词中出现了几遍
        int pos[len];
        bool flag;              // 来标记是否完成猜测
        while (live > 0){
            cnt = 0;            // 每轮循环初始化
            flag = true;

            printf("Guess (%d lives): ", live);
            scanf("%c", &guess);
            while ((c=getchar()) != '\n' && c != EOF);
            for (i=0; i<len; i++){
                if (guess == arr[rnd][i]){
                    pos[cnt] = i;   // 如果找到相同的，把字母的位置存到pos数组里
                    cnt++;
                }
            }
            if (cnt <= 0){
                live--;
            } else {
                for(i=0;i<cnt;i++){
                    blk[pos[i]] = guess;
                }
            }

            printf("%s\n\n", blk);

            // check if the word is completed
            for (i=0;i<len;i++){
                if (blk[i] == '_'){
                    flag = false;   // not completed
                }
            }
            if (flag == true){
                break;
            }
        }

        // 退出循环有两种可能，错误次数太多，和猜对了
        if (live <= 0){
            printf("Mission FAILED! You are dead!\n");
        } else {
            printf("Mission SUCCEED! Thank you captain!\n");
        }

        printf("do you wanna play again? (y/n) ");
        scanf("%c", &ans);
        while ((c=getchar()) != '\n' && c != EOF);
        printf("\n");
        
    }while(ans == 'y');

    return 0;
}