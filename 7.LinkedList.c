#include<stdio.h>
#include<stdlib.h>
typedef struct student* listptr;
typedef struct student{
    char nm[100],usn[100],br[100],sem[100],ph[100];
    listptr link;
}student;
listptr input(){
    listptr temp=(listptr)malloc(sizeof(*temp));
    printf("\nEnter name usn branch sem phone\n");
    scanf("%s%s%s%s%s",temp->nm,temp->usn,temp->br,temp->sem,temp->ph);
    temp->link=NULL;
    return temp;
}
listptr frontInsert(listptr head){
    listptr newNode=input();
    if(head==NULL)
        return newNode;
    newNode->link=head;
    return newNode;
}
listptr frontDelete(listptr head){
    if(head==NULL){
        printf("\nRecords empty\n");
        return head;
    }
    listptr temp=head;
    printf("\nRecords of student %s is being deleted\n",temp->nm);
    head=head->link;
    free(temp);
    return head;
}
listptr rearInsert(listptr head){
    listptr newNode=input();
    if(head==NULL)
        return newNode;
    listptr cur=head;
    while(cur->link!=NULL)
        cur=cur->link;
    cur->link=newNode;
    return head;
}
listptr rearDelete(listptr head){
    listptr cur=head,prev=NULL,temp;
    if(head==NULL){
        printf("\nRecords empty\n");
        return head;
    }
    while(cur->link!=NULL){
        prev=cur;
        cur=cur->link;
    }
    temp=cur;
    printf("\nRecords of student %s is deleted\n",temp->nm);
    if(!prev)
        return NULL;
    prev->link=NULL;
    free(temp);
    return head;
}
void display(listptr head){
    if(head==NULL){
        printf("\nRecords Empty\n");
        return;
    }
    int c=1;
    listptr cur=head;
    printf("\nThe details of the students are:\n");
    while(cur!=NULL){
        printf("\nStudent %d:\n%s %s %s %s %s\n",c++,cur->nm,cur->usn,cur->br,cur->sem,cur->ph);
        cur=cur->link;
    }
}
int main(){
    int ch,i,n;
    listptr head=NULL;
    printf("\nMENU\n1.Create\n2.Front Insert\n3.Front Delete\n4.Rear Insert\n5.Rear Delete\n6.Display\n7.Quit\n");
    while(1){
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nEnter no. of students\n");
                    scanf("%d",&n);
                    for(i=0;i<n;i++){
                        printf("\nEnter details of student %d:\n",i+1);
                        head=frontInsert(head);
                    }
                    break;
            case 2: head=frontInsert(head);
                    break;
            case 3: head=frontDelete(head);
                    break;
            case 4: head=rearInsert(head);
                    break;
            case 5: head=rearDelete(head);
                    break;
            case 6: display(head);
                    break;
            case 7: exit(0);
        }
    }
}
