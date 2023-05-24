//#include<glut.h>
//#include<vector>
//#include<iostream>
//using namespace std;
//const float SIZE = 200.0f;
//class Point3 {
//public:
//	float x, y, z;
//public:
//	//һ������
//	Point3(float x, float y, float z) {
//		this->x = x;
//		this->y = y;
//		this->z = z;
//	}
//};
//class CUVN {
//public:
//	float x, y, z;
//	float d;
//	Point3 xyz[3];
//	Point3 Pxyz[3];
//public:
//	/*CUVN(float Eye_x, float REye_y,float Eye_z,float d) {
//		this->Eye_x = Eye_x;
//		this->Eye_y = Eye_y;
//		this->Eye_z = Eye_z;
//		this->d = d;
//	}*/
//	CUVN();
//	void setPoint3();//
//	void calue(Point3 xyz[],float d);//ת������
//	void display();
//};
//void CUVN::setPoint3() {
//	xyz[0] = { 0.5f, 0.5f, 0.0f };
//	xyz[1] = { -0.5f, -0.5f, 0.0f };
//	xyz[2] = { 0.5f, -0.5f, 0.0f };
//}	
//
//void CUVN::calue(Point3 xyz[], float d) {
//	float px, py, pz;
//	for (int i = 0; i < 3; i++) {
//		px = xyz[i].x / d;
//		py = xyz[i].y / d;
//		pz = d;
//		Pxyz[i] = { px, py, pz };
//	}
//}
//void display() {
//	CUVN cuvn;
//	cuvn.calue(cuvn.xyz, 2);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.0, 0.0, 1.0);
//	for (int i = 0; i < 3; i++) {
//		glBegin(GL_LINE_STRIP);
//		glVertex3f(cuvn.Pxyz[i].x,cuvn.Pxyz[i].y, cuvn.Pxyz[i].z);
//		glEnd();
//	}
//	glutSwapBuffers();
//}
//
//int main(int argc, char** argv)
//{
//	CUVN cuvn;
//	glutInit(&argc, argv);
//	//glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
//	glutInitWindowPosition(200, 200);
//	glutInitWindowSize(600, 600);
//	glutCreateWindow("");
//	glutDisplayFunc(display);
//	glutMainLoop();
//	return 0;
//}
/*
#include <glut.h>
#include <math.h>
GLfloat vertices[][3] = {
        {-1.0, -1.0, -1.0},
        {1.0, -1.0, -1.0},
        {1.0, 1.0, -1.0},
        {-1.0, 1.0, -1.0},
        {-1.0, -1.0, 1.0},
        {1.0, -1.0, 1.0},
        {1.0, 1.0, 1.0},
        {-1.0, 1.0, 1.0}
};
// ����������������Ķ�������
GLubyte cubeIndices[] = {
    0, 3, 2, 1,
    2, 3, 7, 6,
    0, 4, 7, 3,
    1, 2, 6, 5,
    4, 5, 6, 7,
    0, 1, 5, 4
};

// ���崰�ڵĿ���
int windowWidth = 800;
int windowHeight = 600;

void display()
{
    // ���ñ���ɫ
    glClearColor(0.0, 1.0, 0.0, 1.0);

    // ������Ȳ���
    glEnable(GL_DEPTH_TEST);
    // �����ɫ����Ȼ���
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -5);
    //gluPerspective(60.0, (double)windowWidth / windowHeight, 1.0, 100.0);
    // 
    //gluLookAt(4.0, 4.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // ����������
    glColor3f(1.0, 0, 0);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndices);
    glDisableClientState(GL_VERTEX_ARRAY);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //����ƽ�в���
    float left = -2.0, right = 2.0, bottom = -2.0, top = 2.0, near = 1.0,far = 10.0;
    glOrtho(left, right, bottom, top, near, far);
    // ˢ�»���
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    windowWidth = w;
    windowHeight = h;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    // ��ʼ��GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Perspective Projection - Cube");

    // ע��ص�����
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // �����¼�ѭ��
    glutMainLoop();
    return 0;
}*/
/**/


//͸��ͶӰ
#include <glut.h>
#include <GL/glu.h>

void display() {
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);

    // �����������������
    glutWireCube(2.0f);

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // ����ƽ��ͶӰ����
    float left = -2.0f, right = 2.0f, bottom = -2.0f, top = 2.0f, near = 4.0f, far = 10.0f;
    glOrtho(left, right, bottom, top, near, far);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("ƽ��ͶӰ");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}