#include "ui.h"
#include "struct.h"
#include "ArrayList.h"
#include "SinglyLinkedList1.h"
#include "SinglyLinkedList2.h"
#include "DoublyLinkedList.h"
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <climits>
#include <cmath>

void generateIntToFile(std::string filename, int numElements, int minGenerated, int maxGenerated) {
    system("clear");
    std::ofstream file(filename);
    if (file.is_open()) {
        srand(time(nullptr));
        for (int i = 0; i < numElements; i++) {
            int randomInt = minGenerated + rand() % (maxGenerated - minGenerated + 1);
            file << randomInt << std::endl;
        }
        file.close();
    } else {
        std::cout << "Błąd pliku." << std::endl;
    }
}
int generateInt(int minGenerated, int maxGenerated) {
    return minGenerated + rand() % (maxGenerated - minGenerated + 1);
}
void generateTable(std::string* nameStruct,long long int* time) {
    int maxNameLength = 0;
    for (int i = 0; i < 4; ++i) {
        if (nameStruct[i].length() > maxNameLength) {
            maxNameLength = nameStruct[i].length();
        }
    }
    std::cout << "Nazwa";
    for (int i = 0; i < maxNameLength - 4; ++i) {
        std::cout << " ";
    }
    std::cout << " | Czas (nanosekundy)" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << nameStruct[i];
        for (int j = 0; j < maxNameLength - nameStruct[i].length() + 1; ++j){
            std::cout << " ";
        }
        std::cout << " | " << time[i] << std::endl;
    }
}
void uiAddElement(Struct** s, std::string* nameStruct) {
    long long int time[4];
    system("clear");
    int item, index;
    std::cout << "Podaj element: ";
    std::cin >> item;
    do{
        std::cout << "Podaj indeks: ";
        std::cin >> index;
    } while(index < 0 || index >= s[0]->getSize());
    std::cout << "Dodawanie na miejsce " << index << std::endl;
    for(int i = 0; i < 4; i++){
        auto start = std::chrono::high_resolution_clock::now();
        s[i]->addElement(item, index);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        time[i] = duration.count();
    }
    std::cout<< "Czas operacji addElement" << std::endl;
    generateTable(nameStruct, time);
    std::cout << std::endl;  
}
void uiAddElementFront(Struct** s, std::string* nameStruct){
    long long int time[4];
    system("clear");
    int item;
    std::cout << "Podaj element: ";
    std::cin >> item;
    std::cout << "Dodawanie na początku" << std::endl;
    for(int i = 0; i < 4; i++){
        auto start = std::chrono::high_resolution_clock::now();
        s[i]->addElement(item, 0);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        time[i] = duration.count();
    }
    std::cout << "Czas operacji addElementFront" << std::endl;
    generateTable(nameStruct, time);
    std::cout << std::endl;
}
void uiAddElementBack(Struct** s, std::string* nameStruct){
    long long int time[4];
    system("clear");
    int item;
    std::cout << "Podaj element: ";
    std::cin >> item;
    std::cout << "Dodawanie na końcu" << std::endl;
    for(int i = 0; i < 4; i++){
        auto start = std::chrono::high_resolution_clock::now();
        s[i]->addElement(item, s[i]->getSize());
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        time[i] = duration.count();
    }
    std::cout << "Czas operacji addElementBack" << std::endl;
    generateTable(nameStruct, time);
    std::cout << std::endl;
}
void uiDelElement(Struct** s, std::string* nameStruct) {
    system("clear");
    long long int time[4];
    int index;
    do{
        std::cout << "Podaj indeks: ";
        std::cin >> index;
    } while(index < 0 || index >= s[0]->getSize());
    std::cout << "Usuwanie" << std::endl;
    for(int i = 0; i < 4; i++){
        auto start = std::chrono::high_resolution_clock::now();
        s[i]->delElement(index);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        time[i] = duration.count();
    }
    std::cout << "Czas operacji delElement" << std::endl;
    generateTable(nameStruct, time);
    std::cout << std::endl;
}

void uiDelElementFront(Struct** s, std::string* nameStruct) {
    system("cls");
    long long int time[4];
    std::cout << "Usuwanie z przodu" << std::endl;
    for(int i = 0; i < 4; i++){
        auto start = std::chrono::high_resolution_clock::now();
        s[i]->delElement(0);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        time[i] = duration.count();
    }
    std::cout << "Czas operacji delElementFront" << std::endl;
    generateTable(nameStruct, time);
    std::cout << std::endl;
}

void uiDelElementBack(Struct** s, std::string* nameStruct) {
    system("clear");
    long long int time[4];
    std::cout << "Usuwanie z tyłu" << std::endl;
    for(int i = 0; i < 4; i++){
        auto start = std::chrono::high_resolution_clock::now();
        s[i]->delElement(s[i]->getSize());
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        time[i] = duration.count();
    }
    std::cout << "Czas operacji delElementBack" << std::endl;
    generateTable(nameStruct, time);
    std::cout << std::endl;
}
void uiFindElement(Struct** s, std::string* nameStruct) {
    system("clear");
    long long int time[4];
    int item, index = -1;
    std::cout << "Podaj element: ";
    std::cin >> item;
    for(int i = 0; i < 4; i++){
        auto start = std::chrono::high_resolution_clock::now();
        index = s[i]->findElement(item);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        time[i] = duration.count();
    }
    std::cout << "Czas operacji findElement" << std::endl;
    generateTable(nameStruct, time);
    std::cout << std::endl;
    std::cout << "Indeks znalezionego elementu: " << index << std::endl;
    std::cout << std::endl;

}

void uiPrint(Struct** s, std::string* nameStruct) {
    system("clear");
    for(int i = 0; i < 4; i++){
        std::cout << nameStruct[i] << ":" << std::endl;
        s[i]->print();
        std::cout << std::endl;
    }
}
void uiPrintInfo(Struct** s, std::string* nameStruct) {
    system("clear");
    std::cout << "Podaj numer struktury: 0-3\n";
    std::cout << "0 - Array List\n";
    std::cout << "1 - Singly Linked List Head Only\n";
    std::cout << "2 - Singly Linked List Head Tail\n";
    std::cout << "3 - Doubly Linked List\n";
    int i;
    std::cin >> i;
    std::cout << nameStruct[i] << ":" << std::endl;
    s[i]->info();
}

void createStruct(Struct **s, int numberStruct, std::string& nameStruct, std::string& nameGen){
    switch(numberStruct){
        case 0:
            *s = new ArrayList(nameGen);
            nameStruct = "Array List";
            break;
        case 1:
            *s = new SinglyLinkedList1(nameGen);
            nameStruct = "Singly Linked List Head Only";
            break;
        case 2:
            *s = new SinglyLinkedList2(nameGen);
            nameStruct = "Singly Linked List Head Tail";
            break;
        case 3:
            *s = new DoublyLinkedList(nameGen);
            nameStruct = "Doubly Linked List";
            break;
    }
}
void tests(){
    std::string fileName = "StructTests.csv";
    std::ofstream file(fileName, std::fstream::out | std::fstream::app); // Otwieranie pliku w trybie dodawania
    if(!file.is_open()){
        std::cout << "Error: File is not open" << std::endl;
        return;
    }
    file << "Iteration; minGen-maxGen; Size ;Name struct; operation; time; index"<< std::endl;
    double sizeTab[10] = {pow(10,5), pow(2,16)-1, 0.5*pow(10,5), pow(2,15)-1, 0.25*pow(10,5), pow(2,14)-1, pow(10,4), pow(2,13)-1, 0.5*pow(10,4), pow(2,10)-1};
    int indexFind, del, add,indexAdd,  find, findIndex, indexDel;
    Struct *myStruct;
    std::string nameStruct, nameGen, nameFind = "find.txt", nameAdd = "add.txt", nameDel = "del.txt";
    int maxValue=RAND_MAX, minValue=1000, iteration = 0, amountOfResearch = 10;
        for(int sizeTabIndex = 0; sizeTabIndex < 10; sizeTabIndex++){
            int j = 2;
            //mierzenie czasu dla dodawania oraz usuwania elementu na końcu
            for(int i = 0;i<amountOfResearch;i++){
                generateIntToFile(nameAdd, sizeTab[sizeTabIndex], minValue, maxValue);
                add = generateInt(minValue, maxValue);
                for(int j=0;j<4;j++){
                    createStruct(&myStruct, j, nameStruct, nameAdd);
                    auto start3 = std::chrono::high_resolution_clock::now();
                    myStruct->addElement(add, myStruct->getSize());
                    auto end3 = std::chrono::high_resolution_clock::now();
                    auto duration3 = std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - start3);
                    file << iteration << ";" << minValue << "-" << maxValue << ";" << sizeTab[sizeTabIndex] << ";" << nameStruct << ";addElementBack; " <<duration3.count()<< ";" << -1 << std::endl;
                    iteration++;
                    auto start3_1 = std::chrono::high_resolution_clock::now();
                    myStruct->delElement(myStruct->getSize());
                    auto end3_1 = std::chrono::high_resolution_clock::now();
                    auto duration3_1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end3_1 - start3_1);
                    file << iteration << ";" << minValue << "-" << maxValue << ";" << sizeTab[sizeTabIndex] << ";" << nameStruct << ";delElementBack; " <<duration3_1.count()<< ";" << -1 << std::endl;
                    iteration++;
                    delete myStruct;
                    myStruct = nullptr;
                }
            }
            //mierzenie czasu dla szukania elementu
            generateIntToFile(nameFind, sizeTab[sizeTabIndex], minValue, maxValue);
            for(int i = 0;i<amountOfResearch;i++){ 
                find = generateInt(0, INT_MAX);
                for(int j=0;j<4;j++){
                    createStruct(&myStruct, j, nameStruct, nameFind);
                    auto start1 = std::chrono::high_resolution_clock::now();
                    findIndex = myStruct->findElement(find);
                    auto end1 = std::chrono::high_resolution_clock::now();
                    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);
                    file << iteration << ";" << minValue << "-" << maxValue << ";" << sizeTab[sizeTabIndex] << ";" << nameStruct << ";findElement; " <<duration1.count()<< ";" << findIndex << std::endl;
                    iteration++;
                    delete myStruct;
                    myStruct = nullptr;
                }
            }
            //mierzenie czasu dla dodawania oraz usuwania elementu na początku
            for(int i = 0;i<amountOfResearch;i++){
                generateIntToFile(nameAdd, sizeTab[sizeTabIndex], minValue, maxValue);
                add = generateInt(minValue, maxValue);
                for(int j=0;j<4;j++){
                    createStruct(&myStruct, j, nameStruct, nameAdd);
                    auto start2 = std::chrono::high_resolution_clock::now();
                    myStruct->addElement(add, 0);
                    auto end2 = std::chrono::high_resolution_clock::now();
                    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);
                    file << iteration << ";" << minValue << "-" << maxValue << ";" << sizeTab[sizeTabIndex] << ";" << nameStruct << ";addElementFront; " <<duration2.count()<< ";" << -1 << std::endl;
                    iteration++;
                    auto start2_1 = std::chrono::high_resolution_clock::now();
                    myStruct->delElement(0);
                    auto end2_1 = std::chrono::high_resolution_clock::now();
                    auto duration2_1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2_1 - start2_1);
                    file << iteration << ";" << minValue << "-" << maxValue << ";" << sizeTab[sizeTabIndex] << ";" << nameStruct << ";delElementFront; " <<duration2_1.count()<< ";" << -1 << std::endl;
                    iteration++;
                    delete myStruct;
                    myStruct = nullptr;
                }
            }
            //mierzenie czasu dla dodawania oraz usuwania elementu w środku
            for(int i = 0;i<amountOfResearch;i++){
                generateIntToFile(nameAdd, sizeTab[sizeTabIndex], minValue, maxValue);
                add = generateInt(minValue, maxValue);
                indexAdd = generateInt(0, sizeTab[sizeTabIndex]-1);
                indexDel = generateInt(0, sizeTab[sizeTabIndex]-1);
                for(int j=0;j<4;j++){
                    createStruct(&myStruct, j, nameStruct, nameAdd);
                    auto start4 = std::chrono::high_resolution_clock::now();
                    myStruct->addElement(add, indexAdd);
                    auto end4 = std::chrono::high_resolution_clock::now();
                    auto duration4 = std::chrono::duration_cast<std::chrono::nanoseconds>(end4 - start4);
                    file << iteration << ";" << minValue << "-" << maxValue << ";" << sizeTab[sizeTabIndex] << ";" << nameStruct << ";addElement; " <<duration4.count()<< ";" << -1 << std::endl;
                    iteration++;
                    auto start7 = std::chrono::high_resolution_clock::now();
                    myStruct->delElement(indexDel);
                    auto end7 = std::chrono::high_resolution_clock::now();
                    auto duration7 = std::chrono::duration_cast<std::chrono::nanoseconds>(end7 - start7);
                    file << iteration << ";" << minValue << "-" << maxValue << ";" << sizeTab[sizeTabIndex] << ";" << nameStruct << ";delElement; " <<duration7.count()<< ";" << -1 << std::endl;
                    iteration++;
                    delete myStruct;
                    myStruct = nullptr;
                }
            }
        }
    file.close();
}
