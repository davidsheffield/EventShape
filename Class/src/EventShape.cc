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
}

EventShape::~EventShape()
{
}

void EventShape::addVector(TLorentzVector v)
{
  fSumP2 += v.Px()*v.Px() + v.Py()*v.Py() + v.Pz()*v.Pz();
  return;
}

double EventShape::getSumP2(void) const
{
  return fSumP2;
}
