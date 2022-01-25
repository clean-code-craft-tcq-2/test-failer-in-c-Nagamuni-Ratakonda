#include <stdio.h>
#include <assert.h>

int printColorMap();
ColorPair GetColorFromPairNumber(int pairNumber);
void CopyColorPairs(int pairNumber, const char* majorColourIndex, const char* minorColourIndex);
int printColorMap_Stub();

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);
int numberOfMinorColors = sizeof(minorColor) / sizeof(minorColor[0]);

typedef struct 
{
    int pairNumber;
    const char* majorColour;
    const char* minorColour;  
}ColorPair;

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    colorPair.pairNumber = pairNumber;
    colorPair.majorColour = majorColor[(pairNumber / numberOfMajorColors)];
    colorPair.minorColour = minorColor[(pairNumber % numberOfMinorColors)];
    return colorPair;
}

void CopyColorPairs(int pairNumber, const char* majorColourIndex, const char* minorColourIndex)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    assert(colorPair.pairNumber == pairNumber);
    assert(colorPair.majorColour == majorColourIndex);
    assert(colorPair.minorColour == minorColourIndex);  
}

int printColorMap_Stub() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            CopyColorPairs(i * 5 + j,majorColor[i], minorColor[i]);
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
    int (*PrintColorMapFuncPtr)();
    int result;
    PrintColorMapFuncPtr = printColorMap;
    result = PrintColorMapFuncPtr();
    assert(result == 25);
    PrintColorMapFuncPtr = printColorMap_Stub;
    result = PrintColorMapFuncPtr();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
