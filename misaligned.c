#include <stdio.h>
#include <assert.h>

int printColorMap();
ColorPair GetColorFromPairNumber(int pairNumber);
ColorPair  CopyColorPairs(int pairNumber, int majorColourIndex, int minorColourIndex);
int printColorMap_Stub();

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);
int numberOfMinorColors = sizeof(minorColor) / sizeof(minorColor[0]);

struct ColorPair 
{
    int pairNumber;
    char majorColour[25];
    char minorColour[25];  
};

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    colorPair.pairNumber = pairNumber;
    colorPair.majColor = majorColor[(pairNumber / numberOfMajorColors)];
    colorPair.minColor = minorColor[(pairNumber % numberOfMinorColors)];
    return colorPair;
}

ColorPair  CopyColorPairs(int pairNumber, int majorColourIndex, int minorColourIndex)
{
    ColorPair colorPair = getColorInfoFromPairNumber(pairNumber);
    assert(colorPair.pairNumber == pairNumber);
    assert(colorPair.majorColour == majorColourIndex);
    assert(colorPair.minorColour == minorColourIndex);  
}

int printColorMap_Stub() {
    ColorPair  colorPair;
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            colorPair = CopyColorPairs(i,j);
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

int main() {
    int (*Fn_Ptr)() = printColorMap;
    int result = Fn_Ptr();
    assert(result == 25);
    int (*Fn_Ptr)() = printColorMap_Stub;
    int result = Fn_Ptr();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
