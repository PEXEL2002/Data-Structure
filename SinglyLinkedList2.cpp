#include <iostream>
#include <string>
#include <fstream>
#include "SinglyLinkedList2.h"

SinglyLinkedList2::SinglyLinkedList2() {
    _size = 0;
    _head = nullptr;
    _tail = nullptr;
}

SinglyLinkedList2::SinglyLinkedList2(std::string file) {
    _size = 0;
    _head = nullptr;
    _tail = nullptr;
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

SinglyLinkedList2::~SinglyLinkedList2() {
    Node* temp = _head;
    Node* next;
    while(temp!=nullptr) {
        next = temp->next;
        delete temp;
        temp = next;
    }
}

SinglyLinkedList2::Node* SinglyLinkedList2::createNode(int item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = nullptr;
    return newNode;
}

void SinglyLinkedList2::addElement(int item, int index) {
    if (index <= _size || index < 0) {
        Node* newNode = createNode(item);
        if (_size == 0) {
            _head = newNode;
            _tail = newNode;
        } else if (index == 0) {
            newNode->next = _head;
            _head = newNode;
        } else if(index == _size){
            _tail->next = newNode;
            _tail = newNode;
        }else {
            Node* temp = _head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        _size = _size + 1;
    } else {
        std::cout << "Index poza zakresem" << std::endl;
    }
}

void SinglyLinkedList2::delElement(int index) {
    if(index == _size){
        delElement(index-1);
    } else{
        if (index <= _size && _size > 0) {
            if (index == _size || index == 0) {
                Node* temp = _head;
                if (index == 0) {
                    _head = _head->next;
                    if (_size == 1)
                        _tail = nullptr;
                } else {
                    for (int i = 0; i < _size - 1; i++) {
                        temp = temp->next;
                    }
                    delete _tail;
                    _tail = temp;
                    _tail->next = nullptr;
                }
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
        } else {
            std::cout << "Index poza zakresem" << std::endl;
        }
    }
}

int SinglyLinkedList2::findElement(int item) {
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
void SinglyLinkedList2::print() {
    Node* temp = _head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
void SinglyLinkedList2::info() {
    std::cout << "Lista jednokierunkowa Head Tail" << std::endl;
    std::cout << "Rozmiar: " << _size << std::endl;
    std::cout << "Głowa: " << &_head << std::endl;
    std::cout << "Ogon: " << &_tail << std::endl;
}
int SinglyLinkedList2::getSize() {
    return _size;
}