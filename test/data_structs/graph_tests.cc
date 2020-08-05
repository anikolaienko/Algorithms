#include <gtest/gtest.h>

#include "../../data_structs/graph.cc"

TEST(Graph, StringRepresentation) {
    Algorithms::Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(0, 4);
    EXPECT_EQ(graph.toString(), "0: 1, 4\n1: 0, 2\n2: 1, 3\n3: 2, 4\n4: 3, 0");
}

TEST(Graph, AreConnected) {
    Algorithms::Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    EXPECT_TRUE(graph.connected(0, 4));
}

TEST(Graph, AreNotConnected) {
    Algorithms::Graph graph(7);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);
    EXPECT_FALSE(graph.connected(0, 6));
}
