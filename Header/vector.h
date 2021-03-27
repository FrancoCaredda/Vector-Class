#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
private:
    int *pArray;
    int nLength;
    bool sorted;
public:
    Vector();
    Vector(int nLength, ...);
    Vector(const Vector& source);

    void AddElement(int nValue);
    int GetLength() const;

    int operator[](int nIndex) const;
    int operator*();

    int* ToPointer();

    void Print() const;

    void Sort();
    bool IsSorted() const;

    ~Vector();
};


#endif