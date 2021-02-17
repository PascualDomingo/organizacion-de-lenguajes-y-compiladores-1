%{
#include "scanner.h"//se importa el header del analisis sintactico
#include "NodoAST.h"
#include "qdebug.h"
#include <iostream>
extern int yylineno; //linea actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern int columna; //columna actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern char *yytext; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON
extern NodoAST *raiz; // Raiz del arbol

int yyerror(const char* mens)
{

    std::cout << mens <<" "<<yytext<<" "<<yylineno+1<< std::endl;
    return 0;
}
%}
//error-verbose si se especifica la opcion los errores sintacticos son especificados por BISON
%defines "parser.h"
%output "parser.cpp"
%error-verbose
%locations

%union{
//se especifican los tipo de valores para los no terminales y lo terminales
char TEXT [256];
class NodoAST *nodito;
}

//TERMINALES DE TIPO TEXT, SON STRINGS
%token<TEXT> entero;
%token<TEXT> decimal;
%token<TEXT> caracter;
%token<TEXT> booleano;
%token<TEXT> cadena;
%token<TEXT> id;
%token<TEXT> pari;
%token<TEXT> pard;
%token<TEXT> suma;
%token<TEXT> menos;
%token<TEXT> multi;
%token<TEXT> division;
%token<TEXT> potencia;
%token<TEXT> arreglo;
%token<TEXT> corI;
%token<TEXT> corD;
%token<TEXT> eq;
%token<TEXT> llavI;
%token<TEXT> llavD;
%token<TEXT> coma;
%token<TEXT> Dolar;
%token<TEXT> tClase;
%token<TEXT> tPara;
%token<TEXT> tPunto;

%token<TEXT> eqeq;
%token<TEXT> difQ;
%token<TEXT> menorQ;
%token<TEXT> menorIgualQ;
%token<TEXT> mayorQ;
%token<TEXT> mayorIgualQ;
%token<TEXT> Snot;
%token<TEXT> Sand;
%token<TEXT> Snand;
%token<TEXT> Sor;
%token<TEXT> Sxor;
%token<TEXT> tid;


/* palabras reservadas */
%token<TEXT> prInt;
%token<TEXT> prString;
%token<TEXT> prBooleano;
%token<TEXT> prBool;
%token<TEXT> prChar;
%token<TEXT> prDouble;
%token<TEXT> prSi;
%token<TEXT> prSino;
%token<TEXT> tMain;
%token<TEXT> tPrint;
%token<TEXT> tPublico;
%token<TEXT> tPrivado;
%token<TEXT> tProtegido;
%token<TEXT> tAumento;
%token<TEXT> tDecremento;
%token<TEXT> tRomper;
%token<TEXT> tRepetir;
%token<TEXT> tMientras;
%token<TEXT> tContinuar;
%token<TEXT> tSalir;
%token<TEXT> tsobrescribir;
%token<TEXT> tVoid;
%token<TEXT> tHacer;
%token<TEXT> tRetornar;
%token<TEXT> tNotificacion;
%token<TEXT> tArreglo;
%token<TEXT> tNuevo;


/*No terimanesl*/
%type<nodito> INICIO;
%type<nodito> LCLASE;
%type<nodito> CLASE;
%type<nodito> CUERPO;
%type<nodito> MAIN;
%type<nodito> VAR_ASIG;
%type<nodito> TIPO;
%type<nodito> LISTAID;
%type<nodito> LS;
%type<nodito> IF;
%type<nodito> ELSE;
%type<nodito> SEN_IF;
%type<nodito> ELSE_IF;
%type<nodito> IMPRIMIR;
%type<nodito> VAR_DECLARACION;
%type<nodito> VISIBILIDAD;
%type<nodito> REPETIR;
%type<nodito> MIENTRAS;
%type<nodito> HACER_MIENTRAS;
%type<nodito> ROMPER;
%type<nodito> SALIR;
%type<nodito> CONTINUAR;
%type<nodito> AUMENTO;
%type<nodito> DECREMENTO;
%type<nodito> PARA;
%type<nodito> LPARAMETRO;
%type<nodito> PARAMETRO;
%type<nodito> MI_PARAMETRO;
%type<nodito> ENCAPSULAR;
%type<nodito> METODO;
%type<nodito> SOBRESRIBIR;
%type<nodito> LLAMADA;
%type<nodito> NOTIFICACION;
%type<nodito> RETORNAR;
//%type<nodito> DECLARAR_VAR;
%type<nodito> ASIGNACION_VEC;
%type<nodito> DIMENCION;
%type<nodito> ACCESO_VEC;
%type<nodito> REASIGNACION_VEC;
%type<nodito> VALOR_VEC;
%type<nodito> UNIDIMENCION;
%type<nodito> BIDIMENCION;
%type<nodito> LISBI;
%type<nodito> TRIDIMENCION;
%type<nodito> LISTRI;
%type<nodito> EXPRESION;
%type<nodito> INSTANCIA;
%type<nodito> OBJECTO_ASIGNACION;
%type<nodito> ACCES_VFM;
%type<nodito> DECLARAR_ARREGLO;
%type<nodito> DIM1;
%type<nodito> DIM2;
%type<nodito> DIM3;
%type<nodito> REASIGNACION_VAR_CLASE; /*reasigna valor a las variables globales   c1.nombre = "pascual" */
%type<nodito> INICIAR; /*declarar variable dentro de for int x = 0 */
%type<nodito> ACTUALIZACION; /*actualiacion de for num++ num--*/
%type<nodito> EXPL; //expresion logica
%type<nodito> EXPR; //expresion relacional
%type<nodito> EXPA; // Aritmetica

/*precedencia de operadores*/
%left Sor Sxor
%left Sand Snand
%right Snot
%left mayorIgualQ mayorQ menorIgualQ menorQ difQ eqeq
%left suma menos
%left multi division
%left potencia
%left pari
%nonassoc tid


%start INICIO
%%

INICIO : LCLASE { raiz = $$; } ;

LCLASE : LCLASE CLASE
        {
            $$=$1;
            //NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column,"CLASE","CLASE");
            $$->add(*$2);
            //$$->add(*nodo);
        }
    | CLASE
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LCLASE","LCLASE");
            //NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column,"CLASE","CLASE");
            $$->add(*$1);
            //$$->add(*nodo);
        }
    ;

CLASE : tClase id llavI CUERPO llavD
        {
            NodoAST *nodo1 = new NodoAST(yylineno+1, @1.first_column,"id",$2);
            NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"CLASE","CLASE");
            nodo->add(*nodo1);
            nodo->add(*$4);
            $$ = nodo;
        }
    | tClase id llavI llavD
        {  /*cuando la clase puede estar vacia*/
            NodoAST *nodo1 = new NodoAST(yylineno+1, @1.first_column,"id",$2);
            NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"CLASE","CLASE");
            nodo->add(*nodo1);
            $$ = nodo;
        }
;

CUERPO : CUERPO ENCAPSULAR VAR_ASIG
        {
            $$=$1;
            $3->add(*$2);
            $$ ->add(*$3);

        }
    | CUERPO ENCAPSULAR ASIGNACION_VEC
        {
            $$=$1;
            $3->add(*$2);
            $$ ->add(*$3);

        }
    | CUERPO VAR_ASIG
        {
            $$=$1;
            $$->add(*$2);

        }
    | CUERPO ASIGNACION_VEC
        {
            $$=$1;
            $$->add(*$2);

        }
    | CUERPO MAIN
        {
            $$=$1;
            $$->add(*$2);
        }
    | CUERPO METODO
        {
            $$=$1;
            $$->add(*$2);
        }
    | CUERPO ENCAPSULAR VAR_DECLARACION
        {
            $$=$1;
            $3 ->add(*$2);
            $$->add(*$3);
        }
    | CUERPO VAR_DECLARACION
        {
            $$=$1;
            $$ ->add(*$2);
        }
    | CUERPO REASIGNACION_VEC
        {
            $$=$1;
            $$ ->add(*$2);
        }
    | CUERPO INSTANCIA
        {
            $$=$1;
            $$ ->add(*$2);
        }
    | CUERPO OBJECTO_ASIGNACION
        {
            $$=$1;
            $$ ->add(*$2);
        }
    | CUERPO ACCES_VFM Dolar
        {
            $$=$1;
            $$ ->add(*$2);
        }
    | CUERPO DECLARAR_ARREGLO
        {
            $$=$1;
            $$ ->add(*$2);
        }
    | CUERPO REASIGNACION_VAR_CLASE
        {
            $$=$1;
            $$ ->add(*$2);
        }
    | ENCAPSULAR VAR_ASIG
        {
            $2 ->add(*$1);
            $$ = new NodoAST(yylineno+1, @1.first_column,"LCUERPO","LCUERPO");
            $$->add(*$2);
        }
    | ENCAPSULAR ASIGNACION_VEC
        {
            $2 ->add(*$1);
            $$ = new NodoAST(yylineno+1, @1.first_column,"LCUERPO","LCUERPO");
            $$->add(*$2);
        }
    | VAR_ASIG
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LCUERPO","LCUERPO");
            $$->add(*$1);
        }
    | ASIGNACION_VEC
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LCUERPO","LCUERPO");
            $$->add(*$1);
        }
    | ENCAPSULAR VAR_DECLARACION
        {
            $2 ->add(*$1);
            $$ = new NodoAST(yylineno+1, @1.first_column,"LCUERPO","LCUERPO");
            $$->add(*$2);
        }
    | VAR_DECLARACION
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LCUERPO","LCUERPO");
            $$->add(*$1);
        }
    | MAIN
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LCUERPO","LCUERPO");
            $$->add(*$1);
        }
    | METODO
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LCUERPO","LCUERPO");
            $$->add(*$1);
        }
    | REASIGNACION_VEC
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LCUERPO","LCUERPO");
            $$->add(*$1);
        }
    | INSTANCIA
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LCUERPO","LCUERPO");
            $$->add(*$1);
        }
    | ACCES_VFM Dolar
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LCUERPO","LCUERPO");
            $$->add(*$1);
        }
    | REASIGNACION_VAR_CLASE
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LCUERPO","LCUERPO");
            $$->add(*$1);
        }
    | DECLARAR_ARREGLO
    {
        $$ = new NodoAST(yylineno+1, @1.first_column,"LCUERPO","LCUERPO");
        $$->add(*$1);
    }
    | OBJECTO_ASIGNACION
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LCUERPO","LCUERPO");
            $$->add(*$1);
        }
;

MAIN : tMain pari pard llavI LS llavD
        {
            NodoAST *nodo1 = new NodoAST(yylineno+1, @1.first_column,"main",$1);
            NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"MAIN","MAIN");
            nodo->add(*nodo1);
            nodo->add(*$5);
            $$ = nodo;
        };



LS : LS SEN_IF
        {
            $$=$1;
            NodoAST *nodo = new NodoAST(yylineno+1, @1.first_column,"sen_if","sen_if");
            nodo->add(*$2);
            $$->add(*nodo);
        }
    | SEN_IF
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            NodoAST *nodo = new NodoAST(yylineno+1, @1.first_column,"sen_if","sen_if");
            nodo->add(*$1);
            $$->add(*nodo);
        }
    | LS VAR_ASIG
        {
            $$=$1;
            //NodoAST *nodo = new NodoAST(@2.first_line, @2.first_column,"VAR_ASIG","VAR_ASIG");
            $$->add(*$2);
            //$$->add(*nodo);
        }
    | LS ASIGNACION_VEC
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS IMPRIMIR
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS VAR_DECLARACION
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS REASIGNACION_VEC
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS REPETIR
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS MIENTRAS
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS HACER_MIENTRAS
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS ROMPER
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS SALIR
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS RETORNAR
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS CONTINUAR
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS AUMENTO Dolar
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS DECREMENTO Dolar
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS LLAMADA Dolar
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS ACCES_VFM Dolar
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS PARA
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS NOTIFICACION
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS REASIGNACION_VAR_CLASE
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS INSTANCIA
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS DECLARAR_ARREGLO
        {
            $$=$1;
            $$->add(*$2);
        }
    | LS OBJECTO_ASIGNACION
        {
            $$=$1;
            $$->add(*$2);
        }
    | VAR_ASIG
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | IMPRIMIR
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | VAR_DECLARACION
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | REPETIR
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | MIENTRAS
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | HACER_MIENTRAS
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | ROMPER
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | SALIR
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | CONTINUAR
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | RETORNAR
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | AUMENTO Dolar
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | DECREMENTO Dolar
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | PARA
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | LLAMADA Dolar
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | ACCES_VFM Dolar
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | NOTIFICACION
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | REASIGNACION_VEC
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | ASIGNACION_VEC
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | OBJECTO_ASIGNACION
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | REASIGNACION_VAR_CLASE
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }
    | DECLARAR_ARREGLO
    {
        $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
        $$->add(*$1);
    }
    | INSTANCIA
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LS","LS");
            $$->add(*$1);
        }

; 

/*reasigna valor a las variables globales   c1.nombre = "pascual" */
REASIGNACION_VAR_CLASE : id tPunto id eq EXPL Dolar
        {
            NodoAST *id1 = new NodoAST(yylineno+1, @1.first_column,"id",$1);
            NodoAST *id2 = new NodoAST(yylineno+1, @1.first_column,"id",$3);
            NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"REASIGNACION_VAR_CLASE","REASIGNACION_VAR_CLASE");
            nodo -> add(*id1);
            nodo -> add(*id2);
            nodo -> add(*$5);
            $$ = nodo;
        };


/******     acceder a variables, funciones y metodos de las clases      *******/
/******                 abj.metodoRetrnable()                           *******/
ACCES_VFM : id tPunto LLAMADA
        {
            NodoAST *id = new NodoAST(yylineno+1, @1.first_column,"id",$1);
            NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"ACCES_VFM","ACCES_VFM");
            nodo -> add(*id);
            nodo -> add(*$3);
            $$ = nodo;
        };

/*********************** insanciar clase ***************************/
INSTANCIA: id id eq tNuevo id pari pard Dolar { /*  Clase1 c1 = Nuevo Clase1()$ */
        NodoAST *id1 = new NodoAST(yylineno+1, @1.first_column,"id",$1);
        NodoAST *id2 = new NodoAST(yylineno+1, @1.first_column,"id",$2);
        NodoAST *id3 = new NodoAST(yylineno+1, @1.first_column,"id",$5);
        NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"INSTANCIA","INSTANCIA");
        nodo -> add(*id1);
        nodo -> add(*id2);
        nodo -> add(*id3);
        $$ = nodo;
    }

| id id Dolar { /*  clase1 c1$ */
        NodoAST *id1 = new NodoAST(yylineno+1, @1.first_column,"id",$1);
        NodoAST *id2 = new NodoAST(yylineno+1, @1.first_column,"id",$2);
        NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"INSTANCIA","INSTANCIA");
        nodo -> add(*id1);
        nodo -> add(*id2);
        $$ = nodo;
    }
    ;


/*************  asignacion objeto ===       object = nuevo nombreClase()$       ****/
OBJECTO_ASIGNACION : id eq tNuevo id pari pard Dolar
        {
            NodoAST *id1 = new NodoAST(yylineno+1, @1.first_column,"id",$1);
            NodoAST *id2 = new NodoAST(yylineno+1, @1.first_column,"id",$4);
            NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"OBJECTO_ASIGNACION","OBJECTO_ASIGNACION");
            nodo -> add(*id1);
            nodo -> add(*id2);
            $$ = nodo;
        };
/******* METODO  ***********/
METODO : ENCAPSULAR TIPO id MI_PARAMETRO llavI LS llavD
        {
            NodoAST *nodId = new NodoAST(yylineno+1, @1.first_column,"id",$3);
            NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"METODO","METODO");
            nodo->add(*$1);
            nodo->add(*$2);
            nodo->add(*nodId);
            nodo->add(*$4);
            nodo->add(*$6);
            $$ = nodo;
        }
    | TIPO id MI_PARAMETRO llavI LS llavD
        {
            NodoAST *nodId = new NodoAST(yylineno+1, @1.first_column,"id",$2);
            NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"METODO","METODO");
            nodo->add(*$1);
            nodo->add(*nodId);
            nodo->add(*$3);
            nodo->add(*$5);
            $$ = nodo;
        };

MI_PARAMETRO : pari LPARAMETRO pard { $$ = $2; }
    | pari  pard { NodoAST *nodId = new NodoAST(yylineno+1, @1.first_column,"VACIO",$2); $$ = nodId; }
    ;

ENCAPSULAR : SOBRESRIBIR VISIBILIDAD { $$ = new NodoAST(yylineno+1, @1.first_column,"ENCAPSULAR","ENCAPSULAR");  $$ ->add (*$1); $$ -> add(*$2); }
    | VISIBILIDAD {
        $$ = new NodoAST(yylineno+1, @1.first_column,"ENCAPSULAR","ENCAPSULAR");
        $$->add(*$1);
        }
    | SOBRESRIBIR {
        $$ = new NodoAST(yylineno+1, @1.first_column,"ENCAPSULAR","ENCAPSULAR");
        $$->add(*$1);
        }
    ;

SOBRESRIBIR: tsobrescribir  { $$ = new NodoAST(yylineno+1, @1.first_column,"sobrescribir",$1); } ;

/****** LISTA DE PARAMETROS ******/
LPARAMETRO : LPARAMETRO coma PARAMETRO
        {
            $$=$1;
            $$->add(*$3);
        }
    | PARAMETRO
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LPARAMETRO","LPARAMETRO");
            $$->add(*$1);
        }
        ;

PARAMETRO : TIPO EXPL
        {
            NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"PARAMETRO","PARAMETRO");
            nodo->add(*$1);
            nodo->add(*$2);
            $$ = nodo;
        }
    | EXPL { $$ = $1; };


/*sentencias*/

IMPRIMIR : tPrint pari EXPL pard Dolar
        {
            NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"IMPRIMIR","IMPRIMIR");
            nodo->add(*$3);
            $$ = nodo;
        };

SEN_IF : IF { $$ = $1; }
    | IF ELSE_IF
        {
            NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"else_if","else_if");
            nodo->add(*$1);
            nodo->add(*$2);
            $$->add(*nodo);
            $$ = nodo;
        }
;


REPETIR : tRepetir pari EXPL pard llavI LS llavD
        {

            NodoAST *nodo = new NodoAST(yylineno+1, @1.first_column,"REPETIR","REPETIR");
            nodo->add(*$3); nodo->add(*$6);
            $$ = nodo;
        } ;

PARA : tPara pari INICIAR EXPL Dolar ACTUALIZACION pard llavI LS llavD
    {
        NodoAST *nodo = new NodoAST(yylineno+1, @1.first_column,"PARA","PARA");
        nodo->add(*$3);
        nodo->add(*$4);
        nodo->add(*$6);
        nodo->add(*$9);
        $$ = nodo;
    } ;

INICIAR : VAR_ASIG { $$ = $1;  }
    | VAR_DECLARACION { $$ = $1; }
    ;

ACTUALIZACION : AUMENTO { $$ = $1; }
    | DECREMENTO { $$ = $1; }
    ;

MIENTRAS : tMientras pari EXPL pard llavI LS llavD
        {
            NodoAST *nodo = new NodoAST(yylineno+1, @1.first_column,"MIENTRAS","MIENTRAS");
            nodo->add(*$3);
            nodo->add(*$6);
            $$ = nodo;
        } ;

HACER_MIENTRAS : tHacer llavI LS llavD tMientras pari EXPL pard Dolar
        {
            NodoAST *nodo = new NodoAST(yylineno+1, @1.first_column,"HACER_MIENTRAS","HACER_MIENTRAS");
            nodo->add(*$3);
            nodo->add(*$7);
            $$ = nodo;
        } ;

ELSE_IF : ELSE { $$ = $1; }
    | prSino SEN_IF { $$ = $2; } ;

IF : prSi pari EXPL pard llavI LS llavD
    {
        NodoAST *nodo = new NodoAST(yylineno+1, @1.first_column,"if","if");
        nodo->add(*$3); nodo->add(*$6);
        $$ = nodo;
    };

ELSE : prSino llavI LS llavD
        {
            NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"else","else");
            nodo->add(*$3);
            $$ = nodo;
        };


VAR_ASIG : TIPO LISTAID eq EXPL Dolar
        {
            NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"VAR_ASIG","VAR_ASIG");
            nodo->add(*$1);
            nodo->add(*$2);
            nodo->add(*$4);
            $$ = nodo;
        }
    | id eq EXPL Dolar
       {
           NodoAST *nodo1 = new NodoAST(yylineno+1, @1.first_column,"id",$1);
           NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"VAR_ASIG","VAR_ASIG");
           nodo->add(*nodo1);
           nodo->add(*$3);
           $$ = nodo;
       }
       ;


/************************************************************************/
/*************  PRODUCCIONES DE ARREGLO *********************************/
/************************************************************************/

ASIGNACION_VEC : tArreglo TIPO LISTAID DIMENCION eq llavI VALOR_VEC llavD Dolar
        {
            NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"ASIGNACION_VEC","ASIGNACION_VEC");
            nodo->add(*$2);
            nodo->add(*$3);
            nodo->add(*$4);
            nodo->add(*$7);
            $$ = nodo;
        }
        ;


DECLARAR_ARREGLO : tArreglo TIPO LISTAID DIMENCION Dolar
{
    NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"DECLARAR_ARREGLO","DECLARAR_ARREGLO");
    nodo->add(*$2);
    nodo->add(*$3);
    nodo->add(*$4);
    $$ = nodo;
}
;

VAR_DECLARACION : TIPO LISTAID Dolar
        {
            NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"VAR_DECLARACION","VAR_DECLARACION");
            nodo->add(*$1);
            nodo->add(*$2);
            $$ = nodo;
        }
        ;

LISTAID: LISTAID coma id
        {
            $$=$1;
            NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"ID","ID");
            NodoAST *id = new NodoAST(yylineno+1, @1.first_column,"id",$3);
            nodo->add(*id);
            $$->add(*nodo);
        }
    | id
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"LISTAID","LISTAID");
            NodoAST *nodo = new NodoAST(yylineno+1, @1.first_column,"ID","ID");
            NodoAST *id = new NodoAST(yylineno+1, @1.first_column,"id",$1);
            nodo->add(*id);
            $$->add(*nodo);
        }
    ;

EXPRESION : EXPRESION coma EXPA
        {
            $$=$1;
            $$->add(*$3);
        }
    | EXPA
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"EXPRESION","EXPRESION");
            $$->add(*$1);
        }
        ;

DIMENCION : DIM1 | DIM2 | DIM3 ;

DIM1 : corI EXPA corD
{
    NodoAST *nodo = new NodoAST(yylineno+1, columna,"DIMENCION","DIMENCION");
    nodo->add(*$2);
    $$ = nodo;
};

DIM2 : corI EXPA corD corI EXPA corD
{
    NodoAST *nodo = new NodoAST(yylineno+1, columna,"DIMENCION","DIMENCION");
    nodo->add(*$2);
    nodo->add(*$5);
    $$ = nodo;
};

DIM3 : corI EXPA corD corI EXPA corD corI EXPA corD
{
    NodoAST *nodo = new NodoAST(yylineno+1, columna,"DIMENCION","DIMENCION");
    nodo->add(*$2);
    nodo->add(*$5);
    nodo->add(*$8);
    $$ = nodo;
};


VALOR_VEC : UNIDIMENCION | BIDIMENCION | TRIDIMENCION;

UNIDIMENCION :  EXPRESION
        {
            $$ = new NodoAST(yylineno+1, columna,"UNIDIMENCION","UNIDIMENCION");
            $$ -> add(*$1);
        } ;



BIDIMENCION : BIDIMENCION coma LISBI
        {
            $$=$1;
            $$->add(*$3);
        }
    | LISBI
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"BIDIMENCION","BIDIMENCION");
            $$->add(*$1);
        };


LISBI : llavI EXPRESION llavD {$$ = $2; };

TRIDIMENCION :TRIDIMENCION coma LISTRI
        {
            $$=$1;
            $$->add(*$3);
        }
    | LISTRI
        {
            $$ = new NodoAST(yylineno+1, @1.first_column,"TRIDIMENCION","TRIDIMENCION");
            $$->add(*$1);
        };

LISTRI : llavI BIDIMENCION llavD  { $$ = $2; };


/*********     ACCESO AL ARREGLO    ********/
ACCESO_VEC :  id DIMENCION
        {
            NodoAST *nodo1 = new NodoAST(yylineno+1, @1.first_column,"id",$1);
            NodoAST *nodo = new NodoAST(yylineno+1, @1.first_column,"ACCESO_VEC","ACCESO_VEC");
            nodo->add(*nodo1);
            nodo->add(*$2);
            $$ = nodo;
        };

REASIGNACION_VEC : ACCESO_VEC eq EXPL Dolar
        {
            NodoAST *nodo = new NodoAST(yylineno+1, @1.first_column,"REASIGNACION_VEC","REASIGNACION_VEC");
            nodo->add(*$1);
            nodo->add(*$3);
            $$ = nodo;
        };

ROMPER : tRomper Dolar          { $$ = new NodoAST(yylineno+1, columna,"ROMPER",$1); } ;

SALIR : tSalir Dolar            { $$ = new NodoAST(yylineno+1, columna,"SALIR",$1); } ;

CONTINUAR : tContinuar Dolar    { $$ = new NodoAST(yylineno+1, columna,"CONTINUAR",$1); } ;

RETORNAR: tRetornar EXPL Dolar  { NodoAST *nodo = new NodoAST(yylineno+1, columna,"RETORNAR","RETORNAR"); nodo->add(*$2); $$ = nodo; } ;

NOTIFICACION : tNotificacion pari EXPL coma EXPL pard Dolar
    {
        NodoAST *nodo = new NodoAST(yylineno+1, columna,"NOTIFICACION","NOTIFICACION");
        nodo->add(*$3);
        nodo->add(*$5);
        $$ = nodo;
    }
    ;

AUMENTO : id tAumento
    {
        NodoAST *nodo1 = new NodoAST(yylineno+1, @1.first_column,"id",$1);
        NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"AUMENTO","AUMENTO");
        nodo->add(*nodo1);
        $$ = nodo;
    }
;

DECREMENTO : id tDecremento
    {
        NodoAST *nodo1 = new NodoAST(yylineno+1, @1.first_column,"id",$1);
        NodoAST *nodo = new NodoAST(yylineno+1, @2.first_column,"DECREMENTO","DECREMENTO");
        nodo->add(*nodo1);
        $$ = nodo;
    }
;

LLAMADA : id pari LPARAMETRO pard
        {
            NodoAST *id = new NodoAST(yylineno+1, @1.first_column,"id",$1);
            NodoAST *call = new NodoAST(yylineno+1, @1.first_column,"LLAMADA","LLAMADA");
            call->add(*id);
            call->add(*$3);
            $$ = call;

        }
    | id pari  pard
        {
            NodoAST *id = new NodoAST(yylineno+1, @1.first_column,"id",$1);
            NodoAST *call = new NodoAST(yylineno+1, @1.first_column,"LLAMADA","LLAMADA");
            call->add(*id);
            $$ = call;

        }

    ;

TIPO: prInt         { $$ = new NodoAST(yylineno+1, columna,"int",$1); }
    | prString      { $$ = new NodoAST(yylineno+1, @1.first_column,"string",$1);}
    | prBooleano    { $$ = new NodoAST(yylineno+1, @1.first_column,"bool",$1);}
    | prBool        { $$ = new NodoAST(yylineno+1, @1.first_column,"bool",$1);}
    | prChar        { $$ = new NodoAST(yylineno+1, @1.first_column,"char",$1);}
    | prDouble      { $$ = new NodoAST(yylineno+1, @1.first_column,"double",$1);}
    | tVoid         { $$ = new NodoAST(yylineno+1, @1.first_column,"void",$1);}
    | tArreglo      { $$ = new NodoAST(yylineno+1, @1.first_column,"arreglo",$1);}
    ;

VISIBILIDAD: tPrivado   { $$ = new NodoAST(yylineno+1, columna,"visibilidad",$1); }
    | tProtegido        { $$ = new NodoAST(yylineno+1, @1.first_column,"visibilidad",$1);}
    | tPublico          { $$ = new NodoAST(yylineno+1, @1.first_column,"visibilidad",$1);}
    ;


EXPL: Snot EXPL             { NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"not",$1);  nod->add(*$2); $$=nod;}
    | EXPL Sand EXPL        { NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"and",$2);  nod->add(*$1); nod->add(*$3); $$=nod;}
    | EXPL Snand EXPL       { NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"nand",$2);  nod->add(*$1); nod->add(*$3); $$=nod;}
    | EXPL Sor EXPL         { NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"or",$2);  nod->add(*$1); nod->add(*$3); $$=nod;}
    | EXPL Sxor EXPL        { NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"xor",$2);  nod->add(*$1); nod->add(*$3); $$=nod;}
    | EXPR                  {$$=$1;}

    ;

EXPR: EXPR eqeq EXPR        { NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"eqeq",$2);  nod->add(*$1); nod->add(*$3); $$=nod;}
    | EXPR difQ EXPR        { NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"difQ",$2);  nod->add(*$1); nod->add(*$3); $$=nod;}
    | EXPR menorQ EXPR      { NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"menorQ",$2);  nod->add(*$1); nod->add(*$3); $$=nod;}
    | EXPR mayorQ EXPR      { NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"mayorQ",$2);  nod->add(*$1); nod->add(*$3); $$=nod;}
    | EXPR menorIgualQ EXPR { NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"menorIgualQ",$2);  nod->add(*$1); nod->add(*$3); $$=nod;}
    | EXPR mayorIgualQ EXPR { NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"mayorIgualQ",$2);  nod->add(*$1); nod->add(*$3); $$=nod;}
    | EXPA                  {$$=$1;} ;

EXPA:
         EXPA suma EXPA     { NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"suma",$2);  nod->add(*$1); nod->add(*$3); $$=nod;}
        |EXPA menos EXPA    { NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"resta",$2); nod->add(*$1); nod->add(*$3); $$=nod;}
        |EXPA multi EXPA    { NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"multi",$2); nod->add(*$1); nod->add(*$3); $$=nod;}
        |EXPA division EXPA { NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"div",$2); nod->add(*$1); nod->add(*$3); $$=nod;}
        |EXPA potencia EXPA { NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"potencia",$2); nod->add(*$1);  nod->add(*$3);  $$=nod ;  }
        |menos EXPA         { NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"resta",$1); nod->add(*$2); $$=nod; }
        |entero             { $$ = new NodoAST(yylineno+1, @1.first_column,"int",$1);}
        |caracter           { $$ = new NodoAST(yylineno+1, @1.first_column,"char",$1);}
        |decimal            { $$ = new NodoAST(yylineno+1, @1.first_column,"double",$1);}
        |booleano           { $$ = new NodoAST(yylineno+1, @1.first_column,"bool",$1);}
        |cadena             { $$ = new NodoAST(yylineno+1, @1.first_column,"string",$1);}
        |id                 { $$ = new NodoAST(yylineno+1, @1.first_column,"id",$1);}
        |pari EXPL pard     { $$ = $2; }
        // | id pari LPARAMETRO pard { }
        // | id DIMENCION { }
        |LLAMADA            { $$ = $1; }
        |ACCES_VFM          { $$ = $1; }
        |id tPunto id
            {
                NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"ACCESO_OBJECT","ACCESO_OBJECT");
                NodoAST *id1 = new NodoAST(yylineno+1, @1.first_column,"id1",$1);
                NodoAST *id2 = new NodoAST(yylineno+1, @1.first_column,"id2",$3);
                nod -> add(*id1);
                nod -> add(*id2);
                $$ = nod;
            }
        | id id
            {
             NodoAST *id1 = new NodoAST(yylineno+1, @1.first_column,"id1",$1);
             NodoAST *id2 = new NodoAST(yylineno+1, @1.first_column,"id2",$2);
             NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"ACCESO_OBJECT","ACCESO_OBJECT");
             nod -> add(*id1);
             nod -> add(*id2);
             $$ = nod;
            }
        | ACCESO_VEC        { NodoAST *nod = new NodoAST(yylineno+1, @1.first_column,"DATOS_VEC","DATOS_VEC"); nod -> add(*$1); $$ = nod; }
         ;

%%
