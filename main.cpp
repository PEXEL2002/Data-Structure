#include "ui.h"
#include "struct.h"
#include "ArrayList.h"
#include "DoublyLinkedList.h"
#include "SinglyLinkedList1.h"
#include "SinglyLinkedList2.h"
#include <iostream>
#include <chrono>
#include <string>
#include <climits>

using namespace std;
int main() {
    system("clear");
    string structElement[4] = {"Array List", "Singly Linked List Head Only", "Singly Linked List Head Tail", "Doubly Linked List"};
    int action, actionProgram = 1, size, ifTests;
    do{
        cout << "Czy przeprowadzić badania? (1 - tak, 0 - nie):";
        cin >> ifTests;
    } while (ifTests != 0 && ifTests !=1);
    if(ifTests == 0){
        do {
            do {
                cout << "Podaj ilość danych w strukturze: ";
                cin >> size;
            } while (size < 0); 
            generateIntToFile("data.txt", size, 0, INT_MAX);
            Struct *arrayOfStructs[4];
            arrayOfStructs[0] = new ArrayList("data.txt");
            arrayOfStructs[1] = new SinglyLinkedList1("data.txt");
            arrayOfStructs[2] = new SinglyLinkedList2("data.txt");
            arrayOfStructs[3] = new DoublyLinkedList("data.txt");
            do {
                cout << "1.Dodaj element\n";
                cout << "2.Dodaj element na poczatku\n";
                cout << "3.Dodaj element na koncu\n";
                cout << "4.Usun element\n";
                cout << "5.Usun element z poczatku\n";
                cout << "6.Usun element z konca\n";
                cout << "7.Znajdz element\n";
                cout << "8.Wyswietl struktury\n";
                cout << "9.Wyswietl informacje o strurze\n";
                cout << "0.Wygeneruj na nowo dane do struktór\n";
                cout << "Wybierz operacje do wykonania: " << endl;
                cin >> action;
                switch (action) {
                    case 1:
                        uiAddElement(arrayOfStructs, structElement);
                        break;
                    case 2:
                        uiAddElementFront(arrayOfStructs, structElement);
                        break;
                    case 3:
                        uiAddElementBack(arrayOfStructs, structElement);
                        break;
                    case 4:
                        if(arrayOfStructs[0]->getSize() == 1){
                            cout << "Struktury są puste" << endl;
                            action = 0;
                            break;
                        }
                        uiDelElement(arrayOfStructs, structElement);
                        break;
                    case 5:
                        if(arrayOfStructs[0]->getSize() == 1){
                            cout << "Struktury są puste" << endl;
                            action = 0;
                            break;
                        }
                        uiDelElementFront(arrayOfStructs, structElement);
                        break;
                    case 6:
                        if(arrayOfStructs[0]->getSize() == 1){
                            cout << "Struktury są puste" << endl;
                            action = 0;
                            break;
                        }
                        uiDelElementBack(arrayOfStructs, structElement);
                        break;
                    case 7:
                        uiFindElement(arrayOfStructs, structElement);
                        break;
                    case 8:
                        uiPrint(arrayOfStructs, structElement);
                        break;
                    case 9:
                        uiPrintInfo(arrayOfStructs, structElement);
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Nie ma takiej operacji" << endl;
                        break;
                }
            } while (action);
            for (int i = 0; i < 4; ++i) {
                delete arrayOfStructs[i];
            }
            cout << "Czy chcesz kontynuować program? (1 - tak, 0 - nie): ";
            cin >> actionProgram;
        } while (actionProgram);
    }else{
        tests();
        system("clear");
        cout << "Badania zostały przeprowadzone\n";
    }
}
