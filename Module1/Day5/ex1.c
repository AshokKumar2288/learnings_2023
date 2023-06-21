#include <stdio.h>

struct Box {
    float length;
    float width;
    float height;
};

void calculateVolumeAndSurfaceArea(struct Box *box, float *volume, float *surfaceArea) {
    *volume = box->length * box->width * box->height;
    *surfaceArea = 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
}

int main() {
    struct Box myBox;
    struct Box *boxPtr = &myBox;
    float volume, surfaceArea;

    // Accessing members using (*)
    (*boxPtr).length = 5.0;
    (*boxPtr).width = 3.0;
    (*boxPtr).height = 2.0;

    calculateVolumeAndSurfaceArea(boxPtr, &volume, &surfaceArea);

    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    // Accessing members using (->)
    boxPtr->length = 4.0;
    boxPtr->width = 3.0;
    boxPtr->height = 2.5;

    calculateVolumeAndSurfaceArea(boxPtr, &volume, &surfaceArea);

    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    return 0;
}
