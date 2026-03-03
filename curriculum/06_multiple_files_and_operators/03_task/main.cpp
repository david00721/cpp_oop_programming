#include <iostream>
#include "ResourcePack.h"
#include "GuardedResourcePack.h"

int main()
{
    std::cout << "=== URKOLONIA ERQFORRAS-KEZELO TESZTELES ===" << std::endl;

    std::cout << "\n--- 1. Alap csomagok letrehozasa ---" << std::endl;
    ResourcePack alpha(101, 500, 200);
    ResourcePack beta(102, 300, 100);

    std::cout << "Elvart Alpha: Energia 500, Asvany 200" << std::endl;
    std::cout << "Kapott Alpha: Energia " << alpha.getEnergy() << ", Asvany " << alpha.getMinerals() << std::endl;

    std::cout << "\n--- 2. Fuggvenytulterheles tesztelese (addResources) ---" << std::endl;
    // addResources (overload 1)
    alpha.addResources(50, 50);
    std::cout << "[+] Alpha novelve (50, 50) ertekkel." << std::endl;
    std::cout << "Elvart Alpha: Energia 550, Asvany 250" << std::endl;
    std::cout << "Kapott Alpha: Energia " << alpha.getEnergy() << ", Asvany " << alpha.getMinerals() << std::endl;

    // addResources (overload 2 - Objektum átadása)
    alpha.addResources(beta);
    std::cout << "\n[+] Alpha + Beta (Beta objektumkent hozzaadva Alpha-hoz)." << std::endl;
    std::cout << "Elvart Alpha: Energia 850, Asvany 350" << std::endl;
    std::cout << "Kapott Alpha: Energia " << alpha.getEnergy() << ", Asvany " << alpha.getMinerals() << std::endl;

    std::cout << "\n--- 3. Operatorok tesztelese ---" << std::endl;

    // operator+
    ResourcePack gamma = alpha + beta;
    std::cout << "[+] Gamma = Alpha + Beta" << std::endl;
    std::cout << "Elvart Gamma: ID 999, Energia 1150, Asvany 450" << std::endl;
    std::cout << "Kapott Gamma: ID " << gamma.getPackId() << ", Energia " << gamma.getEnergy() << ", Asvany " << gamma.getMinerals() << std::endl;

    // operator*
    ResourcePack delta = beta * 3;
    std::cout << "\n[+] Delta = Beta * 3" << std::endl;
    std::cout << "Elvart Delta: ID 999, Energia 900, Asvany 300" << std::endl;
    std::cout << "Kapott Delta: ID " << delta.getPackId() << ", Energia " << delta.getEnergy() << ", Asvany " << delta.getMinerals() << std::endl;

    // operator- (kivonás és 0-ra vágás tesztje!)
    // Beta energiája 300, Alpha energiája már 850. 300 - 850 mínuszba menne!
    ResourcePack epsilon = beta - alpha;
    std::cout << "\n[+] Epsilon = Beta - Alpha (0-ra vagas tesztje)" << std::endl;
    std::cout << "Elvart Epsilon: ID 999, Energia 0, Asvany 0" << std::endl;
    std::cout << "Kapott Epsilon: ID " << epsilon.getPackId() << ", Energia " << epsilon.getEnergy() << ", Asvany " << epsilon.getMinerals() << std::endl;

    std::cout << "\n--- 4. Vedett csomag (Orkoles) es Mutatok tesztelese ---" << std::endl;
    GuardedResourcePack guarded(201, 400, 500, 5); // ID: 201, Energia: 400

    int targetEnergy = 500; // Ezt várná el a bázis
    int totalAlarms = 0;    // Globális riasztásszámláló

    std::cout << "Elvart elvart energia a bazistol: " << targetEnergy << std::endl;
    std::cout << "Kapott aktualis energia a csomagban: " << guarded.getEnergy() << std::endl;

    std::cout << "Riasztasok szama audit elott (Elvart: 0): " << totalAlarms << std::endl;

    // Audit futtatása (átadjuk a változók memóriacímét a mutatóknak)
    std::cout << "\n[!] Biztonsagi audit futtatasa..." << std::endl;
    bool isAuditPassed = guarded.securityAudit(&targetEnergy, &totalAlarms);

    std::cout << "Audit sikeres? (Elvart: 0 / Nem): " << (isAuditPassed ? "1 / Igen" : "0 / Nem") << std::endl;
    std::cout << "Riasztasok szama audit utan (Elvart: 1): " << totalAlarms << std::endl;

    std::cout << "\n=== TESZTELES VEGE ===" << std::endl;
    return 0;
}