#include<stdio.h>
#include<stdlib.h>
int main(){
    int a;
    printf("請輸入一個整數\n");
    while(scanf("%d",&a))
        switch(a%2){
            case 1:
                printf("%d是奇數\n",a);
                break;
            case 0:
                printf("%d是偶數\n",a);
                break;
        }
    return 0;
}