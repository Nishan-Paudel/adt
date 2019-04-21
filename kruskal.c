#include<stdio.h>
#include<conio.h>
#include<string.h>

int find(int v, int p[100]){
    while(p[v] != v)
        v = p[v];
    return v;
}


void kruskal(int cost[20][20], int n){
    int u, min = 999, i, j, v, k=0, src=0, count = 0, sum = 0, t[100][2], path[10];

    for(i=0;i<n;i++)
        path[i] =i;
// Initialization to find minimum spanning tree


    while(count < n-1){
        min = 999;
        for(i=0; i<n; i++){
            for (j=0; j<n; j++){
                if ((cost[i][j] != 0) && (cost[i][j])<min){
                        min =cost[i][j];
                        u = i;
                        v = j;
                }
            }
        }


        if(min == 999 ) break;
        i = find(u,path);
        j = find(v,path);
        if( i != j){
            t[k][0] =u;
            t[k][1] = v;
            k++;
            count += 1;
            sum += min;
            if(i < j) path[j] = i;
            else path[i] = j;
        }
        cost[u][v] = cost[v][u] = 999;
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
    kruskal(cost, 4);
    getch();
}
