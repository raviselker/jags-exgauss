#include <config.h>
#include "DExgauss.h"
#include <rng/RNG.h>
#include <util/nainf.h>

#include <JRmath.h>
#include <cmath>

using std::vector;

#define MU(par) (*par[0])
#define SIGMA(par) (*par[1])
#define LAMBDA(par) (*par[2])

namespace jags {
namespace exgauss {

DExgauss::DExgauss() : ScalarDist("dexgauss", 3, DIST_PROPORTION)
{}

bool DExgauss::checkParameterValue (vector<double const *> const &parameters) const
{
    return  (SIGMA(parameters)>0 &&
             LAMBDA(parameters)>0);
}

double DExgauss::dexgauss(double x, vector<double const *> const &parameters) const
{
  double mu = MU(parameters); 
  double sigma = SIGMA(parameters); 
  double lambda = LAMBDA(parameters); 

  double logd;

  logd =  log(lambda / 2) + (lambda / 2) * (2 * mu + lambda * pow(sigma,2) - 2 * x) +
        log(erfc((mu + lambda * pow(sigma,2) - x)/(sqrt(2) * sigma)));
  
  return logd;
}

double DExgauss::logDensity(double x, PDFType type,
       vector<double const *> const &parameters,
       double const *lbound, double const *ubound) const 
{
    double d = 0;

    d = dexgauss(x , parameters);
    
    return d;
}

double DExgauss::randomSample(vector<double const *> const &parameters, 
         double const *lbound, double const *ubound,
         RNG *rng) const
{
    return fabs( rng->uniform() );
}

double DExgauss::typicalValue(vector<double const *> const &parameters,
         double const *lbound, double const *ubound) const
{
    return 0.5;
}

bool DExgauss::isDiscreteValued(vector<bool> const &mask) const
{
    return true;
}

} // namespace exgauss
} // namespace jags
