#include <iostream>

using namespace std;



#include "IntList.h"

int main() {

   int testNum;
   
   cout << "Enter test number: ";
   cin >> testNum;
   cout << endl;
   
   if (testNum == 1) {
      IntList test1;
      test1.push_front(-3);
      test1.push_front(1);
      test1.push_front(5);
      test1.push_front(8);
      test1.push_front(2);
      test1.push_front(4);
      test1.push_front(0);
      test1.push_front(9);
      cout << "Key is 8" << endl;
      cout << "Before: " << test1 << endl;
      test1.distanceFrom(8);
      cout << "After : " << test1 << endl;    
   }
   
   // Test exists function
   if (testNum == 2) {
      IntList test2;
      test2.push_front(-3);
      test2.push_front(8);
      test2.push_front(10);
      test2.push_front(-42);
      test2.push_front(3);
      test2.push_front(58);
      cout << "Key is -3" << endl;
      cout << "Before: " << test2 << endl;
      test2.distanceFrom(-3);
      cout << "After : " << test2 << endl;  
   }
	
   if (testNum == 3) {
      IntList test3;
      test3.push_front(-3);
      test3.push_front(8);
      test3.push_front(10);
      test3.push_front(-42);
      test3.push_front(3);
      test3.push_front(58);
      cout << "Key is 58" << endl;
      cout << "Before: " << test3 << endl;
      test3.distanceFrom(58);
      cout << "After : " << test3 << endl;  
   }
   
   return 0;
}