#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "header.hpp"

using TABLE = std::vector<std::vector<double>>;
using TABLE_L = std::vector<std::vector<int>>;

class Graph {
    size_t numVertices;
    TABLE mapRealDistance;      // distancia real
    TABLE mapDistanceStraight;  // distancia em linha reta
    TABLE_L mapLines;           // linha

   public:
    Graph(size_t numVertices, const TABLE mapRealDistance,
          const TABLE mapDistanceStraight, const TABLE_L mapLines)
        : mapRealDistance(mapRealDistance),
          mapDistanceStraight(mapDistanceStraight),
          mapLines(mapLines),
          numVertices(numVertices) {}

    double getDistanceStraightDistance(int origem, int destino) const {
        double distance = mapDistanceStraight[origem][destino];
        return distance != 0 ? distance : mapDistanceStraight[destino][origem];
    }

    double getRealDistance(int origem, int destino) const {
        return mapRealDistance[origem][destino];
    }

    int getLine(int x, int y) const { return this->mapLines[x][y]; }

    size_t getNumVertices() const { return this->numVertices; }
};

#endif