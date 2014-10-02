#pragma comment(lib,"glaux.lib")
GLuint	filter;				
GLuint	texture[3];			
AUX_RGBImageRec *TextureImage[1];   

AUX_RGBImageRec *LoadBMP(char *Filename)              
{
        FILE *File=NULL;                              

        if (!Filename)                                 
        {
                return NULL;                          
        }

        File=fopen(Filename,"r");                     

        if (File)                                       
        {
                fclose(File);                           
               return auxDIBImageLoadA( (const char*) Filename );
        }
        return NULL;                                   
}

int LoadFromFloder(int id)
{
	switch(id)
	{
		glDeleteTextures(516,&texture[0]);
	  case 3: TextureImage[0]= LoadBMP("Data/3.bmp");return 1;
	  case 4: TextureImage[0]= LoadBMP("Data/4.bmp");return 1;
	  case 5: TextureImage[0]= LoadBMP("Data/5.bmp");return 1;
	  case 6: TextureImage[0]= LoadBMP("Data/6.bmp");return 1;
	  case 7: TextureImage[0]= LoadBMP("Data/7.bmp");return 1;
	}
	return 0;
}


int LoadGLTextures(int id)									
{
	 int Status=FALSE;                                

        memset(TextureImage,0,sizeof(void *)*1);        

       
       if(LoadFromFloder(id))
	   {
        
                Status=TRUE;									

		glGenTextures(1, &texture[0]);					

		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	   }
        if (TextureImage[0])                           
        {
                if (TextureImage[0]->data)             
                {
                        free(TextureImage[0]->data);    
                }

                free(TextureImage[0]);                 
        }

        return Status; 
}

void LoadPicture(int Color,float x,float y,int id)
{
	LoadGLTextures(id);
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);						
	glLoadIdentity();									
	gluPerspective(45.0f,1,1.0f,100.0f);
	glMatrixMode(GL_MODELVIEW);							
	glLoadIdentity();

	glTranslatef(x,y,-30.0f);
	glBindTexture(GL_TEXTURE_2D, texture[filter]);
	selectColor(Color);
	glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
	glEnd();
	glPopMatrix();
}
