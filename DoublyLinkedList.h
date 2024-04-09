#pragma once
#include "struct.h"
#include <iostream>
#include <string>

class DoublyLinkedList: public Struct{
    private:
        int _size;
        struct Node{
            int data;
            Node* next;
            Node* prev;
        };
        Node* _head;
        Node* _tail;
    public:
/**
 * @brief Konstruktor DoublyLinkedList
*/
        DoublyLinkedList();
/**
 * @brief Konstruktor DoublyLinkedList
 * @param file - plik z którego pobieramy dane
*/
        DoublyLinkedList(std::string file);
/**
 * @brief Destruktor DoublyLinkedList
*/
        ~DoublyLinkedList();
/**
 * @brief Tworzenie nowego elementu
 * @param item - element
*/
        Node* createNode(int item);
/**
 * @brief Dodanie elementu na dane miejsce
 * @param item - element do dodania
 * @param index - miejsce dodania
*/
        void addElement(int item, int index);
/**
 * @brief Dodanie elementu na dane miejsce
 * @param item - element do dodania
 * @param index - miejsce dodania
*/
        void delElement(int index);
/**
 * @brief Znalezienie elementu w liście
 * @param item - element do znalezienia
 * @return index elementu, -1 gdy nie znaleziono
*/
        int findElement(int item);
/**
 * @brief Wypisanie listy
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