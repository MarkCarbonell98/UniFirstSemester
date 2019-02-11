#include <iostream>

template<class C>
void selectionsort(C& a) {
    for(int i = 0; i < a.size() -1; i++) {
        int min = i;
        for(int j= i+1; j <a.size();j++)
            if(a[j] < a[min] ) min = j;
        std::swap(a[i], a[min] );
    }
}

template<class C>
void bubblesort(C& a) {
    for(int i = a.size() -1; i >= 0; i--)
        for(int j = 0; j < i; j++)
            if(a[j+1] < a[j])
                std::swap(a[j+1], a[j]);
}

template<class C>
void insertionsort(C& a)
{
    for(int i = 1; i < a.size(); i++)
    {
        int j = i;
        while(j > 0 && a[j-1] > a[j])
        {
            std::swap(a[j], a[j-1]);
            j--;
        }
    }
}

template<class C>
void rec_merge_sort(C& a, int o, int n)
{
    if(n == 1) return;
    int n1 = n / 2;
    int n2 = n -n1;
    rec_merge_sort(a,o,n1);
    rec_merge_sort(a, o + n1; n2);

    C b(n);
    int i1 = o, i2 = o + n1;
    for(int k = 0; k < n; k++)
        if(i2 >= o+n || (i1 < o+n1 && a[i1] <= a[i2]))
            b[k] = a[ai++];
        else 
            b[k] = a[i2++];

    for(int k = 0; k<n; k++) a[o+k] = b[k];
}

template <class C>
void mergesort(C& a)
{
    rec_merge_sort(a, 0, a.size());
}

template <class C>
inline void reheap(C& a, int n, int i)
{
    while(2*i+1<n)
    {
        int l = 2* i +1;
        int r = l +1;
        int k = ((r < n) && (a[r] > a[l])) ? r : l;
        if(a[k] <= a[i]) break;
        std::swap(a[k] , a[i]);
        i = k; 
    }
}

template<class C>
void heapsort(C& a) {
    for(int i = a.size() -1; i >= 0; i--)
        reheap(a , a.size(), i);
    for(int i = a.size() -1; i >= 0; i--)
    {
        std::swap(a[0], a[i]);
        reheap(a,i,0);
    }
}

template<class C>
int partition( C& a, int l, int r, int q)
{
    std::swap(a[q], a[r]);
    q = r;
    int i = l -1, j = r;

    while(i < j)
    {
        i++; while(i < j && a[i] <= a[q]) i++;
        j--; while(i < j && a[i] >= a[q]) j--;
        if( i  < j)
            std::swap(a[i], a[j]);
        else 
            std::swap(a[i], a[q]);
    }
    return i;
}

template<class C>
void rec(C& a, int l, int r)
{
    if( l < r)
    {
        int i = partition(a, l, r,r);
        rec(a, l , i-1);
        rec(a, i+1, r);
    }
}

template<class C>
void quicksort(C& a) {
    rec(a , 0, a.size() -1);
}