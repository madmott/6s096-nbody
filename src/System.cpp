#include <nbody/constants.h>
#include <nbody/System.h>
#include <nbody/Vector3.h>

#include <fstream>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cstdlib>

namespace nbody {

  void System::addBody( float init_x, float init_y ) {
	  ++_nBodies;
	  _body.push_back( Body( init_x, init_y, _defaultMass ) );
  }

  inline void System::interactBodies( size_t i, size_t j, float softFactor, Vector3f &acc ) const {
    Vector3f r = _body[j].position() - _body[i].position();
    float distance = r.norm() + softFactor;
    float invDist = 1.0f / distance;
    float invDistCubed = cube( invDist );
    acc = acc + NEWTON_G * _body[j].mass() * invDistCubed * r;
  }

  void System::computeGravitation() {
    for( size_t i = 0; i < _nBodies; ++i ) {
      Vector3f acc{ 0.0f, 0.0f, 0.0f };
      for( size_t j = 0; j < _nBodies; ++j ) {
        if( i != j ) {
          interactBodies( i, j, _softFactor, acc );
        }
      }
      _body[i].force() = acc;
    }
  }

  void System::integrateSystem( float dt ) {
    Vector3f r, v, a;
    for( size_t i = 0; i < _nBodies; ++i ) {
      r = _body[i].position();
      v = _body[i].velocity();
      a = _body[i].force();

      v = v + ( a * dt );
      v = v * _dampingFactor;
      r = r + v * dt;

      _body[i].position() = r;
      _body[i].velocity() = v;
    }
  }

  void System::update( float dt ) {
    computeGravitation();
    integrateSystem( dt );
  }

  void System::readState( std::istream &input ) {
    input >> _nBodies;
    if( _nBodies > MAX_BODIES_RECOMMENDED ) {
      throw std::runtime_error( "Too many input bodies" );
    }
    for( size_t i = 0; i < _nBodies; ++i ) {
      _body.push_back( Body( ) );
      input >> _body[i];
    }
  }

  void System::writeState( std::ostream &output ) const {
    output << _nBodies << "\n";
    for( size_t i = 0; i < _nBodies; ++i ) {
      output << _body[i] << "\n";
    }
  }

  //Give the n bodies random positions
  void System::initRandomState() {
    float max_random = 1000.0f;

    for ( size_t i = 0; i < _nBodies; i++ ) {
      float randX = rand() * max_random;
      float randY = rand() * max_random;
      float randZ = rand() * max_random;
      float randMass = rand() * max_random;
        
      Vector3f randPos = Vector3f{ randX, randY, randZ };
      Body body = Body{ randMass };
      body.position() = randPos;
      body.force() = Vector3f();
      body.velocity() = Vector3f();
      _body.push_back(body);
    }
  }
} // namespace nbody
