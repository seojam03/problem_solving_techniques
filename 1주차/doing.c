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

void hanoi(int num, S *from, S *tmp, S *to, int now, int next){
  if(now != next){
    if(now == 1 && next == 2){
      // 다음 주요수를 3으로 이동
      
    } else if(now == 1){
      // 다음 주요수를 2으로 이동
    } else if(now == 2 && next == 1){
      // 다음 수를 3으로 이동
    } else if(now == 2){
      // 다음 수를 1로 이동
    } else if(now == 3 && next == 1){
      // 다음 수를 2로 이동
    } else if(now == 3){
      // 다음 수를 1로 이동
    }

  } else{
    if(now == 1){
      // 다음 수를 1로 이동
    } else if(now == 2){
      // 다음 수를 2로 이동
    } else if(now == 3){
      // 다음 수를 3으로 이동
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
  for(int i=0 ; i<first.number ; i++){
    set_where[first.lss[i] - 1] = 1;
  }
  for(int i=0 ; i<second.number ; i++){
    set_where[second.lss[i] - 1] = 2;
  }
  for(int i=0 ; i<third.number ; i++){
    set_where[third.lss[i] - 1] = 3;
  }

  for(int i=0 ; i<first_final.number ; i++){
    final_where[first_final.lss[i] - 1] = 1;
  }
  for(int i=0 ; i<second_final.number ; i++){
    final_where[second_final.lss[i] - 1] = 2;
  }
  for(int i=0 ; i<third_final.number ; i++){
    final_where[third_final.lss[i] - 1] = 3;
  }

  // // 샘플
  // S first_sample, second_sample, third_sample;
  // first_sample.lss = (int *)malloc(sizeof(int) * num);
  // second_sample.lss = (int *)malloc(sizeof(int) * num);
  // third_sample.lss = (int *)malloc(sizeof(int) * num);
  // if(first.lss[0] == num){
  //   for(int i=0 ; i < num ; i++){
  //     first_sample.lss[i] = num-i;
  //     second_sample.lss[i] = 0;
  //     third_sample.lss[i] = 0;
  //   }
  //   first_sample.number = num;
  //   second_sample.number = 0;
  //   third_sample.number = 0;

  //   // 1이 시작, 2/3이 목적
  //   if(second_final.lss[0] == num){
  //     hanoi(num, &first_sample, &third_sample, &second_sample);
  //   } else if(third_final.lss[0] == num){
  //     hanoi(num, &first_sample, &second_sample, &third_sample);
  //   }
  // } else if(second.lss[0] == num) {
  //   for(int i=0 ; i < num ; i++){
  //     first_sample.lss[i] = 0;
  //     second_sample.lss[i] = num-i;
  //     third_sample.lss[i] = 0;
  //   }
  //   first_sample.number = 0;
  //   second_sample.number = num;
  //   third_sample.number = 0;

  //   // 2가 시작, 1/3이 목적
  //   if(first_final.lss[0] == num){
  //     hanoi(num, &second_sample, &third_sample, &first_sample);
  //   } else if(third_final.lss[0] == num){
  //     hanoi(num, &second_sample, &first_sample, &third_sample);
  //   }
  // } else if(third.lss[0] == num) {
  //   for(int i=0 ; i < num ; i++){
  //     first_sample.lss[i] = 0;
  //     second_sample.lss[i] = 0;
  //     third_sample.lss[i] = num-i;
  //   }
  //   first_sample.number = 0;
  //   second_sample.number = 0;
  //   third_sample.number = num;

  //   // 3이 시작, 1/2가 목적
  //   if(first_final.lss[0] == num){
  //     hanoi(num, &third_sample, &second_sample, &first_sample);
  //   } else if(third_final.lss[0] == num){
  //     hanoi(num, &third_sample, &first_sample, &second_sample);
  //   }
  // }
  
  // printf("\n------------\n");
  // print_tower(first_sample.lss,num);
  // printf("%d \n",first_sample.number);
  // print_tower(second_sample.lss,num);
  // printf("%d \n",second_sample.number);
  // print_tower(third_sample.lss,num);
  // printf("%d \n",third_sample.number);
  
  /*
  print_tower(first.lss,num);
  printf("%d \n",first.number);
  print_tower(second.lss,num);
  printf("%d \n",second.number);
  print_tower(third.lss,num);
  printf("%d \n",third.number);
  print_tower(first_final.lss,num);
  printf("%d \n",first_final.number);
  print_tower(second_final.lss,num);
  printf("%d \n",second_final.number);
  print_tower(third_final.lss,num);
  printf("%d \n",third_final.number);
  */


  free(first.lss);
  free(second.lss);
  free(third.lss);
  free(first_final.lss);
  free(second_final.lss);
  free(third_final.lss);
  return 0;
}