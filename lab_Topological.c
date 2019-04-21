#include<stdio.h>
#include<conio.h>
#include<string.h>



void find_indegree(int a[10][10], int n, int indegree[10]){
    int i, j, sum;
    for(j=0; j<n; j++){
        sum =0;
        for(i=0; i<n; i++)
                sum += a[i][j];
        indegree[j] = sum;
    }
}

void toposort(int a[10][10], int n){
    int u, v, t[10], s[10], indegree[10], top, k, i;
    find_indegree(a, n, indegree);
    top = -1;
    k =0;
    for(i=0; i<n ;i++){
        if(indegree[i] == 0)
            s[++top] =i;
    }

    while(top != 1){
        u = s[top--];
        t[k++] = u;
        for(v=0; v<n; v++){
            if(a[u][v] == 1){
                indegree[v]--;
                if(indegree[v] = 0)
                    s[++top] = v;
            }
        }

    }
    printf("Topological Sorting is\n");
    for(i=0;i<n;i++)
        printf("%d\t", t[i]);
    return;

}

void main(){
    int n, adj[10][10], i, j, source;
    //clrscr();
    printf("Enter the no  of vertices\n");
    scanf("%d", &n);
    printf("Enter the cost adjancey matrix \n");
    for(i=0; i<n; i++){
        for (j=0;j<n;j++)
            scanf("%d", &adj[i][j]);

    }
    toposort(adj,n);
    getch();
}
