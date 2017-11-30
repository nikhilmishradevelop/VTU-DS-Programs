/*Tob replace a pattern in a strin*/
#include<stdio.h>
#include<string.h>
char str[100],pat[100],rep[100],new[100];
void findAndReplace(){
    int i,j=0,k=0,l=0,si,f=0;
    for(i=0;str[i]!='\0';i++){
        if(str[i]==pat[j]){
            if(j==0)
                si=k;//Get the starting index for backtracking
            j++;//Move to match the next character
            if(j!=strlen(pat))
                new[k++]=str[i];
            if(j==strlen(pat)){ //Now the complete pattern is matched
                k=si;//Start filling the replacement from the point where the first character was matched
                while(l!=strlen(rep))
                    new[k++]=rep[l++];
                l=0;//reset the replacement  to point to the starting index
                j=0;//reset the pattern to point to the starting index
                f=1;
            }
        }
        else{
                while(j!=0&&k!=0&&pat[j-1]==str[i-1]){
                    j--;//Begin matching from the next character.Current Value of j indicates how many characters are matched
                    i--;
                    k--;
                }

                    //j=0;
            new[k++]=str[i];//Just copy the string as it is
        }
    }
    new[k]='\0';
    if(f==0)
        printf("\nPattern not found\n");
}
int main(){
    printf("\nEnter a string\n");
    scanf("\n%[^\n]s",str);
    printf("\nEnter the pattern\n");
    scanf("\n%[^\n]s",pat);
    printf("\nEnter the replacement\n");
    scanf("\n%[^\n]s",rep);
    findAndReplace();
    printf("\nThe replaced string is\n%s",new);
}
