#include <cmath>
#include <iostream>
#include<cstring>
using namespace std;
void sort(int* l,int s);
void print(int* l, int size, int p, int depth);
int main(){
  int list[100];
    for (int i=0;i<100;i++){
    list[i]=NULL;
  }
  int size=1;
  char input[10];
  bool run =true;
  while (run==true){
  cout<<"INSERT,PRINT,DELETE,ROOT,END"<<endl;
  cin.getline(input,10);
  if (strcmp(input,"INSERT")==0){
    cout<<"enter value"<<endl;
    int val;
    cin>>val;
    list[size]=val;
    //sort
    if (size==1){

      }
    else{
      sort(list,size);
    }
    size++;
   
  }
  else if (strcmp(input,"DELETE")==0){

  }
  else if (strcmp(input,"END")==0){
    run=false;
  }
  else if (strcmp(input,"ROOT")==0){

  }
  else if (strcmp(input,"PRINT")==0){
    print(list,size,0,0);
  }

}
  return(0);
}
#include <iostream>
using namespace std;

void print(int* l, int size, int p, int o) {
    int index = p;
    int depth = o;
     if (index >= size) return;

    // Print the right child first (higher values appear first)
    int rightChild = 2 * index + 2;
    print(l, size, rightChild, depth + 1);

    // Print current node with indentation
    for (int i = 0; i < depth; i++) cout << "    ";  // Indentation for hierarchy
    cout << l[index] << endl;

    // Print the left child
    int leftChild = 2 * index + 1;
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
