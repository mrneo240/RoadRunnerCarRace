#define WINDOWWIDTH 1366
#define WINDOWHEIGHT 768
#include "PrintData.h"
#include "PictureLoad.h"
#include "Lighting.h"
#include "Car.h"
#include "ScoreUpdate.h"
#include "CrashCondition.h"
#include "EnableAndDisableFunctions.h"
#include "Road.h"
#include "AllWindowScreenFunctions.h"




GLint FullScreen=1;

void intit()
{
   EnableLightingOnlyScreen();
   EnableTextureAndDepth();
   glShadeModel (GL_SMOOTH);
   glEnable(GL_COLOR_MATERIAL);  
  glutFullScreen();
   glClearDepth(1.0f);											
   glDepthFunc(GL_LEQUAL);								
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);
   glPointSize(10.0);
   glEnable(GL_POINT_SMOOTH);

   Cylinder = gluNewQuadric();
   gluQuadricDrawStyle( Cylinder, GLU_FILL );
   gluQuadricNormals( Cylinder, GLU_SMOOTH);
   gluQuadricOrientation( Cylinder, GLU_OUTSIDE);
   gluQuadricTexture( Cylinder, GL_TRUE);
} 

void reshape(int w,int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,glutGet(GLUT_WINDOW_WIDTH),-4.0,glutGet(GLUT_WINDOW_HEIGHT),-10,10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display()
{
	glClearColor(0.0, 0.0, 0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
	
	if(displayPlayGameScreen!=1){LoadXYpicture();}
	if(displayPlayGameScreen==1){EnableTextureAndDepth();DisableLighting();DisplayPlayGameScreen();}
		
	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key ,int mousex,int mousey)
{
static int old_x = 20;
static int old_y = 15;
static int old_width = 1366;
static int old_height = 768;

if(displayAskePlayerName==1)
{
	if(key==13)
	{
		displayAskePlayerName=0,displayPlayGameScreen=1;
		glDeleteTextures(512,&texture[0]);EnableLightingPlayGame();
		while(TopPlayerName<12){PlayerName[TopPlayerName++]=key;}
		TopPlayerName=0;
	}
	else
	{
	  if(key==8){if(TopPlayerName<=0){goto Down;}else TopPlayerName--; PlayerName[TopPlayerName]=NULL;goto Down;}
	  if(TopPlayerName>=10){goto Down;}
	  PlayerName[TopPlayerName]=key;
	  TopPlayerName++;
	  Down:LoadXYpicture();
	}
	return;
}

	switch(key)
	{
	case 8:  flag=5;
		       if(displayCarModelSelection==1)flag=7;
			   SelectScreen();
			   glutPostRedisplay();
		       break;
	  case 27: if(displayMainMenuScreen==1){flag=3;}
			   if(displayBeforeQuitGame==1) {flag=5;}
			   if(displayPlayGameScreen==1){ flag=6;}
			    SelectScreen();
			   glutPostRedisplay();
		       break;

	  case 13:
		   if(displayCarModelSelection==1)flag=8;
		   if(displayPlayGameScreen==1){if(c==1){flag=6;PlayerName[0]=NULL;}}
		   SelectScreen();
		   glutPostRedisplay();
		         break;

	  case 'f':
	  case 'F':FullScreen=!FullScreen;
		   if(FullScreen)
		   {
			old_x = glutGet(GLUT_WINDOW_X);
	        old_y = glutGet(GLUT_WINDOW_Y);
	        old_width = 1366;//glutGet(GLUT_WINDOW_WIDTH);
	        old_height = 768;//glutGet(GLUT_WINDOW_HEIGHT);
	        glutFullScreen();
		  }
		else
		  {
			glutReshapeWindow(old_width, old_height);
	        glutPositionWindow(old_x, old_y);

		   }
		  break;
	  case 'v':
	  case 'V':View=!View;if(View==1){rx=ry=rz=0;View=1;}
		 break;
	}

	
}

void Specialkeyboard(int key ,int x,int y)
{
	if(key==GLUT_KEY_DOWN )
	{ 
		if(displayMainMenuScreen==1){if(flag<3)flag++;if(flag==5)flag=1;}
		if(displayStartGameOption==1){if(flag<5)flag++;}
		if(displayGameLevelOption==1){if(flag<5)flag++;if(flag==4)flag++;}
		if(displayInstruction==1){flag=5;}
		if(displayScroe==1){flag=5;}
		if(displayBeforeQuitGame==1){flag=5;}
		if(displayPlayGameScreen==1){mcar=0;}
	}
	if(key==GLUT_KEY_UP)
	{ 
		if(displayMainMenuScreen==1){if(flag>1)flag--;if(flag==5)flag=1;}
		if(displayStartGameOption==1){if(flag>1)flag--;}
		if(displayGameLevelOption==1){if(flag>1)flag--;if(flag==4)flag--;}
		if(displayInstruction==1){flag=5;}
		if(displayScroe==1){flag=5;}
		if(displayBeforeQuitGame==1){flag=5;}
		if(displayPlayGameScreen==1){if(c!=1)mcar=1;}	

	}
	if(key==GLUT_KEY_LEFT )								//moving car left
	{
	if( mcar==1 && m>0){
		if(displayPlayGameScreen==1){
		if(level==1)m-=0.041;
		else if(l>=2)m-=0.054;
		else if(l>=3)m-=0.067;
		else if(level>2&&level<4)m-=0.08;
		else if(level==4)m-=0.25;
	    }
		}
		if(displayCarModelSelection==1)
		{
			flag=10;
			SelectScreen();
		}
	}
	if(key==GLUT_KEY_RIGHT)									//moving car right	
	{
	if(mcar==1 && m<=3)
		{
		if(displayPlayGameScreen==1){
		if(level==1)m+=0.041;
		else if(l>=2)m+=0.054;
		else if(l>=3)m+=0.067;
		else if(level>2&&level<4)m+=0.08;
		else if(level==4)m+=0.25;
		}
		}
		if(displayCarModelSelection==1)
		{
			flag=9;
			SelectScreen();
		}
	}
	glutPostRedisplay();
}


void Mouse(int button, int state, int x, int y)
{
	y=WINDOWHEIGHT-y;

	if(button==GLUT_LEFT_BUTTON &&state==GLUT_DOWN)
	{
		SelectScreen();
		glFlush();
	}
}

void passivemotion(int x,int y)
{
	y=WINDOWHEIGHT-y;

	CheckXYposition(x,y);
	if(displayPlayGameScreen!=1){LoadXYpicture();}
	
}

void Idle()
{
	if(displayPlayGameScreen==1)
	{
		levels();
       if(View==0)
       {
	   rx =30 * cos( angle );
	   ry = 30 * sin( angle );
	   rz = 30 * cos( angle );
	   if(ViewRotation==0){angle += 0.001;if (angle > 2.5)ViewRotation=1;}
	   if(ViewRotation==1){angle -= 0.001;if(angle<=0.5)ViewRotation=0;}
       }

	   DisplayPlayGameScreen();
	}
	if(displayCarModelSelection==1)
	{
		angle += 1.4;
	   	LoadXYpicture();
	}
}


int main()
{
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH);
   glutInitWindowSize (1366, 768);
   glutCreateWindow ("RoadRunner2.0");
   intit();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(Specialkeyboard);
   glutMouseFunc(Mouse);
   glutPassiveMotionFunc(passivemotion);
   glutIdleFunc(Idle);
   glutMainLoop();
}


