#include "ArrayList.h"
#include <iostream>
#include <string>
#include <fstream>

ArrayList::ArrayList(){
    _size = 2;
    _capacity = 0;
    _array = new int[_size];
}
ArrayList::ArrayList(std::string file){
    _size = 2;
    _capacity = 0;
    _array = new int[_size];
    std::ifstream fileStream;
    fileStream.open(file);
    if(fileStream.is_open()){
        int number;
        while (fileStream >> number) {
            if(_capacity+1 >= _size){
                extendArray();
                _array[_capacity++] = number;
            }else{
                _array[_capacity++] = number;
            }
        }
    }else{
        std::cout << "Nie mozna otworzyc pliku" << std::endl;
    }
    fileStream.close();
}
ArrayList::~ArrayList(){
    delete[] _array;
}
void ArrayList::addElement(int item, int index){
    if(index < _size){
        if(_capacity+1 >= _size){
            extendArray();
        }
        if(index == _capacity+1){
            _array[index] = item;
            _capacity ++;
        }else{
            for(int i=_capacity;i>=index;i--){
                _array[i+1] = _array[i];
            }
                _array[index] = item;
                _capacity ++;
        }
    }else{
        std::cout << "Index poza zakresem, Index pownien być z zakresu od 0 do "<< _capacity << std::endl;
    }
}
void ArrayList::delElement(int index) {
    if (index < _capacity) {
        for (int i = index; i < _size - 1; i++) {
            _array[i] = _array[i + 1];
        }
        _capacity--;
    } else {
        if (index == _capacity) {
            _capacity--;
        } else {
            std::cout << "Index poza zakresem" << std::endl;
            return;
        }
    }

    if ((_capacity*2)+2 == _size) {
        _size = _size / 2;
        int* tempArray = new int[_size];
        for (int i = 0; i < _capacity; i++) {
            tempArray[i] = _array[i];
        }
        delete[] _array;
        _array = tempArray;
    }
}
int ArrayList::findElement(int item){
    for(int i=0;i<_capacity;i++){
        if(_array[i] == item){
            return i;
        }
    }
    return -1;
}
void ArrayList::extendArray(){
    int* tempArray = new int[_size*2];
    for(int i=0;i<_size;i++){
        tempArray[i] = _array[i];
    }
    delete[] _array;
    _array = tempArray;
    _size = _size*2;
}
void ArrayList::print(){
    for(int i=0;i<_capacity;i++){
        std::cout << _array[i] << " ";
    }
    std::cout << std::endl;
}
void ArrayList::info(){
    std::cout << "Ilosc elementow: " << _capacity << std::endl;
    std::cout << "Maksymalny rozmiar tablicy: " << _size << std::endl;
}
int ArrayList::getSize(){
    return _capacity;
}