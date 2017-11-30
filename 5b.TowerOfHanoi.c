#include<stdio.h>
#include<stdlib.h>
void towerOfHanoi(int n,char fromTower,char toTower,char auxTower){
    if(n==1){
        printf("\nMove disc 1 from tower %c to tower %c\n",fromTower,toTower);
        return;
    }
    towerOfHanoi(n-1,fromTower,auxTower,toTower);
    printf("\nMove disc %d from tower %c to tower %c\n",n,fromTower,toTower);
    towerOfHanoi(n-1,auxTower,toTower,fromTower);
}
int main(){
    int n;
    printf("\nEnter the no. of disks\n");
    scanf("%d",&n);
    printf("\nThe steps to be performed\n");
    towerOfHanoi(n,'a','c','b');
}
