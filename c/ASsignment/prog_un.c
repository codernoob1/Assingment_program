#include<stdio.h>
#include<stdlib.h>

struct AjlistNode{
  int vId;//Vertices id
  struct AjlistNode*next;
};

struct Graph{
  int data; //node key value
  struct AjlistNode*next;
};



int size; //number of nodes

//set node key value
void setData(struct Graph*node)
{
  if(node!=NULL && size>0)
  {
    int index=0;
    for(index;index<size;index++)
    {
      //set vertic node data
      node[index].data=index;//set node key
      //Initial no AjlistNode
      //set NULL Value
      node[index].next=NULL;
    }
  }else{
    printf("Vertic Node is Empty");
  }
}
//Add Edge from Two given Nodes
void addEdge(struct Graph*node, int V ,int E)
{
    //add edge form V to E
    //V and E is Node location
  if(V<size && E <size)
  {
      //first create Adjacency node
    struct AjlistNode *newEdge=(struct AjlistNode*)malloc(
      sizeof(struct AjlistNode)
      );
    if(newEdge!=NULL)
    {

      newEdge->next=NULL;
      newEdge->vId=E;

      struct AjlistNode *temp=node[V].next;

      if(temp==NULL)
      {
        node[V].next=newEdge;
      }else
      {
                //Add node at last
        while(temp->next!=NULL)
        {
          temp=temp->next;
        }      
        temp->next=newEdge;          
      }
    }else
    {
      printf("\n Memory overflow");
    }
  }else
  {
      //not valid Vertices
    printf("Invalid Node Vertices %d  %d", V,E);
  }
}
//Display Adjacency list of vertex
void printGraph(struct Graph*node)
{
  if(node!=NULL)
  {
    struct AjlistNode *temp=NULL;
    for(int index=0;index<size;index++)
    {
      printf("\n Adjacency list of vertex %d  :",index);
      temp=node[index].next;
      while(temp!=NULL)
      {
        //temp->vId is graph node vertices
        //in this case temp->vId is same as 
        //node[temp->vId].data

        printf("  %d",node[temp->vId].data);
        temp=temp->next;
      }
    }
  }else
  {
    printf("Empty Graph");
  }
}


//This function are capable to count all path between two nodes
void count_path(int start,
  int end,
  int *visit,
  struct Graph*node,
  int*result)
{

  if(start >size 
    || end >size 
    || start<0 
    || end<0 
    || node==NULL)
  {
    //invalid node location
    return ;
  }

  if(visit[start]==1)
  {
    //node is already visited
    return;
  }
  if(start==end)
  {
    //when source and destination are get
    *result=(*result)+1;
  }
  //active the visiting node status
  visit[start]=1;

  struct AjlistNode *temp=node[start].next;

  while(temp!=NULL)
  {
    //check node by edges
    count_path(temp->vId,end,visit,node,result); 

    temp=temp->next;
  }
  //inactive current visiting node status
  visit[start]=0;
}


int main()
{

  size=6; //set number of nodes
  struct Graph*node=NULL;
  int *vis;

   vis=(int*)calloc(size,sizeof(int));

  //Creating memory of graph nodes
  node=(struct Graph*)malloc(sizeof(struct Graph)*size);
  
  if(node==NULL)
  {
    printf("\n Memory overflow");

  }else
  {
    //First set node keys
    setData(node); 

    //Connected two node with Edges
    addEdge(node,0, 1); 
    addEdge(node,0, 3); 
    addEdge(node,1, 2); 
    addEdge(node,1, 4); 
    addEdge(node,2, 3); 
    addEdge(node,2, 4); 
    addEdge(node,2, 5); 
    addEdge(node,3, 1); 
    addEdge(node,3, 5); 
    addEdge(node,5, 4); 



    printGraph(node);

    //value 0 is source node
    int source = 0;

    //value 4 is destination node
    int destination = 4;

    //for resultant paths
    int result=0;

    count_path(source,destination,vis,node,&result);

    printf("\n Possible Path : %d\n",result );
  }  
  return 0;
}
/*
 Adjacency list of vertex 0  :  1  3
 Adjacency list of vertex 1  :  2  4
 Adjacency list of vertex 2  :  3  4  5
 Adjacency list of vertex 3  :  1  5
 Adjacency list of vertex 4  :
 Adjacency list of vertex 5  :  4
 Possible Path : 8
*/