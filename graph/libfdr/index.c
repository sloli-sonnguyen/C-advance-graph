#include <stdio.h>
#include <stdlib.h>
#include "jrb.h"
// code mo phong lai thu vien graph
typedef JRB Graph;

// dinh nghia trc cac ham se trien khai
Graph createGraph();
// dinh trong truong hop nay la so nguyen
void addEdge(Graph graph, int v1, int v2);
int adjacent(Graph, int v1, int v2);
int getAdjacentsVertices(Graph graph, int vertex, int *output);
void dropGraph(Graph graph);

int main()
{
    Graph graph = createGraph();
    int n, output[10];
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 0);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);

    n = getAdjacentsVertices(graph, 2, output);

    if (n != 0)
    {
        printf("\n n = %d", n);
        for (int i = 0; i < n; i++)
        {
            printf("\nSo dinh ke cua 1 la : %d", output[i]);
        }
    }
    else
    {
        printf("Khong co n");
    }

    dropGraph(graph);
    return 0;
}

/**viet code chi tiet trong ham da dinh nghia o tren*/
// ham tao graph
Graph createGraph()
{
    Graph graph = make_jrb();
    return graph;
}
// xem 1 dinh co phai dinh ke hay khong
int adjacent(Graph graph, int v1, int v2)
{
    Graph node, tree;
    node = jrb_find_int(graph, v1);
    if (node == NULL)
        return 0;
    tree = (JRB)jval_v(node->val);

    return jrb_find_int(tree, v2) == NULL ? 0 : 1;
}

// sau khi co ham tren , ta day ham them canh
void addEdge(Graph graph, int v1, int v2)
{
    Graph node, tree;
    if (adjacent(graph, v1, v2) == 0)
    {
        node = jrb_find_int(graph, v1);
        if (node == NULL)
        {
            tree = make_jrb();
            jrb_insert_int(graph, v1, new_jval_v(tree));
        }
        else
        {
            tree = (JRB)jval_v(node->val);
        }
        jrb_insert_int(tree, v2, new_jval_i(1));
    }
    if (adjacent(graph, v2, v1) == 0)
    {
        node = jrb_find_int(graph, v2);
        if (node == NULL)
        {
            tree = make_jrb();
            jrb_insert_int(graph, v2, new_jval_v(tree));
        }
        else
        {
            tree = (JRB)jval_v(node->val);
        }
        jrb_insert_int(tree, v1, new_jval_i(1));
    }
}

// ham lay ra nhung dinh ke
int getAdjacentsVertices(Graph graph, int vertex, int *output)
{
    Graph node, tree;
    int total;
    node = jrb_find_int(graph, vertex);
    if (node == NULL)
        return 0;

    tree = (JRB)jval_v(node->val);
    total = 0;
    jrb_traverse(node, tree)
    {
        output[total] = jval_i(node->key);
        total++;
    }
    return total;
}

// xoa graph
void dropGraph(Graph graph)
{
    Graph node, tree;
    jrb_traverse(node, graph)
    {
        tree = (JRB)jval_v(node->val);
        jrb_free_tree(tree);
    }
    jrb_free_tree(graph);
}