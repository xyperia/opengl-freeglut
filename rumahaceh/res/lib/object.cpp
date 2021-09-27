// OBJECT LIBRARY
// 672016143, 672016064, 672016195

#include <gl/glut.h>
#include "imageloader.h"
#include <math.h>

double PI = 3.14159265359;
float temp3, temp4, temp5, temp6, temp7, temp8, temp9;

void centeredRect(float x, float y, float z, float p, float l, float t, GLuint texture) {

	float halfX = l / 2;
	float halfY = t / 2;
	float halfZ = p / 2;
	float diag = 3.0f;

	// Depan
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 4.0f); glVertex3f(x + halfX, y + halfY, z + halfZ);
	glTexCoord2f(0.0f, 4.0f); glVertex3f(x - halfX, y + halfY, z + halfZ);
	glEnd();

	// Belakang
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 4.0f); glVertex3f(x + halfX, y + halfY, z - halfZ);
	glTexCoord2f(0.0f, 4.0f); glVertex3f(x - halfX, y + halfY, z - halfZ);
	glEnd();

	// Kiri
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 4.0f); glVertex3f(x - halfX, y + halfY, z + halfZ);
	glTexCoord2f(0.0f, 4.0f); glVertex3f(x - halfX, y + halfY, z - halfZ);
	glEnd();

	// Kanan
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 4.0f); glVertex3f(x + halfX, y + halfY, z + halfZ);
	glTexCoord2f(0.0f, 4.0f); glVertex3f(x + halfX, y + halfY, z - halfZ);
	glEnd();

	// Atas
	glColor3ub(150, 140, 74);
	glBegin(GL_QUADS);
	glVertex3f(x - halfX, y + halfY, z + halfZ); glVertex3f(x + halfX, y + halfY, z + halfZ); glVertex3f(x + halfX, y + halfY, z - halfZ); glVertex3f(x - halfX, y + halfY, z - halfZ);
	glEnd();

	// Bawah
	glColor3ub(150, 140, 74);
	glBegin(GL_QUADS);
	glVertex3f(x - halfX, y - halfY, z + halfZ); glVertex3f(x + halfX, y - halfY, z + halfZ); glVertex3f(x + halfX, y - halfY, z - halfZ); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glColor3ub(255, 255, 255);
}
void fungsiBaru(float x, float y, float z, float p, float l, float t, GLuint textureFN) {
	float halfX = l / 2;
	float halfY = t / 2;
	float halfZ = p / 2;
	float diag = 3.0f;
	float ketebalan = 0.05f;
	float addition;

	// Depan
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureFN);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 0.45f); glVertex3f(x + halfX, (y + halfY) - 3.0f, z + halfZ);
	glTexCoord2f(0.75f, 1.0f); glVertex3f(x + 10.0f, (y + halfY) + 7.0f, z + halfZ);
	glTexCoord2f(0.25f, 1.0f); glVertex3f(x - 10.0f, (y + halfY) + 7.0f, z + halfZ);
	glTexCoord2f(0.0f, 0.45f); glVertex3f(x - halfX, (y + halfY) - 3.0f, z + halfZ);
	glEnd();

	addition = z + halfZ;
	for (float i = 0.0f; i < ketebalan; i += 0.001f) {
		addition -= i;
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, addition);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, addition);
		glTexCoord2f(1.0f, 0.45f); glVertex3f(x + halfX, (y + halfY) - 3.0f, addition);
		glTexCoord2f(0.75f, 1.0f); glVertex3f(x + 10.0f, (y + halfY) + 7.0f, addition);
		glTexCoord2f(0.25f, 1.0f); glVertex3f(x - 10.0f, (y + halfY) + 7.0f, addition);
		glTexCoord2f(0.0f, 0.45f); glVertex3f(x - halfX, (y + halfY) - 3.0f, addition);
		glEnd();
	}

	glDisable(GL_TEXTURE_2D);
}
void mainBuild(float x, float y, float z, float p, float l, float t, GLuint textureFN, GLuint textureLR, GLuint textureFloor, GLuint textureDoor) {

	float halfX = l / 2;
	float halfY = t / 2;
	float halfZ = p / 2;
	float diag = 3.0f;
	float ketebalan = 0.05f;
	float addition;

	// Depan
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureFN);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	/*glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 0.45f); glVertex3f(x + halfX, (y + halfY) - 3.0f, z + halfZ);
	glTexCoord2f(0.75f, 1.0f); glVertex3f(x + 10.0f, (y + halfY) + 7.0f, z + halfZ);
	glTexCoord2f(0.25f, 1.0f); glVertex3f(x - 10.0f, (y + halfY) + 7.0f, z + halfZ);
	glTexCoord2f(0.0f, 0.45f); glVertex3f(x - halfX, (y + halfY) - 3.0f, z + halfZ);
	glEnd();

	addition = z + halfZ;
	for (float i = 0.0f; i < ketebalan; i += 0.001f) {
		addition -= i;
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, addition);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, addition);
		glTexCoord2f(1.0f, 0.45f); glVertex3f(x + halfX, (y + halfY) - 3.0f, addition);
		glTexCoord2f(0.75f, 1.0f); glVertex3f(x + 10.0f, (y + halfY) + 7.0f, addition);
		glTexCoord2f(0.25f, 1.0f); glVertex3f(x - 10.0f, (y + halfY) + 7.0f, addition);
		glTexCoord2f(0.0f, 0.45f); glVertex3f(x - halfX, (y + halfY) - 3.0f, addition);
		glEnd();
	}*/

	// Partisi
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z);
	glTexCoord2f(1.0f, 0.45f); glVertex3f(x + halfX, (y + halfY) - 3.0f, z);
	glTexCoord2f(0.75f, 1.0f); glVertex3f(x + 10.0f, (y + halfY) + 7.0f, z);
	glTexCoord2f(0.25f, 1.0f); glVertex3f(x - 10.0f, (y + halfY) + 7.0f, z);
	glTexCoord2f(0.0f, 0.45f); glVertex3f(x - halfX, (y + halfY) - 3.0f, z);
	glEnd();

	addition = z;
	for (float i = 0.0f; i < ketebalan; i += 0.001f) {
		addition += i;
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, addition);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, addition);
		glTexCoord2f(1.0f, 0.45f); glVertex3f(x + halfX, (y + halfY) - 3.0f, addition);
		glTexCoord2f(0.75f, 1.0f); glVertex3f(x + 10.0f, (y + halfY) + 7.0f, addition);
		glTexCoord2f(0.25f, 1.0f); glVertex3f(x - 10.0f, (y + halfY) + 7.0f, addition);
		glTexCoord2f(0.0f, 0.45f); glVertex3f(x - halfX, (y + halfY) - 3.0f, addition);
		glEnd();
	}

	temp3 = z + 0.1f;
	for (int i = 0; i < 2; i++) {
		glBindTexture(GL_TEXTURE_2D, textureDoor);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_QUADS);
		glTexCoord2f(0.f, 0.f); glVertex3f(-4.0f, y - halfY, temp3);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, y - halfY, temp3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(4.0f, (y + halfY) - 2.0f, temp3);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-4.0f, (y + halfY) - 2.0f, temp3);
		glEnd();
		temp3 -= 0.2f;
	}

	// Belakang
	glBindTexture(GL_TEXTURE_2D, textureFN);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.45f); glVertex3f(x - halfX, (y + halfY) - 3.0f, z - halfZ);
	glTexCoord2f(0.75f, 1.0f); glVertex3f(x - 10.0f, (y + halfY) + 7.0f, z - halfZ);
	glTexCoord2f(0.25f, 1.0f); glVertex3f(x + 10.0f, (y + halfY) + 7.0f, z - halfZ);
	glTexCoord2f(0.0f, 0.45f); glVertex3f(x + halfX, (y + halfY) - 3.0f, z - halfZ);
	glEnd();

	addition = z - halfZ;
	for (float i = 0.0f; i < ketebalan; i += 0.001f) {
		addition += i;
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, addition);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, addition);
		glTexCoord2f(1.0f, 0.45f); glVertex3f(x + halfX, (y + halfY) - 3.0f, addition);
		glTexCoord2f(0.75f, 1.0f); glVertex3f(x + 10.0f, (y + halfY) + 7.0f, addition);
		glTexCoord2f(0.25f, 1.0f); glVertex3f(x - 10.0f, (y + halfY) + 7.0f, addition);
		glTexCoord2f(0.0f, 0.45f); glVertex3f(x - halfX, (y + halfY) - 3.0f, addition);
		glEnd();
	}

	// Kiri
	glBindTexture(GL_TEXTURE_2D, textureLR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(3.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(3.0f, 1.0f); glVertex3f(x - halfX, (y + halfY) - 3.0f, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, (y + halfY) - 3.0f, z - halfZ);
	glEnd();

	addition = x - halfX;
	for (float i = 0.0f; i < ketebalan; i += 0.001f) {
		addition += i;
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(addition, y - halfY, z - halfZ);
		glTexCoord2f(3.0f, 0.0f); glVertex3f(addition, y - halfY, z + halfZ);
		glTexCoord2f(3.0f, 1.0f); glVertex3f(addition, (y + halfY) - 3.0f, z + halfZ);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(addition, (y + halfY) - 3.0f, z - halfZ);
		glEnd();
	}

	// Kanan
	glBindTexture(GL_TEXTURE_2D, textureLR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(3.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(3.0f, 1.0f); glVertex3f(x + halfX, (y + halfY) - 3.0f, z - halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + halfX, (y + halfY) - 3.0f, z + halfZ);
	glEnd();

	addition = x + halfX;
	for (float i = 0.0f; i < ketebalan; i += 0.001f) {
		addition -= i;
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(addition, y - halfY, z + halfZ);
		glTexCoord2f(3.0f, 0.0f); glVertex3f(addition, y - halfY, z - halfZ);
		glTexCoord2f(3.0f, 1.0f); glVertex3f(addition, (y + halfY) - 3.0f, z - halfZ);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(addition, (y + halfY) - 3.0f, z + halfZ);
		glEnd();
	}

	// Bawah
	// T
	glBindTexture(GL_TEXTURE_2D, textureFloor);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, (z + halfZ) - 15.0f);
	glTexCoord2f(2.0f, 0.0f); glVertex3f(x + halfX, y - halfY, (z + halfZ) - 15.0f);
	glTexCoord2f(2.0f, 10.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(0.0f, 10.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glEnd();

	//B
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(2.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(2.0f, 0.3f); glVertex3f(x + halfX, y - halfY, (z + halfZ) - 3.0f);
	glTexCoord2f(0.0f, 0.3f); glVertex3f(x - halfX, y - halfY, (z + halfZ) - 3.0f);
	glEnd();

	// L
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.5f, 0.0f); glVertex3f((x + halfX) - 11.5f, y - halfY, z + halfZ);
	glTexCoord2f(1.5f, 0.4f); glVertex3f((x + halfX) - 11.5f, y - halfY, (z + halfZ) - 15.0f);
	glTexCoord2f(0.0f, 0.4f); glVertex3f(x - halfX, y - halfY, (z + halfZ) - 15.0f);
	glEnd();

	// R
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f((x + halfX) - 3.0f, y - halfY, z + halfZ);
	glTexCoord2f(0.1f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(0.1f, 1.0f); glVertex3f(x + halfX, y - halfY, (z + halfZ) - 15.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f((x + halfX) - 3.0f, y - halfY, (z + halfZ) - 15.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}
void block(float x, float y, float z, float p, float l, float t, GLuint texture) {

	float halfX = l / 2;
	float halfY = t / 2;
	float halfZ = p / 2;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Depan
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z + halfZ);
	glEnd();

	// Belakang
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z - halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z - halfZ);
	glEnd();

	// Kiri
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z - halfZ);
	glEnd();

	// Kanan
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z - halfZ);
	glEnd();

	// Atas
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y + halfY, z + halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y + halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z - halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z - halfZ);
	glEnd();

	// Bawah
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}
void atapV(float x, float y, float z, float p, float l, float t, GLuint textureRoof, GLuint textureLayer, GLuint textureTriangle, GLuint triangleBot) {
	float halfX = l / 2;
	float halfY = t / 2;
	float halfZ = p / 2;
	float offside = 3.0f;
	float fenceWidth = 2.0f;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureRoof);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Kiri
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);  glVertex3f(x - halfX, y - halfY, (z - halfZ) - offside);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x - halfX, y - halfY, (z + halfZ) + offside);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, t, (z + halfZ) + 3.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, t, (z - halfZ) - 3.0f);
	glEnd();

	// Kanan
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);  glVertex3f(x + halfX, y - halfY, (z - halfZ) - offside);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, (z + halfZ) + offside);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, t, (z + halfZ) + 3.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, t, (z - halfZ) - 3.0f);
	glEnd();

	temp3 = (z + halfZ) + offside;
	temp4 = ((z + halfZ) + 3.0f) - 0.5f;
	temp5 = (z + halfZ) + 1.0f;
	temp6 = temp5 - 5.0f;
	temp7 = temp3 - 0.5f;
	temp8 = x - halfX;
	temp9 = temp8 + 2.5f;

	for (int i = 0; i < 2; i++) {
		//L
		glBindTexture(GL_TEXTURE_2D, textureLayer);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - halfX, y - halfY, temp7);
		glTexCoord2f(1.0f, 1.0f); glVertex3f((x - halfX) + 2.5f, y - halfY, temp7);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x, t - 2.5f, temp4);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, t, temp4);
		glEnd();

		// R
		glBindTexture(GL_TEXTURE_2D, textureLayer);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, temp7);
		glTexCoord2f(1.0f, 1.0f); glVertex3f((x + halfX) - 2.5f, y - halfY, temp7);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x, t - 2.5f, temp4);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, t, temp4);
		glEnd();

		glColor3ub(250, 255, 255);

		// Triangle
		glBindTexture(GL_TEXTURE_2D, textureTriangle);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-9.5f, t - 11.25f, temp5);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(9.5f, t - 11.25f, temp5);
		glTexCoord2f(0.5f, 1.0f); glVertex3f(x, t, temp5);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, triangleBot);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-9.5f, t - 11.25f, temp5);
		glTexCoord2f(2.0f, 0.0f); glVertex3f(9.5f, t - 11.25f, temp5);
		glTexCoord2f(2.0f, 1.0f); glVertex3f(9.5f, t - 11.25f, temp6);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-9.5f, t - 11.25f, temp6);
		glEnd();

		// LPad
		glColor3ub(70, 70, 70);
		temp3 = (z + halfZ) + offside;
		temp4 = (z - halfZ) - offside;
		glBindTexture(GL_TEXTURE_2D, textureLayer);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(temp8, y - halfY, temp3 - 0.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(temp9, y - halfY, temp3 - 0.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(temp9, y - halfY, temp4 + 0.5f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(temp8, y - halfY, temp4 + 0.5f);
		glEnd();

		temp3 = (z - halfZ) - offside;
		temp4 = ((z - halfZ) - 3.0f) + 0.5f;
		temp5 = (z - halfZ) - 1.0f;
		temp6 = temp5 + 5.0f;
		temp7 = temp3 + 0.5f;
		temp8 = x + halfX;
		temp9 = temp8 - 2.5f;

		glColor3ub(255, 255, 255);
	}
	
	glDisable(GL_TEXTURE_2D);
	glColor3f(1.0f, 1.0f, 1.0f);
}
void kursiJemaat(float x, float y, float z, float p, GLuint texture) {
	float halfP = p / 2;

	// Tempat Duduk
	glColor3ub(255, 255, 255);
	block(x, y, z, p, 3.0f, 1.0f, texture);

	// Sandaran Tangan
	glColor3ub(100, 100, 100);
	block(x, y, z + halfP, 1.0f, 3.0f, 2.0f, texture);
	block(x, y, z - halfP, 1.0f, 3.0f, 2.0f, texture);

	// Kaki
	glColor3ub(70, 70, 70);
	block(x, y - 2.0f, (z + halfP) - 1.0f, 1.0f, 3.0f, 3.0f, texture);
	block(x, y - 2.0f, (z - halfP) + 1.0f, 1.0f, 3.0f, 3.0f, texture);

	// Sandaran Belakang
	block(x + 2.0f, y + 1.5f, z, p, 1.0f, 4.0f, texture);

	glColor3ub(255, 255, 255);
}
void bed(float x, float y, float z, float p, float l, float t, GLuint textureBed, GLuint textureFoot) {
	
	float halfX = l / 2;
	float halfY = t / 2;
	float halfZ = p / 2;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureBed);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);

	// Atas
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y + halfY, z + halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y + halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z - halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z - halfZ);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textureFoot);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);

	// Depan
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z + halfZ);
	glEnd();

	// Belakang
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z - halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z - halfZ);
	glEnd();

	// Kiri
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z - halfZ);
	glEnd();

	// Kanan
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z - halfZ);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	
}
void meja(float x, float y, float z, float p, float l, float t, GLuint texture) {

	float halfX = l / 2;
	float halfY = t / 2;
	float halfZ = p / 2;

	glColor3ub(255, 255, 255);
	block(x, y, z, p, l, 1.0f, texture);

	glColor3ub(150, 150, 150);
	block(x - halfX, y - halfY, z + halfZ, 0.8f, 0.8f, t, texture);
	block(x + halfX, y - halfY, z + halfZ, 0.8f, 0.8f, t, texture);
	block(x + halfX, y - halfY, z - halfZ, 0.8f, 0.8f, t, texture);
	block(x - halfX, y - halfY, z - halfZ, 0.8f, 0.8f, t, texture);
	glColor3f(1.0f, 1.0f, 1.0f);
}
void kursi(float x, float y, float z, float p, float l, float t, GLuint texture) {

	float halfX = l / 2;
	float halfY = t / 2;
	float halfZ = p / 2;

	glColor3ub(200, 200, 200);
	block(x, y, z, p, l, 1.0f, texture); // Seat
	block(x, y + halfY, z - halfZ, 1.0f, l * 0.8f, l, texture); // Back

	glColor3ub(140, 140, 140);
	block(x - halfX, y - halfY, z + halfZ, 0.5f, 0.5f, t, texture);
	block(x + halfX, y - halfY, z + halfZ, 0.5f, 0.5f, t, texture);
	block(x + halfX, y - halfY, z - halfZ, 0.5f, 0.5f, t, texture);
	block(x - halfX, y - halfY, z - halfZ, 0.5f, 0.5f, t, texture);
	glColor3f(1.0f, 1.0f, 1.0f);
}
void title(float x, float y, float z, float p, float l, float t, GLuint textureTitle, GLuint textureSide, GLuint textureFoot) {
	float halfX = l / 2;
	float halfY = t / 2;
	float halfZ = p / 2;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureTitle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Depan
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z + halfZ);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textureSide);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Belakang
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z - halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z - halfZ);
	glEnd();

	// Kiri
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z - halfZ);
	glEnd();

	// Kanan
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z - halfZ);
	glEnd();

	// Atas
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y + halfY, z + halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y + halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z - halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z - halfZ);
	glEnd();

	// Bawah
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glEnd();

	centeredRect((x - halfX) + 5.0f, (y - halfY) - 3.75f, z, 2.0f, 2.0f, (t - halfY) + 0.3f, textureFoot);
	centeredRect((x + halfX) - 5.0f, (y - halfY) - 3.75f, z, 2.0f, 2.0f, (t - halfY) + 0.3f, textureFoot);
}