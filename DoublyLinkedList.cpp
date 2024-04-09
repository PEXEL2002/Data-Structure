#include "DoublyLinkedList.h"
#include <iostream>
#include <string>
#include <fstream>

DoublyLinkedList::DoublyLinkedList(){
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}

DoublyLinkedList::DoublyLinkedList(std::string file){
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
    std::ifstream fileStream(file);
    if (fileStream.is_open()) {
        int number;
        int size = 0;
        while (fileStream >> number) {
            addElement(number, size);
            size++;
        }
        addElement(number, size);
        size++;
        _size = size;
    } else {
        std::cout << "Nie mozna otworzyc pliku" << std::endl;
    }
}

DoublyLinkedList::~DoublyLinkedList() {
    Node* temp = _head;
    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
}

DoublyLinkedList::Node* DoublyLinkedList::createNode(int item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void DoublyLinkedList::addElement(int item, int index) {
    if (index < 0 || index > _size) {
        std::cout << "Nieprawidlowy indeks" << std::endl;
        return;
    }

    Node* newNode = createNode(item);

    if (_head == nullptr && _size == 0) { // Lista jest pusta
        _head = _tail = newNode;
    } else if (index == 0) { // Dodanie na początku listy
        newNode->next = _head;
        _head->prev = newNode;
        _head = newNode;
    } else if (index == _size) { // Dodanie na końcu listy
        newNode->prev = _tail;
        _tail = newNode;
        _tail->prev->next = _tail;
        _tail->next = nullptr;
    } else { // Dodanie w środku listy
        Node* temp = _head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    _size++;
}

void DoublyLinkedList::delElement(int index) {
    if (index < 0 || index > _size) {
        std::cout << "Nieprawidlowy indeks" << std::endl;
        return;
    }

    Node* temp;

    if (index == 0) { // Usunięcie pierwszego elementu
        temp = _head;
        _head = _head->next;
        if (_head != nullptr) {
            _head->prev = nullptr;
        } else {
            _tail = nullptr; // Lista jest teraz pusta
        }
    } else if (index == _size) { // Usunięcie ostatniego elementu
        temp = _tail;
        _tail = _tail->prev;
        _tail->next = nullptr;
    } else { // Usunięcie elementu w środku listy
        temp = _head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
    _size--;
}

int DoublyLinkedList::findElement(int item) {
    Node* temp = _head;
    for (int i = 0; i < _size; i++) {
        if (temp->data == item) {
            return i;
        }
        temp = temp->next;
    }
    return -1;
}
void DoublyLinkedList::print() {
    Node* temp = _head;
    while (temp->next != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::info() {
    std::cout << "Lista dwukierunkowa" << std::endl;
    std::cout << "Rozmiar: " << _size << std::endl;
    std::cout << "Głowa: " << _head << std::endl;
    std::cout << "Ogon:  " << _tail << std::endl;
}

int DoublyLinkedList::getSize() {
    return _size;
}
