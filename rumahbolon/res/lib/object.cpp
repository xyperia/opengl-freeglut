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
void centeredTrap(float x, float y, float z, float p, float l, float t, GLuint textureFN, GLuint textureLR, GLuint textureFloor, GLuint textureDoor) {

	float halfX = l / 2;
	float halfY = t / 2;
	float halfZ = p / 2;
	float diag = 3.0f;

	// Depan
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureFN);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.25f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.8f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(2.0f, 1.0f); glVertex3f((x + halfX) + diag, y + halfY, (z + halfZ) + diag);
	glTexCoord2f(0.1f, 1.0f); glVertex3f((x - halfX) - diag, y + halfY, (z + halfZ) + diag);
	glEnd();

	// Partisi
	glBegin(GL_QUADS);
	glTexCoord2f(0.25f, 0.0f); glVertex3f(x - halfX, y - halfY, z);
	glTexCoord2f(1.8f, 0.0f); glVertex3f(x + halfX, y - halfY, z);
	glTexCoord2f(2.0f, 1.0f); glVertex3f((x + halfX) + diag, y + halfY, z);
	glTexCoord2f(0.1f, 1.0f); glVertex3f((x - halfX) - diag, y + halfY, z);
	glEnd();

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
	glBegin(GL_QUADS);
	glTexCoord2f(0.25f, 0.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.8f, 0.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(2.0f, 1.0f); glVertex3f((x + halfX) + diag, y + halfY, (z - halfZ) - diag);
	glTexCoord2f(0.1f, 1.0f); glVertex3f((x - halfX) - diag, y + halfY, (z - halfZ) - diag);
	glEnd();

	// Kiri
	glBindTexture(GL_TEXTURE_2D, textureLR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.25f, 0.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(3.75f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(4.0f, 1.0f); glVertex3f((x - halfX) - diag, y + halfY, (z + halfZ) + diag);
	glTexCoord2f(0.0f, 1.0f); glVertex3f((x - halfX) - diag, y + halfY, (z - halfZ) - diag);
	glEnd();

	// Kanan
	glBindTexture(GL_TEXTURE_2D, textureLR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.25f, 0.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(3.75f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(4.0f, 1.0f); glVertex3f((x + halfX) + diag, y + halfY, (z + halfZ) + diag);
	glTexCoord2f(0.0f, 1.0f); glVertex3f((x + halfX) + diag, y + halfY, (z - halfZ) - diag);
	glEnd();

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
	glTexCoord2f(0.5f, 0.0f); glVertex3f(x - 5.0f, y - halfY, z + halfZ);
	glTexCoord2f(0.5f, 0.4f); glVertex3f(x - 5.0f, y - halfY, (z + halfZ) - 15.0f);
	glTexCoord2f(0.0f, 0.4f); glVertex3f(x - halfX, y - halfY, (z + halfZ) - 15.0f);
	glEnd();

	// R
	glBegin(GL_QUADS);
	glTexCoord2f(0.525f, 0.0f); glVertex3f(x + 5.0f, y - halfY, z + halfZ);
	glTexCoord2f(1.25f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.25f, 1.0f); glVertex3f(x + halfX, y - halfY, (z + halfZ) - 15.0f);
	glTexCoord2f(0.525f, 1.0f); glVertex3f(x + 5.0f, y - halfY, (z + halfZ) - 15.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}
void block(float x, float y, float z, float p, float l, float t) {

	float halfX = l / 2;
	float halfY = t / 2;
	float halfZ = p / 2;

	// Depan
	glBegin(GL_QUADS);
	glVertex3f(x - halfX, y - halfY, z + halfZ); glVertex3f(x + halfX, y - halfY, z + halfZ); glVertex3f(x + halfX, y + halfY, z + halfZ); glVertex3f(x - halfX, y + halfY, z + halfZ);
	glEnd();

	// Belakang
	glBegin(GL_QUADS);
	glVertex3f(x - halfX, y - halfY, z - halfZ); glVertex3f(x + halfX, y - halfY, z - halfZ); glVertex3f(x + halfX, y + halfY, z - halfZ); glVertex3f(x - halfX, y + halfY, z - halfZ);
	glEnd();

	// Kiri
	glBegin(GL_QUADS);
	glVertex3f(x - halfX, y - halfY, z - halfZ); glVertex3f(x - halfX, y - halfY, z + halfZ); glVertex3f(x - halfX, y + halfY, z + halfZ); glVertex3f(x - halfX, y + halfY, z - halfZ);
	glEnd();

	// Kanan
	glBegin(GL_QUADS);
	glVertex3f(x + halfX, y - halfY, z - halfZ); glVertex3f(x + halfX, y - halfY, z + halfZ); glVertex3f(x + halfX, y + halfY, z + halfZ); glVertex3f(x + halfX, y + halfY, z - halfZ);
	glEnd();

	// Atas
	glBegin(GL_QUADS);
	glVertex3f(x - halfX, y + halfY, z + halfZ); glVertex3f(x + halfX, y + halfY, z + halfZ); glVertex3f(x + halfX, y + halfY, z - halfZ); glVertex3f(x - halfX, y + halfY, z - halfZ);
	glEnd();

	// Bawah
	glBegin(GL_QUADS);
	glVertex3f(x - halfX, y - halfY, z + halfZ); glVertex3f(x + halfX, y - halfY, z + halfZ); glVertex3f(x + halfX, y - halfY, z - halfZ); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glEnd();
}
void atapV(float x, float y, float z, float p, float l, float t, GLuint textureRoof, GLuint texturePanel, GLuint textureTriangle, GLuint textureLayer, GLuint textureCrossLR, GLuint textureCrossUD) {
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

	// Bawah
	glColor3ub(60, 60, 60);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glEnd();
	glColor3ub(255, 255, 255);

	// Depan
	glBindTexture(GL_TEXTURE_2D, texturePanel);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(0.5f, 1.0f); glVertex3f(x, t, z + halfZ);
	glEnd();

	// Belakang
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(0.5f, 1.0f); glVertex3f(x, t, z - halfZ);
	glEnd();

	// Miring
	temp3 = (z + halfZ) + offside;
	temp4 = (z + halfZ) + 8.0f;
	temp5 = (z + halfZ) + 6.0f;
	temp6 = (z + halfZ) + 7.9f;
	temp7 = z + halfZ;
	temp8 = 36.5f;
	temp9 = temp8 - 3.0f;

	for (int i = 0; i < 2; i++) {
		// L
		glBindTexture(GL_TEXTURE_2D, textureLayer);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - halfX, y - halfY, temp3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f((x - halfX) + 2.5f, y - halfY, temp3);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x, t - 2.0f, temp4);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, t + 3.0f, temp4);
		glEnd();

		// R
		glBindTexture(GL_TEXTURE_2D, textureLayer);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, temp3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f((x + halfX) - 2.5f, y - halfY, temp3);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x, t - 2.0f, temp4);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, t + 3.0f, temp4);
		glEnd();

		// Triangle
		glBindTexture(GL_TEXTURE_2D, textureTriangle);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-6.5f, t - 12.0f, temp5);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(6.5f, t - 12.0f, temp5);
		glTexCoord2f(0.5f, 1.0f); glVertex3f(x, t + 3.0f, temp6);
		glEnd();

		// ExtendedRoof
		glBindTexture(GL_TEXTURE_2D, textureRoof);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, temp3);
		glTexCoord2f(0.5f, 0.5f); glVertex3f(x, t + 3.0f, temp4);
		glTexCoord2f(0.0f, 0.95f); glVertex3f(x, t, temp7);
		glEnd();

		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x + halfX, y - halfY, temp3);
		glTexCoord2f(0.5f, 0.5f); glVertex3f(x, t + 3.0f, temp4);
		glTexCoord2f(0.0f, 0.95f); glVertex3f(x, t, temp7);
		glEnd();

		// CrossLR
		glBindTexture(GL_TEXTURE_2D, textureCrossLR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f((x - halfX) + 10.0f, halfY - 1.0f, temp8);
		glTexCoord2f(1.0f, 0.0f); glVertex3f((x + halfX) - 10.0f, halfY - 1.0f, temp8);
		glTexCoord2f(0.8f, 1.0f); glVertex3f((x + halfX) - 11.5f, halfY + 2.5f, temp8);
		glTexCoord2f(0.0f, 1.0f); glVertex3f((x - halfX) + 11.5f, halfY + 2.5f, temp8);
		glEnd();

		// CrossUD
		glColor3f(1.0f, 1.0f, 1.0f);
		glBindTexture(GL_TEXTURE_2D, textureCrossUD);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_QUADS);
		glTexCoord2f(0.1f, 0.1f); glVertex3f(x - 1.5f, (y - halfY) + 3.0f, temp9);
		glTexCoord2f(0.9f, 0.1f); glVertex3f(x + 1.5f, (y - halfY) + 3.0f, temp9);
		glTexCoord2f(0.9f, 0.9f); glVertex3f(x + 1.5f, halfY - 1.0f, temp8);
		glTexCoord2f(0.1f, 0.9f); glVertex3f(x - 1.5f, halfY - 1.0f, temp8);
		glEnd();

		temp3 = (z - halfZ) - offside;
		temp4 = (z - halfZ) - 8.0f;
		temp5 = (z - halfZ) - 6.0f;
		temp6 = (z - halfZ) - 7.9f;
		temp7 = z - halfZ;
		temp8 = -36.5f;
		temp9 = temp8 + 3.0f;
	}

	glDisable(GL_TEXTURE_2D);
	glColor3f(1.0f, 1.0f, 1.0f);
}
void kursiJemaat(float x, float y, float z, float p) {
	float halfP = p / 2;

	// Tempat Duduk
	glColor3ub(77, 54, 0);
	block(x, y, z, p, 3.0f, 1.0f);

	// Sandaran Tangan
	glColor3ub(40, 40, 40);
	block(x, y, z + halfP, 1.0f, 3.0f, 2.0f);
	block(x, y, z - halfP, 1.0f, 3.0f, 2.0f);

	// Kaki
	glColor3ub(20, 20, 20);
	block(x, y - 2.0f, (z + halfP) - 1.0f, 1.0f, 3.0f, 3.0f);
	block(x, y - 2.0f, (z - halfP) + 1.0f, 1.0f, 3.0f, 3.0f);

	// Sandaran Belakang
	block(x + 2.0f, y + 1.5f, z, p, 1.0f, 4.0f);

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
void meja(float x, float y, float z, float p, float l, float t) {

	float halfX = l / 2;
	float halfY = t / 2;
	float halfZ = p / 2;

	glColor3ub(0, 34, 92);
	block(x, y, z, p, l, 1.0f);

	glColor3ub(0, 18, 48);
	block(x - halfX, y - halfY, z + halfZ, 0.8f, 0.8f, t);
	block(x + halfX, y - halfY, z + halfZ, 0.8f, 0.8f, t);
	block(x + halfX, y - halfY, z - halfZ, 0.8f, 0.8f, t);
	block(x - halfX, y - halfY, z - halfZ, 0.8f, 0.8f, t);
	glColor3f(1.0f, 1.0f, 1.0f);
}
void kursi(float x, float y, float z, float p, float l, float t) {

	float halfX = l / 2;
	float halfY = t / 2;
	float halfZ = p / 2;

	glColor3ub(0, 68, 140);
	block(x, y, z, p, l, 1.0f); // Seat
	block(x, y + halfY, z - halfZ, 1.0f, l * 0.8f, l); // Back

	glColor3ub(0, 35, 71);
	block(x - halfX, y - halfY, z + halfZ, 0.5f, 0.5f, t);
	block(x + halfX, y - halfY, z + halfZ, 0.5f, 0.5f, t);
	block(x + halfX, y - halfY, z - halfZ, 0.5f, 0.5f, t);
	block(x - halfX, y - halfY, z - halfZ, 0.5f, 0.5f, t);
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