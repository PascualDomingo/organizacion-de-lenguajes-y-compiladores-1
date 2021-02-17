#ifndef RESULTADO_H
#define RESULTADO_H
#include <qstring.h>
#include <qlist.h>
#include <NodoAST.h>

struct uni
{
    QList <QString> unidimencion;
};

struct bi
{
    QList <uni> bidimencion;
};

struct tri
{
    QList <bi> tridimencion;
};


class Resultado
{
public:
    Resultado();
    Resultado(int l, int c, int t, QString v, bool f, QList<QString> li, QString tv, QString r, QString cn, QString ret, QList<tri> arr, NodoAST nod );
    int tipo;
    QString valor;
    int linea;
    int columna;
    bool flag;
    QList<QString> LId;
    QString tipo_var;
    QString romper;
    QString continuar;
    QString retornar;
    QList<tri> arreglo;
    NodoAST nodo;
};

#endif // RESULTADO_H
