//
// Created by Utilisateur on 13/12/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

queue_t * create_queue() {
    queue_t * queue = malloc(sizeof * queue);
    return queue;
}

void init_queue(queue_t * queue) {
    if(queue == NULL) {
        puts("Initialisation de la queue impossible");
        exit(1);
    }

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

void add_to_queue(queue_t * queue, int value) {
    if(queue == NULL) {
        puts("Ajout d'une valeur impossible sur la queue");
        exit(1);
    }

    node_t * node = create_node();
    init_node(node, value);

    node_t * tail = queue->tail;
    if(tail != NULL) {
        node->next = tail;
        tail->last = node;

        queue->tail = node;
    } else {
        queue->head = node;
        queue->tail = node;
    }

    queue->size++;
}

int get_from_queue(queue_t * queue) {
    int value;
    if(queue == NULL || queue->head == NULL) {
        puts("Erreur: La liste est nulle ou vide");
        exit(1);
    }
    value = queue->head->value;

    node_t * head = queue->head->last;
    free_node(queue->head);
    queue->head = head;

    queue->size--;
    return value;
}

int get_queue_size(queue_t * queue) {
    return queue->size;
}
void free_queue(queue_t * queue) {
    node_t * current_node = queue->head;
    node_t * next_node;

    if(current_node != NULL)
        next_node = current_node->last;

    while(next_node != NULL) {
        next_node = current_node->last;
        free_node(current_node);
        current_node = next_node;
    }
}