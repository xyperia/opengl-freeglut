#include <gl/glut.h>
#include <stdio.h>
#include "res/lib/imageloader.h"
#include "res/lib/object.h"

// GL_LINEAR
int xray = 0, lighting = 1, zoomInMax = 50, zoomOutMax = 5, currZoom = 30, strafeMax = 50, currStrafe = 30, paneMax = 30, currPane = 15;
float xrot = 0.0f, yrot = 0.0f, xdiff = 0.0f, ydiff = 0.0f, xpos = 0.0f, ypos = 0.0f, zpos = 0.0f;
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
_textureId15;

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return textureId;
}

void initRendering() {
	glClearColor(0.9f, 0.9f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GLUT_MULTISAMPLE);

	// TEXTURE LOADING
	Image* image = loadBMP("res/img/ground.bmp");
	_textureId = loadTexture(image);
	delete image;

	image = loadBMP("res/img/sky.bmp");
	_textureId2 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/roof.bmp");
	_textureId3 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/door.bmp");
	_textureId4 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/crossbg.bmp");
	_textureId5 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/fntower.bmp");
	_textureId6 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/lrtower.bmp");
	_textureId7 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/window.bmp");
	_textureId8 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/smallwindow.bmp");
	_textureId9 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/author.bmp");
	_textureId10 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/wall.bmp");
	_textureId11 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/floor.bmp");
	_textureId12 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/title.bmp");
	_textureId13 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/wood.bmp");
	_textureId14 = loadTexture(image);
	delete image;

	image = loadBMP("res/img/groundN.bmp");
	_textureId15 = loadTexture(image);
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
		glBindTexture(GL_TEXTURE_2D, _textureId15);
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

void footer()
{
	// AUTHOR
	// 672016143, 672016064, 672016195
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId10);
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
	
	header();

	// TEXT
	char maxLength[25] = { 0 };
	sprintf_s(maxLength, "GPIB Taman Sari Salatiga");

	if (lighting == 1) {
		glDisable(GL_LIGHTING);
		glColor3ub(255, 255, 255);
		renderBitmap(-20.0f, 85.0f, 15.0f, GLUT_BITMAP_HELVETICA_18, maxLength);
		glEnable(GL_LIGHTING);
	}
	else {
		renderBitmap(-20.0f, 85.0f, 15.0f, GLUT_BITMAP_HELVETICA_18, maxLength);
	}

	// HALF CIRCLE UPSIDE MAIN DOOR
	glColor3ub(43, 46, 79);
	drawCircle(51.0f, 8);
	glRotatef(-270.0f, 0, 0, 1);

	// XRAY FOR INTERIOR VIEW
	if (xray == 0) {
		
		glColor3ub(255, 237, 189);
		atapH(0, 50.0f, 0, 50.0f, 110.0f, 50.0f, _textureId3, _textureId12, _textureId14);
		glColor3ub(255, 237, 189);
		atapV(0, 27.5f, 25.0f, 50.0f, 25.0f, _textureId3, _textureId11, _textureId14);

		// Menara
		glColor3ub(64, 68, 99);
		centeredRect(0, 30.0f, 44.8f, 10.0f, 10.0f, 20.0f, _textureId11);

		// Sisi Z ( Salib )
		float zPos = 49.9f;
		for (int i = 0; i < 2; i++) {
			glColor3ub(255, 255, 255);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, _textureId6);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glBegin(GL_QUADS);
			glTexCoord2f(0.f, 0.f); glVertex3f(-5.0f, 23.0f, zPos);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 23.0f, zPos);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 40.0f, zPos);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f, 40.0f, zPos);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			zPos -= 10.2f;
		}

		// Sisi X ( Biasa )
		float xPos = -5.1f;
		for (int i = 0; i < 2; i++) {
			glColor3ub(255, 255, 255);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, _textureId7);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glBegin(GL_QUADS);
			glTexCoord2f(0.f, 0.f); glVertex3f(xPos, 23.0f, 39.7f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(xPos, 23.0f, 49.9f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(xPos, 40.0f, 49.9f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(xPos, 40.0f, 39.7f);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			xPos += 10.2f;
		}

		// Atap Menara
		glColor3ub(255, 237, 189);
		prism(0, 65.0f, 45.0f, 17.0f, 50.0f, _textureId3);
		prism(0, 70.5f, 45.0f, 9.0f, 70.0f, _textureId3);

	} // PENUTUP XRAY

	// MAIN ROOM
	centeredRect(0, 0, 0, 50.0f, 110.0f, 50.0f, _textureId11);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId5);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.f, 0.f); glVertex3f(-55.0f, -25.0f, 25.0f);
	glTexCoord2f(1.f, 0.f); glVertex3f(-55.0f, -25.0f, -25.0);
	glTexCoord2f(1.f, 1.f); glVertex3f(-55.0f, 25.0f, -25.0);
	glTexCoord2f(0.f, 1.f); glVertex3f(-54.9f, 25.0f, 25.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	// INSIDE PODIUM
	glColor3ub(255, 255, 255);
	texturedBlock(-42.0f, -22.4f, 0, 49.9f, 25.0f, 5.0f, _textureId14);

	glColor3ub(68, 0, 99);
	block(-35.0f, -16.0f, 0, 6.0f, 6.0f, 12.5f);

	glColor3ub(255, 255, 255);
	glLineWidth(10.0f);
	glBegin(GL_LINES);
	glVertex3f(-31.9f, -12.5f, 1.75f);
	glVertex3f(-31.9f, -12.5f, -1.75f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-31.9f, -11.0f, 0);
	glVertex3f(-31.9f, -17.5f, 0);
	glEnd();

	// CONGREGATION SEAT
	temp = -15.0f;
	for (int i = 0; i < 7; i++) {
		kursiJemaat(temp, -20.0f, -12.0f, 15.0f);
		temp += 10.0f;
	}

	temp = -15.0f;
	for (int i = 0; i < 7; i++) {
		kursiJemaat(temp, -20.0f, 10.0f, 15.0f);
		temp += 10.0f;
	}

	// FRONT FACING WINDOWS
	glColor3ub(255, 237, 189);

	temp = 25.1f;
	for (int i = 0; i < 2; i++) {
		jendelaLR(-40.0f, -12.5f, temp, _textureId8);
		jendelaLR(-32.5f, -12.5f, temp, _textureId8);
		jendelaLR(25.0f, -12.5f, temp, _textureId8);
		jendelaLR(33.0f, -12.5f, temp, _textureId8);
		temp = 24.9f;
	}

	temp = -20.1f;
	temp2 = 20.1f;
	for (int i = 0; i < 2; i++) {
		jendelaFN(temp, -12.5f, 30.0f, _textureId9);
		jendelaFN(temp, -12.5f, 36.0f, _textureId9);
		jendelaFN(temp2, -12.5f, 30.0f, _textureId9);
		jendelaFN(temp2, -12.5f, 36.0f, _textureId9);

		temp = -19.9f;
		temp2 = 19.9f;
	}

	// BACK FACING WINDOWS
	float windowPos = -40.0f;
	for (int i = 0; i < 5; i++) {
		jendelaLR(windowPos, -12.5f, -25.1f, _textureId8);
		windowPos += 18.0;
	}

	windowPos = -40.0f;
	for (int i = 0; i < 5; i++) {
		jendelaLR(windowPos, -12.5f, -24.9f, _textureId8);
		windowPos += 18.0;
	}

	// FRONT ROOM
	glColor3ub(255, 237, 189);
	centeredRect(0, -5.0f, 37.51f, 25.0f, 40.0f, 40.0f, _textureId11);

	// CANOPY ( ARC TYPE )
	glColor3ub(27, 30, 51);
	drawArc(51.0f, 16, 20);
	glRotatef(-90.0f, 0, 0, 1);

	// FRONT WALL REGION
	glColor3ub(27, 30, 51);
	drawArc(51.0f, 12, 1);
	glRotatef(-90.0f, 0, 0, 1);

	// MAIN PILLAR
	glColor3ub(255, 255, 255);
	texturedBlock(-55.0f, 0.0f, 25.0f, 2.0f, 2.0f, 50.0f, _textureId14);
	texturedBlock(55.0f, 0.0f, 25.0f, 2.0f, 2.0f, 50.0f, _textureId14);
	texturedBlock(55.0f, 0.0f, -25.0f, 2.0f, 2.0f, 50.0f, _textureId14);
	texturedBlock(-55.0f, 0.0f, -25.0f, 2.0f, 2.0f, 50.0f, _textureId14);

	// FRONT PILLAR
	// OUTER PILLAR
	glColor3ub(255, 255, 255);
	texturedBlock(-20.0f, -5.0f, 50.0f, 3.0f, 3.0f, 40.0f, _textureId14);
	texturedBlock(20.0f, -5.0f, 50.0f, 3.0f, 3.0f, 40.0f, _textureId14);

	// INSIDE PILLAR
	glColor3ub(27, 30, 51);
	block(-12.0f, -13.25f, 50.5f, 4.0f, 2.5f, 23.5f);
	block(12.0f, -13.25f, 50.5f, 4.0f, 2.5f, 23.5f);

	// INSIDE DOOR
	glColor3ub(255, 255, 255);
	temp = 26.0f;
	for (int i = 0; i < 2; i++) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureId4);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-8.0f, -25.0f, temp);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(8.0f, -25.0f, temp);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(8.0f, -1.0f, temp);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-8.0f, -1.0f, temp);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		temp -= 2.0f;
	}

	// OUTSIDE DOOR
	glColor3ub(255, 255, 255);
	temp = 51.0f;
	for (int i = 0; i < 2; i++) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureId4);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_QUADS);
		glTexCoord2f(0.f, 0.f); glVertex3f(-8.0f, -25.0f, temp);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(8.0f, -25.0f, temp);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(8.0f, -1.0f, temp);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-8.0f, -1.0f, temp);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		temp -= 2.0f;
	}

	glTranslatef(55.0f, 0.0f, 50.0f);
	glRotatef(-35.0f, 0.0f, 1.0f, 0.0f);
	title(30.0f, -10.0f, 70.0f, 2.0f, 30.0f, 15.0f, _textureId13, _textureId14, _textureId12);
	glRotatef(35.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-55.0f, 0.0f, -50.0f);
}

void timer(int t) {
	if (!mouseDown && isIdle == true)
	{
		yrot += 0.025f;
	}
	glutPostRedisplay();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(xpos, ypos, zpos);
	glutTimerFunc(10, timer, 0);

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
	gluLookAt(20.0f, -8.0f, 60.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
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

	case '1':
		if (isIdle == true) {
			isIdle = false;
		}
		else {
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
	glutCreateWindow("GPIB TAMAN SARI SALATIGA");
	initRendering();
	glutDisplayFunc(display);
	glutReshapeFunc(ukuran);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(keyBind);
	glutMainLoop();
	return 0;
}