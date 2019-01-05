#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <limits>

using namespace std;

//aufgabe 1

// A)

//testing v.size() und v.resize()
void playingWithVectors() {
    vector<double> emptyVector;

    vector<double> notReallyEmptyVector(10);

    vector<double> fullVector = {{3,8,9,7,4,1}};


    //testing v.size
    printf("The notReallyEmptyVector size is %i \n and the fullVector size is %i \n", notReallyEmptyVector.size(), fullVector.size());

    //testing v.resize()
    notReallyEmptyVector.resize(42);
    fullVector.resize(25);

    printf("The notReallyEmptyVector resized size is %i \n and the fullVector resized size is %i \n", notReallyEmptyVector.size(), fullVector.size());

    return;
}

//Eintrage mit einer for-schleife geben
void readVector(vector<double> input) {
    
    printf("The following vector has the values:\n(");
    for(auto i = input.begin(); i != input.end(); ++i) {
        cout << *i << ", ";
    }
    printf(")\n");

    return;
}

// B)

void findBiggestAndSmallestNumber(vector<double> input) {
    if(input.size() == 0) {
        printf("The largest value of the vector is: %i, the smallest one %i \n", 0, 0);
        printf("The pair looks like: (%i,%i) \n", 0,0);
        return;
    }
    double largest, smallest;
    //find the largest value in vector
    largest = *max_element(input.begin(), input.end());

    //find the smallest value in vector
    smallest = *min_element(input.begin(), input.end());

    //create the pair 
    pair<double,double> thePair = make_pair(smallest, largest);

    //print it all to the console
    printf("The largest value of the vector is: %g, the smallest one is: %g \n", thePair.second, thePair.first);

    printf("The pair looks like: (%g,%g) \n", thePair.second, thePair.first);
    return;
}


// C 

vector<double> reversed(vector<double> v) {
    if(v.size() == 0) {
        return v;
    }

    //create the new vector
    vector <double> theNewVector;

    //loop through the input v vector in reverse and pushing the elements to the new vector
    for(int i = v.size() - 1; i >= 0; i--) {
        theNewVector.push_back(v[i]);
    }

    //printing the vector to the console
    
    printf("The values of the reversed vector are:\n("); 
    for(unsigned i = 0; i <= theNewVector.size() - 1; i++) {
        printf("%g, ", theNewVector[i]);
    }
    printf(") \n");
    
    return theNewVector;
}

vector<double> roundThisVector(vector<double> &input) {

    printf("The resulting vector rounded looks like:'\n (");
    for(unsigned i = 0; i<= input.size() -1; i++) {
        input[i] = round(input[i]);
        printf("%g, ", input[i]);
    }
    printf(")\n");

    return input;
}

vector<double> reverseVectorUsingSwap(vector<double> &input) {
    if(input.size() == 0) {
        return input;
    }

    printf("The resulting vector rounded looks like:\n (");
    reverse(input.begin(), input.end());
    for(unsigned i = 0 ; i <= input.size() - 1; i++) {
        printf("%g, ", input[i]);
    }
    printf(")\n");

    return input;
}

//aufgabe2

//I am aware of the isdigit() function, eventhough I'll implement my own.

int convertCharToNumber(char n) {

    if(n == 48)
    {
        return 48;
    }
    else if(n == 49) {
        return 1;
    }
    else if(n == 50) {
        return 2;
    }
    else if(n == 51) {
        return 3;
    }
    else if(n == 52) {
        return 4;
    }
    else if(n == 53) {
        return 5;
    }
    else if(n == 54) {
        return 6;
    }
    else if(n == 55) {
        return 7;
    }
    else if(n == 56) {
        return 8;
    }
    else if(n == 57) {
        return 9;
    } else { 
        return 0;
    }
}

double calculateNumber(string n) {

    if(n == "0") {
        return numeric_limits<double>::quiet_NaN();
    }
    int theFirstNumber, theNewNumber = 0, thePower = 0;
    
    for(unsigned i = 0; convertCharToNumber(n[i]); i++) {


        if(convertCharToNumber(n[i]) == 48) {
            theFirstNumber = 0;
        } else {
            theFirstNumber = convertCharToNumber(n[i]);
        }

        thePower = ceil(pow(10, n.size() - 1 - i));

        theNewNumber += theFirstNumber * thePower;
    }
    return theNewNumber;
}

// string trimZeroes(string &number) {
// }
string trimZeroes(string &number) {
    if(number.at(0) == '0') {
        number.erase(0, number.find_first_not_of("0"));
    }
    return number;
}

string trimWeirdChars(string &number) {
    try {

        //Aufgabe 2b
        if(number.at(0) == '-' || number.at(0) == '+') {
            number.erase(0, number.find_first_not_of("-+"));
        }

        if(number.find_first_not_of("0123456789") != string::npos) {
            number.erase(number.find_first_not_of("0123456789"), number.size());
        }

        //aufgabe 2e
        if(number.size() == 0) {
            throw invalid_argument("The number you entered is not valid");
        }
    } 
    catch (const invalid_argument e) {
        cerr << "Invalid argument: " << e.what() << endl;
    }

    return number;
}

// aufgabe 2a)
int parse_int(string number) {
    string theOriginalNumber = number;
    try {

        if(number == "") {
            throw invalid_argument("please insert a value");
        } 

        trimZeroes(theOriginalNumber);
        trimZeroes(number);
        trimWeirdChars(number);

        if(theOriginalNumber[0] == '-') {
            return calculateNumber(number) * -1;
        } else {
            return calculateNumber(number);
        }

    }

    catch (const invalid_argument e) {
        cerr << "The argument you entered is empty, " << e.what() << endl;
    }
    return 0;
}

// aufgabe 2d)
//damit ihr sehen kann dass die aufgaben 2a, 2b und 2d gemacht wurden, ohne alles zu mischen.
pair<int,int> parse_int_as_pair(string number) {
    try {
        if(number == "") {
            throw invalid_argument("please insert a value");
        } 
        return make_pair(parse_int(number), number.find_first_not_of("+-1234567890"));
    } catch(const invalid_argument e) {
        cerr << e.what() << endl;
    }
    return make_pair(0,0);
}

void test_parse_int(vector<string> input) {
    for(unsigned i = 0; i <= input.size() - 1; i++) {
        printf("parse_int('%s') = %i \n \n", input[i].c_str(), parse_int(input[i]));
    }
    return;
}

void test_parse_int_as_pair(vector<string> input) {
    for(unsigned i = 0; i <= input.size() - 1; i++) {
        printf("\n parse_int_as_pair(%s) = (%i,%i) \n", input[i].c_str(), parse_int_as_pair(input[i]).first, parse_int_as_pair(input[i]).second);
    }
    return;
}

int main() {
    //Aufgabe 1a
    vector<double> testVector1 = {{1,2,3,4,5,6,7,8,9,10}};
    vector<double> testVectorUneven = {{1,2,3,4,5,6,7,8,9,10,11}};
    vector<double> testVectorDecimal = {{1.1234,1.123,2.3,5.235,10,12.1234,16.56}};
    vector<double> testVector2(20);
    vector<double> emptyTestVector;
    vector<string> testVectorStrings = {{"1234", "0001234", "0001.234", "0002.1234", "1a1234",  "1234a1234", "asdf", "-1234", "-12.1234", "-a1234", "-.1234", "-1.234","000-1.234", "-10000.234", "-.2", "-.3", "-.333333","", "."}};


    playingWithVectors();
    readVector(emptyTestVector);
    //Falls kein explizite Wert fur den Vector eingegeben ist dann interpretiert der 
    //Compile den Wert als 0

    //Aufgabe 1b
    findBiggestAndSmallestNumber(emptyTestVector);
    readVector(emptyTestVector);

    //Aufgabe 1c
    reversed(emptyTestVector);

    //Aufgabe 1d
    roundThisVector(testVectorDecimal);

    //beweis dass die elementen des Vectors geandert wurden
    readVector(testVectorDecimal);

    //Aufgabe 1e
    reverseVectorUsingSwap(testVectorUneven);

    //beweis
    readVector(testVectorUneven);


    //Aufgabe 2abce
    test_parse_int(testVectorStrings);

    //Aufgabe 2d
    test_parse_int_as_pair(testVectorStrings);

    char c = 49;
    cout << c << endl;
    return 0;
}

