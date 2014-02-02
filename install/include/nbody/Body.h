#ifndef _NBODY_BODY_H
#define _NBODY_BODY_H

#include <nbody/Vector3.h>
#include <nbody/Color.h>
#include <iosfwd>

namespace nbody {

  class Body {
    Vector3f _position;
    Vector3f _velocity;
    Vector3f _force;
    float _mass;
    Color _color;
  public:
    Body() : _position{}, _velocity{}, _force{}, _mass{}, _color{} {}
    Body( float x_pos, float y_pos, float mass_ ) : _position{ x_pos, y_pos, 0.0f }, _velocity{ 0.0f, 0.0f, 0.0f}, _force{ 0.0f, 0.0f, 0.0f }, _mass{ mass_}, _color{} {}
    Body( float mass_ ) : _position {}, _velocity{}, _force{}, _mass{ mass_ }, _color{} {}
    inline Vector3f position() const { return _position; }
    inline Vector3f& position() { return _position; }
    inline Vector3f velocity() const { return _velocity; }
    inline Vector3f& velocity() { return _velocity; }
    inline Vector3f force() const { return _force; }
    inline Vector3f& force() { return _force; }
    inline float mass() const { return _mass; }
    friend std::istream& operator>>( std::istream &is, Body &body );
    friend std::ostream& operator<<( std::ostream &os, const Body &body );
    inline Color color() const { return _color; }
    inline Color& color() { return _color; }
  };

} // namespace nbody

#endif // _NBODY_BODY_H
