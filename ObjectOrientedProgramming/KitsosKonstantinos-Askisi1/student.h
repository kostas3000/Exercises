#include <iostream>
#include <cstring>

using namespace std;

class student{
private:

         const char* name;
         const int fn; // floor number
         const int cn; // class number

public: student():fn(0),cn(0){cout<<"Student created! ";}
        student(const char* n,int f,int c):name(n),fn(f),cn(c){cout<<"student "<<n<<" created! "<<f+1<<","<<c+1<<endl;} // usual constructor
        student(const student& s):name(s.name),fn(s.fn),cn(s.cn){ //copy constructor
                cout<<"***student copied"<<endl;
                }

        ~student(){cout<<"student destroyed!"<<endl;}

        const char* get_name()const{return name;}
        int get_fn()const{return fn;}
	int get_cn()const{return cn;}
        void print()/* const/**/{cout<<"Student "<< get_name()<<"       of class:"<< get_fn() +1<<","<<get_cn() +1 <<endl;}  
};

///////////////////////////////////////////////////

class room;

class teacher{
private:const char* name;
        const int fn;
        const int cn;
        room *croom;
//      int inside;

public: teacher(const char* n,int f,int c):name(n),fn(f),cn(c){cout<<"new teacher created"<<endl;}
        ~teacher(){/*delete[] croom ;*/ cout<<" a teacher to be destroyed"<<endl; }

        const char* get_name()const{return name;}// same
        int get_fn()const{return fn;}            //  as
        int get_cn()const{return cn;}           // student


        void set_class(room * cr  ){
                croom = cr;
//              set_inside();
                }

};/**/























































