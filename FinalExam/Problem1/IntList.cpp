#include "IntList.h"

void IntList::removeOdds() {
   
   if (head != nullptr)
   {
      IntNode* temp;
      if (head->next == nullptr)
      {
         if ((head->data) % 2 != 0)
         {
            temp = head;
            head = nullptr;
            delete temp;
         }
      }
      else
      {
         
         IntNode* first = head;
      	
         while ((head->data) % 2 != 0)
      	{
      		head = head->next;
         	temp = first;
         	first = first->next;
         	delete temp;
         }
      	
      	first = first->next;
      	IntNode* second = first->next;
      	IntNode* holder = head;
      	
      	
      	while (first != nullptr)
      	{
      		if ((first->data) % 2 != 0)
      		{
      			holder->next = first->next;
      			temp = first;
      			first = first->next;
      			delete temp;			
      		}
      		else 
      		{
      			first = second;
      			holder = holder->next;
      		}
      		if (second != nullptr)
      		{
      			second = first->next;
      		}
      		else 
      		{
      			second = nullptr;
      		}
   	   }
      }  
   }
   
}