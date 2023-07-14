#include "student.h"

struct Node{
 student data;
 Node* next;
Node(const student &s, Node* n = NULL) : data(s), next(n) {
 char *x;

 cout << "***Node creation with student " << endl;
 }
};


class List {
 Node *start;
 unsigned int size_; //list size
public:
        List() : start(NULL), size_(0) {
 cout << "***List creation" << endl;
 }

 unsigned int size() const { return size_; }

 Node *get_start(){return start;}

 bool isEmpty(){
        if(get_start()==NULL)return true;
        return false;
 }/**/


 void pushFront(const student& s) {
 start = new Node(s, start);
 size_++;
 }

 bool pop(unsigned int index) {
 if (index >= size_) return false;
 Node *t = start;
 if (index ==0) {
 start = start->next;
 delete t;
 }
 else {
 while (--index >0) t = t->next;
  Node* t2 = t->next;
 t->next = t->next->next;
 delete t2;
 }
 size_--;
 return true; }


//////////////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!//////////////////////////
student get_student(unsigned int index=0) {	//	! The function at the same time REMOVES student from the List
  if (index >= size_){ student s0("error",0,0); return s0;}	// error gives us the warning that we are trying to get a student from an empty list

 Node *t=start;
 if (index ==0) {	// stack implementation. In the programm there is (worst case) only one student in a list . So we can get him from the first position
  student s1=start->data;
  start = start->next;
  delete t;

  return s1;
  }
 else { 
  while (--index > 0){ t = t->next;}// queue implementation (if index = size) 
  Node* t2 = t->next;
  student s2=t2->data;
  t->next = t->next->next;
  delete t2;
  return s2;    //student(t->data);
  }/**/
 }
//////////////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!//////////////////////////

 void print()
 {
 Node* t = start;
 while (t != NULL) {
 t->data.print();
 t = t->next;
 } }

 ~List() {
 Node* t1 = start;
 while (t1 != NULL) {
 Node* t2 = t1;
 t1 = t1->next;
 delete t2;
 }
 cout << "***List destruction" << endl;
 }

};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

























































