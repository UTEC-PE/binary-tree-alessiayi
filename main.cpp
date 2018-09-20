#include <iostream>
#include "tree.h"

using namespace std;
/*
void menu() {
  system("cls");
  cout<<"==========================================================="<<endl;
  cout<<"\t\tPractica Operaciones"<<endl;
  cout<<"==========================================================="<<endl;

  //char* str="7/4*((a+b)*a)+3";
  //char* str="7/4*((a+-+--b)*a)+3";
  //char* str="2+(3)";
  char* str="7/4*((a+b)^4*a)+3";
}

void


int main(int argc, char const *argv[]) {
  menu();

  cout << "\nPress enter to continue ...";
  cin.get();
  return EXIT_SUCCESS;
}*/

int main(int argc, char const *argv[]) {
  tree Tree;
  Tree.constructTree("10+2");
  return 0;
}
