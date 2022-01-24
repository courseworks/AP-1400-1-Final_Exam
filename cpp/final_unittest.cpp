#include "gtest/gtest.h"
#include <limits>
#include <iostream>
#include <monkey.h>
#include <snake.h>
#include <jungle.h>
#include <vector>
#include <final.h>
#include <memory
namespace
{
    TEST(FINALTEST,basictest)
    {
       Monkey alex = Monkey(1,"alex","Monkey");
       Snake  rex  = Snake (2,"rex" ,"Snake");
       alex.setHungerRate(10);
       rex.setHungerRate(20);        
       rex.talk();
       alex.talk();
    }

    TEST(FINALTEST,operatortest)
    {
        Monkey alex = Monkey(1,"alex","Monkey");
        Snake  rex  = Snake (2,"rex" ,"Snake");
        alex.setHungerRate(10);
        rex.setHungerRate(20);
        alex.setThirstLevel(9);
        rex.setThirstLevel(1);   
        rex++;
        ++rex;
        ++alex++;
        std::cout << rex << std::endl;
        std::cout << alex << std::endl;
        EXPECT_EQ(rex.getHungerRate(),21);
        EXPECT_EQ(rex.getThirstLevel(),2);
        EXPECT_EQ(alex.getHungerRate(),11);
        EXPECT_EQ(alex.getThirstLevel(),10);
        
    }

    TEST(FINALTEST,findpath_without_snake)
    {
        Jungle::Tree *tree0 = new Jungle::Tree(0,nullptr);
        Jungle::Tree *tree1 = new Jungle::Tree(1,nullptr);
        Jungle::Tree *tree2 = new Jungle::Tree(2,nullptr);
        Jungle::Tree *tree3 = new Jungle::Tree(3,nullptr,true);//This is a banana Tree
        
        std::vector<Rope> ropes = {
        {tree0,tree2},{tree2,tree0},{tree0,tree1},
        {tree2,tree1},{tree1,tree3},{tree0,tree3}
        };
        
        int number_of_trees  = 4;

        Jungle amazon(ropes, number_of_trees);
        
        FindPath(&amazon,tree2,tree3);

    }

    TEST(FINALTEST,findpath_snake)
    {
        Jungle::Tree *tree0 = new Jungle::Tree(0,new Snake(1,"rex","Snake"));
        Jungle::Tree *tree1 = new Jungle::Tree(1,nullptr);
        Jungle::Tree *tree2 = new Jungle::Tree(2,nullptr);
        Jungle::Tree *tree3 = new Jungle::Tree(3,nullptr,true);
        
        std::vector<Rope> ropes = {
        {tree0,tree2},{tree2,tree0},{tree0,tree1},
        {tree2,tree1},{tree1,tree3},{tree0,tree3}
        };
        
        int number_of_trees  = 4;

        Jungle amazon(ropes, number_of_trees);
        
        FindPath(&amazon,tree2,tree3);

    }

    TEST(FINALTEST,stl_sort_one_parameter) 
    {
        Monkey *alex        = new Monkey(1,"alex","Monkey");
        Snake  *rex         = new Snake (2,"rex" ,"Snake");
        Monkey *simiiformes = new Monkey(3,"simiiformes","Monkey");
        Monkey *catarrhini  = new Monkey(4,"catarrhini ","Monkey");
        Monkey *bonnet      = new Monkey(5,"bonnet ","Monkey");
        Snake  *python      = new Snake(6,"python","Snake");

        std::vector<Animal*> animals={alex,rex,simiiformes,catarrhini,bonnet,python};

        
        alex->setHungerRate(15);       
        rex->setHungerRate(30);        
        simiiformes->setHungerRate(5);
        catarrhini->setHungerRate(40); 
        bonnet->setHungerRate(20);     
        python->setHungerRate(10);

        animals = SortAnimal(animals);
        EXPECT_EQ(animals.at(2)->getHungerRate(),20);
        
    }

    TEST(FINALTEST,stl_advanced_sort)
    {
        Monkey *alex        = new Monkey(1,"alex","Monkey");
        Snake  *rex         = new Snake (2,"rex" ,"Snake");
        Monkey *simiiformes = new Monkey(3,"simiiformes","Monkey");
        Monkey *catarrhini  = new Monkey(4,"catarrhini ","Monkey");
        Monkey *bonnet      = new Monkey(5,"bonnet ","Monkey");
        Snake  *python      = new Snake(6,"python","Snake");

        std::vector<Animal*> animals={alex,rex,simiiformes,catarrhini,bonnet,python};

        
        alex->setHungerRate(5);       
        rex->setHungerRate(30);        
        simiiformes->setHungerRate(5);
        catarrhini->setHungerRate(40); 
        bonnet->setHungerRate(30);     
        python->setHungerRate(10);

        alex->setThirstLevel(10);       
        rex->setThirstLevel(45);        
        simiiformes->setThirstLevel(25);
        catarrhini->setThirstLevel(40); 
        bonnet->setThirstLevel(1);     
        python->setThirstLevel(2);

        animals = SortAnimal(animals);

        EXPECT_EQ(animals.at(2)->getThirstLevel(),45);
    }

    TEST(FINALTEST,move_semantic)
    {
        Monkey alex = Monkey(1,"alex","Monkey");
        
        printDetailOfAnimal(std::move(alex));
        printDetailOfAnimal(alex);
    }

}