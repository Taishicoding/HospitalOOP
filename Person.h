#ifndef PERSON_H
#define PERSON_H
#include <string>
class Person {
    protected:
        std::string name;
        int age;
        std::string contactNo;
    public:
        // Constructors
        Person();
        Person(const std::string& name, int age, const std::string& contactNo);
        // Destructor
        virtual ~Person();
        // Calling Methods
        std::string getName() const;
        int getAge() const;
        std::string getInfo() const;
        // Changer
        void setName(const std::string& name);
        void setAge(int age);
        void setInfo(const std::string& contactNo);
        //Display Info
        virtual void printInfo() const;
};
#endif