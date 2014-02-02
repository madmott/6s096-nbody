#ifndef _NBODY_VIEW_H
#define _NBODY_VIEW_H

/*#include <iosfwd>
#include <string>
#include <vector>*/
#include "nbody/System.h"
#include "nbody/Color.h"

namespace nbody{
    class View {
        float _xposition;
        float _yposition;
        System _system;
        static void menuCallback ( int value );
        static void mouseCallback( int button, int state, int x, int y);
        static void exitCallback( unsigned char key, int x, int y );
        static void displayCallback();
        void drawBody( Vector3<float> position, Color color);
    protected:
        static View *_instance;
    public:
        View( System &system ) : _xposition{}, _yposition{}, _system{ system } {initializer();}
        ~View() {}
        void initializer ();
        void updateGUI();
        void menu();
        void mouse( int x, int y );
        void exitGUI();
            
    };
}

#endif