#include "Person.h"
#include <iostream>
//Constructor
Person::Person() : name("Greg"), age(99), contactNo("Ring 131"){}
Person::Person(const std::string& name, int age, const std::string& contactNo) : name(name), age(age), contactNo(contactNo){}
//Destructor
Person::~Person(){}
//calling
std::string Person::getName() const{
    return name;
};
int Person::getAge() const{
    return age;
};
std::string Person::getInfo() const{
    return contactNo;
};
//setting
void Person::setName(const std::string& name){
    this->name = name;
};
void Person::setAge(int age){
    this->age = age;
};
void Person::setInfo(const std::string& contactNo){
    this->contactNo = contactNo;
};
//Print
void Person::printInfo() const{
    std::cout<<"Name:"<<" "<<name<<std::endl;
    std::cout<<"Age:"<<" "<<age<<std::endl;
    std::cout<<"Contact Number:"<<" "<<contactNo<<std::endl;
};


