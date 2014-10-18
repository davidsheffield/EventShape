#ifndef _EVENTSHAPE_CLASS_EVENTSHAPE_H_
#define _EVENTSHAPE_CLASS_EVENTSHAPE_H_

//
// EventShape.h
//
//   description: Class to calculate event shape varialbes in ROOT
//
//   author: David. G. Sheffield, Rutgers
//

#include "TObject.h"
#include "TLorentzVector.h"

class EventShape
{
 public:
  EventShape();
  ~EventShape();
  
  void addVector(TLorentzVector v);
  double getSumP2(void) const;
 private:
  double fSumP2;
};

#endif
