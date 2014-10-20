#ifndef _EVENTSHAPE_CLASS_EVENTSHAPE_H_
#define _EVENTSHAPE_CLASS_EVENTSHAPE_H_

//
// EventShape.h
//
//   description: Class to calculate event shape varialbes in ROOT
//
//   author: David. G. Sheffield, Rutgers
//

#include <vector>
#include <cmath>
#include <iostream>

#include "TVector3.h"
#include "TMatrixDSym.h"
#include "TMatrixDSymEigen.h"
#include "TVectorD.h"

class EventShape
{
 public:
  EventShape(std::vector<TVector3>);
  ~EventShape();
  
  double getEigenvalue(int) const;
  double getSphericity(void) const;
  double getAplanarity(void) const;
  double getC(void) const;
  double getD(void) const;
  double getY(void) const;
 private:
  double eigenvalue1_;
  double eigenvalue2_;
  double eigenvalue3_;
};

#endif
