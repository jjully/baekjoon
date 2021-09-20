#include<iostream>
#include <string>

#define NAME_SIZE 50

class Person {
    int id;
    char name[NAME_SIZE];

    public:
    virtual void aboutMe() {
        std::cout << "I am a person." << std::endl;
    }
    virtual bool addCourse(std::string s) = 0;

    virtual ~Person() {
        std::cout <<"Delete a person." << std::endl;
    }
};

class Student: public Person {
    public:
    void aboutMe() {
        std::cout << "I am a student." << std::endl;
    }
    bool addCourse(std::string s) { 
        std::cout << "Adder course" << s <<"to student." << std::endl;
        return true;
    }
    virtual ~Student() {
        std::cout <<"Delete a student." << std::endl;
        //delete this;
    }

};



int main() {
    Person *p = new Student;
    p->aboutMe();
    p->addCourse("Math");
    delete p;
}

