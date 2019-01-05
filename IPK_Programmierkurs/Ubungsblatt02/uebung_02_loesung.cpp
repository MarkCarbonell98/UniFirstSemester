//loesung des aufgabenblatts

// a)
/*
    cmd line eingabe: 

    curl -LO https://conan.iwr.uni-heidelberg.de/data/teaching/ipk_ws2018/exampleprogram.tar.xz

    cmd line output: 

    hat ein neues comprimiertes order.zip erstellt 

*/

// b)

/*
    eingabe: 

    file exampleprogram.tar.xz

    ergibt: 
    exampleprogram.tar.xz: XZ compressed data
*/

// c)

/*
    eingabe: 

    tar xf exampleprogram.tar.xz

    output: 

    hat ein exampleprogram Ordner erzeugt

*/

// d)

/*
    eingabe in cmd line: 

    cd exampleprogram
    dir

    ergibt: exampleprogam.cc

    eingabe in cmd line: 

    g++ -o exampleprogram exampleprogram.cc

    ergibt: exampleprogram.exe

    eingabe: ./exampleprogram.exe 2

    ergibt 4

    eingabe: ./exampleprogram.exe 100

    ergibt: 10000

    dh => exampleprogram berechnet der angegebene Zahl zum quadrat, also x*x
*/

// e)

/*
    eingabe in cmd line: 
    cd ..

    tar cfj new_archiv exampleprogram/exampleprogram.cc

    ergibt ein archiv namens new_archive
*/

// d)

/*
    eingabe in der cmd line: 
    tar tf new_archive

    ergibt: exampleprogram/exampleprogram.cc

    eingabe: 
    mkdir directory_for_new_archive
    mv new_archive directory_for_new_archive
    cd directory_for_new_archive

    tar xf new_archive 

    ergibt: hat ein Ordner erstellt mit exampleprogram.cc drin

    eingabe: 
    g++ -o exampleprogram exampleprogram.cc
    ./exampleprogram.exe 10

    ergibt 100

*/

// falls 
#include <iostream>

int main(int argc, char** argv) {
    std::cout << "Typing is difficult" << std::endl;
    int ret = 0;
    return ret;
}

// ergibt fehlermeldungen:
/*
    $ g++ uebung_02_loesung.cpp
uebung_02_loesung.cpp:103:19: fatal error: iostrea: No such file or directory
 #include <iostrea>
                  ^
compilation terminated.

dann: 

g++ uebung_02_loesung.cpp
uebung_02_loesung.cpp: In function 'int main(int, char**)':
uebung_02_loesung.cpp:106:5: error: 'stf' has
not been declared
     stf::cout << "Typing is difficult" << endl;
     ^~~
uebung_02_loesung.cpp:106:43: error: 'endl' was not declared in this scope
     stf::cout << "Typing is difficult" << endl;
                                           ^~~~
uebung_02_loesung.cpp:106:43: note: suggested
alternative:
In file included from c:\mingw\lib\gcc\mingw32\6.3.0\include\c++\iostream:39:0,
                 from uebung_02_loesung.cpp:103:
c:\mingw\lib\gcc\mingw32\6.3.0\include\c++\ostream:590:5: note:   'std::endl'
     endl(basic_ostream<_CharT, _Traits>& __os)
     ^~~~
uebung_02_loesung.cpp:108:12: error: 'retv' was not declared in this scope
     return retv;
            ^~~~


dann stf === std

g++ uebung_02_loesung.cpp
uebung_02_loesung.cpp: In function 'int main(int, char**)':
uebung_02_loesung.cpp:106:43: error: 'endl' was not declared in this scope
     std::cout << "Typing is difficult" << endl;
                                           ^~~~
uebung_02_loesung.cpp:106:43: note: suggested
alternative:
In file included from c:\mingw\lib\gcc\mingw32\6.3.0\include\c++\iostream:39:0,
                 from uebung_02_loesung.cpp:103:
c:\mingw\lib\gcc\mingw32\6.3.0\include\c++\ostream:590:5: note:   'std::endl'
     endl(basic_ostream<_CharT, _Traits>& __os)
     ^~~~
uebung_02_loesung.cpp:108:12: error: 'retv' was not declared in this scope
     return retv;
            ^~~~

dann retv === ret

g++ uebung_02_loesung.cpp
uebung_02_loesung.cpp: In function 'int main(int, char**)':
uebung_02_loesung.cpp:106:43: error: 'endl' was not declared in this scope
     std::cout << "Typing is difficult" << endl;
                                           ^~~~
uebung_02_loesung.cpp:106:43: note: suggested
alternative:
In file included from c:\mingw\lib\gcc\mingw32\6.3.0\include\c++\iostream:39:0,
                 from uebung_02_loesung.cpp:103:
c:\mingw\lib\gcc\mingw32\6.3.0\include\c++\ostream:590:5: note:   'std::endl'
     endl(basic_ostream<_CharT, _Traits>& __os)
     ^~~~

dann kompiliert er ganz normal zu a.exe


*/



