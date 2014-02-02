#ifndef _NBODY_CONSTANTS_H
#define _NBODY_CONSTANTS_H

#include <cstddef> 

namespace nbody {

  extern const size_t MAX_BODIES_RECOMMENDED; // = 10000
  extern const float NEWTON_G; // = 1.0f
  extern const float TIME_STEP; // 1/60

} // namespace nbody
#endif // _NBODY_CONSTANTS_H
