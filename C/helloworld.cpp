#include<stdio.h>
#include<stdlib.h>
int main(){
    int x,y,counter=0;
    int **arr;
    scanf("%d%d",&x,&y);
    arr=(int**)malloc(sizeof(int*)*x);
    for(int i = 0; i!=x;i++){
        arr[i]=(int*)malloc(sizeof(int)*y);
        for(int j=0;j!=y;j++)
            arr[i][j]=++counter;
    }
    for(int i=0;i!=x;i++){
        for(int j=0;j!=y;j++)
            printf ("%0.1f\t",(float)arr[i][j]);
        printf ("\n");
    }
    
    return 0;
}