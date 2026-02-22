#include <stdio.h>

int x(int score[]);

int main() {
    
    int i;
    int score[4];
    for(i=0;i<4;i++){
        scanf("%d",&score[i]);
    }
    
    int result = x(score);
    printf("%d\n",result);

    return 0;
}

int x(int score[]) {
    int i;
    int min = score[0];
    int sum = 0;

    for(i=0;i<4;i++) {
        sum += score[i];
        if(score[i]<min) {
            min = score[i];
        }
    }

    return sum-min;
}