#include "SinglyLinkedList1.h"
#include <iostream>
#include <fstream>
#include <string>

SinglyLinkedList1::SinglyLinkedList1() {
    _size = 0;
    _head = nullptr;
}

SinglyLinkedList1::SinglyLinkedList1(std::string file) {
    _size = 0;
    _head = nullptr;
    std::ifstream fileStream(file);
    if(fileStream.is_open()){
        int number;
        while(fileStream >> number) {
            addElement(number, _size);
        }
    } else {
        std::cout << "Nie mozna otworzyc pliku" << std::endl;
    }
}

SinglyLinkedList1::~SinglyLinkedList1() {
    Node* temp = _head;
    Node* next;
    while(temp != nullptr){
        next = temp->next;
        delete temp;
        temp = next;
    }
}

SinglyLinkedList1::Node* SinglyLinkedList1::createNode(int item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = nullptr;
    return newNode;
}

void SinglyLinkedList1::addElement(int item, int index) {
    if(index<0 || index >_size){
        std::cout << "Index poza zakresem" << std::endl;
        return;
    }
    Node* newNode = createNode(item);
    if(index==0){
        newNode->next = _head;
        _head = newNode;
    }else{
        Node* temp = _head;
        for(int i=0; i<index-1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    _size++;
}

void SinglyLinkedList1::delElement(int index) {
        if (index < 0 || index >= _size) {
            std::cout << "Index poza zakresem" << std::endl;
            return;
        }
        if (index == 0) {
            Node* temp = _head;
            _head = _head->next;
            delete temp;
        } else {
            Node* temp = _head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            Node* delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        }
        _size--;
}



int SinglyLinkedList1::findElement(int item) {
    Node* temp = _head;
    int index = 0;
    while (temp != nullptr) {
        if (temp->data == item) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

void SinglyLinkedList1::print() {
    Node* temp = _head;
    while (temp != nullptr) {
        temp = temp->next;
    }
    std::cout << std::endl;
}
void SinglyLinkedList1::info() {
    std::cout << "Lista jednokierunkowa Head Only" << std::endl;
    std::cout << "Rozmiar: " << _size << std::endl;
    std::cout << "Głowa: " << &_head << std::endl;
}
int SinglyLinkedList1::getSize() {
    return _size-1;
}
