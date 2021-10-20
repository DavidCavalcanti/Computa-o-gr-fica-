#include <windows.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

#define PI 3.1415926535

//Parâmetro globais para transladar cículos
GLfloat t1=0,t2=0;


//Função desenha círculo

void DesenhaCirculo(GLfloat t1, GLfloat t2){

	float angle, raio_x, raio_y;
     int i, circle_points = 1000;
	
	glTranslatef(t1,t2,0);
	// Desenha um c?rculo (elipse) preenchido com a cor corrente
     //glBegin(GL_LINE_LOOP);
     glBegin(GL_POLYGON); //como é polygon será preenchido por completo a cor
               raio_x = 15.0;
               raio_y = 15.0;
               for(i = 0; i < circle_points; i++) {
                 angle = (2*PI*i)/circle_points;
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
	 DesenhaCirculo(t1,t2);
     
     //Desenha circulo 2 na cor verde
     glColor3f(0.0f,1.0f,0.0f);     
     t1 +=40;
     t2+=40;
     DesenhaCirculo(t1,t2);
	
	//Desenha circulo 3 na cor amarela
	glColor3f(1.0f,1.0f,0.0f);     
     t1 +=10;
     t2+=10;
     DesenhaCirculo(t1,t2);
     
	//Desenha circulo 4 na cor vermelha
	glColor3f(0.0f,0.0f,1.0f);     
     t1 +=-100;
     t2+=-50;
     DesenhaCirculo(t1,t2);
     
     //Desenha circulo 5 na cor 
	glColor3f(0.0f,1.0f,1.0f);     
     t1 +=-50;
     t2+=-50;
     DesenhaCirculo(t1,t2);
     // Executa os comandos OpenGL
     glFlush();
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

int main(int argc, char ** argv) {
 int sizex, sizey;

 sizex = 500;
 sizey = 500;

 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(sizex,sizey);
 glutInitWindowPosition(10,10);
 glutCreateWindow("C?rculo");
 glutDisplayFunc(Desenha);
 glutReshapeFunc(AlteraTamanhoJanela);
 glutKeyboardFunc(Teclado);
 Inicializa();
 glutMainLoop();

 return 0;
}
