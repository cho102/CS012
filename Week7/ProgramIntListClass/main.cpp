#include <iostream>
using namespace std;

#include "IntList.h"

int main() {

  //tests constructor, destructor, push_front, pop_front, display

   {
      cout << "\nlist1 constructor called" << endl;
      IntList list1;
      cout << "pushfront 10" << endl;
      list1.push_front(10);
//       cout << "pushfront 20" << endl;
//       list1.push_front(20);
//       cout << "pushfront 30" << endl;
//       list1.push_front(30);
//       cout << "list1: " << list1 << endl;
//        list1.pop_front();
//        list1.pop_front();
//        list1.pop_front();
//        list1.pop_front();
//        list1.clear();
       cout << "list1: " << list1 << endl;
//         IntList emptyList;
//         IntList list2(emptyList);
       
       IntList list2 = list1;
       
      cout << "list2: " << list2 << endl;
       
       

       
   }
    
//             IntList list5;
//         cout << "pushfront 10" << endl;
//         list5.push_front(10);
//         cout << "pushfront 20" << endl;
//         list5.push_front(20);
//         cout << "pushfront 10" << endl;
//         list5.push_front(10);
//         cout << "pushfront 30" << endl;
//         list5.push_front(30);
//         cout << "list 5: " << list5 << endl;
       
//          list5 = list1;
//          cout << "list 5: " << list5 << endl;
       
    
    
    
    
//       cout << "pop" << endl;
//       list1.pop_front();
//       cout << "list1: " << list1 << endl;
//       cout << "pop" << endl;
//       list1.pop_front();
//       cout << "list1: " << list1 << endl;
//       cout << "pop" << endl;
//       list1.pop_front();
//       cout << "list1: " << list1 << endl;
//       cout << "pushfront 100" << endl;
//       list1.push_front(100);
//       cout << "pushfront 200" << endl;
//       list1.push_front(200);
//       cout << "pushfront 300" << endl;
//       list1.push_front(300);
//       cout << "pushfront 300" << endl;
//       list1.push_front(300);
//       cout << "pushfront 700" << endl;
//       list1.push_front(700);
//       cout << "pushback 400" << endl;
//       list1.push_back(400);
//       cout << "list1: " << list1 << endl;
//       cout << "selectionsort" << endl;
//       list1.selection_sort();
//       cout << "list1: " << list1 << endl;
//       cout << "insertordered 750" << endl;
//       list1.insert_ordered(750);
//       cout << "insertordered 750" << endl;
//       list1.insert_ordered(750);
//       cout << "insertordered 50" << endl;
//       list1.insert_ordered(50);
//       cout << "insertordered 150" << endl;
//       list1.insert_ordered(150);
//       cout << "list1: " << list1 << endl;
//       cout << "removedupicates" << endl;
//       list1.remove_duplicates();
//       cout << "list1: " << list1 << endl; 
       
       
//       cout << "clear" << endl;
//       list1.clear();
//       cout << "list1: " << list1 << endl;
//       cout << endl;
//       cout << "Calling list1 destructor..." << endl;
//    }
//    cout << "list1 destructor returned" << endl;
   
//    // Test destructor on empty IntList
//    {
//       IntList list2;
//       cout << "Calling list2 destructor..." << endl;
//    }
//    cout << "list2 destructor returned" << endl;
   
    
//     cout << "\nlist4 constructor called" << endl;
//     IntList list4;
//     cout << "insert 20" << endl;
//     list4.insert_ordered(20);
//     cout << "insert 10" << endl;
//     list4.insert_ordered(10);
//     cout << "insert 30" << endl;
//     list4.insert_ordered(30);
//     cout << "list4: " << list4 << endl;
//     cout << "insert 50" << endl;
//     list4.insert_ordered(50);
//     cout << "list4: " << list4 << endl;
//     cout << "insert 40" << endl;
//     list4.insert_ordered(40);
//     cout << "list4: " << list4 << endl;
//     cout << "insert 11" << endl;
//     list4.insert_ordered(11);
//     cout << "list4: " << list4 << endl;
//     cout << "insert 10" << endl;
//     list4.insert_ordered(10);
//     cout << "list4: " << list4 << endl;
//     cout << "insert 11" << endl;
//     list4.insert_ordered(11);
//     cout << "list4: " << list4 << endl;
//     cout << "insert 9" << endl;
//     list4.insert_ordered(9);
//     cout << "list4: " << list4 << endl;
//     cout << "insert 50" << endl;
//     list4.insert_ordered(50);
//     cout << "list4: " << list4 << endl;
//     cout << "insert 51" << endl;
//     list4.insert_ordered(51);
//     cout << "list4: " << list4 << endl;
    
    
    
//     cout << "list5 constructor called" << endl;
//     IntList list5;
//     cout << "pushfront 10" << endl;
//     list5.push_front(10);
//     cout << "pushfront 20" << endl;
//     list5.push_front(20);
//     cout << "pushfront 10" << endl;
//     list5.push_front(10);
//     cout << "pushfront 30" << endl;
//     list5.push_front(30);
//     cout << "list 5: " << list5 << endl;
//     cout << "remove_duplicates()" << endl;
//     list5.remove_duplicates();
//     cout << "list 5: " << list5 << endl;
//     cout << "pushfront 10" << endl;
//     list5.push_front(10);
//     cout << "list 5: " << list5 << endl;
//     cout << "remove_duplicates()" << endl;
//     list5.remove_duplicates();
//     cout << "list 5: " << list5 << endl;
//     cout << "pushfront 20" << endl;
//     list5.push_front(20);
//     cout << "list 5: " << list5 << endl;
//     cout << "remove_duplicates()" << endl;
//     list5.remove_duplicates();
//     cout << "list 5: " << list5 << endl;
//     cout << "pushfront 20" << endl;
//     list5.push_front(20);
//     cout << "list 5: " << list5 << endl;
//     cout << "remove_duplicates()" << endl;
//     list5.remove_duplicates();
//     cout << "list 5: " << list5 << endl;
//     cout << "pushfront 20" << endl;
//     list5.push_front(20);
//     cout << "pushfront 20" << endl;
//     list5.push_front(20);
//     cout << "list 5: " << list5 << endl;
//     cout << "remove_duplicates()" << endl;
//     list5.remove_duplicates();
//     cout << "list 5: " << list5 << endl;
    

}
