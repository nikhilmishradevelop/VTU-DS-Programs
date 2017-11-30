#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100
char in[100],pf[100],stk[MAX];
int top=-1;
int pre(char op){
    if(op=='%'||op=='^')
        return 3;
    if(op=='*'||op=='/')
        return 2;
    return 1;
}
int isoperator(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='%')
        return 1;
    return 0;
}
void push(char a){
    stk[++top]=a;
}
char pop(){
    return stk[top--];
}
int main(){
    int i,c=0;
    printf("Enter an infix expression\n");
    scanf("%s",in);
    for(i=0;in[i]!='\0';i++){
        if(isalnum(in[i]))
           pf[c++]=in[i];
        else if(in[i]=='(')
            push(in[i]);
        else if(isoperator(in[i])){
            while(pre(in[i])<pre(stk[top]))
                pf[c++]=pop();
            push(in[i]);
        }
        else if(in[i]==')'){
            while(stk[top]!='(')
                pf[c++]=pop();
            pop();//To pop the '('
        }
        else{
            printf("\nInvalid expression\n");
            return 0;
        }
    }
    while(top!=-1)
        pf[c++]=pop();
    printf("\nThe equivalent postfix expression is %s \n",pf);
}
