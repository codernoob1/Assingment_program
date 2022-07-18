// /*
// Name - Saikat Mazumder
// program name - dfs of spanning tree
// */

// #include<bits/stdc++.h>
// using namespace std;


// class Graph{
//     private:
//         int V; //Number of Vertices
//         list<int> *adj;
//         void DFS_helper(int s,bool *visited);
//     public:
//         Graph(int v);

//         void addEdge(int v,int w);
//         void Dfs(int s);
// };
// //constructor with number of vertices
// Graph :: Graph(int v){
//     //set number of vertices
//     V = v;
    
//     adj = new list<int>[v];
// }
// void Graph :: addEdge(int v,int w){
//     adj[v].push_back(w);
// }
// void Graph:: DFS_helper(int s,bool *visited){
//     cout << "Visting node " << s << endl;
//     visited[s] = true;


//     for(auto i = adj[s].begin(); i != adj[s].end(); i++){
//         if(!visited[*i]){
//             cout<< "Going to vertex " << *i << "from vertex "<< s << endl;

//             DFS_helper(*i,visited);
//         }
//     }
    
// }
// void Graph :: Dfs(int s){
//     bool *visited = new bool[V];
//     for(int i = 0;i<V;i++){
//         visited[i] = false;
//     }
//     DFS_helper(s,visited);
// }

// int main(){
//     Graph g(5);

//     g.addEdge(0,1);
//     g.addEdge(1,0);
//     g.addEdge(1,3);
//     g.addEdge(3,1);
//     g.addEdge(3,4);
//     g.addEdge(4,3);
//     g.addEdge(4,2);
//     g.addEdge(2,4);

    

//     g.Dfs(0);
//     return 0;
// } 

// /*output:
//     Visting node 0
// Going to vertex 1from vertex 0
// Visting node 1
// Going to vertex 3from vertex 1
// Visting node 3
// Going to vertex 4from vertex 3
// Visting node 4
// Going to vertex 2from vertex 4
// Visting node 2
// */


#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

typedef struct node
{
    int key;
    struct node *next;
} node;

typedef struct list
{
    node *head;
} list;


void add_edge(list **nodelist, int source, int destination);
void input(list **arr, int n);
int** printlist(int **arr , list **nodelist , int n);
void dfs(int n ,int vertex , int **adjmat , int *visited);

void main()
{
    int n, src, dst, ch = 1 , i , j;

    printf("\nEnter the numbers of vertices:");
    scanf("%d", &n);

    int **adj_mat , *visited;
    visited = (int*)calloc(n,sizeof(int));
    adj_mat = (int**)calloc(n,sizeof(int));
    for(i = 0; i < n ; i++)
        adj_mat[i] = (int*)calloc(n,sizeof(int));

    list *nodelist[n];

    for (int i = 0; i < n; i++)
    {
        nodelist[i] = (list *)malloc(sizeof(list));
        nodelist[i]->head = NULL;
    }

    input(nodelist, n);

    while (1)
    {
        printf("\n1.add edge\n2.Update adjacency list\n3.Print spanning tree\n4.Exit\nEnter choice:\t");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter source and destination vertices:\t");
            scanf("%d%d", &src, &dst);
            add_edge(nodelist, src, dst);
            add_edge(nodelist, dst, src);
            break;
        case 2:
            printlist(adj_mat , nodelist , n);
            printf("\nAdjacency matrix:\n");
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < n; j++)
                    printf("%d\t",adj_mat[i][j]);
                printf("\n");
            }
            break;
        case 3:
            printf("\nEnter the starting vertex:\t");
            scanf("%d",&i);
            printf("\nA spanning tree of the graph is:\n");
            dfs(n , i , adj_mat , visited);
            for(j = 0 ; j < n; j++)
                visited[j] = 0;
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }
}

void add_edge(list **nodelist, int source, int destination){

    node *temp, *dst;

    dst = (node *)malloc(sizeof(node));
    dst->key = destination;
    dst->next = NULL;
    temp = nodelist[source]->head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = dst;
}

void input(list **arr, int n)
{

    node *temp;

    for (int i = 0; i < n; i++)
    {
        temp = (node *)malloc(sizeof(node));
        temp->key = i;
        temp->next = NULL;
        arr[i]->head = temp;
    }
}

int** printlist(int **adj_mat , list **nodelist , int n)
{
    for (int i = 0; i < n; i++)
    {
        node *p = nodelist[i]->head;
        printf("\nAdjacency list for vertex %d\n", i);

        p = p->next;
        while (p)
        {
            if (p->next == NULL)
            {
                printf("%d", p->key);
                adj_mat[i][p->key] = 1;
            }
            else
            {
                printf("%d->", p->key);
                adj_mat[i][p->key] = 1;
            }

            p = p->next;
        }
    }
    return adj_mat;
}

void dfs(int n ,int vertex , int **adjmat , int *visited) {

    printf("%d->\t",vertex);
    visited[vertex] = 1 ;
    for (int i = 0; i < n; i++)
    {
        if(adjmat[vertex][i] == 1 && !visited[i])
            dfs(n , i , adjmat , visited);
    }  
}