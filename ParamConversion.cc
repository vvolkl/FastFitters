#include <cmath>
#include <iostream>
#include <array>
#include "GlobalPoint.h"



struct PerigeeTrackParameters {
  double d0;
  double z0;
  double phi0;
  double cotTheta;
  double qOverPt;
};


PerigeeTrackParameters ParticleProperties2TrackParameters (GlobalPoint vertex, GlobalPoint momentum, double Bfield, int charge) {

  // assuming referencePoint = (0,0,0)
  
  PerigeeTrackParameters params;

  // calculation of qOverP ;
  double pt =  std::sqrt( momentum.x() * momentum.x() + momentum.y() * momentum.y() );
  params.qOverPt = charge / pt;

  double rho = params.qOverPt * Bfield * 0.003;


  // calculation of d0
  // azimuthal angle of the momentum at the vertex
  double phiGen = std::atan2(momentum.y(), momentum.x()); 

  // coordinates of the helix center
  double xc = vertex.x() + charge * rho * std::sin(phiGen);
  double yc = vertex.y() - charge * rho * std::cos(phiGen);
  params.d0 = -1 * charge * (std::sqrt(xc*xc + yc*yc) - rho);

  // calculation of phi0
  params.phi0 = std::atan2(yc, xc) + M_PI / 2.;

  //calculation of cotTheta
  params.cotTheta = momentum.z() / pt;

  //calculation of z0

  params.z0 = vertex.z() - params.cotTheta * rho * std::abs(params.phi0 - phiGen);

  return params;


}

int main() {

  GlobalPoint vertex(0,0,0);
  GlobalPoint momentum(0,1,1);
  PerigeeTrackParameters res = ParticleProperties2TrackParameters(vertex, momentum, 1. / 0.003, 1);
  std::cout << "\t"<< res.d0;
  std::cout << "\t"<< res.z0;
  std::cout << "\t"<< res.phi0;
  std::cout << "\t"<< res.cotTheta;
  std::cout << "\t"<< res.qOverPt;
  std::cout << std::endl;





return 0;
}



