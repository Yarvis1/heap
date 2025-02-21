#include<iostream>
#include<cstring>
#include "node.h"

node::node(int i, node* p){
  value =i;
  parent=p;
  Lchild=NULL;
  Rchild=NULL;
}
int node::getValue(){
  return value;
}
node* node::getParent(){
  return parent;
}
node* node::getLchild(){
  return Lchild;
}
node* node::getRchild(){
  return Rchild;
}
node* node::setParent(node p){
  parent =p;
}
void node::setValue(int i);
void node::setLchild(node* child){
  Lchild=child;
}
void node::setRchild(node* child){
  Rchild=child;
}
