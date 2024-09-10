#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "datatype.h"
#include "data_loader.h"
#include "build_solution.h"
#include "check_solution.h"
#include "vnd.h"
#include "ils.h"
#include "n1.h"
#include "n2.h"
#include "n3.h"
#include "n4.h"
#include "n5.h"
#include "save_solution.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Verifica se o nome do arquivo foi passado como argumento
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <nome_do_arquivo>" << endl;
        return 1;
    }

    // Nome da instancia a partir do argumento da linha de comando
    string nome_arquivo = argv[1];

    // Carrega os dados da instancia
    InstanceData* dados_instancia = readAndExtractData(nome_arquivo);

    // Constrói a solução inicial
    Solution* solucao_inicial = buildSolution(dados_instancia);

    // VND
    Solution* afterVND = vnd(solucao_inicial, dados_instancia);
    cout << "Custo da solucao depois do VND: " << afterVND->totalCost << "\n";

    // ILS
    Solution* afterILS = ils(afterVND, dados_instancia);
    cout << "Solucao depois do ILS: \n";
    doubleCheck(dados_instancia, afterILS);
    cout << "Custo da solucao depois do ILS: " << afterILS->totalCost << "\n";

    // Escreve no arquivo de saída
    saveSolutionToFile(nome_arquivo, afterILS, dados_instancia);

    // Libera a memória alocada
    delete dados_instancia;
    delete afterILS;

    cout << "Tudo certo!\n";

    return 0;
}
