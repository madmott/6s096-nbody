#include <nbody/View.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <vector>
#include <nbody/System.h>
#include <nbody/Body.h>
#include <nbody/Color.h>
#include <nbody/constants.h>

namespace nbody {
    
    View *View:: _instance = nullptr;
    
    // exit the program if press the escape button
    void View::exit() {
        glutDestroyWindow( 1 );
        exit ( EXIT_SUCCESS );
    }
    
    // if press the new object dropdown from the menu button, add a new body given the current mouse coordinates [the new object's position] to the system
    
    void View:: menu() {
        _system.addBody( _xposition, _yposition ); // X and Y
    }
    
    // draw a body at its correct position in the correct color
    void View::drawBody ( Vector3<float> position, Color color ) {
        glPointSize( 1.0 ); // all bodies will be the same size
        glColor3f( color.r(), color.g(), color.b() ); // set the color
        
        glBegin( GL_POINTS ); // draw the new point
        glVertex3f( position.x(), position.y(), position.z() );
        glEnd();
    }
    
    // the display callback; for each body in the System's bodies, draw the body (after one time step)
    void View::updateGUI() {
         
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // just draw new
        
        _system.update(TIME_STEP); // update by one time step
        std::vector <Body> bodies = _system.getBodies();
        for ( size_t i = 0; i < bodies.size(); i++ ) {
            drawBody( bodies[i].position(), bodies[i].color() );
        }
        
        glutSwapBuffers();
        glFlush();
        glutPostRedisplay();
    }
    
    
    // gets the position of the mouse for when a user presses right click
    // (which generates the menu for generating a new body)
    void View::mouse( int x, int y ) {
        // want to know this x and y position
        _xposition = ( x - 250.0 ) / 250.0;
        _yposition = ( y - 250.0 ) / 250.0;
    }
    
    void View::menuCallback ( int value ) {
        if ( value == 1 ) {
            _instance -> menu ();
        }
    }
    
    void View::mouseCallback( int button, int state, int x, int y) {
        if ( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN ) {
            _instance -> mouse ( x, y );
        }
    }
    
    void View::exitCallback( unsigned char key, int x, int y ) {
        if ( key == 27 ) {
            x += y; // have to do something with them, or else get an error
            _instance -> exit();
        }
    }
    void View::displayCallback() {
        _instance -> updateGUI();
    }

    
    void View::initializer () {
        glutInit( nullptr, nullptr ); // main function
        glutInitDisplayMode ( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA );
        
        // generate a new window called "N-body Simulation" with a size of 500X500
        glutInitWindowSize ( 500,500 );
        glutInitWindowPosition ( 100, 100 );
        glutCreateWindow ( "N-Body Simulation" );
        
        // create a dropdown menu [which you get by right-clicking], so if you then
        //click on the entry "create new object here", it generates a new object
        
        int menu = glutCreateMenu( menuCallback );
        glutMouseFunc( mouseCallback );
        glutSetMenu( menu );
        glutAddMenuEntry( "create new body here", 1 );
        glutAttachMenu( GLUT_RIGHT_BUTTON );
        
        // callback method for pressing on keys -> keyFunction only responds to
        // pressing down on the escape button
        glutKeyboardFunc( exitCallback );
        
        // add a display callback, constantly updates the positions of the bodies
        glutDisplayFunc( updateGUI );
        
        // run the gui loop
        glutMainLoop();
    }
}