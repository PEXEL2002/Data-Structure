#include "struct.h"
#pragma once
#include <iostream>
#include <string>
/**
 * @brief Klasa DynamicArrayInt
 * @param _size - rozmiar tablicy
 * @param _capacity - index ostatniego elementu
 * @param _array - tablica
*/
class ArrayList : public Struct{
    private:
        int _size;
        int _capacity;
        int* _array;
    public:
/**
 * @brief Konstruktor arrayList
 * 
*/
        ArrayList();
/**
 *  @brief Konstruktor ArrayList
 *  @param file - plik z którego pobieramy dane
*/
        ArrayList(std::string file);
/**
 * @brief Destruktor ArrayList
*/
        ~ArrayList();
/**
 * @brief Funkcja dodająca element do struktury
 * @param item - element do dodania
 * @param index - index na którym dodajemy element
*/
        void addElement(int item, int index);
/**
 * @brief Funkcja usuwająca element ze struktury
 * @param index - index elementu do usunięcia
*/
        void delElement(int index);
/**
 * @brief Funkcja znajdująca element w strukturze
 * @param item - element do znalezienia
 * @return index elementu, -1 gdy nie znaleziono
*/
        int findElement(int item);
/**
 * @brief Funkcja rozszerzająca tablicę
*/
        void extendArray();
/**
 * @brief Funkcja print wyświetlająca stukture
*/
        void print();
/**
 * @brief Wypisanie informacji o tablicy
*/
        void info();
/**
 * @brief Funkcja zwracająca index ostatniego elementu
 * @return index ostatniego elementu
*/
        int getSize();
};