#include "floor.h"

class school{
private: yard syard;
        stairs sstairs;
        floor **sfloor;
        // int cortotal;int croomtotal;
        const int ycapacity; const int stairscapacity; const int corcapacity ;const int croomcapacity;

public: school( int y,int s,int c,int r):ycapacity(y),stairscapacity(s),corcapacity(c),croomcapacity(r){
                sfloor=new floor*[3];
                for (int i = 0 ; i < 3 ; i++)
                        sfloor[i] = new floor(c,r);
                cout<<"school created"<<endl;    }

	~school(){ delete[] sfloor; cout<<"school destroyed"<<endl;}

        const room get_room(int f,int c){return sfloor[f]->get_room(c);} //     {       FLOOR FUNCTIONS

        void get_teach(teacher *t){                                       //{     THAT  ARE
                int f=t->get_fn();
                sfloor[f]->get_teach(t);
                }
        int get_teach_inside(int f,int c){return sfloor[f]->get_teach_inside(c);}   //         TRANSFERED           }

	//student to exit corridor :
	const student st_to_go(int i){return sfloor[i]->st_to_go();}	     // 		IN

        void enteryard(const student &s){if(syard.get_total()< ycapacity) syard.enter(s);}  //          SCHOOL CLASS    }


        void enterstairs(){
                if(sstairs.get_total()< stairscapacity){
                        //if(s.get_name()!="error"){}
                        student s = syard.st_to_go();  // we get the student ready to go (!) and he is poped out of the yard list
                         cout<<"                       "<<s.get_name()<<" exits yard"<<endl;
                        sstairs.enter(s);
                        }
                }

         void entercor(){
		
                student s = sstairs.st_to_go(); // we get the student ready to go (!) and he is poped out of the sstairs list
                int i;
                i=s.get_fn();           // we get students floor number
		if(sfloor[i]->cor_total()<corcapacity){
                  cout<<"                       "<<s.get_name()<<" exits stairs"<<endl;
		  sfloor[i]->entercor(s);}

		else sstairs.enter(s); // return the student back
                //}
                }

void entercroom(int i){                // we choose in the main programm the floor number( i =floor number)
/*calling get_st() is enough for the student to pop from list/**/
                        student s=st_to_go(i);
                    //    if(s.get_name()!="error"){      // error is what the get_student()(of class List) function returns when a location is empty

         if(get_teach_inside(i, s.get_cn()) ==false && s.get_name()!="error" && sfloor[i]->croom_total(s.get_cn())<croomcapacity ){  //check if there is a teacher inside (!) floor number is already given
                                cout<<"                       "<<s.get_name()<<" exits corridor"<<endl;
                                sfloor[i]->enter_class(s);
                                }

                           else{cout<<"The teacher kicked "<<s.get_name()<<" out of the class!"<<endl;
                                sfloor[i]->entercor(s); // calling cor_1st(i) poped the student out of the corridor , so we get him back in
                                }
                      //   }

                        //else{ cout<<"                   no one is waiting in the corridor in floor "<<i+1<<endl;
                             //   sfloor[i]->entercor(s);	// return the student back 
                          //    }
                        }



         void print(){
                syard.print();
                sstairs.print();

                cout<<"1st floor: "<<endl;
                sfloor[0]->print();
                cout<<"2nd floor: "<<endl;
                sfloor[1]->print();
                cout<<"3rd floor: "<<endl;
                sfloor[2]->print();/**/
                }
};
































