//
// Created by Utilisateur on 13/12/2019.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include "node.h"

typedef struct {
    int size;
    node_t * head, * tail;
} queue_t;

queue_t * create_queue();

void init_queue(queue_t *);

void add_to_queue(queue_t *, int);

int get_from_queue(queue_t *);

int get_queue_size(queue_t *);

void free_queue(queue_t *);

#endif //QUEUE_QUEUE_H
