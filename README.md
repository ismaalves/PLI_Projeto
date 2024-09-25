Projeto Final - Análise e Projetos de Algoritmos e Programação Linear Inteira

Alunos/autores: 

* Ismael Alves Lima
* Julyanna Azevedo
* Ruy de Morais e Silva

# PROBLEMA DE ROTEAMENTO DE VEÍCULOS COM TERCEIRIZAÇÃO

## DESCRIÇÃO DO PROBLEMA

Seja $G = (V, A)$ um grafo orientado onde $V = {0, 1, . . ., n}$ é o conjunto de vértices. O vértice 0 representa o depósito, $n$ é o número de clientes a serem atendidos, e $A$ é o conjunto de arcos do grafo. Um arco $(i, j) \in A$ representa o caminho que um veículo deve percorrer para ir do ponto $i$ ao $j$, e o custo associado a tal arco é dado por $c_{ij}$. Cada cliente $i$ possui uma demanda $d_i$ de pacotes a serem entregues. A empresa possui uma frota com $k$ veículos, todos do mesmo modelo e com capacidade $Q$. Todos os veículos devem iniciar e terminar suas rotas no depósito, a capacidade máxima deve ser respeitada, e cada veículo utilizado incorre em um custo $r$ para a empresa. Visto que existe a opção de terceirizar entregas, caso um cliente $i$ não seja atendido por nenhum veículo, deve ser pago um valor $p_i$ para que a entrega seja realizada por outra empresa. A fim de garantir uma utilização mínima de sua frota e de seus funcionários, a empresa estabelece que ao menos $LA) entregas devem ser realizadas sem terceirização. O objetivo do problema é encontrar o conjunto de rotas que minimize a soma do custo de roteamento (custo dos arcos), do custo associado à utilização dos veículos e do total pago com a terceirização de entregas.

## ABORDAGEM DE SOLUÇÃO

Para a resolução do problema em questão, foi adotado o seguinte procedimento (recomendado pelo professor):

* Construção de uma solução inicial (K-NN);
* Busca exaustiva na vizinhança da solução (VND);
* Combinação de perturbação da solução com busca exaustiva (ILS+VND).

### SOLUÇÃO INICIAL

Para a construção da solução inicial implementamos um algoritmo guloso, a saber, o K-Nearest Neighbors. A ideia principal do algoritmo é sempre escolher o vizinho mais próximo do vértice atual, ou seja, a aresta de menor valor, até que todos os vértices sejam visitados ou as condições preestabelecidas sejam atingidas. Com isso, é possível iniciar a resolução do problema a partir de uma solução viável.

### BUSCA EXAUSTIVA NA VIZINHANÇA

A partir da solução inicial, é realizado um processo de busca exaustiva com o VND, explorando todas as vizinhanças possíveis para melhorar a solução. A ideia é iterar através de várias vizinhanças definidas, buscando por melhorias na solução atual. Quando a solução não pode ser mais melhorada com uma vizinhança específica, o algoritmo muda para a próxima, explorando diferentes áreas do espaço de busca. A ordem de exploração das vizinhanças foi estabelecidas pela complexidade que ela implementa.

### PERTURBAÇÃO E BUSCA EXAUSTIVA

Aqui a ideia principal é se beneficiar das vantagens do Iterated Local Search (ILS) e do Variable Neighborhood Descent (VND). O loop se inicia com a perturbação da solução da busca exaustiva (passo anterior), selecionando aleatoriamente a vizinhança que fará a perturbação (respeitando as restrições de viabilidade da solução), depois essa solução perturbada é melhorada pelo VND, e o processo se repete até X execuções sem melhora.

## INSTRUÇÕES PARA A EXECUÇÃO

### PASSO 1

Faça download do repositório:

```bash
git clone https://github.com/ismaalves/PLI_Projeto.git
```

### PASSO 2

Compile todos os arquivos de código:

```bash
mingw32-make
```

### PASSO 3

Adicione o arquivo .txt com a instância do problema na pasta Inputs e execute:

```bash
mingw32-make run ARGS="sua_instancia"
```
