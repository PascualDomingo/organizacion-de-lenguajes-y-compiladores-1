%option case-insensitive
%option yylineno
%{
#include <cstdlib>
#include "parser.h"
#include <QString>
#include <stdio.h>
#include <iostream>
#include <NodoAST.h>
#include "qlist.h"

int yylex();
void yyerror(const char *s);
int linea=0; // Para contar lineas
int columna = 1; // para las columnas
int anterior = 0;
NodoAST *raiz;
%}

%option header-file="scanner.h"
%option outfile="scanner.cpp"
%option noyywrap
%option nounput

mulComentario ("<-")[^\->]*("->")
comentario "//"[^\r\n]*[^\r\n]
letra [a-zñA-ZÑ]+
numero [0-9]+
booleano ("true"|"false"|"verdadero"|"falso")
decimal [0-9]+"."[0-9]+
especiales (\\n)|(\\')|(\\’)|(\\"\"")|(\\"\”")
caracter "\'"("\\")?({especiales}|{letra}|{numero})"\'"

id {letra}({letra}|{numero}|"_")*
cadena "\""[^"\""]*"\""
sinosi ("miif")[[:blank:]]("mielse")

%x COM COMM

%%
INITIAL
{

"("          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pari; }
")"          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pard; }
"$"          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return Dolar; }
"+"         		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return suma; }
"-"         		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return menos; }
"*"         		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return multi; }
"/"         		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return division; }
"^"         		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return potencia; }
"["         		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return corI; }
"]"         		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return corD; }
"="          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return eq;}
"{"          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return llavI;}
"}"          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return llavD;}
","          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return coma;}
"."          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tPunto;}

"=="          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return eqeq;}
"!="          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return difQ;}
"<"          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return menorQ;}
"<="          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return menorIgualQ;}
">"          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return mayorQ;}
">="          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return mayorIgualQ;}
"!"          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return Snot;}
"&&"          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return Sand;}
"!&&"          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return Snand;}
"||"          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return Sor;}
"!||"          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return Sxor;}

"Entero"         	{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return prInt; }
"Cadena"       		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return prString; }
"Booleano"         	{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return prBooleano; }
"Caracter"	        {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return prChar; }
"Doble"         	{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return prDouble; }
"Si"				{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return prSi; }
"Sino"				{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return prSino; }
"Clase"				{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tClase; }
"Principal"			{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tMain; }
"Imprimir"			{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tPrint; }
"Publico"			{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tPublico; }
"Privado"			{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tPrivado; }
"Protegido"			{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tProtegido; }
"++"				{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tAumento; }
"--"				{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tDecremento; }
"Romper"			{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tRomper; }
"Continuar"			{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tContinuar; }
"Salir"				{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tSalir; }
"Repetir"			{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tRepetir; }
"Mientras"			{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tMientras; }
"Hacer"				{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tHacer ; }
"Para"				{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tPara; }
"Void"				{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tVoid; }
"Sobrescribir"		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tsobrescribir; }
"Retornar"			{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tRetornar; }
"MostrarNotificacion" {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tNotificacion; }
"Arreglo" 			{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tArreglo; }
"Nuevo" 			{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return tNuevo; }

{numero}          	{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return entero;}
{decimal}          	{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return decimal;}
{caracter}          {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return caracter;}
{booleano}          {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return booleano;}
{cadena}          	{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return cadena;}
{id}          		{   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return id;}


"\t"            	{
                    	strcpy(yylval.TEXT, yytext); columna=26;
                	}
[[:blank:]]     	{ 	columna++; }
"\n"            	{	linea++; columna = 0; anterior = 0;}
.               	{
                    	columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);
/*                    	errorT *nuevoE = new errorT("Lexico",yytext,linea, columna);
                    	listaErrores->append(*nuevoE);
*/
                    	std::cout <<yytext <<" Error Lexico en la linea "<< linea << " Columna:"<< columna<<  std::endl;
                	}
}

{comentario} 		{  	/*se ignora*/ }
{mulComentario}		{  	/*se ignora*/ }


%%
