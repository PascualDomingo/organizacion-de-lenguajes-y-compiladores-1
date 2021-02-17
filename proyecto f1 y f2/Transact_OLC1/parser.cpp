/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.yy" /* yacc.c:339  */

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

#line 84 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
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
#line 24 "parser.yy" /* yacc.c:355  */

//se especifican los tipo de valores para los no terminales y lo terminales
char TEXT [256];
class NodoAST *nodito;

#line 196 "parser.cpp" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 227 "parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1252

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  191
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  358

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   176,   176,   178,   185,   194,   202,   211,   218,   225,
     231,   237,   242,   247,   253,   258,   263,   268,   273,   278,
     283,   288,   294,   300,   305,   310,   316,   321,   326,   331,
     336,   341,   346,   351,   356,   363,   374,   381,   388,   395,
     400,   405,   410,   415,   420,   425,   430,   435,   440,   445,
     450,   455,   460,   465,   470,   475,   480,   485,   490,   495,
     500,   505,   510,   515,   520,   525,   530,   535,   540,   545,
     550,   555,   560,   565,   570,   575,   580,   585,   590,   595,
     600,   605,   614,   628,   638,   649,   661,   671,   682,   693,
     694,   697,   698,   702,   708,   711,   716,   723,   730,   735,
     742,   743,   754,   762,   772,   773,   776,   777,   780,   788,
     796,   797,   799,   806,   814,   822,   837,   849,   859,   868,
     876,   886,   891,   898,   898,   898,   900,   907,   915,   925,
     925,   925,   927,   935,   940,   947,   949,   954,   960,   964,
     973,   981,   983,   985,   987,   989,   998,  1007,  1016,  1025,
    1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  1046,  1047,
    1048,  1052,  1053,  1054,  1055,  1056,  1057,  1061,  1062,  1063,
    1064,  1065,  1066,  1067,  1070,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1085,  1086,  1087,
    1096,  1105
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "entero", "decimal", "caracter",
  "booleano", "cadena", "id", "pari", "pard", "suma", "menos", "multi",
  "division", "potencia", "arreglo", "corI", "corD", "eq", "llavI",
  "llavD", "coma", "Dolar", "tClase", "tPara", "tPunto", "eqeq", "difQ",
  "menorQ", "menorIgualQ", "mayorQ", "mayorIgualQ", "Snot", "Sand",
  "Snand", "Sor", "Sxor", "tid", "prInt", "prString", "prBooleano",
  "prBool", "prChar", "prDouble", "prSi", "prSino", "tMain", "tPrint",
  "tPublico", "tPrivado", "tProtegido", "tAumento", "tDecremento",
  "tRomper", "tRepetir", "tMientras", "tContinuar", "tSalir",
  "tsobrescribir", "tVoid", "tHacer", "tRetornar", "tNotificacion",
  "tArreglo", "tNuevo", "$accept", "INICIO", "LCLASE", "CLASE", "CUERPO",
  "MAIN", "LS", "REASIGNACION_VAR_CLASE", "ACCES_VFM", "INSTANCIA",
  "OBJECTO_ASIGNACION", "METODO", "MI_PARAMETRO", "ENCAPSULAR",
  "SOBRESRIBIR", "LPARAMETRO", "PARAMETRO", "IMPRIMIR", "SEN_IF",
  "REPETIR", "PARA", "INICIAR", "ACTUALIZACION", "MIENTRAS",
  "HACER_MIENTRAS", "ELSE_IF", "IF", "ELSE", "VAR_ASIG", "ASIGNACION_VEC",
  "DECLARAR_ARREGLO", "VAR_DECLARACION", "LISTAID", "EXPRESION",
  "DIMENCION", "DIM1", "DIM2", "DIM3", "VALOR_VEC", "UNIDIMENCION",
  "BIDIMENCION", "LISBI", "TRIDIMENCION", "LISTRI", "ACCESO_VEC",
  "REASIGNACION_VEC", "ROMPER", "SALIR", "CONTINUAR", "RETORNAR",
  "NOTIFICACION", "AUMENTO", "DECREMENTO", "LLAMADA", "TIPO",
  "VISIBILIDAD", "EXPL", "EXPR", "EXPA", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320
};
# endif

#define YYPACT_NINF -174

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-174)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -16,     3,    18,   -16,  -174,     0,  -174,  -174,  1156,    -2,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,    27,  -174,  -174,
    -174,  -174,  -174,   871,  1183,  -174,  -174,    22,  -174,  -174,
    -174,    40,    65,  -174,  -174,  -174,  -174,    33,  -174,    47,
    -174,    52,   779,   118,    80,  -174,  -174,  -174,  -174,    49,
    -174,    88,  -174,  -174,  -174,    75,  -174,  -174,  -174,    40,
    -174,  -174,  -174,  -174,  -174,  -174,    83,   871,  -174,  -174,
    -174,   103,  -174,   398,   109,    54,    55,  -174,  -174,  -174,
    -174,  -174,  -174,    32,   398,   779,  -174,  -174,  -174,   628,
     398,   131,   191,   797,    94,    -7,  -174,   112,  -174,    50,
    -174,  -174,  -174,  -174,   398,    88,   109,   438,   717,   125,
     398,   142,  -174,   154,  -174,   759,   155,    -6,   139,   779,
     779,   779,   779,   779,   149,  -174,   159,  -174,   398,   398,
     398,   398,   779,   779,   779,   779,   779,   779,   398,  1118,
      78,    50,   144,  -174,  -174,    12,  -174,   398,   160,  1118,
     454,  -174,   163,  -174,    44,   167,  -174,   139,   139,   166,
     166,  -174,   779,   175,  -174,  -174,    51,    51,  -174,  -174,
    -174,  -174,  -174,  -174,   493,   148,   183,   190,   194,   181,
     200,   201,   192,   196,   198,   398,   215,   812,  -174,   199,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,   184,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,   209,
     214,   218,    88,   216,  -174,   219,  1118,  -174,   801,   160,
     838,  -174,   233,  -174,   761,   222,  -174,  -174,  -174,   147,
     398,   398,  -174,   398,   398,  -174,  -174,  1118,   508,   398,
    -174,  -174,   224,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,   225,   230,   232,  -174,   -13,  -174,  -174,  -174,  -174,
    -174,  1181,   882,  -174,  -174,   238,   245,  -174,   398,  -174,
    -174,    28,   124,   223,   236,   908,  -174,   406,  -174,  -174,
    -174,  -174,  1118,  -174,  1232,   246,   253,  -174,   268,  -174,
     272,  -174,    94,  -174,  -174,   779,   599,   247,   252,   266,
     275,   241,   398,   952,   779,   116,   121,   779,   279,   283,
     286,   803,   299,  1118,  -174,  1118,  1118,   300,   244,  -174,
    -174,  -174,    94,  -174,  -174,   283,  -174,  -174,    95,   301,
    -174,  -174,   978,  1022,  1048,   398,   289,   293,  -174,  -174,
    -174,   377,  -174,  1118,   296,  1092,  -174,  -174
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     3,     0,     0,
       6,   150,   151,   152,   153,   154,   155,     0,   160,   158,
     159,    94,   156,   157,     0,    27,    32,     0,    30,    34,
      28,     0,    93,    23,    24,    33,    26,     0,    29,     0,
      92,     0,     0,     0,     0,   139,   123,   124,   125,     0,
     157,     0,     5,    11,    20,     0,    16,    17,    12,     0,
       9,    10,    19,    14,    15,    31,     0,   157,    21,    22,
      25,     0,    91,     0,   120,     0,     0,    85,   180,   182,
     181,   183,   184,   185,     0,     0,   188,   191,   187,     0,
       0,     0,     0,   166,   173,     0,    83,     0,   120,     0,
      18,     7,     8,    13,     0,     0,   120,     0,     0,     0,
       0,     0,   118,     0,   190,     0,     0,     0,   179,     0,
       0,     0,     0,     0,   126,   161,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   140,    90,     0,    96,     0,    98,     0,
       0,   119,     0,   149,     0,   189,   186,   174,   175,   176,
     177,   178,     0,     0,   162,   163,   164,   165,   167,   168,
     169,   171,   170,   172,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
      81,    78,    61,    37,    63,    72,    64,    65,   100,    60,
      77,    80,    62,    76,    66,    67,    68,    69,    75,     0,
       0,     0,     0,     0,   117,     0,     0,    89,     0,    97,
       0,   114,     0,   148,     0,     0,    82,   146,   147,     0,
       0,     0,   141,     0,     0,   143,   142,     0,     0,     0,
      35,    56,     0,    57,    59,    40,    36,    43,    54,    44,
      45,    38,    39,    58,    41,    42,    46,    47,    49,    48,
      55,     0,     0,     0,    74,     0,   101,   110,    70,    71,
      73,     0,     0,    95,    88,     0,   127,    86,     0,   104,
     105,     0,     0,     0,     0,     0,   144,     0,    53,    50,
      51,    52,     0,   111,     0,   132,     0,   129,   130,   134,
     131,   137,   122,    87,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,   113,
     135,   138,   121,   116,   133,     0,   136,   128,     0,     0,
     106,   107,     0,     0,     0,     0,     0,     0,   112,   102,
     108,     0,   145,     0,     0,     0,   109,   103
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -174,  -174,  -174,   323,  -174,   292,  -148,    29,    -8,    36,
      79,   303,   227,   305,  -174,   228,   119,   213,   -92,   239,
     264,  -174,  -174,   313,   338,  -174,  -174,  -174,    11,    19,
     105,    15,   -48,    59,   -90,  -174,  -174,  -174,  -174,  -174,
      67,    25,  -174,    26,    -3,   111,   345,   353,   360,   392,
     400,  -173,   195,   249,     2,   316,   366,   846,   -29
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    24,    25,   187,   188,    86,   190,
     191,    30,   109,    31,    32,   145,   146,   192,   193,   194,
     195,   278,   339,   196,   197,   266,   198,   267,   199,   200,
     201,   202,    75,   315,    45,    46,    47,    48,   296,   297,
     316,   299,   300,   301,    87,   203,   204,   205,   206,   207,
     208,   209,   210,    88,   212,    40,   148,    93,    94
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      27,   220,   115,    99,   156,    37,    41,   292,     1,   140,
      39,     5,   138,    89,   261,    42,    55,    43,     6,    33,
       8,    37,   217,    36,    44,    51,    39,    34,   128,   129,
     130,   131,   177,    71,   218,    60,    49,    26,   307,    63,
     114,   115,    68,    61,    28,    65,    70,   261,    66,    42,
      69,   215,    73,    54,   223,    74,   118,   141,   116,    97,
      56,    71,   128,   129,   130,   131,   218,    42,   272,   105,
     101,    76,   111,   110,   103,    77,   111,   112,   102,    11,
      12,    13,    14,    15,    16,   128,   129,    29,    95,   285,
     157,   158,   159,   160,   161,   246,    98,   213,   100,   261,
      22,   214,   104,    57,    67,   119,   120,   121,   122,   123,
     147,   106,   261,    35,    18,    19,    20,   147,   108,    38,
     113,    78,    79,    80,    81,    82,    83,    84,   246,    62,
      85,   189,   139,   224,   308,    64,    37,   330,   317,   126,
     261,   189,   331,   319,   313,   149,    37,   227,   228,   340,
     151,    90,   121,   122,   123,    66,    41,   115,   128,   129,
     130,   131,   152,   155,   216,    42,   162,    43,   163,   261,
     261,   261,   222,   293,    44,   342,   115,   343,   344,   242,
     246,   123,   261,    91,    37,   225,    11,    12,    13,    14,
      15,    16,   229,   246,   128,   129,   130,   131,   251,   230,
     227,   228,   254,   231,   232,   355,   252,    22,   189,   233,
     234,    50,   242,    37,   127,   235,   241,    37,   237,   236,
     147,   246,   264,   243,   239,   128,   129,   130,   131,   189,
     265,   251,   268,   309,    37,   254,   271,   269,   213,   252,
     279,   270,   302,   275,   280,   277,   310,   288,   289,   241,
     246,   246,   246,   290,   346,   291,   243,   128,   129,   130,
     131,   304,   305,   246,   242,   302,   244,   323,   317,    37,
     128,   129,   130,   131,   318,   324,   321,   242,   128,   129,
     130,   131,    37,   251,   189,   302,   325,   254,   332,    37,
     319,   252,   253,    96,   320,   326,   251,   327,   255,   244,
     254,   241,   333,   314,   252,   242,   335,   338,   243,   345,
      37,   347,   352,   353,   241,   189,    53,   189,   189,   356,
      37,   243,    37,    37,   251,   253,     7,    58,   254,    59,
     295,   255,   252,   142,   242,   242,   242,   273,   298,    37,
      37,    37,   241,   154,   334,   189,   336,   242,    72,   243,
      37,   244,    37,   251,   251,   251,     0,   254,   254,   254,
       0,   252,   252,   252,   244,    96,   251,     0,     0,     0,
     254,   241,   241,   241,   252,     0,     0,   253,   243,   243,
     243,     0,   262,   255,   241,     0,     0,   354,   211,     0,
     253,   243,   244,     0,     0,     0,   255,     0,   211,     0,
     245,    78,    79,    80,    81,    82,    83,    84,     0,    92,
      85,   128,   129,   130,   131,   262,     0,     0,   253,     0,
       0,   244,   244,   244,   255,     0,   247,     0,   312,     0,
       0,    90,     0,   245,   244,     0,   263,     0,     0,   107,
     128,   129,   130,   131,     0,     0,     0,   253,   253,   253,
     117,   248,     0,   255,   255,   255,   125,     0,     0,   247,
     253,   143,     0,     0,     0,   211,   255,   262,     0,   263,
      92,     0,   128,   129,   130,   131,   150,   221,     0,     0,
     262,     0,     0,     0,   248,   245,   211,     0,   128,   129,
     130,   131,     0,     0,   164,   165,   166,   167,   245,     0,
     249,     0,     0,     0,   174,     0,     0,     0,   262,     0,
       0,   247,     0,   219,     0,     0,   226,   341,     0,     0,
       0,   263,     0,     0,   247,   250,   245,   128,   129,   130,
     131,   286,   256,   249,   263,     0,   248,   262,   262,   262,
     257,   211,   128,   129,   130,   131,     0,   258,     0,   248,
     262,   238,   247,     0,     0,   245,   245,   245,   250,     0,
       0,     0,   263,     0,     0,   256,     0,     0,   245,     0,
       0,     0,   211,   257,   211,   211,     0,   248,     0,   259,
     258,   247,   247,   247,     0,   249,     0,   260,     0,     0,
       0,   263,   263,   263,   247,     0,   281,   282,   249,   283,
     284,     0,   211,     0,   263,   287,   248,   248,   248,     0,
     250,     0,   259,     0,     0,     0,     0,   256,     0,   248,
     260,     0,   322,   250,     0,   257,   249,     0,     0,     0,
     256,     0,   258,   128,   129,   130,   131,     0,   257,   119,
     120,   121,   122,   123,   306,   258,   124,     0,     0,     0,
       0,   250,     0,     0,     0,   249,   249,   249,   256,     0,
       0,     0,     0,     0,   259,     0,   257,     0,   249,     0,
       0,     0,   260,   258,     0,     0,     0,   259,   328,     0,
     250,   250,   250,     0,     0,   260,     0,   256,   256,   256,
       0,     0,     0,   250,     0,   257,   257,   257,     0,     0,
     256,     0,   258,   258,   258,   259,     0,     0,   257,     0,
       0,   351,     0,   260,     0,   258,     0,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    84,   144,     0,    85,
       0,     0,     0,     0,   259,   259,   259,     0,     0,     0,
       0,     0,   260,   260,   260,     0,     0,   259,     0,     0,
      90,     0,     0,     0,     0,   260,    11,    12,    13,    14,
      15,    16,    78,    79,    80,    81,    82,    83,    84,   153,
       0,    85,   119,   120,   121,   122,   123,    22,     0,   276,
       0,    50,    78,    79,    80,    81,    82,    83,    84,     0,
       0,    85,    90,     0,     0,     0,     0,     0,    11,    12,
      13,    14,    15,    16,    78,    79,    80,    81,    82,    83,
      84,     0,     0,    85,   119,   120,   121,   122,   123,    22,
     175,   337,     0,    50,   132,   133,   134,   135,   136,   137,
       0,     0,     0,   240,    90,     0,     0,   176,     0,     0,
      11,    12,    13,    14,    15,    16,   175,     0,     0,     0,
       0,    11,    12,    13,    14,    15,    16,   177,     0,   274,
     178,    22,     0,   176,     0,    50,   179,   180,   181,   182,
     183,     0,    22,   184,   185,   186,    23,    11,    12,    13,
      14,    15,    16,   177,     0,     0,   178,     0,     0,     0,
     175,     0,   179,   180,   181,   182,   183,     0,    22,   184,
     185,   186,    23,   303,     0,     0,     0,   176,     0,     0,
      11,    12,    13,    14,    15,    16,   175,     0,     0,     0,
       0,    11,    12,    13,    14,    15,    16,   177,     0,   311,
     178,    22,     0,   176,     0,    50,   179,   180,   181,   182,
     183,     0,    22,   184,   185,   186,    23,    11,    12,    13,
      14,    15,    16,   177,     0,     0,   178,     0,     0,     0,
     175,     0,   179,   180,   181,   182,   183,     0,    22,   184,
     185,   186,    23,   329,     0,     0,     0,   176,   168,   169,
     170,   171,   172,   173,     0,     0,   175,     0,     0,     0,
       0,    11,    12,    13,    14,    15,    16,   177,     0,   348,
     178,     0,     0,   176,     0,     0,   179,   180,   181,   182,
     183,     0,    22,   184,   185,   186,    23,    11,    12,    13,
      14,    15,    16,   177,     0,     0,   178,     0,     0,     0,
     175,     0,   179,   180,   181,   182,   183,     0,    22,   184,
     185,   186,    23,   349,     0,     0,     0,   176,     0,     0,
       0,     0,     0,     0,     0,     0,   175,     0,     0,     0,
       0,    11,    12,    13,    14,    15,    16,   177,     0,   350,
     178,     0,     0,   176,     0,     0,   179,   180,   181,   182,
     183,     0,    22,   184,   185,   186,    23,    11,    12,    13,
      14,    15,    16,   177,     0,     0,   178,     0,     0,     0,
     175,     0,   179,   180,   181,   182,   183,     0,    22,   184,
     185,   186,    23,   357,     0,     0,     0,   176,     0,     0,
       0,     0,     0,     0,     0,     0,   175,     0,     0,     0,
       0,    11,    12,    13,    14,    15,    16,   177,     0,     0,
     178,     0,     0,   176,     0,     0,   179,   180,   181,   182,
     183,     0,    22,   184,   185,   186,    23,    11,    12,    13,
      14,    15,    16,   177,     9,     0,   178,     0,     0,     0,
       0,     0,   179,   180,   181,   182,   183,    10,    22,   184,
     185,   186,    23,     0,    78,    79,    80,    81,    82,    83,
      84,     9,     0,    85,     0,    11,    12,    13,    14,    15,
      16,   294,     0,    17,    52,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,    21,    22,     0,     0,     0,
      23,     0,    11,    12,    13,    14,    15,    16,     0,     0,
      17,     0,    18,    19,    20,    78,    79,    80,    81,    82,
      83,    84,    21,    22,    85,     0,     0,    23,     0,     0,
       0,     0,   314
};

static const yytype_int16 yycheck[] =
{
       8,   149,     9,    51,    10,     8,     8,    20,    24,    99,
       8,     8,    19,    42,   187,    17,    24,    19,     0,     8,
      20,    24,    10,     8,    26,    23,    24,     8,    34,    35,
      36,    37,    45,    31,    22,    24,     9,     8,    10,    24,
       8,     9,    31,    24,     8,    23,    31,   220,     8,    17,
      31,   141,    19,    24,    10,     8,    85,   105,    26,    10,
      24,    59,    34,    35,    36,    37,    22,    17,   216,    67,
      59,    19,    22,    19,    59,    23,    22,    23,    59,    39,
      40,    41,    42,    43,    44,    34,    35,     8,     8,   237,
     119,   120,   121,   122,   123,   187,     8,    19,    23,   272,
      60,    23,    19,    24,    64,    11,    12,    13,    14,    15,
     108,     8,   285,     8,    49,    50,    51,   115,     9,     8,
      65,     3,     4,     5,     6,     7,     8,     9,   220,    24,
      12,   139,    20,   162,    10,    24,   139,    21,    22,     8,
     313,   149,    21,    22,   292,    20,   149,    52,    53,   322,
       8,    33,    13,    14,    15,     8,     8,     9,    34,    35,
      36,    37,     8,     8,    20,    17,    17,    19,     9,   342,
     343,   344,     9,   265,    26,   323,     9,   325,   326,   187,
     272,    15,   355,    65,   187,    10,    39,    40,    41,    42,
      43,    44,     9,   285,    34,    35,    36,    37,   187,     9,
      52,    53,   187,     9,    23,   353,   187,    60,   216,     9,
       9,    64,   220,   216,    23,    23,   187,   220,    20,    23,
     218,   313,    23,   187,     9,    34,    35,    36,    37,   237,
      46,   220,    23,    10,   237,   220,    20,    23,    19,   220,
     229,    23,   271,    10,   229,    23,    10,    23,    23,   220,
     342,   343,   344,    23,    10,    23,   220,    34,    35,    36,
      37,    23,    17,   355,   272,   294,   187,    20,    22,   272,
      34,    35,    36,    37,    21,    23,   305,   285,    34,    35,
      36,    37,   285,   272,   292,   314,    20,   272,   317,   292,
      22,   272,   187,    44,    22,    20,   285,    56,   187,   220,
     285,   272,    23,    20,   285,   313,    20,     8,   272,     9,
     313,    10,    23,    20,   285,   323,    24,   325,   326,    23,
     323,   285,   325,   326,   313,   220,     3,    24,   313,    24,
     271,   220,   313,   106,   342,   343,   344,   218,   271,   342,
     343,   344,   313,   115,   319,   353,   320,   355,    32,   313,
     353,   272,   355,   342,   343,   344,    -1,   342,   343,   344,
      -1,   342,   343,   344,   285,   116,   355,    -1,    -1,    -1,
     355,   342,   343,   344,   355,    -1,    -1,   272,   342,   343,
     344,    -1,   187,   272,   355,    -1,    -1,    10,   139,    -1,
     285,   355,   313,    -1,    -1,    -1,   285,    -1,   149,    -1,
     187,     3,     4,     5,     6,     7,     8,     9,    -1,    43,
      12,    34,    35,    36,    37,   220,    -1,    -1,   313,    -1,
      -1,   342,   343,   344,   313,    -1,   187,    -1,    22,    -1,
      -1,    33,    -1,   220,   355,    -1,   187,    -1,    -1,    73,
      34,    35,    36,    37,    -1,    -1,    -1,   342,   343,   344,
      84,   187,    -1,   342,   343,   344,    90,    -1,    -1,   220,
     355,    23,    -1,    -1,    -1,   216,   355,   272,    -1,   220,
     104,    -1,    34,    35,    36,    37,   110,    23,    -1,    -1,
     285,    -1,    -1,    -1,   220,   272,   237,    -1,    34,    35,
      36,    37,    -1,    -1,   128,   129,   130,   131,   285,    -1,
     187,    -1,    -1,    -1,   138,    -1,    -1,    -1,   313,    -1,
      -1,   272,    -1,   147,    -1,    -1,    23,   322,    -1,    -1,
      -1,   272,    -1,    -1,   285,   187,   313,    34,    35,    36,
      37,    23,   187,   220,   285,    -1,   272,   342,   343,   344,
     187,   292,    34,    35,    36,    37,    -1,   187,    -1,   285,
     355,   185,   313,    -1,    -1,   342,   343,   344,   220,    -1,
      -1,    -1,   313,    -1,    -1,   220,    -1,    -1,   355,    -1,
      -1,    -1,   323,   220,   325,   326,    -1,   313,    -1,   187,
     220,   342,   343,   344,    -1,   272,    -1,   187,    -1,    -1,
      -1,   342,   343,   344,   355,    -1,   230,   231,   285,   233,
     234,    -1,   353,    -1,   355,   239,   342,   343,   344,    -1,
     272,    -1,   220,    -1,    -1,    -1,    -1,   272,    -1,   355,
     220,    -1,    23,   285,    -1,   272,   313,    -1,    -1,    -1,
     285,    -1,   272,    34,    35,    36,    37,    -1,   285,    11,
      12,    13,    14,    15,   278,   285,    18,    -1,    -1,    -1,
      -1,   313,    -1,    -1,    -1,   342,   343,   344,   313,    -1,
      -1,    -1,    -1,    -1,   272,    -1,   313,    -1,   355,    -1,
      -1,    -1,   272,   313,    -1,    -1,    -1,   285,   312,    -1,
     342,   343,   344,    -1,    -1,   285,    -1,   342,   343,   344,
      -1,    -1,    -1,   355,    -1,   342,   343,   344,    -1,    -1,
     355,    -1,   342,   343,   344,   313,    -1,    -1,   355,    -1,
      -1,   345,    -1,   313,    -1,   355,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      -1,    -1,    -1,    -1,   342,   343,   344,    -1,    -1,    -1,
      -1,    -1,   342,   343,   344,    -1,    -1,   355,    -1,    -1,
      33,    -1,    -1,    -1,    -1,   355,    39,    40,    41,    42,
      43,    44,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    11,    12,    13,    14,    15,    60,    -1,    18,
      -1,    64,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    33,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    11,    12,    13,    14,    15,    60,
       8,    18,    -1,    64,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    21,    33,    -1,    -1,    25,    -1,    -1,
      39,    40,    41,    42,    43,    44,     8,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    -1,    21,
      48,    60,    -1,    25,    -1,    64,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    63,    64,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    48,    -1,    -1,    -1,
       8,    -1,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    63,    64,    21,    -1,    -1,    -1,    25,    -1,    -1,
      39,    40,    41,    42,    43,    44,     8,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    -1,    21,
      48,    60,    -1,    25,    -1,    64,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    63,    64,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    48,    -1,    -1,    -1,
       8,    -1,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    63,    64,    21,    -1,    -1,    -1,    25,   132,   133,
     134,   135,   136,   137,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    -1,    21,
      48,    -1,    -1,    25,    -1,    -1,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    63,    64,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    48,    -1,    -1,    -1,
       8,    -1,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    63,    64,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    -1,    21,
      48,    -1,    -1,    25,    -1,    -1,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    63,    64,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    48,    -1,    -1,    -1,
       8,    -1,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    63,    64,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      48,    -1,    -1,    25,    -1,    -1,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    63,    64,    39,    40,    41,
      42,    43,    44,    45,     8,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    57,    58,    21,    60,    61,
      62,    63,    64,    -1,     3,     4,     5,     6,     7,     8,
       9,     8,    -1,    12,    -1,    39,    40,    41,    42,    43,
      44,    20,    -1,    47,    21,    49,    50,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      64,    -1,    39,    40,    41,    42,    43,    44,    -1,    -1,
      47,    -1,    49,    50,    51,     3,     4,     5,     6,     7,
       8,     9,    59,    60,    12,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    67,    68,    69,     8,     0,    69,    20,     8,
      21,    39,    40,    41,    42,    43,    44,    47,    49,    50,
      51,    59,    60,    64,    70,    71,    73,    74,    75,    76,
      77,    79,    80,    94,    95,    96,    97,   110,   111,   120,
     121,     8,    17,    19,    26,   100,   101,   102,   103,     9,
      64,   120,    21,    71,    73,    74,    75,    76,    77,    79,
      94,    95,    96,    97,   111,    23,     8,    64,    94,    95,
      97,   120,   121,    19,     8,    98,    19,    23,     3,     4,
       5,     6,     7,     8,     9,    12,    74,   110,   119,   124,
      33,    65,   122,   123,   124,     8,   119,    10,     8,    98,
      23,    94,    95,    97,    19,   120,     8,   122,     9,    78,
      19,    22,    23,    65,     8,     9,    26,   122,   124,    11,
      12,    13,    14,    15,    18,   122,     8,    23,    34,    35,
      36,    37,    27,    28,    29,    30,    31,    32,    19,    20,
     100,    98,    78,    23,    10,    81,    82,   120,   122,    20,
     122,     8,     8,    10,    81,     8,    10,   124,   124,   124,
     124,   124,    17,     9,   122,   122,   122,   122,   123,   123,
     123,   123,   123,   123,   122,     8,    25,    45,    48,    54,
      55,    56,    57,    58,    61,    62,    63,    72,    73,    74,
      75,    76,    83,    84,    85,    86,    89,    90,    92,    94,
      95,    96,    97,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    19,    23,   100,    20,    10,    22,   122,
      72,    23,     9,    10,   124,    10,    23,    52,    53,     9,
       9,     9,    23,     9,     9,    23,    23,    20,   122,     9,
      21,    73,    74,    75,    76,    83,    84,    85,    86,    89,
      90,    94,    95,    96,    97,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    23,    46,    91,    93,    23,    23,
      23,    20,    72,    82,    21,    10,    18,    23,    87,    94,
      97,   122,   122,   122,   122,    72,    23,   122,    23,    23,
      23,    23,    20,    84,    20,    99,   104,   105,   106,   107,
     108,   109,   124,    21,    23,    17,   122,    10,    10,    10,
      10,    21,    22,    72,    20,    99,   106,    22,    21,    22,
      22,   124,    23,    20,    23,    20,    20,    56,   122,    21,
      21,    21,   124,    23,   107,    20,   109,    18,     8,    88,
     117,   118,    72,    72,    72,     9,    10,    10,    21,    21,
      21,   122,    23,    20,    10,    72,    23,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    69,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    73,    74,    75,    75,    76,    77,    77,    78,
      78,    79,    79,    79,    80,    81,    81,    82,    82,    83,
      84,    84,    85,    86,    87,    87,    88,    88,    89,    90,
      91,    91,    92,    93,    94,    94,    95,    96,    97,    98,
      98,    99,    99,   100,   100,   100,   101,   102,   103,   104,
     104,   104,   105,   106,   106,   107,   108,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   120,   121,   121,
     121,   122,   122,   122,   122,   122,   122,   123,   123,   123,
     123,   123,   123,   123,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     5,     4,     3,     3,     2,
       2,     2,     2,     3,     2,     2,     2,     2,     3,     2,
       2,     2,     2,     1,     1,     2,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     6,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     3,     3,     3,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     6,     3,     8,     3,     7,     7,     6,     3,
       2,     2,     1,     1,     1,     3,     1,     2,     1,     5,
       1,     2,     7,    10,     1,     1,     1,     1,     7,     9,
       1,     2,     7,     4,     5,     4,     9,     5,     3,     3,
       1,     3,     1,     1,     1,     1,     3,     6,     9,     1,
       1,     1,     1,     3,     1,     3,     3,     1,     3,     2,
       4,     2,     2,     2,     3,     7,     2,     2,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     3,
       2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 176 "parser.yy" /* yacc.c:1646  */
    { raiz = (yyval.nodito); }
#line 1842 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 179 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            //NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column,"CLASE","CLASE");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
            //$$->add(*nodo);
        }
#line 1853 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 186 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LCLASE","LCLASE");
            //NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column,"CLASE","CLASE");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
            //$$->add(*nodo);
        }
#line 1864 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 195 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *nodo1 = new NodoAST(yylineno+1, (yylsp[-4]).first_column,"id",(yyvsp[-3].TEXT));
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-3]).first_column,"CLASE","CLASE");
            nodo->add(*nodo1);
            nodo->add(*(yyvsp[-1].nodito));
            (yyval.nodito) = nodo;
        }
#line 1876 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 203 "parser.yy" /* yacc.c:1646  */
    {  /*cuando la clase puede estar vacia*/
            NodoAST *nodo1 = new NodoAST(yylineno+1, (yylsp[-3]).first_column,"id",(yyvsp[-2].TEXT));
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"CLASE","CLASE");
            nodo->add(*nodo1);
            (yyval.nodito) = nodo;
        }
#line 1887 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 212 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-2].nodito);
            (yyvsp[0].nodito)->add(*(yyvsp[-1].nodito));
            (yyval.nodito) ->add(*(yyvsp[0].nodito));

        }
#line 1898 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 219 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-2].nodito);
            (yyvsp[0].nodito)->add(*(yyvsp[-1].nodito));
            (yyval.nodito) ->add(*(yyvsp[0].nodito));

        }
#line 1909 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 226 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));

        }
#line 1919 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 232 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));

        }
#line 1929 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 238 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 1938 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 243 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 1947 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 248 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-2].nodito);
            (yyvsp[0].nodito) ->add(*(yyvsp[-1].nodito));
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 1957 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 254 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito) ->add(*(yyvsp[0].nodito));
        }
#line 1966 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 259 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito) ->add(*(yyvsp[0].nodito));
        }
#line 1975 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 264 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito) ->add(*(yyvsp[0].nodito));
        }
#line 1984 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 269 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito) ->add(*(yyvsp[0].nodito));
        }
#line 1993 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 274 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-2].nodito);
            (yyval.nodito) ->add(*(yyvsp[-1].nodito));
        }
#line 2002 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 279 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito) ->add(*(yyvsp[0].nodito));
        }
#line 2011 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 284 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito) ->add(*(yyvsp[0].nodito));
        }
#line 2020 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 289 "parser.yy" /* yacc.c:1646  */
    {
            (yyvsp[0].nodito) ->add(*(yyvsp[-1].nodito));
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"LCUERPO","LCUERPO");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2030 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 295 "parser.yy" /* yacc.c:1646  */
    {
            (yyvsp[0].nodito) ->add(*(yyvsp[-1].nodito));
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"LCUERPO","LCUERPO");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2040 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 301 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LCUERPO","LCUERPO");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2049 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 306 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LCUERPO","LCUERPO");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2058 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 311 "parser.yy" /* yacc.c:1646  */
    {
            (yyvsp[0].nodito) ->add(*(yyvsp[-1].nodito));
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"LCUERPO","LCUERPO");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2068 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 317 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LCUERPO","LCUERPO");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2077 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 322 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LCUERPO","LCUERPO");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2086 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 327 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LCUERPO","LCUERPO");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2095 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 332 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LCUERPO","LCUERPO");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2104 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 337 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LCUERPO","LCUERPO");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2113 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 342 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"LCUERPO","LCUERPO");
            (yyval.nodito)->add(*(yyvsp[-1].nodito));
        }
#line 2122 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 347 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LCUERPO","LCUERPO");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2131 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 352 "parser.yy" /* yacc.c:1646  */
    {
        (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LCUERPO","LCUERPO");
        (yyval.nodito)->add(*(yyvsp[0].nodito));
    }
#line 2140 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 357 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LCUERPO","LCUERPO");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2149 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 364 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *nodo1 = new NodoAST(yylineno+1, (yylsp[-5]).first_column,"main",(yyvsp[-5].TEXT));
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-4]).first_column,"MAIN","MAIN");
            nodo->add(*nodo1);
            nodo->add(*(yyvsp[-1].nodito));
            (yyval.nodito) = nodo;
        }
#line 2161 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 375 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"sen_if","sen_if");
            nodo->add(*(yyvsp[0].nodito));
            (yyval.nodito)->add(*nodo);
        }
#line 2172 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 382 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[0]).first_column,"sen_if","sen_if");
            nodo->add(*(yyvsp[0].nodito));
            (yyval.nodito)->add(*nodo);
        }
#line 2183 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 389 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            //NodoAST *nodo = new NodoAST(@2.first_line, @2.first_column,"VAR_ASIG","VAR_ASIG");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
            //$$->add(*nodo);
        }
#line 2194 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 396 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2203 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 401 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2212 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 406 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2221 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 411 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2230 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 416 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2239 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 421 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2248 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 426 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2257 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 431 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2266 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 436 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2275 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 441 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2284 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 446 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2293 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 451 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-2].nodito);
            (yyval.nodito)->add(*(yyvsp[-1].nodito));
        }
#line 2302 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 456 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-2].nodito);
            (yyval.nodito)->add(*(yyvsp[-1].nodito));
        }
#line 2311 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 461 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-2].nodito);
            (yyval.nodito)->add(*(yyvsp[-1].nodito));
        }
#line 2320 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 466 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-2].nodito);
            (yyval.nodito)->add(*(yyvsp[-1].nodito));
        }
#line 2329 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 471 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2338 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 476 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2347 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 481 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2356 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 486 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2365 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 491 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2374 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 496 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2383 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 501 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2392 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 506 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2401 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 511 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2410 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 516 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2419 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 521 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2428 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 526 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2437 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 531 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2446 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 536 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2455 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 541 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2464 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 546 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2473 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 551 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[-1].nodito));
        }
#line 2482 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 556 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[-1].nodito));
        }
#line 2491 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 561 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2500 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 566 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[-1].nodito));
        }
#line 2509 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 571 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[-1].nodito));
        }
#line 2518 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 576 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2527 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 581 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2536 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 586 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2545 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 591 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2554 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 596 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2563 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 601 "parser.yy" /* yacc.c:1646  */
    {
        (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
        (yyval.nodito)->add(*(yyvsp[0].nodito));
    }
#line 2572 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 606 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LS","LS");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2581 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 615 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *id1 = new NodoAST(yylineno+1, (yylsp[-5]).first_column,"id",(yyvsp[-5].TEXT));
            NodoAST *id2 = new NodoAST(yylineno+1, (yylsp[-5]).first_column,"id",(yyvsp[-3].TEXT));
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-4]).first_column,"REASIGNACION_VAR_CLASE","REASIGNACION_VAR_CLASE");
            nodo -> add(*id1);
            nodo -> add(*id2);
            nodo -> add(*(yyvsp[-1].nodito));
            (yyval.nodito) = nodo;
        }
#line 2595 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 629 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *id = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"id",(yyvsp[-2].TEXT));
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"ACCES_VFM","ACCES_VFM");
            nodo -> add(*id);
            nodo -> add(*(yyvsp[0].nodito));
            (yyval.nodito) = nodo;
        }
#line 2607 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 638 "parser.yy" /* yacc.c:1646  */
    { /*  Clase1 c1 = Nuevo Clase1()$ */
        NodoAST *id1 = new NodoAST(yylineno+1, (yylsp[-7]).first_column,"id",(yyvsp[-7].TEXT));
        NodoAST *id2 = new NodoAST(yylineno+1, (yylsp[-7]).first_column,"id",(yyvsp[-6].TEXT));
        NodoAST *id3 = new NodoAST(yylineno+1, (yylsp[-7]).first_column,"id",(yyvsp[-3].TEXT));
        NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-6]).first_column,"INSTANCIA","INSTANCIA");
        nodo -> add(*id1);
        nodo -> add(*id2);
        nodo -> add(*id3);
        (yyval.nodito) = nodo;
    }
#line 2622 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 649 "parser.yy" /* yacc.c:1646  */
    { /*  clase1 c1$ */
        NodoAST *id1 = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"id",(yyvsp[-2].TEXT));
        NodoAST *id2 = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"id",(yyvsp[-1].TEXT));
        NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"INSTANCIA","INSTANCIA");
        nodo -> add(*id1);
        nodo -> add(*id2);
        (yyval.nodito) = nodo;
    }
#line 2635 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 662 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *id1 = new NodoAST(yylineno+1, (yylsp[-6]).first_column,"id",(yyvsp[-6].TEXT));
            NodoAST *id2 = new NodoAST(yylineno+1, (yylsp[-6]).first_column,"id",(yyvsp[-3].TEXT));
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-5]).first_column,"OBJECTO_ASIGNACION","OBJECTO_ASIGNACION");
            nodo -> add(*id1);
            nodo -> add(*id2);
            (yyval.nodito) = nodo;
        }
#line 2648 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 672 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *nodId = new NodoAST(yylineno+1, (yylsp[-6]).first_column,"id",(yyvsp[-4].TEXT));
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-5]).first_column,"METODO","METODO");
            nodo->add(*(yyvsp[-6].nodito));
            nodo->add(*(yyvsp[-5].nodito));
            nodo->add(*nodId);
            nodo->add(*(yyvsp[-3].nodito));
            nodo->add(*(yyvsp[-1].nodito));
            (yyval.nodito) = nodo;
        }
#line 2663 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 683 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *nodId = new NodoAST(yylineno+1, (yylsp[-5]).first_column,"id",(yyvsp[-4].TEXT));
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-4]).first_column,"METODO","METODO");
            nodo->add(*(yyvsp[-5].nodito));
            nodo->add(*nodId);
            nodo->add(*(yyvsp[-3].nodito));
            nodo->add(*(yyvsp[-1].nodito));
            (yyval.nodito) = nodo;
        }
#line 2677 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 693 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = (yyvsp[-1].nodito); }
#line 2683 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 694 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nodId = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"VACIO",(yyvsp[0].TEXT)); (yyval.nodito) = nodId; }
#line 2689 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 697 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"ENCAPSULAR","ENCAPSULAR");  (yyval.nodito) ->add (*(yyvsp[-1].nodito)); (yyval.nodito) -> add(*(yyvsp[0].nodito)); }
#line 2695 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 698 "parser.yy" /* yacc.c:1646  */
    {
        (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"ENCAPSULAR","ENCAPSULAR");
        (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2704 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 702 "parser.yy" /* yacc.c:1646  */
    {
        (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"ENCAPSULAR","ENCAPSULAR");
        (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2713 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 708 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"sobrescribir",(yyvsp[0].TEXT)); }
#line 2719 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 712 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-2].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2728 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 717 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LPARAMETRO","LPARAMETRO");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2737 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 724 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[0]).first_column,"PARAMETRO","PARAMETRO");
            nodo->add(*(yyvsp[-1].nodito));
            nodo->add(*(yyvsp[0].nodito));
            (yyval.nodito) = nodo;
        }
#line 2748 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 730 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = (yyvsp[0].nodito); }
#line 2754 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 736 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-3]).first_column,"IMPRIMIR","IMPRIMIR");
            nodo->add(*(yyvsp[-2].nodito));
            (yyval.nodito) = nodo;
        }
#line 2764 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 742 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = (yyvsp[0].nodito); }
#line 2770 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 744 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[0]).first_column,"else_if","else_if");
            nodo->add(*(yyvsp[-1].nodito));
            nodo->add(*(yyvsp[0].nodito));
            (yyval.nodito)->add(*nodo);
            (yyval.nodito) = nodo;
        }
#line 2782 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 755 "parser.yy" /* yacc.c:1646  */
    {

            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-6]).first_column,"REPETIR","REPETIR");
            nodo->add(*(yyvsp[-4].nodito)); nodo->add(*(yyvsp[-1].nodito));
            (yyval.nodito) = nodo;
        }
#line 2793 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 763 "parser.yy" /* yacc.c:1646  */
    {
        NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-9]).first_column,"PARA","PARA");
        nodo->add(*(yyvsp[-7].nodito));
        nodo->add(*(yyvsp[-6].nodito));
        nodo->add(*(yyvsp[-4].nodito));
        nodo->add(*(yyvsp[-1].nodito));
        (yyval.nodito) = nodo;
    }
#line 2806 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 772 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = (yyvsp[0].nodito);  }
#line 2812 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 773 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = (yyvsp[0].nodito); }
#line 2818 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 776 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = (yyvsp[0].nodito); }
#line 2824 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 777 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = (yyvsp[0].nodito); }
#line 2830 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 781 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-6]).first_column,"MIENTRAS","MIENTRAS");
            nodo->add(*(yyvsp[-4].nodito));
            nodo->add(*(yyvsp[-1].nodito));
            (yyval.nodito) = nodo;
        }
#line 2841 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 789 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-8]).first_column,"HACER_MIENTRAS","HACER_MIENTRAS");
            nodo->add(*(yyvsp[-6].nodito));
            nodo->add(*(yyvsp[-2].nodito));
            (yyval.nodito) = nodo;
        }
#line 2852 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 796 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = (yyvsp[0].nodito); }
#line 2858 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 797 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = (yyvsp[0].nodito); }
#line 2864 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 800 "parser.yy" /* yacc.c:1646  */
    {
        NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-6]).first_column,"if","if");
        nodo->add(*(yyvsp[-4].nodito)); nodo->add(*(yyvsp[-1].nodito));
        (yyval.nodito) = nodo;
    }
#line 2874 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 807 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"else","else");
            nodo->add(*(yyvsp[-1].nodito));
            (yyval.nodito) = nodo;
        }
#line 2884 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 815 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-3]).first_column,"VAR_ASIG","VAR_ASIG");
            nodo->add(*(yyvsp[-4].nodito));
            nodo->add(*(yyvsp[-3].nodito));
            nodo->add(*(yyvsp[-1].nodito));
            (yyval.nodito) = nodo;
        }
#line 2896 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 823 "parser.yy" /* yacc.c:1646  */
    {
           NodoAST *nodo1 = new NodoAST(yylineno+1, (yylsp[-3]).first_column,"id",(yyvsp[-3].TEXT));
           NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"VAR_ASIG","VAR_ASIG");
           nodo->add(*nodo1);
           nodo->add(*(yyvsp[-1].nodito));
           (yyval.nodito) = nodo;
       }
#line 2908 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 838 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-7]).first_column,"ASIGNACION_VEC","ASIGNACION_VEC");
            nodo->add(*(yyvsp[-7].nodito));
            nodo->add(*(yyvsp[-6].nodito));
            nodo->add(*(yyvsp[-5].nodito));
            nodo->add(*(yyvsp[-2].nodito));
            (yyval.nodito) = nodo;
        }
#line 2921 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 850 "parser.yy" /* yacc.c:1646  */
    {
    NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-3]).first_column,"DECLARAR_ARREGLO","DECLARAR_ARREGLO");
    nodo->add(*(yyvsp[-3].nodito));
    nodo->add(*(yyvsp[-2].nodito));
    nodo->add(*(yyvsp[-1].nodito));
    (yyval.nodito) = nodo;
}
#line 2933 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 860 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"VAR_DECLARACION","VAR_DECLARACION");
            nodo->add(*(yyvsp[-2].nodito));
            nodo->add(*(yyvsp[-1].nodito));
            (yyval.nodito) = nodo;
        }
#line 2944 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 869 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-2].nodito);
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"ID","ID");
            NodoAST *id = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"id",(yyvsp[0].TEXT));
            nodo->add(*id);
            (yyval.nodito)->add(*nodo);
        }
#line 2956 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 877 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"LISTAID","LISTAID");
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[0]).first_column,"ID","ID");
            NodoAST *id = new NodoAST(yylineno+1, (yylsp[0]).first_column,"id",(yyvsp[0].TEXT));
            nodo->add(*id);
            (yyval.nodito)->add(*nodo);
        }
#line 2968 "parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 887 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-2].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2977 "parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 892 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"EXPRESION","EXPRESION");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 2986 "parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 901 "parser.yy" /* yacc.c:1646  */
    {
    NodoAST *nodo = new NodoAST(yylineno+1, columna,"DIMENCION","DIMENCION");
    nodo->add(*(yyvsp[-1].nodito));
    (yyval.nodito) = nodo;
}
#line 2996 "parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 908 "parser.yy" /* yacc.c:1646  */
    {
    NodoAST *nodo = new NodoAST(yylineno+1, columna,"DIMENCION","DIMENCION");
    nodo->add(*(yyvsp[-4].nodito));
    nodo->add(*(yyvsp[-1].nodito));
    (yyval.nodito) = nodo;
}
#line 3007 "parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 916 "parser.yy" /* yacc.c:1646  */
    {
    NodoAST *nodo = new NodoAST(yylineno+1, columna,"DIMENCION","DIMENCION");
    nodo->add(*(yyvsp[-7].nodito));
    nodo->add(*(yyvsp[-4].nodito));
    nodo->add(*(yyvsp[-1].nodito));
    (yyval.nodito) = nodo;
}
#line 3019 "parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 928 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, columna,"UNIDIMENCION","UNIDIMENCION");
            (yyval.nodito) -> add(*(yyvsp[0].nodito));
        }
#line 3028 "parser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 936 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-2].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 3037 "parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 941 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"BIDIMENCION","BIDIMENCION");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 3046 "parser.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 947 "parser.yy" /* yacc.c:1646  */
    {(yyval.nodito) = (yyvsp[-1].nodito); }
#line 3052 "parser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 950 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-2].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 3061 "parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 955 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"TRIDIMENCION","TRIDIMENCION");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
        }
#line 3070 "parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 960 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = (yyvsp[-1].nodito); }
#line 3076 "parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 965 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *nodo1 = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"id",(yyvsp[-1].TEXT));
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"ACCESO_VEC","ACCESO_VEC");
            nodo->add(*nodo1);
            nodo->add(*(yyvsp[0].nodito));
            (yyval.nodito) = nodo;
        }
#line 3088 "parser.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 974 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[-3]).first_column,"REASIGNACION_VEC","REASIGNACION_VEC");
            nodo->add(*(yyvsp[-3].nodito));
            nodo->add(*(yyvsp[-1].nodito));
            (yyval.nodito) = nodo;
        }
#line 3099 "parser.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 981 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, columna,"ROMPER",(yyvsp[-1].TEXT)); }
#line 3105 "parser.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 983 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, columna,"SALIR",(yyvsp[-1].TEXT)); }
#line 3111 "parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 985 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, columna,"CONTINUAR",(yyvsp[-1].TEXT)); }
#line 3117 "parser.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 987 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nodo = new NodoAST(yylineno+1, columna,"RETORNAR","RETORNAR"); nodo->add(*(yyvsp[-1].nodito)); (yyval.nodito) = nodo; }
#line 3123 "parser.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 990 "parser.yy" /* yacc.c:1646  */
    {
        NodoAST *nodo = new NodoAST(yylineno+1, columna,"NOTIFICACION","NOTIFICACION");
        nodo->add(*(yyvsp[-4].nodito));
        nodo->add(*(yyvsp[-2].nodito));
        (yyval.nodito) = nodo;
    }
#line 3134 "parser.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 999 "parser.yy" /* yacc.c:1646  */
    {
        NodoAST *nodo1 = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"id",(yyvsp[-1].TEXT));
        NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[0]).first_column,"AUMENTO","AUMENTO");
        nodo->add(*nodo1);
        (yyval.nodito) = nodo;
    }
#line 3145 "parser.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1008 "parser.yy" /* yacc.c:1646  */
    {
        NodoAST *nodo1 = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"id",(yyvsp[-1].TEXT));
        NodoAST *nodo = new NodoAST(yylineno+1, (yylsp[0]).first_column,"DECREMENTO","DECREMENTO");
        nodo->add(*nodo1);
        (yyval.nodito) = nodo;
    }
#line 3156 "parser.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1017 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *id = new NodoAST(yylineno+1, (yylsp[-3]).first_column,"id",(yyvsp[-3].TEXT));
            NodoAST *call = new NodoAST(yylineno+1, (yylsp[-3]).first_column,"LLAMADA","LLAMADA");
            call->add(*id);
            call->add(*(yyvsp[-1].nodito));
            (yyval.nodito) = call;

        }
#line 3169 "parser.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1026 "parser.yy" /* yacc.c:1646  */
    {
            NodoAST *id = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"id",(yyvsp[-2].TEXT));
            NodoAST *call = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"LLAMADA","LLAMADA");
            call->add(*id);
            (yyval.nodito) = call;

        }
#line 3181 "parser.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1036 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, columna,"int",(yyvsp[0].TEXT)); }
#line 3187 "parser.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1037 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"string",(yyvsp[0].TEXT));}
#line 3193 "parser.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1038 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"bool",(yyvsp[0].TEXT));}
#line 3199 "parser.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1039 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"bool",(yyvsp[0].TEXT));}
#line 3205 "parser.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1040 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"char",(yyvsp[0].TEXT));}
#line 3211 "parser.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1041 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"double",(yyvsp[0].TEXT));}
#line 3217 "parser.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1042 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"void",(yyvsp[0].TEXT));}
#line 3223 "parser.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1043 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"arreglo",(yyvsp[0].TEXT));}
#line 3229 "parser.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1046 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, columna,"visibilidad",(yyvsp[0].TEXT)); }
#line 3235 "parser.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1047 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"visibilidad",(yyvsp[0].TEXT));}
#line 3241 "parser.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1048 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"visibilidad",(yyvsp[0].TEXT));}
#line 3247 "parser.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1052 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"not",(yyvsp[-1].TEXT));  nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3253 "parser.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1053 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"and",(yyvsp[-1].TEXT));  nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3259 "parser.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1054 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"nand",(yyvsp[-1].TEXT));  nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3265 "parser.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1055 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"or",(yyvsp[-1].TEXT));  nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3271 "parser.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1056 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"xor",(yyvsp[-1].TEXT));  nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3277 "parser.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1057 "parser.yy" /* yacc.c:1646  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 3283 "parser.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1061 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"eqeq",(yyvsp[-1].TEXT));  nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3289 "parser.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1062 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"difQ",(yyvsp[-1].TEXT));  nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3295 "parser.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1063 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"menorQ",(yyvsp[-1].TEXT));  nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3301 "parser.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1064 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"mayorQ",(yyvsp[-1].TEXT));  nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3307 "parser.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1065 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"menorIgualQ",(yyvsp[-1].TEXT));  nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3313 "parser.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1066 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"mayorIgualQ",(yyvsp[-1].TEXT));  nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3319 "parser.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1067 "parser.yy" /* yacc.c:1646  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 3325 "parser.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1070 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"suma",(yyvsp[-1].TEXT));  nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3331 "parser.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1071 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"resta",(yyvsp[-1].TEXT)); nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3337 "parser.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1072 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"multi",(yyvsp[-1].TEXT)); nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3343 "parser.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1073 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"div",(yyvsp[-1].TEXT)); nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3349 "parser.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1074 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"potencia",(yyvsp[-1].TEXT)); nod->add(*(yyvsp[-2].nodito));  nod->add(*(yyvsp[0].nodito));  (yyval.nodito)=nod ;  }
#line 3355 "parser.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1075 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"resta",(yyvsp[-1].TEXT)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod; }
#line 3361 "parser.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1076 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"int",(yyvsp[0].TEXT));}
#line 3367 "parser.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1077 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"char",(yyvsp[0].TEXT));}
#line 3373 "parser.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1078 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"double",(yyvsp[0].TEXT));}
#line 3379 "parser.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1079 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"bool",(yyvsp[0].TEXT));}
#line 3385 "parser.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1080 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"string",(yyvsp[0].TEXT));}
#line 3391 "parser.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1081 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST(yylineno+1, (yylsp[0]).first_column,"id",(yyvsp[0].TEXT));}
#line 3397 "parser.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1082 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = (yyvsp[-1].nodito); }
#line 3403 "parser.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1085 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = (yyvsp[0].nodito); }
#line 3409 "parser.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1086 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = (yyvsp[0].nodito); }
#line 3415 "parser.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1088 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"ACCESO_OBJECT","ACCESO_OBJECT");
                NodoAST *id1 = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"id1",(yyvsp[-2].TEXT));
                NodoAST *id2 = new NodoAST(yylineno+1, (yylsp[-2]).first_column,"id2",(yyvsp[0].TEXT));
                nod -> add(*id1);
                nod -> add(*id2);
                (yyval.nodito) = nod;
            }
#line 3428 "parser.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1097 "parser.yy" /* yacc.c:1646  */
    {
             NodoAST *id1 = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"id1",(yyvsp[-1].TEXT));
             NodoAST *id2 = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"id2",(yyvsp[0].TEXT));
             NodoAST *nod = new NodoAST(yylineno+1, (yylsp[-1]).first_column,"ACCESO_OBJECT","ACCESO_OBJECT");
             nod -> add(*id1);
             nod -> add(*id2);
             (yyval.nodito) = nod;
            }
#line 3441 "parser.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1105 "parser.yy" /* yacc.c:1646  */
    { NodoAST *nod = new NodoAST(yylineno+1, (yylsp[0]).first_column,"DATOS_VEC","DATOS_VEC"); nod -> add(*(yyvsp[0].nodito)); (yyval.nodito) = nod; }
#line 3447 "parser.cpp" /* yacc.c:1646  */
    break;


#line 3451 "parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1108 "parser.yy" /* yacc.c:1906  */

