
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

#include <math.h>

void AmazonGlassProblem(int maxlitres, int numberofLevel, int capacity)
{

float glasses[1000] = {0};
int glassInALevel = 1;
int currentLevel = 0;
bool isNextLevelRequired = true;
glasses[0] = maxlitres;
while(currentLevel < numberofLevel)
{
for(int indexInLevel = 1; indexInLevel <= currentLevel + 1; indexInLevel++)
{
    int idx = (currentLevel*(currentLevel + 1))/2;
    if(glasses[idx - 1+indexInLevel] > capacity)
    {
        float rest = glasses[idx - 1+indexInLevel] - capacity;
        int nextIndex = ((currentLevel+1) *
                (currentLevel + 2))/2 + indexInLevel;
        glasses[nextIndex -1] += rest/2;
        glasses[nextIndex] += rest/2;
        glasses[idx - 1 + indexInLevel] = capacity;
    }
}
currentLevel++;
}

currentLevel =0;
while(currentLevel < numberofLevel)
{
for(int indexInLevel = 1; indexInLevel <= currentLevel + 1; indexInLevel++) {

int idx = (currentLevel*(currentLevel + 1))/2;

std::cout << idx<< ": "<< glasses[idx] << "L  ";
}
std::cout << "\n";
currentLevel++;
}

}


int main() {

   AmazonGlassProblem(15,7,1);
    return 1;
}


