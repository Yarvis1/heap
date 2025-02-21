#include<iostream>
#include<cstring>

class node{
public:
  node(int i,node* p);
  int getValue();
  void setValue(int i);
  node setParent(node* p);
  node* getParent();
  node* getLchild();
  node* getRchild();
  void setLchild(node* child);
  void setRchild(node* child);
private:
  int value;
  node* parent;
  node* Lchild;
  node* Rchild;

}






