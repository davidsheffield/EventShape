//
// testEventShape.cc
//
//   description: Test EventShape class
//
//   author: David G. Sheffield, Rutgers

#include "EventShape/Class/src/EventShape.cc"
#include <iostream>
#include "TLorentzVector.h"

using namespace std;

int main()
{
  EventShape eventshape;
  
  TLorentzVector vec(1.5,0.0,0.0,2.0);
  eventshape.addVector(vec);
  
  cout << eventshape.getSumP2() << endl;
  
  return 0;
}
