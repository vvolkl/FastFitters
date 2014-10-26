#include "FastHelix.h"
#include "FastLine.h"
#include "FastCircle.h"
#include "GlobalPoint.h"
#include <iostream>

int main(void)
{
  GlobalPoint c = GlobalPoint(-3.1349, -3.39122, -9.87096);
  GlobalPoint b = GlobalPoint(-5.16787, -5.50287, -14.075);
  GlobalPoint a = GlobalPoint(-6.85429, -7.1734, -17.484);
  FastHelix fit (a, b, c, 3.8112);
  std::cout << fit.isValid() << " " << length(fit.getPt()) << std::endl;
}
