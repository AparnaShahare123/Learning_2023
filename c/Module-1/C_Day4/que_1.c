#include <stdio.h>

struct Box {
    float length;
    float width;
    float height;
};

float calculateVolume(struct Box* boxPtr) {
    return boxPtr->length * boxPtr->width * boxPtr->height;
}

float calculateSurfaceArea(struct Box* boxPtr) {
    float lw = boxPtr->length * boxPtr->width;
    float wh = boxPtr->width * boxPtr->height;
    float hl = boxPtr->height * boxPtr->length;
    return 2 * (lw + wh + hl);
}

int main() {
    struct Box myBox = { 90.0, 4.0, 2.0 };
    struct Box* boxPtr = &myBox;

    double volume = calculateVolume(boxPtr);
    double surfaceArea = calculateSurfaceArea(boxPtr);
    printf("-------Aparna Shahare_Level_1_que_1-------\n");
    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    return 0;
}
