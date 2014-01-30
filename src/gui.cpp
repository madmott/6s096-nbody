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


void starting () {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glFlush();

}

// exit if press the escape button
void keyFunction (unsigned char key, int x, int y) {
    if (key == 27) {
        glutDestroyWindow(1);
        exit (EXIT_SUCCESS);
    }
}

void menuFunction(int value){
 // do something here
    if (value == 1) {
        numBodies ++;
        // mysystem -> makeNewBody(_x, _y);
        
        /* pressed the create new object button
         * system can either declare mass, velocity, acceleration values to be 0
         * OR it could give each one a random value?
         */
    }
}

void drawBody (float new_x, float new_y, float new_z, float mass, float old_x, float old_y, float old_z, float r, float g, float b) {
    
    //std::cout << "trying to do drawBody() \n";
    
    glColor3f(r,g,b);
    glPointSize(mass);
    glBegin(GL_POINTS);
    
    //std::cout << "new x,y,z are: " << new_x << " , "<< new_y << " , " << new_z << "\n";
    glVertex3f(new_x,new_y,new_z); // draw the new point at the old (x,y,z) values
    glEnd();
    glBegin(GL_LINE);
    glVertex3f(old_x,old_y,old_z);
    glVertex3f(new_x, new_y, new_z);
    glEnd();
    
}

void redrawBodies(int button, int state, int x, int y){
    // for body in bodies
    // draw the body
    
    if (button == GLUT_LEFT && state == GLUT_DOWN){
      //  std:: cout << "pressed button\n";
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
   
    glutInitWindowSize (500,500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Practice Window");
    int menu = glutCreateMenu(menuFunction);
    std::cout << "menu is: " << menu << "\n";
    glutSetMenu(menu);
    glutAddMenuEntry("create new object here",1);    
    glutKeyboardFunc(keyFunction);
    glutDisplayFunc(starting);
    
    glutMouseFunc(redrawBodies); //don't need this
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    
    return 0;
}