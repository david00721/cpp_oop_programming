#include <iostream>
using namespace std;

class Teglalap {
public:
    int szelesseg;
    int magassag;

    // Teglalap(int sz, int m) : szelesseg(sz), magassag(m) {}

    int teruletSzamitas() {
        return szelesseg * magassag;
    }
};

int main() {
    // Teglalap teglalap1(5, 10);
    // Teglalap teglalap2(7, 8);

    Teglalap teglalap1;
    teglalap1.szelesseg = 5;
    teglalap1.magassag = 10;

    Teglalap teglalap2;
    teglalap2.szelesseg = 7;
    teglalap2.magassag = 8;

    cout << "Első téglalap területe: " << teglalap1.teruletSzamitas() << endl;
    cout << "Második téglalap területe: " << teglalap2.teruletSzamitas() << endl;

    return 0;
}