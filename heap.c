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
   if(pq->size == 0) return NULL;
   void *data = (void*) pq->heapArray[0].data;
   return data;
}



void heap_push(Heap* pq, void* data, int priority){
   if(pq->size == pq->capac){
      pq->capac = (pq->capac*2) + 1;
      pq->heapArray = (heapElem*)realloc(pq->heapArray,sizeof(heapElem)*pq->capac);
      if(pq->heapArray == NULL) exit(EXIT_FAILURE);
   }
   
   pq->heapArray[pq->size].data = data;
   pq->heapArray[pq->size].priority = priority;


   pq->size++;
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
