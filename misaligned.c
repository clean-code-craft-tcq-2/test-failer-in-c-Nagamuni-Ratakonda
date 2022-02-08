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

ColorPair CopyColorPairs_Stub(int pairNumber, int majorColourIndex, int minorColourIndex);
ColorPair CopyColorPairs(int pairNumber, int majorColourIndex, int minorColourIndex);
int printColorMap(ColorPair (*CopyColorPairs_FunctionPtr)(int,int,int));

ColorPair CopyColorPairs_Stub(int pairNumber, int majorColourIndex, int minorColourIndex)
{
    ColorPair colorPair;
    colorPair.pairNumber = pairNumber;
    colorPair.majorColour = majorColor[majorColourIndex];
    colorPair.minorColour = minorColor[minorColourIndex];
    assert(colorPair.pairNumber == pairNumber);
    assert(colorPair.majorColour == majorColourIndex);
    assert(colorPair.minorColour == minorColourIndex);
    
    return colorPair;
}

ColorPair CopyColorPairs(int pairNumber, int majorColourIndex, int minorColourIndex)
{
    ColorPair colorPair;
    colorPair.pairNumber = pairNumber;
    colorPair.majorColour = majorColor[majorColourIndex];
    colorPair.minorColour = minorColor[minorColourIndex];
    return colorPair;
}

int printColorMap(ColorPair (*CopyColorPairs_FunctionPtr)(int,int,int)) {
    ColorPair colorPair;
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            colorPair = CopyColorPairs_FunctionPtr((i * 5 + j),i,j);
            printf("%d | %s | %s\n", colorPair.pairNumber,colorPair.majorColour,colorPair.minorColour);
        }
    }
    return i * j;
}

int main() {
    int result = 0;
    int result_stub = 0;
    ColorPair (*CopyColorPairs_FunctionPtr)(int,int,int)

    CopyColorPairs_FunctionPtr = CopyColorPairs;
    result = printColorMap(CopyColorPairs_FunctionPtr);
    assert(result == 25);
    
    CopyColorPairs_FunctionPtr = CopyColorPairs_Stub;
    result_stub = printColorMap(CopyColorPairs_FunctionPtr);
    assert(result_stub == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
