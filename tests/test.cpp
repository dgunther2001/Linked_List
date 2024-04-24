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



    friend ostream& operator << (ostream& os, const students& s)
    {
        os << s.age << " " << s.name;
        return os;
    }

};

int main() {
    //std::cout << "Hello linked list!!!\n";


    Linked_List<students> myList;

    students student1("Daniel", 23);
    students student2("Hannah", 22);

    myList.addNode(student1);
    myList.addNode(student2);

    myList.printList();

    std::cout << "\n";

    Linked_List<int> myList2;

    myList2.addNode(76);
    myList2.addNode(43);
    myList2.addNode(53);

    myList2.printList();


    return 0;
}