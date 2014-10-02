void EnableLightingOnlyScreen()
{
    glLightfv(GL_LIGHT1 ,GL_AMBIENT, LightAmbientOnlyScreen);
    glLightfv(GL_LIGHT1 ,GL_DIFFUSE, LightDiffuseOnlyScreen);
    glLightfv(GL_LIGHT1 ,GL_POSITION, LightPositionOnlyScreen);
	glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);
}

void EnableLightingPlayGame()
{
   glLightfv(GL_LIGHT1 ,GL_AMBIENT, LightAmbientOnlyPlayGame);
   glLightfv(GL_LIGHT1 ,GL_DIFFUSE, LightDiffuseOnlyPlayGame);
   glLightfv(GL_LIGHT1 ,GL_POSITION, LightPositionOnlyPlayGame);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT1);
}

void DisableLighting()
{
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT1);
}

void EnableTextureAndDepth()
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
}

void DisableTextureAndDepth()
{
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
}

void EnableOrtho()
{
	DisableTextureAndDepth();
	glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, WINDOWWIDTH, 0, WINDOWHEIGHT, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
	glPushMatrix();
}

void DisableOrtho()
{
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    EnableTextureAndDepth();
}


void BorderStyle()
{
	GLint TempBoby=8;
	if(displayCarModelSelection!=1)TempBoby=body;
   // DisableTextureAndDepth();
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(25.0, 1.0, 3.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	gluLookAt(3.9, -18.0, 11.0, 6.0,19.0, 0.5,0, 0, 4.0);

	glPushMatrix();
	//selectColor(13);
	//glColor3f(1.0,0.2,0.5);
	f1b(TempBoby+1);
	glTranslatef(0.84,-1,2.2);				
	glRotatef(92,0,1,0);
	gluCylinder(Cylinder,0.2,0.2,8.15,50,50);
	glPopMatrix();

	glPushMatrix();
	//selectColor(10);
	f1b(TempBoby-2);
	glTranslatef(-13.89,111,2.2);				
	glRotatef(90.5,0,1,0);
	gluCylinder(Cylinder,1.5,1.5,50.9,50,50);
	glPopMatrix();
			
	glPushMatrix();
	//selectColor(12);
	//glColor3f(1.0,0.2,0.5);
	f1b(TempBoby-1);
	glTranslatef(0.85,-0.2,2.1);				
    glRotatef(6,1,1,1);
	gluCylinder(Cylinder,0.2,0.15,7.8,50,50);
	glPopMatrix();

	glPushMatrix();
	//selectColor(7);
	f1b(TempBoby);
	glTranslatef(8.95,-0.8,2.1);				
    glRotatef(-4.7,1,1,1);
	gluCylinder(Cylinder,0.2,0.15,7.8,50,50);
	glPopMatrix();
}
