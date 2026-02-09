#include <iostream>
#include <string>

using namespace std;

class Kutya {
public:
    string nev;
    int kor;

    // Kutya(std::string n, int k) : nev(n), kor(k) {}
    
    void ugat() {
        cout << "Vau-vau!" << endl;
    }
    
    void szuletesnap();
};

void Kutya::szuletesnap() {
    kor++;
    cout << "Boldog szulinapot! Most mar " << kor << " eves vagy." << endl;
}

int main() {
    Kutya bodri;
    bodri.nev = "Bodri";
    bodri.kor = 3;
    
    cout << "Nev: " << bodri.nev << endl;
    cout << "Kor: " << bodri.kor << endl;
    
    bodri.ugat();
    bodri.szuletesnap();
    
    return 0;
}