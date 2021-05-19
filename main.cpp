#include <stdlib.h>
#include <iostream>
#include <gl/glut.h>
#include <Math.h>

void initGL() {
	glClearColor(248 / 255., 168 / 255., 51 / 255., 1.0); // Background
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
	void cokelat() {
		rgb(138, 125, 78);
	}
	void putih() {
		rgb(255, 255, 255);
	}
};

Palet warna;

// ********** FUNCTION **********
void segitiga(float sudut, float l, float t, float xPos, float yPos) { // TESTING
	l = l / 2;
	glPushMatrix();
	glTranslatef(xPos, yPos, 0.0f);
	glRotatef(sudut, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
	glVertex2f(-l, 0.);
	glVertex2f(l, 0.);
	glVertex2f(0., t);
	glEnd();
	glPopMatrix();
}

void persegi(float sudut, float p, float l, float xPos, float yPos) {
	glPushMatrix();
	glTranslatef(xPos, yPos, 0.0f);
	glRotatef(sudut, 0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex2f(p, l);
	glVertex2f(-p, l);
	glVertex2f(-p, -l);
	glVertex2f(p, -l);
	glEnd();
	glPopMatrix();
}

#define PI 3.1415926f
void lingkaran(float radius, float xPos, float yPos) {
	glPushMatrix();
	glTranslatef(xPos, yPos, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0f, 0.0f);
	int numSegment = 100;
	GLfloat sudut;
	for (int i = 0; i <= numSegment; i++) {
		sudut = i * 2.0f * PI / numSegment;
		glVertex2f(cos(sudut) * radius, sin(sudut) * radius);
	}
	glEnd();
	glPopMatrix();
}

void pohon(float scale, float xPos, float yPos) {
	glPushMatrix();
	glTranslatef(xPos, yPos, 0.0);
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

	// BURUNG
	glLineWidth(4);
	glBegin(GL_LINE_STRIP); 
	warna.cokelat();
	glVertex2f(-40, 100);
	glVertex2f(-30, 110);
	warna.putih();
	glVertex2f(-20, 100);
	glVertex2f(-30, 100);
	warna.cokelat();
	glVertex2f(-20, 110);
	glVertex2f(-10, 100);
	glEnd();

	glBegin(GL_LINE_STRIP); 
	warna.cokelat();
	glVertex2f(60, 60);
	glVertex2f(70, 70);
	warna.putih();
	glVertex2f(80, 60);
	glVertex2f(70, 60);
	warna.cokelat();
	glVertex2f(80, 70);
	glVertex2f(90, 60);
	glEnd();

	glBegin(GL_LINE_STRIP); 
	warna.cokelat();
	glVertex2f(110, 50);
	glVertex2f(120, 60);
	warna.putih();
	glVertex2f(130, 50);
	glVertex2f(120, 50);
	warna.cokelat();
	glVertex2f(130, 60);
	glVertex2f(140, 50);
	glEnd();

	glBegin(GL_LINE_STRIP);
	warna.cokelat();
	glVertex2f(30, 90);
	glVertex2f(40, 100);
	warna.putih();
	glVertex2f(50, 90);
	glVertex2f(40, 90);
	warna.cokelat();
	glVertex2f(50, 100);
	glVertex2f(60, 90);
	glEnd();

	glBegin(GL_LINE_STRIP);
	warna.cokelat();
	glVertex2f(100, 100);      
	glVertex2f(110, 110);
	warna.putih();
	glVertex2f(120, 100);
	glVertex2f(110, 100);
	warna.cokelat();
	glVertex2f(120, 110);
	glVertex2f(130, 100);
	glEnd();

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
	pohon(7, -130, -97);
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
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(50, 50);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Sunset Art");
	gluOrtho2D(-400., 400., -300., 300.);
	glutDisplayFunc(render);
	initGL();
	glutMainLoop();
	return EXIT_SUCCESS;
}
