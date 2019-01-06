#ifndef CLASS_TEST
#define CLASS_TEST

#include <iostream>

class SimpleFloatArray {
    public:
        //new field constructor
        SimpleFloatArray(int s, float f);

        //copy constructor
        SimpleFloatArray(const SimpleFloatArray&);

        //definition per copy of fields with = 
        SimpleFloatArray& operator=(const SimpleFloatArray&);

        ~SimpleFloatArray();

        float& operator[](int i);

        int numIndices();

        int minIndex();

        int maxIndex();

        bool isMember(int i);

    private:
        int n;
        float* p;
};

#endif// CLASS_TEST