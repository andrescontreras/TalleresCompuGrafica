#include "figuras.h"

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
bool pause = true;

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
  float hotfix = 1;
  eyeX = zoom * std::sin(camAngleX*(_PI/180))*std::cos(camAngleY*(_PI/180));
  eyeY = zoom * std::sin(camAngleY*(_PI/180));
  eyeZ = zoom * std::cos(camAngleX*(_PI/180))*std::cos(camAngleY*(_PI/180));

  if(camAngleY >= 0 && camAngleY < 90)
    hotfix = 1;
  if(camAngleY >= 90 && camAngleY < 270)
    hotfix = -1;
  if(camAngleY >= 270 && camAngleY < 360)
    hotfix = 1;
  // Camara
  glLoadIdentity( );
  gluLookAt( eyeX, eyeY, eyeZ, 0, 0, 0, 0, hotfix, 0 );

  //Sol
  glPushMatrix( );
  //Tamaño de 2.5 en X,Y y Z
  glScalef(2.5,2.5,2.5);
  //No se encuentra rotado
  glRotatef(rot1,0,1,0);
  DrawUnitaryOctahedron(GL_POLYGON,1,1,1);
  DrawUnitaryOctahedron(GL_LINE_LOOP,1,1,1);
  glPopMatrix();

  //Planeta 1
   //Anillo
  glPushMatrix( );
  glColor3f(0.4, 0.254, 0.0392);
  //Orbita circular de tamaño 4
  glScalef(4,4,4);
  //Orbita rotada 40° en X,Y y Z
  glRotatef(40,1,1,1);
  DrawCircle(GL_LINE_LOOP,100);
  glPopMatrix();
   //Planeta
  glPushMatrix( );
  glColor3f(0.4, 0.254, 0.0392);
  //Orbita rotada 40° en X,Y y Z
  glRotatef(40,1,1,1);
  //Orbita circular de tamaño 4 ; se pone la figura en la orbita
  glTranslatef(4*std::cos(tra2),0,4*std::sin(tra2));
  //Se regresa la rotación de la figura a su punto inicial, pero se deja rotada 40° en y
  glRotatef(40,-1,0,-1);
  glRotatef(rot1,0,1,0);
  //La figura tiene un tamaño de 1.7
  glScalef(1.7,1.7,1.7);
  DrawUnitaryTetrahedron(GL_POLYGON,1,35,1);
  DrawUnitaryTetrahedron(GL_LINE_LOOP,1,35,1);
  glPopMatrix();
  //Planeta 2
   //Anillo
      glPushMatrix( );
      glColor3f(0.4, 0.254, 0.0392);
      //Se desplaza el eje de traslación en x -1.5
      glTranslatef(-1.5,0,0);
      //Se Rota la figura 40° en y
      glRotatef(40,0,1,0);
      //Elipse de tamaño 6 en x y 8 en y
      DrawEllipse(GL_LINE_LOOP,100,6,8);
      glPopMatrix();
   //Planeta
      glPushMatrix( );
      //Se desplaza el eje de traslación en x -1.5
      glTranslatef(-1.5,0,0);
      //Se Rota la figura 40° en y
      glRotatef(40,0,1,0);
      //Elipse de tamaño 6 en x y 8 en y
      glTranslatef(6*std::cos(tra4),0,8*std::sin(tra4));
      //Se Regresa a la rotación inicial
      glRotatef(40,0,-1,0);
      //Se rotan 45° en x , y 
      glRotatef(45,1,1,0);
      glRotatef(rot2,0,1,0);
      //Figura de tamaño 1.5
      glScalef(1.5,0.5,1.5);
      DrawUnitaryCube(GL_POLYGON,1,1,6);
      DrawUnitaryCube(GL_LINE_LOOP,1,1,1);
      glPopMatrix();
      //Lunas
        //Anillo Luna 1
          glPushMatrix( );
          glColor3f(0.4, 0.254, 0.0392);
          //Se desplaza el eje de traslación en x -1.5
          glTranslatef(-1.5,0,0);
          //Se Rota la figura 40° en y
          glRotatef(40,0,1,0);
          //Elipse de tamaño 6 en x y 8 en y
          glTranslatef(6*std::cos(tra4),0,8*std::sin(tra4));
          //Una vez ya puesto el anillo de la luna en orbita al planeta, se rota el anillo -90° en y (Es decir 40° - 90° = -50°) y 90° en z
          glRotatef(90,0,-1,1);
          //Anillo circular centrado de tamaño 2
          glScalef(2,2,2);
          DrawCircle(GL_LINE_LOOP,100);
          glPopMatrix();
        //Luna 1
          glPushMatrix( );
          glTranslatef(-1.5,0,0);
          glRotatef(40,0,1,0);
          glTranslatef(6*std::cos(tra4),0,8*std::sin(tra4));
          glRotatef(90,0,-1,1);
          glTranslatef(2*std::cos(tra2),0,2*std::sin(tra2));
          //Hasta aqui es el mismo procedimiento de antes, solo que con la consideracion del anillo de la luna
          glRotatef(10,-1,0,-1);
          glRotatef(rot3,0,1,0);
          glScalef(0.45,0.45,0.45);
          DrawUnitaryOctahedron(GL_POLYGON,1,1,1);
          DrawUnitaryOctahedron(GL_LINE_LOOP,1,1,1);
          glPopMatrix();

  //Planeta 3
    //Anillo
      glPushMatrix( );
      glColor3f(0.4, 0.254, 0.0392);
      glTranslatef(0,-1.5,0);
      glRotatef(90,0,1,1);
      DrawEllipse(GL_LINE_LOOP,100,9,12);
      glPopMatrix();
    //Planeta
      glPushMatrix( );
      glTranslatef(0,-1.5,0);
      glRotatef(90,0,1,1);
      glTranslatef(9*std::cos(tra6),0,12*std::sin(tra6));
      glRotatef(30,1,1,-1);
      glRotatef(rot1,0,1,0);
      glScalef(1.4,1.4,1.4);
      DrawUnitaryPyramid(GL_POLYGON,7,1.4,1.2);
      DrawUnitaryPyramid(GL_LINE_LOOP,1,1,1);
      glPopMatrix();
      //Lunas
        //Anillo Luna 1
          glPushMatrix( );
          glColor3f(0.4, 0.254, 0.0392);
          glTranslatef(0,-1.5,0);
          glRotatef(90,0,1,1);
          glTranslatef(9*std::cos(tra6),0,12*std::sin(tra6));
          glRotatef(75,1,-1,-1);
          glScalef(1.7,1.5,1.5);
          DrawCircle(GL_LINE_LOOP,100);
          glPopMatrix();
        //Luna 1
          glPushMatrix( );
          glTranslatef(0,-1.5,0);
          glRotatef(90,0,1,1);
          glTranslatef(9*std::cos(tra6),0,12*std::sin(tra6));
          glRotatef(75,1,-1,-1);
          glTranslatef(1.7*std::cos(tra4),0,1.5*std::sin(tra4));
          glScalef(0.6,0.6,0.6);
          glRotatef(70,1,1,1);
          glRotatef(rot5,0,1,0);
          DrawUnitaryPyramid(GL_POLYGON,2,4,1);
          DrawUnitaryPyramid(GL_LINE_LOOP,1,1,1);
          glPopMatrix();
  //Planeta 4
   //Anillo
      glPushMatrix( );
      glColor3f(0.4, 0.254, 0.0392);
      glTranslatef(0,0,-0.5);
      glRotatef(60,1,1,1);
      glScalef(15,15,15);
      DrawCircle(GL_LINE_LOOP,100);
      glPopMatrix();
    //Planeta
      glPushMatrix( );
      glTranslatef(0.3,-0.2,-0.5);
      glRotatef(60,1,1,1);
      glTranslatef(15*std::cos(tra1),0,15*std::sin(tra1));
      glRotatef(60,1,-1,-1);
      glRotatef(rot3,0,1,0);
      glScalef(1.5,1.5,1.5);
      DrawUnitaryOctahedron(GL_POLYGON,1,3.4,2);
      DrawUnitaryOctahedron(GL_LINE_LOOP,1,1,1);
      glPopMatrix();
        //Anillo Luna 1
          glPushMatrix( );
          glColor3f(0.4, 0.254, 0.0392);
          glTranslatef(0.3,-0.2,-0.5);
          glRotatef(60,1,1,1);
          glTranslatef(15*std::cos(tra1),0,15*std::sin(tra1));
          glRotatef(90,0,0,1);
          glScalef(3,3,3);
          DrawCircle(GL_LINE_LOOP,100);
          glPopMatrix();
        //Luna 1
          glPushMatrix( );
          glTranslatef(0.3,-0.2,-0.5);
          glRotatef(60,1,1,1);
          glTranslatef(15*std::cos(tra1),0,15*std::sin(tra1));
          glRotatef(90,0,0,1);
          glTranslatef(3*std::cos(tra3),0,3*std::sin(tra3));
          glScalef(1,1,1);
          glRotatef(40,-1,0,-1);
          glRotatef(rot1,0,1,0);
          DrawUnitaryTetrahedron(GL_POLYGON,8,1,1);
          DrawUnitaryTetrahedron(GL_LINE_LOOP,1,1,1);
          glPopMatrix();
        //Anillo Luna 2
          glPushMatrix( );
          glColor3f(0.4, 0.254, 0.0392);
          glTranslatef(0.3,-0.2,-0.5);
          glRotatef(60,1,1,1);
          glTranslatef(15*std::cos(tra1),0,15*std::sin(tra1));
          glRotatef(70,1,1,1);
          glScalef(4,4,4);
          DrawCircle(GL_LINE_LOOP,100);
          glPopMatrix();
        //Luna 2
          glPushMatrix( );
          glTranslatef(0.3,-0.2,-0.5);
          glRotatef(60,1,1,1);
          glTranslatef(15*std::cos(tra1),0,15*std::sin(tra1));
          glRotatef(70,1,1,1);
          glTranslatef(4*std::cos(tra4),0,4*std::sin(tra4));
          glRotatef(rot2,0,1,0);
          DrawUnitaryCube(GL_POLYGON,3,1,2);
          DrawUnitaryCube(GL_LINE_LOOP,1,1,1);
          glPopMatrix();
        //Anillo Luna 3
          glPushMatrix( );
          glColor3f(0.4, 0.254, 0.0392);
          glTranslatef(0.3,-0.2,-0.5);
          glRotatef(60,1,1,1);
          glTranslatef(15*std::cos(tra1),0,15*std::sin(tra1));
          glRotatef(20,1,1,1);
          glScalef(6,6,6);
          DrawCircle(GL_LINE_LOOP,100);
          glPopMatrix();
        //Luna 3
          glPushMatrix( );
          glTranslatef(0.3,-0.2,-0.5);
          glRotatef(60,1,1,1);
          glTranslatef(15*std::cos(tra1),0,15*std::sin(tra1));
          glRotatef(20,1,1,1);
          glTranslatef(6*std::cos(tra2),0,6*std::sin(tra2));
          glRotatef(60,1,1,-1);
          glRotatef(rot5,0,1,0);
          glScalef(1.3,1.3,1.3);
          DrawUnitaryOctahedron(GL_POLYGON,1.4,1,1.8);
          DrawUnitaryOctahedron(GL_LINE_LOOP,1,1,1);
          glPopMatrix();

  // Finish
  glutSwapBuffers( );
}

// -------------------------------------------------------------------------
void IdleCbk()
{
    if(!pause)
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
    }
    glutPostRedisplay();
}

// -------------------------------------------------------------------------
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
        if(camAngleY == 90)
        {
            camAngleY +=0.5;
        }
        if(camAngleY == 270)
        {
            camAngleY +=0.5;
        }

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

        case 'Q':
            zoom += 5;
            break;

        case 'E':
            zoom -= 5;
            break;

        case 'P':
            if(!pause)
                pause = true;
            else
                pause = false;
            break;

        case 'p':
            if(!pause)
                pause = true;
            else
                pause = false;
            break;
    }
}

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

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

 