//
//  PriorityQueue.h
//  undirectedGraph
//
//  Created by Maya Bishop on 2020-04-15.
//  Copyright © 2020 Maya Bishop. All rights reserved.
//

#ifndef PriorityQueue_h
#define PriorityQueue_h

#include <stdio.h>
#include "Vertex.h"
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

class PriorityQueue;

class PriorityQueue{
    private:
        vector<Vertex*> heap;
        int heap_size;
    public:
        //constructors and destructors
        PriorityQueue();
        PriorityQueue(vector<Vertex*> cities);
        ~PriorityQueue();
    
        //priority queue functions
        Vertex* extractMin();
        void modifyKey(int index);
    
        //heap functions
        int parent(int index);
        int left(int index);
        int right(int index);
        void heapify(int index);

        int getHeapSize();

};
#endif /* PriorityQueue_hpp */
