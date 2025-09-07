#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

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

int main(void){
  int num, count;
  scanf("%d", &num);
  int first[num], second[num], third[num], first_final[num], second_final[num], third_final[num];
  // 초기 상태
  scanf("%d",&count);
  set(first,count,num);
  scanf("%d",&count);
  set(second,count,num);
  scanf("%d",&count);
  set(third,count,num);
  // 최종 상태
  scanf("%d",&count);
  set(first_final,count,num);
  scanf("%d",&count);
  set(second_final,count,num);
  scanf("%d",&count);
  set(third_final,count,num);
  
  /*
  print_tower(first,num);
  print_tower(second,num);
  print_tower(third,num);
  print_tower(first_final,num);
  print_tower(second_final,num);
  print_tower(third_final,num);
  */

  return 0;
}