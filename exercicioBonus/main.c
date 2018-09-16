//CLODOALDO BASAGLIA DA FONSECA
//RA: 968692

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

int rotacao = 0;
int translacao = 1;

float tx = 0;
float ty = 0;

int rx = 5;
int ry = 5;

int angulo = 0;

void desenhaQuadrad() {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(10, 0);
    glVertex2i(10, 10);
    glVertex2i(0, 10);
    glEnd();
}

void selectedKey(unsigned char key, int x, int y) {
    switch(key) {
    case 't':
        translacao =1 ;
        rotacao = 0;
        break;
    case 'r':
        rotacao = 1 ;
        translacao = 0;
        break;
    }
    glutPostRedisplay();
}

void selectedDirection(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        if (translation == 1) {
            tx--;
            break;
        }
        if (rotation == 1) {
            angulo ++ ;
            break;
        }
        break;

    case GLUT_KEY_RIGHT:
        if (translation == 1) {
            tx++;
            break;
        }
        if (rotation == 1) {
            angulo --;

            break;
        }
        break;

    case GLUT_KEY_UP:
        if (translation == 1) {
            ty++;
            break;
        }
        if (rotation == 1) {
            break;
        }

    case GLUT_KEY_DOWN:
        if (translation == 1) {
            ty--;
            break;
        }
        if (rotation == 1) {
            break;
        }
    }
    glutPostRedisplay();
}

int init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(tx, ty, 0);

    glTranslatef(rx,ry,0);
    glRotatef(angulo,0,0,1);
    glTranslatef(-(rx),-(ry),0);
    drawSquare();


    glFlush();
}

int main() {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bonus 1");

    init();

    glutDisplayFunc(display);

    glutKeyboardFunc(selectedKey);
    glutSpecialFunc(selectedDirection);


    glutMainLoop();
    rx = tx + 5;
    ry = ty + 5;

    return 0;
}
