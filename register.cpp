#include "register.hpp"
#include "aircraft.hpp"
#include "boat.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

Register::~Register() {
    for (auto vehicle : vehicles_) {
        std::cout << "Deleting: " << vehicle->GetRegisterNumber() << std::endl;
        delete(vehicle);
    }
}

void Register::Add(Vehicle* v) {
    vehicles_.push_back(v);
}

void Register::Save(const std::string& filename) const {
    std::ofstream ofs(filename);
    for (auto vehicle : vehicles_) {
        vehicle->Write(ofs);
    }
}

bool ReadLine(std::istream& stream){
    Vehicle* vehicle {
         Aircraft::Read(stream) 
         };
    if (vehicle == NULL){ 
        vehicle = Boat::Read(stream);
    }
    if (vehicle) {
        Add(vehicle);
        return true;
    }
    std::string line;
    std::getline(stream, line);
    return false;
    }

int Load(const std::string& filename){
    std::ifstream f2(filename);
    int c = 0;
    if (!f2.is_open()){
        return -1;
    }
    else{
        while (f2.good()){
            if(ReadLine(f2)){
                c++;
            }
        }
    }
    f2.close();
    return c;
 
}

void Register::Print() {
    for (auto vc : vehicles_) {
        vc->Print();
    }
}

size_t Register::Size() const {
    return vehicles_.size();
}