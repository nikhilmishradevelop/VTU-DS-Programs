#include<stdio.h>
#include<stdlib.h>
typedef struct emp* listptr;
typedef struct emp{
    char ssn[20],nm[20],dept[20],desg[20],sal[20],ph[20];
    listptr llink;
    listptr rlink;
}emp;
listptr input(){
    listptr temp=(listptr)malloc(sizeof(*temp));
    printf("\nEnter name ssn dept desg sal ph\n");
    scanf("%s%s%s%s%s%s",temp->nm,temp->ssn,temp->dept,temp->desg,temp->sal,temp->ph);
    temp->llink=temp->rlink=NULL;
    return temp;
}
listptr frontInsert(listptr end){
    listptr newNode=input();
    if(end==NULL)
        return newNode;
    listptr cur=end;
    while(cur->llink!=NULL)
        cur=cur->llink;
    cur->llink=newNode;
    newNode->rlink=cur;
    return end;
}
listptr frontDelete(listptr end){
    if(end==NULL){
        printf("\nRecords Empty\n");
        return end;
    }
    listptr cur=end,prev=NULL;
    while(cur->llink!=NULL){
        prev=cur;
        cur=cur->llink;
    }
    printf("\nDetails of employee %s is deleted\n",cur->nm);
    free(cur);
    if(!prev)
        return NULL;
    prev->llink=NULL;
    return end;
}
listptr rearInsert(listptr end){
    listptr newNode=input();
    if(end==NULL)
        return newNode;
    newNode->llink=end;
    end->rlink=newNode;
    return newNode;
}
listptr rearDelete(listptr end){
    if(end==NULL){
        printf("\nRecords Empty\n");
        return NULL;
    }
    listptr temp=end;
    end=end->llink;
    if(end!=NULL)
        end->rlink=NULL;
    printf("\nDetails of employee %s is deleted\n",temp->nm);
    free(temp);
    return end;
}
void display(listptr end){
    if(end!=NULL){
        display(end->llink);
        printf("\n%s %s %s %s %s %s\n",end->nm,end->ssn,end->dept,end->desg,end->sal,end->ph);
    }
}
int main(){
    int ch,i,n;
    listptr end=NULL;
    printf("\nMENU:\n1.Create\n2.Front Insert\n3.Front Delete\n4.Rear Insert\n5.Rear Delete\n6.Display\n7.Exit\n");
    while(1){
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nEnter the no. of employees\n");
                    scanf("%d",&n);
                    for(i=0;i<n;i++){
                        printf("\nEnter details of employee %d\n",i+1);
                        end=rearInsert(end);
                    }
                    break;
            case 2: end=frontInsert(end);
                    break;
            case 3: end=frontDelete(end);
                    break;
            case 4: end=rearInsert(end);
                    break;
            case 5: end=rearDelete(end);
                    break;
            case 6: if(!end)
                        printf("\nRecord Empty\n");
                    else{
                        printf("\nRecords of employees are:\n");
                        display(end);
                    }
                    break;
            case 7: exit(0);
        }
    }
}
