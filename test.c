/* =========================================
   PIPELINE HANDOFF TEST
   ========================================= */

#include <stdio.h> // Stage 2 should verify and eat this

#define MAX_BUFFER 1024 /* Stage 2 eats this too */

int main() {
    // Stage 1 removes this comment
    int x = MAX_BUFFER;
    
    if (x > 0) {
        printf("Pipeline is active!\n");
    
    }
    return 0;}
