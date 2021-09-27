// OBJECT LIBRARY BY SEPTIAN TRIIRIAWAN PARAPAK
// 672016143

#ifndef OBJECT_H
#define OBJECT_H 

void rect(float, float, float, float, float, float);
void centeredRect(float x, float y, float z, float p, float l, float t, GLuint texture);
void texturedBlock(float x, float y, float z, float p, float l, float t, GLuint texture);
void block(float x, float y, float z, float p, float l, float t);
void atapH(float, float, float, float, float, float, GLuint, GLuint, GLuint);
void atapV(float, float, float, float, float, GLuint, GLuint, GLuint);
void prism(float, float, float, float, float, GLuint);
void jendelaLR(float x, float y, float z, GLuint);
void jendelaFN(float x, float y, float z, GLuint);
void drawArc(float z, int r, int count);
void drawCircle(float z, int r);
void kursiJemaat(float x, float y, float z, float p);
void renderBitmap(float x, float y, float z, void* font, char* string);
void title(float x, float y, float z, float p, float l, float t, GLuint textureTitle, GLuint textureSide, GLuint textureFoot);

#endif