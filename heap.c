#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
   Heap *NewHeap = (Heap*) malloc(sizeof(Heap));
   if(NewHeap == NULL) exit(EXIT_FAILURE);

   NewHeap->capac = 3;
   NewHeap->size = 0;
   NewHeap->heapArray = (heapElem*) malloc(sizeof(heapElem)*NewHeap->capac);

   return NewHeap;
}
