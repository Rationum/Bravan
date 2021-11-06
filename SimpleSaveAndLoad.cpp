#include "SimpleSaveAndLoad.h"
#include <iostream>
#include <fstream>

// Constructor implemented
SimpleSaveAndLoad::SimpleSaveAndLoad()
{
};

// Getters implemented
std::string SimpleSaveAndLoad::get_SLLabel() const { return _SaveLoadLabel; }
int SimpleSaveAndLoad::get_SLID() const { return _SaveLoadID; }
int SimpleSaveAndLoad::get_SLRate() const { return _SaveLoadRate; }

// Setters implemented
void SimpleSaveAndLoad::set_SLLabel(std::string para) { _SaveLoadLabel = para; }
void SimpleSaveAndLoad::set_SLID(int para) { _SaveLoadID = para; }
void SimpleSaveAndLoad::set_SLRate(int para) { _SaveLoadRate = para; }

// Save implemented
bool SimpleSaveAndLoad::saveRecord(SimpleSaveAndLoad newMenu)
{
    std::ofstream out;
    out.open("Menu.dat", std::ios::app);
    out << newMenu.get_SLLabel() << ' '
        << newMenu.get_SLID() << ' '
        << newMenu.get_SLRate() << std::endl;
    out.close();

    return true;
}

// Load
std::istream& operator >> (std::istream& is, SimpleSaveAndLoad& s)
{
    is >> s._SaveLoadLabel >> s._SaveLoadID >> s._SaveLoadRate;
    return is;
}

// Load p2
//std::ostream& operator << (std::ostream& os, const SimpleSaveAndLoad& s)
//{
//    os << s.get_SLLabel() << ' '
//        << s.get_SLID() << ' '
//        << s.get_SLRate();
//    return os;
//}