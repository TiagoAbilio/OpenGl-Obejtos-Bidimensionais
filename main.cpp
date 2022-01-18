#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

GLfloat escala = 1;//variavel responsavel pela escala do objeto
GLfloat transx=0,transy=0;//variaveis responsaveis pela translação do objeto
GLfloat rotacaob=1;//variavel responsavel pela rotação do objeto
GLfloat angulorotacao=0;//variavel responsavel pelo angulo de rotação

void quadrado(void){

    glScalef(escala,escala,0);//responsavel pela escala que variam em 3 dimensoes
    glTranslatef(transx,transy,0);//responsavel por fazer a translação do objeto
    glRotatef(angulorotacao,rotacaob,rotacaob,1);


    glColor3f(0,0,0);
    glBegin(GL_QUADS);//responsavel por instancia oque sera desenhado
    glVertex2f(1,3);//reponsavel por desenhar usando as posições no plano cartesiano
    glVertex2f(5,3);//reponsavel por desenhar usando as posições no plano cartesiano
    glVertex2f(5,7);//reponsavel por desenhar usando as posições no plano cartesiano
    glVertex2f(1,7);//reponsavel por desenhar usando as posições no plano cartesiano
    glEnd();
    glFlush();

}



void triangulo(void){

    glScalef(escala,escala,0);//responsavel pela escala que variam em 3 dimensoes
    glTranslatef(transx,transy,0);//responsavel por fazer a translação do objeto
    glRotatef(angulorotacao,rotacaob,rotacaob,1);


    glColor3f(0,0,0);
    glBegin(GL_TRIANGLES);//responsavel por instancia oque sera desenhado
    glVertex2f(-4,2);//reponsavel por desenhar usando as posições no plano cartesiano
    glVertex2f(-8,2);//reponsavel por desenhar usando as posições no plano cartesiano
    glVertex2f(-6,6);//reponsavel por desenhar usando as posições no plano cartesiano
    glEnd();
    glFlush();
}



void desenharTela(){

    glClear(GL_COLOR_BUFFER_BIT); // funcao responsavel por carregar os buffers de cor da janela inicial
    glMatrixMode(GL_PROJECTION);// modo de projecao da tela,
    glLoadIdentity();// responsavel por carregar a nova projeção, matriz indentidade
    gluOrtho2D(-10,10,-10,10); // responsavel por iniciar o plano cartesiano com seus valores iniciais e finais em X e Y
    glClearColor(1,1,1,1);

    glColor3f(1.0,1.0,1.0);
    quadrado();

    glColor3f(1.0,1.0,1.0);
    triangulo();

}


void tecladoacao(unsigned char teclaprecionada,GLint x, GLint y){
    switch(teclaprecionada){
        case '+' : escala+=0.5; // responsavel por incrementar a variavel escala que e responsavel pelo tamnho inicial do objeto
        break;
        case '-' : escala-=0.5; // responsavel por decrementar a variavel escala que e responsavel pelo tamnho inicial do objeto
        break;

        case 'd' : transx++;//responsavel pela translacao em mais 1 em x
        break;
        case 'a' : transx--;//responsavel pela translacao em menos 1 em x
        break;
        case 's' : transy--;//responsavel pela translacao em mais 1 em y
        break;
        case 'w' : transy++;//responsavel pela translacao em mais 1 em y
        break;


        case '.':rotacaob+=3;//resposavel pela rotacao para x
        break;
        case ',':rotacaob-=3;//resposavel pela rotacao para y
        break;

        case 'r':angulorotacao-=3; //resposavel pela rotacao incrementando em + 3
        break;
        case 't':angulorotacao+=3; //resposavel pela rotacao incrementando em + 3
        break;
    }

    desenharTela();//recarregando a funcao de desenho


}

int main(int argc, char *argv[]){

    glutInit(&argc,argv);//responsavel por pegar os parametros vindo do terminal
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//funcao responsavel por instancia o glut
    glutInitWindowSize(800,600);//instanciando o tamnho inicial da tela de execução
    glutCreateWindow("Prova Programacao IV");//instancia da creação da tela com seu titulo
    glutDisplayFunc(desenharTela); // instancia a funcao na qual ficara os objetos 2D
    glClearColor(1,1,1,0); // responsavel pela cor de fundo da tel
    glutKeyboardFunc(tecladoacao);//reponsavel por ficar fiscalizando entradas do teclado
    glutMainLoop(); // responsavel por atualizar todos os objetos que estao na funcao tela
    return 0;

}

















