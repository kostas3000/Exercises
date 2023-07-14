#include <stdlib.h>
#include "school.h"
#include <ctime>
#include <cstring>
#include <cstdlib>


/////  RANDOM NAME GENERATOR  ///////////
char* rand_name(){

char cletters[20]={'b','c','d','f','g','h','j','k','l','m','n','p','q',
'r','s','t','v','w','x','z'};	// �consonant / used as consonant

char vletters[6]={'a','e','i','o','u','y'}; //voiced

char *ran;
ran=new char[10];

for (int i=0;i<10;i+=2) ran[i]=cletters[rand() % 20];  

for (int i=1;i<10;i+=2) ran[i]=vletters[rand() % 6];

return ran;
}

///////////////////////////////////////////////////////////////////
//////////////////  M   A   I   N  :   ////////////////////////////
///////////////////////////////////////////////////////////////////

int main(int argc,char **argv){

FILE * freopen ( const char * filename, const char * mode, FILE * stream );
freopen ("OUTPUT_file.txt", "w", stdout); // direct std output to a txt file

int Cyard=atoi(argv[1]);
int Cstairs=atoi(argv[2]);
int Ccorridor=atoi(argv[3]);
int Cclass=atoi(argv[4]);

srand(time(NULL));
int i,j,k,count=0;


//////	CONSTRUCTION OF SCHOOL(+YARD,STAIRS,CORRIDOR,CLASSROOMS):   ///////
school dit(Cyard,Cstairs,Ccorridor,Cclass); 


///////////	STUDENTS' CONSTRUCTION:     ////////////////
student* st[18*Cclass];
for( i=0; i<18*Cclass; i++ ){		// the number of students is num_of_floors*nclass*nstudentsin1class
		st[count]=new student(rand_name(),rand()%3,rand()%6);
		count++;
		}



///////////	TEACHERS' CONSTRUCTION:	    /////////////////
teacher* teachers[18];

for(i=0;i<18;i++){
teachers[i]=new teacher(rand_name(),i/6,i%6);  

if(rand()%5==0) dit.get_teach(teachers[i]);    //////a random way of deciding wether the teacher will be inside his class//////////

}


/////////////////////////////////////////////////////
int used_number[18*Cclass];
for(i=0;  i< 18*Cclass ; i++){ //each poisition represents the similar position int the students array
	used_number[i]=0;	//when a students position number has 0 value it means the student hasn't entered the school yet
}


//////////	STUDENT INSERTION:	//////////////////////
int counter=0;

for(int i=0; counter< 18*Cclass ;i++ ){
int r=rand()% (18*Cclass);	//////////random position in the student array

if(used_number[r]==0){		// one by one insertion 
  dit.enteryard(*st[r]);
  dit.enterstairs();
  dit.entercor();
  dit.entercroom(st[r]->get_fn());

  counter++;		// this the real counter of the students inside school
}
used_number[r]=1;	// now there is no danger the programm will insert the same student more than once
}



////////////////	 PRINT:		//////////////////////////
cout<<"school life consists of :"<<endl;
dit.print();
//////////////////////////////////////////



for(i=0;i<18*Cclass;i++)delete st[i];		//destructions
for(i=0;i<18;i++)delete teachers[i];

cout<<"we are exiting main"<<endl;
return 0;
}

