#include <stdio.h>
#include <time.h>

#include "queue.h"

int main() {
    clock_t start, end;

    start = clock();
    queue_t * queue = create_queue();

    init_queue(queue);

    int i = 0;
    for(; i < 1000000; add_to_queue(queue, i), i++);
    printf("TAILLE: %d elements\n", get_queue_size(queue));
    free_queue(queue);
    end = clock();

    printf(" Temps execution: %.3f secondes", (double)(end - start) / (double)(CLOCKS_PER_SEC));
    return 0;
}