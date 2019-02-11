#include "floatArr.cc"

//polynomial basisklasse
//floatarray abgeleitete klasse

class Polynomial : public floatArray {
    private:
        floatArray coefficients;
    public:
        Polynomial();

        Polynomial(int n) : floatArray(n+1, 0.0) {}

        float eval(float x) {
            float sum = 0.0;
            for(int i = maxIndex(); i >= 0; i--) 
                sum = sum * x + (*this)[i]; //also operator[](i) posible;
            return sum;
        }

        int degree() {
            return maxIndex();
        }

        Polynomial operator+(Polynomial q) {
            int number = degree();
            if(q.degree() > number) number = q.degree();
            Polynomial r(number);
            for(int i = 0; i <= number; i++) {
                if( i <= degree())
                    r[i] += operator[](i);
                if(i <= q.degree())
                    r[i] += q[i];
            } 
            return r;
        }

        Polynomial operator*(Polynomial q) {
            Polynomial r(degree() + q.degree());
            for(int i = 0; i <= degree(); i++)
                for(int j = 0; i <= q.degree(); j++)    
                    r[i+j] = r[i+j] + (*this)[i] * q[j];
            return r;
        }

        void print() {
            if(degree() < 0)
                std::cout << 0;
            else 
                std::cout << (*this)[0];

            for(int i = 1; i <= maxIndex(); i++)
                std::cout << "+" << (*this)[i] << "x^" << i;

            std::cout << "\n";
        }

        bool operator==(Polynomial q) {
            if(q.degree() > degree()){
                for(int i = 0; i <= degree(); i++)
                    if((*this)[i] != q[i]) return false;
                for(int i = degree() + 1; i <= q.degree(); i++)
                    if(q[i] != 0.0) return false;
            } else {
                for ( int i =0; i<=q . degree () ; i=i+1 )
                    if ( (*this ) [ i ] != q [ i ] ) return false ;
                for ( int i=q . degree () +1; i<=degree () ; i=i +1 )
                    if ( (*this ) [ i ] != 0.0 ) return false ;
            }
            return true;
        }

};

void g(floatArray a) {a[3] = 1.0;}
int main(int argc, char const *argv[])
{
    Polynomial p(10);
    floatArray b(100, 0.0);
    g(p);   //slicing. Only the values of the simple float array will be copied by the parameter a. The rest of residual parameters and member functions of p will not be copied, as p is not of class floatArray.

    Polynomial q(10);

    Polynomial * ptr1 = &p;
    Polynomial * ptr2 = &p;
    std::cout << (ptr1 == ptr2) << "\n";
    Polynomial * ptr3 = &q;
    std::cout << (ptr1 == ptr3) << "\n";


    //as-is the class floatArray erhalt ein polynomial als unterobjekt im moment de ableitung
    // p = b
    b = p; //slicing. 
    std::cout << p[0]; 
    // show(b);
    return 0;
}


