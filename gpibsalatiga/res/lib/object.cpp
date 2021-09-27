// OBJECT LIBRARY
// 672016143, 672016064, 672016195

#include <gl/glut.h>
#include "imageloader.h"
#include <math.h>

double PI = 3.14159265359;

void rect(float x, float y, float z, float p, float l, float t) {
	// Depan
	glBegin(GL_QUADS);
	glVertex3f(x, y, z); glVertex3f(x + l, y, z); glVertex3f(x + l, y + l, z); glVertex3f(x, y + l, z);
	glEnd();

	// Belakang
	glBegin(GL_QUADS);
	glVertex3f(x, y, z - p); glVertex3f(x + l, y, z - p); glVertex3f(x + l, y + l, z - p); glVertex3f(x, y + l, z - p);
	glEnd();

	// Kiri
	glBegin(GL_QUADS);
	glVertex3f(x, y, z - p); glVertex3f(x, y, z); glVertex3f(x, y + l, z); glVertex3f(x, y + l, z - p);
	glEnd();

	// Kanan
	glBegin(GL_QUADS);
	glVertex3f(x + l, y, z - p); glVertex3f(x + l, y, z); glVertex3f(x + l, y + l, z); glVertex3f(x + l, y + l, z - p);
	glEnd();

	// Atas
	glBegin(GL_QUADS);
	glVertex3f(x, y + l, z); glVertex3f(x + l, y + l, z); glVertex3f(x + l, y + l, z - p); glVertex3f(x, y + l, z - p);
	glEnd();

	// Bawah
	glVertex3f(x, y, z);
	glVertex3f(x + l, y, z); glVertex3f(x, y, z - p); glVertex3f(x + l, y, z - p);
	glEnd();
}
void centeredRect(float x, float y, float z, float p, float l, float t, GLuint texture) {

	float halfX = l / 2;
	float halfY = t / 2;
	float halfZ = p / 2;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Depan
	glColor3ub(235, 220, 179);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(2.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(2.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z + halfZ);
	glEnd();

	// Belakang
	glColor3ub(215, 210, 169);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(2.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(2.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z - halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z - halfZ);
	glEnd();

	// Kiri
	glColor3ub(255, 237, 189);
	glBegin(GL_QUADS);
	glColor3ub(255, 237, 189);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y + halfY, z - halfZ);
	glEnd();

	// Kanan
	glColor3ub(220, 215, 170);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + halfX, y + halfY, z - halfZ);
	glEnd();

	// Bawah
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}
void texturedBlock(float x, float y, float z, float p, float l, float t, GLuint texture) {

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
	glColor3ub(255, 255, 255);
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
void atapH(float x, float y, float z, float p, float l, float t, GLuint texture, GLuint texSide, GLuint texEnd) {
	float halfX = l / 2;
	float halfY = p / 2;
	float halfZ = p / 2;

	float fenceWidth = 3.0f;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Depan
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, t, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, t, z);
	glEnd();

	// Belakang
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, t, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, t, z);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, texSide);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Kiri
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(0.5f, 1.0f); glVertex3f(x - halfX, t, z);
	glEnd();

	// Kanan
	glColor3ub(220, 215, 170);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(0.5f, 1.0f); glVertex3f(x + halfX, t, z);
	glEnd();

	// Bawah
	glBegin(GL_QUADS);
	glVertex3f(x - halfX, y - halfY, z + halfZ); glVertex3f(x + halfX, y - halfY, z + halfZ); glVertex3f(x + halfX, y - halfY, z - halfZ); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glEnd();

	glColor3ub(255, 255, 255);

	// FN RoofEnd
	glBindTexture(GL_TEXTURE_2D, texEnd);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	float pointer = z + halfZ;
	for (int i = 0; i < 2; i++) {
		// face
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f((x - halfX) - 3.0f, y - halfY, pointer + 2.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f((x + halfX) + 3.0f, y - halfY, pointer + 2.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f((x + halfX) + 3.0f, (y - halfY) + 2.0f, pointer + 2.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f((x - halfX) - 3.0f, (y - halfY) + 2.0f, pointer + 2.0f);
		glEnd();

		// top
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f((x + halfX) + 3.0f, (y - halfY) + 2.0f, pointer + 2.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f((x - halfX) - 3.0f, (y - halfY) + 2.0f, pointer + 2.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f((x - halfX) - 3.0f, (y - halfY) + 2.0f, pointer);
		glTexCoord2f(0.0f, 1.0f); glVertex3f((x + halfX) + 3.0f, (y - halfY) + 2.0f, pointer);
		glEnd();

		// back
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f((x - halfX) - 3.0f, y - halfY, pointer);
		glTexCoord2f(1.0f, 0.0f); glVertex3f((x + halfX) + 3.0f, y - halfY, pointer);
		glTexCoord2f(1.0f, 1.0f); glVertex3f((x + halfX) + 3.0f, (y - halfY) + 2.0f, pointer);
		glTexCoord2f(0.0f, 1.0f); glVertex3f((x - halfX) - 3.0f, (y - halfY) + 2.0f, pointer);
		glEnd();

		// bottom
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f((x + halfX) + 3.0f, y - halfY, pointer + 2.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f((x - halfX) - 3.0f, y - halfY, pointer + 2.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f((x - halfX) - 3.0f, y - halfY, pointer);
		glTexCoord2f(0.0f, 1.0f); glVertex3f((x + halfX) + 3.0f, y - halfY, pointer);
		glEnd();

		pointer = (z - halfZ) - 2.0f;
	}

	// LR RoofEnd
	pointer = (x - halfX) - 3.0f;
	for (int i = 0; i < 2; i++)
	{
		// FENCE_f
		// top
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(pointer, (y - halfY) + 2.0f, z + halfZ);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(pointer + fenceWidth, (y - halfY) + 2.0f, z + halfZ);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(pointer + fenceWidth, t + 2.0f, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(pointer, t + 2.0f, z);
		glEnd();

		// face
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(pointer, y - halfY, z + halfZ);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(pointer + fenceWidth, y - halfY, z + halfZ);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(pointer + fenceWidth, (y - halfY) + 2.0f, z + halfZ);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(pointer, (y - halfY) + 2.0f, z + halfZ);
		glEnd();

		// left
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(pointer, t, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(pointer, y - halfY, z + halfZ);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(pointer, (y - halfY) + 2.0f, z + halfZ);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(pointer, t + 2.0f, z);
		glEnd();

		// right
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(pointer + fenceWidth, t, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(pointer + fenceWidth, y - halfY, z + halfZ);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(pointer + fenceWidth, (y - halfY) + 2.0f, z + halfZ);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(pointer + fenceWidth, t + 2.0f, z);
		glEnd();

		// FENCE_b
		// top
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(pointer, (y - halfY) + 2.0f, z - halfZ);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(pointer + fenceWidth, (y - halfY) + 2.0f, z - halfZ);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(pointer + fenceWidth, t + 2.0f, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(pointer, t + 2.0f, z);
		glEnd();

		// face
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(pointer, y - halfY, z - halfZ);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(pointer + fenceWidth, y - halfY, z - halfZ);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(pointer + fenceWidth, (y - halfY) + 2.0f, z - halfZ);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(pointer, (y - halfY) + 2.0f, z - halfZ);
		glEnd();

		// left
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(pointer, t, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(pointer, y - halfY, z - halfZ);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(pointer, (y - halfY) + 2.0f, z - halfZ);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(pointer, t + 2.0f, z);
		glEnd();

		// right
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(pointer + fenceWidth, t, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(pointer + fenceWidth, y - halfY, z - halfZ);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(pointer + fenceWidth, (y - halfY) + 2.0f, z - halfZ);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(pointer + fenceWidth, t + 2.0f, z);
		glEnd();

		pointer = x + halfX;
	}

	glDisable(GL_TEXTURE_2D);
	glColor3ub(255, 255, 255);
}
void atapV(float x, float y, float z, float l, float t, GLuint texture, GLuint texSide, GLuint texEnd) {
	float halfX = l / 2;
	float halfY = t / 2;
	float halfZ = l / 2;

	float fenceWidth = 2.0f;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Kiri
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);  glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, t, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, t, z - halfZ);
	glEnd();

	// Kanan
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);  glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, t, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, t, z - halfZ);
	glEnd();

	// Depan
	glBindTexture(GL_TEXTURE_2D, texSide);
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

	// Bawah
	glBegin(GL_QUADS);
	glVertex3f(x - halfX, y - halfY, z + halfZ); glVertex3f(x + halfX, y - halfY, z + halfZ); glVertex3f(x + halfX, y - halfY, z - halfZ); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glEnd();

	// ROOF END FN
	glColor3ub(255, 255, 255);
	// LEFT_PART
	// face
	glBindTexture(GL_TEXTURE_2D, texEnd);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, (y - halfY) - 3.0, (z + halfZ) + fenceWidth);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, t - 3.0, (z + halfZ) + fenceWidth);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, t, (z + halfZ) + fenceWidth);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y - halfY, (z + halfZ) + fenceWidth);
	glEnd();

	// top
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, y - halfY, (z + halfZ) + fenceWidth);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, t, (z + halfZ) + fenceWidth);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, t, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glEnd();

	// bottom
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, (y - halfY) - 3.0, (z + halfZ) + fenceWidth);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, t - 3.0, (z + halfZ) + fenceWidth);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, t - 3.0, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, (y - halfY) - 3.0, z + halfZ);
	glEnd();

	// left
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x - halfX, (y - halfY) - 3.0, z + halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x - halfX, (y - halfY) - 3.0, (z + halfZ) + fenceWidth);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x - halfX, y - halfY, (z + halfZ) + fenceWidth);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glEnd();

	// RIGHT_PART
	// face
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + halfX, (y - halfY) - 3.0, (z + halfZ) + fenceWidth);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, t - 3.0, (z + halfZ) + fenceWidth);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, t, (z + halfZ) + fenceWidth);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + halfX, y - halfY, (z + halfZ) + fenceWidth);
	glEnd();

	// top
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + halfX, y - halfY, (z + halfZ) + fenceWidth);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, t, (z + halfZ) + fenceWidth);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, t, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glEnd();

	// bottom
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + halfX, (y - halfY) - 3.0, (z + halfZ) + fenceWidth);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, t - 3.0, (z + halfZ) + fenceWidth);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, t - 3.0, z + halfZ);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + halfX, (y - halfY) - 3.0, z + halfZ);
	glEnd();

	// right
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + halfX, (y - halfY) - 3.0, z + halfZ);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + halfX, (y - halfY) - 3.0, (z + halfZ) + fenceWidth);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + halfX, y - halfY, (z + halfZ) + fenceWidth);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glEnd();

	float pointer = x - halfX;
	// ROOF END LR
	for (int i = 0; i < 2; i++) {
		// face
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(pointer, (y - halfY) - 3.0, z - halfZ);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(pointer, (y - halfY) - 3.0, z + halfZ);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(pointer, y - halfY, z + halfZ);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(pointer, y - halfY, z - halfZ);
		glEnd();

		// bottom
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(pointer, (y - halfY) - 3.0, z - halfZ);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(pointer, (y - halfY) - 3.0, z + halfZ);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(pointer + 2.0, (y - halfY) - 3.0, z + halfZ);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(pointer + 2.0, (y - halfY) - 3.0, z - halfZ);
		glEnd();

		// back
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(pointer + 2.0, (y - halfY) - 3.0, z - halfZ);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(pointer + 2.0, (y - halfY) - 3.0, z + halfZ);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(pointer + 2.0, y - halfY, z + halfZ);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(pointer + 2.0, y - halfY, z - halfZ);
		glEnd();

		// right
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(pointer, (y - halfY) - 3.0, z + halfZ);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(pointer + 2.0, (y - halfY) - 3.0, z + halfZ);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(pointer + 2.0, y - halfY, z + halfZ);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(pointer, y - halfY, z + halfZ);
		glEnd();

		pointer = (x + halfX) - fenceWidth;
	}
	glDisable(GL_TEXTURE_2D);
}
void prism(float x, float y, float z, float l, float t, GLuint texture) {
	float halfX = l / 2;
	float halfY = t / 2;
	float halfZ = l / 2;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Depan
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0, 0); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(1.f, 0); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(0, 0.5f); glVertex3f(x, t, z);
	glEnd();

	// Belakang
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0, 0); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.f, 0); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(0, 0.5f); glVertex3f(x, t, z);
	glEnd();

	// Kiri
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0, 0); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.f, 0); glVertex3f(x - halfX, y - halfY, z + halfZ);
	glTexCoord2f(0, 0.5f); glVertex3f(x, t, z);
	glEnd();

	// Kanan
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0, 0); glVertex3f(x + halfX, y - halfY, z - halfZ);
	glTexCoord2f(1.f, 0); glVertex3f(x + halfX, y - halfY, z + halfZ);
	glTexCoord2f(0, 0.5f); glVertex3f(x, t, z);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	// Bawah
	glBegin(GL_QUADS);
	glVertex3f(x - halfX, y - halfY, z + halfZ); glVertex3f(x + halfX, y - halfY, z + halfZ); glVertex3f(x + halfX, y - halfY, z - halfZ); glVertex3f(x - halfX, y - halfY, z - halfZ);
	glEnd();
}
void jendelaLR(float x, float y, float z, GLuint texture) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + 7.0, y, z);
	glTexCoord2f(1.0f, 0.85f); glVertex3f(x + 7.0, y + 22.0, z);
	glTexCoord2f(0.5f, 1.0f); glVertex3f(x + 3.5, y + 26.0, z);
	glTexCoord2f(0.0f, 0.85f); glVertex3f(x, y + 22.0, z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void jendelaFN(float x, float y, float z, GLuint texture) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + 5.0);
	glTexCoord2f(1.0f, 0.82f); glVertex3f(x, y + 18.0, z + 5.0);
	glTexCoord2f(0.5f, 1.0f); glVertex3f(x, y + 22.0, z + 2.5);
	glTexCoord2f(0.0f, 0.82f); glVertex3f(x, y + 18.0, z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void drawCircle(float z, int r)
{
	float radius = r;
	float twoPI = 2 * PI;

	glRotatef(270.0f, 0, 0, 1);
	glBegin(GL_TRIANGLE_FAN);
	for (float i = PI; i <= twoPI; i += 0.001)
	{
		glVertex3f((sin(i) * radius), (cos(i) * radius), z);
	}
	glEnd();
	glFlush();
}
void drawArc(float z, int r, int count)
{
	float radius = r;
	float twoPI = 2 * PI;
	float posZ = z;

	glRotatef(90.0f, 0, 0, 1);
	glPointSize(25.0f);
	glBegin(GL_POINTS);

	for (int i = 0; i < count; i++) {
		for (float i = 0.0; i <= twoPI / 2; i += 0.001) {
			glVertex3f((sin(i) * radius), (cos(i) * radius), posZ);
		}
		posZ = posZ += 0.5f;
	}
	glEnd();
	glFlush();
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
}
void renderBitmap(float x, float y, float z, void* font, char* string) {
	char* c;
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
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
	glColor3ub(255, 255, 255);
}