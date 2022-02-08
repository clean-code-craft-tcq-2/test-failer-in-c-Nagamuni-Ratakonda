#include <stdio.h>
#include <assert.h>

typedef struct 
{
    int pairNumber;
    const char* majorColour;
    const char* minorColour;  
}ColorPair;

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

ColorPair GetColorFromPairNumber_Stub(int pairNumber);
void CopyColorPairs_Stub(int pairNumber, const char* majorColourIndex, const char* minorColourIndex, ColorPair(*GetColorPairNum_FunctionPtr)(int));
int printColorMap_Stub(void (*CopyColorPairs_FunctionPtr)(int, const char*, const char*));

ColorPair GetColorFromPairNumber(int pairNumber);
void CopyColorPairs(int pairNumber, const char* majorColourIndex, const char* minorColourIndex, ColorPair(*GetColorPairNum_FunctionPtr)(int));
int printColorMap(void (*CopyColorPairs_FunctionPtr)(int, const char*, const char*));

int numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);
int numberOfMinorColors = sizeof(minorColor) / sizeof(minorColor[0]);

ColorPair GetColorFromPairNumber_Stub(int pairNumber) {
    ColorPair colorPair;
    colorPair.pairNumber = pairNumber;
    colorPair.majorColour = majorColor[(pairNumber / numberOfMajorColors)];
    colorPair.minorColour = minorColor[(pairNumber % numberOfMinorColors)];
    return colorPair;
}

void CopyColorPairs_Stub(int pairNumber, const char* majorColourIndex, const char* minorColourIndex, ColorPair(*GetColorPairNum_FunctionPtr)(int))
{
    ColorPair colorPair = GetColorPairNum_FunctionPtr(pairNumber);
    assert(colorPair.pairNumber == pairNumber);
    assert(colorPair.majorColour == majorColourIndex);
    assert(colorPair.minorColour == minorColourIndex);  
}

int printColorMap_Stub(void (*CopyColorPairs_FunctionPtr)(int, const char*, const char*)) {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            CopyColorPairs_FunctionPtr(i * 5 + j,majorColor[i], minorColor[i]);
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    colorPair.pairNumber = pairNumber;
    colorPair.majorColour = majorColor[(pairNumber / numberOfMajorColors)];
    colorPair.minorColour = minorColor[(pairNumber % numberOfMinorColors)];
    return colorPair;
}

void CopyColorPairs(int pairNumber, const char* majorColourIndex, const char* minorColourIndex, ColorPair(*GetColorPairNum_FunctionPtr)(int))
{
    ColorPair colorPair = GetColorPairNum_FunctionPtr(pairNumber);
    assert(colorPair.pairNumber == pairNumber);
    assert(colorPair.majorColour == majorColourIndex);
    assert(colorPair.minorColour == minorColourIndex);  
}

int printColorMap(void (*CopyColorPairs_FunctionPtr)(int, const char*, const char*)) {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            CopyColorPairs_FunctionPtr(i * 5 + j,majorColor[i], minorColor[i]);
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

int main() {
    int result = 0;
    int (*PrintColorMapFuncPtr)(void (*CopyColorPairs_FunctionPtr)(int, const char*, const char*));
    void (*CopyColorPairs_FunctionPtr)(int, const char*, const char*, ColorPair(*GetColorPairNum_FunctionPtr)(int));
    ColorPair(*GetColorPairNum_FunctionPtr)(int);
    
    GetColorPairNum_FunctionPtr = GetColorFromPairNumber;
    CopyColorPairs_FunctionPtr = CopyColorPairs;
    PrintColorMapFuncPtr = printColorMap;
    result = PrintColorMapFuncPtr;
    assert(result == 25);
    
    GetColorPairNum_FunctionPtr = GetColorFromPairNumber_Stub;
    CopyColorPairs_FunctionPtr = CopyColorPairs_Stub;
    PrintColorMapFuncPtr = printColorMap_Stub;
    result = PrintColorMapFuncPtr;
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
