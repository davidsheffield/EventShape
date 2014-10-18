//
// testEventShape.cc
//
//   description: Test EventShape class
//
//   author: David G. Sheffield, Rutgers

#include "EventShape/Class/src/EventShape.cc"
#include <iostream>
#include "TLorentzVector.h"
#include "TVectorD.h"

using namespace std;

int main()
{
  EventShape eventshape;
  
  TLorentzVector vec(1.5,0.0,0.0,2.0);
  eventshape.addVector(vec);
  vec.SetPy(2.5);
  eventshape.addVector(vec);
  vec.SetPz(0.5);
  vec.SetPx(0.0);
  eventshape.addVector(vec);
  
  cout << eventshape.getSumP2() << endl;

  for(int i=0; i<3; i++){
    cout << "[ ";
    for(int j=0; j<3; j++){
      cout << eventshape.getMomentumTensor(i,j) << " ";
    }
    cout << "]" << endl;
  }

  cout << endl;

  TVectorD eigen = eventshape.getEigenvalues();

  cout << eigen[0] << endl;
  cout << eigen[1] << endl;
  cout << eigen[2] << endl;

  return 0;
}
