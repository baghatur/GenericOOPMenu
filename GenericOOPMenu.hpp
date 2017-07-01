#ifndef GENERICOOPMENU
#define GENERICOOPMENU

#include <iostream>
#include <vector>
using namespace std;

class Component
{
public:
  Component(string s): label(s) {}
  
  virtual void traverse() = 0;
  virtual Component * EnterNode()   = 0;
  virtual Component * ExitNode()     = 0;
  virtual Component * ExecuteNode() = 0;
  virtual void nextItem() = 0;
  virtual void prevItem() = 0;
  
  void setParentId (Component * parent) { parentId = parent; }
  Component * getId (void) { return id; }
  Component * getParentId (void) { return parentId; }
  string getLabel (void) { return label; }
  
protected:
  string label;
  Component * id = this;
  Component * parentId = 0;
};

class Leaf: public Component
{
  using Component::Component;
   
  void traverse()
  {
    cout << label << ',';
  }
  Component* EnterNode()
    {
      cout << "Enter" << label << ',';
      return this;
    }
  
  Component* ExitNode()
  {
    cout << "exit" << label << ',';
    return getParentId();
  }
  
  Component* ExecuteNode()
  {
    cout << "Execute" << label << ',';
    return this;
  }
  
  void nextItem(){
  }
  
  void prevItem(){
  }
  
  
};

class Composite: public Component
{
  using Component::Component;
  vector < Component * > children;

public:
  void add(Component *ele)
  {
    children.push_back(ele);
    ele->setParentId(this);
  }
  void traverse()
  {
    cout << label << ':';
    for (int i = 0; i < children.size(); i++){
      cout << endl << ">";
      children[i]->getLabel();
    }
    cout << "?" << endl;
  }

  void populateMenu()
  {
    cout << label << ':';
        for (int i = 0; i < children.size(); i++){
	  cout << endl;
        if (i == selectedItem) cout << ">";
        cout << children[i]->getLabel();
        }
        cout << endl << "---------------" << endl;
  }
  
  Component* EnterNode()
  {
    return children[selectedItem]->getId();
  }
  
  Component* ExitNode()
  {
    populateMenu();
    return getParentId();
  }
  
  Component* ExecuteNode()
  {
    populateMenu();
    return this;
  }
  
  
  void nextItem(){
    selectedItem++;
    populateMenu();
  }
  
  void prevItem(){
    selectedItem--;
    populateMenu();
  }
  
private:
  int selectedItem = 0;
  
};

#endif /*GENERICOOPMENU*/
