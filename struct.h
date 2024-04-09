#pragma once
#include <iostream>
#include <string>
class Struct{
    public:
        virtual void addElement(int item, int index);
        virtual void delElement(int index);
        virtual int findElement(int item);
        virtual void print();;
        virtual void info();
        virtual int getSize();
};
