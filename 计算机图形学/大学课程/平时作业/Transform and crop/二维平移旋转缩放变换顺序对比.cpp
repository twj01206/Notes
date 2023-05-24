/*
* @Name:������ƽ�� ��ת ���ű任 ͳһ��ʱ����ת45 
* @Author:twj
* @Date:2023-3-18
* ֤����ͨ�������ʵ��ת�䣬֤���˾���任�����н�����
* �ܽ᣺��ֻҪ�˽�����ʵ��ԭ��ת�����ܼ�
*		�ڱ�д�����ʼ��Ϊy�����������������ת�޷�ʵ�֣�д�������ˣ�****ϸ�ں���Ҫ******
* ԭ��
		�پ���任�ĽǶ�ȥ-----�������󽻻�λ����˽����һ�����Ӷ������˸�����
		�ھ�����˲����㽻����
* ʹ��˵����
*		��Դ����ȥ��ע�ͣ�ѡ��Ҫ���еĺ����磺move_rotate(&vec[0],0.4, 0.4, 45);����156�У�
*/
#include<glut.h>
#include<iostream>
#include<math.h>
#define PI 3.1415926
using namespace std;
float vec[4][2] = {
	{ -0.2f,-0.2f},
	{-0.2f,0.2f },
	{0.2f,0.2f},
	{0.2f,-0.2f}
};
//��ƽ������ת ͬʱ�滭����
void move_rotate(float vec[][2],float x, float y,float angle) {
	float** points;//��ű任�������
	points = new float* [4];
	for (int i = 0; i < 4; i++) {
		points[i] = new float[2];
	}
	//ƽ��
	for (int i = 0; i < 4; i++) {
		points[i][0] = vec[i][0] + x;
		points[i][1] = vec[i][1] + y;
	}
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);

	for (int i = 0; i < 4; i++) {
		glVertex2fv(&points[i][0]);
	}
	glEnd();
	//��ת
	float a = angle / 180 * PI;
	for (int i = 0; i < 4; i++) {
		points[i][0] = points[i][0] * cos(a) - points[i][1] * sin(a);
		points[i][1] = points[i][0] * sin(a) + points[i][1] * cos(a);
	}
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 4; i++) {
		glVertex2fv(&points[i][0]);
	}
	glEnd();
}
//����ת��ƽ�� ͬʱ�滭����
void rotate_move(float vec[][2], double angle,float x,float y) {
	float points[4][2];
	float a = angle / 180 * PI;
	//��ת
	for (int i = 0; i < 4; i++) {
		points[i][0] = vec[i][0] * cos(a) - vec[i][1] * sin(a);
		points[i][1] = vec[i][0] * sin(a) + vec[i][1] * cos(a);
	}
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 4; i++) {
		glVertex2fv(&points[i][0]);
	}
	glEnd();
	//ƽ��
	for (int i = 0; i < 4; i++) {
		points[i][0] = points[i][0] + x;
		points[i][1] = points[i][1] + y;
	}
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 4; i++) {
		glVertex2fv(&points[i][0]);
	}
	glEnd();
}
//����������ת ͬʱ�滭����
void scale_rotate(float vec[][2], float sx, float sy, float angle) {
	float points[4][2];
	for (int i = 0; i < 4; i++) {
		points[i][0] = vec[i][0] * sx;
		points[i][1] = vec[i][1] * sy;
	}
	glColor3f(0.5, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 4; i++) {
		glVertex2fv(&points[i][0]);
	}
	glEnd();
	//��ת
	float a = angle * PI / 180;
	for (int i = 0; i < 4; i++) {
		points[i][0] = points[i][0] * cos(a) - points[i][1] * sin(a);
		points[i][1] = points[i][0] * sin(a) + points[i][1] * cos(a);
	}
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 4; i++) {
		glVertex2fv(&points[i][0]);
	}
	glEnd();
}
//����ת������ ͬʱ�滭����
void rotate_scale(float vec[][2],double angle, float sx, float sy) {
	float points[4][2];
	//��ת
	float a = angle / 180 * PI;
	for (int i = 0; i < 4; i++) {
		points[i][0] = vec[i][0] * cos(a) - vec[i][1] * sin(a);
		points[i][1] = vec[i][0] * sin(a) + vec[i][1] * cos(a);
	}
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 4; i++) {
		glVertex2fv(&points[i][0]);
	}
	glEnd();
	//����
	for (int i = 0; i < 4; i++) {
		points[i][0] = points[i][0] * sx;
		points[i][1] = points[i][1] * sy;
	}
	glColor3f(0.5, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 4; i++) {
		glVertex2fv(&points[i][0]);
	}
	glEnd();
}
void display() {
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	//�滭��x��y����
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glVertex2f(0, 1);
	glVertex2f(0, -1);
	glEnd();

	//��ԭ�㻭������
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 4; i++) {
		glVertex2fv(&vec[i][0]);
	}
	glEnd();

	//��ƽ������ת
	move_rotate(&vec[0],0.4, 0.4, 45);//��ת45
	//����ת��ƽ��
	//rotate_move(&vec[0], 60, 0.4f, 0.4f);
	//����������ת
	//scale_rotate(&vec[0], 0.7, 0.7, 45);
	//����ת������
	//rotate_scale(&vec[0], 60, 0.6, 0.6);
	
	//glutSwapBuffers();
	glFlush();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	//glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(600, 600);
	glutCreateWindow("��ƽ������ת");
	//glutCreateWindow("����ת��ƽ��");
	//glutCreateWindow("����������ת");
	//glutCreateWindow("����ת������");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
	return 0;
}