/*e are pushing the operands or the numbers into the stack here.
In infix to postfix conversion we pushed the operators into the stack.
So here data type of stk will be int whereas in the previous case it was char
When an operator is encountered pop 2 numbers,find their result using the operator and push the
result back into the stack*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stk[MAX],top=-1;
char pf[MAX];
int pop(){
    return stk[top--];
}
void push(int x){
    stk[++top]=x;
}
int evaluate(char op){
    int a=pop(),b=pop();
    switch(op){
        case '+': return b+a;
        case '-': return b-a;
        case '*': return b*a;
        case '/': return b/a;
        case '^': return b^a;
        case '%': return b%a;
    }
}
int isoperator(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='%'||x=='^')
        return 1;
    return 0;
}
int main(){
    int i,d;
    printf("\nEnter the postfix expression to be evaluated\n");
    scanf("%s",pf);
    for(i=0;pf[i]!='\0';i++){
        if(pf[i]>='0'&&pf[i]<='9')
            push(pf[i]-48);
        else if(isoperator(pf[i]))
            push(evaluate(pf[i]));//Push the result into the stack
       else{
            printf("\nNot a valid expression\n");
            return 0;
        }
    }
    if(top==0)
        printf("\nThe result of the postfix expression is %d\n",stk[top]);
    else
        printf("\nNot a valid postfix expression\n");
}

