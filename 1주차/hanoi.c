#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int seojam=0;
int check=0;

void set(int *lss, int count, int num){
  for(int i=0 ; i < count ; i++){
    scanf("%d", &lss[i]);
  }
  for(int i=count ; i<num ; i++){
    lss[i] = 0;
  }
}

void print_tower(int *lss, int num){
  for(int i=0 ; i<num ; i++){
    printf("%d ",lss[i]);
  }
  printf("\n");
}

typedef struct{
  int *lss;
  int number;
} S;

int isSame(int num, S firstA, S secondA, S thirdA, S firstB, S secondB, S thirdB){
  for(int i=0 ; i<num ; i++){
    if(firstA.lss[i] != firstB.lss[i]){
      return 0;
    } else if(secondA.lss[i] != secondB.lss[i]){
      return 0;
    } else if(thirdA.lss[i] != thirdB.lss[i]){
      return 0;
    }
  }
  return 1;
}

void orignal_hanoi(int num, S *from, S *tmp, S *to){
    if(num == 1){
        from->lss[--from->number] = 0;
        to->lss[to->number++] = 1;
        seojam++;
    } else {
        orignal_hanoi(num - 1, from, to, tmp);
        from->lss[--from->number] = 0;
        to->lss[to->number++] = num;
        seojam++;
        orignal_hanoi(num - 1, tmp, from, to);
    }
}

void hanoi(int num, S *from, S *tmp, S *to, int now, int next, int *now_where, int max){
    if(num == 1){
        if(now != next){
            if(now == 1 && next == 2){
                from->lss[--from->number] = 0;
                tmp->lss[tmp->number++] = 1;
                now_where[num-1] = 2;
                seojam++;
            } else if(now == 1){
                from->lss[--from->number] = 0;
                to->lss[to->number++] = 1;
                now_where[num-1] = 3;
                seojam++;
            } else if(now == 2 && next == 1){
                tmp->lss[--tmp->number] = 0;
                from->lss[from->number++] = 1;
                now_where[num-1] = 1;
                seojam++;
            } else if(now == 2){
                tmp->lss[--tmp->number] = 0;
                to->lss[to->number++] = 1;
                now_where[num-1] = 3;
                seojam++;
            } else if(now == 3 && next == 1){
                to->lss[--to->number] = 0;
                from->lss[from->number++] = 1;
                now_where[num-1] = 1;
                seojam++;
            } else if(now == 3){
                to->lss[--to->number] = 0;
                tmp->lss[tmp->number++] = 1;
                now_where[num-1] = 2;
                seojam++;
            }
        }
    // 1이 아닐 때 순환
    } else {
        if(now != next){
            if(now == 1 && next == 2){
                hanoi(num-1, from, tmp, to, now_where[num-2], 3, now_where, max);
    
                from->lss[--from->number] = 0;
                tmp->lss[tmp->number++] = num;
                now_where[num-1] = 2;
                seojam++;
                
                if(num-1 != max-1) orignal_hanoi(num-1, to, from, tmp);
            } else if(now == 1){
              // 다음 수를 2으로 이동
                hanoi(num-1, from, tmp, to, now_where[num-2], 2, now_where, max);
    
                from->lss[--from->number] = 0;
                to->lss[to->number++] = num;
                now_where[num-1] = 3;
                seojam++;
    
                if(num-1 != max-1) orignal_hanoi(num-1, tmp, from, to);
            } else if(now == 2 && next == 1){
              // 다음 수를 3으로 이동
                hanoi(num-1, from, tmp, to, now_where[num-2], 3, now_where, max);
    
                tmp->lss[--tmp->number] = 0;
                from->lss[from->number++] = num;
                now_where[num-1] = 1;
                seojam++;
    
                if(num-1 != max-1) orignal_hanoi(num-1, to, tmp, from);
            } else if(now == 2){
              // 다음 수를 1로 이동
                hanoi(num-1, from, tmp, to, now_where[num-2], 1, now_where, max);
    
                tmp->lss[--tmp->number] = 0;
                to->lss[to->number++] = num;
                now_where[num-1] = 3;
                seojam++;
    
                if(num-1 != max-1) orignal_hanoi(num-1, from, tmp, to);
            } else if(now == 3 && next == 1){
              // 다음 수를 2로 이동
                hanoi(num-1, from, tmp, to, now_where[num-2], 2, now_where, max);
    
                to->lss[--to->number] = 0;
                from->lss[from->number++] = num;
                now_where[num-1] = 1;
                seojam++;
    
                if(num-1 != max-1) orignal_hanoi(num-1, tmp, to, from);
            } else if(now == 3){
              // 다음 수를 1로 이동
                hanoi(num-1, from, tmp, to, now_where[num-2], 1, now_where, max);
            
                to->lss[--to->number] = 0;
                tmp->lss[tmp->number++] = num;
                now_where[num-1] = 2;
                seojam++;
    
                if(num-1 != max-1) orignal_hanoi(num-1, from, to, tmp);
            }
        } else {
            if(now == 1){
              // 다음 수를 1로 이동
                if(num-1 != max-1) hanoi(num-1, from, tmp, to, now_where[num-2], 1, now_where, max);
    
            } else if(now == 2){
              // 다음 수를 2로 이동
                if(num-1 != max-1) hanoi(num-1, from, tmp, to, now_where[num-2], 2, now_where, max);
    
            } else if(now == 3){
              // 다음 수를 3으로 이동
                if(num-1 != max-1) hanoi(num-1, from, tmp, to, now_where[num-2], 3, now_where, max);
            }
        }
    }
}

int main(void){
    int num, count;
    scanf("%d", &num);
    S first, second, third, first_final, second_final, third_final;
    first.lss = (int *)malloc(sizeof(int) * num);
    second.lss = (int *)malloc(sizeof(int) * num);
    third.lss = (int *)malloc(sizeof(int) * num);
    first_final.lss = (int *)malloc(sizeof(int) * num);
    second_final.lss = (int *)malloc(sizeof(int) * num);
    third_final.lss = (int *)malloc(sizeof(int) * num);

    // 초기 상태
    scanf("%d",&count);
    first.number = count;
    set(first.lss,count,num);

    scanf("%d",&count);
    second.number = count;
    set(second.lss,count,num);

    scanf("%d",&count);
    third.number = count;
    set(third.lss,count,num);
    // 최종 상태
    scanf("%d",&count);
    first_final.number = count;
    set(first_final.lss,count,num);

    scanf("%d",&count);
    second_final.number = count;
    set(second_final.lss,count,num);

    scanf("%d",&count);
    third_final.number = count;
    set(third_final.lss,count,num);
    
    // 초기 상태의 원판들이 1번, 2번, 3번 어디에 위치하는지 (1원판은 0인덱스에 위치 저장, ...)
    int set_where[num], final_where[num];

    for(int i=0 ; i<first_final.number ; i++){
        final_where[first_final.lss[i] - 1] = 1;
    }
    for(int i=0 ; i<second_final.number ; i++){
        final_where[second_final.lss[i] - 1] = 2;
    }
    for(int i=0 ; i<third_final.number ; i++){
        final_where[third_final.lss[i] - 1] = 3;
    }


    for(int i=num ; i>=1 ; i--){
        for(int i=0 ; i<first.number ; i++){
            set_where[first.lss[i] - 1] = 1;
        }
        for(int i=0 ; i<second.number ; i++){
            set_where[second.lss[i] - 1] = 2;
        }
        for(int i=0 ; i<third.number ; i++){
            set_where[third.lss[i] - 1] = 3;
        }
        hanoi(i, &first, &second, &third, set_where[i-1], final_where[i-1], set_where, i);
    }

    printf("%d \n",seojam);

    // hanoi(num, &first, &second, &third, set_where[num-1], final_where[num-1], set_where, num);
    
    // print_tower(first.lss,num);
    // printf("%d \n",first.number);
    // print_tower(second.lss,num);
    // printf("%d \n",second.number);
    // print_tower(third.lss,num);
    // printf("%d \n",third.number);

    // printf("---------------\n");
    // for(int i=0 ; i<num ; i++){
    //     printf("%d %d\n",set_where[i],final_where[i]);
    // }

    // hanoi(num-1, &first, &second, &third, set_where[num-2], final_where[num-2], set_where, num-1);
    
    // print_tower(first.lss,num);
    // printf("%d \n",first.number);
    // print_tower(second.lss,num);
    // printf("%d \n",second.number);
    // print_tower(third.lss,num);
    // printf("%d \n",third.number);


    free(first.lss);
    free(second.lss);
    free(third.lss);
    free(first_final.lss);
    free(second_final.lss);
    free(third_final.lss);
    return 0;
}