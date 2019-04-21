
#include<stdio.h>

#include<conio.h>

#include<string.h>


void dijkstra(int cost[20][20],int visited[], int distance[], int path[], int n, int src, int dest){
    int i, u, min, j, v;

    for (i=0; i<n; i++){
        distance[i] = cost[src][i];
        path[i] = src;
        visited[i] = 0;
    }

    visited[src] = 1;

    for (i=0; i<n ; i++){
        u = -1;
        min = 999;

        for (j= 0; j<n; j++){
            if ((visited[j] == 0) && (distance[j] <min) ){
                min = distance[j];
                u = j;
            }
        }

        if (u==-1) return ;
        if (u==dest) return;
        visited[u] = 1;

        for (v=0; v<n; v++){
            if ((visited[v] == 0) && (distance[u]+cost[u][v])<distance[v]){
                    distance[v] = distance [u] +cost[u][v];
                    path[v] = u;
            }
        }
    }
}

void main(){
    int n, src, dest, i, j, distance[20], cost[20][20], visited[100], path[100];
  /*  int cost[20][20] = {{0,5,12,17,999 },
                    {999,0,999,8,7},
                    {999,999,0,6,999},
                    {999,999,999,0,9},
                    {999,999,999,999,0},
                   };
    */
    //clrscr();
    printf("Enter the no  of vertices\n");
    scanf("%d", &n);
    printf("Enter the cost adjancency matrix \n");
    for(i=0; i<n; i++){
        for (j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }

    }

    printf("Enter the source vertex\n");
    scanf("%d",&src);

    for(dest =0 ; dest<n; dest++){
        dijkstra(cost, visited, distance, path, n, src, dest);
        if(distance[dest] == 999)
            printf("Node %d is not reachable from %d\n", dest, src);
        else{
            printf("Path from %d to %d is ", dest, src);
            i = dest;
            while(i != src){
                printf("%d <- ", i);
                i = path[i];
            }
            printf("%d ", i);
            printf("Distance =%d\n ", distance[dest]);

        }

    }
    getch();

}

