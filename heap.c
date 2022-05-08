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

void change_pos(heapElem *Array,int pos){
   heapElem *aux = (heapElem*)malloc(sizeof(heapElem)*3);
   int i,k;
   //guardo en un arreglo
   for(i = 0;i < 3;i++){
      aux[i] = Array[(2*pos)+i];
   }
   heapElem max;
   //ordeno mayor a menor
   for(i = 1;i < 4;i++){
      printf("Impresion en ordenamiento...\n");
      printfArray(aux,3);
      for(k = 0;k < 3-i;k++){
         if(aux[k].priority < aux[k+1].priority){
            max = aux[k];
            aux[k] = aux[k+1];
            aux[k+1] = max;
         }
      }
   }
   //micro intercambio
   if(aux[1].priority > aux[2].priority){
      max = aux[1];
      aux[1] = aux[2];
      aux[2] = aux[1];
   }

   //asignaicon
   for(i = 0 ; i < 3 ; i++){
      Array[(2*pos)+i] = aux[i];
   }




}

void heap_pop(Heap* pq){

   //printf("impimiendo arreglo completo...\n");
   //printfArray(pq->heapArray,pq->capac);

   if(pq->size == 0) return;
   printf("Imprimiendo antes de eliminar...\n");
   printfArray(pq->heapArray,pq->capac);
   pq->size--;
   //intercambio primer y ultimo nodo
   heapElem *Aux = &pq->heapArray[0];
   pq->heapArray[0] = pq->heapArray[pq->size];
   pq->heapArray[pq->size] = *Aux;
   printf("Imprimiendo luego de la eliminacion...\n");
   printfArray(pq->heapArray,pq->size);

   //Elimino el ultimo
   free(pq->heapArray[pq->size].data);
   pq->heapArray[pq->size].data = NULL;
   pq->heapArray[pq->size].priority = 0;

   //hago un ciclo para intercambiar las posiciones de las prioridades 
   printf("Imprimiendo en ciclo...\n");
   int i;
   for(i = 0 ; i < pq->size ; i++){
      if(pq->heapArray[(2*i)+1].priority == 0 || pq->heapArray[(2*i)+2].priority == 0) break;
      change_pos(pq->heapArray,i);
   }
   printf("final...\n");
   printfArray(pq->heapArray,pq->capac);
}

Heap* createHeap(){
   Heap *NewHeap = (Heap*) malloc(sizeof(Heap));
   if(NewHeap == NULL) exit(EXIT_FAILURE);

   NewHeap->capac = 3;
   NewHeap->size = 0;
   NewHeap->heapArray = (heapElem*) malloc(sizeof(heapElem)*NewHeap->capac);

   return NewHeap;
}
