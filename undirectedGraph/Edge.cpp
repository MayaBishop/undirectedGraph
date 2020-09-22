//
//  Edge.cpp
//  undirectedGraph
//
//  Created by Maya Bishop on 2020-04-15.
//  Copyright © 2020 Maya Bishop. All rights reserved.
//

#include "Edge.h"

///Constructors and destructors
Edge::Edge(){
    distance = 0.0;
    u_vrtx = -1;
}

Edge::Edge(double d, int u){
    distance = d;
    u_vrtx = u;
}

/////Get and Set functions

double Edge::getDistance(){
    return distance;
}

void Edge::setDistance(double w){
    distance = w;
}

int Edge::getU(){
    return u_vrtx;
}

void Edge::setU(int u){
    u_vrtx = u;
}


