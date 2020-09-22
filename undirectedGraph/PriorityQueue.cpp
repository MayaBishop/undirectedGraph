//
//  PriorityQueue.cpp
//  undirectedGraph
//
//  Created by Maya Bishop on 2020-04-15.
//  Copyright © 2020 Maya Bishop. All rights reserved.
//

#include "PriorityQueue.h"

//constructors and destructors
PriorityQueue::PriorityQueue(){
    heap = {};
    heap_size = 0;
}

PriorityQueue::PriorityQueue(vector<Vertex*> cities){//O(N)
    heap = cities;
    heap_size = heap.size();
    for(int i = heap_size/2; i>=0;i--){
        heapify(i);
    }
}

PriorityQueue::~PriorityQueue(){
    for(int i = 0; i<heap.size();i++){
        heap[i] = nullptr;
    }
}


//priority queue functions
Vertex* PriorityQueue::extractMin(){//O(lg|N|)
    Vertex* min = heap[0];
    heap[0] = heap[heap_size-1];
    heap[0]->setHeapIndex(0);
    heap[heap_size-1] = nullptr;// add a popback to this part
    heap.pop_back();
    heap_size--;
    heapify(0);//O(lg|N|)
    return min;
}

void PriorityQueue::modifyKey(int index){
    int i = index;
    int prnt = parent(i);
    while(i>0 && heap[prnt]->getKey()>heap[i]->getKey()){
        Vertex* temp = heap[i];
        heap[i] = heap[prnt];
        heap[prnt] = temp;
        heap[i]->setHeapIndex(i);
        heap[prnt]->setHeapIndex(prnt);
        temp = nullptr;
        i = prnt;
        prnt = parent(i);
    }
    if(i == index){
        heapify(index);
    }
}


//heap functions
int PriorityQueue::parent(int index){
    return ((index+1)/2)-1;
}

int PriorityQueue::left(int index){
    return 2*(index+1)-1;
}

int PriorityQueue::right(int index){
    return (2*(index+1));
}

void PriorityQueue::heapify(int index){//O(lgn)(height of tree)
    int l = left(index);
    int r = right(index);
    int min;
    if((l < heap_size) && (heap[l]->getKey()<heap[index]->getKey())){
        min = l;
    }else{
        min = index;
    }
    if((r < heap_size) && (heap[r]->getKey()<heap[min]->getKey())){
        min = r;
    }
    if(min != index){
        Vertex* temp = heap[index];
        heap[index] = heap[min];
        heap[min] = temp;
        heap[index]->setHeapIndex(index);
        heap[min]->setHeapIndex(min);
        temp = nullptr;
        heapify(min);
    }
}

int PriorityQueue::getHeapSize(){
    return heap_size;
}
