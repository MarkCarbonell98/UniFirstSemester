#include "fcpp.hh"

int main(int argc, char const *argv[])
{
    const int n = 50000000;
    bool prim[n];

    prim[0] = false;
    prim[1] = false;
    for(int i = 2; i < n; i++) 
        prim[i] = true;    

    for(int i = 2; i <=sqrt((double) n); i++)
        if(prim[i])
            for(int j = 2*i; j < n; j++)
                prim[j] = false;

    int m = 0;
    for(int i = 0; i<n;i++) 
        if(prim[i])
            m++;
    print("# of prims: ");
    print(m);

    for(auto val : prim) {
        std::cout << val << " ";
    }
    
    return 0;
}
