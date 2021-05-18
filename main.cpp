#include <stdlib.h>
#include <gl/glut.h>
#include <Math.h>
#include <iostream>

void initGL() {
	glClearColor(145 / 255., 216 / 255., 232 / 255., 1.0); // ganti warna background
}

void rgb(float red, float green, float blue){
	glColor3ub(red, green, blue);
}

struct Palet {
    // WARNA HEX CODE (255, 255, 255)
	void merah() {
		rgb(255, 0, 0);
	}
    

};

Palet warna;

// ********** FUNCTION **********






void render(void) {
	glClear(GL_COLOR_BUFFER_BIT); 
    // CODE BELOW
    warna.merah();
	segitiga(0, 450, 300, 0.0, 0.0);


	glFlush();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(10, 10);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Pemandangan Pedesaan");
	gluOrtho2D(-350., 350., -350., 350.);
	glutDisplayFunc(render);
	initGL();
	glutMainLoop();
	return EXIT_SUCCESS;
}
