// animal.h
#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>

class Animal 
{
  public:
    Animal(int _id,std::string _name, std::string _type);
    

    virtual void  talk() const=0;

    
    //setters and getters
    void           setHungerRate(int a){hunger_rate = a;}
    int            getHungerRate(){return hunger_rate;}
    void           setThirstLevel(int a ){thirst_level = a;}
    int            getThirstLevel(){return thirst_level;}
  private:
    std::string    name; 
    std::string    type;
    int            id;
    int            hunger_rate=0;
    int            thirst_level=0;
};

#endif
