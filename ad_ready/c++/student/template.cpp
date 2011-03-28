




#include <iostream>
#include <string>

using namespace std;

class Person 
{
public:

    string name;
    string tel;
    int age;
    
    Person()
    {}

    Person(string name, string tel, int age)
    {
        this->name = name ;
        this->tel = tel;
        this->age = age;
    }

    void print()
    {
        cout << name << "\t" << tel << "\t" << age << "\t";
        cout << endl;
    }


};
template <class T>
class node 
{
public:
    node<T> * next;
    T data; 

};

template <class T>
class list 
{
    node<T> *head; 
public:
    list()
    {
        head = NULL;
    }

    ~list()
    {}

    node<T>* inserthead(T q)
    {
        node<T> *p = new node<T>;           
        p->next = head;
        head = p;
        p->data = q;
    }
    void print()
    {
        node<T>* p = head;
        while(p)
        {
            p->data->print();
            p = p->next;
        }
    
    }
};



int main()
{
   list<Person*> studentlist;

    Person *p;

   p = new Person("name1","158",15) ;
   studentlist.inserthead(p);
   
   p = new Person("name2","136",20) ;
   studentlist.inserthead(p);

   p = new Person("name3","137",15) ;
   studentlist.inserthead(p);


   studentlist.print();
}









