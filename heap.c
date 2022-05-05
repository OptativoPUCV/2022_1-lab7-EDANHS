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

void printfArray(void *array,int capacity){

}


void heap_push(Heap* pq, void* data, int priority){
   if(pq->size == pq->capac){
      pq->capac = (pq->capac*2) + 1;
      pq->heapArray = (heapElem*)realloc(pq->heapArray,sizeof(heapElem)*pq->capac);
      if(pq->heapArray == NULL) exit(EXIT_FAILURE);
   }
   
   pq->heapArray[pq->size].data = data;
   pq->heapArray[pq->size].priority = priority;

   
   int posDown = pq->size;
   int posUp = (posDown-1)/2;
   heapElem *Aux = (heapElem*) malloc(sizeof(heapElem));
   while(posUp>0){
      printfArray(pq->heapArray,pq->size);
      if(pq->heapArray[posUp].priority < pq->heapArray[posDown].priority){
         *Aux = pq->heapArray[posDown];
         pq->heapArray[posDown] = pq->heapArray[posUp];
         pq->heapArray[posUp] = *Aux;
      }
      posDown = posUp;
      posUp = (posDown-1)/2;
   }
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
