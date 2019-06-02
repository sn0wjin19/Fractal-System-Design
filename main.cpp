#include "Grammar.h"
#include "FractalSystem.h"
#include <corecrt_math_defines.h>
#include <GL/glut.h>
#include <Windows.h>
//#include <stdlib.h>
//#include <GL/glew.h>
//#include "ogldev_math_3d.h"
//#include "ogldev_util.h"

using namespace std;
float colors[13][3] = { {1.0, 1.0, 1.0}, {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {1.0, 1.0, 0.0}, {0.0, 0.0, 1.0}, {1.0, 0.0, 1.0}, {0.0, 1.0, 1.0}, {0.25, 0.25, 0.25},{0.75, 0.75, 0.75}, {0.60, 0.40, 0.12}, {0.98, 0.625, 0.12}, {0.98, 0.04, 0.7}, {0.60, 0.40, 0.70} };
// °×£¬ ºì£¬ ÂÌ£¬ »Æ£¬ À¶£¬ Ñóºì, Çà, Éî»Ò, Ç³»Ò, ºÖ£¬ ÄÏ¹Ï³È£¬ ·Ûºì£¬ °ÍÄá×Ï

vector<Trunk> trunks;
FractalSystem fs;
int winWidth = 800, winHeight = 600;

void myRender() {

	trunks = fs.trunks;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);//Çå¿Õ»º³åäÖÈ¾ÑÕÉ«
	glColor3f(1.0f, 1.0f, 1.0f);//ÉèÖÃÑÕÉ«

	int i = 0;
	int j = 0;
	float tem1[2], tem2[2];
	vec2 pos1, pos2;
	for (i = 0; i < trunks.size(); i++) {
		glBegin(GL_LINE_STRIP);
		pos1 = trunks.at(i).pos1;
		pos2 = trunks.at(i).pos2;
		tem1[0] = pos1.x;
		tem1[1] = pos1.y;
		tem2[0] = pos2.x;
		tem2[1] = pos2.y;
		glVertex2fv(tem1);//ÒÔ¶¥µã
		glVertex2fv(tem2);
		glEnd();
	}
	glFlush();
}

void changeSize(GLsizei w, GLsizei h)
{
	if (h == 0)
		h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
	{
		glOrtho(-960.0f, 960.0f, -50.0f, 900.0f, 1.0f, -1.0f);
	}
	else
	{
		glOrtho(-960.0f, 960.0f, -50.0f, 900.0f, 1.0f, -1.0f);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


int main(int argc, char* argv[]) {
	glutInit(&argc, argv);//³õÊ¼»¯GLUT¿â
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1920, 1080);
	glutCreateWindow("Fractal");
	fs = FractalSystem();
	fs.clearAll();
	fs.initGrammar();
	fs.generateFractal();

	glutDisplayFunc(myRender);
	glutReshapeFunc(changeSize);

	glutSwapBuffers();
	glutMainLoop();
	
	return 0;
}



