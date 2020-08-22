//
// Created by davi on 22/08/2020.
//

#ifndef GRAPH_1_GRAPH_H
#define GRAPH_1_GRAPH_H

#include "list.h"

typedef struct Entry {
  List edges;
  int value{};

  Entry *next{};

public:
  Entry();

  void add_edge(int toNode);
} Entry;


typedef struct Graph {
  Entry *nodes;
  int size;

public:
  Graph();

  void insert(int value);

  [[nodiscard]] bool create_edge(int fromNode, int toNode) const;

  [[nodiscard]] Entry* get(int node) const;

  ~Graph();
} Graph;

void print_graph(const Graph& graph);

#endif //GRAPH_1_GRAPH_H
