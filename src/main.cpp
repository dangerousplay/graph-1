#include <iostream>
#include "graph.h"


int main() {
  Graph graph = Graph();

  while (true) {

    printf("Menu: \n");
    printf("1 - Adicionar node \n");
    printf("2 - Criar aresta \n");
    printf("3 - Mostrar grafo \n");
    printf("4 - Sair \n");

    int operation = 0;

    scanf("%d", &operation);

    switch (operation) {
      case 1:{
        printf("Digite o valor do node: ");

        int value = 0;

        scanf("%d", &value);

        graph.insert(value);
        break;
      }
      case 2: {
        printf("Digite o valor do From: ");

        int fromNode = 0;

        scanf("%d", &fromNode);

        printf("Digite o valor do To: ");

        int toNode = 0;

        scanf("%d", &toNode);

        auto created = graph.create_edge(fromNode, toNode);

        if(!created) {
          printf("Não encontrado node com valor %d", fromNode);
        }

        break;
      }

      case 3: {
        print_graph(graph);
        break;
      }
      case 4:
        exit(0);

      default:
        continue;
    }

  }

  print_graph(graph);

  return 0;
}
