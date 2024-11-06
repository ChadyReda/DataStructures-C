#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>


typedef struct graph {
    int number_of_nodes;
    bool **edges;
} graph;


graph* create_graph(int number_of_nodes) 
{
    // allocate the graph
    graph* newgraph = (graph*) malloc(sizeof(*newgraph));
    if (newgraph == NULL) 
    {
        printf("Not enough memory");
        return NULL;
    }
    newgraph->number_of_nodes = number_of_nodes;
    
    // allocate the matrix
    newgraph->edges = (bool**) calloc(sizeof(bool*), number_of_nodes);
    if (newgraph->edges == NULL)
    {
        printf("Not enough memory");
        return NULL;
    }
    for (int i = 0; i < newgraph->number_of_nodes; i++) 
    {
        newgraph->edges[i] = (bool*) calloc(sizeof(bool), number_of_nodes);
        
        
        if (newgraph->edges[i] == NULL) 
        {
            printf("Not enough memory");
            for (int e = 0; e < i; e++) 
            {
                free(newgraph->edges[e]);
            }
            free(newgraph->edges);
            free(newgraph);
            return NULL;   
        }
    }

    return newgraph;
};

void destroy_graph(graph* g) 
{
    // graph containes no edges
    if (g->edges == NULL) 
    {
        return;
    }
    for (int i = 0; i < g->number_of_nodes; i++)
    {
        if (g->edges[i] != NULL)
        {
            free(g->edges[i]);
        }
    }
    free(g->edges);
    free(g);
}




void print_graph(graph* g) {
    if (g == NULL || g->edges == NULL) {
        return;
    }
    
    printf("digraph {\n");
    for (int from = 0; from < g->number_of_nodes; from++) {
        for (int to = 0; to < g->number_of_nodes; to++) {
            if (g->edges[from][to]) {
                printf("    %d -> %d;\n", from, to);
            }
        }
    }
    printf("}\n");
}


bool has_edge(graph* g, unsigned int nodefrom, unsigned int nodeto)
{
    assert(g != NULL);
    assert(nodefrom < g->number_of_nodes);
    assert(nodeto < g->number_of_nodes);

    return g->edges[nodefrom][nodeto];
}

bool add_edge(graph* g, unsigned int nodefrom, unsigned int nodeto)
{
    assert(g != NULL);
    assert(nodefrom < g->number_of_nodes);
    assert(nodeto < g->number_of_nodes);

    if (has_edge(g, nodefrom, nodeto))
    {
        return false;
    }

    g->edges[nodefrom][nodeto] = true;
    return true;
}



int main ()
{
    graph* g1 = create_graph(5);

    add_edge(g1, 0, 0);
    add_edge(g1, 3, 4);
    add_edge(g1, 1, 2);

    print_graph(g1);
    return 0;
}