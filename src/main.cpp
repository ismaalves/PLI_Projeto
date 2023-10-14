#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "readfile.h"
#include "construtor.h"
#include "guloso.h"
#include "showsolution.h"
#include "n1.h"
#include "n2.h"
#include "n3.h"
#include "n3_1.h"
#include "datatype.h"
using namespace std;


int main(void){

    int n;// Número de clientes
    int k; // Quantidade de veículos
    int Q; // Quantidade máxima de cada veículo
    int L; // Quantidade mínima de entrega sem terceirização
    int r; // Custo de cada veículo

    vector<int> dados;
    vector<int> d;
    vector<int> p;
    vector<vector<int>> c;
    dados = read_file("instance1.txt");
    //cout << "Size of dados = " << dados.size() << endl;

    extrai_dados(&dados[0], &n,&k,&Q,&L,&r ,d, p, c);

    //print do vetor d
    cout << "\n" << endl;
    cout << "VECTOR D FORA DA FUNCAO: ";
    print_array(&d[0], d.size());

    //print do vetor p
    //cout << "VECTOR P FORA DA FUNCAO: ";
    //print_array(&p[0], p.size());

    //print da matriz c
    /*
    cout << "MATRIZ C FORA DA FUNCAO: " << endl;
    for (int i = 0; i < c.size(); i++){
        print_array(&c[i][0], c[i].size());
    }
    cout << endl;
    */
    //print das variaveis após a função
    //cout << "n = " << n << endl;
    //cout << "k = " << k << endl;
    //cout << "Q = " << Q << endl;
    //cout << "L = " << L << endl;
    //cout << "r = " << r << endl;
    //cout << endl;
    
    Solution result = buildSolution(n, k, r, Q, L, c, d, p);
    printSolution(result);

    /*
    cout << "Rota 1: ";
    print_array(&result.routes[0][0], result.routes[0].size());

    swapInside(&result.totalCost,c,result.routes[0], 1, 2);
    cout << "Depois do swap: ";
    print_array(&result.routes[0][0], result.routes[0].size());
    cout<< "Custo atualizado = " << result.totalCost << endl;
   

    
    cout << "Rota 2: ";
    print_array(&result.routes[1][0], result.routes[1].size());

    swapInside(&result.totalCost,c,result.routes[1], 1, 3);
    cout << "Depois do swap: ";
    print_array(&result.routes[1][0], result.routes[1].size());
    cout<< "Custo atualizado = " << result.totalCost << endl;

    */

    /*
    vector<int> lst_clientes;
    lst_clientes.push_back(2);

    cout << "Rota 2: ";
    print_array(&result.routes[1][0], result.routes[1].size());

    Upgrade_Routes(&result.totalCost, 8, Q, lst_clientes, d, c, p, result.routes[1], 3);
    cout << "Depois do swap da terceirizacaoo: ";

    print_array(&result.routes[1][0], result.routes[1].size());
    cout<< "Custo atualizado = " << result.totalCost << endl;
    /*
    Precisamos alterar a struct pra incluir:
        int com numero de rotas
        vetor com o tamanho de cada rota pra não precisar calcular size toda hora
        vetor com a demanda total de cada rota pra facilitar no N3

    */
    cout<< "\n";
    
    Swap_Routes(&result.totalCost, Q, d, c, p, result.routes[0],result.routes[1], result.rota_dem);
    printSolution(result);
    
    
    melhora_rotas(Q, L, &result.total_clientes,&result.totalCost, d, p, c, result.routes[1], 3, result.terceirizados, &result.rota_dem[1]);
    printSolution(result);
    

    return 0;
}