#include "aircraft.hpp"
#include <vector>
#include <sstream>
//TODO: implement Aircraft's members
Aircraft::Aircraft(std::string register_number, std::string owner, std::string model, double wingspan, unsigned int cruise_speed): 
Vehicle(register_number, owner), model_(model), wingspan_(wingspan), cruise_speed_(cruise_speed) { }

void Aircraft::Write(std::ostream& stream){
    stream <<"A;" <<  GetRegisterNumber() <<";"<< GetOwner() << ";" << model_ << ";" << wingspan_ << ";" << cruise_speed_ << "\n";
}
void Aircraft::Print(){
    std::cout <<"A;" <<  GetRegisterNumber() <<";"<< GetOwner() << ";" << model_ << ";" << wingspan_ << ";" << cruise_speed_<< std::endl;
}
Aircraft* Aircraft::Read(std::istream& stream){
   std::string j;
   std::string register_number;
   std::string owner;
   std::string model;
   std::string wingspan;
   std::string cruise_speed;
   std::getline(stream, j, ';');
   if(j != "A"){
    return nullptr;
   }
   else{
    std::getline(stream, register_number, ';');
    std::getline(stream, owner, ';');
    std::getline(stream, model, ';');
    std::getline(stream, wingspan, ';');
    std::getline(stream, cruise_speed, '\n');
    return new Aircraft(register_number, owner, model, std::stod(wingspan), std::stoi(cruise_speed));
 
   }
   return 0;
}


