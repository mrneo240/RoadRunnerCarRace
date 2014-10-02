#include <GL/glut.h>
#include <windows.h>
#include <gl\gl.h>			
#include <gl\glut.h>			
#include <gl\glaux.h>
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


GLdouble rx,ry,rz,angle=0.6;
GLUquadricObj *Cylinder;
GLint ViewRotation=0,TopPlayerName=0;
char PlayerName[12];
GLfloat theta,m=2,color,mcar=0,l=0;
GLint x=0,i,circle,j,w=1,newobstacle=0,obs=1,score=0,crash=0,c=0,jj,level;
int body=14;
GLint AddLeft=0,AddRight=0;

GLint displayMainMenuScreen=1,displayStartGameOption=0,displayGameLevelOption=0,displayInstruction=0,displayScroe=0,displayBeforeQuitGame=0;
GLint flag=0,View=1,displayPlayGameScreen=0,selectcar=0,displayAskePlayerName=0,displayCarModelSelection=0;
int rem,temp,k,p;
char S[10]={'0'};

void *font = GLUT_BITMAP_TIMES_ROMAN_24;
void *fonts[] =
{
  GLUT_BITMAP_9_BY_15,
  GLUT_BITMAP_TIMES_ROMAN_10,
  GLUT_BITMAP_TIMES_ROMAN_24,
  GLUT_BITMAP_HELVETICA_10,
  GLUT_BITMAP_HELVETICA_12,
  GLUT_BITMAP_HELVETICA_18,
  GLUT_BITMAP_8_BY_13
};



void selectFont(int newfont)
{
  font = fonts[newfont];
}

void selectColor(int color)
{
  switch (color) 
  {
    case 1:glColor3f(0.0,0.0,0.0);break;//Black
    case 2:glColor3f(1.0, 0.0, 0.0);break;//Red
    case 3: glColor3f(0.0, 1.0, 0.0);break; //Green
	case 4:glColor3f(1.0, 1.0, 0.0);break;//Yellow
    case 5:glColor3f(0.0, 0.0, 1.0);break;//Blue
    case 6: glColor3f(1.0, 0.0, 1.0);break;//Magenta
	case 7:glColor3f(0.0, 1.0, 1.0);break;//Cyan
    case 8:glColor3f(0.25, 0.25, 0.25);break;//Dark gray
    case 9: glColor3f(0.75, 0.75,0.75);break;//Light gray
	case 10:glColor3f(0.60, 0.40, 0.12);break;//Brown
    case 12:glColor3f(0.98, 0.625, 0.12);break;//Pumpkin orange
    case 13: glColor3f(0.98, 0.04, 0.7);break;//Pastel pink
	case 14: glColor3f(0.60, 0.40, 0.70);break;//Barney purple
	case 15: glColor3f(1.0, 1.0, 1.0);break;//White
  }
}

void Sprint( int x, int y, char *string)
{
	int l,i;

	l=(int)strlen( string );
	glRasterPos3i( x, y, -1);
	for( i=0; i < l; i++)
	{
		glutBitmapCharacter(font, string[i]);
	}

}