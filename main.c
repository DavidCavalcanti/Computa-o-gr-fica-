#include <windows.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

//#define PI 3.1415926535

//Parâmetro globais para transladar cículos
GLfloat t1=0,t2=0; 

//Raio

GLfloat raio;


//parâmetros para animação
//GLint moveCirculo=0;
//GLint direcao=1;

//Criando vetor com os dados dos respectivos meses
GLfloat	AL[12] = {1478,1429,1392,1483,2444,2324,1805,1545,1330,1376,1211,1054};
GLfloat		BA[12] = {5594,5197,5977,5845,7165,8133,8321,7695,6436,6512,5765,4278};
GLfloat		CE[12] = {3268,3322,3787,4721,8427,5019,4279,3965,3806,3768,3465,2721};
GLfloat	MA[12] = {1577,1636,1858,2533,3735,2617,2173,2006,1707,1623,1534,942};
GLfloat	PB[12] = {2135,1910,2116,2018,2905,2784,2663,2461,2105,2092,2091,1585};
GLfloat	PE[12] = {4881,4599,5298,6055,8734,6225,5909,5505,5130,5233,5259,4434};
GLfloat	PI[12] = {917,933,1078,1042,1077,1359,1278,1196,1082,1161,867,310};
GLfloat	RN[12] = {1305,1243,1369,1292,1591,2019,1799,1439,1333,1265,1283,937};
GLfloat	SE[12] = {939,861,981,878,1076,1389,1582,1188,973,967,894,640};


GLfloat r0; GLfloat r1; GLfloat r2; GLfloat r3; GLfloat r4;
GLfloat r5; GLfloat r6; GLfloat r7; GLfloat r8;

//Função desenha círculo

void DesenhaCirculo(GLfloat t1, GLfloat t2, GLfloat raio){

	float angle, raio_x, raio_y;
     int i, circle_points = 1000;
	
	glTranslatef(t1,t2,0);
	// Desenha um c?rculo (elipse) preenchido com a cor corrente
     //glBegin(GL_LINE_LOOP);
     glBegin(GL_POLYGON); //como é polygon será preenchido por completo a cor
               raio_x = raio/100;
               raio_y = raio/100;
               for(i = 0; i < circle_points; i++) {
                 angle = (2*3.1415926535*i)/circle_points;
                 glVertex2f(125.0+raio_x*cos(angle),125.0+raio_y*sin(angle));
                 }
     glEnd();
	
	
}

// Fun??o callback chamada para fazer o desenho
void Desenha(void)
{
          
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
                   
     // Limpa a janela de visualiza??o com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);

   
   
     
     
     // Especifica o tamanho do pixel
     glPointSize(1.0);
	
	//Desenha círculo 1 na cor branca
     glColor3f(1.0f, 1.0f, 1.0f);
	 DesenhaCirculo(t1,t2,r0);
     
     //Desenha circulo 2 na cor verde
     glColor3f(0.0f,1.0f,0.0f);     
     t1 +=40;
     t2+=40;
     DesenhaCirculo(t1,t2,r1);
	
	//Desenha circulo 3 na cor amarela
	glColor3f(1.0f,1.0f,0.0f);     
     t1 +=10;
     t2+=10;
     DesenhaCirculo(t1,t2,r2);
     
	//Desenha circulo 4 na cor vermelha
	glColor3f(0.0f,0.0f,1.0f);     
     t1 +=-100;
     t2+=-50;
     DesenhaCirculo(t1,t2,r3);
     
     //Desenha circulo 5 
	glColor3f(0.0f,1.0f,1.0f);     
     t1 +=-0;
     t2+=-50;
     DesenhaCirculo(t1,t2,r4);
    
      //Desenha circulo 6 
     glColor3f(0.0f,0.5f,0.5f);     
     t1 +=0;
     t2+=-50;
     DesenhaCirculo(t1,t2,r5);
     
      //Desenha circulo 7 
     glColor3f(0.5f,0.1f,1.0f);     
     t1 +=80;
     t2+=80;
     DesenhaCirculo(t1,t2,r6);
     
       //Desenha circulo 8 
     glColor3f(0.5f,0.5f,0.5f);     
     t1 +=80;
     t2+=80;
     DesenhaCirculo(t1,t2,r7);
     
       //Desenha circulo 9 
    glColor3f(0.5f,0.5f,0.0f);     
     t1 +=-250;
     t2+=-60;
     DesenhaCirculo(t1,t2,r8);
     
     
    
     
    // Executa os comandos OpenGL
    glFlush();
      //glutSwapBuffers();
}

// Inicializa par?metros de rendering
void Inicializa (void)
{   
    // Define a cor de fundo da janela de visualiza??o como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    //Exibe informações de como interagir
    printf("Informações de como interagir com o programa:\n\n");
    printf("LOREM IPSUM DOLOR IT...");
    printf("\nLOREM IPSUM DOLOR IT...");
    printf("\nLOREM IPSUM DOLOR IT...");
}

void Teclado(unsigned char key, int x, int y){
	
	if(key == 27){
		exit(0);
	}
}
// Fun??o callback chamada quando o tamanho da janela ? alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
                   // Evita a divisao por zero
                   if(h == 0) h = 1;
                           
                   // Especifica as dimens?es da Viewport
                   glViewport(0, 0, w, h);

                   // Inicializa o sistema de coordenadas
                   glMatrixMode(GL_PROJECTION);
                   glLoadIdentity();

                   // Estabelece a janela de sele??o (left, right, bottom, top)
                   if (w <= h) 
                           gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
                   else 
                           gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

/*void MoverCirculo(int passo)
{
if(direcao==1)
{
moveCirculo += 1;
if(moveCirculo==500) direcao = 0;
}

else
{
moveCirculo -= 1;
if(moveCirculo==-225) direcao = 1;
}
glutPostRedisplay();
glutTimerFunc(10,MoverCirculo, 1);

}*/


/*
=======menu meses ===

janeiro 1
junho  2
Dezembro 3

*/
void MenuMeses (int opcao){
		
	
	switch(opcao)
	{
		case 0:
			r0 =AL[0]; 
			r1= BA[0]; 
			r2=CE[0]; 
			r3=MA[0]; 
			r4=PB[0];
			r5=PE[0]; 
			r6=PI[0];
			r7=RN[0]; 
			r8=SE[0];
			Desenha();
			break;
	}
	glutPostRedisplay();
}

int main(int argc, char ** argv) {
 
 
 int sizex, sizey;

 sizex = 500;
 sizey = 500;
 
 int menu;

 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(sizex,sizey);
 glutInitWindowPosition(10,10);
 glutCreateWindow("C?rculo");
 glutDisplayFunc(Desenha);
 
 //Função para menu
  glutCreateMenu(MenuMeses);
 //Adicionando opções do menu
 glutAddMenuEntry("Janeiro",0);	
 glutAddMenuEntry("Junho",1);	
 glutAddMenuEntry("Dezembro",2);	
 //Associando menu ao botão direito do mouse
 glutAttachMenu(GLUT_RIGHT_BUTTON);	


 glutReshapeFunc(AlteraTamanhoJanela);
 glutKeyboardFunc(Teclado);
 //glutTimerFunc(10,MoverCirculo,1);
 Inicializa();
 glutMainLoop();

 return 0;
}
