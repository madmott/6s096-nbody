#ifndef _NBODY_SIMULATION_H
#define _NBODY_SIMULATION_H

#include <nbody/System.h>
#include <nbody/View.h>
#include <iosfwd>
#include <string>

namespace nbody {

  class Simulation {
    System *_system;
    std::string _name;
    View *_view;
    Simulation( const Simulation& sim ) = delete;
    Simulation& operator=( const Simulation& sim ) = delete;
    std::string generateName();
  public:
    Simulation() : _system{nullptr}, _name{ generateName() }, _view{ new View (*_system) } {}
    Simulation( std::istream &input ) : _system{ new System (input) }, _name{ generateName()}, _view { new View (*_system) } {}
    void evolveSystem( int nSteps, float dt );
    void loadRun( std::istream &input );
    void saveRun() const;
  };

} // namespace nbody

#endif // _NBODY_SIMULATION_H
