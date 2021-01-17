#include<bits/stdc++.h>

using namespace std;

struct Person{
  int id;
  int age;
  string name;
  vector<Person*> childs;
  vector<Person*> parents;

  Person(void){}

  Person(int id, int age, string name){
    setId(id);
    setAge(age);
    setName(name);
  }

  void setId(int id){
    this->id = id;
  }

  void setAge(int age){
    this->age = age;
  }

  void setName(string name){
    this->name = name;
  }

  void addChild(Person* child){
    childs.push_back(child);
  }

  void addParent(Person* parent){
    parents.push_back(parent);
  }

};


/**
 * grandfather
 * ├── son1
 * │   ├── grandson1
 * │   └── grandson2
 * └── son2
 *     └── grandson3
 *
 **/

int main(){
  Person grandfather(1, 90, "First Gen");

  Person son1(2, 60, "Second Gen 1");
  Person son2(3, 50, "Second Gen 2");

  Person grandson1(4, 30, "Third Gen 1");
  Person grandson2(5, 25, "Third Gen 2");
  Person grandson3(6, 10, "Third Gen 3");

  grandfather.addChild(&son1);
  grandfather.addChild(&son2);
  son1.addParent(&grandfather);
  son2.addParent(&grandfather);

  son1.addChild(&grandson1);
  son1.addChild(&grandson2);
  son2.addChild(&grandson3);

  grandson1.addParent(&son1);
  grandson2.addParent(&son1);
  grandson3.addParent(&son2);


  cout << "Retrieve grandparent name from grandson: " << grandson1.parents[0]->parents[0]->name << endl;
  cout << "Retrieve grandson name from grandparent: " << grandfather.childs[1]->childs[0]->name << endl;
  cout << "Retrieve parent name from second gen: " << son2.parents[0]->name << endl;
  cout << "Retrieve son name from second gen: " << son1.childs[1]->name << endl;
  return 0;
}



