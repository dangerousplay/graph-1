//
// Created by davi on 22/08/2020.
//

#include <catch2/catch.hpp>
#include "../src/graph.h"


#ifndef GRAPH_1_TEST_GRAPH_H
#define GRAPH_1_TEST_GRAPH_H

TEST_CASE( "Graph", "[Graph]" ) {

  SECTION("Graph adding nodes") {

    SECTION("Pushing an element on graph") {
      Graph graph = Graph();

      int value = 10;

      graph.insert(value);

      REQUIRE(graph.nodes != NULL);
      REQUIRE(graph.nodes->value == value);
      REQUIRE(graph.nodes->next == NULL);
      REQUIRE(graph.size == 1);
    }

    SECTION("Pushing elements on graph") {
      Graph graph = Graph();

      int amount = 10;

      for(int i = 0; i < amount; i++) {
        graph.insert(i);
      }

      int count = 0;

      for(auto next = graph.nodes; next->next != nullptr; next = next->next) {
        REQUIRE(next->value == count);
        REQUIRE(next->edges.is_empty());

        count++;
      }

      REQUIRE(graph.nodes != NULL);
      REQUIRE(graph.nodes->next != NULL);
      REQUIRE(count+1 == amount);
    }
  }

  SECTION("Graph adding edges") {

    SECTION("Creatine one edge for a node") {
      Graph graph = Graph();

      int amount = 10;

      for(int i = 0; i < amount; i++) {
        graph.insert(i);
      }

      int fromNode = 0;
      int toNode = 0;

      graph.create_edge(fromNode, toNode);

      auto actual = graph.get(fromNode);

      REQUIRE(actual->edges.size == 1);
      REQUIRE(actual->edges.get(0)->info == toNode);
      REQUIRE(actual->value == fromNode);
      REQUIRE(actual->next != nullptr);
    }

    SECTION("Creatine multiple edges for a node") {
      Graph graph = Graph();

      int amount = 10;

      for(int i = 0; i < amount; i++) {
        graph.insert(i);
      }

      int fromNode = 0;

      for(int i = 0; i < amount; i++) {
        graph.create_edge(fromNode, i);
      }

      auto actual = graph.get(fromNode);
      auto edges = actual->edges;

      REQUIRE(actual->edges.size == amount);

      for(int i = 0; i < amount; i++) {
        REQUIRE(edges.get(i)->info == i);
      }

      REQUIRE(actual->value == fromNode);
      REQUIRE(actual->next != nullptr);
    }

  }


}

#endif //GRAPH_1_TEST_GRAPH_H
