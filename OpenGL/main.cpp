#include <GL/glut.h>
#include <cmath>
#include <iostream>

// -------------------------------------------------------------------------
#define _PI      3.1415926535897932
#define _2PI     6.28318530718

float rot1 = 0;
float rot2 = 0;
float rot3 = 0;
float rot4 = 0;
float rot5 = 0;
float tra1 = 0;
float tra2 = 0;
float tra3 = 0;
float tra4 = 0;
float tra5 = 0;
float tra6 = 0;
float camAngleX = 0;
float camAngleY = 0;

float zoom = 30;
// -------------------------------------------------------------------------
void DrawUnitaryCube( )
{
  float colors[ 8 ][ 3 ] =
  {
    { 1, 0, 0 },
    { 0, 1, 0 },
    { 0, 0, 1 },
    { 0, 1, 1 },
    { 1, 0, 1 },
    { 1, 1, 0 },
    { 0.5, 0.5, 0.5 },
    { 1, 1, 1 }
  };

  float points[ 8 ][ 3 ] =
  {
    {-0.5, -0.5, -0.5},
    {0.5, -0.5, -0.5},
    {-0.5, -0.5, 0.5},
    { 0.5, -0.5, 0.5 },
    { -0.5, 0.5, -0.5 },
    { -0.5, 0.5, 0.5 },
    { 0.5, 0.5, -0.5 },
    { 0.5, 0.5, 0.5 }
  };

  unsigned int faces[ 6 ][ 4 ] =
  {
    { 0, 1, 3, 2 },
    { 0, 2, 5, 4 },
    { 2, 3, 7, 5 },
    { 5, 7, 6, 4 },
    { 1, 6, 7, 3 },
    { 1, 0, 4, 6 }
  };

  for( unsigned int i = 0; i < 6; ++i )
  {
    glBegin( GL_LINE_LOOP );
    {
      for( unsigned int j = 0; j < 4; ++j )
      {
        glColor3fv( colors[ faces[ i ][ j ] ] );
        glVertex3fv( points[ faces[ i ][ j ] ] );
      } // end for
    }
    glEnd( );
  } // end for
}
// -------------------------------------------------------------------------
void DrawCircle( GLenum mode, unsigned int samples )
{
  glBegin( mode );
  for( unsigned int i = 0; i < samples; ++i )
  {
    float t = _2PI * float( i ) / float( samples );
    glVertex3f(std::cos( t ), 0,std::sin( t ) );
  } // end if
  glEnd( );
}
// -------------------------------------------------------------------------
void DrawEllipse( GLenum mode, unsigned int samples,int rx,int ry )
{
  glBegin( mode );
  for( unsigned int i = 0; i < samples; ++i )
  {
    float t = _2PI * float( i ) / float( samples );
    glVertex3f(rx*std::cos( t ), 0,ry*std::sin( t ) );
  } // end if
  glEnd( );
}
// -------------------------------------------------------------------------
void DrawUnitaryPyramid( )
{
  float colors[ 5 ][ 3 ] =
  {
    { 1, 0, 0 },
    { 0, 1, 0 },
    { 0, 0, 1 },
    { 0, 1, 1 },
    { 1, 0, 1 }
  };

  float points[ 5 ][ 3 ] =
  {
    { -0.5, -0.5, -0.5 },
    { 0.5, -0.5, -0.5 },
    { -0.5, -0.5, 0.5 },
    { 0.5, -0.5, 0.5 },
    { 0, 0.366, 0 }
  };

  unsigned int faces[ 5 ][ 4 ] =
  {
    {0,1,3,2},
    {0,2,4,0},
    {2,3,4,0},
    {1,4,3,0},
    {1,0,4,0}
  };


  for( unsigned int j = 0; j < 4; ++j )
  {
      glColor3fv( colors[ faces[ 0 ][ j ] ] );
      glVertex3fv( points[ faces[ 0 ][ j ] ] );
  } // end for
  for( unsigned int i = 1; i < 5; ++i )
  {
    glBegin( GL_LINE_LOOP );
    {
      for( unsigned int j = 0; j < 3; ++j )
      {
        glColor3fv( colors[ faces[ i ][ j ] ] );
        glVertex3fv( points[ faces[ i ][ j ] ] );
      } // end for
    }
    glEnd( );
  } // end for
}


// -------------------------------------------------------------------------
void DrawUnitaryOctahedron( )
{
  float colors[ 6 ][ 3 ] =
  {
    { 1, 0, 0 },
    { 0, 1, 0 },
    { 0, 0, 1 },
    { 0, 1, 1 },
    { 1, 0, 1 },
    { 0, 1, 0 }
  };

  float points[ 6 ][ 3 ] =
  {
    { -0.5, 0, -0.5 },
    { 0.5,  0, -0.5 },
    { -0.5, 0, 0.5 },
    { 0.5,  0, 0.5 },
    { 0, 0.866, 0 },
    { 0, -0.866, 0}
  };

  unsigned int faces[ 8 ][ 3 ] =
  {
    {0,2,4},
    {2,3,4},
    {1,4,3},
    {1,0,4},
    {1,5,0},
    {0,5,2},
    {2,5,3},
    {1,3,5}
  };


  for( unsigned int i = 1; i < 8; ++i )
  {
    glBegin( GL_LINE_LOOP );
    {
      for( unsigned int j = 0; j < 3; ++j )
      {
        glColor3fv( colors[ faces[ i ][ j ] ] );
        glVertex3fv( points[ faces[ i ][ j ] ] );
      } // end for
    }
    glEnd( );
  } // end for
}
// -------------------------------------------------------------------------
void DrawUnitaryTetrahedron( )
{
  float colors[ 4 ][ 3 ] =
  {
    { 1, 0, 0 },
    { 0, 1, 0 },
    { 0, 0, 1 },
    { 0, 1, 1 }
  };

  float points[ 4 ][ 3 ] =
  {
    { 0, -0.288, 0.578 },
    { -0.5, -0.288, -0.288 },
    { 0.5, -0.288, -0.288 },
    { 0, 0.578, 0 }
  };

  unsigned int faces[ 4 ][ 3 ] =
  {
    {0,1,2},
    {0,2,3},
    {1,3,2},
    {1,0,3}
  };

  for( unsigned int i = 1; i < 4; ++i )
  {
    glBegin( GL_LINE_LOOP );
    {
      for( unsigned int j = 0; j < 3; ++j )
      {
        glColor3fv( colors[ faces[ i ][ j ] ] );
        glVertex3fv( points[ faces[ i ][ j ] ] );
      } // end for
    }
    glEnd( );
  } // end for
}

// -------------------------------------------------------------------------

void Init( )
{
  glClearColor( 0.7, 0.7, 0.7, 0.0 );
}

// -------------------------------------------------------------------------
void ResizeCbk( int width, int height )
{
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  glViewport( 0, 0, width, height );

  // Prespective
  gluPerspective(
    45,
    float( width ) / float( height ),
    0.01, 200
    );
}

// -------------------------------------------------------------------------
void DisplayCbk( )
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glMatrixMode( GL_MODELVIEW );
  float eyeX,eyeY,eyeZ;

  eyeX = zoom * sinf(camAngleX*(_PI/180))*cosf(camAngleY*(_PI/180));
  eyeY = zoom * -sinf(camAngleY*(_PI/180));
  eyeZ = zoom * cosf(camAngleX*(_PI/180))*cosf(camAngleY*(_PI/180));
  // Camara
  glLoadIdentity( );
  gluLookAt( eyeX, eyeY, eyeZ, 0, 0, 0, 0, 1, 0 );

  //Sol
  glPushMatrix( );
  glScalef(2.5,2.5,2.5);
  glRotatef(rot1,0,1,0);
  DrawUnitaryOctahedron();
  glPopMatrix();

  //Planeta 1
   //Anillo
  glPushMatrix( );
  glColor3f(0.4, 0.254, 0.0392);
  glScalef(4,4,4);
  glRotatef(40,20,20,10);
  DrawCircle(GL_LINE_LOOP,100);
  glPopMatrix();
   //Planeta
  glPushMatrix( );
  glColor3f(0.4, 0.254, 0.0392);
  glRotatef(40,20,20,10);
  glTranslatef(4*std::cos(tra2),0,4*std::sin(tra2));
  glRotatef(40,-20,0,-10);
  glRotatef(rot1,0,1,0);
  glScalef(1.7,1.7,1.7);
  DrawUnitaryTetrahedron();
  glPopMatrix();

  //Planeta 2
   //Anillo
      glPushMatrix( );
      glColor3f(0.4, 0.254, 0.0392);
      glScalef(3,3,3);
      glTranslatef(-0.5,0,0);
      glRotatef(40,0,20,0);
      DrawEllipse(GL_LINE_LOOP,100,2,3);
      glPopMatrix();
   //Planeta
      glPushMatrix( );
      glTranslatef(-0.5,0,0);
      glRotatef(40,0,20,0);
      glTranslatef(6*std::cos(tra4),0,9*std::sin(tra4));
      glRotatef(40,0,-20,0);
      glRotatef(rot2,0,1,0);
      glScalef(1.5,1.5,1.5);
      DrawUnitaryCube();
      glPopMatrix();
      //Lunas
        //Anillo Luna 1
          glPushMatrix( );
          glColor3f(0.4, 0.254, 0.0392);
          glTranslatef(-0.5,0,0);
          glRotatef(40,0,20,0);
          glTranslatef(6*std::cos(tra4),0,9*std::sin(tra4));
          glRotatef(90,0,-20,90);
          glScalef(2,2,2);
          DrawCircle(GL_LINE_LOOP,100);
          glPopMatrix();
        //Luna 1
          glPushMatrix( );
          glTranslatef(-0.5,0,0);
          glRotatef(40,0,20,0);
          glTranslatef(6*std::cos(tra4),0,9*std::sin(tra4));
          glRotatef(90,0,-20,90);
          glTranslatef(2*std::cos(tra2),0,2*std::sin(tra2));
          glScalef(0.5,0.5,0.5);
          glRotatef(10,-20,0,-10);
          glRotatef(rot3,0,1,0);
          DrawUnitaryOctahedron();
          glPopMatrix();

  //Planeta 3
    //Anillo
      glPushMatrix( );
      glColor3f(0.4, 0.254, 0.0392);
      glScalef(3,3,3);
      glTranslatef(0,-0.5,0);
      glRotatef(90,0,10,90);
      DrawEllipse(GL_LINE_LOOP,100,3,4);
      glPopMatrix();
    //Planeta
      glPushMatrix( );
      glTranslatef(0,-0.5,0);
      glRotatef(90,0,10,90);
      glTranslatef(9*std::cos(tra6),0,12*std::sin(tra6));
      glRotatef(30,10,10,-60);
      glRotatef(rot1,0,1,0);
      glScalef(1.4,1.4,1.4);
      DrawUnitaryPyramid();
      glPopMatrix();
      //Lunas
        //Anillo Luna 1
          glPushMatrix( );
          glColor3f(0.4, 0.254, 0.0392);
          glRotatef(90,0,10,90);
          glTranslatef(9*std::cos(tra6),0,12*std::sin(tra6));
          glRotatef(90,90,-10,-90);
          glScalef(1.7,1.5,1.5);
          DrawCircle(GL_LINE_LOOP,100);
          glPopMatrix();
        //Luna 1
          glPushMatrix( );
          glRotatef(90,0,10,90);
          glTranslatef(9*std::cos(tra6),0,12*std::sin(tra6));
          glRotatef(90,90,-10,-90);
          glTranslatef(1.7*std::cos(tra4),0,1.5*std::sin(tra4));
          glScalef(0.6,0.6,0.6);
          glRotatef(70,30,15,10);
          glRotatef(rot5,0,1,0);
          DrawUnitaryPyramid();
          glPopMatrix();
  //Planeta 4
   //Anillo
      glPushMatrix( );
      glColor3f(0.4, 0.254, 0.0392);
      glTranslatef(0,0,-0.5);
      glRotatef(60,25,10,30);
      glScalef(15,15,15);
      DrawCircle(GL_LINE_LOOP,100);
      glPopMatrix();
    //Planeta
      glPushMatrix( );
      glTranslatef(0,0,-0.5);
      glRotatef(60,25,10,30);
      glTranslatef(15*std::cos(tra1),0,15*std::sin(tra1));
      glRotatef(60,25,-10,-30);
      glRotatef(rot3,0,1,0);
      glScalef(1.5,1.5,1.5);
      DrawUnitaryPyramid();
      glPopMatrix();
        //Anillo Luna 1
          glPushMatrix( );
          glColor3f(0.4, 0.254, 0.0392);
          glTranslatef(0,0,-0.5);
          glRotatef(60,25,10,30);
          glTranslatef(15*std::cos(tra1),0,15*std::sin(tra1));
          glRotatef(90,0,0,90);
          glScalef(3,3,3);
          DrawCircle(GL_LINE_LOOP,100);
          glPopMatrix();
        //Luna 1
          glPushMatrix( );
          glTranslatef(0,0,-0.5);
          glRotatef(60,25,10,30);
          glTranslatef(15*std::cos(tra1),0,15*std::sin(tra1));
          glRotatef(90,0,0,90);
          glTranslatef(3*std::cos(tra3),0,3*std::sin(tra3));
          glScalef(1,1,1);
          glRotatef(40,-20,0,-10);
          glRotatef(rot1,0,1,0);
          DrawUnitaryTetrahedron();
          glPopMatrix();
        //Anillo Luna 2
          glPushMatrix( );
          glColor3f(0.4, 0.254, 0.0392);
          glTranslatef(0,0,-0.5);
          glRotatef(60,25,10,30);
          glTranslatef(15*std::cos(tra1),0,15*std::sin(tra1));
          glRotatef(70,20,24,90);
          glScalef(4,4,4);
          DrawCircle(GL_LINE_LOOP,100);
          glPopMatrix();
        //Luna 2
          glPushMatrix( );
          glTranslatef(0,0,-0.5);
          glRotatef(60,25,10,30);
          glTranslatef(15*std::cos(tra1),0,15*std::sin(tra1));
          glRotatef(70,20,24,90);
          glTranslatef(4*std::cos(tra4),0,4*std::sin(tra4));
          glScalef(1,1,1);
          glRotatef(rot2,0,1,0);
          DrawUnitaryCube();
          glPopMatrix();
        //Anillo Luna 3
          glPushMatrix( );
          glColor3f(0.4, 0.254, 0.0392);
          glTranslatef(0,0,-0.5);
          glRotatef(60,25,10,30);
          glTranslatef(15*std::cos(tra1),0,15*std::sin(tra1));
          glRotatef(20,80,54,90);
          glScalef(6,6,6);
          DrawCircle(GL_LINE_LOOP,100);
          glPopMatrix();
        //Luna 3
          glPushMatrix( );
          glTranslatef(0,0,-0.5);
          glRotatef(60,25,10,30);
          glTranslatef(15*std::cos(tra1),0,15*std::sin(tra1));
          glRotatef(20,80,54,90);
          glTranslatef(6*std::cos(tra2),0,6*std::sin(tra2));
          glScalef(1.3,1.3,1.3);
          glRotatef(60,20,14,-40);
          glRotatef(rot5,0,1,0);
          DrawUnitaryOctahedron();
          glPopMatrix();



  // Finish
  glutSwapBuffers( );
}

void IdleCbk()
{
    rot1 += 0.3;
    if(rot1 >=360)
    {
        rot1 = 0;
    }
    rot2 += 0.5;
    if(rot2 >=360)
    {
        rot2 = 0;
    }
    rot3 += 0.8;
    if(rot3 >=360)
    {
        rot3 = 0;
    }
    rot4 += 1.2;
    if(rot4 >=360)
    {
        rot4 = 0;
    }
    rot5 += 1.5;
    if(rot5 >=360)
    {
        rot5 = 0;
    }
    tra1 +=  0.0006;
    if(tra1>= 360)
    {
        tra1 = 0;
    }
    tra2 +=  0.0008;
    if(tra2>= 360)
    {
        tra2 = 0;
    }
    tra3 +=  0.001;
    if(tra3>= 360)
    {
        tra3 = 0;
    }
    tra4 +=  0.004;
    if(tra4>= 360)
    {
        tra4 = 0;
    }
    tra5 +=  0.0065;
    if(tra5>= 360)
    {
        tra5 = 0;
    }
    tra6 +=  0.0075;
    if(tra6>= 360)
    {
        tra6 = 0;
    }

    glutPostRedisplay();
}

void SpecialKeyboardCbk( int key, int x, int y )
{
    switch (key){
        case GLUT_KEY_RIGHT:
        camAngleX += 1;
        break;
    case GLUT_KEY_LEFT:
        camAngleX -= 1;
        break;
    case GLUT_KEY_UP:
        camAngleY += 1;
        break;
    case GLUT_KEY_DOWN:
        camAngleY -= 1;
        break;
    }
    if(camAngleX >= 360)
    {
        camAngleX = 0;
    }
    else if(camAngleX < 0)
    {
        camAngleX = 360+camAngleX;
    }
    if(camAngleY >= 360)
    {
        camAngleY = 0;
    }
    else if(camAngleY < 0)
    {
        camAngleY = 360+camAngleY;
    }
    std::cout << camAngleY << std::endl;

}
// -------------------------------------------------------------------------
void KeyboardCbk( unsigned char key, int x, int y )
{
    switch (key)
    {
        case 27 :
        case 'q':
            zoom += 5;
            break;

        case 'e':
            zoom -= 5;
            break;
    }
}

// -------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
  glutInitWindowPosition( 50, 50 );
  glutInitWindowSize( 500, 500 );
  glutCreateWindow( "3D test!!!" );
  glutDisplayFunc( DisplayCbk );
  glutReshapeFunc( ResizeCbk );
  glutKeyboardFunc( KeyboardCbk );
  glutSpecialFunc( SpecialKeyboardCbk );
  glutIdleFunc( IdleCbk );
  Init( );
  glutMainLoop( );

  return( 0 );
}

// eof