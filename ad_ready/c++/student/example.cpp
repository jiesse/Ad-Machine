




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
        cout << name << "" << tel << "" << age << "";
        cout << endl;
    }


};
class node 
{
public:
    node * next;
    Person* data; 

};

class list 
{
    node *head; 
public:
    list()
    {
        head = NULL;
    }

    ~list()
    {}

    node* inserthead(Person *q)
    {
        node *p = new node;           
        p->next = head;
        head = p;
        p->data = q;
    }
    void print()
    {
        node* p = head;
        while(p)
        {
            p->data->print();
            p = p->next;
        }
        //while(head) 
        //{
        // 
        //}
    
    }
};



int main()
{
   list studentlist;

   Person * p;

   p = new Person("name1","158",15) ;
   studentlist.inserthead(p);
   
   p = new Person("name2","136",20) ;
   studentlist.inserthead(p);

   p = new Person("name3","137",15) ;
   studentlist.inserthead(p);


   studentlist.print();
}









