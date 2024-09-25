Projeto Final - Análise e Projetos de Algoritmos

Alunos/autores: 

* Ismael Alves Lima
* Julyanna Azevedo
* Ruy de Morais e Silva

# PROBLEMA DE ROTEAMENTO DE VEÍCULOS COM TERCEIRIZAÇÃO

## DESCRIÇÃO DO PROBLEMA

Seja $G = (V, A)$ um grafo orientado onde $V = {0, 1, . . ., n}$ é o conjunto de vértices. O vértice 0 representa o depósito, $n$ é o número de clientes a serem atendidos, e $A$ é o conjunto de arcos do grafo. Um arco $(i, j) \in A$ representa o caminho que um veículo deve percorrer para ir do ponto $i$ ao $j$, e o custo associado a tal arco é dado por $c_{ij}$. Cada cliente $i$ possui uma demanda $d_i$ de pacotes a serem entregues. A empresa possui uma frota com $k$ veículos, todos do mesmo modelo e com capacidade $Q$. Todos os veículos devem iniciar e terminar suas rotas no depósito, a capacidade máxima deve ser respeitada, e cada veículo utilizado incorre em um custo $r$ para a empresa. Visto que existe a opção de terceirizar entregas, caso um cliente $i$ não seja atendido por nenhum veículo, deve ser pago um valor $p_i$ para que a entrega seja realizada por outra empresa. A fim de garantir uma utilização mínima de sua frota e de seus funcionários, a empresa estabelece que ao menos $LA) entregas devem ser realizadas sem terceirização. O objetivo do problema é encontrar o conjunto de rotas que minimize a soma do custo de roteamento (custo dos arcos), do custo associado à utilização dos veículos e do total pago com a terceirização de entregas.

## ABORDAGEM DE SOLUÇÃO

Para a resolução do problema em questão, foi adotado o seguinte procedimento:

* Construção de uma solução inicial (K-NN);
* Busca exaustiva na vizinhança da solução (VND);
* Combinação de perturbação da solução com busca exaustiva (ILS+VND).

##

> ALGORITMO GULOSO

A ideia principal do algoritmo é sempre escolher o vizinho mais próximo do vértice atual, ou seja, a aresta de menor valor, até que todos os vértices sejam visitados ou as condições preestabelecidas sejam atingidas.

> CONSTRUTOR DA SOLUÇÃO

Após identificar o vizinho mais próximo, o próximo passo é construir a solução, determinando as rotas que os carros irão seguir.
O algoritmo é baseado em uma abordagem gulosa, que pode não garantir a solução ótima em todos os casos. No entanto, é uma estratégia eficaz para obter soluções aproximadas rapidamente.

> ESTRUTURAS DE VIZINHANÇA

 - N1: SwapIntra 

A ideia é fazer troca entre clientes numa mesma rota, evitando problemas de limite de capacidade, além de propor ligações entre clientes que possa diminuir o custo final da solução

 - N2: Reinsertion

Consiste em realizar a remoção de um cliente em uma rota, e reinserí-lo na mesma rota em uma posição melhor, buscando minimizar o custo da solução

 - N3: SwapTerc

A ideia é fazer a troca de um cliente em uma rota com um cliente que está na terceirização, respeitando a capacidade do veículo.

 - N4: Remove

A ideia é remover um cliente que está sendo terceirizado e realocá-lo em uma das rotas de entrega

 - N5: SwapInter
 
A ideia é trocar clientes entre duas rotas, de maneira a não ultrapassar a capacidade do carro disponível em cada rota. É a tentativa de que na redestribuição dos custos de ligação possa encontrar um menor valor, impactando no custo final da solução.

> BUSCA EXAUSTIVA

Consiste em avaliar todas as possíveis soluções para cada estrututura de vizinhança, de forma a mudar a solução final quando o valor, em comparação com o obtido incialmente, é o menor encontrado.

> VND

Explora todas as diferentes vizinhanças em torno de uma solução recorrente. Para o nosso problema, optamos pela seguinte ordem de estruturas de vizinhança: N1, N2, N5, N3 E N4.

> ILS (Metaheurística)

A ideia é pegar o valor da solução inicial, passar pelo vnd, depois causar uma pertubação de forma aleatória na rota e tentar encontrar uma solução melhor com o auxílio do VND. Essas iterações acontecem até 10 vezes sem a solução tenha melhorado.
Optamos pela pertubação de troca de cliente entre rotas, por isso escolhe de forma aleatória dois clientes entre rotas diferentes e efetua a troca.  
