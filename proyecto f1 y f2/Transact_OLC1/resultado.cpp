#include "resultado.h"

Resultado::Resultado()
{
    linea = 0;
    columna = 0;
    tipo = 0;
    valor = "";
    flag = false;
    LId;
    tipo_var = "";
    romper = "";
    continuar = "";
    retornar = "";
    arreglo;
    nodo;

}

Resultado::Resultado(int l, int c, int t, QString v, bool f, QList<QString> li, QString tp, QString r, QString cn, QString ret, QList<tri> arr, NodoAST nod)
{
    linea = l;
    columna = c;
    tipo = t;
    valor = v;
    flag = f;
    LId = li;
    tipo_var = tp;
    romper = r;
    continuar = cn;
    retornar = ret;
    arreglo = arr;
    nodo = nod;
}
