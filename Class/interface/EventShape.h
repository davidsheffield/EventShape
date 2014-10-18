#ifndef _EVENTSHAPE_CLASS_EVENTSHAPE_H_
#define _EVENTSHAPE_CLASS_EVENTSHAPE_H_

//
// EventShape.h
//
//   description: Class to calculate event shape varialbes in ROOT
//
//   author: David. G. Sheffield, Rutgers
//

#include "TLorentzVector.h"
#include "TMatrixDSym.h"
#include "TMatrixDSymEigen.h"
#include "TVectorD.h"

class EventShape
{
 public:
  EventShape();
  ~EventShape();
  
  void addVector(TLorentzVector v);
  double getSumP2(void) const;
  double getMomentumTensor(int,int) const;
  TVectorD getEigenvalues();
 private:
  double fSumP2;
  TMatrixDSym fMomentumTensor;
};

#endif
