#include "include/display.hpp"

void display() {
    bool status = true;
    char menu_opt;
    std::string e_atual;
    std::string e_destino;
    Graph graph{14, T_D_REAL, T_D_RETA, T_L};
    do {
        std::cout << "\nMETRO DE PARIS" << '\n' << "estacao atual: ";
        std::getline(std::cin, e_atual);
        std::cout << "estacao destino: ";
        std::getline(std::cin, e_destino);
        std::cout << "===============================\n"
                  << "caminho: ";
        AStar rota(graph);

        if (!e_atual.empty() &&
            !e_destino.empty()) {  // Verifica se as strings não estão vazias
            rota.run(stringToEnum(upper(e_atual)),
                     stringToEnum(upper(e_destino)));

            if (!rota.getCaminhos()
                     .empty()) {  // Verifica se o vetor não está vazio
                for (const auto& caminho : rota.getCaminhos()) {
                    std::cout << enumToString(caminho) << ' ';
                }
            } else {
                std::cout << "Não foi possível encontrar um caminho.\n";
            }
        } else {
            std::cout << "Entrada inválida.\n";
        }

        std::cout << "\ndeseja visualizar uma nova rota(y / n): ";
        std::cin >> menu_opt;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (menu_opt == 'y') {
            status = true;
            e_atual.clear();
            e_destino.clear();
        } else {
            status = false;
        }

    } while (status);

    std::cout << "===============================\n";
    std::cout << "Obrigado!";
}