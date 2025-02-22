#include <sstream>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include<cstring>
#include <fstream>
#include <vector>
using namespace std;
void root(int* l, int &size);
void sortDown(int* l, int size, int index);
void sort(int* l,int s);
void insert(int* l,int s,int v);
void print(int* l, int size, int p, int o);

int main(){
  int list[100];
  for (int i=0;i<100;i++){
    list[i]=NULL;
  }
  vector<int> numbers;
  int size=1;
  char input[10];
  bool run =true;
  while (run==true){
    cout<<"INSERT,PRINT,DELETE,ROOT,END"<<endl;
    cin.getline(input,10);

    if (strcmp(input,"INSERT")==0){
      cout<< "from file(F) or input manualy(M)"<<endl;
      
      cin.getline(input,10);
      
      if (strcmp(input,"F")==0){
	if(size<100){
	cout<<"using numbers from file \"numbers\""<<endl;
	
	int val;
	ifstream number("number.txt");
	
	while (number >> val) {
	  numbers.push_back(val);
	}
	
	for(int i =0; i<numbers.size();i++){
	  
	  insert(list,size,numbers[i]);
	  size++;
	}
	}
	else{
	  cout<<"list full"<<endl;
	}
      }
      else if (strcmp(input,"M")==0){
	if (size<100){
	string input;
	cout << "Enter numbers separated by spaces: ";
	getline(cin, input);
	
	stringstream ss(input);
	int num;
	vector<int> tempNumbers; 
	
	while (ss >> num) {
	  tempNumbers.push_back(num);
	}
	
	for (int i = 0; i < tempNumbers.size(); i++) {
	  insert(list, size, tempNumbers[i]);
	  size++;
	}
      }
	else{
	  cout<<"list full"<<endl;
	}
      }
    }
    else if (strcmp(input,"DELETE")==0){
      while (size>1){
	root(list,size);
      }
    }
    else if (strcmp(input,"END")==0){
      run=false;
    }
    else if (strcmp(input,"ROOT")==0){
      root(list,size);
    }
    else if (strcmp(input,"PRINT")==0){
      print(list,size,1,0);
    }
    
  }
  return(0);
}


void root(int* l, int &size) {
  if (size <= 1) {
    cout << "Heap is empty!" << endl;
    return;
  }
  
  // print from heap(do job)
  cout << "Root: " << l[1] << endl;
  
  // switch root w/ last index then delete and sort
  l[1] = l[size - 1];
  l[size - 1] = 0; 
  size--; 

  
  sortDown(l, size, 1);
}

void sortDown(int* l, int size, int index) {
  int leftChild = 2 * index;
  int rightChild = 2 * index + 1;
  int smallest = index;
  
  if (leftChild < size && l[leftChild] < l[smallest]) {
    smallest = leftChild;
  }
  
  if (rightChild < size && l[rightChild] < l[smallest]) {
        smallest = rightChild;
  }
  
  if (smallest != index) {
    swap(l[index], l[smallest]);
    sortDown(l, size, smallest);
  }
}


void insert(int* l,int s,int v){
  l[s]=v;
  //sort
  if (s==1){
    
  }
  else{
    sort(l,s);
  }
  
}
void print(int* l, int size, int index, int depth) {
  if (index >= size || l[index] == 0) return;
  
  int rightChild = 2 * index + 1;
  int leftChild = 2 * index;
  
  // print right above
  print(l, size, rightChild, depth + 1);
  
  // print called node
  for (int i = 0; i < depth; i++) cout << "    ";
  cout << l[index] << endl;
  
  // print left below
  print(l, size, leftChild, depth + 1);
}


void sort (int* l,int s){
  //child less than parent
  int parent = floor(s/2);
  
  if (l[s]<l[parent]){
    //swap
    int temp =l[s];
    l[s]=l[parent];
    l[parent]=temp;
    sort(l,parent);
  }
  else{
    
  }
}
