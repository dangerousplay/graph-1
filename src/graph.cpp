//
// Created by davi on 22/08/2020.
//

#include "graph.h"


Graph::Graph() {
  this->nodes = nullptr;
  this->size = 0;
}


void Graph::insert(int value) {
  auto node = (Entry*)calloc(1, sizeof(Entry));

  node->value = value;

  auto next = this->nodes;

  if(next == nullptr) {
    this->nodes = node;

    goto increment;
  }

  for(; next->next != nullptr; next = next->next) {}

  next->next = node;

  increment:
  this->size++;
}


bool Graph::create_edge(int fromNode, int toNode) const {
  Entry* node = this->get(fromNode);

  if(node == nullptr) return false;

  node->add_edge(toNode);

  return true;
}


Graph::~Graph() {
  free(this->nodes);
}

Entry *Graph::get(int node) const {
  Entry* found = nullptr;

  for(auto it = this->nodes; it != nullptr; it = it->next) {
    if(it->value == node) {
      found = it;

      break;
    }
  }

  return found;
}


Entry::Entry() {
  this->edges = List();
}


void Entry::add_edge(int toNode) {
  this->edges.push_back(toNode);
}


void print_graph(const Graph& graph) {

  printf("Mostrando grafo: \n\n");

  for(auto next = graph.nodes; next != nullptr; next = next->next) {
    printf("%d = ", next->value);

    for(auto edge = next->edges.inner_nodes(); edge != nullptr; edge = edge->next) {
      printf("(%d -> %d)", next->value, edge->info);
    }

    printf("\n\n");
  }

}