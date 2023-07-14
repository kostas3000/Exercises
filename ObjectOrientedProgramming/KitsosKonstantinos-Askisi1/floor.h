#include "rooms.h"

class floor{
private: corridor cor;
         room *croom;	  //classroom array
         int corcapacity; //max number of students
         int croomcapacity;

public: floor(int i,int j):cor(0),corcapacity(i),croomcapacity(j){ //CONSTRUCTOR
                croom=new room[6];     //! we can initialize the classroom array like that beacause the capacitities are saved in the floorclass and not in croom class
                cout<<"floor created"<<endl; 
		   }

        ~floor(){ delete[] croom ; cout<<"floor destroyed!"<<endl;}//DESTRUCTOR

	int get_corcapacity(){return corcapacity; }
        int get_croomcapacity(){return croomcapacity; }

	int cor_total(){return cor.get_total();}	// get total from corridor
	int croom_total(int c){return croom[c].get_total();}	// get total from class

	student st_to_go(){return cor.st_to_go();}/**/////////////////////

	const room get_room(int i){return croom[i];}

	void get_teach(teacher *t){	// put a teacher in a class
                        int c=t->get_cn();
                        croom[c].get_teach(t);
                        }

        int get_teach_inside(int c){return croom[c].get_teach_inside();} // check if teacher is inside

        void entercor(const student &s ){
                //if( cor.get_total()< get_corcapacity() )
                        cor.enter(s);
		
                }

        void enter_class(const student &s ){
               int i=s.get_cn();       // i class number
                if( croom[i].get_total()< get_croomcapacity() ){
                        croom[i].enter(s);
                        }
                }

	void print(){
                cor.print();
                for(int i=0; i<6 ; i++){
                        cout<<" class "<<i+1<<" ! ";
                        croom[i].print();
                        }
                }

};

