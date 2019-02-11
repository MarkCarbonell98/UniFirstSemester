#include <iostream>
#include <string>
class Student {
    private:    
        std::string _Vorname;
        std::string _Nachname;
        int _Matrikelnummer;
    public:
        Student(std::string vorname, std::string nachname, int matrikelnummer): _Vorname(vorname), _Nachname(nachname), _Matrikelnummer(matrikelnummer) {} 

        std::string firstName() const {
            return _Vorname;
        }

        std::string lastName() const {
            return _Nachname;
        }

        int idNumber() const {
            return _Matrikelnummer;
        }

        friend std::ostream& operator<<(std::ostream& input, const Student &student) {
            input << student.lastName() << ", " << student.firstName() << ": " << student.idNumber();
            return input;
        }

};

int main(int argc, char const *argv[])
{
    Student marcos("Marcos", "Carbonell", 3529019);
    std::cout << marcos << std::endl;
    std::cout << marcos.idNumber() << std::endl;
    std::cout << marcos.firstName() << std::endl;
    std::cout << marcos.lastName() << std::endl;
    return 0;
}

