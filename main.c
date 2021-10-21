#include <windows.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

#define PI 3.1415926535

//Parâmetro globais para transladar cículos
GLfloat t1=0,t2=0;
GLint moveCirculo=0;
GLint direcao=1;

GLfloat raio; // valor de 1500 para fazer os círculos aparecerem no início da chamada

GLfloat AL[12] = {1478,1429,1392,1483,2444,2324,1805,1545,1330,1376,1211,1054};
GLfloat	BA[12] = {5594,5197,5977,5845,7165,8133,8321,7695,6436,6512,5765,4278};
GLfloat	CE[12] = {3268,3322,3787,4721,8427,5019,4279,3965,3806,3768,3465,2721};
GLfloat	MA[12] = {1577,1636,1858,2533,3735,2617,2173,2006,1707,1623,1534,942};
GLfloat	PB[12] = {2135,1910,2116,2018,2905,2784,2663,2461,2105,2092,2091,1585};
GLfloat	PE[12] = {4881,4599,5298,6055,8734,6225,5909,5505,5130,5233,5259,4434};
GLfloat	Pi[12] = {917,933,1078,1042,1077,1359,1278,1196,1082,1161,867,310};
GLfloat	RN[12] = {1305,1243,1369,1292,1591,2019,1799,1439,1333,1265,1283,937};
GLfloat	SE[12] = {939,861,981,878,1076,1389,1582,1188,973,967,894,640};

GLfloat r0,r1,r2,r3,r4,r5,r6,r7,r8;

//Função desenha círculo

void DesenhaCirculo(GLfloat t1, GLfloat t2){

	float angle, raio_x, raio_y;
     int i, circle_points = 1000;
	
	glTranslatef(t1,t2,0);
	// Desenha um c?rculo (elipse) preenchido com a cor corrente
     //glBegin(GL_LINE_LOOP);
     glBegin(GL_POLYGON); //como é polygon será preenchido por completo a cor
               raio_x = raio/100;
               raio_y = raio/100;
               for(i = 0; i < circle_points; i++) {
                 angle = (2*PI*i)/circle_points;
                 glVertex2f(125.0+raio_x*cos(angle),125.0+raio_y*sin(angle));
                 }
     glEnd();
	
	
}


void DesenhaTexto(void *font, char *string) 
{
	// Exibe caractere a caractere
	while(*string)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*string++); 
}

// Função que recebe a fonte e um texto por parâmetro para ser exibido na 
// tela usando fonte de linhas
void DesenhaTextoStroke(void *font, char *string) 
{  
	// Exibe caractere a caractere
	while(*string)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++); 
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
     raio = r0;
	
	//Desenha círculo 1 na cor branca Alagoas
     glColor3f(1.0f, 1.0f, 1.0f);
     t1 = -10;
     t2 = 0;
	 DesenhaCirculo(t1,t2);
     
     //Desenha circulo 2 na cor verde Bahia
     raio=r1;
     glColor3f(0.0f,1.0f,0.0f);     
     t1 =90;
     t2 =40;
     DesenhaCirculo(t1,t2);
	
	//Desenha circulo 3 na cor amarela Ceará
	raio = r2;
	glColor3f(1.0f,1.0f,0.0f);     
     t1 =100;
     t2 =40;
     DesenhaCirculo(t1,t2);
    
	 
	//Desenha circulo 4 na cor azul Maranhão
	raio = r3;
	glColor3f(0.0f,0.0f,1.0f);     
     t1 =30;
     t2=-70;
     DesenhaCirculo(t1,t2);
     
     //Desenha circulo 5 Paraíba
	 raio = r4; 
	glColor3f(0.0f,1.0f,0.0f);     
     t1 =45;
     t2 =15;
     DesenhaCirculo(t1,t2);
    
      //Desenha circulo 6 magenta
      raio = r5;
     glColor3f(0.0f,0.5f,0.5f);     
     t1 = 55;
     t2 = 60;
     DesenhaCirculo(t1,t2);
     
      //Desenha circulo 7 
      raio = r6;
     glColor3f(0.5f,0.1f,1.0f);     
     t1 =75;
     t2 =-45;
     DesenhaCirculo(t1,t2);
     
       //Desenha circulo 8 
       raio = r7;
     glColor3f(0.5f,0.5f,0.5f);     
     t1 =65;
     t2 =-10;
     DesenhaCirculo(t1,t2);
     
       //Desenha circulo 9 
       raio = r8;
    glColor3f(0.5f,0.5f,0.0f);     
     t1 =-50;
     t2 =-45;
     DesenhaCirculo(t1,t2);
     
     	glTranslatef(-320,320,0);
	glScalef(0.1, 0.1, 0.1);
    DesenhaTextoStroke(GLUT_STROKE_ROMAN,"GRAFICO DE BOLHA DE CADA ESTADO DO NORDESTE - COVID 19");    
     
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
    printf("Precione Esc para sair ");
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
                           gluOrtho2D (0.0f, 350.0f, 0.0f, 350.0f*h/w);
                   else 
                           gluOrtho2D (0.0f, 350.0f*w/h, 0.0f, 350.0f);
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


void criaMenu(int opcao){
	switch(opcao){
		case 0:
			r0 = AL[0]; 
			r1 = BA[0];
			r2 = CE[0];
			r3 = MA[0];
			r4 = PB[0];
			r5 = PE[0];
			r6 = Pi[0];
			r7 = RN[0];
			r8 = SE[0];
						
			break;
		case 1:
			r0 = AL[1]; 
			r1 = BA[1];
			r2 = CE[1];
			r3 = MA[1];
			r4 = PB[1];
			r5 = PE[1];
			r6 = Pi[1];
			r7 = RN[1];
			r8 = SE[1];
						
			break;
			
		case 2:
			r0 = AL[2]; 
			r1 = BA[2];
			r2 = CE[2];
			r3 = MA[2];
			r4 = PB[2];
			r5 = PE[2];
			r6 = Pi[2];
			r7 = RN[2];
			r8 = SE[2];
						
			break;
			
		case 3:
			r0 = AL[3]; 
			r1 = BA[3];
			r2 = CE[3];
			r3 = MA[3];
			r4 = PB[3];
			r5 = PE[3];
			r6 = Pi[3];
			r7 = RN[3];
			r8 = SE[3];
						
			break;
			
		case 4:
			r0 = AL[4]; 
			r1 = BA[4];
			r2 = CE[4];
			r3 = MA[4];
			r4 = PB[4];
			r5 = PE[4];
			r6 = Pi[4];
			r7 = RN[4];
			r8 = SE[4];
						
			break;
			
		case 5:
			r0 = AL[5]; 
			r1 = BA[5];
			r2 = CE[5];
			r3 = MA[5];
			r4 = PB[5];
			r5 = PE[5];
			r6 = Pi[5];
			r7 = RN[5];
			r8 = SE[5];
						
			break;
			
		case 6:
			r0 = AL[6]; 
			r1 = BA[6];
			r2 = CE[6];
			r3 = MA[6];
			r4 = PB[6];
			r5 = PE[6];
			r6 = Pi[6];
			r7 = RN[6];
			r8 = SE[6];
						
			break;
			
		case 7:
			r0 = AL[7]; 
			r1 = BA[7];
			r2 = CE[7];
			r3 = MA[7];
			r4 = PB[7];
			r5 = PE[7];
			r6 = Pi[7];
			r7 = RN[7];
			r8 = SE[7];
						
			break;
			
		case 8:
			r0 = AL[8]; 
			r1 = BA[8];
			r2 = CE[8];
			r3 = MA[8];
			r4 = PB[8];
			r5 = PE[8];
			r6 = Pi[8];
			r7 = RN[8];
			r8 = SE[8];
						
			break;
			
		case 9:
			r0 = AL[9]; 
			r1 = BA[9];
			r2 = CE[9];
			r3 = MA[9];
			r4 = PB[9];
			r5 = PE[9];
			r6 = Pi[9];
			r7 = RN[9];
			r8 = SE[9];
						
			break;
			
		case 10:
			r0 = AL[10]; 
			r1 = BA[10];
			r2 = CE[10];
			r3 = MA[10];
			r4 = PB[10];
			r5 = PE[10];
			r6 = Pi[10];
			r7 = RN[10];
			r8 = SE[10];
						
			break;
			
		case 11:
			r0 = AL[11]; 
			r1 = BA[11];
			r2 = CE[11];
			r3 = MA[11];
			r4 = PB[11];
			r5 = PE[11];
			r6 = Pi[11];
			r7 = RN[11];
			r8 = SE[11];
						
			break;
	
	}
	
	glutPostRedisplay();
}

int main(int argc, char ** argv) {
 int sizex, sizey;

 sizex = 900;
 sizey = 500;

 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(sizex,sizey);
 glutInitWindowPosition(10,10);
 glutCreateWindow("C?rculo");
 glutDisplayFunc(Desenha  );
 glutFullScreen();
 int menu;
 
 menu = glutCreateMenu(criaMenu);
 
 glutAddMenuEntry("JANEIRO", 0);
 glutAddMenuEntry("FEVEREIRO", 1);
 glutAddMenuEntry("MARÇO", 2);
 glutAddMenuEntry("ABRIL", 3);
 glutAddMenuEntry("MAIO", 4);
 glutAddMenuEntry("JUNHO", 5);
 glutAddMenuEntry("JULHO", 6);
 glutAddMenuEntry("AGOSTO", 7);
 glutAddMenuEntry("SETEMBRO", 8);
 glutAddMenuEntry("OUTUBRO", 9);
 glutAddMenuEntry("NOVEMBRO", 10);
 glutAddMenuEntry("DEZEMBRO", 11);
 
 glutAttachMenu(GLUT_RIGHT_BUTTON);
 
 
 glutReshapeFunc(AlteraTamanhoJanela);
 glutKeyboardFunc(Teclado);
 //glutTimerFunc(10,MoverCirculo,1);
 Inicializa();
 glutMainLoop();

 return 0;
}
