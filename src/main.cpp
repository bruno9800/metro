#include "include/a-stars.hpp"
#include "include/graph.hpp"
#include "include/header.hpp"

int main() {
    Graph metro(14, T_D_REAL, T_D_RETA, T_L);
    AStars estacoes(metro);

    std::cout << "distancia: " << estacoes.run(E4, E1) << '\n';
    for (const auto& par : estacoes.getVizinhos()) {
        std::cout << "(" << par.first << ", " << par.second << ")";
        std::cout << " = " << metro.getRealDistance(par.first, par.second)
                  << '/' << metro.getLine(par.first, par.second) << '\n';
    }

    return 0;
}

/**
 * @brief
 *
 * ORIGEM-> ATUAL -> DESTINO 36.3
                E5

                E4 	=> 13 + 24.8 = 37.8
                E6 3 	=> 3  + 38.8 = 41.8
                E7 2.4	=> 2.4 + 35.8= 38.2
                E8 30   => 30 + 25.4 = 55.4


 *
 */

/*
    FORMULA DO PESO DA VIAGEM

    distancia / 3
    if(mudança de linha ) += 4;
*/