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

int smaller(int a, int b, int c){
    if(a<b && a<c){
        return a;
    } else if(a<b){
        return c;
    } else if(b>c){
        return c;
    } else {
        return b;
    }
}

int recursive_pyramid(int num, int *lss, int index, int max){
    if(num == 0 || max>=(num*2+1)) return num;
    for(int i=1 ; i<=num ; i++){
        if((lss[index - i] < num - i + 1) || (lss[index + i] < num - i + 1) || (lss[index - num + i - 1] < i) || (lss[index + num - i + 1] < i)){
            return recursive_pyramid(num - 1, lss, index, max);
        }
    }
    return num;
}

int main(void){
    int num, max_len=0, limit, input_it;
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
        limit = smaller(lss[i].index*2+1, (num - lss[i].index)*2-1, lss[i].value*2-1);
        if(limit <= max_len) continue;
        
        input_it = recursive_pyramid(limit/2, origin_lss, lss[i].index, max_len)*2 + 1;
        if(input_it > max_len){
            max_len = input_it;
        }
    }
    printf("%d",max_len);

    free(lss);
    free(origin_lss);
    return 0;
}