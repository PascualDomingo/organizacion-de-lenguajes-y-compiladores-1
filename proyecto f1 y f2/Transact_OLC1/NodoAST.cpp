#include "NodoAST.h"
#include <qdebug.h> // Para imprimir en consola.
NodoAST::NodoAST()
{
    tipo ="";
    valor = "";
    linea = 0;
    columna = 0;
    hijos =  QList<NodoAST>();
}

NodoAST:: NodoAST(int l, int c, QString t, QString v)
{
    linea = l;
    columna = c;
    tipo = t;
    valor = v;
    tipo_ = getTipo();
    hijos = QList<NodoAST>();
}

void NodoAST::add(NodoAST nd)
{
    this->hijos.append(nd);
}

int NodoAST::getTipo()
{
    if(this->tipo=="int")           {return 1;}
    if(this->tipo=="string")        {return 2;}
    if(this->tipo=="bool")          {return 3;}
    if(this->tipo=="char")          {return 4;}
    if(this->tipo=="double")        {return 5;}
    if(this->tipo=="suma")          {return 6;}
    if(this->tipo=="resta")         {return 7;}
    if(this->tipo=="multi")         {return 8;}
    if(this->tipo=="div")           {return 9;}
    if(this->tipo=="potencia")      {return 10;}
    if(this->tipo=="mayorIgualQ")   {return 11;}
    if(this->tipo=="menorIgualQ")   {return 12;}
    if(this->tipo=="mayorQ")        {return 13;}
    if(this->tipo=="menorQ")        {return 14;}
    if(this->tipo=="difQ")          {return 15;}
    if(this->tipo=="eqeq")          {return 16;}
    if(this->tipo=="or")            {return 17;}
    if(this->tipo=="and")           {return 18;}
    if(this->tipo=="not")           {return 19;}
    if(this->tipo=="LISTAID")       {return 20;}
    if(this->tipo=="ID")            {return 21;}
    if(this->tipo=="VAR_ASIG")      {return 22;}
    if(this->tipo=="else")          {return 23;}
    if(this->tipo=="if")            {return 24;}
    if(this->tipo=="else_if")       {return 25;}
    if(this->tipo=="LS")            {return 26;}
    if(this->tipo=="sen_if")        {return 27;}
    if(this->tipo=="MAIN")          {return 28;}
    if(this->tipo=="LCUERPO")       {return 29;}
    if(this->tipo=="CLASE")         {return 30;}
    if(this->tipo=="LCLASE")        {return 31;}
    if(this->tipo=="IMPRIMIR")      {return 32;}
    if(this->tipo=="nand")          {return 33;}
    if(this->tipo=="xor")           {return 34;}
    if(this->tipo=="id")            {return 35;}
    if(this->tipo=="VAR_DECLARACION"){return 36;}
    if(this->tipo=="REPETIR")       {return 37;}
    if(this->tipo=="MIENTRAS")      {return 38;}
    if(this->tipo=="ROMPER")        {return 39;}
    if(this->tipo=="AUMENTO")       {return 40;}
    if(this->tipo=="DECREMENTO")    {return 41;}
    if(this->tipo=="CONTINUAR")     {return 42;}
    if(this->tipo=="SALIR")         {return 43;}
    if(this->tipo=="PARA")          {return 44;}
    if(this->tipo=="METODO")        {return 45;}
    if(this->tipo=="LPARAMETRO")    {return 46;}
    if(this->tipo=="PARAMETRO")     {return 47;}
    if(this->tipo=="ENCAPSULAR")    {return 48;}
    if(this->tipo=="LLAMADA")       {return 49;}
    if(this->tipo=="HACER_MIENTRAS"){return 50;}
    if(this->tipo=="RETORNAR")      {return 51;}
    if(this->tipo=="NOTIFICACION")  {return 52;}
    if(this->tipo=="ASIGNACION_VEC")  {return 53;}
    if(this->tipo=="DIMENCION")     {return 54;}
    if(this->tipo=="UNIDIMENCION")  {return 55;}
    if(this->tipo=="EXPRESION")     {return 56;}
    if(this->tipo=="BIDIMENCION")   {return 57;}
    if(this->tipo=="TRIDIMENCION")  {return 58;}
    if(this->tipo=="ACCESO_VEC")    {return 59;}
    if(this->tipo=="REASIGNACION_VEC") {return 60;}
    if(this->tipo=="INSTANCIA")     {return 61;}
    if(this->tipo=="OBJECTO_ASIGNACION")        {return 62;}
    if(this->tipo=="ACCES_VFM")     {return 63;}
    if(this->tipo=="REASIGNACION_VAR_CLASE")    {return 64;}
    if(this->tipo=="ACCESO_OBJECT") {return 65;}
    if(this->tipo=="DATOS_VEC")     {return 66;}
    if(this->tipo=="DECLARAR_ARREGLO")     {return 67;}


    return 0;
}
