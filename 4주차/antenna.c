#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} S;

typedef struct {
    int first;
    int second;
    long long length;
} SL;

int compare(const void *a, const void *b){
    SL num1 = *(SL *)a;
    SL num2 = *(SL *)b;
    if(num1.length < num2.length){
        return -1;
    } else if(num1.length == num2.length){
        return 0;
    } else{
        return 1;
    }
}

int find_root(int *lss, int number){
    if(lss[number] == number){
        return number;
    }
    return find_root(lss,lss[number]);
}

int main(void){
    int num, row = 0, lss_idx = 0, line = 0;
    long long max = 0;
    scanf("%d", &num);
    S *lsss = (S *)malloc(sizeof(S) * num);
    int *check = (int *)malloc(sizeof(int)*num);
    for(int i=0 ; i<num ; i++){
        scanf("%d %d",&lsss[i].x, &lsss[i].y);
        row += (num - 1 - i);
        check[i] = i;
    }
    SL *lss = (SL *)malloc(sizeof(SL) * row);
    for(int i=0 ; i<num ; i++){
        for(int j=i+1 ; j<num ; j++){
            lss[lss_idx].first = i;
            lss[lss_idx].second = j;
            lss[lss_idx++].length = (long long)(lsss[i].x - lsss[j].x)*(long long)(lsss[i].x - lsss[j].x) + (long long)(lsss[i].y - lsss[j].y)*(long long)(lsss[i].y - lsss[j].y);
        }
    }
    qsort(lss, row, sizeof(SL), compare);

    for(int i=0 ; i<row ; i++){
        if(line >= num - 1){
            break;
        }
        int checking1 = find_root(check,lss[i].first), checking2 = find_root(check,lss[i].second);
        if(checking1 != checking2){
            line++;
            check[checking2] = check[checking1];
            max = lss[i].length;
        }
    }

    printf("%.7lf\n",sqrt(max) / 2);

    free(lsss);
    free(lss);
    free(check);

    return 0;
}