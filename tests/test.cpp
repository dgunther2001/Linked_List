#include "linked_list/linked_list.h"
#include <iostream>
#include <string>

using namespace std;

class students {
private: 
    std::string name;
    int age;

public:
    students(std::string n, int a) {
        name = n;
        age = a;
    }
    
    
    bool operator==(const students& otherStudent) const {
        return (name == otherStudent.name && age == otherStudent.age);
    }
    
    

    bool operator!=(const students& otherStudent) const {
        return (name != otherStudent.name || age != otherStudent.age);
    }

    
    friend ostream& operator<< (ostream& os, const students& s)
    {
        os << s.name << ": " << s.age;
        return os;
    }
    
    
    

};

int main() {
    //std::cout << "Hello linked list!!!\n";

    
    Linked_List<int> myList0;
    myList0.addNode(7);
    myList0.addNode(75);
    //myList0.printList();
    //myList0.deleteNode(75);
    //myList0.printList();

    Linked_List<char> myList2;
    myList2.addNode('c');
    myList2.addNode('h');
    myList2.printList();


    

    Linked_List<students> myList;

    students* student1 = new students("Daniel", 23);
    students* student2 = new students("Hannah", 22);
    students* student3 = new students("Zach", 23);

    myList.addNode(student1);
    myList.addNode(student2);
    //myList.addNode(student3);

    myList.printList();
    //myList.deleteNode(student1);
    //myList.printList();

    cout << myList2.getObjAtIndex(1) << "\n";
    cout << *(myList.getObjAtIndex(0)) << "\n";

    Linked_List<double> myList3;
    myList3.addNode(77.4);
    myList3.addNode(64.2);
    myList3.printList();


    //cout << "\n";

    /*
    cout << myList0.contains(7) << "\n";
    cout << myList0.contains(44) << "\n";
    cout << myList.contains(student1) << "\n";
    cout << myList.contains(student3) << "\n";
    */

    //myList.deleteNode(student1);

    //myList.deleteNode(student3);

    //myList.printList();

    //students* myStudent = myList.getObjAtIndex(0);
    //cout << *myStudent << "\n";

    //std::cout << "\n";

    //cout << myList.contains(student1) << "\n";
    //cout << myList.contains(student3) << "\n";

    

    /*
    Linked_List<int> myList2;

    myList2.addNode(76);
    myList2.addNode(43);
    myList2.addNode(53);

    myList2.printList();

    std::cout << "\n";

    cout << myList2.contains(43) << "\n";
    cout << myList2.contains(66) << "\n";

    cout << myList2.getSize() << "\n";
    */


    return 0;
}