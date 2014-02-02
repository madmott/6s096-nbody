#ifndef _NBODY_VIEW_H
#define _NBODY_VIEW_H

#include <iosfwd>
#include <string>
#include <vector>
#include "nbody/System.h"
#include "nbody/Body.h"
#include "nbody/Color.h"

namespace nbody{
    class View {
        float _xposition;
        float _yposition;
        System _system;
    public:
        View( System &system ) : _xposition{}, _yposition{}, _system{ system } {initializer();}
        ~View() {}
        void initializer (); 
    void menuCallback ( int value );
    void mouseCallback( int button, int state, int x, int y);
    void exitCallback( unsigned char key, int x, int y );
    void updateGUI();
    void drawBody( Vector3<float> position, Color color);
    
    };
}

#endif