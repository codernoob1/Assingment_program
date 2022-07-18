#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
bool vis[N];

void dfs(int vertex){
    cout << vertex << endl;
    vis[vertex] = true;
    for(int child: g[vertex]){
        cout << "Par "<< vertex << ", child "<< child<< endl;
        if(vis[child]) continue;
        dfs(child);
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i =0;i<m;++i){
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(5);
}

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node
// {
//     int key;
//     struct node *next;
// } node;

// typedef struct list
// {
//     node *head;
// } list;

// void add_edge(list **nodelist, int source, int destination);
// void input(list **arr, int n);
// int** printlist(int **arr , list **nodelist , int n);
// void dfs(int n ,int vertex , int **adjmat , int *visited);

// void main()
// {
//     int n, src, dst, ch = 1 , i , j;

//     printf("\nEnter the numbers of vertices:");
//     scanf("%d", &n);

//     int **adj_mat , *visited;
//     visited = (int*)calloc(n,sizeof(int));
//     adj_mat = (int*)calloc(n,sizeof(int));
//     for(i = 0; i < n ; i++)
//         adj_mat[i] = (int*)calloc(n,sizeof(int));

//     list *nodelist[n];

//     for (int i = 0; i < n; i++)
//     {
//         nodelist[i] = (list *)malloc(sizeof(list));
//         nodelist[i]->head = NULL;
//     }

//     input(nodelist, n);

//     while (1)
//     {
//         printf("\n1.add edge\n2.Update adjacency list\n3.Print spanning tree\n4.Exit\nEnter choice:\t");
//         scanf("%d", &ch);

//         switch (ch)
//         {
//         case 1:
//             printf("\nEnter source and destination vertices:\t");
//             scanf("%d%d", &src, &dst);
//             add_edge(nodelist, src, dst);
//             add_edge(nodelist, dst, src);
//             break;
//         case 2:
//             printlist(adj_mat , nodelist , n);
//             printf("\nAdjacency matrix:\n");
//             for(i = 0; i < n; i++)
//             {
//                 for(j = 0; j < n; j++)
//                     printf("%d\t",adj_mat[i][j]);
//                 printf("\n");
//             }
//             break;
//         case 3:
//             printf("\nEnter the starting vertex:\t");
//             scanf("%d",&i);
//             printf("\nA spanning tree of the graph is:\n");
//             dfs(n , i , adj_mat , visited);
//             for(j = 0 ; j < n; j++)
//                 visited[j] = 0;
//             break;
//         case 4:
//             exit(0);
//         default:
//             break;
//         }
//     }
// }

// void add_edge(list **nodelist, int source, int destination){

//     node *temp, *dst;

//     dst = (node *)malloc(sizeof(node));
//     dst->key = destination;
//     dst->next = NULL;
//     temp = nodelist[source]->head;

//     while (temp->next != NULL)
//         temp = temp->next;

//     temp->next = dst;
// }

// void input(list **arr, int n)
// {

//     node *temp;

//     for (int i = 0; i < n; i++)
//     {
//         temp = (node *)malloc(sizeof(node));
//         temp->key = i;
//         temp->next = NULL;
//         arr[i]->head = temp;
//     }
// }

// int** printlist(int **adj_mat , list **nodelist , int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         node *p = nodelist[i]->head;
//         printf("\nAdjacency list for vertex %d\n", i);

//         p = p->next;
//         while (p)
//         {
//             if (p->next == NULL)
//             {
//                 printf("%d", p->key);
//                 adj_mat[i][p->key] = 1;
//             }
//             else
//             {
//                 printf("%d->", p->key);
//                 adj_mat[i][p->key] = 1;
//             }

//             p = p->next;
//         }
//     }
//     return adj_mat;
// }

// void dfs(int n ,int vertex , int **adjmat , int *visited) {

//     printf("%d->\t",vertex);
//     visited[vertex] = 1 ;
//     for (int i = 0; i < n; i++)
//     {
//         if(adjmat[vertex][i] == 1 && !visited[i])
//             dfs(n , i , adjmat , visited);
//     }  
// }
/*

Enter the numbers of vertices:5

1.add edge
2.Update adjacency list
3.Print spanning tree
4.Exit
Enter choice:   1

Enter source and destination vertices:  1 2

1.add edge
2.Update adjacency list
3.Print spanning tree
4.Exit
Enter choice:   1

Enter source and destination vertices:  2 3

1.add edge
2.Update adjacency list
3.Print spanning tree
4.Exit
Enter choice:   1

Enter source and destination vertices:  3 4

1.add edge
2.Update adjacency list
3.Print spanning tree
4.Exit
Enter choice:   1 

Enter source and destination vertices:  4 1

1.add edge
2.Update adjacency list
3.Print spanning tree
4.Exit
Enter choice:   2

Adjacency list for vertex 0

Adjacency list for vertex 1
2->4
Adjacency list for vertex 2
1->3
Adjacency list for vertex 3
2->4
Adjacency list for vertex 4
3->1
Adjacency matrix:
0   0   0   0   0   
0   0   1   0   1   
0   1   0   1   0   
0   0   1   0   1   
0   1   0   1   0   

1.add edge
2.Update adjacency list
3.Print spanning tree
4.Exit
Enter choice:   3

Enter the starting vertex:  3

A spanning tree of the graph is:
3-> 2-> 1-> 4-> 
1.add edge
2.Update adjacency list
3.Print spanning tree
4.Exit
Enter choice:   4