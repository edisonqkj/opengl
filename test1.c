//#include <GL/gl.h>
//#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>

#define	WIDTH	300
#define	HEIGHT	200

//unsigned char texture[WIDTH][HEIGHT][3];

void init(){
	glClearColor(0,0,0,0);
	
	//glOrtho(0,1,0,1,-1,1);
}

void render(){
	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f();

	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
		glVertex3f(0,0,1);
		glVertex3f(1,0.5,0);
		glVertex3f(0,1,0);
	glEnd();

	glFlush();
	glutSwapBuffers();
}
void resize(int width,int height){
	printf("width=%d\theight=%d.\n",width,height);

	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(22.5,(GLfloat)width/(GLfloat)height,0.01,100);
	//glFrustum(-1,1,-1,1,1.5,20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	double eye[3]={5,0,0};
	double center[3]={0,0,0};
	
	gluLookAt(eye[0],eye[1],eye[2],center[0],center[1],center[2],
			0,0,1);
//	glutPostRedisplay();
}

void keypressed(unsigned char key,int x,int y){
	printf("key=%c.\n",key);
	glutPostRedisplay();
}

void mouseclicked(int btn,int state, int x, int y){
	printf("btn=%d\tstate=%d\t(%d,%d).\n",btn,state,x,y);
	glutPostRedisplay();
}

void motion(int x,int y){
	printf("(x,y):\t(%d,%d).\n",x,y);
	glutPostRedisplay();
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutCreateWindow("first");

	init();
	glutDisplayFunc(render);
	//render();
	glutReshapeFunc(resize);
	glutKeyboardFunc(keypressed);
	glutMouseFunc(mouseclicked);
	glutMotionFunc(motion);

	glutMainLoop();
	return 0;
}
