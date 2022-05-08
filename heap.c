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

void printfArray(heapElem*array,int capacity){
   int i; 
   printf("[ ");
   for(i = 0 ; i < capacity ; i++){
      printf("%i ",array[i].priority);
   } 
   printf("]\n");
}


void heap_push(Heap* pq, void* data, int priority){
   //confirmo si es necesario aumentar el tamaño;
   if(pq->size == pq->capac){
      pq->capac = (pq->capac*2) + 1;
      pq->heapArray = (heapElem*)realloc(pq->heapArray,sizeof(heapElem)*pq->capac);
      if(pq->heapArray == NULL) exit(EXIT_FAILURE);
   }
   
   //inserto la en la ultima casilla;
   pq->heapArray[pq->size].data = data;
   pq->heapArray[pq->size].priority = priority;

   //recorrido y confirmación si es necesario intercambio
   int posDown = pq->size;
   int posUp = (posDown-1)/2;
   heapElem *Aux = (heapElem*) malloc(sizeof(heapElem));
   while(posDown>0){
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
   if(pq->size == 0) return;
   printf("Imprimiendo antes de eliminar...\n");
   printfArray(pq->heapArray,pq->size);
   pq->size--;
   //intercambio primer y ultimo nodo
   heapElem *Aux = &pq->heapArray[0];
   pq->heapArray[0] = pq->heapArray[pq->size];
   pq->heapArray[pq->size] = *Aux;
   printf("Imprimiendo luego de la eliminacion...\n");
   printfArray(pq->heapArray,pq->size);

   //Elimino el ultimo
   free(pq->heapArray[pq->size].data);
   pq->heapArray[pq->size].priority = -1;

   //hago un ciclo para intercambiar las posiciones de las prioridades 
   printf("Imprimiendo en ciclo...\n");
   int posAux = 0;
   while(pq->heapArray[posAux].priority < pq->heapArray[(2*posAux)+1].priority &&
      pq->heapArray[posAux].priority < pq->heapArray[(2*posAux)+2].priority){
      
      *Aux = pq->heapArray[posAux];
      printfArray(pq->heapArray,pq->size);

      if(pq->heapArray[posAux].priority < pq->heapArray[(2*posAux)+1].priority){
         pq->heapArray[posAux] = pq->heapArray[(2*posAux)+1];
         pq->heapArray[(2*posAux)+1] = *Aux;
         posAux = (2*posAux)+1;
      }
      if(pq->heapArray[posAux].priority < pq->heapArray[(2*posAux)+2].priority){
         pq->heapArray[posAux] = pq->heapArray[(2*posAux)+2];
         pq->heapArray[(2*posAux)+2] = *Aux;
         posAux = (2*posAux)+2;
      }
   }
}

Heap* createHeap(){
   Heap *NewHeap = (Heap*) malloc(sizeof(Heap));
   if(NewHeap == NULL) exit(EXIT_FAILURE);

   NewHeap->capac = 3;
   NewHeap->size = 0;
   NewHeap->heapArray = (heapElem*) malloc(sizeof(heapElem)*NewHeap->capac);

   return NewHeap;
}
