#include "GenericOOPMenu.hpp"

int main()
{
  Component * CurrItem = 0;
  Composite  menuRoot("Main Menu");
  CurrItem = menuRoot.getId();
  menuRoot.add(new Leaf("Start Game"));
  menuRoot.add(new Leaf("Start Game"));
  Composite menuGsm("GSM");
  Leaf enableGsm("A");
  Leaf gameMasterTelNum("B");
  Leaf sendTestMessage("C");
  menuRoot.add(&menuGsm);
  menuGsm.add(&enableGsm);
  menuGsm.add(&gameMasterTelNum);
  menuGsm.add(&sendTestMessage);
  Leaf vibrationSwitch("VSW");
  menuRoot.add(new Leaf("Root"));
  menuRoot.add(&vibrationSwitch);

  CurrItem->ExecuteNode();
  
  char tmp;
  
  while (tmp != 'e'){
    cout << ">>";
    cin >> tmp;
      
    switch (tmp){
    case 'w':
    case 'W':
      CurrItem->prevItem();	
      break;
      
    case 's':
    case 'S':
      CurrItem->nextItem();	
      break;
      
    case 'd':
    case 'D':
      CurrItem->EnterNode();	
      break;
      
    case 'a':
    case 'A':
	CurrItem->ExitNode();	
	break;
    
    case 'x':
    case 'X':
      CurrItem->ExecuteNode();	
      break;
      
    default:
      
      break;
    }
  }
  
}
