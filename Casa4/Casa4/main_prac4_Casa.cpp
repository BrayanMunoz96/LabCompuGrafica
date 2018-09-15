//Semestre 2019 - 1  
//************************************************************//
//Alumno (s): Muñoz Juárez Brayan Osiris 
//Visual Studio 2015
//Práctica No.4 Casa
//Modelo 3D de un Perro
//Para acercar presionar W, Para Alejar presionar S
//Para girar derecha presionar D, Para girar izquierda presionar A
//************************************************************//
#include "Main.h"

float transZ = -5.0f; //-7.0f
float variable = 0.0f;
int screenW = 0.0;
int screenH = 0.0;


void InitGL ( void )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glColor3f(1.0,0.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(0.0,0.0,1.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(0.0,1.0,0.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(1.0,1.0,1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glColor3f(0.4,0.2,0.6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(0.8,0.2,0.4);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		
	glTranslatef(0.0f, 0.0f, transZ);
	glRotatef(variable, 0, 1, 0); //45
	//-------------------------------------------
	//----Parte de la tarea agregar un rotate para visualizar en otros angulos para que pueda girar la figura, visualizarlo
	//---------------------------------------------
		//Poner Código Aquí.
	/*
		//----------Código puesto en clase
		//glRotatef(45, 1, 0, 0); //La rotación,Escalamiento y Traslación afecta a todo como una pila
		glScalef(4,6,1); // x,y,z --> unidades que quiero de medida, en Z pongo 1 para que no se afecte, si pongo 0 lo multiplicaría por él y desaparece en Z
		prisma();
		
		//Muevo el pivote de los siguientes prismas a dibujar
		glTranslatef(1.0f,1.0f,0);
		prisma();
		glTranslatef(0.0f, -2.0f, 0.0f);
		prisma();
	*/	

	//----------------Tarea Casa Modelo de un Perro 3D-----------
	//Ocuparemos push y pop para que no vean afectadas las secciones de código
	// al poner push pone el valor anterior en una pila y cuando pones pop se libera ese valor antes de este procedimiento
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix(); //Cuerpo 1
	glTranslatef(0.5,-1.5, 0);
		glScalef(9, 5, 5);
		prisma();
	glPopMatrix(); //fin 

	glPushMatrix(); //Cuerpo 2
	glTranslatef(-4.5,-0.5, 0);
	glScalef(1, 3, 5);
	prisma();
	glPopMatrix(); //fin 

	//Inicia el pivote en el origen
	glPushMatrix(); //Cola
		glTranslatef(6,-0.5,0);
		glScalef(2, 1, 5);
		prisma();
	glPopMatrix(); //fin 

	glPushMatrix(); // Cabeza 1
		glTranslatef(-5.0, 3.0, 0);
		glScalef(4, 4, 5);
		prisma();
	glPopMatrix(); //fin 

	glPushMatrix(); // Cabeza 2
	glTranslatef(-7.5, 2.5, 0);
	glScalef(1, 3, 5);
	prisma();
	glPopMatrix(); //fin 

	glPushMatrix(); // Cabeza 3
	glTranslatef(-8.5, 2.0, 0);
	glScalef(1, 2, 5);
	prisma();
	glPopMatrix(); //fin 

	//Pata Delantera

	glPushMatrix(); //1
	glTranslatef(-2.0, -5.0, 0);
	glScalef(2.0,2.0, 5);
	prisma();
	glPopMatrix(); //fin

	glPushMatrix(); //2
	glTranslatef(-4.0, -5.5, 0);
	glScalef(2.0, 1.0, 5);
	prisma();
	glPopMatrix(); //fin

 //Pata Trasera

	glPushMatrix(); //1
	glTranslatef(4.0, -5.0, 0);
	glScalef(2.0, 2.0, 5);
	prisma();
	glPopMatrix(); //fin

	glPushMatrix(); //2
	glTranslatef(2.0, -5.5, 0);
	glScalef(2.0, 1.0, 5);
	prisma();
	glPopMatrix(); //fin

	//Orejas
	glPushMatrix(); //1
	glTranslatef(-4.5, 2.0, 0);
	glScalef(1.0, 4.0, 5.1);
	prisma();
	glPopMatrix(); //fin



								
  glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-8, 8,-8, 8, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.3f;
			break;
		case 's':
		case 'S':
			transZ -= 0.3f;
			break;
		case 'a':
		case 'A':
			variable += 3.0;
			break;
		case 'd':
		case 'D':
			variable -= 3.0;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		break;
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



