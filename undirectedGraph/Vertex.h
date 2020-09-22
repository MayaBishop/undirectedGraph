//
//  City.h
//  undirectedGraph
//
//  Created by Maya Bishop on 2020-04-15.
//  Copyright © 2020 Maya Bishop. All rights reserved.
//

#ifndef City_h
#define City_h

#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include "Edge.h"
using namespace std;
class Vertex;

class Vertex{
    private:
        string name;
        double key;
        int parent_i;
        int heap_i;
        vector<Edge*> adjacencies;
    
    public:
        //Constructors and destructors
        Vertex();
        Vertex(string n);
        ~Vertex();
    
        //get and set functions
        string getName();
        void setName(string new_n);
        double getKey();
        void setKey(double k);
        int getParentIndex();
        void setParentIndex (int p_i);
        int getHeapIndex();
        void setHeapIndex (int p_i);
        vector<Edge*> getAdjancencies();
        void setAdjancencies (vector<Edge*> adj);    
        //other functions
        void addEdge(Edge* e);


};


#endif /* City_hpp */
