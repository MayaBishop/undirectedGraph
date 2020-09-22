//
//  Edge.h
//  undirectedGraph
//
//  Created by Maya Bishop on 2020-04-15.
//  Copyright © 2020 Maya Bishop. All rights reserved.
//

#ifndef Edge_h
#define Edge_h

#include <stdio.h>
#include <vector>
using namespace std;
class Edge;

class Edge{
    private:
        double distance;
        int u_vrtx;
    public:
        //Constructors and destructors
        Edge();
        Edge(double d, int u);
        
        //Get and Set functions
        double getDistance();
        void setDistance(double d);
        int getU();
        void setU(int u);

};

#endif /* Edge_hpp */
