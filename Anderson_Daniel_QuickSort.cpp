//  Daniel Anderson

#ifndef QuickSort_cpp
#define QuickSort_cpp

#include <stdlib.h>  // for random pivot rand() % list arraysize
#include <iostream>  // for personal testing 
#include <time.h>    // to set up random
#include <chrono>    // for track time
#include <fstream>   // read/write to files
#include <string>



int partition (double array[], int start, int end) {
   
// start: first index
// end: last index = size-1
// array whole array
   
   int size = end - start;
   srand(time(NULL));
   int index_pivot = start + rand() % (size);
   double pivot = array[index_pivot];
  
 
   
   //Have random pivot value and spot
   
   

   
    std::swap(array[index_pivot],array[start]);
   // put pivot at start
   

   //partition from after pivot at start index
   int startI = start;
   int endJ = end;

   while (endJ > startI) {

     while(pivot > array[startI]){
         startI++;
     }

     while(pivot < array[endJ]) {
         endJ--;
     }
     
     std::swap(array[startI],array[endJ]);
     
   }
     // prevent swap if the start index before end
     if(endJ <= startI){
     std::swap(array[startI],array[endJ]);
     }
     
     // last swap only if value of pivot greater than last spot of end
     if(array[start] > array[endJ])
     std::swap(array[start],array[endJ]);
   
     return endJ;
}



void Quicksort(double array[], int start, int end) {
   if(start < end) {
   
   // position of sorted element
   int split = partition(array, start, end);

   // sort to the left of split
      Quicksort(array,start,split - 1);

   //sort to the right of spilt
      Quicksort(array,split + 1, end);

   }
      
}


int main(int argc, char *argv[]){

   const std::string OutDelim = "_"; 
   std::string content;    
 
   if(argc < 0){
   std::cout << "no  input file";
   return 0;
  }
   
   std::string input = argv[1];
   // Make defualt output file
   std::string output = "output/output";
   output += input.substr(input.find(OutDelim)+1,
		      input.length());
  

 // open file 
   std::ifstream Infile(input);

//put contents of file in content
    if(Infile.is_open()){
       getline(Infile,content);   
      }
    
     Infile.close();

     int str_leng = content.length();
     char delim = '\t';
     int array_size=0;
   //get array size
  for(int i = 0; i < str_leng;++i) {

    if(content.at(i) == delim)  
    array_size++;    
}


   double *array = new double[array_size];
   int pos = 0;
 int index = 0;
  while((static_cast<const long unsigned int>(pos = content.find(delim)) != std::string::npos )){
   
      std::string temp = content.substr(0,pos);
      array[index] = std::stod(temp);
      content.erase(0,pos + sizeof(delim));
      ++index;
}



//test & time QuickSort
auto startTime = std::chrono::steady_clock::now();

int start = 0;
Quicksort(array,start, array_size-1);


auto endTime = std::chrono::steady_clock::now();


// nano to Milli conversion
double time = std::chrono::duration_cast<std::chrono::microseconds>(endTime-startTime).count();

// set to given out file 
if(argv[2] != nullptr){
   output = argv[2];
}

std::ofstream Outfile(output);

  if(Outfile.is_open()) {
    Outfile << array_size;
    Outfile << "input Size\t";
    Outfile << time << " microseconds"<<"\n";

    for(int i = 0;i < array_size;++i){
    Outfile << array[i] <<"\t";
       }    
   }
Outfile.close();

//hard coded outfile 
Infile.open("Anderson_Daniel_executionTime.txt");
content = "";

double size10Ave = 0;
double size100Ave = 0;
double size1000Ave = 0;
double count10 = 0;
double count100 = 0;
double count1000 =0;

if(Infile.is_open()){
   std::string temp;
   while(getline(Infile,temp)){

   if (temp == ""){
      break;
      }
      int InputSize =  stoi(temp.substr(0,delim));
      if( InputSize == 10){
        count10++;
        size10Ave += stoi(temp.substr(temp.find(delim)+1,temp.length()));
      }else if(InputSize == 100){
         count100++;
         size100Ave += stoi(temp.substr(temp.find(delim)+1,temp.length()));
      }else {
         count1000++;
         size1000Ave += stoi(temp.substr(temp.find(delim)+1,temp.length()));
      }
      content += temp;
      content += "\n";
   }
  
}
Infile.close();

if(array_size == 10){
count10++;
size10Ave += time;
} else if(array_size == 100){
   count100++;
   size100Ave += time;
}else {
   count1000++;
   size1000Ave +=time;
}




Outfile.open("Anderson_Daniel_executionTime.txt");
if(Outfile.is_open()) {
   Outfile <<content  << array_size << "\t" << time << "\n";
}
Outfile.close();
//Hard coded ave time file
Outfile.open("Anderson_Daniel_averageExecutionTime.txt");
size10Ave /= count10;
size100Ave /= count100;
size1000Ave /= count1000;
if(Outfile.is_open()){
   Outfile << "10\t" << size10Ave <<"\n100\t" << size100Ave <<"\n1000\t" << size1000Ave;
}
Outfile.close();


delete [] array;
return 0;
}
#endif // QuickSort_cpp
