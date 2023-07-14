#include <iostream>
#include "List.h"


class yard{
private: int total;   // total students currently inside
	 List students;
public: yard(int i=0):total(i){cout<<"yard created !"<<endl;}
	~yard(){ cout<<"yard destroyed !"<<endl;}

	int get_total(){return total;}

	const student st_to_go()/*student to exit*/{ total--; return students.get_student(); }  // any st_to_go function at the same time make the student
												//	exit the location 
	void exit(){
		if(!students.isEmpty()){
		 total--;
                 students.pop(0);
                 cout<<st_to_go().get_name()<<" exits yard!"<<endl;
		 }
                }

	void enter(const student &s){
                total++;
                students.pushFront(s);
		cout<<"                 "<<s.get_name()<<" enters yard!"<<endl;
		} 
               
        void print(){
                cout<<"students inside yard: "<<get_total()<<endl;
                students.print();
                }
};
///////////////////////////////////////////////////////////////////////////////////////////////


class stairs{
private: int total;   // total students currently inside
         List students;
public: stairs(int i=0):total(i){cout<<" stairs created !"<<endl;}
        ~stairs(){ cout<<"stairs destroyed !"<<endl;}

        int get_total(){return total;}

	const student st_to_go()/*student to exit*/{ total--; return students.get_student();}

        void enter(const student &s){
                total++;
                students.pushFront(s);
		cout<<"			"<<s.get_name()<<" ENTERS STAIRS"<<endl;
                }

	void exit(){
                if(!students.isEmpty()){
                 total--;
                 students.pop(0);
                 cout<<"                 "<<st_to_go().get_name()<<" exits stairs"<<endl;
                 }
                }


        void print(){
                cout<<"students inside  stairs: "<<get_total()<<endl;
                students.print();
                }
};
/////////////////////////////////////////////////////////////////////////////////


class corridor{
private: /*static cortotal;*/ int total;   // total students currently inside
         List students;
public: corridor(int i=0):total(i){cout<<"corridor created !"<<endl;}

	
        ~corridor(){ cout<<"corridor destroyed !"<<endl;}

        int get_total(){return total;}

	const student st_to_go()/*student to exit*/{ total--; return students.get_student(); } 

        void enter(const student &s){
                total++;
                students.pushFront(s);
		cout<<"                 "<<s.get_name()<<" enters floor"<<endl;
		cout<<"                 "<<s.get_name()<<" enters corridor"<<endl; 
                }

	void exit(){
		if(!students.isEmpty()){
                  total--;
		  students.pop(0);
		  cout<<"                 "<<st_to_go().get_name()<<" exits corridor"<<endl;
		  }
		}
		

        void print(){
                cout<<"students inside corridor: "<<get_total()<<endl;
                students.print();
                }
};
///////////////////////////////////////////////////////////////////////////


class room{
private: /*static croom total;*/int total;
         List students;
	 teacher * classTeacher;
	 bool teach_inside;  // true=a teacher is inside

public: room(int i=0):total(i),teach_inside(false){cout<<"class created !"<<endl;}
	
	bool get_teach_inside(){return teach_inside;} 

	void set_teach_inside(){ teach_inside=true;}  	

        ~room(){ cout<<"class destroyed !"<<endl;}

	int get_total(){return total;}

        void enter(const student &s){
		total++;
		students.pushFront(s);
		cout<<" 	                "<<s.get_name()<<" enters classroom"<<endl;
		}

	void get_teach(teacher *t){	//puts a teacher t inside the classroom 
	set_teach_inside();
	t->set_class(this);
        classTeacher=t; 
	/**/
	cout<<"body of teach!"<<endl;
	}

        void print(){
		if(get_teach_inside())cout<<endl<<"Classroom's Teacher :"<< classTeacher->get_name()<<endl;

		cout<<"Students inside class: "<<get_total()<<endl;
                students.print();   // go to class List (stlist.cpp
      		}
};
















































