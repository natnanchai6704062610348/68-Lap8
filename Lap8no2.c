#include <stdio.h>
int checkscore(char std[]);
int howmanypeople(char ans[][10],int num);
int questionsohard(char ans[][10],int num,int q);
char keys[10]={'D','B','D','C','C','D','A','E','A','D'};

int main() {
    int i,j;
    char ans[8][10]={
        	{'A','B','A','C','C','D','E','E','A','D'},//7
            {'D','B','A','B','C','A','E','E','A','D'},//6
            {'E','D','D','A','C','B','E','E','A','D'},//5
            {'C','B','A','E','D','C','E','E','A','D'},//4
            {'A','B','D','C','C','D','E','E','A','D'},//8
            {'B','B','E','C','C','D','E','E','A','D'},//7
            {'B','B','A','C','C','D','E','E','A','D'},//7
            {'E','B','E','C','C','D','E','E','A','D'}};//7

    
   
    for(i=0;i<8;i++){
        printf("std %d => %d\n", (i+1), checkscore(ans[i]));
    }printf("\n");

    int resul = howmanypeople(ans,8);
    printf("Someone answered question 1 correctly = %d people.\n",resul);

    int hard = questionsohard(ans,8,10);
    printf("questionhard = %d\n",hard);
    
    
    
}

int checkscore(char std[]){
    int i,score=0;

    for(i=0;i<10;i++){
        if(std[i]==keys[i]){
            score++;
        }
    }
    return score;
}

int howmanypeople(char ans[][10],int num){

    int i,count=0;
    for(i=0;i<num; i++){
        if(ans[i][0]==keys[0]){
            count++;
        }
    }

    return count;
}

int questionsohard(char ans[][10],int num,int q){

    int i, j;
    int min = num + 1;
    int hard = 0;

    for(i=0;i<q;i++){
        int co = 0;
        for(j=0;j<num;j++){
            if(ans[j][i]==keys[i]){
                co++;
            }
        }

        if(co<min){
            min = co;
            hard = i+1;
        }
    }

    return hard;

}