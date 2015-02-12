#include <Module.h> // JAGS module base class
#include <distributions/DExgauss.h> // Exgauss distribution class

namespace exgauss { // module namespace

class EXGAUSSModule : public Module { // module class
  public:
    EXGAUSSModule(); // constructor
    ~EXGAUSSModule(); // destructor
};

EXGAUSSModule::EXGAUSSModule() : Module("exgauss") {
  insert(new DExgauss); // inherited function to load JAGS objects
}
EXGAUSSModule::~EXGAUSSModule() {
  std::vector<Distribution*> const &dvec = distributions();
  for (unsigned int i = 0; i < dvec.size(); ++i) {
    delete dvec[i];
  } // deletes instantiated distribution objects
}

}

exgauss::EXGAUSSModule _exgauss_module;
