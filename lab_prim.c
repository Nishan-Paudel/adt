#include<stdio.h>
#include<conio.h>
#include<string.h>

void prim(int cost[20][20], int n, int distancek[], int pathk[], int visitedk[]){
    int u, min = 999, i, j, v, k=0, src=0, count = 0, sum = 0, t[100][2], visited[10], distance[10], path[10];
/*

    for(i=0; i<n ;i++){
        distance[i] = cost[src][i];
        visited[i] = 0;
    }

*/
// Find the source vertex
    min = 999;
    for (i=0; i<n ; i++){
        for (j= 0; j<n; j++){
            if ( cost[i][j] != 0 && cost[i][j] < min ){
                min = cost[i][j];
                src = i;
            }
        }
    }
  //  printf("******%d*********\n", src);

// Initialization to find minimum spanning tree


    for (i=1; i<n; i++){
            visited[i] = 0;
            path[i] = src;
            distance[i] = cost[src][i];

        }
        visited[src] = 1;

        sum = 0;
        for (i=0; i<n; i++){
            u = -1;
            min = 999;
            for(j=0; j<n; j++){
                if ((visited[j]== 0) && (distance[j] < min)){
                    min = distance[j];
                    u = j;
                }
            }
        if (u == -1) return;
        visited[u] = 1;
        t[k][0] = path[u];
        t[k][1] = u;
        count++; k++;
        //sum += cost[u][path[u]];
        sum += min;

        for (v=0; v<n; v++){
            if ((visited[v] == 0) && (cost[u][v])<distance[v]){
                    distance[v] =cost[u][v];
                    path[v] = u;
            }
        }
    }

    if (count == n-1){
        printf("Spanning tree  exists, edges is\n");
        for (i=0; i<n-1; i++)
                printf("%d ->%d\n", t[i][0], t[i][1]);
                printf("Sum = %d",sum);
    }
    else
        printf("Spanning tree doesn\'t exists\n");

    }


void main(){
    int n, src, distance[20], i, j, path[100], visited[100];
  /*  int cost[20][20] = {{0,60,10,999,999,999},
                        {60,0,999,20, 40, 70},
                        {10, 999, 0, 999, 999, 50},
                        {999, 20, 999, 0, 999, 80},
                        {999, 40, 999, 999, 0, 30},
                        {999, 70, 50, 80, 30, 0}
                       };
  */
    int cost[20][20] = {{0,10,40,999},
                        {10,0,999,20},
                        {40,999,0, 30},
                        {999, 20, 30, 0}

                    };

  /*  printf("Enter the no  of vertices\n");
    scanf("%d", &n);
    printf("Enter the cost adjancey matrix \n");
    for(i=0; i<n; i++){
        for (j=0;j<n;j++){
            scanf("%d", &cost[i][j]);
        }

    }

    printf("Enter the source vertex\n");
    scanf("%d",&src);
*/
    prim(cost, 4, visited, path, distance);
    getch();
}
