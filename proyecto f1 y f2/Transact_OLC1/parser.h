/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    entero = 258,
    decimal = 259,
    caracter = 260,
    booleano = 261,
    cadena = 262,
    id = 263,
    pari = 264,
    pard = 265,
    suma = 266,
    menos = 267,
    multi = 268,
    division = 269,
    potencia = 270,
    arreglo = 271,
    corI = 272,
    corD = 273,
    eq = 274,
    llavI = 275,
    llavD = 276,
    coma = 277,
    Dolar = 278,
    tClase = 279,
    tPara = 280,
    tPunto = 281,
    eqeq = 282,
    difQ = 283,
    menorQ = 284,
    menorIgualQ = 285,
    mayorQ = 286,
    mayorIgualQ = 287,
    Snot = 288,
    Sand = 289,
    Snand = 290,
    Sor = 291,
    Sxor = 292,
    tid = 293,
    prInt = 294,
    prString = 295,
    prBooleano = 296,
    prBool = 297,
    prChar = 298,
    prDouble = 299,
    prSi = 300,
    prSino = 301,
    tMain = 302,
    tPrint = 303,
    tPublico = 304,
    tPrivado = 305,
    tProtegido = 306,
    tAumento = 307,
    tDecremento = 308,
    tRomper = 309,
    tRepetir = 310,
    tMientras = 311,
    tContinuar = 312,
    tSalir = 313,
    tsobrescribir = 314,
    tVoid = 315,
    tHacer = 316,
    tRetornar = 317,
    tNotificacion = 318,
    tArreglo = 319,
    tNuevo = 320
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 24 "parser.yy" /* yacc.c:1909  */

//se especifican los tipo de valores para los no terminales y lo terminales
char TEXT [256];
class NodoAST *nodito;

#line 126 "parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
