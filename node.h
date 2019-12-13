//
// Created by Utilisateur on 13/12/2019.
//

#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H

struct node_t {
    int value;
    struct node_t * next, * last;
};

typedef struct node_t node_t;

node_t * create_node();

void init_node(node_t *, int);

void free_node(node_t *);

#endif //QUEUE_NODE_H
