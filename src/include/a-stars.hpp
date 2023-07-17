#ifndef ASTARS_HPP
#define ASTARS_HPP
#include <iostream>

#include "graph.hpp"

class AStars
{
    double distancia;
    const Graph &graph;
    std::vector<std::pair<int, int>> vizinhos;
    std::vector<int> caminho;

    int origem;
    int destino;

    void setVizinhos(int origem, int destino)
    {
        vizinhos.clear();
        for (size_t i = 0; i < graph.getNumVertices(); i++)
        {
            if (graph.getRealDistance(origem, i) != 0)
            {
                vizinhos.push_back(std::make_pair(origem, i));
            }
            if (graph.getRealDistance(i, origem) != 0)
            {
                vizinhos.push_back(std::make_pair(i, origem));
            }
        }
    }

    bool foiPercorrido(std::pair<int, int> vizinho, int atual)
    {
        int estacao = vizinho.first != atual ? vizinho.first : vizinho.second;
        for (const auto &prev : this->caminho)
        {
            if (prev == estacao)
            {
                return true;
            }
        }

        return false;
    }

    std::pair<int, int> melhorVizinho(int atual)
    {
        std::vector<double> distances;
        for (const auto &par : vizinhos)
        {
            const int vizinho = par.first != atual ? par.first : par.second;
            const auto &caminho = graph.getRealDistance(par.first, par.second);
            const double straighDistBtwVizinhoDestino = graph.getDistanceStraightDistance(vizinho, this->destino);
            std::cout << '(' << par.first << ' ' << par.second << ')';
            std::cout << straighDistBtwVizinhoDestino << " + " << caminho << '\n';
            const double distanciaTotal = caminho + straighDistBtwVizinhoDestino;
            if (graph.getLine(par.first, par.second) != graph.getLine(atual, this->destino))
            {
                distances.push_back(distanciaTotal + 2);
            }
            else
            {
                distances.push_back(distanciaTotal);
            }
        }

        int pos_menor = 0;

        for (int i = 0; i < distances.size(); ++i)
        {
            bool exists = false;
            std::cout << distances[i] << ' ';
            if (distances[i] < distances[pos_menor])
            {
                if (!foiPercorrido(vizinhos[i], atual))
                {
                    pos_menor = i;
                }
            }
        }

        return vizinhos[pos_menor];
    }

public:
    AStars(const Graph &graph) : graph(graph){};

    double run(int origem, int destino)
    {
        this->origem = origem;
        this->destino = destino;
        int atual = origem;
        this->distancia = graph.getDistanceStraightDistance(origem, destino);
        // definir vizinhos/
        //  descobrir o tempo gasto de cada vizinho;
        //  modificar a posição atual para a melhor estação entre os vizinhos;
        //  refazer tudo;
        while (atual != destino)
        {
            setVizinhos(atual, destino);
            std::pair<int, int> par = melhorVizinho(atual);
            std::cout << "melhor vizinho: " << par.first << ' ' << par.second << '|' << atual << '\n';
            this->caminho.push_back(par.first != atual ? par.first : par.second);
            atual = par.first != atual ? par.first : par.second;
            std::cout << atual << par.first << '\n';
        }

        return distancia;
    };

    std::vector<std::pair<int, int>> getVizinhos() { return vizinhos; }

    std::vector<int> getCaminhos() { return this->caminho; }
};

#endif