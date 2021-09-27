#include <gl/glut.h>
#include <stdio.h>
#include "res/lib/imageloader.h"
#include "res/lib/object.h"

// VARIABLE
int xray = 0, lighting = 1, zoomInMax = 50, zoomOutMax = 5, currZoom = 30, strafeMax = 50, currStrafe = 30, paneMax = 30, currPane = 15;
float xrot = 0.0f, yrot = 0.0f, xdiff = 0.0f, ydiff = 0.0f, xpos = 0.0f, ypos = 0.0f, zpos = 0.0f, initialYPos = 23.0f, currentYPos = initialYPos, atapVHeight = 45.0f;
bool isIdle = true, mouseDown = false, isDepth = false;

// TEMPORARY STORAGE
float temp, temp2;

// LIGHTING MATERIAL
GLfloat light_position[] = { 1.0f, 1.0f, 1.0f, 0.0f };
GLfloat light_ambient_color[] = { 0.4f, 0.4f, 0.4f, 1.0f };
GLfloat light_diffuse_color[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat qaBlack[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat qaGreen[] = { 0.0f, 1.0f, 0.0f, 1.0f };
GLfloat qaWhite[] = { 1.0f, 1.0f, 1.0f, 1.0f };

GLuint // TEXTURE DEFINITION
_textureId,
_textureId2,
_textureId3,
_textureId4,
_textureId5,
_textureId6,
_textureId7,
_textureId8,
_textureId9,
_textureId10,
_textureId11,
_textureId12,
_textureId13,
_textureId14,
_textureId15,
_textureId16,
_textureId17;

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return textureId;
}

void footer()
{
	// AUTHOR
	// 672016143, 672016064, 672016195
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-200.0f, -25.2f, 200.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(200.0f, -25.2f, 200.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(200.0f, -25.2f, -200.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-200.0f, -25.2f, -200.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void initRendering() {
	glClearColor(0.9f, 0.9f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);	
	glEnable(GLUT_MULTISAMPLE);
	glShadeModel(GL_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	// TEXTURE LOADING
	Image* image = loadBMP("res/img/ground.bmp");
	_textureId = loadTexture(image);
	delete image;

	image = loadBMP("res/img/sky.bmp");
	_textureId2 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/author.bmp");
	_textureId3 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/frontmain.bmp");
	_textureId4 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/sampinglayer.bmp");
	_textureId5 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/wood.bmp");
	_textureId6 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/floor.bmp");
	_textureId7 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/roof.bmp");
	_textureId8 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/panel.bmp");
	_textureId9 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/triangle.bmp");
	_textureId10 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/UkiranAtap.bmp");
	_textureId11 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/UkiranAtap.bmp");
	_textureId11 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/crossLR.bmp");
	_textureId12 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/crossUD.bmp");
	_textureId13 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/door.bmp");
	_textureId14 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/bed.bmp");
	_textureId15 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/title.bmp");
	_textureId16 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/groundN.bmp");
	_textureId17 = loadTexture(image);
	delete image;
}

void header()
{
	// GROUND ( RUMPUT )
	glEnable(GL_TEXTURE_2D);
	if (lighting == 1) {
		glBindTexture(GL_TEXTURE_2D, _textureId);
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D, _textureId17);
	}
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-200.0f, -25.1f, 200.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(200.0f, -25.1f, 200.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(200.0f, -25.1f, -200.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-200.0f, -25.1f, -200.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void view()
{

	if (isDepth == false) {
		glEnable(GL_DEPTH_TEST);
		// Author
		footer();
	}
	else {
		glDisable(GL_DEPTH_TEST);
	}

	// Ground
	header();

	// Ruang Utama
	centeredTrap(0.0f, -4.4f, 0.0f, 60.0, 30.0f, 15.0f, _textureId4, _textureId5, _textureId7, _textureId14);

	// Kaki BEGIN!
	// Tengah
	centeredRect(0.0f, -18.5f, 6.0f, 4.0f, 4.0f, 13.0f, _textureId6);
	centeredRect(0.0f, -18.5f, -6.0f, 4.0f, 4.0f, 13.0f, _textureId6);

	// Depan
	temp = -13.5f;
	for (int i = 0; i < 2; i++) {
		for (int i = 0; i < 3; i++) {
			centeredRect(temp, -18.5f, 28.5f, 2.5f, 2.5f, 13.0f, _textureId6);
			temp += 4.0f;
		}
		temp = 5.5f;
	}

	// Kiri
	temp = -13.5f;
	temp2 = 28.5f;
	for (int i = 0; i < 10; i++) {
		centeredRect(temp, -18.5f, temp2, 2.5f, 2.5f, 13.0f, _textureId6);
		temp2 -= 6.35f;
	}
	centeredRect(-13.5f, -21.0f, 0.0f, 59.0f, 2.5f, 2.5f, _textureId6);
	centeredRect(-13.5f, -15.0f, 0.0f, 59.0f, 2.5f, 2.5f, _textureId6);

	// Kanan
	temp = 13.5f;
	temp2 = 28.5f;
	for (int i = 0; i < 10; i++) {
		centeredRect(temp, -18.5f, temp2, 2.5f, 2.5f, 13.0f, _textureId6);
		temp2 -= 6.35f;
	}
	centeredRect(13.5f, -21.0f, 0.0f, 59.0f, 2.5f, 2.5f, _textureId6);
	centeredRect(13.5f, -15.0f, 0.0f, 59.0f, 2.5f, 2.5f, _textureId6);

	// Belakang
	temp = -13.5f;
	for (int i = 0; i < 6; i++) {
		centeredRect(temp, -18.5f, -28.5f, 2.5f, 2.5f, 13.0f, _textureId6);
		temp += 5.5f;
	}
	centeredRect(0.0f, -21.0f, -28.5f, 2.5f, 25.0f, 2.5f, _textureId6);
	centeredRect(0.0f, -15.0f, -28.5, 2.5f, 25.0f, 2.5f, _textureId6);
	// Kaki END!

	// Tangga BEGIN!
	temp = -24.5f; // Y
	temp2 = 28.5f; // Z
	for (int i = 0; i < 7; i++) {
		centeredRect(0.0f, temp, temp2, 3.0f, 8.0f, 1.0f, _textureId6);
		temp += 2.0f;
		temp2 -= 2.0f;
	}

	glRotatef(45.0f, 1.0f, 0.0f, 0.0f); glTranslatef(0.0f, 22.5f, 0.0f);
	centeredRect(-4.0f, -21.0f, 28.0f, 17.0f, 1.5f, 1.5f, _textureId6);
	centeredRect(4.0f, -21.0f, 28.0f, 17.0f, 1.5f, 1.5f, _textureId6);
	glTranslatef(0.0f, -22.5f, 0.0f);  glRotatef(-45.0f, 1.0f, 0.0f, 0.0f);
	// Tangga END!

	// Atap BEGIN!
	glColor3ub(255, 255, 255);
	atapV(0.0f, currentYPos, 0.0f, 66.0f, 40.0f, atapVHeight, _textureId8, _textureId9, _textureId10, _textureId11, _textureId12, _textureId13);
	// Atap END!

	// Furniture
	kursiJemaat(12.5f, -8.5f, 20.0f, 10.0f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	kursiJemaat(12.5f, -8.5f, -20.0f, 10.0f);
	glRotatef(-180.0f, 0.0f, 1.0f, 0.0f);

	bed(0.0f, -10.3f, -22.0f, 15.0f, 10.0f, 3.0f, _textureId15, _textureId6);
	meja(-10.0f, -6.5f, -3.0f, 4.0f, 6.0f, 5.0f);
	kursi(-10.0f, -8.5f, -5.0f, 4.0f, 4.0f, 3.0f);

	glTranslatef(55.0f, 0.0f, 20.0f);
	glRotatef(-35.0f, 0.0f, 1.0f, 0.0f);
	title(30.0f, -10.0f, 70.0f, 2.0f, 30.0f, 15.0f, _textureId16, _textureId6, _textureId7);
	glRotatef(35.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-55.0f, 0.0f, -20.0f);
}

void timer(int t) {
	if (!mouseDown && isIdle == true)
	{
		yrot += 0.01f;
	}
	glutPostRedisplay();
}

void animationTimer(int t) {
	if (xray == 1) {
		if (currentYPos < 150.0f) {
			currentYPos++;
			atapVHeight++;
		}
	}
	else {
		if (currentYPos > initialYPos) {
			currentYPos--;
			atapVHeight--;
		}
	}
	glutPostRedisplay();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(xpos, ypos, zpos);
	glutTimerFunc(10, timer, 0);
	glutTimerFunc(10, animationTimer, 0);
	// FIXED BACKGROUND
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.f, 0.f); glVertex3f(-300.0f, -300.0f, -200.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(300.0f, -300.0f, -200.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(300.0f, 300.0f, -200.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-300.0f, 300.0f, -200.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	if (lighting == 1) {
		// DIFFUSE LIGHTING
		glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient_color);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse_color);

		// SPOTLIGHT LIGHTING
		glMaterialfv(GL_FRONT, GL_AMBIENT, qaGreen);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaGreen);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
		glMaterialf(GL_FRONT, GL_SHININESS, 60.0);
	}
	else {
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
	}
	gluLookAt(15.0f, -5.0f, 60.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	view();
	glFlush();
	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
	if (button == 3)
	{
		if (currZoom >= zoomInMax) {
			currZoom = zoomInMax;
		}
		else {
			if (state == GLUT_UP) return;
			zpos += 5.0;
			glTranslatef(0.0, 0.0, 5.0);
			display();
			currZoom++;
		}
	}
	else if (button == 4) {
		if (currZoom <= zoomOutMax) {
			currZoom = zoomOutMax;
		}
		else {
			zpos += -5.0;
			glTranslatef(0.0, 0.0, -5.0);
			display();
			currZoom--;
		}
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		if (xray == 0) {
			xray = 1;
			
		}
		else {
			xray = 0;
		}
		display();
	}
	else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
		if (lighting == 1) {
			lighting = 0;
		}
		else {
			lighting = 1;
		}
		display();
	}
	else {
		mouseDown = false;
	}
}

void mouseMotion(int x, int y)
{
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;
		glutPostRedisplay();
	}
}

void keyBind(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'q':
	case 'Q':
		exit(0);
		break;
	case 'w':
	case 'W':
		if (currPane >= paneMax) {
			currPane = paneMax;
		}
		else {
			ypos += -5.0;
			display();
			currPane++;
		}
		break;

	case 's':
	case 'S':
		if (currPane <= 0) {
			currPane = 0;
		}
		else {
			ypos += 5.0;
			display();
			currPane--;
		}
		break;

	case 'a':
	case 'A':
		if (currStrafe <= 0) {
			currStrafe = 0;
		}
		else {
			xpos += 5.0;
			display();
			currStrafe--;
		}
		break;

	case 'd':
	case 'D':
		if (currStrafe >= strafeMax) {
			currStrafe = strafeMax;
		}
		else {
			xpos += -5.0;
			display();
			currStrafe++;
		}
		break;

	case '1':
		if (isIdle == true) {
			isIdle = false;
		}
		else
		{
			isIdle = true;
		}
		display();
		break;

	case 'e':
	case 'E':
		if (isDepth == true) {
			isDepth = false;
		}
		else
		{
			isDepth = true;
		}
		display();
		break;
	}
}

void ukuran(int lebar, int tinggi)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, lebar, tinggi);
	gluPerspective(35.0, lebar / tinggi, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutInitWindowSize(900, 700);
	glutInitWindowPosition(210, 30);
	glutCreateWindow("672016143 - 672016064 - 672016195");
	initRendering();
	glutDisplayFunc(display);
	glutReshapeFunc(ukuran);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(keyBind);
	glutMainLoop();
	return 0;
}