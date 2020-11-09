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
int lp=0;//getline position 
double val[MAX_VAL];
void getline(char []);
int getop(char []);
int getops(char [],char []);
void push(double);
double pop(void);
int main(){
    int type ; 
    double op1 ,op2;
    char line[MAX_OP];
    char s[MAX_OP];
    getline(line);
    while ((type = getops(s,line))!=EOF){
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
                else printf("Error, Divide by zero !\n");
                break;
            case '%':
                op2=pop();
                op1=pop();
                if (op2!=0) push(op1-op2*(floor(op1/op2)));
                else puts("Error, Mod by zero !");
                break;
            case '\n':
                printf("= %.2f\n",pop()) ;
                lp=0;
                getline(line);
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
int  getch(void);
void ungetch(int);
int  getop(char s[]){
    int i,c;

    while((s[0]=c=getch())==' '||c=='\t') ; 
    //s[0] is the char which is neither tab nor space
    s[1]='\0';//ensure the end of string will be '\0'
    if(!isdigit(c)&&c!='.'&&c!='-')
        return c; //operator or \n
    i=1;
    if(c=='-')  {
        while(isdigit(s[i]=c=getch())) i++;
        if (i==1)   { s[i]='\0';return s[0]; ungetch(c);}
    } 
    if(isdigit(c))//collect integer part
        while(isdigit(s[i++]=c=getch()));
    if(c=='.')//'.'has already in the string 
        while(isdigit(s[i++]=c=getch()));
    s[i]='\0';
    if(c!=EOF&&c!=' '&&c!='\t')  ungetch(c);//read too much char
    return NUMBER;
}
int getops(char s[],char line[]){
    int i,c;

    while((s[0]=c=line[lp++])==' '||c=='\t'); 
    //s[0] is the char which is neither tab nor space
    s[1]='\0';//ensure the end of string will be '\0'
    if(!isdigit(c)&&c!='.'&&c!='-')
        return c; //operator or \n
    i=1;
    if(c=='-')  {
        while(isdigit(s[i]=c=line[lp++])) i++;
        if (i==1)   { s[i]='\0';return s[0]; lp--;}
    } 
    if(isdigit(c))//collect integer part
        while(isdigit(s[i++]=c=line[lp++]));
    if(c=='.')//'.'has already in the string 
        while(isdigit(s[i++]=c=line[lp++]));
    s[i]='\0';
    if(c!=EOF&&c!=' '&&c!='\t')  lp--;//read too much char
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
void getline(char s[]){
    int i=0,c;
    for(i=0;i!=MAX_OP;i++)
        s[i]=0;
    i=0;
    while ((s[i++]=c=getchar())!=EOF&&c!='\n'&&i!=MAX_OP);
    s[i]='\n';
}