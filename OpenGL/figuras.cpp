#include "figuras.h"


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
void DrawUnitaryCube(GLenum mode, float r, float g, float b )
{
  float colors[ 8 ][ 3 ] =
  {
    { 1/r, 0, 0 },
    { 0, 1/g, 0 },
    { 0, 0, 1/b },
    { 0, 1/g, 1/b },
    { 1/r, 0, 1/b },
    { 1/r, 1/g, 0 },
    { 1/r, 1/g, 1/b },
    { 1/r, 1/g, 1/b }
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
    glBegin( mode );
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
void DrawUnitaryPyramid( GLenum mode, float r, float g, float b )
{
  float colors[ 5 ][ 3 ] =
  {
    { 1/r, 0, 0 },
    { 0, 1/g, 0 },
    { 1/r, 1/g, 0 },
    { 1/r, 1/g, 1/b },
    { 1/r, 1/g, 1/b }
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
    glBegin( mode );
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
void DrawUnitaryOctahedron( GLenum mode, float r, float g, float b )
{
  float colors[ 6 ][ 3 ] =
  {
    { 1/r, 0, 0 },
    { 0, 1/g, 0 },
    { 0, 0, 1/b },
    { 0, 1/g, 1/b },
    { 1/r, 1/g, 0 },
    { 1/r, 1/g, 1/b }
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
    glBegin( mode );
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
void DrawUnitaryTetrahedron( GLenum mode, float r, float g, float b )
{
  float colors[ 4 ][ 3 ] =
  {
     { 1/r, 0, 0 },
    { 0, 1/g, 0 },
    { 0, 0, 1/b },
    { 1/r, 1/g, 1/b }
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
    glBegin( mode );
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
