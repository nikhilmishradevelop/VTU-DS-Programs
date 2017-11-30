/*To create ,display,insert and delete*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int a[MAX],f=0,n,i,p;
void create(){
    printf("\nEnter no. of elements\n");
    scanf("%d",&n);
    if(n>MAX){
        printf("The no. of elements inserted cannot be greater than max'm size %d",MAX);
        return;
    }
    printf("\nEnter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        f=1;
}
void display(){
    if(f==0){
        printf("Array not created");
        return;
    }
    if(n==0){
        printf("\nArray Empty\n");
        return;
    }
    printf("\nThe elements are\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
void delete(){
    if(f==0){
        printf("Array not created");
        return;
    }
    if(n==0){
        printf("\nArray Empty\n");
        return;
    }
    printf("\nEnter position to delete\n");
    scanf("%d",&p);
    p=p-1;//To get the index corresponding to the position
    for(i=p;i<n-1;i++)
        a[i]=a[i+1];
    n=n-1;//Update the size of the array
}
void insert(){
    if(f==0){
        printf("Array not created");
        return;
    }
    int e;
    if(n==MAX){
        printf("\nArray FULL\n");
        return;
    }
    printf("\nEnter element and position to insert\n");
    scanf("%d%d",&e,&p);
    p=p-1;//To get the index corresponding to the position
    for(i=n;i>p;i--)
        a[i]=a[i-1];
    a[p]=e;
    n=n+1;//Update array's size
}
int main(){
    int ch;
    printf("\nMENU:\n1.Create\n2.Display\n3.Delete\n4.Insert\n5.Exit\n");
    while(1){
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: delete();
                    break;
            case 4: insert();
                    break;
            case 5: exit(0);
                    break;
        }
    }
}
