#ifndef _NBODY_VIEW_H
#define _NBODY_VIEW_H

#include <iosfwd>
#include <string>
#include <vector>
#include "nbody/System.h"
#include "nbody/Body.h"

namespace nbody{
    class View {
        System system;
        float _xposition;
        float _yposition;
    public:
        View() : _xposition{}, _yposition{}, system{0} {initializer();}
        View( std::string filename ) : _xposition{}, _yposition, system{filename} {initializer();}
        View( std::istream &input ) : _xposition{}, _yposition{}, system {input} {initializer();}
        ~View() {}
        
        void initializer (); 
    void menuCallback ( int value );
    void mouseCallback( int button, int state, int x, int y);
    void exitCallback( unsigned char key, int x, int y );
    void updateGUI();
    void drawBody( Vector3<float> position, Color color);
    
    }
}

#endif