//  introOpenGL.cpp
//  Creado por Andrea Rueda, 01/2018
//

#include <GL/freeglut.h>
#include <GL/gl.h>


void myInit (void) {
    
    glClearColor(1.0,1.0,1.0,1.0); 
    
    glMatrixMode(GL_PROJECTION); 
    
    glLoadIdentity(); 
    
    gluOrtho2D(0, 640, 0, 480);
    //glOrtho(0, 640, 0, 480, 1.0, -1.0);
    
}


void myDisplay (void) {
    
    glClear(GL_COLOR_BUFFER_BIT); 
    
    glColor3f(1.0, 0.0, 0.0); 
    
    glBegin(GL_LINES); 
    
        glVertex2i(600,15); 
    
        glVertex2i(10,345); 
    
    glEnd(); 
    
    glFlush(); 
    
}


void myResize (int w, int h) {
    
    glViewport(0, 0, w, h); 
    
    glMatrixMode(GL_PROJECTION); 

    glLoadIdentity();
    
    gluOrtho2D(0, w, 0, h);
    
}


int main (int argc, char** argv) {
    
    glutInit(&argc, argv); 
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    
    glutInitWindowSize(640, 480); 
    
    glutInitWindowPosition(100, 100); 

    glutCreateWindow("Graphics Window");  
    
    glutDisplayFunc(myDisplay); 
    
    glutReshapeFunc(myResize); 
    
    myInit(); 
    
    glutMainLoop(); 
    
    return 0;

}