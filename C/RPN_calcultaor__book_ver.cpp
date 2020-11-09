#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
//Reverse Polish Calculator 
#define MAX_OP 100//limit for amount in a function
#define MAX_VAL 100//max depth of a stack 
#define NUMBER '0'// stand for a number 
int sp=0;//stack position 
double val[MAX_VAL];
int getop(char []);
void push(double);
double pop(void);
int main(){
    int type ; 
    double op2;
    char s[MAX_OP];

    while ((type = getop(s))!=EOF){
        switch(type){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop()+pop());
                break;
            case '*':
                push(pop()*pop());
                break;
            case '-':
                op2=pop();
                push(pop()-op2);
                break;
            case '/':
                op2=pop();
                if (op2!=0) push(pop()/op2) ;
                else printf("Error Devide by zero !\n");
                break;
            case '\n':
                printf("\t= %.2f\n",pop()) ;
                break;
            default :
                puts("Error :UNKOWN numerator or operator !");
                break;
        }        
    }
    return 0 ;     
}
void push(double n){
    if(sp<MAX_VAL)
        val[sp++]=n;
    else puts("Push failed, stack is now FULL !");
}
double pop(void){
    if (sp>0)
        return val[--sp];
    else puts("Pop failed, stack is now EMPTY");
    return -1;
}
//get op function 
int getch(void);
void ungetch(int);
int getop(char s[]){
    int i,c;

    while((s[0]=c=getch())==' '||c=='\t') ; 
    //s[0] is the char which is neither tab nor space
    s[1]='\0';//ensure the end of string will be '\0'
    if(!isdigit(c)&&c!='.')
        return c; //operator or \n
    i=1;
    if(isdigit(c))//collect integer part
        while(isdigit(s[i++]=c=getch()));
    if(c=='.')//'.'has already in the string 
        while(isdigit(s[i++]=c=getch()));
    s[i]='\0';
    if(c!=EOF&&c!=' '&&c!='\t')  ungetch(c);//read too much char
    return NUMBER;
}
#define BUF_SIZE 100
char buff[BUF_SIZE];
int bufp = 0 ;//pointer
int getch(void){
    return bufp>0? buff[bufp--]:getchar();
}
void ungetch(int c){
    if(bufp==BUF_SIZE)
        puts("Error : Buffer is FULL");
    else buff[bufp++]=c;
}