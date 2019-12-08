#include "Angel.h"

float X = 0;
float Y = 0;
vec2 pos[] = { vec2(0.2f, 0.1f), vec2(0.2f, 0.2f), vec2(0.3f, 0.2f), vec2(0.3f, 0.1f),
			   vec2(0.2f, 0.2f), vec2(0.1f, 0.2f), vec2(0.1f, 0.3f), vec2(0.2f, 0.3f),
			   vec2(0.3f, 0.2f), vec2(0.3f, 0.3f), vec2(0.4f, 0.3f), vec2(0.4f, 0.2f) };
int moveCount = 0;
vec2 mousecords;
vec2 dis[12] = { 0 };
bool move = false;
bool gravity = false;

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2fv(pos[0]);
	glVertex2fv(pos[1]);
	glVertex2fv(pos[2]);
	glVertex2fv(pos[3]);
	glVertex2fv(pos[4]);
	glVertex2fv(pos[5]);
	glVertex2fv(pos[6]);
	glVertex2fv(pos[7]);
	glVertex2fv(pos[8]);
	glVertex2fv(pos[9]);
	glVertex2fv(pos[10]);
	glVertex2fv(pos[11]);
	glColor3f(1.0f, 0.0f, 1.0f); 
	glVertex2f(-1.0f, 0.01f);
	glColor3f(1.0f, 0.0f, 1.0f); 
	glVertex2f(1.0f, 0.01f);
	glColor3f(1.0f, 0.0f, 1.0f); 
	glVertex2f(1.0f, -0.01f);
	glColor3f(1.0f, 0.0f, 1.0f); 
	glVertex2f(-1.0f, -0.01f);
	glEnd();
	glFlush();
}

void idle()
{
	if (moveCount < 100)
	{
		for (int f = 0; f < 12; f++)
		{
			pos[f].x += dis[f].x;
			pos[f].y += dis[f].y;
		}
		glutPostRedisplay();
		moveCount++;
	}
	if (move)
	{
		for (int v = 0; v < 12; v++)
		{
			pos[v].x += X;
			pos[v].y += Y;
		}
		X = 0; 
		Y = 0;
		move = false;
	}
	if (gravity)
	{
		for (size_t j = 0; j < 12; j++)
		{
			if (pos[0].y <= 0)
			{
				gravity = false;
				break;
			}
			pos[j].y -= 0.001;
		}
	}
	glutPostRedisplay();
}

vec2 ScreenToWorldPOint(int x, int y)
{
	vec2 worldPoint;
	worldPoint.x = (((float)x / 640) * 2) - 1;
	worldPoint.y = ((float)(640 - y) / 640 * 2) - 1;
	return worldPoint;
}

void mymouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mousecords = ScreenToWorldPOint(x, y);
		for (int f = 0; f < 12; f++)
		{
			dis[f].x = mousecords.x - pos[3].x;
			dis[f].y = mousecords.y - pos[3].y;
			dis[f].x /= 100;
			dis[f].y /= 100;
		}
		moveCount = 0;
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		gravity = true;
	}
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Rectangle Mover");
	glutDisplayFunc(myDisplay);
	glutIdleFunc(idle);
	glutMouseFunc(mymouse);
	glutMainLoop();
	return 0;
}


























//#include "Angel.h"
//#include <GL\glut.h>
//
//using namespace std;
//
//vec2 movePos;
//vec2 previousPos;
//float speed;
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glBegin(GL_LINES);
//	for (float i = 0.76f; i < 0.8f; i += 0.001f)
//	{
//		glColor3f(1.0f, 0.0f, 0.7f);
//		glVertex2f(-0.8f, -i);
//		glColor3f(1.0f, 0.0f, 0.7f);
//		glVertex2f(0.8f, -i);
//	}
//	for (float i = movePos.y; i < movePos.y + 0.055; i += 0.001f)
//	{
//		glColor3f(0.0f, 0.0f, 1.0f);
//		glVertex2f(0.0f + movePos.x, i);
//		glColor3f(0.0f, 0.0f, 1.f);
//		glVertex2f(0.25f + movePos.x, i);
//	}
//	for (float i = movePos.y; i < movePos.y + 0.055; i += 0.001f)
//	{
//		glColor3f(0.5f, 0.0f, 1.0f);
//		glVertex2f(0.05f + movePos.x, i + 0.055);
//		glColor3f(0.0f, 0.0f, 1.f);
//		glVertex2f(-0.1f + movePos.x, i + 0.055);
//	}
//	for (float i = movePos.y; i < movePos.y + 0.055; i += 0.001f)
//	{
//		glColor3f(0.5f, 0.0f, 1.0f);
//		glVertex2f(0.2f + movePos.x, i + 0.055);
//		glColor3f(0.5f, 0.0f, 1.f);
//		glVertex2f(0.35f + movePos.x, i + 0.055);
//	}
//	glEnd();
//	glFlush();
//}
//
//void myMouse(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		vec2 worldPoint;
//		worldPoint.x = ((float)x / 640 * 2) - 1;
//		worldPoint.y = ((float)(640 - y) / 640 * 2) - 1;
//		movePos = worldPoint;
//		speed = (movePos.x - (-0.5f)) / 60;
//	}
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
//	{
//		movePos.y = -0.755f;
//	}
//}
//
//void idle()
//{
//	for (float i = movePos.y; i < movePos.y + 0.055; i += 0.001f)
//	{
//		glColor3f(0.0f, 0.0f, 1.0f);
//		glVertex2f(0.0f + movePos.x, i);
//		glColor3f(0.0f, 0.0f, 1.f);
//		glVertex2f(0.25f + movePos.x, i);
//	}
//	for (float i = movePos.y; i < movePos.y + 0.055; i += 0.001f)
//	{
//		glColor3f(0.5f, 0.0f, 1.0f);
//		glVertex2f(0.05f + movePos.x, i + 0.055);
//		glColor3f(0.0f, 0.0f, 1.f);
//		glVertex2f(-0.1f + movePos.x, i + 0.055);
//	}
//	for (float i = movePos.y; i < movePos.y + 0.055; i += 0.001f)
//	{
//		glColor3f(0.5f, 0.0f, 1.0f);
//		glVertex2f(0.2f + movePos.x, i + 0.055);
//		glColor3f(0.5f, 0.0f, 1.f);
//		glVertex2f(0.35f + movePos.x, i + 0.055);
//	}
//	glutPostRedisplay();
//}
//
//int main(int argc, char** argv)
//{
//	movePos.x = -0.5f;
//	movePos.y = -0.755f;
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(640, 640);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Rectangle Mover");
//	glutDisplayFunc(display);
//	glutMouseFunc(myMouse);
//	glutIdleFunc(idle);
//	glutMainLoop();
//	return 0;
//}