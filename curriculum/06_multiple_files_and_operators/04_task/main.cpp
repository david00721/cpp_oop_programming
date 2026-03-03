#include <iostream>
#include <string>
#include "Agent.h"
#include "ClassifiedDocument.h"
#include "ArchiveVault.h"

int main()
{
    std::cout << "=== SZIGORUAN TITKOS ARCHIVUM TESZTELES ===" << std::endl;

    std::cout << "\n--- 1. Teszt: Ugynok letrehozasa ---" << std::endl;
    Agent rookie("John Doe", 2);
    Agent veteran("Jane Smith", 5);

    std::cout << "Elvart ugynok 1: John Doe (Szint: 2)" << std::endl;
    std::cout << "Kapott ugynok 1: " << rookie.getName() << " (Szint: " << rookie.getClearanceLevel() << ")" << std::endl;

    std::cout << "Elvart ugynok 2: Jane Smith (Szint: 5)" << std::endl;
    std::cout << "Kapott ugynok 2: " << veteran.getName() << " (Szint: " << veteran.getClearanceLevel() << ")" << std::endl;

    std::cout << "\n--- 2. Teszt: Dokumentum olvasasa (Alacsony szint) ---" << std::endl;
    ClassifiedDocument doc("PROJECT_OMEGA_DETAILS", 5);

    std::string result1 = doc.readDocument(rookie);
    std::cout << "Elvart kimenet: ACCESS_DENIED" << std::endl;
    std::cout << "Kapott kimenet: " << result1 << std::endl;

    std::cout << "Elvart probalkozasok szama: 1" << std::endl;
    std::cout << "Kapott probalkozasok szama: " << doc.getAccessAttempts() << std::endl;

    std::cout << "\n--- 3. Teszt: Dokumentum olvasasa (Megfelelo szint) ---" << std::endl;
    std::string result2 = doc.readDocument(veteran);
    std::cout << "Elvart kimenet: PROJECT_OMEGA_DETAILS" << std::endl;
    std::cout << "Kapott kimenet: " << result2 << std::endl;

    std::cout << "Elvart probalkozasok szama: 2" << std::endl;
    std::cout << "Kapott probalkozasok szama: " << doc.getAccessAttempts() << std::endl;

    std::cout << "\n--- 4. Teszt: Szef (ArchiveVault) es Mutable (A kritikus teszt) ---" << std::endl;
    ClassifiedDocument alienDoc("ALIEN_TECHNOLOGY", 4);
    ArchiveVault vault(alienDoc);

    // Elkérjük a dokumentumot KONSTANS referenciaként.
    // Itt dolgozik a mutable: bár a securedDoc konstans, a readDocument() mégis növelni tudja a számlálót!
    const ClassifiedDocument &securedDoc = vault.getDocument();

    std::cout << "Szef kompromittalodott kezdetben? (Elvart: 0 / Hamis)" << std::endl;
    std::cout << "Kapott: " << vault.isCompromised() << std::endl;

    std::cout << "\n[!] Hacker tamadas indul (4 gyors olvasasi kiserlet)..." << std::endl;
    Agent hacker("Anonymous", 1);

    securedDoc.readDocument(hacker); // 1. kísérlet
    securedDoc.readDocument(hacker); // 2. kísérlet
    securedDoc.readDocument(hacker); // 3. kísérlet

    std::cout << "Probalkozasok szama 3 kiserlet utan (Elvart: 3): " << securedDoc.getAccessAttempts() << std::endl;
    std::cout << "Szef kompromittalodott 3 kiserlet utan? (Elvart: 0 / Hamis): " << vault.isCompromised() << std::endl;

    securedDoc.readDocument(hacker); // 4. kísérlet (Itt kell átbillennie a védelemnek!)

    std::cout << "Probalkozasok szama 4 kiserlet utan (Elvart: 4): " << securedDoc.getAccessAttempts() << std::endl;
    std::cout << "Szef kompromittalodott 4 kiserlet utan? (Elvart: 1 / Igaz): " << vault.isCompromised() << std::endl;

    std::cout << "\n=== TESZTELES VEGE ===" << std::endl;
    return 0;
}