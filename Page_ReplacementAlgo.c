#include <stdio.h>

void printFrames(int frames[], int n,int page) {
    printf("Page %d -> [",page);
    for(int i = 0; i < n; i++) {
        if(frames[i]== -1) continue;
        printf("%d ", frames[i]);
    }
    printf("]\n");
}

void FIFO(int pages[], int n, int f) {
    int frames[f], faults = 0, next = 0;

    for(int i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nFIFO:\n");

    for(int i = 0; i < n; i++) {
        int found = 0;

        for(int j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            frames[next] = pages[i];
            next = (next + 1) % f;
            faults++;
        }

        printFrames(frames, f,pages[i]);
    }

    printf("Page Faults = %d\n", faults);
}

void Optimal(int pages[], int n, int f) {
    int frames[f], faults = 0;

    for(int i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nOptimal:\n");

    for(int i = 0; i < n; i++) {
        int found = 0;

        for(int j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            int pos = -1;

            for(int j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if(pos == -1) {
                int farthest = -1;

                for(int j = 0; j < f; j++) {
                    int k;

                    for(k = i + 1; k < n; k++) {
                        if(frames[j] == pages[k]) {
                            if(k > farthest) {
                                farthest = k;
                                pos = j;
                            }
                            break;
                        }
                    }

                    if(k == n) {
                        pos = j;
                        break;
                    }
                }
            }

            frames[pos] = pages[i];
            faults++;
        }

        printFrames(frames, f,pages[i]);
    }

    printf("Page Faults = %d\n", faults);
}

void LRU(int pages[], int n, int f) {
    int frames[f], time[f], faults = 0;

    for(int i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = -1;
    }

    printf("\nLRU:\n");

    for(int i = 0; i < n; i++) {
        int found = 0;

        for(int j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                time[j] = i;
                break;
            }
        }

        if(!found) {
            int pos = -1;

            for(int j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if(pos == -1) {
                pos = 0;

                for(int j = 1; j < f; j++) {
                    if(time[j] < time[pos])
                        pos = j;
                }
            }

            frames[pos] = pages[i];
            time[pos] = i;
            faults++;
        }

        printFrames(frames, f,pages[i]);
    }

    printf("Page Faults = %d\n", faults);
}

int main() {
    int n, f;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter reference string: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    FIFO(pages, n, f);
    Optimal(pages, n, f);
    LRU(pages, n, f);

    return 0;
}
