#include <View.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <vector>
#include <System.h>
#include <Body.h>
#include <Color.h>

namespace nbody {
    
    
    // exit the program if press the escape button
    void View::exitCallback (unsigned char key, int x, int y) {
        if (key == 27) {
            glutDestroyWindow(1);
            exit (EXIT_SUCCESS);
        }
    }
    
    // if press the new object dropdown from the menu button, add a new body given the current mouse coordinates [the new object's position] to the system
    
    void View:: menuCallback(int value){
        // do something here
        if (value == 1) {
            mysystem -> addBody(_xposition, _yposition);
        }
    }
    
    // draw a body at its correct position in the correct color
    void View::drawBody (Vector3<float> position, Color color) {
        glPointSize(1.0); // all bodies will be the same size
        glColor3f(color.r(), color.g(), color.b()); // set the color
        
        glBegin(GL_POINTS); // draw the new point
        glVertex3f(position.x(), position.y(), position.z());
        glEnd();
    }
    
    // the display callback; for each body in the System's bodies, draw the body (after one time step)
    void View::updateGUI(){
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // just draw new
        
        
        std::<vector> Body bodies = System.getBodies();
        for (int i = 0; i < bodies.size(); i++) {
            drawBody(bodies[i].position(), bodies[i].color());
        }
        
        glutSwapBuffers();
        
        glFlush();
        glutPostRedisplay();
    }
    
    
    // gets the position of the mouse for when a user presses right click
    // (which generates the menu for generating a new body)
    void View::mouseCallback (int button, int state, int x, int y) {
        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
            // want to know this x and y position
            _xposition = (x-250.0)/250.0;
            _yposition = (y-250.0)/250.0;
            //     std :: cout << " new position is now: " << _x << " " << _y << " \n";
        }
    }

    
    void View:: initializer () {
        glutInit(&argc,argv);
        glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
        
        // generate a new window called "N-body Simulation" with a size of 500X500
        glutInitWindowSize (500,500);
        glutInitWindowPosition (100, 100);
        glutCreateWindow ("N-Body Simulation");
        
        // create a dropdown menu [which you get by right-clicking], so if you then
        //click on the entry "create new object here", it generates a new object
        int menu = glutCreateMenu(menuFunction);
        glutMouseFunc(mouseCallback);
        glutSetMenu(menu);
        glutAddMenuEntry("create new body here",1);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        
        // callback method for pressing on keys -> keyFunction only responds to
        // pressing down on the escape button
        glutKeyboardFunc(keyFunction);
        
        // add a display callback, constantly updates the positions of the bodies
        glutDisplayFunc(updateGUI);
        
        // run the gui loop
        glutMainLoop();
    }
}