#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int value;
    int index;
} S;

int compare(const void *a, const void *b){
    int num1 = ((S*)a)->value;
    int num2 = ((S*)b)->value;
    return num2 - num1;
}

int smaller(int a, int b){
    if(a<b){
        return a;
    } else return b;
}

int main(void){
    int num, max_len, limit;
    scanf("%d",&num);
    int *origin_lss = (int *)malloc(sizeof(int)*num);
    S *lss = (S *)malloc(sizeof(S)*num);
    for(int i=0 ; i<num ; i++){
        scanf("%d",&lss[i].value);
        origin_lss[i] = lss[i].value;
        lss[i].index = i;
    }
    qsort(lss,num,sizeof(S),compare);
    
    for(int i=0 ; max_len < lss[i].value * 2 - 1 ; i++){
        limit = smaller(lss[i].index*2-1, (num - lss[i].index)*2-1);
        if(limit <= max_len) continue;
        limit = smaller(limit, lss[i].value*2-1);
        
    }
    


    // 출력
    // for(int i=0 ; i<num ; i++){
    //     printf("%d %d \n",lss[i].value, lss[i].index);
    // }


    free(lss);
    free(origin_lss);
    return 0;
}