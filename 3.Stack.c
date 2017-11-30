#include <stdio.h>
#include<stdlib.h>
#define MAX 5
int top=-1,stk[MAX];
void push(){
    if(top==MAX-1){
        printf("\nStack Overflow\n");
        return;
    }
    int n;
    printf("\nEnter no. to be pushed\n");
    scanf("%d",&n);
    stk[++top]=n;
}
void pop(){
    if(top==-1)
        printf("\nStack underflow\n");
    else
        printf("\nThe element being popped% d\n",stk[top--]);
}
void palindromeNo(){
    int n,b,s=0,d;
    printf("\nEnter the element to be checked for palindrome\n");
    scanf("%d",&n);
    b=n;
    while(b!=0){
        d=b%10;
        s=s*10+d;
        b=b/10;
    }
    if(s==n)
        printf("\nPalindrome no\n");
    else
        printf("\nNot palindrome no\n");
}
void palindrome(){
    int i;
    for(i=0;i<=top/2;i++){
        if(stk[i]!=stk[top-i]){
            printf("\nNot a palindrom stack\n");
            return;
        }
    }
    printf("\nPalindrome Stack\n");
}
void display(){
    int i=top;
    printf("\nThe elements of the stack are\n");
    for(i=top;i>=0;i--)
        printf("%d ",stk[i]);
}
int main() {
    int ch;
    printf("\nMENU\n1.Push\n2.Pop\n3.Display\n4.Palindrome Stack\n5.Palindrome No\n6.Exit\n");
    while(1){
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: palindrome();
                    break;
            case 5: palindromeNo();
                    break;
            case 6: exit(0);        
        }
    }
}