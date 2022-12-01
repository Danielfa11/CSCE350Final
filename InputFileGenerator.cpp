// Daniel Anderson
//

#ifndef InputFileGenerator_cpp
#define InputFileGenerator_cpp

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

int main() {

int max = 0;
srand(time(NULL));
while(max <= 74){
  string file = "inputs/input_";
  
  file += to_string(max);
  
  if(max < 25){
  file += "size_10";
  } else if(max < 50) {
  file += "size_100";
  } else {
  file += "size_1000";
  }  
  file += ".txt";
   ofstream myfile(file);

   if(myfile.is_open()) {
     int count = 0; 
     if(max <= 25) {
     while(count <= 9){
       myfile << static_cast<double>(rand())/static_cast<double>(RAND_MAX/100);
       myfile <<"\t";
       count++;
       
     }
     } else if(max <= 50) {
        while(count <= 99){
       myfile << static_cast<double>(rand())/static_cast<double>(RAND_MAX/1000);      
       myfile <<"\t";
       count++;
       
	}
     } else 
	while(count <= 999){
       myfile << static_cast<double>(rand())/static_cast<double>(RAND_MAX/10000);       
       myfile <<"\t";
       count++;
       
	}
   
   myfile.close();
   }else
     cout << "not open\n";
max++;
}
// 25 files input size 10, 100, 1000
return 0;
}

#endif //InputFileGenerator_cpp
