//Self loops condition
#include<stdio.h>
#include<stdlib.h>
int vis[10];
void bfs(int src,int a[10][10],int n){
	int u,i,f=-1,r=-1,q[100];
	q[++r]=src;
	while(f<r){
		u=q[++f];//u indicates the current node.Dequeue the front of the queue and check all the nodes that can be visited from it
		for(i=0;i<n;i++){//n is the no. of nodes
			if(a[u][i]==1 && vis[i]==0){//a[u][i] indicates whether a node can be visited from the current node
                vis[i]=1;//Mark the node as visited
                q[++r]=i;//Add the visited node to the queue
			}
		}
	}
}
void dfs(int src,int a[10][10],int n){
	int i;
	vis[src]=1;
	for(i=0;i<n;i++){
		if(vis[i]==0 && a[src][i]==1)
			dfs(i,a,n);
	}
}
int main(){
	int n,i,j,a[10][10],src,flag,ch;
	printf("enter the no. of nodes\n");
	scanf("%d",&n);
	printf("enter the adjacency matrix\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	printf("\nMENU:\n1.BFS\n2.DFS\n3.Exit\n");
    while(1){
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
    	switch(ch){
    		case 1: for(i=0;i<n;i++)
                        vis[i]=0;
                    printf("\nEnter the Source:\n");
    				scanf("%d",&src);
    				if((src<0)||(src>n))
    					printf("\nBfs is not possible");
    				else{
    					bfs(src,a,n);
    					printf("\nThe nodes that can be reached from %d is\n",src);
    					for(i=0;i<n;i++)
    					   if(vis[i]==1)
    							printf("%d ",i);
    				}
    				break;
    		case 2: flag=1;
    				for(src=0;src<n;src++){
                        for(i=0;i<n;i++)
                            vis[i]=0;
    					dfs(src,a,n);
    					for(i=0;i<n;i++){
    						if(vis[i]==0){
    							printf("graph is not connected\n");//A graph is connected if there is a path between every pair of vertices
    							return 0;
    					   }
    					}
    				}
                    printf("graph is connected\n");
    				break;
    		case 3: exit(0);
        }
    }
}
