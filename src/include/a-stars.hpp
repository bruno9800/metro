#ifndef ASTARS_HPP
#define ASTARS_HPP

#include "graph.hpp"

class AStars {
    double distancia;
    const Graph& graph;
    std::vector<std::pair<int, int>> vizinhos;

    void setVizinhos(int origem, int destino) {
        vizinhos.clear();
        for (size_t i = 0; i < graph.getNumVertices(); i++) {
            if (graph.getRealDistance(origem, i) != 0) {
                vizinhos.push_back(std::make_pair(origem, i));
            }
            if (graph.getRealDistance(i, origem) != 0) {
                vizinhos.push_back(std::make_pair(i, origem));
            }
        }
    }

   public:
    AStars(const Graph& graph) : graph(graph){};

    double run(int origem, int destino) {
        this->distancia = graph.getDistanceStraightDistance(origem, destino);
        setVizinhos(origem, destino);
        return distancia;
    };

    std::vector<std::pair<int, int>> getVizinhos() { return vizinhos; }
};

#endif