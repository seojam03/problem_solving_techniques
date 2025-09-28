#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int end_three_idx = 3;

int main(void){
    int num, i;
    scanf("%d",&num);
    int *end_three = (int *)malloc(sizeof(int) * num);
    int *lss = (int *)malloc(sizeof(int) * num);
    end_three[0] = 0;
    end_three[1] = 0;
    end_three[2] = 1;
    lss[0] = 1;
    lss[1] = 2;
    lss[2] = 4;
    for(i=0 ; i<num-3 ; i++){
        end_three[end_three_idx + i] = lss[end_three_idx + i - 3] - end_three[end_three_idx + i -3];
        lss[end_three_idx + i] = lss[end_three_idx + i - 1] + lss[end_three_idx + i - 2] + end_three[end_three_idx + i];

        if(end_three[end_three_idx + i] > 1004){
            end_three[end_three_idx + i] %= 1004; 
        } else if(end_three[end_three_idx + i] < 0){
            end_three[end_three_idx + i] += 1004;
        }
        if(lss[end_three_idx + i] > 1004){
            lss[end_three_idx + i] %= 1004; 
        } else if(lss[end_three_idx + i] < 0){
            lss[end_three_idx + i] += 1004;
        }
    }

    if(num > 3){
        printf("%d\n", lss[end_three_idx + i - 1]);
    } else{
        if(num == 1){
        printf("%d\n", 1);
        } else if(num == 2){
        printf("%d\n", 2);
        } else if(num == 3){
        printf("%d\n", 4);
        }
    }

    free(lss);
    free(end_three);
    return 0;
}