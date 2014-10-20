//
// EventShape.cc
//
//   description: Class to calculate event shape varialbes in ROOT
//
//   author: David. G. Sheffield, Rutgers
//

#include "EventShape/Class/interface/EventShape.h"

EventShape::EventShape(std::vector<TVector3> vectorCollection)
{
  TMatrixDSym momentumTensor(3);

  for(std::vector<TVector3>::const_iterator p=vectorCollection.begin(); p!=vectorCollection.end(); p++){
    for(int i=0; i<3; i++){
      for(int j=0; j<=i; j++){
	momentumTensor[i][j] += (*p)[i]*(*p)[j];
      }
    }
  }
  
  momentumTensor *= 1/(momentumTensor[0][0] + momentumTensor[1][1] + momentumTensor[2][2]);
  TMatrixDSymEigen eigenSystem(momentumTensor);
  TVectorD eigenvalues = eigenSystem.GetEigenValues();
  eigenvalue1_ = eigenvalues[0];
  eigenvalue2_ = eigenvalues[1];
  eigenvalue3_ = eigenvalues[2];

  if(eigenvalue1_ < eigenvalue2_ || eigenvalue1_ < eigenvalue3_ || eigenvalue2_ < eigenvalue3_) std::cout << "not in order" << std::endl;
}

EventShape::~EventShape()
{
}

double EventShape::getEigenvalue(int iEigen) const
{
  switch(iEigen)
    {
    case 1:
      return eigenvalue1_;
    case 2:
      return eigenvalue2_;
    case 3:
      return eigenvalue3_;
    default:
      return -1000.0;
    }
  return 0.0;
}

double EventShape::getSphericity(void) const
{
  return 3.0/2.0*(eigenvalue2_ + eigenvalue3_);
}

double EventShape::getAplanarity(void) const
{
  return 3.0/2.0*eigenvalue3_;
}

double EventShape::getC(void) const
{
  return 3.0*(eigenvalue1_*eigenvalue2_ + eigenvalue1_*eigenvalue3_ + eigenvalue2_*eigenvalue3_);
}

double EventShape::getD(void) const
{
  return 27.0*eigenvalue1_*eigenvalue2_*eigenvalue3_;
}

double EventShape::getY(void) const
{
  return sqrt(3.0)/2.0*(eigenvalue2_ - eigenvalue3_);
}
