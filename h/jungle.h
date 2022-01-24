#pragma once
#include <vector>
#include <snake.h>


struct Rope;

class Jungle
{
private:
    int number_of_trees;    
    std::vector<Rope> ropes;  
public:
    class Tree{
        public:
            int id; // Id of trees
            Animal * animal = nullptr; // if tree has animal or not
            bool bananaTree = false;
            
    };
    
    Jungle(std::vector<Rope>,int);  // Constructor
    
 
    
};

struct Rope {
    Jungle::Tree* srcTree;
    Jungle::Tree* destTree;
};

