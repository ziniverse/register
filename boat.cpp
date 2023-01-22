#include "boat.hpp"
#include <vector>
#include <sstream>
//TODO: implement Boat's members
Boat::Boat(std::string register_number, std::string owner, std::string name, double draft, double power):
 Vehicle(register_number, owner), name_(name), draft_(draft), power_(power){ }
void Boat::Write(std::ostream &stream){
    stream << "B;" << GetRegisterNumber() << ";" << GetOwner() << ";" << name_ << ";" << draft_ << ";" << power_ << "\n";
}
void Boat::Print(){
    std::cout << "B;" << GetRegisterNumber() << ";" << GetOwner() << ";" << name_ << ";" << draft_ << ";" << power_ << std::endl;
}
Boat* Boat::Read(std::istream &stream){
   std::string j;
   std::string register_number;
   std::string owner;
   std::string name;
   std::string draft;
   std::string power;
   std::getline(stream, j, ';');
   if(j != "B"){
    return nullptr;
   }
   else{
    std::getline(stream, register_number, ';');
    std::getline(stream, owner, ';');
    std::getline(stream, name, ';');
    std::getline(stream, draft, ';');
    std::getline(stream, power, '\n');
    return new Boat(register_number, owner, name, std::stod(draft), std::stoi(power));
 
   }
   return 0;
}