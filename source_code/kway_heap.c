#include <stdio.h>
#define K 3
#define SIZE 4

struct Node { int value, list, index; };
struct Node heap[K];
int heapSize = 0;

void swap(struct Node *a, struct Node *b) {
    struct Node temp = *a; *a = *b; *b = temp;
}
void heapifyDown() {
    int i = 0;
    while (1) {
        int left = 2*i+1, right = 2*i+2, smallest = i;
        if (left < heapSize && heap[left].value < heap[smallest].value) smallest = left;
        if (right < heapSize && heap[right].value < heap[smallest].value) smallest = right;
        if (smallest == i) break;
        swap(&heap[i], &heap[smallest]); i = smallest;
    }
}
void insert(struct Node node) {
    int i = heapSize;
    heap[heapSize++] = node;
    while (i > 0) {
        int parent = (i-1)/2;
        if (heap[parent].value <= heap[i].value) break;
        swap(&heap[parent], &heap[i]); i = parent;
    }
}
struct Node deleteMin() {
    struct Node min = heap[0];
    heap[0] = heap[heapSize-1];
    heapSize--;
    if (heapSize > 0) heapifyDown();
    return min;
}
int main() {
    int lists[K][SIZE] = {
        {10,30,50,70},
        {20,40,60,80},
        {15,35,55,75}
    };
    for (int i=0; i<K; i++) {
        struct Node node = {lists[i][0], i, 0};
        insert(node);
    }
    printf("K-Way Merge using Min Heap:\n");
    while (heapSize > 0) {
        struct Node min = deleteMin();
        printf("%d ", min.value);
        if (min.index + 1 < SIZE) {
            struct Node next = {lists[min.list][min.index+1], min.list, min.index+1};
            insert(next);
        }
    }
    printf("\n");
    return 0;
}
