#include "../Header/vector.h"

#include <iostream>

using namespace std;

int main(void) {
    Vector vector1(5, 5, 1, 6, 4, 3);
    vector1.Sort();
    vector1.Print();
    int nLength = vector1.GetLength();
    int *pArray = vector1.ToPointer();

    pArray[0] = 5;

    for (int i = 0; i < nLength; i++) {
        cout << pArray[i] << " ";
    }

    return 0;
}