#include "../Header/vector.h"

#include <iostream>
#include <stdarg.h>
#include <stdlib.h>

//--------------------------------------------------------------------------------
static void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
//--------------------------------------------------------------------------------
Vector::Vector() {
    this->pArray = nullptr;
}
//--------------------------------------------------------------------------------
Vector::Vector(int nLength, ...) {
    this->pArray = new int[nLength];
    this->nLength = nLength;
    this->sorted = false;

    va_list pElement; 

    for (int i = 0; i < nLength; i++) {
        if (i == 0) 
            va_start(pElement, nLength);
        else
            va_arg(pElement, int);

        pArray[i] = *pElement;
    }

    va_end(pElement);
}
//--------------------------------------------------------------------------------
Vector::Vector(const Vector& source) {
    this->nLength = source.GetLength();
    this->pArray = new int[this->nLength];
    this->sorted = source.IsSorted();

    for (int i = 0; i < this->nLength; i++)
        this->pArray[i] = source[i];
}
//--------------------------------------------------------------------------------
int Vector::operator[](int nIndex) const {
    if (nIndex > (this->nLength - 1) || nIndex < (0)) {
        perror("ERROR: OUT OF BOUNDS!!!");
        return -20000000000000;
    }

    return this->pArray[nIndex];
}
//--------------------------------------------------------------------------------
int Vector::operator*() {
    return *pArray;
}
//--------------------------------------------------------------------------------
int* Vector::ToPointer() {
    int *pNewArray = new int[this->nLength];

    for (int i = 0; i < this->nLength; i++)
        pNewArray[i] = this->pArray[i];

    return pNewArray;
}
//--------------------------------------------------------------------------------
void Vector::AddElement(int nValue) {
    int *pTemp = (int*)realloc(this->pArray, sizeof(int) * (this->nLength + 1));

    if (pTemp != NULL) {
        this->pArray = pTemp;
    } else {
        perror("ERROR: CAN\'T ALLOCATE NEW MEMORY!!!");
        return;
    }

    this->nLength++;
    pArray[this->nLength - 1] = nValue;
}
//--------------------------------------------------------------------------------
int Vector::GetLength() const {
    return this->nLength;
}
//--------------------------------------------------------------------------------
void Vector::Print() const {
    for (int i = 0; i < this->nLength; i++) {
        std::cout << this->pArray[i] << " ";
    }
    std::cout << std::endl;
}
//--------------------------------------------------------------------------------
void Vector::Sort() {
    int nTemp;

    int j = 0;
    for (int i = 1; i < this->nLength; i++) {
        j = i;
        while (j > 0) {
            if (pArray[j] < pArray[j - 1])
                Swap(pArray[j], pArray[j - 1]);

            j--;
        }
    }

    sorted = true;
}
//--------------------------------------------------------------------------------
bool Vector::IsSorted() const {
    return this->sorted;
}
//--------------------------------------------------------------------------------
Vector::~Vector() {
    delete [] this->pArray;
    this->sorted = false;
    this->nLength = 0;
}
