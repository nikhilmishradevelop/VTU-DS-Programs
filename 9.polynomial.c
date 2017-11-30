#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct poly* polyptr;
typedef struct poly{
    int cf,px,py,pz,flag;
    polyptr link;
}poly;
polyptr getNode(){
    polyptr x=(polyptr)malloc(sizeof(*x));
    return x;
}
void display(polyptr head){
    polyptr tmp=head->link;
    while(tmp!=head){
        printf("%dx^%d y^%d z^%d",tmp->cf,tmp->px,tmp->py,tmp->pz);
        if(tmp->link!=head)
            printf(" + ");
        tmp=tmp->link;
    }
    printf("\n");
}
polyptr rearInsert(int cf,int x,int y,int z,polyptr head){
    polyptr temp=getNode();
    polyptr cur=head->link;
    temp->px=x;
    temp->py=y;
    temp->pz=z;
    temp->cf=cf;
    temp->link=head;
    while(cur->link!=head)
        cur=cur->link;
    cur->link=temp;
    return head;
}
polyptr readPoly(polyptr head){
    int ch=1,cf,px,py,pz;
    while(ch!=0){
        printf("\nEnter coefficient\n");
        scanf("%d",&cf);
        printf("\nEnter the powers of x,y and z. 0 indicates no term\n");
        scanf("%d %d %d",&px,&py,&pz);
        head=rearInsert(cf,px,py,pz,head);
        printf("\nEnter 1 to continue.0 to stop\n");
        scanf("%d",&ch);
    }
    return head;
}
polyptr add(polyptr h1,polyptr h2,polyptr h3){
    polyptr p1=h1->link,p2;
    while(p1!=h1){
        p2=h2->link;
        while(p2!=h2){
            if(p1->px==p2->px&&p1->py==p2->py&&p1->pz==p2->pz){
                h3=rearInsert(p1->cf+p2->cf,p1->px,p1->py,p1->pz,h3);
                p2->flag=1;
                break;
            }
            p2=p2->link;
        }
        if(p2==h2)
            h3=rearInsert(p1->cf,p1->px,p1->py,p1->pz,h3);
        p1=p1->link;
    }
    p2=h2->link;
    while(p2!=h2){
        if(p2->flag!=1)
            h3=rearInsert(p2->cf,p2->px,p2->py,p2->pz,h3);
        p2=p2->link;
    }
    return h3;
}
void evaluate(polyptr h){
    polyptr p=h->link;
    float x,y,z,res=0;
    printf("\nEnter x,y and z terms to evaluate:\n");
    scanf("%f%f%f",&x,&y,&z);
    while(p!=h){
        res=res+(p->cf)*pow(x,p->px)*pow(y,p->py)*pow(z,p->pz);
        p=p->link;
    }
    printf("\nThe result of the polynomial is %f\n",res);
}
int main(){
    polyptr h1=getNode(),h2=getNode(),h3=getNode();
    h1->link=h1,h2->link=h2,h3->link=h3;
    int ch;
    printf("\nMENU:\n1.Evaluate\n2.Add 2 polynomials\n3.Exit\n");
    while(1){
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: h1=readPoly(h1);
                    display(h1);
                    evaluate(h1);
                    break;
            case 2: printf("\nEnter the 1st polynomial\n");
                    h1=readPoly(h1);
                    printf("\nEnter the 2nd polynomial\n");
                    h2=readPoly(h2);
                    printf("\n1st polynomial is\n");
                    display(h1);
                    printf("\n2nd polynomial is\n");
                    display(h2);
                    h3=add(h1,h2,h3);
                    printf("\nThe result is\n");
                    display(h3);
                    break;
            case 3: exit(0);
        }
    }
}
