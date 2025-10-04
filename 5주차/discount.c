#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int price;
    int sale;
} S;

int compare(const void *a, const void *b){
    S num1 = *(S*)a;
    S num2 = *(S*)b;
    return num1.price - num2.price;
}

int main(void){
    int num, discount, i, check = 0;
    long long total = 0, total_sale = 0;
    scanf("%d %d",&num, &discount);
    S *lss = (S *)malloc(sizeof(S) * num);
    for(i=0 ; i<num ; i++){
        scanf("%d",&lss[i].price);
        lss[i].sale = lss[i].price / 100 * discount;
        total += (long long)lss[i].price;
    }
    qsort(lss,num,sizeof(S),compare);

    if(i == 1){
        printf("%lld\n", total - (long long)lss[0].sale);
    } else if(i==2){
        printf("%lld\n", total - (long long)lss[0].sale - (long long)lss[1].sale);
    } else if(i==3){
        int counting = lss[0].sale + lss[1].sale + lss[2].sale;
        if(lss[0].price < counting){
                printf("%lld\n",total - (long long)counting);
            } else {
                printf("%lld\n",total - (long long)lss[0].price);
            }
    } else{
        int one, two, three, four, one_sale, two_sale, three_sale, four_sale;
        four = lss[--i].price;
        four_sale = lss[i].sale;
        three = lss[--i].price;
        three_sale = lss[i].sale;
        two = lss[--i].price;
        two_sale = lss[i].sale;
        one = lss[--i].price;
        one_sale = lss[i].sale;

        while(i >= 0){
            if(two < two_sale + three_sale + four_sale){
                total_sale += (long long)four_sale;
                if(i==0){
                    break;
                }
                four = three, four_sale = three_sale, three = two, three_sale = two_sale, two = one, two_sale = one_sale, one = lss[--i].price,one_sale = lss[i].sale;
            } else {
                if(two + one_sale >= one + four_sale){
                    total_sale += (long long)two;
                    if(i-3 < 0){
                        check = 1;
                        break;
                    }
                    four = one;
                    four_sale = one_sale;
                    three = lss[--i].price;
                    three_sale = lss[i].sale;
                    two = lss[--i].price;
                    two_sale = lss[i].sale;
                    one = lss[--i].price;
                    one_sale = lss[i].sale;
                } else {
                    total_sale += (long long)four_sale;
                    if(i==0){
                    break;
                    }
                    four = three, four_sale = three_sale, three = two, three_sale = two_sale, two = one, two_sale = one_sale, one = lss[--i].price,one_sale = lss[i].sale;
                }
            }
        }

        if(i == 0){
            if(check == 1){
                total_sale += (long long)one_sale;
            } else{
                if(one < one_sale + two_sale + three_sale){
                    total_sale = total_sale + (long long)(one_sale + two_sale + three_sale);
                } else {
                    total_sale += (long long)one;
                }
            }
        } else if(i == 1){
            total_sale = total_sale + (long long)(lss[0].sale + lss[1].sale);
        } else{
            int counting = lss[0].sale + lss[1].sale + lss[2].sale;
            if(lss[0].price < counting){
                    total_sale += (long long)counting;
                } else {
                    total_sale += (long long)lss[0].price;
                }
        }
        printf("%lld\n",total-total_sale);
        }

    free(lss);
    return 0;
}