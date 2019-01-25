#ifndef AUFGABE1_HH
#define AUFGABE1_HH

template<typename Map>
class LetterFrequencies {
    public:
        template<typename Source>
        void readData(Source& source);

        void printStatistics();
};

#endif //AUFGABE1_HH