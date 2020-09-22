//
//  City.cpp
//  undirectedGraph
//
//  Created by Maya Bishop on 2020-04-15.
//  Copyright © 2020 Maya Bishop. All rights reserved.
//

#include "Vertex.h"
Vertex::Vertex(){
    name = "";
    key = INFINITY;
    parent_i = -1;
    heap_i = -1;
    adjacencies = {};
}

Vertex::Vertex(string n){
    name = n;
    key = INFINITY;
    parent_i = -1;
    heap_i = -1;
    adjacencies = {};
}

Vertex::~Vertex(){
    for(int i = 0; i<adjacencies.size(); i++){
        delete adjacencies[i];
        adjacencies[i] = nullptr;
    }
}


//get and set functions
string Vertex::getName(){
    return name;
}

void Vertex::setName(string new_n){
    name = new_n;
}

double Vertex::getKey(){
    return key;
}

void Vertex::setKey(double k){
    key = k;
}

int Vertex::getParentIndex(){
    return parent_i;
}

void Vertex::setParentIndex (int p_i){
    parent_i = p_i;
}

int Vertex::getHeapIndex(){
    return heap_i;
}

void Vertex::setHeapIndex (int p_i){
    heap_i = p_i;
}

vector<Edge*> Vertex::getAdjancencies(){
    return adjacencies;
}

void Vertex::setAdjancencies (vector<Edge*> adj){
    adjacencies = adj;
}

void Vertex::addEdge(Edge* e){
    adjacencies.push_back(e);
}
