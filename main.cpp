/*
#include <GL/gl.h>
#include <GL/glu.h>
*/

#include <GL/glut.h>
#include "ship.h"

void init();
void display();
void reshape(int width, int height);
void timer(int t);
void drawShip();

Ship player(5.0, 5.0, 0);

int main(int argc, char**argv) {
  glutInit(&argc, argv); 
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  
  glutInitWindowPosition(200, 100); 
  glutInitWindowSize(1000, 1000); 
  glutCreateWindow("Asteroids");
  
  glutDisplayFunc(display); 
  glutReshapeFunc(reshape);
  glutTimerFunc(1000, timer, 0);
  
  init();
  glutMainLoop();

  return 0;
}

void init() {
  glClearColor(0.1, 0.1, 0.1, 1.0); 
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glPointSize(100);
  drawShip(); 
  glutSwapBuffers();
}

void reshape(int width, int height) {
  glViewport(0, 0, (GLsizei)width, (GLsizei)height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity(); 
  gluOrtho2D(0, 10, 0, 10);
  glMatrixMode(GL_MODELVIEW);
}

void timer(int t) {
  glutPostRedisplay();
  glutTimerFunc(1000/60, timer, 0);
}

void drawShip() {
  glTranslatef(player.x, player.y, 0);
  glBegin(GL_TRIANGLES);
  glColor3f(1.0,1.0,1.0);
  glVertex2f(-0.25, 0.3);
  glVertex2f(-0.25, -0.3);
  glVertex2f(0.5,0);
  glEnd();
}


