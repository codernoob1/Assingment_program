#include <stdio.h>
#include <stdlib.h>

struct KAryHeap
{
    int limit;
    int n;
    int k;
    int *collection;
};
struct KAryHeap* newHeap(int limit, int k)
{
    struct KAryHeap* heap = (struct KAryHeap*)malloc(sizeof(struct KAryHeap));
    if(heap==NULL)
    {
        printf("\n Memory Overflow, when creating new heap\n");
        return NULL;
    }
    heap->limit = limit;
    heap->n = 0;
    heap->k = k;
    heap->collection = (int *)calloc(limit,sizeof(int));

    if(heap->collection == NULL)
    {
        printf("\n Memory Overflow, when creating new heap collection\n");
    }

    return heap;
}
void preorder(struct KAryHeap*heap, int root)
{
    if ( root < heap->n)
    {
        printf("  %d", heap->collection[root]);
        for (int i = 1; i <= heap->k; ++i)
        {
            preorder(heap,heap->k *root + i);
        }
    }
}
void swap(struct KAryHeap*heap, int first, int second)
{
    int auxiliary = heap->collection[first];
    heap->collection[first] = heap->collection[second];
    heap->collection[second] = auxiliary;
}
void putElement(struct KAryHeap*heap, int location)
{
    int root = (location-1)/heap->k;

    while (root >= 0 && heap->collection[location] > heap->collection[root])
    {
        swap(heap, location, root);
        location = root;
        root = (location-1)/heap->k;
    }
}
void addElement(struct KAryHeap*heap, int data)
{
    if(heap->n+1 >= heap->limit)
    {
        printf("\n Heap limit is exceeded When add new element");
        return;
    }
    heap->collection[heap->n] = data;
    heap->n = heap->n + 1;
    putElement(heap, heap->n-1);
}
void changeElement(struct KAryHeap*heap, int location)
{
    int update = -1;
    for (int i = 1; i <= heap->k; ++i)
    {
        if((location*heap->k)+i < heap->n && heap->collection[location] <
            heap->collection[(location*heap->k)+i])
        {
            if(update == -1)
            {
                update = (location*heap->k)+i;
            }
            else if(heap->collection[update] < heap->collection[(location*heap->k)+i])
            {
                update = (location*heap->k)+i;
            }
        }
    }
    if(update >= 0)
    {
        swap(heap,location,update);
        changeElement(heap,update);
    }
}
int extractMax(struct KAryHeap*heap)
{
    if(heap->n == 0)
    {
        printf("\n Empty Heap ");
        return -1;
    }
    int element = heap->collection[0];

    heap->collection[0] = heap->collection[heap->n-1];

    heap->collection[heap->n-1] = 0;

    heap->n = heap->n - 1;

    changeElement(heap, 0);

    return element;
}
void printTree(struct KAryHeap*heap)
{
    printf("\n Level Order Heap Element  \n");

    for (int i=0; i < heap->n; i++)
    {
        printf("  %d", heap->collection[i]);
    }
    printf("\n Preorder \n");
    preorder(heap,0);
}

int main()
{
    int limit = 50;
    int k = 4;

    struct KAryHeap*heap = newHeap(limit,k);
    addElement(heap,10);
    addElement(heap,7);
    addElement(heap,40);
    addElement(heap,2);
    addElement(heap,5);
    addElement(heap,15);
    addElement(heap,21);
    addElement(heap,35);
    addElement(heap,49);
    addElement(heap,38);
    addElement(heap,63);
    addElement(heap,19);

    printTree(heap);

    printf("\n Extract Max Element : %d",extractMax(heap));
    printTree(heap);
    printf("\n");
    return 0;
}

/*
output:
 Level Order Heap Element  
  63  40  49  2  5  7  15  21  35  10  38  19
 Preorder 
  63  40  7  15  21  35  49  10  38  19  2  5
 Extract Max Element : 63
 Level Order Heap Element  
  49  40  38  2  5  7  15  21  35  10  19
 Preorder 
  49  40  7  15  21  35  38  10  19  2  5
*/