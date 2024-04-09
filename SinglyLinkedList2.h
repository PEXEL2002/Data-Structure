#include "struct.h"
#include <iostream>
#include <string>
/**
 * @brief Klasa SinglyLinkedList2
 * @param _size - rozmiar listy
 * @param _head - wskaźnik na głowę listy
 * @param _tail - wskaźnik na ogon listy
*/
class SinglyLinkedList2: public Struct{
    private:
        int _size;
        struct Node{
            int data;
            Node* next;
        };
        Node* _head;
        Node* _tail;
    public:
/**
 * @brief Konstruktor SinglyLinkedList2
*/
        SinglyLinkedList2();
/**
 * @brief Konstruktor SinglyLinkedList2
 * @param file nazwa pliku
*/
        SinglyLinkedList2(std::string file);
/**
 * @brief Destruktor SinglyLinkedList2
*/
        ~SinglyLinkedList2();
/**
 * @brief Tworzenie nowego elementu
 * @param item element
*/
        Node* createNode(int item);
/**
 * @brief Dodanie elementu na danym miejscu
 * @param item element
 * @param index miejsce
*/
        void addElement(int item, int index);
/**
 * @brief Usunięcie elementu z listy
 * @param index miejsce
*/
        void delElement(int index);
/**
 * @brief Znalezienie elementu
 * @param item element
 * @return miejsce elementu, -1 brak elementu
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