/*
* @Name:正方形平移 旋转 缩放变换 统一逆时针旋转45 
* @Author:twj
* @Date:2023-3-18
* 证明：通过矩阵的实际转变，证明了矩阵变换不具有交换性
* 总结：①只要了解矩阵的实际原理转换，很简单
*		②编写程序，最开始因为y坐标的数组搞错，导致旋转无法实现，写错坐标了，****细节很重要******
* 原因：
		①矩阵变换的角度去-----两个矩阵交换位置相乘结果不一样，从而导致了该现象
		②矩阵相乘不满足交换律
* 使用说明：
*		再源码中去掉注释，选择要运行的函数如：move_rotate(&vec[0],0.4, 0.4, 45);（第156行）
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
//先平移再旋转 同时绘画出来
void move_rotate(float vec[][2],float x, float y,float angle) {
	float** points;//存放变换点的数组
	points = new float* [4];
	for (int i = 0; i < 4; i++) {
		points[i] = new float[2];
	}
	//平移
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
	//旋转
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
//先旋转再平移 同时绘画出来
void rotate_move(float vec[][2], double angle,float x,float y) {
	float points[4][2];
	float a = angle / 180 * PI;
	//旋转
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
	//平移
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
//先缩放再旋转 同时绘画出来
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
	//旋转
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
//先旋转再缩放 同时绘画出来
void rotate_scale(float vec[][2],double angle, float sx, float sy) {
	float points[4][2];
	//旋转
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
	//缩放
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
	//绘画坐x，y标轴
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glVertex2f(0, 1);
	glVertex2f(0, -1);
	glEnd();

	//在原点画正方形
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 4; i++) {
		glVertex2fv(&vec[i][0]);
	}
	glEnd();

	//先平移再旋转
	move_rotate(&vec[0],0.4, 0.4, 45);//旋转45
	//先旋转再平移
	//rotate_move(&vec[0], 60, 0.4f, 0.4f);
	//先缩放再旋转
	//scale_rotate(&vec[0], 0.7, 0.7, 45);
	//先旋转再缩放
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
	glutCreateWindow("先平移再旋转");
	//glutCreateWindow("先旋转再平移");
	//glutCreateWindow("先缩放再旋转");
	//glutCreateWindow("先旋转再缩放");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
	return 0;
}