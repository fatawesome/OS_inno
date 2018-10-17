#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    unsigned char timeline;
    int reference;
    int free;
} PageFrame;

int findFreeSpace(PageFrame *array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i].free == 1) {
            return i;
        }
    }
    return -1;
}

int findSameReference(int reference, PageFrame *array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i].reference == reference) {
            return i;
        }
    }
    return -1;
}

int findSmallestTimeline(PageFrame *array, int size) {
    int idx = -1;
    int min = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (array[i].timeline < min) {
            idx = i;
            min = array[i].timeline;
        }
    }
    return idx;
}

int setPage(int idx, int reference, PageFrame *array, int size) {
    array[idx].timeline = array[idx].timeline >> 1 | 128;
    array[idx].reference = reference;

    for (int i = 0; i < size; i++) {
        if (i != idx) {
            array[i].timeline = array[i].timeline >> 1;
        }
    }
    return 0;
}

int handleReference(int reference, PageFrame *array, int size) {
    int res = 1;
    int idx;

    int same = findSameReference(reference, array, size);
    if (same != -1) {
        idx = same;
        res = 0;
    } else {
        int free = findFreeSpace(array, size);
        if (free != -1) {
            idx = free;
            array[free].free = 0;
        } else {
            idx = findSmallestTimeline(array, size);
        }
    }

    setPage(idx, reference, array, size);
    return res;
}

int printPages(PageFrame *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("Page %d. timeline: %d, reference: %d\n", i, array[i].timeline, array[i].reference);
    }
    return 0;
}

int main(int argc, char **argv) {
    int pageFrameCount = atoi(argv[1]);
    PageFrame *pageArray = malloc(sizeof(PageFrame) * pageFrameCount);
    int missCount;

    FILE *file;
    file = fopen("input.txt", "r");

    for (int i = 0; i < pageFrameCount; i++) {
        pageArray[i].timeline = (unsigned char)0;
        pageArray[i].reference = -1;
        pageArray[i].free = 1;
    }

    // printPages(pageArray, pageFrameCount);

    int buffer;
    while (fscanf(file, "%d", &buffer) == 1) {
        missCount = missCount + handleReference(buffer, pageArray, pageFrameCount);
        printPages(pageArray, pageFrameCount);
        printf("\n");
    }

    printf("%d\n", missCount);
    return 0;
}
