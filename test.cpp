#include<stdio.h>
#include<stdlib.h>
int main(){
    float a,b;
    char c;
    printf("What operation would you like to perform ?\n\tA> Addiction\n\tB> Substraction\n\tC> Multiplication\n\tD> Division\n");
    scanf("%c",&c);
    printf("Please enter first number: ");
    scanf("%f",&a);
    printf("Please enter second number: ");
    scanf("%f",&b);
    printf("\n");
    switch(c){
        case 'A' : case 'a':
            printf("%f + %f = %f",a,b,a+b);
            break;
        case 'B' : case 'b':
            printf("%f - %f = %f",a,b,a-b);
            break;
        case 'C' : case 'c':
            printf("%f * %f = %f",a,b,a*b);
            break;
        case 'D' : case 'd':
            printf("%f / %f = %f",a,b,a/b);
            break;
    }    
    return 0;
}