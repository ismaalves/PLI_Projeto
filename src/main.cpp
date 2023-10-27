#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "readfile.h"
#include "datatype.h"
#include "construtor.h"
#include "guloso.h"
#include "showsolution.h"
#include "n1.h"
#include "n2.h"
#include "n3.h"
#include "n4.h"
#include "n5.h"
#include "vnd.h"
#include "ILS.h"
#include "file_exit.h"
#include "checksolution.h"


using namespace std;


int main(void){

    int n;// Número de clientes
    int k; // Quantidade de veículos
    int Q; // Quantidade máxima de cada veículo
    int L; // Quantidade mínima de entrega sem terceirização
    int r; // Custo de cada veículo

    // Vetores para armazenar os dados
    vector<int> dados;
    // Vetor de demandas dos clientes
    vector<int> d;
    // Vetor de custo de terceirização dos clientes
    vector<int> p;
    // Matriz de custo de transporte entre os clientes
    vector<vector<int>> c;

    //Nome do arquivo
    string instance = "n64k9_C.txt";
    dados = read_file(instance);

    // Extração dos dados
    extrai_dados(&dados[0], &n,&k,&Q,&L,&r ,d, p, c);
    
    // Relógio start
    auto start = chrono::steady_clock::now();
    // Heuristica construtiva
    Solution result = buildSolution(n, k, r, Q, L, c, d, p);
    // Relógio stop
    auto stop = chrono::steady_clock::now();
    // Tempo de execução
    cout << "TEMPO EXECUCAO GULOSO: " << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << " ms" << endl;
    printSolution(result);
    
    /*
    int i = 3;
    int j = 1;
    int a = costReinsertion(result.totalCost, c, result.routes[0], i, j);
    ReinsertionFunc(c, result.routes[0], i, j);
    result.totalCost = a;
    printSolution(result);
    doublecheck(result, Q, L, r, d, p, c);
    */

    /* 
    cout << "EXECUTANDO N2" << endl;
    Solution result2 = buscaExaustivaN2(result, c);
    printSolution(result2);
    doublecheck(result2, Q, L, r, d, p, c);
    */
    
    /*
    //busca exaustiva N1 para cada rota
    cout << "EXECUTANDO N1" <<endl;
    Solution result2 = buscaExaustivaN1(result, c);
    printSolution(result2);
    doublecheck(result2, Q, L, r, d, p, c);
    */
    

    /*    
    cout << "EXECUTANDO N3" << endl;
    Solution result4 = buscaExaustivaN3(result, Q, L, d, p, c);
    printSolution(result4);
    doublecheck(result4, Q, L, r, d, p, c);
    */

    /*
    cout << "EXECUTANDO N4" <<endl;
    Solution result5 = buscaExaustivaN4(result, r, L, d, p, c);
    printSolution(result5);
    doublecheck(result5, Q, L, r, d, p, c);
    */

    /*
    cout << "EXECUTANDO N5" <<endl;
    Solution result7 = buscaExaustivaN5(result, Q, d, p, c);
    printSolution(result7);
    doublecheck(result7, Q, L, r, d, p, c);
    */

    
    // Relógio start
    auto start2 = chrono::steady_clock::now();
    cout << "EXECUTANDO O VND" << endl;
    Solution result6 = vnd(result, r, Q, L, d, p, c);
    // Relógio stop
    auto stop2 = chrono::steady_clock::now();
    // Tempo de execução
    cout << "TEMPO EXECUCAO VND: " << chrono::duration_cast<chrono::milliseconds>(stop2 - start2).count() << " ms" << endl;
    //printSolution(result6);
    cout << "Custo total:" << result6.totalCost << endl;
    doublecheck(result6, Q, L, r, d, p, c);
    

    
    //relogio start
    auto start3 = chrono::steady_clock::now();
    cout << "EXECUTANDO O ILS" << endl;
    Solution ils = ILS(result, r, Q, L, d, p, c);
    //relogio stop
    auto stop3 = chrono::steady_clock::now();
    //tempo de execução
    cout << "TEMPO EXECUCAO ILS: " << chrono::duration_cast<chrono::milliseconds>(stop3 - start3).count() << " ms" << endl;
    printSolution(ils);
    doublecheck(ils, Q, L, r, d, p, c);

    
    cout << "OBRIGADO MEU DEUS !!!" << endl;
    /*
    Solution teste = pertubacao(result, Q, d, c);
    cout << "\n" << endl;
    printSolution(teste);
    doublecheck(teste, Q, L, r, d, p, c);
    */
    file_exit(instance, r, c, p, result);

    /*
    pertubacao(result, c);
    int i = 1;
    int j = 3;
    cout << "Status check: " << checkReinsertion(Q, d, result.rota_dem, result.routes[0], 0, 2, i)<< endl;
    costReinsertion(&result.totalCost, c, result.routes[0], result.routes[2], i, j); //eu posso tirar entre as posições 1 e 3
    Reinsertion(c, result.routes[0], result.routes[2], i, j); //eu posso tirar entre as posições 1 e 3
    cout << "\n" << endl;
    printSolution(result);
    */
    return 0;
}