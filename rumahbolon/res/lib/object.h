// OBJECT LIBRARY BY SEPTIAN TRIIRIAWAN PARAPAK
// 672016143

#ifndef OBJECT_H
#define OBJECT_H 

void centeredRect(float x, float y, float z, float p, float l, float t, GLuint texture);
void centeredTrap(float x, float y, float z, float p, float l, float t, GLuint texturesFN, GLuint textureLR, GLuint textureFloor, GLuint textureDoor);
void block(float x, float y, float z, float p, float l, float t);
void atapV(float x, float y, float z, float p, float l, float t, GLuint textureRoof, GLuint texturePanel, GLuint textureTriangle, GLuint textureLayer, GLuint textureCrossLR, GLuint textureCrossUD);
void kursiJemaat(float x, float y, float z, float p);
void bed(float x, float y, float z, float p, float l, float t, GLuint textureBed, GLuint textureFoot);
void meja(float x, float y, float z, float p, float l, float t);
void kursi(float x, float y, float z, float p, float l, float t);
void title(float x, float y, float z, float p, float l, float t, GLuint textureTitle, GLuint textureSide, GLuint textureFoot);

#endif