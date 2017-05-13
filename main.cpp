#include "FastHelix.h"
#include "FastLine.h"
#include "FastCircle.h"
#include "GlobalPoint.h"
#include <iostream>

int main(void)
{
  GlobalPoint c = GlobalPoint(-3.30708786, -3.75092555, -5.65468847);
  GlobalPoint b = GlobalPoint(-2.6792851,  -1.35026685, -3.11210371);
  GlobalPoint a = GlobalPoint(0,0,0);
  //GlobalPoint c = GlobalPoint(0,-1,0);
  //GlobalPoint b = GlobalPoint(2,1,1);
  //GlobalPoint a = GlobalPoint(0,3,2);

//GlobalPoint a = GlobalPoint(-6.85429, -7.1734, -17.484);

  FastHelix fit2 (a, b, c, 3);
  FastCircle fit = fit2.circle();
  std::cout << fit2.getPt() << "   "  << fit.isValid() << " " << fit.rho() << " " << fit.x0() << " " << fit.y0()  << std::endl;

}
