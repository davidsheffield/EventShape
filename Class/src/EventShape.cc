//
// EventShape.cc
//
//   description: Class to calculate event shape varialbes in ROOT
//
//   author: David. G. Sheffield, Rutgers
//

#include "EventShape/Class/interface/EventShape.h"

EventShape::EventShape()
{
  fSumP2 = 0.0;
  fMomentumTensor.ResizeTo(3,3);
  for(int i=0; i<3; i++){
    for(int j=0; j<=i; j++){
      fMomentumTensor[i][j] = 0.0;
    }
  }
}

EventShape::~EventShape()
{
}

void EventShape::addVector(TLorentzVector v)
{
  fSumP2 += v.Px()*v.Px() + v.Py()*v.Py() + v.Pz()*v.Pz();
  fMomentumTensor[0][0] += v.Px()*v.Px();
  fMomentumTensor[1][0] += v.Py()*v.Px();
  fMomentumTensor[1][1] += v.Py()*v.Py();
  fMomentumTensor[2][0] += v.Pz()*v.Px();
  fMomentumTensor[2][1] += v.Pz()*v.Py();
  fMomentumTensor[2][2] += v.Pz()*v.Py();

  return;
}

double EventShape::getSumP2(void) const
{
  return fSumP2;
}

double EventShape::getMomentumTensor(int i, int j) const
{
  return fMomentumTensor[i][j];
}

TVectorD EventShape::getEigenvalues()
{
  TMatrixDSymEigen eigen(fMomentumTensor);
  return eigen.GetEigenValues();
}
