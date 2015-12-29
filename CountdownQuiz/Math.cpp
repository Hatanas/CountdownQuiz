#include "Math.h"


double util::Math::norm(double x, double minX, double maxX)
{
	if(x < minX) {
		return 0.0;
	}
	else if(maxX < x) {
		return 1.0;
	}
	else {
		return (x - minX) / (maxX - minX);
	}
}

double util::Math::reverseNorm(double x, double minX, double maxX)
{
	if(x < minX) {
		return 1.0;
	} else if(maxX < x) {
		return 0.0;
	} else {
		return 1.0 - (x - minX) / (maxX - minX);
	}
}

double util::Math::inverseNorm(double normX, double minX, double maxX)
{
	if(normX < 0.0) {
		return minX;
	} else if(1.0 < normX) {
		return maxX;
	} else {
		return (maxX - minX) * normX - minX;
	}
}