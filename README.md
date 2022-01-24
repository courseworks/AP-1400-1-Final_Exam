<div style="text-align: center;">
<h1>
In The Name Of ALLAH
</h1>
<h2>
Advanced Programming - Final Exam
</h2>
<h2>
Dr.Amir Jahanshahi
</h2>
<h3>
4 Bahman  - 7:00 
</div>

# Introduction
Hi all 🙋‍♂️

Exam has two parts:
- ## CPP
- ## Python

Let's go to CPP part then Python. The Considered time for the CPP part is 2:00.(7-9 AM)

# CPP part
## Animal--Monkey,Snake class
At first implement Animal like below : 
```c++
class Animal 
{
  public:
    Animal(int _id,std::string _name, std::string _type);
    
    virtual void  talk();
    
    
  private:
    std::string    name; 
    std::string    type;
    int            id;
    int            hunger_rate=0;
    int            thirst_level=0;
};
```
```Monkey``` and ```Snake``` class are inherited from Animal class and both of them must have ```talk``` function and this function must print the voice of monkey and snake.

- Monkey Voice : ```"Eep! Eep!"```
- Snake Voice  : ```"Sssss! Ssss!"```

Each animal has hunger_rate and thirst_level. These parameters must be initialized at zero at first.

Okay if you write these classes successfully you can pass through the first test.

At the second test, you must overload some operators for each animal according to the below table.

<table align="center">
  <tr>
    <td align="center"><b>Operator</b></td>
    <td align="center"><b>Function</b></td>    
  </tr>
    <tr>
        <td align="center" >++object</td>
        <td align="center">add 1 to hunger_rate of animal</td>
    </tr>
    <tr>
        <td align="center">object++</td>
        <td align="center">add 1 to thirst_level of animal</td>
    </tr>
    <tr>
        <td align="center"> << </td>
        <td align="center">Print animal thirst level and hunger_rate with its name</td>
    </tr>
</table>

## Jungle class
In this part, implement the ```Jungle``` class that has a ```Tree``` class inside it(nested class). Jungle class is something like below:
```c++
class Jungle
{
private:
    int number_of_trees;    
    std::vector<Rope> ropes;  
public:
    class Tree{
        public:
            int id; 
            Animal * animal = nullptr;
            bool bananaTree = false;
    };
    
    Jungle(std::vector<Rope>,int);
 
    
};
```
As you can see in test 3 at first, write a proper constructor for tree class.

Then we have a ```Rope``` structure that connects each tree.
```c++
struct Rope {
    Jungle::Tree* srcTree;
    Jungle::Tree* destTree;
};
```
```Jungle``` constructor gets these connections and the number of trees.

<img width = 200 src="./stuff/monkey_playing.gif">

A monkey want to use these ropes to find bananaTree with ```FindPath``` function help him to find the best and the nearest path to bananaTree. ```FindPath``` function get jungle and source tree (Monkey Home) and destination tree (Banana Tree).

```FindPath``` output must print id of tree alternatively. for example: 

```
The best path : 2 -> 0 -> 3
```

Congratulation you passed the 3 tests. The story of the fourth test is that sometimes there is a dangerous snake on a tree so it's not a good tree for the path so this test has a tree with a snake.

# Sort
The fifth test and sixth test are the same. In both of them, you must sort the animals' list in descending order.
In the sixth test two animals' hunger_rate are the same so in this situation sort these animals by thirst level in ascending order.

<b>NOTE</b> In this part, you have no permission to use for or while loop.  

# Move semantics
The seventh test is simple, implementing  ```printDetailOfAnimal``` to print detail of an animal
according to the following pattern:

```
id name type hunger_rate thirst_level
```
```printDetailOfAnimal``` must have one declaration.
