#pragma once
#include <iostream>
#include <string>
#include "struct.h"
/**
 * @brief Klasa SinglyLinkedList1
 * @param _size - rozmiar listy
 * @param _head - wskaźnik na głowę listy
*/
class SinglyLinkedList1: public Struct{
    private:
        int _size;
        struct Node{
            int data;
            Node* next;
        };
        Node* _head;
    public:
/**
 * @brief Konstruktor SinglyLinkedList1
*/
        SinglyLinkedList1();
/**
 * @brief Konstruktor SinglyLinkedList1
 * @param file - plik z którego pobieramy dane
*/
        SinglyLinkedList1(std::string file);
/**
 * @brief Destruktor SinglyLinkedList1
*/
        ~SinglyLinkedList1();
/**
 * @brief Funkcja tworząca nowy element listy
*/
        Node* createNode(int item);
/**
 * @brief Funkcja dodająca element do listy
 * @param item - element do dodania
 * @param index - index na którym dodajemy element
*/
        void addElement(int item, int index);
/**
 * @brief Funkcja usuwająca element z listy
 * @param index - index elementu do usunięcia
*/
        void delElement(int index);
/**
 * @brief Funkcja znajdująca element w liście
 * @param item - element do znalezienia
 * @return index elementu, -1 gdy nie znaleziono
*/
        int findElement(int item);
/**
 * @brief Funkcja wyświetlająca listę
*/
        void print();
/**
 * @brief Wypisanie informacji o liście
*/
        void info();
/**
 * @brief Zwrócenie rozmiaru listy
 * @return rozmiar listy
*/
        int getSize();
};
