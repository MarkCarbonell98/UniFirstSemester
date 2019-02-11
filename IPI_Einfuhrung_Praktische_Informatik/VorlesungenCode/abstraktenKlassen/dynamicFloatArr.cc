#include "floatArray.cc"

class DynamicFloatArray : public FloatArray
{
public :
DynamicFloatArray ( ) { n = 0; o = 0; p = new float [1]; }
virtual ~DynamicFloatArray ( ) { delete [ ] p ; }
virtual float& operator []( int i ) ;
virtual int numIndices ( ) { return n ; }
virtual int minIndex ( ) { return o ; }
virtual int maxIndex ( ) { return o + n - 1 ; }
virtual bool isMember( int i ) { return ( i >= o ) && ( i < o+n ) ; }
private :
int n ; // Anzahl Elemente
int o ; // Ursprung der Indexmenge
float * p ; // Zeiger auf built i n array
};

float& DynamicFloatArray::operator []( int i ) {
        
    if ( i < o || i >= o+n )
    { // resize
    int new_o , new_n ;
    if ( i < o ) {
    new_o = i ;
    new_n = n + o - i ;
    }
    else
    {
    new_o = o ;
    new_n = i - o + 1;
    }
    float * q = new float [ new_n ] ;
    for ( int j =0; j<new_n ; j=j+1 ) q [ j ] = 0.0;
    for ( int j =0; j<n ; j=j+1 )
    q [ j + o - new_o ] = p [ j ] ;
    delete [ ] p ;
    p = q ;
    n = new_n ;
    o = new_o ;
    }
    return p [ i - o ] ;
}