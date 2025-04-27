#include <iostream>

using namespace std;

template <typename T1, typename T2>
class Pair {

    private:
        T1 first;
        T2 second;

    public:

        Pair(const T1& first, const T2& second) : first(first), second(second) {}
    
        T1 getFirst() const { return first; }
        T2 getSecond() const { return second; }

        void print() const {
            cout << first << ", " << second << endl;
        }

};


int main () {

    Pair<int, double> p1(15, 0.234234);
    Pair<char, int> p2('l', 993);
    
    p1.print();
    p2.print();

    return 0;
}