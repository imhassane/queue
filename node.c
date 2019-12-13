//
// Created by Utilisateur on 13/12/2019.
//
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

node_t * create_node() {
    node_t * node = malloc(sizeof * node);
    return node;
}

void init_node(node_t * node, int value) {
    if(node == NULL) {
        puts("Une erreur s'est produite");
        exit(1);
    }

    node->value = value;
    node->next = NULL;
    node->last = NULL;
}

void free_node(node_t * node) {
    free(node);
}