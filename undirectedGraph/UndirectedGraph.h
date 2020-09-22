//
//  UndirectedGraph.h
//  undirectedGraph
//
//  Created by Maya Bishop on 2020-04-15.
//  Copyright © 2020 Maya Bishop. All rights reserved.
//

#ifndef UndirectedGraph_h
#define UndirectedGraph_h

#include <stdio.h>
#include <stdio.h>
#include "PriorityQueue.h"
#include "Vertex.h"
#include "Edge.h"
#include <math.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class UndirectedGraph;

class UndirectedGraph{
    private:
        vector<Vertex*> vertexes;
        int num_edges;
        int num_vertexes;
    public:
        //constructor/destructor
        UndirectedGraph();
        ~UndirectedGraph();
        //command functions
        string insertVertex(string name);
        string insertEdge(string name1, string name2, double weight);
        int searchVertex(string name);
        string degree(string name);
        string vertexCount();
        string edgeCount();
        string weight(string name1, string name2);
        double weight(int name1, int name2);
        string smallestWeight(string name1, string name2);
        double smallestWeight(int name1, int name2);
        string printPath(string name1, string name2);
        string clear();
        
        //helper functions
        void relax(int u, int v, double weight);
        string removeZeros(double s);
    
};
#endif /* UndirectedGraph_hpp */
