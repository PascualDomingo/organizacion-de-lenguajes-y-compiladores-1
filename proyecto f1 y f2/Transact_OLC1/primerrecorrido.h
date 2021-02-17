#ifndef PRIMERRECORRIDO_H
#define PRIMERRECORRIDO_H
#include <qstring.h>
#include <resultado.h>
#include <NodoAST.h>
#include <string>
#include <QLinkedList>

struct errorSin{
    QString fila;
    QString columna;
    QString desc;
    QString valor;
};

struct Esemantico
{
    int linea;
    int columna;
    QString tipo;
    QString detalle;

};

struct tabla_Var_local
{
    int linea;
    int columna;
    QString visibilidad;
    QString rol;
    QString tipo;
    QString id;
    QString valor;
    QList <tri> arreglo;
    NodoAST raiz;
};

struct tabla_met_fun
{
    int linea;
    int columna;
    QString sobrescribir;
    QString visibilidad;
    QString tipo;
    QString id;
    QList<tabla_Var_local> misParametros;
    NodoAST raiz;
};

struct lista_notificacion{
    QString titulo;
    QString mensaje;
};

struct tabla_clase
{
    int linea;
    int columna;
    QString tipo;
    QString idClase;
    NodoAST NodoClase;
};

class primerRecorrido
{
public:
    primerRecorrido();
    QString resultado;
    QList <Esemantico>esemantico;
    QList <tabla_Var_local> Tabla_simbolo;
    QList <tabla_Var_local> Vlocal;
    QList <tabla_Var_local> Vglobal;
    QList <tabla_Var_local> misParametro;
    QList <tabla_met_fun> misFunciones;
    QList <tabla_clase> misClases;
    QList <tabla_clase> objetos;
    QList <lista_notificacion> notificacion;

    Resultado primer_recorrdio( NodoAST *raiz);
    Resultado segundo_recorrdio( NodoAST *raiz);
    Resultado tercer_recorrdio( NodoAST *raiz);
    void metodo_principla ();
    void limpiar_listas ();
    void bool_to_false();

private:
    Resultado op_artimetica( NodoAST *raiz);
    Resultado op_logicaYrelacional( NodoAST *raiz);
    Resultado buscar_id (NodoAST *raiz);
    Resultado buscar_metod_function (QString, QList<tabla_Var_local>);

    int char_to_int(QString);
    int boolenao_to_int(QString);
    QString metodo_or(QString, QString);
    QString metodo_And(QString, QString);
    void insertarErrSem(int, int, QString, QString);
    void insert_entorno(int, int, QString, QString, QString, QString);
    void insert_entorno_global(int, int, QString, QString, QString, QString);
    void insert_aument_decremet(QString, QString);
    void entorno(QString);
    void entorno_global(QString);
    void recorrerlista();
    void insertarLSVec();
    void insertarErrSintac();
    void insertarModPos();
    QString obtenerValVec();
    void insertarVariable();
    bool diferente_cero(QString);
    Resultado existe_clase(QString, int);
    Resultado existe_objeto(QString, int);
    Resultado reasignar_valores_clase_global(QString, QString, Resultado);



};

#endif // PRIMERRECORRIDO_H
