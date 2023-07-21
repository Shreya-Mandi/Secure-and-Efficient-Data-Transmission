#include <stdio.h>
#include <stdlib.h>

// structure for nodes of tree
struct Node(int data){
    int data=data;
};

// structure defining min heap
struct MinHeap(int size){
    int size=size;
    int rear=-1;
    Node* arr=(Node*)malloc(size*sizeof(Node));
};

// function to create a heap node
Node* createNode(int data){
    newNode=(Node*)malloc(sizeof(Node));

    return newNode;
}

// function to swap 2 nodes of the heap at ith and jth index
MinHeap* swap(MinHeap* heap,i,j){
    Node* temp=heap->arr[i];
    heap->arr[i]=heap->arr[j];
    heap->arr[j]=temp;

    return heap;
}

// function to ensure the minimum node is the root node
// recurrsively check if child nodes satisfy constraint- top to bottom
MinHeap* heapify(MinHeap* heap, int i){
    Node* smallest=heap->arr[i];
    Node* left=heap->arr[(i*2)+1];
    Node* right=heap->arr[(i*2)+2];

    if left->data<smallest->data{
        swap(heap,(i*2)+1,i);
        heapify(heap,(i*2)+1);
    }
    else if right->data<smallest->data{
        swap(heap,(i*2)+2,i);
        heapify(heap,(i*2)+2);
    }

    return heap;
}

// function to insert element to heap
// add to end of the array and heapify the parent
MinHeap* insertHeap(MinHeap* heap, int data){
    Node* newNode=createNode(data);

    heap->arr[(heap->rear)+1]=newNode;
    heap->rear=+1;
    heapify(heap,((heap->rear)-1)/2);

    return heap;
}

// function to delete the root or minimum node
// swapping the root node witht he last node of the tree and removing the last node
// heapify the root
MinHeap* deleteHeap(MinHeap* heap){
    swap(heap,0,(heap->rear));
    heap->rear-=1;

    heapify(heap,0);
    
    return heap;
}