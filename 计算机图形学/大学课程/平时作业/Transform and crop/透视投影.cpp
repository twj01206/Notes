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

    // ����ͶӰ����
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)windowWidth / windowHeight, 1.0, 100.0);

    // ����ģ����ͼ����
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(4.0, 4.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // ����������
    glColor3f(1.0, 0, 0);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndices);
    glDisableClientState(GL_VERTEX_ARRAY);

    // ˢ�»���
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    windowWidth = w;
    windowHeight = h;
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
}