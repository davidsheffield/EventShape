//
// testEventShape.cc
//
//   description: Test EventShape class
//
//   author: David G. Sheffield, Rutgers

#include "EventShape/Class/src/EventShape.cc"
#include <iostream>
#include <vector>
#include "TVector3.h"

using namespace std;

int main()
{
  vector<TVector3> vectors;
  vectors.push_back(TVector3(1.0,2.0,5.0));
  vectors.push_back(TVector3(2.0,1.0,4.0));
  vectors.push_back(TVector3(1.5,3.0,2.0));
  cout << "vectors size: " << vectors.size() << endl;

  EventShape eventshape(vectors);
  
  cout << "eigenvalue 1: " << eventshape.getEigenvalue(1) << endl;
  cout << "eigenvalue 2: " << eventshape.getEigenvalue(2) << endl;
  cout << "eigenvalue 3: " << eventshape.getEigenvalue(3) << endl;

  cout << "sphericity: " << eventshape.getSphericity() << endl;
  cout << "aplanarity: " << eventshape.getAplanarity() << endl;
  cout << "C: " << eventshape.getC() << endl;
  cout << "D: " << eventshape.getD() << endl;
  cout << "Y: " << eventshape.getY() << endl;

  return 0;
}
