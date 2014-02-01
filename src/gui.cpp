// gui stuff

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <vector>
#include <System.h>

float rando = 0.0f;
int numBodies = 0;

//nbody::System *mysystem = new nbody::System{1};


// need a display callback.. this function does nothing [for now]
void starting () {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glFlush();

}

// exit the program if press the escape button
void keyFunction (unsigned char key, int x, int y) {
    if (key == 27) {
        glutDestroyWindow(1);
        exit (EXIT_SUCCESS);
    }
}

// if press the new object dropdown from the menu button, increase numBodies
// by one -> later on, will have the system create a new body given the mouse
// coordinates [the object's position]

void menuFunction(int value){
 // do something here
    if (value == 1) {
        numBodies ++;
        // mysystem -> makeNewBody(_x, _y);
    }
}

void drawBody (float new_x, float new_y, float new_z, float mass, float old_x, float old_y, float old_z, float r, float g, float b) {
    
    //std::cout << "trying to do drawBody() \n";
    
    glColor3f(r,g,b); // set color to the color of that object
    glPointSize(mass); // set size to the size of that object
    
    glBegin(GL_POINTS); // draw the new point
    glVertex3f(new_x,new_y,new_z);
    glEnd();
    
    glBegin(GL_LINE); // draw a line from the old point to the new one
    glVertex3f(old_x,old_y,old_z);
    glVertex3f(new_x, new_y, new_z);
    glEnd();
    
}

// in future -> for each body in the System's bodies, draw the body (after one time step)
void redrawBodies(int button, int state, int x, int y){
    
    // for now: just have each body move a little bit to the right whenever we click
    if (button == GLUT_LEFT && state == GLUT_DOWN){
    
        if (numBodies > 0) {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            for (int i = 1; i <= numBodies; i++){
                drawBody ((i*rando)+.01, 0.0f,0.0f,5.0f,(i*rando),0.0f,0.0f, 0.0, 0.0, 1.0);
            }
            glutSwapBuffers();
            
            glFlush();
            glutPostRedisplay();
            rando += .01;
        }
    }
}

int main(int argc, char * argv[])
{ 
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    
    // generate a new window called "practice window" with a size of 500X500
    glutInitWindowSize (500,500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Practice Window");
    
    // create a dropdown menu [which you get by right-clicking], so if you then
    //click on the entry "create new object here", it generates a new object
    int menu = glutCreateMenu(menuFunction);
    glutSetMenu(menu);
    glutAddMenuEntry("create new object here",1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    // add a callback method for pressing on keys -> keyFunction only responds to
    // pressing down on the escape button
    glutKeyboardFunc(keyFunction);
    
    // add a display callback that does nothing
    glutDisplayFunc(starting);
    
    // add a callback method for clicking on the mouse (currently, just make the
    // objects move to the right)
    glutMouseFunc(redrawBodies); //don't need this later on
    
    // run the gui loop
    glutMainLoop();
    return 0;
}