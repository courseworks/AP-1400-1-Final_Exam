// snake.h
#ifndef SNAKE_H
#define SNAKE_H

#include "animal.h"



class Snake : public Animal
{
  public:
    Snake(int id,std::string name, std::string type);
    virtual void talk() const;
};

#endif
