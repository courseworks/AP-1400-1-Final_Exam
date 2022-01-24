// monkey.h
#ifndef MONKEY_H
#define MONKEY_H

#include "animal.h"
#include <string>


class Monkey : public Animal
{
public:
  Monkey(int id,std::string name, std::string type);
  virtual void talk() const;
};

#endif
