#include <stdlib.h>
#include <gl/glut.h>
#include <Math.h>
#include <iostream>


void initGL() {
	glClearColor(248 / 255., 168 / 255., 51 / 255., 1.0); // ganti warna background
}

void rgb(float red, float green, float blue) {
	glColor3ub(red, green, blue);
}

struct Palet {
	// WARNA HEX CODE (255, 255, 255)
	void siluet() {
		rgb(39, 39, 39);
	}
	void kuningMatahari() {
		rgb(248, 239, 170);
	}
	void sinarMatahari() {
		rgb(247, 213, 126);
	}
	void sinarMatahari1() {
		rgb(247, 186, 84);
	}
	void abuTua() {
		rgb(88, 89, 91);
	}
	void abuMuda() {
		rgb(155, 142, 133);
	}
	void pink() {
		rgb(242, 70, 128);
	}
	void orange() {
		rgb(248, 168, 51);
	}

};

Palet warna;

// ********** FUNCTION **********
void segitiga(float angle, float l, float t, float posX, float posY) { // TESTING
	l = l / 2;
	glPushMatrix();
	glTranslatef(posX, posY, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
	glVertex2f(-l, 0.);
	glVertex2f(l, 0.);
	glVertex2f(0., t);
	glEnd();
	glPopMatrix();
}

void persegi(float angle, float p, float l, float posX, float posY) {
	glPushMatrix();
	glTranslatef(posX, posY, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex2f(p, l);
	glVertex2f(-p, l);
	glVertex2f(-p, -l);
	glVertex2f(p, -l);
	glEnd();
	glPopMatrix();
}

#define PI 3.1415926f
void lingkaran(float ballRadius, float posX, float posY) {
	glPushMatrix();
	glTranslatef(posX, posY, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0f, 0.0f);
	int numSegments = 100;
	GLfloat angle;
	for (int i = 0; i <= numSegments; i++) {
		angle = i * 2.0f * PI / numSegments;
		glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius);
	}
	glEnd();
	glPopMatrix();
}

void pohon(float scale, float posX, float posY) {
	glPushMatrix();
	glTranslatef(posX, posY, 0.0);
	glScalef(scale, scale, 0.0);

	//batang
	warna.siluet();
	persegi(0, 0.6, 1.55, 0, 0);

	//daun
	warna.siluet();
	segitiga(0, 3.3, 3.3, 0, -0.5);
	segitiga(0, 3.3, 3.3, 0, 0.75);
	segitiga(0, 3.3, 3.3, 0, 2);
	warna.siluet();
	segitiga(0, 3, 3, 0, -0.5);
	segitiga(0, 3, 3, 0, 0.75);
	segitiga(0, 3, 3, 0, 2);

	glPopMatrix();
}


void render(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	// LANGIT ATAS
	glBegin(GL_QUADS);
	warna.orange();
	glVertex2f(-400, 200);
	glVertex2f(400, 200);
	warna.pink();
	glVertex2f(400, 300);
	glVertex2f(-400, 300);
	glEnd();

	// GUNUNG KIRI BELAKANG
	warna.abuMuda();
	segitiga(0, 500, 120, -350, -80);

	// GUNUNG KANAN BELAKANG
	warna.abuMuda();
	segitiga(0, 500, 130, 350, -80);

	// GUNUNG KIRI
	warna.abuTua();
	segitiga(0, 420, 190, -400, -100);

	// GUNUNG KANAN
	warna.abuTua();
	segitiga(0, 420, 200, 400, -100);

	// MATAHARI
	warna.sinarMatahari1();
	lingkaran(210, 0, -20);
	warna.sinarMatahari();
	lingkaran(190, 0, -20);
	warna.kuningMatahari();
	lingkaran(180, 0, -20);

	// PERBUKITAN
	warna.siluet();
	lingkaran(700, -400, -750);
	lingkaran(700, 400, -750);

	// PEPOHONAN KIRI
	warna.siluet();
	segitiga(0, 40, 80, -380, -80);
	segitiga(0, 50, 100, -350, -70);
	segitiga(0, 35, 70, -300, -100);
	pohon(10, -240, -55);
	segitiga(0, 40, 80, -195, -105);
	segitiga(0, 30, 60, -175, -105);
	pohon(7, -130, -95);
	segitiga(0, 40, 80, -90, -150);
	segitiga(0, 30, 60, -70, -160);
	segitiga(0, 25, 50, -40, -180);

	// PEPOHONAN KANAN
	warna.siluet();
	pohon(15, 380, -30);
	segitiga(0, 50, 100, 320, -80);
	segitiga(0, 35, 70, 295, -80);
	pohon(10, 250, -55);
	segitiga(0, 30, 60, 215, -90);
	segitiga(0, 20, 40, 200, -90);
	segitiga(0, 20, 40, 170, -110);
	pohon(8, 145, -88);
	segitiga(0, 30, 60, 110, -130);
	segitiga(0, 20, 40, 95, -130);
	segitiga(0, 20, 40, 70, -150);
	segitiga(0, 20, 40, 40, -165);

	glFlush();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600); // 700, 700
	glutInitWindowPosition(10, 10);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Sunset Illustration");
	gluOrtho2D(-400., 400., -300., 300.); // 350, 350
	glutDisplayFunc(render);
	initGL();
	glutMainLoop();
	return EXIT_SUCCESS;
}
