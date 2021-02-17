#include "primerrecorrido.h"
#include <string>
#include <QString>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

//ErrorSeamntico *errSem = new ErrorSeamntico();
//ListVector *lsvec = new ListVector();
//ListVar *lsVar = new ListVar();
//tolower lo pasa a minuscula

QString tipoV = "";
QString iden = "";
QString asignacionMod = "";
int cont_aument = 0;
int cont_decrement = 0;
bool flag_retornar = false;
bool imprimir = false;
QString tipo_funcion = "";
Resultado miRetorno = Resultado();
QString id_objeto = "";

QList <QString> ids;
QList <QString> tam;
QList <QString> val;
QList <QString> dim_vec;

enum Choice
{
    INT =1 ,
    STRING = 2,
    BOOL = 3,
    CHAR = 4,
    DOUBLE = 5,
    SUMA = 6,
    RESTA = 7,
    MULTI = 8,
    DIV = 9,
    POTENCIA = 10,
    MAYORIGUALQ = 11,
    MENORIGUALQ = 12,
    MAYORQ = 13,
    MENORQ = 14,
    DIFQ = 15,
    EQEQ = 16,
    OR = 17,
    AND = 18,
    NOT = 19,
    LISTAID = 20,
    ID = 21,
    VAR_ASIG = 22,
    ELSE = 23,
    IF = 24,
    ELSE_IF = 25,
    LS = 26,
    SEN_IF = 27,
    MAIN = 28,
    LCUERPO = 29,
    CLASE = 30,
    LCLASE = 31,
    IMPRIMIR = 32,
    NAND = 33,
    XOR = 34,
    IDENTIFICADOR = 35,
    VAR_DECLARACION = 36,
    REPETIR = 37,
    MIENTRAS = 38,
    ROMPER = 39,
    AUMENTO = 40,
    DECREMENTO = 41,
    CONTINUAR = 42,
    SALIR = 43,
    PARA = 44,
    METODO = 45,
    LPARAMETRO = 46,
    PARAMETRO = 47,
    ENCAPSULAR = 48,
    LLAMADA = 49,
    HACER_MIENTRAS = 50,
    RETORNAR = 51,
    NOTIFICACION = 52,
    ASIGNACION_VEC = 53,
    DIMENCION = 54,
    UNIDIMENCION = 55,
    EXPRESION = 56,
    BIDIMENCION = 57,
    TRIDIMENCION = 58,
    ACCESO_VEC = 59,
    REASIGNACION_VEC = 60,
    INSTANCIA = 61,
    OBJECTO_ASIGNACION = 62,
    ACCES_VFM = 63,
    REASIGNACION_VAR_CLASE = 64,
    ACCESO_OBJECT = 65,
    DATOS_VEC = 66,
    DECLARAR_ARREGLO = 67
};


primerRecorrido::primerRecorrido()
{
    resultado = "";
    //esemantico = mi_e_semantco;
}

void primerRecorrido::insertarErrSem(int linea, int columna, QString tipo, QString detalle){
    //int tamES = Esemantico.length();
    struct Esemantico new_e_sem;
    new_e_sem.linea = linea;
    new_e_sem.columna = columna;
    new_e_sem.tipo = tipo;
    new_e_sem.detalle = detalle;
    esemantico.append(new_e_sem);

}

int primerRecorrido::char_to_int(QString caracter){
    //convertir a char
    QString cadena = caracter;
    std::string cad = cadena.toStdString();
    char c = cad[0];
    printf("\n");
    int num = c;

    return num;
}

int primerRecorrido::boolenao_to_int(QString booleano){
    int num = 0;
    QString cadena = booleano;
    std::string cad = cadena.toStdString();
    if(cad == "verdadero" || cad == "true"){
        num = 1;
    }
    return num;
}

QString primerRecorrido::metodo_or(QString opl, QString opl1){
    QString respuesta = "true";
    std::string cad = opl.toStdString();
    std::string cad1 = opl1.toStdString();
    if(cad == "false" && cad1 == "false"){
        respuesta = "false";
    }
    if(cad == "falso" && cad1 == "falso"){
        respuesta = "falso";
    }else{
        if(cad == "verdadero" || cad1 == "verdadero"){
            respuesta = "verdadero";
        }
    }
    return respuesta;
}

QString primerRecorrido::metodo_And(QString opl, QString opl1){
    QString respuesta = "false";
    std::string cad = opl.toStdString();
    std::string cad1 = opl1.toStdString();
    if(cad == "true" && cad1 == "true"){
        respuesta = "true";
    }
    if(cad == "verdadero" && cad1 == "verdadero"){
        respuesta = "verdadero";
    }else{
        if(cad == "falso" || cad1 == "falso"){
            respuesta = "falso";
        }
    }
    return respuesta;
}

bool primerRecorrido::diferente_cero(QString num){
    double numero = num.toDouble();
    bool responder =  true;
    if(numero == 0){
        insertarErrSem(1, 1, "Error semantico", "imposible dividir entre Cero");
        responder = false;
    }
    return responder;
}

/*se recogeran los ID*/
Resultado primerRecorrido :: primer_recorrdio( NodoAST *raiz){
    Resultado r = Resultado();
    switch (raiz->tipo_) {
    case LCLASE:
    {
        for(int x = 0; x < raiz->hijos.size(); x++){
            NodoAST lclase = raiz->hijos.at(x);
            Resultado mislclase = primer_recorrdio(&lclase);
        }
        //bool_to_false();
    }
        break;
    case CLASE:
    {
        NodoAST nodoClase = raiz->hijos.at(1);
        struct tabla_clase tmp;
        tmp.linea = raiz->hijos.at(0).linea;
        tmp.columna = raiz->hijos.at(0).columna;
        tmp.idClase = raiz->hijos.at(0).valor;
        tmp.NodoClase = nodoClase;
        misClases.append(tmp);
    }
        break;
    }

    return r;
}

/*recoge funciones, metodos y toda clase de variables globales, los inserta en la tabla de simbolos*/
Resultado primerRecorrido:: segundo_recorrdio(NodoAST *raiz){
    Resultado r = Resultado();
    switch(raiz->tipo_){
        case LCLASE:
            {
            NodoAST lclase = raiz->hijos.at(0);
            Resultado mislclase = segundo_recorrdio(&lclase);
            }
            break;
        case CLASE:
            {
            NodoAST clase = raiz->hijos.at(1);
            Resultado miclase = segundo_recorrdio(&clase);
            }
            break;
        case LCUERPO:
            {   /*como tiene muchos hijos entonces se ejecuta un for*/
            for(int i = 0; i < raiz->hijos.size(); i++){
                NodoAST lcuerpo = raiz->hijos.at(i);
                Resultado milcuerpo = segundo_recorrdio(&lcuerpo);
            }
            }
            break;
        case VAR_DECLARACION:
            {
                /*se guarda las variables dentro de la Lista variable*/
                struct tabla_Var_local tmp;
                tmp.linea = raiz->hijos.at(0).linea;
                tmp.columna = raiz->hijos.at(0).columna;

                if(raiz->hijos.size() == 3){
                    tmp.visibilidad = raiz->hijos.at(2).hijos.at(0).valor.toLower();
                }else{
                    tmp.visibilidad = "publico";
                }

                NodoAST lsId = raiz->hijos.at(1);
                Resultado LSID = segundo_recorrdio(&lsId);
                for(int x = 0; x < LSID.LId.size(); x++){
                      tmp.rol = "variable";
                      tmp.tipo = raiz->hijos.at(0).valor.toLower();
                      tmp.id = LSID.LId.at(x);
                      tmp.valor = "";
                      Vglobal.append(tmp);

                      /*guardar objetos en la tabla de simbolos*/
                      Tabla_simbolo.append(tmp);
                  }

            }
            break;
        case VAR_ASIG:
            {
                /*se guarda las variables dentro de la Lista variable*/
                struct tabla_Var_local tmp;
                int linea = raiz->hijos.at(0).linea;
                int columna = raiz->hijos.at(0).columna;

                bool hijo34 = false;
                int hijoID = 0;

                if(raiz->hijos.size() == 4){
                    hijo34 = true;
                    tmp.visibilidad = raiz->hijos.at(3).hijos.at(0).valor.toLower();
                }else
                if(raiz->hijos.size() == 3){
                    hijo34 = true;
                    tmp.visibilidad = "publico";
                }

                if(hijo34){
                    NodoAST lsId = raiz->hijos.at(1);
                    Resultado LSID = segundo_recorrdio(&lsId);

                    NodoAST operacion = raiz->hijos.at(2);
                    Resultado misOperaciones = op_logicaYrelacional(&operacion);
                    QString miBool = "";

                    bool flag_tipo_var = true;

                    if(raiz->hijos.at(0).valor.toLower() == misOperaciones.tipo_var){
                        flag_tipo_var = false;
                        for(int x = 0; x < LSID.LId.size(); x++){
                          //std::cout<<LSID.LId.at(x).toStdString()<<endl;
                              tmp.linea = linea;
                              tmp.columna = columna;
                              tmp.rol = "variable";
                              tmp.tipo = raiz->hijos.at(0).valor.toLower();
                              tmp.id = LSID.LId.at(x);
                              /* para convertir el valor de un booleano a false o true */
                              if(misOperaciones.tipo_var == "booleano"){
                                  if(misOperaciones.flag){
                                      tmp.valor = "true";
                                  }else{
                                      tmp.valor = "false";
                                  }
                              }else{
                                  tmp.valor = misOperaciones.valor;
                              }
                              Vglobal.append(tmp);

                              /*guardar objetos en la tabla de simbolos*/
                              Tabla_simbolo.append(tmp);
                          }
                    }

                    if(flag_tipo_var){
                        insertarErrSem(linea, columna, "error semantico", "la variable < "+LSID.LId[0]+" > no es de tipo "+misOperaciones.tipo_var);
                    }
                }

                /*asignar valor a las variables ya declaradas*/
                if(raiz->hijos.size() == 2){
                    QString idVar = raiz->hijos.at(0).valor;
                    int idline = raiz->hijos.at(0).linea;
                    int idcol = raiz->hijos.at(0).columna;

                    NodoAST operacion = raiz->hijos.at(1);
                    Resultado misOperaciones = op_logicaYrelacional(&operacion);
                    bool flag_id = true;
                    bool flag_tipo = true;
                    /*buscar variable declarada*/
                    for(int x = Vglobal.length()-1; x >=0 ; x--){
                        if(idVar == Vglobal[x].id ){
                            flag_id = false;
                            if(misOperaciones.tipo_var == Vglobal[x].tipo ){
                                flag_tipo = false;
                                /* para convertir el valor de un booleano a false o true */
                                if(misOperaciones.tipo_var == "booleano"){
                                    if(misOperaciones.flag){
                                        Vglobal[x].valor = "true";
                                    }else{
                                        Vglobal[x].valor = "false";
                                    }
                                }else{
                                    Vglobal[x].valor = misOperaciones.valor;
                                }
                                break;
                            }
                            flag_tipo = false;
                            break;
                        }
                    }

                    if(flag_id){
                        insertarErrSem(idline, idcol, "error semantico", "la variable < "+idVar+" > no se ha declarado");
                    }
                    if(flag_tipo){
                        insertarErrSem(idline, idcol, "error semantico", "la variable < "+idVar+" > no es de tipo "+misOperaciones.tipo_var);
                    }
                    /*buscar variable declarada en la tabla de simbolo*/
                    for(int x = Tabla_simbolo.length()-1; x >=0 ; x--){
                        if(idVar == Tabla_simbolo[x].id ){
                            if(misOperaciones.tipo_var == Tabla_simbolo[x].tipo ){
                                /* para convertir el valor de un booleano a false o true */
                                if(misOperaciones.tipo_var == "booleano"){
                                    if(misOperaciones.flag){
                                        Tabla_simbolo[x].valor = "true";
                                    }else{
                                        Tabla_simbolo[x].valor = "false";
                                    }
                                }else{
                                    Tabla_simbolo[x].valor = misOperaciones.valor;
                                }
                                break;
                            }
                            break;
                        }
                    }
                }

            }
            break;
        case ASIGNACION_VEC:
        {
            /*se guarda las variables dentro de la Lista variable*/
            struct tabla_Var_local tmp;
            int linea = raiz->hijos.at(0).linea;
            int columna = raiz->hijos.at(0).columna;

            bool hijo34 = false;
            int hijoID = 0;

            if(raiz->hijos.size() == 5){
                hijo34 = true;
                tmp.visibilidad = raiz->hijos.at(4).hijos.at(0).valor.toLower();
            }else
            if(raiz->hijos.size() == 4){
                hijo34 = true;
                tmp.visibilidad = "publico";
            }

            if(hijo34){
                NodoAST lsId = raiz->hijos.at(1);
                Resultado LSID = segundo_recorrdio(&lsId);

                NodoAST nodoDim = raiz->hijos.at(2);
                segundo_recorrdio(&nodoDim);

                NodoAST nodoVec = raiz->hijos.at(3);
                Resultado res_vec = segundo_recorrdio(&nodoVec);
                dim_vec.clear(); /*limpia lista de dimenciones del arreglo*/

                    for(int x = 0; x < LSID.LId.size(); x++){
                          tmp.linea = linea;
                          tmp.columna = columna;
                          tmp.rol = "arreglo";
                          tmp.tipo = raiz->hijos.at(0).valor.toLower();
                          tmp.id = LSID.LId.at(x);
                          tmp.arreglo = res_vec.arreglo;
                          Vglobal.append(tmp);
                          /*guardar objetos en la tabla de simbolos*/
                          Tabla_simbolo.append(tmp);
                      }
            }

            /*asignar valor a las variables ya declaradas*/
            if(raiz->hijos.size() == 2){
                QString idVar = raiz->hijos.at(0).valor;
                int idline = raiz->hijos.at(0).linea;
                int idcol = raiz->hijos.at(0).columna;

                NodoAST operacion = raiz->hijos.at(1);
                Resultado misOperaciones = op_logicaYrelacional(&operacion);
                bool flag_id = true;
                bool flag_tipo = true;
                /*buscar variable declarada*/
                for(int x = Vglobal.length()-1; x >=0 ; x--){
                    if(idVar == Vglobal[x].id ){
                        flag_id = false;
                        if(misOperaciones.tipo_var == Vglobal[x].tipo ){
                            flag_tipo = false;
                            /* para convertir el valor de un booleano a false o true */
                            if(misOperaciones.tipo_var == "booleano"){
                                if(misOperaciones.flag){
                                    Vglobal[x].valor = "true";
                                }else{
                                    Vglobal[x].valor = "false";
                                }
                            }else{
                                Vglobal[x].valor = misOperaciones.valor;
                            }
                            break;
                        }
                        flag_tipo = false;
                        break;
                    }
                }

                if(flag_id){
                    insertarErrSem(idline, idcol, "error semantico", "la variable < "+idVar+" > no se ha declarado");
                }
                if(flag_tipo){
                    insertarErrSem(idline, idcol, "error semantico", "la variable < "+idVar+" > no es de tipo "+misOperaciones.tipo_var);
                }
                /*buscar variable declarada en la tabla de simbolo*/
                for(int x = Tabla_simbolo.length()-1; x >=0 ; x--){
                    if(idVar == Tabla_simbolo[x].id ){
                        if(misOperaciones.tipo_var == Tabla_simbolo[x].tipo ){
                            /* para convertir el valor de un booleano a false o true */
                            if(misOperaciones.tipo_var == "booleano"){
                                if(misOperaciones.flag){
                                    Tabla_simbolo[x].valor = "true";
                                }else{
                                    Tabla_simbolo[x].valor = "false";
                                }
                            }else{
                                Tabla_simbolo[x].valor = misOperaciones.valor;
                            }
                            break;
                        }
                        break;
                    }
                }
            }

        }
        break;
        case LISTAID:
            {
                QList<QString> lsid;
                for(int i = 0; i< raiz->hijos.size(); i++){
                    NodoAST lID = raiz->hijos.at(i);
                    Resultado miID = segundo_recorrdio(&lID);
                    lsid.append(miID.valor);
                }
                r.LId = lsid;
                return r;
            }
            break;
        case DIMENCION:
        {
            for(int i = 0; i< raiz->hijos.size(); i++){
                NodoAST ldim = raiz->hijos.at(i);
                Resultado miDim = op_artimetica(&ldim);
                if(miDim.tipo_var == "entero"){
                    dim_vec.append(miDim.valor);
                }else{
                    insertarErrSem(miDim.linea, miDim.columna, "error semantico", "las dimenciones del < arreglo > deben ser de tipo ENTERO ");
                }

            }
        }
        break;
        case ID:
            {
                r.valor = raiz->hijos.at(0).valor;
            }
            break;
        case MAIN:
            {
                int linea = raiz->hijos.at(0).linea;
                int colunna = raiz->hijos.at(0).columna;
                QString id = raiz->hijos.at(0).valor;
                NodoAST principal = raiz->hijos.at(1);
                /*guardar atributos del metodo principal*/
                struct tabla_met_fun tmp;
                tmp.linea = linea;
                tmp.columna = colunna;
                tmp.id = id.toLower();
                tmp.raiz = principal;
                misFunciones.append(tmp);

                /*guardar id principal en la tabla de simbolo*/
                struct tabla_Var_local aux;
                aux.linea = linea;
                aux.columna = colunna;
                aux.rol = "principal";
                aux.id = id.toLower();
                Tabla_simbolo.append(aux);
                Vlocal.append(aux);

            }
            break;
        case METODO:
            {

            struct tabla_met_fun tmp;
            int can_hios = 0;
            if(raiz->hijos.size()== 5 ){
                can_hios = 1;
                NodoAST enc = raiz->hijos.at(0);
                Resultado res = segundo_recorrdio(&enc);
                tmp.linea =  res.linea;
                tmp.columna = res.columna;
                tmp.sobrescribir = res.tipo_var;
                tmp.visibilidad = res.valor;
            }else{
                can_hios = 0;
                tmp.linea = raiz->hijos.at(0).linea;
                tmp.columna = raiz->hijos.at(0).columna;
                tmp.visibilidad = "publico";
            }
                QString tipo_fun = raiz->hijos.at(can_hios).valor;
                tmp.tipo = tipo_fun;
                QString id = raiz->hijos.at(can_hios+1).valor;
                tmp.id = id;

                NodoAST p = raiz->hijos.at(can_hios+2);
                Resultado pa = segundo_recorrdio(&p);
                tmp.misParametros = misParametro;

                NodoAST nodo = raiz->hijos.at(can_hios+3);
                tmp.raiz = nodo;

                misFunciones.append(tmp);
                misParametro.clear();

        }
            break;
        case LPARAMETRO:
        {
            for(int x = 0; x < raiz->hijos.size(); x++){
                NodoAST lps = raiz->hijos.at(x);
                Resultado res = tercer_recorrdio(&lps);
                struct tabla_Var_local tmp;
                tmp.linea = res.linea;
                tmp.columna = res.columna;
                tmp.tipo = res.tipo_var;
                tmp.id = res.valor;
                misParametro.append(tmp);
            }
        }
            break;
        case ENCAPSULAR:
            {
                if(raiz->hijos.size() == 2){
                    r.tipo_var = raiz->hijos.at(0).valor.toLower();
                    r.valor = raiz->hijos.at(1).valor.toLower();
                }else if(raiz->hijos.at(0).valor.toLower() == "sobrescribir" ){
                    r.tipo_var = raiz->hijos.at(0).valor.toLower();
                    r.valor = "publico";
                }else if(raiz->hijos.at(0).valor.toLower() == "publico" ){
                    r.tipo_var = "";
                    r.valor = raiz->hijos.at(0).valor.toLower();
                }

            }
            break;
        case UNIDIMENCION:
        {
            NodoAST nod = raiz->hijos.at(0);
            r = segundo_recorrdio(&nod);
            dim_vec.clear(); /*limpia lista de dimenciones del arreglo*/
        }
            break;
        case BIDIMENCION:
        {
            int tam = dim_vec.length();
            if(dim_vec[tam-2].toInt() == raiz->hijos.size()){
                struct tri tridim;
                struct bi bidim;
                struct uni unidim;
                for(int x = 0; x < raiz->hijos.size(); x++){
                    NodoAST nod = raiz->hijos.at(x);
                    Resultado res = segundo_recorrdio(&nod);
                    unidim.unidimencion = res.arreglo[0].tridimencion[0].bidimencion[0].unidimencion;
                    bidim.bidimencion.append(unidim);
                }
                tridim.tridimencion.append(bidim);
                r.arreglo.append(tridim);

        }else{
            insertarErrSem(raiz->linea, raiz->columna, "error semantico", " error fatal en las dimenciones del arreglo ");
        }

        }
            break;
        case TRIDIMENCION:
        {
            if(dim_vec[0].toInt() == raiz->hijos.size()){
                struct tri tridim;
                struct bi bidim;
                for(int x = 0; x < raiz->hijos.size(); x++){
                    NodoAST nod = raiz->hijos.at(x);
                    Resultado res = segundo_recorrdio(&nod);
                    bidim.bidimencion = res.arreglo[0].tridimencion[0].bidimencion;
                    tridim.tridimencion.append(bidim);
                }
                r.arreglo.append(tridim);

    }else{
        insertarErrSem(raiz->linea, raiz->columna, "error semantico", " error fatal en las dimenciones del arreglo ");
    }

    }
        break;
        case EXPRESION:
        {
            int tamdim = dim_vec.length();
            if(dim_vec[tamdim-1].toInt() == raiz->hijos.size()){
                struct tri tridi;
                struct bi bidi;
                struct uni unidi;
                for(int x = 0; x < raiz->hijos.size(); x++){
                    NodoAST nod = raiz->hijos.at(x);
                    Resultado res = op_artimetica(&nod);
                    unidi.unidimencion.append(res.valor);
                }
                bidi.bidimencion.append(unidi);
                tridi.tridimencion.append(bidi);
                r.arreglo.append(tridi);
            }else{
                insertarErrSem(raiz->linea, raiz->columna, "error semantico", " error fatal en las dimenciones del arreglo ");
            }
        }
            break;
        case REASIGNACION_VEC:
        {
            NodoAST nod = raiz->hijos.at(0);
            NodoAST nod1 = raiz->hijos.at(1);

            Resultado miId = segundo_recorrdio(&nod);

            QList<QString> dime = dim_vec;
            dim_vec.clear();/*limpia lsita*/
            Resultado nuevoasig = op_logicaYrelacional(&nod1);

            bool flag = true;
            /*busca el id en la lista de variables locales */
            if(Vlocal.length() != 0){
                for(int x = Vlocal.length()-1; x >=0 ; x--){
                    if(miId.valor == Vlocal[x].id){
                        if("variable" != Vlocal[x].rol){
                            flag = false;
                            if(dime.length() == 1){
                                Vlocal[x].arreglo[0].tridimencion[0].bidimencion[0].unidimencion[dime[0].toInt()]= nuevoasig.valor;
                            }else if(dime.length() == 2){
                                Vlocal[x].arreglo[0].tridimencion[0].bidimencion[dime[0].toInt()].unidimencion[dime[1].toInt()]= nuevoasig.valor;
                            }else if(dime.length() == 3){
                                Vlocal[x].arreglo[0].tridimencion[dime[0].toInt()].bidimencion[dime[1].toInt()].unidimencion[dime[2].toInt()]= nuevoasig.valor;
                            }else{
                                insertarErrSem(raiz->linea, raiz->columna, "error semantico", "el arreglo: < " + Vlocal[x].id + " > esceso de dimenciones");
                            }

                            //std::cout<<endl<< Vlocal[x].arreglo[0].tridimencion[0].bidimencion[0].unidimencion[0].toStdString();
                            //std::cout<<endl<< Vlocal[x].arreglo[0].tridimencion[2].bidimencion[2].unidimencion[2].toStdString()<<endl;
                            break;
                        }
                        break;
                    }
                }
            }
            /*busca el id en la lista de variables globaels*/
            if(flag){
                for(int x = Vglobal.length()-1; x >=0 ; x--){
                    if(miId.valor == Vglobal[x].id){
                        if("variable" != Vglobal[x].rol){
                            flag = false;
                            if(dime.length() == 1){
                                Vglobal[x].arreglo[0].tridimencion[0].bidimencion[0].unidimencion[dime[0].toInt()]= nuevoasig.valor;
                            }else if(dime.length() == 2){
                                Vglobal[x].arreglo[0].tridimencion[0].bidimencion[dime[0].toInt()].unidimencion[dime[1].toInt()]= nuevoasig.valor;
                            }else if(dime.length() == 3){
                                Vglobal[x].arreglo[0].tridimencion[dime[0].toInt()].bidimencion[dime[1].toInt()].unidimencion[dime[2].toInt()]= nuevoasig.valor;
                            }else{
                                insertarErrSem(raiz->linea, raiz->columna, "error semantico", "el arreglo: < " + Vglobal[x].id + " > esceso de dimenciones");
                            }

                            //std::cout<<endl<< Vglobal[x].arreglo[0].tridimencion[0].bidimencion[0].unidimencion[0].toStdString();
                            //std::cout<<endl<< Vglobal[x].arreglo[0].tridimencion[2].bidimencion[2].unidimencion[2].toStdString()<<endl;
                            break;
                        }
                        break;
                    }
                }
            }
            /*si no existe el id entonces arroja un error en consola*/
            if(flag){
                insertarErrSem(raiz->linea, raiz->columna, "error semantico", "la variable: " +raiz->valor + " no se ha declarado");
            }

            dime.clear(); /*limpia la lista de dime para que no genere errores */
        }
            break;
        case ACCESO_VEC:
        {
            r.valor = raiz->hijos.at(0).valor; /*retorna el id*/
            NodoAST nod = raiz->hijos.at(1);
            Resultado res = segundo_recorrdio(&nod); /*guarda las dimenciones*/
        }
            break;
        case INSTANCIA:
        {
            Resultado res = existe_clase(raiz->hijos.at(0).valor, raiz->hijos.at(0).linea);
            if(raiz->hijos.size() == 2){
                if(res.flag){
                    struct tabla_clase tmp;
                    tmp.linea = raiz->hijos.at(0).linea;
                    tmp.columna = raiz->hijos.at(0).columna;
                    tmp.tipo = raiz->hijos.at(0).valor;
                    tmp.idClase = raiz->hijos.at(1).valor;
                    objetos.append(tmp);
                }
            }else if(raiz->hijos.size() == 3){
                if(res.flag){
                    struct tabla_clase tmp;
                    tmp.linea = raiz->hijos.at(0).linea;
                    tmp.columna = raiz->hijos.at(0).columna;
                    tmp.tipo = raiz->hijos.at(0).valor;
                    tmp.idClase = raiz->hijos.at(1).valor;
                    tmp.NodoClase = res.nodo;
                    objetos.append(tmp);
                }
                existe_clase(raiz->hijos.at(2).valor, raiz->hijos.at(2).linea);
            }

        }
            break;
        case OBJECTO_ASIGNACION:
        {
            for(int x = 0; x < objetos.length(); x++){
                if(raiz->hijos.at(0).valor == objetos[x].idClase){
                    Resultado res =  existe_clase(raiz->hijos.at(1).valor, raiz->hijos.at(1).linea);
                    if(res.flag){
                        objetos[x].NodoClase = res.nodo;
                        objetos[x].tipo = raiz->hijos.at(1).valor;
                    }
                    return r;
                }
            }
            insertarErrSem(raiz->hijos.at(0).linea, raiz->hijos.at(0).columna, "error semantico", " no existe la clase"+raiz->hijos.at(0).valor);
        }
            break;
        case ACCES_VFM:
        {
            id_objeto = raiz->hijos.at(0).valor;
            for (int x = objetos.length()-1; x >=0 ; x--) {
                if(raiz->hijos.at(0).valor == objetos[x].idClase){
                    insert_entorno_global(0, 0, "CLASE", "", "", objetos[x].idClase);
                    segundo_recorrdio(&objetos[x].NodoClase); /*manda a ejecutar la clase para obtener sus atributos*/
                    NodoAST fun = raiz->hijos.at(1);
                    r = tercer_recorrdio(&fun);
                    /*elimina el entorno de las funciones */
                    entorno_global("CLASE");
                    return r;
                }
            }
            insertarErrSem(raiz->hijos.at(0).linea, raiz->hijos.at(0).columna, "error semantico", " no se ha instanciado el objeto: "+raiz->hijos.at(0).valor);
        }
            break;

    }
    return r;
}



Resultado primerRecorrido:: tercer_recorrdio(NodoAST *raiz){
    Resultado r = Resultado();
    switch(raiz->tipo_){
        case LCLASE:
            {
            NodoAST lclase = raiz->hijos.at(0);
            Resultado mislclase = tercer_recorrdio(&lclase);
            }
            break;
        case CLASE:
            {
            NodoAST clase = raiz->hijos.at(1);
            Resultado miclase = tercer_recorrdio(&clase);
            }
            break;
        case LCUERPO:
            {   /*como tiene muchos hijos entonces se ejecuta un for*/
            for(int i = 0; i < raiz->hijos.size(); i++){
                NodoAST lcuerpo = raiz->hijos.at(i);
                Resultado milcuerpo = tercer_recorrdio(&lcuerpo);
            }
            }
            break;
        case VAR_DECLARACION:
            {
                /*se guarda las variables dentro de la Lista variable*/
                struct tabla_Var_local tmp;
                tmp.linea = raiz->hijos.at(0).linea;
                tmp.columna = raiz->hijos.at(0).columna;

                if(raiz->hijos.size() == 3){
                    tmp.visibilidad = raiz->hijos.at(2).valor.toLower();
                }else{
                    tmp.visibilidad = "publico";
                }

                NodoAST lsId = raiz->hijos.at(1);
                Resultado LSID = tercer_recorrdio(&lsId);
                for(int x = 0; x < LSID.LId.size(); x++){
                      tmp.rol = "variable";
                      tmp.tipo = raiz->hijos.at(0).valor.toLower();
                      tmp.id = LSID.LId.at(x);
                      tmp.valor = "";
                      Vlocal.append(tmp);

                      /*guardar objetos en la tabla de simbolos*/
                      Tabla_simbolo.append(tmp);
                  }

            }
            break;
        case VAR_ASIG:
            {
                /*se guarda las variables dentro de la Lista variable*/
                struct tabla_Var_local tmp;
                int linea = raiz->hijos.at(0).linea;
                int columna = raiz->hijos.at(0).columna;

                bool hijo34 = false;
                int hijoID = 0;

                if(raiz->hijos.size() == 4){
                    hijo34 = true;
                    tmp.visibilidad = raiz->hijos.at(3).valor.toLower();
                }else
                if(raiz->hijos.size() == 3){
                    hijo34 = true;
                    tmp.visibilidad = "";
                }

                if(hijo34){
                    NodoAST lsId = raiz->hijos.at(1);
                    Resultado LSID = tercer_recorrdio(&lsId);

                    NodoAST operacion = raiz->hijos.at(2);
                    Resultado misOperaciones = op_logicaYrelacional(&operacion);
                    QString miBool = "";

                    bool flag_tipo_var = true;

                    if(raiz->hijos.at(0).valor.toLower() == misOperaciones.tipo_var){
                        flag_tipo_var = false;
                        for(int x = 0; x < LSID.LId.size(); x++){
                          //std::cout<<LSID.LId.at(x).toStdString()<<endl;
                              tmp.linea = linea;
                              tmp.columna = columna;
                              tmp.rol = "variable";
                              tmp.tipo = raiz->hijos.at(0).valor.toLower();
                              tmp.id = LSID.LId.at(x);
                              /* para convertir el valor de un booleano a false o true */
                              if(misOperaciones.tipo_var == "booleano"){
                                  if(misOperaciones.flag){
                                      tmp.valor = "true";
                                  }else{
                                      tmp.valor = "false";
                                  }
                              }else{
                                  tmp.valor = misOperaciones.valor;
                              }
                              Vlocal.append(tmp);

                              /*guardar objetos en la tabla de simbolos*/
                              Tabla_simbolo.append(tmp);
                          }
                    }

                    if(flag_tipo_var){
                        insertarErrSem(linea, columna, "error semantico", "la variable < "+LSID.LId[0]+" > no es de tipo "+misOperaciones.tipo_var);
                    }
                }
                /*la variable esta de esta forma: var = 5*2$  entonces tiene dos hijos la raiz*/
                if(raiz->hijos.size() == 2){
                    QString idVar = raiz->hijos.at(0).valor;
                    int idline = raiz->hijos.at(0).linea;
                    int idcol = raiz->hijos.at(0).columna;

                    NodoAST operacion = raiz->hijos.at(1);
                    Resultado misOperaciones = op_logicaYrelacional(&operacion);
                    bool flag_id = true;
                    bool flag_tipo = true;

                    /*busca variable declarada en la lista local*/
                    for(int x = Vlocal.length()-1; x >=0 ; x--){
                        if(idVar == Vlocal[x].id ){
                            flag_id = false;
                            if(misOperaciones.tipo_var == Vlocal[x].tipo ){
                                flag_tipo = false;
                                /* para convertir el valor de un booleano a false o true */
                                if(misOperaciones.tipo_var == "booleano"){
                                    if(misOperaciones.flag){
                                        Vlocal[x].valor = "true";
                                        reasignar_valores_clase_global(id_objeto, idVar, misOperaciones);
                                    }else{
                                        Vlocal[x].valor = "false";
                                        reasignar_valores_clase_global(id_objeto, idVar, misOperaciones);
                                    }
                                }else{
                                    Vlocal[x].valor = misOperaciones.valor;
                                    reasignar_valores_clase_global(id_objeto, idVar, misOperaciones);
                                }
                                break;
                            }
                            flag_tipo = false;
                            break;
                        }
                    }
                     /*busca variables declaradas globalmente*/
                    if(flag_id){
                        for(int x = Vglobal.length()-1; x >=0 ; x--){
                            if(idVar == Vglobal[x].id ){
                                flag_id = false;
                                if(misOperaciones.tipo_var == Vglobal[x].tipo ){
                                    flag_tipo = false;
                                    /* para convertir el valor de un booleano a false o true */
                                    if(misOperaciones.tipo_var == "booleano"){
                                        if(misOperaciones.flag){
                                            Vglobal[x].valor = "true";
                                            reasignar_valores_clase_global(id_objeto, idVar, misOperaciones);
                                        }else{
                                            Vglobal[x].valor = "false";
                                            reasignar_valores_clase_global(id_objeto, idVar, misOperaciones);
                                        }
                                    }else{

                                        Vglobal[x].valor = misOperaciones.valor;
                                        reasignar_valores_clase_global(id_objeto, idVar, misOperaciones);
                                    }
                                    break;
                                }
                                flag_tipo = false;
                                break;
                            }
                        }
                    }

                    if(flag_id){
                        insertarErrSem(idline, idcol, "error semantico", "la variable < "+idVar+" > no se ha declarado");
                    }
                    if(flag_tipo){
                        insertarErrSem(idline, idcol, "error semantico", "la variable < "+idVar+" > no es de tipo "+misOperaciones.tipo_var);
                    }
                    /*buscar variable declarada en la tabla de simbolo*/
                    for(int x = Tabla_simbolo.length()-1; x >=0 ; x--){
                        if(idVar == Tabla_simbolo[x].id ){
                            if(misOperaciones.tipo_var == Tabla_simbolo[x].tipo ){
                                /* para convertir el valor de un booleano a false o true */
                                if(misOperaciones.tipo_var == "booleano"){
                                    if(misOperaciones.flag){
                                        Tabla_simbolo[x].valor = "true";
                                    }else{
                                        Tabla_simbolo[x].valor = "false";
                                    }
                                }else{
                                    Tabla_simbolo[x].valor = misOperaciones.valor;
                                }
                                break;
                            }
                            break;
                        }
                    }
                }

            }
            break;
        case LISTAID:
            {
                QList<QString> lsid;
                for(int i = 0; i< raiz->hijos.size(); i++){
                    NodoAST lID = raiz->hijos.at(i);
                    Resultado miID = tercer_recorrdio(&lID);
                    lsid.append(miID.valor);
                }
                r.LId = lsid;
                return r;
            }
            break;
        case ID:
            {
                //QString ids = raiz->hijos.at(0).valor;
                //std::cout<<ids.toStdString()<<endl;
                r.valor = raiz->hijos.at(0).valor;
            }
            break;
        case MAIN:
            {
                NodoAST mimain = raiz->hijos.at(1);
                Resultado misMain = tercer_recorrdio(&mimain);
            }
            break;
        case LS:
            {   /*como tiene muchos hijos entonces se ejecuta un for*/
                for(int i = 0; i < raiz->hijos.size(); i++){
                NodoAST ls = raiz->hijos.at(i);
                    r = tercer_recorrdio(&ls);
                    if(r.romper == "romper"){
                        break;
                    }else if(r.continuar == "continuar"){
                        break;
                    }else if(r.romper == "salir"){
                        break;
                    }else if(r.retornar == "retornar"){
                        break;
                    }
                }
            }
            break;
        case IMPRIMIR:
            {
                NodoAST Nimprimir = raiz->hijos.at(0);
                imprimir = true;
                Resultado Miimpirmir = op_artimetica(&Nimprimir);
                resultado += Miimpirmir.valor + "\n";
            }
            break;
        case SEN_IF:
            {
                NodoAST senIf = raiz->hijos.at(0);
                Resultado misenIf = tercer_recorrdio(&senIf);
                r.romper = misenIf.romper;
                r.continuar = misenIf.continuar;
                r.retornar = misenIf.retornar;
            }
            break;
        case IF:
            {
                 imprimir = true;
                NodoAST OPL = raiz->hijos.at(0);
                Resultado miOPL = op_logicaYrelacional(&OPL);

                if(miOPL.tipo_var == "booleano"){
                    if(miOPL.flag){
                        insert_entorno(raiz->linea, raiz->columna, "SENTENCIA", "", "", "IF"); /*insertar nombre entonrno*/
                        NodoAST entrarIf = raiz->hijos.at(1);
                        Resultado resEntrarIf = tercer_recorrdio(&entrarIf);
                        miOPL.romper = resEntrarIf.romper;
                        miOPL.continuar = resEntrarIf.continuar;
                        miOPL.retornar = resEntrarIf.retornar;

                        entorno("SENTENCIA"); /* entorno*/
                    }
                }else{
                    insertarErrSem(raiz->linea, raiz->columna, "error semantico", "solo se validan expresiones logicas y relacionales en las sentencias IF");
                    miOPL.flag = true;
                }

                return miOPL;
            }
            break;
        case ELSE_IF:
        {
            NodoAST NodIF = raiz->hijos.at(0);
            Resultado miIf = tercer_recorrdio(&NodIF);

            if(!miIf.flag){
                NodoAST NodElse = raiz->hijos.at(1);
                Resultado res = tercer_recorrdio(&NodElse);
                r.romper = res.romper;
                r.continuar = res.continuar;
                r.retornar = res.retornar;
            }else{
                r.romper = miIf.romper;
                r.continuar = miIf.continuar;
                r.retornar = miIf.retornar;
            }

        }
            break;
        case ELSE:
        {
            NodoAST senIf = raiz->hijos.at(0);
            insert_entorno(raiz->linea, raiz->columna, "SENTENCIA", "", "", "ELSE"); /*insertar nombre entonrno*/
            Resultado misenIf = tercer_recorrdio(&senIf);
            r.continuar = misenIf.continuar;
            r.romper = misenIf.romper;
            r.retornar = misenIf.retornar;
            entorno("SENTENCIA"); /*entorno*/
        }
            break;
        case REPETIR:
        {
            NodoAST nodCond = raiz->hijos.at(0);
            Resultado condicion = op_artimetica(&nodCond);
            insert_entorno(raiz->linea, raiz->columna, "SENTENCIA", "", "","REPETIR"); /*insertar nombre entonrno*/
            NodoAST nodRepetir = raiz->hijos.at(1);

            if(condicion.tipo_var == "entero"){
                for(int x = 0; x < condicion.valor.toInt(); x++){
                    Resultado res = tercer_recorrdio(&nodRepetir);
                    if(res.romper == "romper"){
                        break;
                    }else if(res.romper == "salir"){
                        break;
                    }else if(res.retornar == "retornar"){
                        break;
                    }
                }
            }
            cont_aument = 0;
            cont_decrement = 0;
            entorno("SENTENCIA"); /*entorno*/
        }
            break;
        case ROMPER:
        {
            r.linea = raiz->linea;
            r.columna = raiz->columna;
            r.romper = raiz->valor.toLower();
        }
            break;
        case SALIR:
        {
            r.linea = raiz->linea;
            r.columna = raiz->columna;
            r.romper = raiz->valor.toLower();
        }
            break;
        case CONTINUAR:
        {
            r.linea = raiz->linea;
            r.columna = raiz->columna;
            r.continuar = raiz->valor.toLower();
        }
            break;
        case AUMENTO:
        {
            cont_aument++;
            NodoAST nodo = raiz->hijos.at(0);
            QString id = raiz->hijos.at(0).valor;
            r = op_artimetica(&nodo);
            struct tabla_Var_local tmp;
            tmp.linea = raiz->hijos.at(0).linea;
            tmp.columna = raiz->hijos.at(0).columna;
            tmp.rol = "variable";
            tmp.tipo = r.tipo_var;
            tmp.id = id;

            if(r.tipo_var == "entero"){
                tmp.valor = QString::number(r.valor.toInt() + 1);
                if(cont_aument >= 3){
                    insert_aument_decremet(id, QString::number(r.valor.toInt() + 1));
                }else{
                    Vlocal.append(tmp);
                }
            }else if(r.tipo_var == "doble"){
                tmp.valor = QString::number(r.valor.toDouble() + 1);
                if(cont_aument >= 3){
                    insert_aument_decremet(id, QString::number(r.valor.toInt() + 1));
                }else{
                    Vlocal.append(tmp);
                }
            }else if(r.tipo_var == "caracter"){
                int increm = char_to_int(r.valor) +1 ;
                char caracter = increm;
                tmp.valor = QString::number(caracter);
                if(cont_aument >= 3){
                    insert_aument_decremet(id, QString::number(r.valor.toInt() + 1));
                }else{
                    Vlocal.append(tmp);
                }
            }else{
                insertarErrSem(r.linea, r.columna, "error semantico: ", "no se puede aumentar la variable < "+id+" > no es de tipo ENTERO, DOBLE O CARACTER");
            }
        }
            break;
        case DECREMENTO:
    {
        cont_decrement++;
        NodoAST nodo = raiz->hijos.at(0);
        QString id = raiz->hijos.at(0).valor;
        r = op_artimetica(&nodo);
        struct tabla_Var_local tmp;
        tmp.linea = raiz->hijos.at(0).linea;
        tmp.columna = raiz->hijos.at(0).columna;
        tmp.rol = "variable";
        tmp.tipo = r.tipo_var;
        tmp.id = id;

        if(r.tipo_var == "entero"){
            tmp.valor = QString::number(r.valor.toInt() - 1);
            if(cont_decrement >= 3){
                insert_aument_decremet(id, QString::number(r.valor.toInt() - 1));
            }else{
                Vlocal.append(tmp);
            }
        }else if(r.tipo_var == "doble"){
            tmp.valor = QString::number(r.valor.toDouble() - 1);
            if(cont_decrement >= 3){
                insert_aument_decremet(id, QString::number(r.valor.toInt() - 1));
            }else{
                Vlocal.append(tmp);
            }
        }else if(r.tipo_var == "caracter"){
            int increm = char_to_int(r.valor) - 1 ;
            char caracter = increm;
            tmp.valor = QString::number(caracter);
            if(cont_decrement >= 3){
                insert_aument_decremet(id, QString::number(r.valor.toInt() - 1));
            }else{
                Vlocal.append(tmp);
            }
        }else{
            insertarErrSem(r.linea, r.columna, "error semantico: ", "no se puede aumentar la variable < "+id+" > no es de tipo ENTERO, DOBLE O CARACTER");
        }
    }
            break;
        case PARA:
        {
            insert_entorno(raiz->linea, raiz->columna, "SENTENCIA", "", "", "PARA"); /*insertar nombre entonrno*/
            NodoAST nod = raiz->hijos.at(0);
            tercer_recorrdio(&nod); /*inicializacion de condicion for(int x = 0  ******** )*/
            NodoAST nod1 = raiz->hijos.at(1);
            Resultado condicion = op_logicaYrelacional(&nod1);

            /* entorno de for*/
                while(condicion.flag){
                    if(condicion.tipo_var == "booleano"){
                        NodoAST entrar = raiz->hijos.at(3);
                        Resultado resEntrar = tercer_recorrdio(&entrar);
                        if(resEntrar.romper == "romper"){
                            break;
                        }else if(resEntrar.romper == "salir"){
                            break;
                        }else if(resEntrar.retornar == "retornar"){
                            break;
                        }
                        NodoAST aument = raiz->hijos.at(2);
                        tercer_recorrdio(&aument);
                    }else{
                        insertarErrSem(raiz->linea, raiz->columna, "error semantico", "solo se validan expresiones relacionales en las sentencias PARA");
                        break;
                    }
                    condicion = op_logicaYrelacional(&nod1); /*condicion de for*/
                }
            entorno("SENTENCIA"); /* entorno*/
            cont_aument = 0;
            cont_decrement = 0;

        }
            break;
        case MIENTRAS:
            {
                insert_entorno(raiz->linea, raiz->columna, "SENTENCIA", "", "", "MIENTRAS"); /*insertar nombre entonrno*/
                //NodoAST nod = raiz->hijos.at(0);
                //tercer_recorrdio(&nod); /*inicializacion de condicion for(int x = 0  ******** )*/
                NodoAST nod1 = raiz->hijos.at(0);
                Resultado condicion = op_logicaYrelacional(&nod1); /*condicion*/

                /* entorno de while*/
                    int contador = 0;
                    if(condicion.tipo_var == "booleano"){
                        while(condicion.flag){
                            contador++;
                            cout<<contador<<endl;
                            NodoAST entrar = raiz->hijos.at(1);
                            Resultado resEntrar = tercer_recorrdio(&entrar);
                            if(resEntrar.romper == "romper"){
                                break;
                            }else if(resEntrar.romper == "salir"){
                                break;
                            }else if(resEntrar.retornar == "retornar"){
                                break;
                            }
                            condicion = op_logicaYrelacional(&nod1); /*condicion de for*/
                            }
                    }else{
                        insertarErrSem(raiz->linea, raiz->columna, "error semantico", "solo se validan expresiones relacionales en las sentencias PARA");
                        break;
                    }

            entorno("SENTENCIA"); /* entorno*/
            cont_aument = 0;
            cont_decrement = 0;

    }
            break;
        case HACER_MIENTRAS:
        {
            insert_entorno(raiz->linea, raiz->columna, "SENTENCIA", "", "", "HACER_MIENTRAS"); /*insertar nombre entonrno*/
            Resultado condicion;
            do{
                NodoAST ast = raiz->hijos.at(0);
                Resultado res = tercer_recorrdio(&ast);
                if(res.romper == "romper"){
                    break;
                }else if(res.romper == "salir"){
                    break;
                }else if(res.retornar == "retornar"){
                    break;
                }
                NodoAST ASTcondicion = raiz->hijos.at(1);
                condicion = op_logicaYrelacional(&ASTcondicion);
                if(condicion.tipo_var != "booleano"){
                    insertarErrSem(condicion.linea, condicion.columna, "error semantico", "solo se validan expresiones relacionales en las sentencias PARA");
                    break;
                }
            }while(condicion.flag);
            entorno("SENTENCIA"); /* entorno*/
            cont_aument = 0;
            cont_decrement = 0;
        }
            break;
        case LLAMADA:
        {
            if(raiz->hijos.size() == 1){
                r = buscar_metod_function(raiz->hijos.at(0).valor, misParametro);
            }else{
                NodoAST ast = raiz->hijos.at(1);
                Resultado res = tercer_recorrdio(&ast);
                r = buscar_metod_function(raiz->hijos.at(0).valor, misParametro);
            }
        }
            break;
        case LPARAMETRO:
        {
            for(int lp = 0; lp<raiz->hijos.size(); lp++){
                NodoAST nod = raiz->hijos.at(lp);
                Resultado res = op_logicaYrelacional(&nod);
                struct tabla_Var_local aux;
                aux.linea = res.linea;
                aux.columna = res.columna;
                aux.tipo = res.tipo_var;
                aux.valor = res.valor;
                misParametro.append(aux);
            }
        }
            break;
        case PARAMETRO:
        {
            r.tipo_var = raiz->hijos.at(0).valor.toLower();/*tipo*/
            r.linea = raiz->hijos.at(0).linea;
            r.columna = raiz->hijos.at(0).columna;
            r.valor = raiz->hijos.at(1).valor; /*id*/
        }
            break;
        case RETORNAR:
        {
            NodoAST nodo_retornar = raiz->hijos.at(0);
            miRetorno = op_logicaYrelacional(&nodo_retornar);
            r.retornar = "retornar";
            flag_retornar = true;
            if(miRetorno.tipo_var != tipo_funcion){
                insertarErrSem(0,0, "error semantico: ", " el retorno no es de tipo < "+tipo_funcion+" > no coincide con el tipo de la funcion");
            }
        }
            break;
        case NOTIFICACION:
        {
            NodoAST nodoTitulo = raiz->hijos.at(0);
            Resultado titulo = op_logicaYrelacional(&nodoTitulo);

            NodoAST nodoMensaje = raiz->hijos.at(1);
            Resultado mensaje = op_logicaYrelacional(&nodoMensaje);
            struct lista_notificacion tmp;
            tmp.titulo = titulo.valor;
            tmp.mensaje = mensaje.valor;
            notificacion.append(tmp);
        }
            break;
        case ACCESO_VEC:
        {
            NodoAST pos = raiz->hijos.at(1);
            Resultado miPos = segundo_recorrdio(&pos); /*poscicion del arreglo*/

            NodoAST nod = raiz->hijos.at(0);
            Resultado miid = op_artimetica(&nod);/*manda a buscar el id del vector*/

        }
            break;
        case ASIGNACION_VEC:
    {
        /*se guarda las variables dentro de la Lista variable*/
        struct tabla_Var_local tmp;
        int linea = raiz->hijos.at(0).linea;
        int columna = raiz->hijos.at(0).columna;

        bool hijo34 = false;
        int hijoID = 0;

        if(raiz->hijos.size() == 5){
            hijo34 = true;
            tmp.visibilidad = raiz->hijos.at(4).hijos.at(0).valor.toLower();
        }else
        if(raiz->hijos.size() == 4){
            hijo34 = true;
            tmp.visibilidad = "publico";
        }

        if(hijo34){
            NodoAST lsId = raiz->hijos.at(1);
            Resultado LSID = segundo_recorrdio(&lsId);

            NodoAST nodoDim = raiz->hijos.at(2);
            segundo_recorrdio(&nodoDim);

            NodoAST nodoVec = raiz->hijos.at(3);
            Resultado res_vec = segundo_recorrdio(&nodoVec);
            dim_vec.clear(); /*limpia lista de dimenciones del arreglo*/

                for(int x = 0; x < LSID.LId.size(); x++){
                      tmp.linea = linea;
                      tmp.columna = columna;
                      tmp.rol = "arreglo";
                      tmp.tipo = raiz->hijos.at(0).valor.toLower();
                      tmp.id = LSID.LId.at(x);
                      tmp.arreglo = res_vec.arreglo;
                      Vlocal.append(tmp);
                      /*guardar objetos en la tabla de simbolos*/
                      Tabla_simbolo.append(tmp);
                  }
        }

        /*asignar valor a las variables ya declaradas*/
        if(raiz->hijos.size() == 2){
            QString idVar = raiz->hijos.at(0).valor;
            int idline = raiz->hijos.at(0).linea;
            int idcol = raiz->hijos.at(0).columna;

            NodoAST operacion = raiz->hijos.at(1);
            Resultado misOperaciones = op_logicaYrelacional(&operacion);
            bool flag_id = true;
            bool flag_tipo = true;
            /*buscar variable declarada*/
            for(int x = Vglobal.length()-1; x >=0 ; x--){
                if(idVar == Vglobal[x].id ){
                    flag_id = false;
                    if(misOperaciones.tipo_var == Vglobal[x].tipo ){
                        flag_tipo = false;
                        /* para convertir el valor de un booleano a false o true */
                        if(misOperaciones.tipo_var == "booleano"){
                            if(misOperaciones.flag){
                                Vglobal[x].valor = "true";
                            }else{
                                Vglobal[x].valor = "false";
                            }
                        }else{
                            Vglobal[x].valor = misOperaciones.valor;
                        }
                        break;
                    }
                    flag_tipo = false;
                    break;
                }
            }

            if(flag_id){
                insertarErrSem(idline, idcol, "error semantico", "la variable < "+idVar+" > no se ha declarado");
            }
            if(flag_tipo){
                insertarErrSem(idline, idcol, "error semantico", "la variable < "+idVar+" > no es de tipo "+misOperaciones.tipo_var);
            }
            /*buscar variable declarada en la tabla de simbolo*/
            for(int x = Tabla_simbolo.length()-1; x >=0 ; x--){
                if(idVar == Tabla_simbolo[x].id ){
                    if(misOperaciones.tipo_var == Tabla_simbolo[x].tipo ){
                        /* para convertir el valor de un booleano a false o true */
                        if(misOperaciones.tipo_var == "booleano"){
                            if(misOperaciones.flag){
                                Tabla_simbolo[x].valor = "true";
                            }else{
                                Tabla_simbolo[x].valor = "false";
                            }
                        }else{
                            Tabla_simbolo[x].valor = misOperaciones.valor;
                        }
                        break;
                    }
                    break;
                }
            }
        }

    }
            break;
        case REASIGNACION_VEC:
        {
            r = segundo_recorrdio(raiz);
        }
            break;
        case INSTANCIA:
        {
            Resultado res = existe_clase(raiz->hijos.at(0).valor, raiz->hijos.at(0).linea);
            if(raiz->hijos.size() == 2){
                if(res.flag){
                    struct tabla_clase tmp;
                    tmp.linea = raiz->hijos.at(0).linea;
                    tmp.columna = raiz->hijos.at(0).columna;
                    tmp.tipo = raiz->hijos.at(0).valor;
                    tmp.idClase = raiz->hijos.at(1).valor;
                    objetos.append(tmp);
                }
            }else if(raiz->hijos.size() == 3){
                if(res.flag){
                    struct tabla_clase tmp;
                    tmp.linea = raiz->hijos.at(0).linea;
                    tmp.columna = raiz->hijos.at(0).columna;
                    tmp.tipo = raiz->hijos.at(0).valor;
                    tmp.idClase = raiz->hijos.at(1).valor;
                    tmp.NodoClase = res.nodo;
                    objetos.append(tmp);
                }
                existe_clase(raiz->hijos.at(2).valor, raiz->hijos.at(2).linea);
            }

        }
            break;
        case OBJECTO_ASIGNACION:
        {
            for(int x = 0; x < objetos.length(); x++){
                if(raiz->hijos.at(0).valor == objetos[x].idClase){
                    Resultado res =  existe_clase(raiz->hijos.at(1).valor, raiz->hijos.at(1).linea);
                    if(res.flag){
                        objetos[x].NodoClase = res.nodo;
                        objetos[x].tipo = raiz->hijos.at(1).valor;
                    }
                }
            }
        }
            break;
        case ACCES_VFM:
        {
            r = segundo_recorrdio(raiz); /* envia a ejecutar en el segundo recorrido y devuelve los valores*/
        }
            break;
        case REASIGNACION_VAR_CLASE:
        {
            bool entra = true;
            QString c1 = raiz->hijos.at(0).valor;
            QString object = raiz->hijos.at(1).valor;
            QString nuevoRaiz = raiz->hijos.at(2).valor;
            for(int x = 0; x < objetos.length(); x++){
                if(c1 == objetos[x].idClase){  /*si el primer objeto existe  C1*/
                    for(int obj = 0; obj < objetos.length(); obj++){/*busca el objeto C1.object = nodoNuevo$ */
                        if(object == objetos[obj].idClase){  /* si el segundo objeto existe  OBJECT*/
                            if(objetos[x].tipo == objetos[obj].tipo){  /*si son del mismo tipo clase  C1.OBJECT */
                                NodoAST nod = raiz->hijos.at(2);
                                Resultado nodoNuevo = op_artimetica(&nod);  /*busca el nodo a asignar NUEVONODO*/
                                objetos[obj].NodoClase = nodoNuevo.nodo; /* C1.OBJECT = NUEVONODO$ */
                                entra = false;
                            }
                        }
                    }

                    if(entra){ /*reasignar variables de clase */
                        NodoAST nod = raiz->hijos.at(2);
                        Resultado nodoNuevo = op_logicaYrelacional(&nod);
                        for (int var = 0; var < objetos[x].NodoClase.hijos.length(); ++var) {
                            if(objetos[x].NodoClase.hijos[var].tipo == "VAR_ASIG"){
                                if(objetos[x].NodoClase.hijos[var].hijos[0].valor.toLower() != "arreglo" ){
                                    if(objetos[x].NodoClase.hijos[var].hijos[1].hijos[0].hijos[0].valor == object){
                                        objetos[x].NodoClase.hijos[var].hijos[2].valor = nodoNuevo.valor;
                                    }
                                }

                            }
                        }
                    }
                }
            }
        }
            break;
        case ACCESO_OBJECT:
        {

        r.tipo_var = raiz->hijos.at(0).valor;
        r.valor = raiz->hijos.at(1).valor;

            if(imprimir){
                QString idinstancia = raiz->hijos.at(0).valor;
                QString mivariable = raiz->hijos.at(1).valor;
                for(int x = 0; x < objetos.length(); x++){
                    if(idinstancia == objetos[x].idClase){
                        for (int var = 0; var < objetos[x].NodoClase.hijos.length(); ++var) {
                            if(objetos[x].NodoClase.hijos[var].tipo == "VAR_DECLARACION"){
                                if(objetos[x].NodoClase.hijos[var].hijos[0].valor.toLower() != "arreglo" ){
                                    if(objetos[x].NodoClase.hijos[var].hijos[1].hijos[0].hijos[0].valor == mivariable){
                                        //r.valor = objetos[x].NodoClase.hijos[var].hijos[2].valor;
                                        //r.tipo = objetos[x].NodoClase.hijos[var].hijos[0].tipo_;
                                        std::cout<<endl<<" cagada grande ";
                                        std::cout<<endl<<" funciona "<<objetos[x].NodoClase.hijos[var].hijos[2].valor.toStdString()<<"  exelente \n";
                                        break;
                                    }
                                }

                            }
                        }
                        break;
                    }
                }
            }

        }
            break;
        case DATOS_VEC:
        {
        NodoAST nod = raiz->hijos.at(0);

        Resultado miId = segundo_recorrdio(&nod);

        bool flag = true;
        /*busca el id en la lista de variables locales */
        if(Vlocal.length() != 0){
            for(int x = Vlocal.length()-1; x >=0 ; x--){
                if(miId.valor == Vlocal[x].id){
                    if("variable" != Vlocal[x].rol){
                        flag = false;
                        if(dim_vec.length() == 1){
                            r.valor =  Vlocal[x].arreglo[0].tridimencion[0].bidimencion[0].unidimencion[dim_vec[0].toInt()];
                            r.tipo_var = Vlocal[x].tipo;

                        }else if(dim_vec.length() == 2){
                            r.valor =  Vlocal[x].arreglo[0].tridimencion[0].bidimencion[dim_vec[0].toInt()].unidimencion[dim_vec[1].toInt()];
                            r.tipo_var = Vlocal[x].tipo;
                        }else if(dim_vec.length() == 3){
                            r.valor =  Vlocal[x].arreglo[0].tridimencion[dim_vec[0].toInt()].bidimencion[dim_vec[1].toInt()].unidimencion[dim_vec[2].toInt()];
                            r.tipo_var = Vlocal[x].tipo;
                        }else{
                            insertarErrSem(raiz->linea, raiz->columna, "error semantico", "el arreglo: < " + Vlocal[x].id + " > esceso de dimenciones");
                        }

                        //std::cout<<endl<< Vlocal[x].arreglo[0].tridimencion[0].bidimencion[0].unidimencion[0].toStdString();
                       // std::cout<<endl<< Vlocal[x].arreglo[0].tridimencion[2].bidimencion[2].unidimencion[2].toStdString()<<endl;
                        break;
                    }
                    break;
                }
            }
        }
        /*busca el id en la lista de variables globaels*/
        if(flag){
            for(int x = Vglobal.length()-1; x >=0 ; x--){
                if(miId.valor == Vglobal[x].id){
                    if("variable" != Vglobal[x].rol){
                        flag = false;
                        if(dim_vec.length() == 1){
                            r.valor =  Vglobal[x].arreglo[0].tridimencion[0].bidimencion[0].unidimencion[dim_vec[0].toInt()];
                            r.tipo_var = Vglobal[x].tipo;
                            r.linea = Vglobal[x].linea;
                        }else if(dim_vec.length() == 2){
                            r.valor =  Vglobal[x].arreglo[0].tridimencion[0].bidimencion[dim_vec[0].toInt()].unidimencion[dim_vec[1].toInt()];
                            r.tipo_var = Vglobal[x].tipo;
                        }else if(dim_vec.length() == 3){
                            r.valor =  Vglobal[x].arreglo[0].tridimencion[dim_vec[0].toInt()].bidimencion[dim_vec[1].toInt()].unidimencion[dim_vec[2].toInt()];
                            r.tipo_var = Vglobal[x].tipo;
                        }else{
                            insertarErrSem(raiz->linea, raiz->columna, "error semantico", "el arreglo: < " + Vglobal[x].id + " > esceso de dimenciones");
                        }

                        //std::cout<<endl<< Vglobal[x].arreglo[0].tridimencion[0].bidimencion[0].unidimencion[0].toStdString();
                        //std::cout<<endl<< Vglobal[x].arreglo[0].tridimencion[2].bidimencion[2].unidimencion[2].toStdString()<<endl;
                        break;
                    }
                    break;
                }
            }
        }
        if(!flag){
            if(r.tipo_var.toLower() == "entero"){
                r.tipo = INT;
            }else if(r.tipo_var.toLower() == "doble"){
                r.tipo = DOUBLE;
            }else if(r.tipo_var.toLower() == "cadena"){
                r.tipo = STRING;
            }else if(r.tipo_var.toLower() == "caracter"){
                r.tipo = CHAR;
            }else if(r.tipo_var.toLower() == "booleano"){
                r.tipo = BOOL;
            }
        }
        /*si no existe el id entonces arroja un error en consola*/
        if(flag){
            insertarErrSem(raiz->linea, raiz->columna, "error semantico", "la variable: " +raiz->valor + " no se ha declarado");
        }

        dim_vec.clear(); /*limpia la lista de dime para que no genere errores */
    }
            break;
    }
    return r;
}


Resultado primerRecorrido::op_logicaYrelacional( NodoAST *raiz){
    Resultado r = Resultado();
    switch(raiz->tipo_){
        case EQEQ:
        {
            NodoAST iz = raiz->hijos.at(0);
            Resultado op1 = op_logicaYrelacional(&iz);
            NodoAST der = raiz->hijos.at(1);
            Resultado op2 = op_logicaYrelacional(&der);
            r.tipo_var = "booleano";
            switch(op1.tipo){
                case INT:
                {
                    switch(op2.tipo){
                        case INT:
                        {
                            if(op1.valor.toInt() == op2.valor.toInt()){
                                r.flag = true;
                            }
                            r.tipo = INT;
                            r.valor = op1.valor;
                            return r;
                        }
                        case DOUBLE:
                        {
                            if(op1.valor.toInt() == op2.valor.toDouble()){
                                r.flag = true;
                            }
                            r.tipo = INT;
                            r.valor = op1.valor;
                            return r;
                        }
                        case BOOL:
                        {
                            if(op1.valor.toInt() == boolenao_to_int(op2.valor)){
                                r.flag = true;
                            }
                            r.tipo = INT;
                            r.valor = op1.valor;
                            return r;
                        }
                        case CHAR:
                        {
                            if(op1.valor.toInt() == char_to_int(op2.valor)){
                                r.flag = true;
                            }
                            r.tipo = INT;
                            r.valor = op1.valor;
                            return r;
                        }
                        case STRING:
                        {
                            insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar con cadena");
                            return r;
                        }

                    }
                }
            case DOUBLE:
            {
                switch(op2.tipo){
                    case INT:
                    {
                        if(op1.valor.toDouble() == op2.valor.toInt()){
                            r.flag = true;
                        }
                        r.tipo = DOUBLE;
                        r.valor = op1.valor;
                        return r;
                    }
                    case DOUBLE:
                    {
                        if(op1.valor.toDouble() == op2.valor.toDouble()){
                            r.flag = true;
                        }
                        r.tipo = DOUBLE;
                        r.valor = op1.valor;
                        return r;
                    }
                    case BOOL:
                    {
                        if(op1.valor.toDouble() == boolenao_to_int(op2.valor)){
                            r.flag = true;
                        }
                        r.tipo = DOUBLE;
                        r.valor = op1.valor;
                        return r;
                    }
                    case CHAR:
                    {
                        if(op1.valor.toDouble() == char_to_int(op2.valor)){
                            r.flag = true;
                        }
                        r.tipo = DOUBLE;
                        r.valor = op1.valor;
                        return r;
                    }
                    case STRING:
                    {
                        insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar con cadena");
                        return r;
                    }

                }
            }
            case BOOL:
            {
                switch(op2.tipo){
                    case INT:
                    {
                        if(boolenao_to_int(op1.valor) == op2.valor.toInt()){
                            r.flag = true;
                        }
                        r.tipo = BOOL;
                        r.valor = op1.valor;
                        return r;
                    }
                    case DOUBLE:
                    {
                        if(boolenao_to_int(op1.valor) == op2.valor.toDouble()){
                            r.flag = true;
                        }
                        r.tipo = BOOL;
                        r.valor = op1.valor;
                        return r;
                    }
                    case BOOL:
                    {
                        if(boolenao_to_int(op1.valor) == boolenao_to_int(op2.valor)){
                            r.flag = true;
                        }
                        r.tipo = BOOL;
                        r.valor = op1.valor;
                        return r;
                    }
                    case CHAR:
                    {
                        insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar booleano con caracter");
                        return r;
                    }
                    case STRING:
                    {
                        insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar booleano con cadena");
                        return r;
                    }

                }
            }
            case CHAR:
            {
                switch(op2.tipo){
                    case INT:
                    {
                        if(char_to_int(op1.valor) == op2.valor.toInt()){
                            r.flag = true;
                        }
                        r.tipo = CHAR;
                        r.valor = op1.valor;
                        return r;
                    }
                    case DOUBLE:
                    {
                        if(char_to_int(op1.valor) == op2.valor.toDouble()){
                            r.flag = true;
                        }
                        r.tipo = CHAR;
                        r.valor = op1.valor;
                        return r;
                    }
                    case BOOL:
                    {
                        insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar caracter con booleano");
                        return r;
                    }
                    case CHAR:
                    {
                        if(char_to_int(op1.valor) == char_to_int(op2.valor)){
                            r.flag = true;
                        }
                        r.tipo = CHAR;
                        r.valor = op1.valor;
                        return r;
                    }
                    case STRING:
                    {
                        insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar caracter con cadena");
                        return r;
                    }

                }
            }
            case STRING:
            {
                switch(op2.tipo){
                    case STRING:
                    {
                        if(op1.valor == op2.valor){
                            r.flag = true;
                        }
                        r.tipo = STRING;
                        r.valor = op1.valor;
                        return r;
                    }
                    default:
                    {
                        insertarErrSem(op1.linea, op1.columna, "error semantico", "no se puede comparar cadena con otro tipo de dato");
                        return r;
                    }
                }
                break;
            }
                break;
            }
        }
            break;
    case DIFQ:
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = op_logicaYrelacional(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = op_logicaYrelacional(&der);
        r.tipo_var = "booleano";
        switch(op1.tipo){
            case INT:
            {
                switch(op2.tipo){
                    case INT:
                    {
                        if(op1.valor.toInt() != op2.valor.toInt()){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case DOUBLE:
                    {
                        if(op1.valor.toInt() != op2.valor.toDouble()){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case BOOL:
                    {
                        if(op1.valor.toInt() != boolenao_to_int(op2.valor)){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case CHAR:
                    {
                        if(op1.valor.toInt() != char_to_int(op2.valor)){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case STRING:
                    {
                        insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar con cadena");
                        return r;
                    }

                }
            }
        case DOUBLE:
        {
            switch(op2.tipo){
                case INT:
                {
                    if(op1.valor.toDouble() != op2.valor.toInt()){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case DOUBLE:
                {
                    if(op1.valor.toDouble() != op2.valor.toDouble()){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case BOOL:
                {
                    if(op1.valor.toDouble() != boolenao_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case CHAR:
                {
                    if(op1.valor.toDouble() != char_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case STRING:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar con cadena");
                    return r;
                }

            }
        }
        case BOOL:
        {
            switch(op2.tipo){
                case INT:
                {
                    if(boolenao_to_int(op1.valor) != op2.valor.toInt()){
                        r.flag = true;
                    }
                    r.tipo = BOOL;
                    r.valor = op1.valor;
                    return r;
                }
                case DOUBLE:
                {
                    if(boolenao_to_int(op1.valor) != op2.valor.toDouble()){
                        r.flag = true;
                    }
                    r.tipo = BOOL;
                    r.valor = op1.valor;
                    return r;
                }
                case BOOL:
                {
                    if(boolenao_to_int(op1.valor) != boolenao_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = BOOL;
                    r.valor = op1.valor;
                    return r;
                }
                case CHAR:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar booleano con caracter");
                    return r;
                }
                case STRING:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar booleano con cadena");
                    return r;
                }

            }
        }
        case CHAR:
        {
            switch(op2.tipo){
                case INT:
                {
                    if(char_to_int(op1.valor) != op2.valor.toInt()){
                        r.flag = true;
                    }
                    r.tipo = CHAR;
                    r.valor = op1.valor;
                    return r;
                }
                case DOUBLE:
                {
                    if(char_to_int(op1.valor) != op2.valor.toDouble()){
                        r.flag = true;
                    }
                    r.tipo = CHAR;
                    r.valor = op1.valor;
                    return r;
                }
                case BOOL:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar caracter con booleano");
                    return r;
                }
                case CHAR:
                {
                    if(char_to_int(op1.valor) != char_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = CHAR;
                    r.valor = op1.valor;
                    return r;
                }
                case STRING:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar caracter con cadena");
                    return r;
                }

            }
        }
        case STRING:
        {
            switch(op2.tipo){
                case STRING:
                {
                    if(op1.valor != op2.valor){
                        r.flag = true;
                    }
                    r.tipo = STRING;
                    r.valor = op1.valor;
                    return r;
                }
                default:
                {
                    insertarErrSem(op1.linea, op1.columna, "error semantico", "no se puede comparar cadena con otro tipo de dato");
                    return r;
                }
            }
            break;
        }
            break;
        }
    }
        break;
    case MENORQ:
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = op_logicaYrelacional(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = op_logicaYrelacional(&der);
        r.tipo_var = "booleano";
        switch(op1.tipo){
            case INT:
            {
                switch(op2.tipo){
                    case INT:
                    {
                        if(op1.valor.toInt() < op2.valor.toInt()){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case DOUBLE:
                    {
                        if(op1.valor.toInt() < op2.valor.toDouble()){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case BOOL:
                    {
                        if(op1.valor.toInt() < boolenao_to_int(op2.valor)){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case CHAR:
                    {
                        if(op1.valor.toInt() < char_to_int(op2.valor)){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case STRING:
                    {
                        insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar entero con cadena");
                        return r;
                    }

                }
            }
        case DOUBLE:
        {
            switch(op2.tipo){
                case INT:
                {
                    if(op1.valor.toDouble() < op2.valor.toInt()){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case DOUBLE:
                {
                    if(op1.valor.toDouble() < op2.valor.toDouble()){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case BOOL:
                {
                    if(op1.valor.toDouble() < boolenao_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case CHAR:
                {
                    if(op1.valor.toDouble() < char_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case STRING:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar con cadena");
                    return r;
                }

            }
        }
        case BOOL:
        {
            switch(op2.tipo){
                case INT:
                {
                    if(boolenao_to_int(op1.valor) < op2.valor.toInt()){
                        r.flag = true;
                    }
                    r.tipo = BOOL;
                    r.valor = op1.valor;
                    return r;
                }
                case DOUBLE:
                {
                    if(boolenao_to_int(op1.valor) < op2.valor.toDouble()){
                        r.flag = true;
                    }
                    r.tipo = BOOL;
                    r.valor = op1.valor;
                    return r;
                }
                case BOOL:
                {
                    if(boolenao_to_int(op1.valor) < boolenao_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = BOOL;
                    r.valor = op1.valor;
                    return r;
                }
                case CHAR:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar booleano con caracter");
                    return r;
                }
                case STRING:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar booleano con cadena");
                    return r;
                }

            }
        }
        case CHAR:
        {
            switch(op2.tipo){
                case INT:
                {
                    if(char_to_int(op1.valor) < op2.valor.toInt()){
                        r.flag = true;
                    }
                    r.tipo = CHAR;
                    r.valor = op1.valor;
                    return r;
                }
                case DOUBLE:
                {
                    if(char_to_int(op1.valor) < op2.valor.toDouble()){
                        r.flag = true;
                    }
                    r.tipo = CHAR;
                    r.valor = op1.valor;
                    return r;
                }
                case BOOL:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar caracter con booleano");
                    return r;
                }
                case CHAR:
                {
                    if(char_to_int(op1.valor) < char_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = CHAR;
                    r.valor = op1.valor;
                    return r;
                }
                case STRING:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar caracter con cadena");
                    return r;
                }

            }
        }
        case STRING:
        {
            insertarErrSem(op1.linea, op1.columna, "error semantico", "no se puede comparar cadena con otro tipo de dato");
            return r;
        }
            break;
        }
    }
        break;
    case MAYORQ:
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = op_logicaYrelacional(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = op_logicaYrelacional(&der);
        r.tipo_var = "booleano";
        switch(op1.tipo){
            case INT:
            {
                switch(op2.tipo){
                    case INT:
                    {
                        if(op1.valor.toInt() > op2.valor.toInt()){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    break;
                    case DOUBLE:
                    {
                        if(op1.valor.toInt() > op2.valor.toDouble()){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case BOOL:
                    {
                        if(op1.valor.toInt() > boolenao_to_int(op2.valor)){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case CHAR:
                    {
                        if(op1.valor.toInt() > char_to_int(op2.valor)){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case STRING:
                    {
                        insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar entero con cadena");
                        return r;
                    }

                }
            }
        case DOUBLE:
        {
            switch(op2.tipo){
                case INT:
                {
                    if(op1.valor.toDouble() > op2.valor.toInt()){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case DOUBLE:
                {
                    if(op1.valor.toDouble() > op2.valor.toDouble()){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case BOOL:
                {
                    if(op1.valor.toDouble() > boolenao_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case CHAR:
                {
                    if(op1.valor.toDouble() > char_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case STRING:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar con cadena");
                    return r;
                }

            }
        }
        case BOOL:
        {
            switch(op2.tipo){
                case INT:
                {
                    if(boolenao_to_int(op1.valor) > op2.valor.toInt()){
                        r.flag = true;
                    }
                    r.tipo = BOOL;
                    r.valor = op1.valor;
                    return r;
                }
                case DOUBLE:
                {
                    if(boolenao_to_int(op1.valor) > op2.valor.toDouble()){
                        r.flag = true;
                    }
                    r.tipo = BOOL;
                    r.valor = op1.valor;
                    return r;
                }
                case BOOL:
                {
                    if(boolenao_to_int(op1.valor) > boolenao_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = BOOL;
                    r.valor = op1.valor;
                    return r;
                }
                case CHAR:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar booleano con caracter");
                    return r;
                }
                case STRING:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar booleano con cadena");
                    return r;
                }

            }
        }
        case CHAR:
        {
            switch(op2.tipo){
                case INT:
                {
                    if(char_to_int(op1.valor) > op2.valor.toInt()){
                        r.flag = true;
                    }
                    r.tipo = CHAR;
                    r.valor = op1.valor;
                    return r;
                }
                case DOUBLE:
                {
                    if(char_to_int(op1.valor) > op2.valor.toDouble()){
                        r.flag = true;
                    }
                    r.tipo = CHAR;
                    r.valor = op1.valor;
                    return r;
                }
                case BOOL:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar caracter con booleano");
                    return r;
                }
                case CHAR:
                {
                    if(char_to_int(op1.valor) > char_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = CHAR;
                    r.valor = op1.valor;
                    return r;
                }
                case STRING:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar caracter con cadena");
                    return r;
                }

            }
        }
        case STRING:
        {
            insertarErrSem(op1.linea, op1.columna, "error semantico", "no se puede comparar cadena con otro tipo de dato");
            return r;
        }
            break;
        }
    }
        break;
    case MENORIGUALQ:
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = op_logicaYrelacional(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = op_logicaYrelacional(&der);
        r.tipo_var = "booleano";
        switch(op1.tipo){
            case INT:
            {
                switch(op2.tipo){
                    case INT:
                    {
                        if(op1.valor.toInt() <= op2.valor.toInt()){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case DOUBLE:
                    {
                        if(op1.valor.toInt() <= op2.valor.toDouble()){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case BOOL:
                    {
                        if(op1.valor.toInt() <= boolenao_to_int(op2.valor)){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case CHAR:
                    {
                        if(op1.valor.toInt() <= char_to_int(op2.valor)){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case STRING:
                    {
                        insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar entero con cadena");
                        return r;
                    }

                }
            }
        case DOUBLE:
        {
            switch(op2.tipo){
                case INT:
                {
                    if(op1.valor.toDouble() <= op2.valor.toInt()){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case DOUBLE:
                {
                    if(op1.valor.toDouble() <= op2.valor.toDouble()){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case BOOL:
                {
                    if(op1.valor.toDouble() <= boolenao_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case CHAR:
                {
                    if(op1.valor.toDouble() <= char_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case STRING:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar con cadena");
                    return r;
                }

            }
        }
        case BOOL:
        {
            switch(op2.tipo){
                case INT:
                {
                    if(boolenao_to_int(op1.valor) <= op2.valor.toInt()){
                        r.flag = true;
                    }
                    r.tipo = BOOL;
                    r.valor = op1.valor;
                    return r;
                }
                case DOUBLE:
                {
                    if(boolenao_to_int(op1.valor) <= op2.valor.toDouble()){
                        r.flag = true;
                    }
                    r.tipo = BOOL;
                    r.valor = op1.valor;
                    return r;
                }
                case BOOL:
                {
                    if(boolenao_to_int(op1.valor) <= boolenao_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = BOOL;
                    r.valor = op1.valor;
                    return r;
                }
                case CHAR:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar booleano con caracter");
                    return r;
                }
                case STRING:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar booleano con cadena");
                    return r;
                }

            }
        }
        case CHAR:
        {
            switch(op2.tipo){
                case INT:
                {
                    if(char_to_int(op1.valor) <= op2.valor.toInt()){
                        r.flag = true;
                    }
                    r.tipo = CHAR;
                    r.valor = op1.valor;
                    return r;
                }
                case DOUBLE:
                {
                    if(char_to_int(op1.valor) <= op2.valor.toDouble()){
                        r.flag = true;
                    }
                    r.tipo = CHAR;
                    r.valor = op1.valor;
                    return r;
                }
                case BOOL:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar caracter con booleano");
                    return r;
                }
                case CHAR:
                {
                    if(char_to_int(op1.valor) <= char_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = CHAR;
                    r.valor = op1.valor;
                    return r;
                }
                case STRING:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar caracter con cadena");
                    return r;
                }

            }
        }
        case STRING:
        {
            insertarErrSem(op1.linea, op1.columna, "error semantico", "no se puede comparar cadena con otro tipo de dato");
            return r;
        }
            break;
        }
    }
        break;
    case MAYORIGUALQ:
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = op_logicaYrelacional(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = op_logicaYrelacional(&der);
        r.tipo_var = "booleano";
        switch(op1.tipo){
            case INT:
            {
                switch(op2.tipo){
                    case INT:
                    {
                        if(op1.valor.toInt() >= op2.valor.toInt()){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case DOUBLE:
                    {
                        if(op1.valor.toInt() >= op2.valor.toDouble()){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case BOOL:
                    {
                        if(op1.valor.toInt() >= boolenao_to_int(op2.valor)){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case CHAR:
                    {
                        if(op1.valor.toInt() >= char_to_int(op2.valor)){
                            r.flag = true;
                        }
                        r.tipo = INT;
                        r.valor = op1.valor;
                        return r;
                    }
                    case STRING:
                    {
                        insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar entero con cadena");
                        return r;
                    }

                }
            }
        case DOUBLE:
        {
            switch(op2.tipo){
                case INT:
                {
                    if(op1.valor.toDouble() >= op2.valor.toInt()){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case DOUBLE:
                {
                    if(op1.valor.toDouble() >= op2.valor.toDouble()){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case BOOL:
                {
                    if(op1.valor.toDouble() >= boolenao_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case CHAR:
                {
                    if(op1.valor.toDouble() >= char_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = DOUBLE;
                    r.valor = op1.valor;
                    return r;
                }
                case STRING:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar con cadena");
                    return r;
                }

            }
        }
        case BOOL:
        {
            switch(op2.tipo){
                case INT:
                {
                    if(boolenao_to_int(op1.valor) >= op2.valor.toInt()){
                        r.flag = true;
                    }
                    r.tipo = BOOL;
                    r.valor = op1.valor;
                    return r;
                }
                case DOUBLE:
                {
                    if(boolenao_to_int(op1.valor) >= op2.valor.toDouble()){
                        r.flag = true;
                    }
                    r.tipo = BOOL;
                    r.valor = op1.valor;
                    return r;
                }
                case BOOL:
                {
                    if(boolenao_to_int(op1.valor) >= boolenao_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = BOOL;
                    r.valor = op1.valor;
                    return r;
                }
                case CHAR:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar booleano con caracter");
                    return r;
                }
                case STRING:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar booleano con cadena");
                    return r;
                }

            }
        }
        case CHAR:
        {
            switch(op2.tipo){
                case INT:
                {
                    if(char_to_int(op1.valor) >= op2.valor.toInt()){
                        r.flag = true;
                    }
                    r.tipo = CHAR;
                    r.valor = op1.valor;
                    return r;
                }
                case DOUBLE:
                {
                    if(char_to_int(op1.valor) >= op2.valor.toDouble()){
                        r.flag = true;
                    }
                    r.tipo = CHAR;
                    r.valor = op1.valor;
                    return r;
                }
                case BOOL:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar caracter con booleano");
                    return r;
                }
                case CHAR:
                {
                    if(char_to_int(op1.valor) >= char_to_int(op2.valor)){
                        r.flag = true;
                    }
                    r.tipo = CHAR;
                    r.valor = op1.valor;
                    return r;
                }
                case STRING:
                {
                    insertarErrSem(op2.linea, op2.columna, "error semantico", "no se puede comparar caracter con cadena");
                    return r;
                }

            }
        }
        case STRING:
        {
            insertarErrSem(op1.linea, op1.columna, "error semantico", "no se puede comparar cadena con otro tipo de dato");
            return r;
        }
            break;
        }
    }
        break;

    /**********************************************************/
    /******         OPERADORES LOGICOS        ***************/
    case AND:
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = op_logicaYrelacional(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = op_logicaYrelacional(&der);
        r.tipo_var = "booleano";
        if(op1.flag && op2.flag){
            r.flag = true;
            r.valor = "true";
        }else{
            r.flag = false;
            r.valor = "false";
        }
            r.tipo = BOOL;
            return r;
    }
        break;
    case OR:
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = op_logicaYrelacional(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = op_logicaYrelacional(&der);
        r.tipo_var = "booleano";
        if(op1.flag || op2.flag){
            r.flag = true;
            r.valor = "true";
        }else{
            r.flag = false;
            r.valor = "false";
        }
            r.tipo = BOOL;
            return r;
    }
        break;
    case NOT:
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = op_logicaYrelacional(&iz);
        r.tipo_var = "booleano";
        if(op1.flag == false){
            r.flag = true;
            r.valor = "true";
        }else{
            r.flag = false;
            r.valor = "false";
        }
            r.tipo = BOOL;
            return r;
    }
        break;
    case NAND:
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = op_logicaYrelacional(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = op_logicaYrelacional(&der);
        r.tipo_var = "booleano";
        if(op1.flag && op2.flag){
            r.flag = false;
            r.valor = "false";
        }else{
            r.flag = true;
            r.valor = "true";
        }
            r.tipo = BOOL;
            return r;
    }
        break;
    case XOR:   /* funciona como NOR */
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = op_logicaYrelacional(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = op_logicaYrelacional(&der);
        r.tipo_var = "booleano";
        if(op1.flag || op2.flag){
            r.flag = false;
            r.valor = "false";
        }else{
            r.flag = true;
            r.valor = "true";
        }
            r.tipo = BOOL;
            return r;
    }
        break;

    /**********************************************************/
    /******         OPERADORES ARITMETICOS        ***************/
    case IDENTIFICADOR:
    {
        Resultado opa = op_artimetica(raiz);
        return opa;
    }
    case INT:
    {
        Resultado opa = op_artimetica(raiz);
        return opa;
    }
        break;
    case DOUBLE:
    {
            Resultado opa = op_artimetica(raiz);
            return opa;
    }
    break;
    case BOOL:
    {
        QString cadena = raiz->valor;
        std::string cad = cadena.toStdString();
        if(cad == "verdadero" || cad == "true"){
            r.flag = true;
        }
        r.tipo = BOOL;
        r.tipo_var = "booleano";
        r.valor = raiz->valor;
        r.linea = raiz->linea;
        r.columna = raiz->columna;
        return r;
    }
    break;
    case STRING:
        {
        Resultado opa = op_artimetica(raiz);
        return opa;
        }
        break;
    case CHAR:
        {
        Resultado opa = op_artimetica(raiz);
        return opa;
        }
        break;
    case SUMA:
        {
        Resultado opa = op_artimetica(raiz);
        return opa;
        }
        break;
    case RESTA:
        {
        Resultado opa = op_artimetica(raiz);
        return opa;
        }
        break;
    case MULTI:
        {
        Resultado opa = op_artimetica(raiz);
        return opa;
        }
        break;
    case DIV:
        {
        Resultado opa = op_artimetica(raiz);
        return opa;
        }
        break;
    case POTENCIA:
        {
        Resultado opa = op_artimetica(raiz);
        return opa;
        }
        break;
    case LLAMADA:
        {
        Resultado call = tercer_recorrdio(raiz);
        return call;
        }
        break;
    case ACCESO_OBJECT:
        {
            r = tercer_recorrdio(raiz);
        }
        break;
    case DATOS_VEC:
        {
            Resultado res = op_artimetica(raiz);
            return res;
        }
        break;
    return r;
    }
}

Resultado primerRecorrido:: op_artimetica( NodoAST *raiz)
{
    Resultado r = Resultado();
    r.linea = raiz->linea;          // Nos servirán para un posible reporte de error de tipos.
    r.columna = raiz->columna;
    switch(raiz->tipo_)
    {
        case ACCESO_OBJECT:
            {
                r = tercer_recorrdio(raiz);
            }
            break;
        case DATOS_VEC:
            {
                Resultado re = tercer_recorrdio(raiz);
                return re;
            }
            break;
        case IDENTIFICADOR:
            {
                r = buscar_id(raiz);
            }
            break;
        case INT:
            {
                r.tipo = INT;
                r.valor = raiz->valor;
                r.linea = raiz->linea;
                r.columna = raiz->columna;

            }
            break;
        case DOUBLE:
            {
                r.tipo = DOUBLE;
                r.valor = raiz->valor;
                r.linea = raiz->linea;
                r.columna = raiz->columna;
            }
            break;
        case BOOL:
        {
            r.tipo = BOOL;
            r.valor = raiz->valor;
            r.linea = raiz->linea;
            r.columna = raiz->columna;
        }
        break;
        case STRING:
            {
                r.tipo = STRING;
                r.valor = raiz->valor.replace("\"", "");
                r.linea = raiz->linea;
                r.columna = raiz->columna;
            }
            break;
        case CHAR:
            {
                r.tipo = CHAR;
                r.valor = raiz->valor.replace("\'", "");
                r.linea = raiz->linea;
                r.columna = raiz->columna;
            }
            break;
        case SUMA:
            {        
                NodoAST iz = raiz->hijos.at(0);
                Resultado op1 = op_artimetica(&iz);
                NodoAST der = raiz->hijos.at(1);
                Resultado op2 = op_artimetica(&der);
                switch (op1.tipo)
                {
                    case INT:
                        {
                            switch (op2.tipo)
                            {
                                case INT:
                                    {
                                        r.tipo = INT;
                                        int result = op1.valor.toInt() + op2.valor.toInt();
                                        r.valor = QString::number(result);
                                    }
                                    break;
                                case DOUBLE:
                                    {
                                        r.tipo = DOUBLE;
                                        double result = op1.valor.toDouble() + op2.valor.toDouble();
                                        r.valor = QString::number(result);
                                    }
                                    break;
                                case STRING:
                                    {
                                        r.tipo = STRING;
                                        r.valor = op1.valor + op2.valor;
                                    }
                                    break;
                                case BOOL:
                                    {
                                        r.tipo = INT;
                                        int result = op1.valor.toInt() + boolenao_to_int(op2.valor);
                                        r.valor = QString::number(result);
                                    }
                                    break;
                            case CHAR:
                                {
                                    r.tipo = INT;
                                    int result = op1.valor.toInt() + char_to_int(op2.valor);
                                    r.valor = QString::number(result);
                                }
                                break;
                                default:
                                    {
                                        /*Aqui debe ir el código para reportar el error de tipos*/
                                    }
                            }
                        }
                        break;
                        case DOUBLE:
                        {
                            switch (op2.tipo)
                            {
                                case INT:
                                    {
                                        r.tipo = DOUBLE;
                                        double result = op1.valor.toDouble() + op2.valor.toDouble();
                                        r.valor = QString::number(result);
                                    }
                                    break;
                                case DOUBLE:
                                    {
                                        r.tipo = DOUBLE;
                                        double result = op1.valor.toDouble() + op2.valor.toDouble();
                                        r.valor = QString::number(result);
                                    }
                                    break;
                                case STRING:
                                    {
                                        r.tipo = STRING;
                                        r.valor = op1.valor + op2.valor;
                                    }
                                    break;
                                case BOOL:
                                    {
                                        r.tipo = DOUBLE;
                                        double result = op1.valor.toDouble() +boolenao_to_int(op2.valor);
                                        r.valor = QString::number(result);
                                    }
                                    break;
                            case CHAR:
                                {
                                    r.tipo = DOUBLE;
                                    double result = op1.valor.toDouble() + char_to_int(op2.valor);
                                    r.valor = QString::number(result);
                                }
                                break;
                                default:
                                    {
                                        /*Aqui debe ir el código para reportar el error de tipos*/
                                    }
                                break;
                            }
                        }
                        break;
                    case STRING:
                        {
                            switch (op2.tipo)
                            {
                                case INT:
                                    {
                                        r.tipo = STRING;
                                        r.valor = op1.valor + op2.valor;
                                    }
                                    break;
                                case DOUBLE:
                                    {
                                        r.tipo = STRING;
                                        r.valor = op1.valor + op2.valor;
                                    }
                                    break;
                                case STRING:
                                    {
                                        r.tipo = STRING;
                                        r.valor = op1.valor + op2.valor;
                                    }
                                    break;
                                case BOOL:
                                    {
                                        /*error*/
                                        insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede sumar cadena con booleano");
                                    }
                                    break;
                                case CHAR:
                                    {
                                        r.tipo = STRING;
                                        r.valor = op1.valor + op2.valor;
                                    }
                                    break;
                                default:
                                    {
                                        /*Aqui debe ir el código para reportar el error de tipos*/
                                    }
                                    break;
                            }
                        }
                        break;
                    case BOOL:
                {
                    switch (op2.tipo)
                    {
                        case INT:
                            {
                                r.tipo =INT;
                                int result = boolenao_to_int(op1.valor) + op2.valor.toInt();
                                r.valor = QString::number(result);
                            }
                                break;
                        case DOUBLE:
                            {
                                r.tipo = DOUBLE;
                                double result = boolenao_to_int(op1.valor) + op2.valor.toDouble();
                                r.valor = QString::number(result);
                            }
                                break;
                        case STRING:
                            {
                                /*error*/
                                insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede sumar Boolenao con Cadena");
                            }
                            break;
                    case BOOL:
                        {
                            r.tipo = BOOL;
                            r.valor = metodo_or(op1.valor , op2.valor);
                        }
                        break;
                    case CHAR:
                        {
                            r.tipo =INT;
                            int result = boolenao_to_int(op1.valor) + char_to_int(op2.valor);
                            r.valor = QString::number(result);
                        }
                        break;
                        default:
                            {
                                /*Aqui debe ir el código para reportar el error de tipos*/
                            }
                        break;
                    }
                }
                        break;
                    case CHAR:
                        {
                            switch (op2.tipo)
                                {
                                    case INT:
                                        {
                                            r.tipo = INT;
                                            int result = char_to_int(op1.valor) + op2.valor.toInt();
                                            r.valor = QString::number(result);
                                        }
                                        break;
                                    case DOUBLE:
                                        {
                                            r.tipo = DOUBLE;
                                            double result = char_to_int(op1.valor) + op2.valor.toDouble();
                                            r.valor = QString::number(result);
                                        }
                                        break;
                                    case STRING:
                                        {
                                            r.tipo = STRING;
                                            r.valor = op1.valor + op2.valor;
                                        }
                                        break;
                                    case BOOL:
                                        {
                                            r.tipo = INT;
                                            int result = char_to_int(op1.valor) + boolenao_to_int(op2.valor);
                                            r.valor =  QString::number(result);
                                        }
                                        break;
                                    case CHAR:
                                        {
                                            r.tipo = INT;
                                            int result = char_to_int(op1.valor)+ char_to_int(op2.valor);
                                            r.valor = QString::number(result);
                                        }
                                        break;
                                    default:
                                        {
                                            /*Aqui debe ir el código para reportar el error de tipos*/
                                        }
                                        break;
                                }
                        }
                        break;
                    }
            }
            break;
        case RESTA:
            {
                if(raiz->hijos.size() == 2){
                    NodoAST iz = raiz->hijos.at(0);
                    Resultado op1 = op_artimetica(&iz);
                    NodoAST der = raiz->hijos.at(1);
                    Resultado op2 = op_artimetica(&der);
                    switch (op1.tipo)
                        {
                            case INT:
                                {
                                switch (op2.tipo)
                                {
                                case INT:
                                    {
                                        r.tipo = INT;
                                        int result = op1.valor.toInt() - op2.valor.toInt();
                                        r.valor = QString::number(result);
                                    }
                                    break;
                                case DOUBLE:
                                    {
                                        r.tipo = DOUBLE;
                                        double result = op1.valor.toDouble() - op2.valor.toDouble();
                                        r.valor = QString::number(result);
                                    }
                                    break;
                                case STRING:
                                    {
                                        /*error*/
                                        insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede restar Entero con Cadena");
                                    }
                                    break;
                                case BOOL:
                                    {
                                        r.tipo = INT;
                                        int result = op1.valor.toInt() - boolenao_to_int(op2.valor);
                                        r.valor = QString::number(result);
                                    }
                                    break;
                                case CHAR:
                                    {
                                        r.tipo = INT;
                                        int result = op1.valor.toInt() - char_to_int(op2.valor);
                                        r.valor = QString::number(result);
                                    }
                                    break;
                                default:
                                    {
                                        /*Aqui debe ir el código para reportar el error de tipos*/
                                    }
                                }
                            }
                            break;
                            case DOUBLE:
                        {
                            switch (op2.tipo)
                            {
                                case INT:
                                    {
                                        r.tipo = DOUBLE;
                                        double result = op1.valor.toDouble() - op2.valor.toDouble();
                                        r.valor = QString::number(result);
                                    }
                                    break;
                                case DOUBLE:
                                    {
                                        r.tipo = DOUBLE;
                                        double result = op1.valor.toDouble() - op2.valor.toDouble();
                                        r.valor = QString::number(result);
                                    }
                                    break;
                                case STRING:
                                    {
                                        /*error*/
                                        insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede restar Doble con Cadena");
                                    }
                                    break;
                                case BOOL:
                                    {
                                        r.tipo = DOUBLE;
                                        double result = op1.valor.toDouble() - boolenao_to_int(op2.valor);
                                        r.valor = QString::number(result);
                                    }
                                    break;
                            case CHAR:
                                {
                                    r.tipo = DOUBLE;
                                    double result = op1.valor.toDouble() - char_to_int(op2.valor);
                                    r.valor = QString::number(result);
                                }
                                default:
                                    {
                                        /*Aqui debe ir el código para reportar el error de tipos*/
                                    }
                                break;
                            }
                        }
                            break;
                            case STRING:
                        {
                            switch (op2.tipo)
                            {
                                case INT:
                                    {
                                        /*error*/
                                        insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede restar Cadena con Entero");
                                    }
                                    break;
                                case DOUBLE:
                                    {
                                        /*error*/
                                        insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede restar Cadena con Doble");
                                    }
                                    break;
                                case STRING:
                                    {
                                        /*error*/
                                        insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede restar Cadena con Cadena");
                                    }
                                    break;
                                case BOOL:
                                    {
                                        /*error*/
                                        insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede restar cadena con booleano");
                                    }
                                    break;
                                case CHAR:
                                    {
                                        /*error*/
                                        insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede restar Cadena con Caracter");
                                    }
                                    break;
                                default:
                                    {
                                        /*Aqui debe ir el código para reportar el error de tipos*/
                                    }
                                    break;
                            }
                        }
                            break;
                            case BOOL:
                {
                    switch (op2.tipo)
                    {
                        case INT:
                            {
                                r.tipo =INT;
                                int result = boolenao_to_int(op1.valor) - op2.valor.toInt();
                                r.valor = QString::number(result);
                            }
                                break;
                        case DOUBLE:
                            {
                                r.tipo = DOUBLE;
                                double result = boolenao_to_int(op1.valor) - op2.valor.toDouble();
                                r.valor = QString::number(result);
                            }
                                break;
                        case STRING:
                            {
                                /*error*/
                                insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede restar Boolenao con Cadena");
                            }
                            break;
                    case BOOL:
                        {
                            /*error*/
                            insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede restar Booleano con Booleano");
                        }
                        break;
                    case CHAR:
                        {
                            /*error*/
                            insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede restar Booleano con Caracter");
                        }
                        break;
                        default:
                            {
                                /*Aqui debe ir el código para reportar el error de tipos*/
                            }
                        break;
                    }
                }
                            break;
                            case CHAR:
                        {
                            switch (op2.tipo)
                                {
                                    case INT:
                                        {
                                            r.tipo = INT;
                                            int result = char_to_int(op1.valor) - op2.valor.toInt();
                                            r.valor = QString::number(result);
                                        }
                                        break;
                                    case DOUBLE:
                                        {
                                            r.tipo = DOUBLE;
                                            double result = char_to_int(op1.valor) - op2.valor.toDouble();
                                            r.valor = QString::number(result);
                                        }
                                        break;
                                    case STRING:
                                        {
                                            /*error*/
                                            insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede restar Caracter con cadena");
                                        }
                                        break;
                                    case BOOL:
                                        {
                                            /*error*/
                                            insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede restar Caracter con Booleano");
                                        }
                                        break;
                                    case CHAR:
                                        {
                                            r.tipo = INT;
                                            int result = char_to_int(op1.valor) - char_to_int(op2.valor);
                                            r.valor = QString::number(result);
                                        }
                                    default:
                                        {
                                            /*Aqui debe ir el código para reportar el error de tipos*/
                                        }
                                        break;
                                }
                        }
                            break;
                        }

                }else{
                    NodoAST iz = raiz->hijos.at(0);
                    Resultado op1 = op_artimetica(&iz);
                    if(INT == op1.tipo){
                        r.tipo = INT;
                        r.tipo_var = "entero";
                        int result = (-1)*op1.valor.toInt();
                        r.valor = QString::number(result);
                    }else if(DOUBLE == op1.tipo){
                        double result = (-1)*op1.valor.toDouble();
                        r.valor = QString::number(result);
                        r.tipo_var = "doble";
                        r.tipo = DOUBLE;
                    }else{
                        insertarErrSem(op1.linea, op1.columna, "error semantico: ", "el valor no debe ser negativo < "+op1.valor+" > ");
                    }
                }
            }
            break;
        case MULTI:
        {
            NodoAST iz = raiz->hijos.at(0);
            Resultado op1 = op_artimetica(&iz);
            NodoAST der = raiz->hijos.at(1);
            Resultado op2 = op_artimetica(&der);
            switch (op1.tipo)
                {
                    case INT:
                        {
                        switch (op2.tipo)
                        {
                        case INT:
                            {
                                r.tipo = INT;
                                int result = op1.valor.toInt() * op2.valor.toInt();
                                r.valor = QString::number(result);
                            }
                            break;
                        case DOUBLE:
                            {
                                r.tipo = DOUBLE;
                                double result = op1.valor.toDouble() * op2.valor.toDouble();
                                r.valor = QString::number(result);
                            }
                            break;
                        case STRING:
                            {
                                /*error*/
                                insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede multiplicar Entero con Cadena");
                            }
                            break;
                        case BOOL:
                            {
                                r.tipo = INT;
                                int result = op1.valor.toInt() * boolenao_to_int(op2.valor);
                                r.valor = QString::number(result);
                            }
                            break;
                        case CHAR:
                            {
                                r.tipo = INT;
                                int result = op1.valor.toInt() * char_to_int(op2.valor);
                                r.valor = QString::number(result);
                            }
                            break;
                        default:
                            {
                                /*Aqui debe ir el código para reportar el error de tipos*/
                            }
                        }
                    }
                    break;
                    case DOUBLE:
                {
                    switch (op2.tipo)
                    {
                        case INT:
                            {
                                r.tipo = DOUBLE;
                                double result = op1.valor.toDouble() * op2.valor.toDouble();
                                r.valor = QString::number(result);
                            }
                            break;
                        case DOUBLE:
                            {
                                r.tipo = DOUBLE;
                                double result = op1.valor.toDouble() * op2.valor.toDouble();
                                r.valor = QString::number(result);
                            }
                            break;
                        case STRING:
                            {
                                /*error*/
                                insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede multiplicar Doble con Cadena");
                            }
                            break;
                        case BOOL:
                            {
                                r.tipo = DOUBLE;
                                double result = op1.valor.toDouble() * boolenao_to_int(op2.valor);
                                r.valor = QString::number(result);
                            }
                            break;
                    case CHAR:
                        {
                            r.tipo = DOUBLE;
                            double result = op1.valor.toDouble() * char_to_int(op2.valor);
                            r.valor = QString::number(result);
                        }
                        break;
                        default:
                            {
                                /*Aqui debe ir el código para reportar el error de tipos*/
                            }
                        break;
                    }
                }
                    break;
                    case STRING:
                {
                    switch (op2.tipo)
                    {
                        case INT:
                            {
                                /*error*/
                                insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede multiplicar Cadena con Entero");
                            }
                            break;
                        case DOUBLE:
                            {
                                /*error*/
                                insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede multiplicar Cadena con Doble");
                            }
                            break;
                        case STRING:
                            {
                                /*error*/
                                insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede multiplicar Cadena con Cadena");
                            }
                            break;
                        case BOOL:
                            {
                                /*error*/
                                insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede multiplicar cadena con booleano");
                            }
                            break;
                        case CHAR:
                            {
                                /*error*/
                                insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede multiplicar Cadena con Caracter");
                            }
                            break;
                        default:
                            {
                                /*Aqui debe ir el código para reportar el error de tipos*/
                            }
                            break;
                    }
                }
                    break;
                    case BOOL:
        {
            switch (op2.tipo)
            {
                case INT:
                    {
                        r.tipo =INT;
                        int result = boolenao_to_int(op1.valor) * op2.valor.toInt();
                        r.valor = QString::number(result);
                    }
                        break;
                case DOUBLE:
                    {
                        r.tipo = DOUBLE;
                        double result = boolenao_to_int(op1.valor) * op2.valor.toDouble();
                        r.valor = QString::number(result);
                    }
                        break;
                case STRING:
                    {
                        /*error*/
                        insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede multiplicar Boolenao con Cadena");
                    }
                    break;
            case BOOL:
                {
                    r.tipo =BOOL;
                    r.valor = metodo_And(op1.valor, op2.valor);
                }
                break;
            case CHAR:
                {
                    r.tipo =INT;
                    int result = boolenao_to_int(op1.valor) * char_to_int(op2.valor);
                    r.valor = QString::number(result);
                }
                break;
                default:
                    {
                        /*Aqui debe ir el código para reportar el error de tipos*/
                    }
                break;
            }
        }
                    break;
                    case CHAR:
                {
                    switch (op2.tipo)
                        {
                            case INT:
                                {
                                    r.tipo = INT;
                                    int result = char_to_int(op1.valor) * op2.valor.toInt();
                                    r.valor = QString::number(result);
                                }
                                break;
                            case DOUBLE:
                                {
                                    r.tipo = DOUBLE;
                                    double result = char_to_int(op1.valor) * op2.valor.toDouble();
                                    r.valor = QString::number(result);
                                }
                                break;
                            case STRING:
                                {
                                    /*error*/
                                    insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede multiplicar Caracter con cadena");
                                }
                                break;
                            case BOOL:
                                {
                                    r.tipo = INT;
                                    int result = char_to_int(op1.valor) * boolenao_to_int(op2.valor);
                                    r.valor = QString::number(result);
                                }
                                break;
                            case CHAR:
                                {
                                    r.tipo = INT;
                                    int result = char_to_int(op1.valor) * char_to_int(op2.valor);
                                    r.valor = QString::number(result);
                                }
                            default:
                                {
                                    /*Aqui debe ir el código para reportar el error de tipos*/
                                }
                                break;
                        }
                }
                    break;
                }
        }
            break;
        case DIV:
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = op_artimetica(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = op_artimetica(&der);
        switch (op1.tipo)
            {
                case INT:
                    {
                    switch (op2.tipo)
                    {
                    case INT:
                        {
                            r.tipo = DOUBLE;
                            double result = 0.0;
                            if(diferente_cero(op2.valor)){
                                result = op1.valor.toDouble() / op2.valor.toDouble();
                                r.valor = QString::number(result);
                            }
                        }
                        break;
                    case DOUBLE:
                        {
                            r.tipo = DOUBLE;
                            double result = 0.0;
                            if(diferente_cero(op2.valor)){
                                result = op1.valor.toDouble() / op2.valor.toDouble();
                                r.valor = QString::number(result);
                            }
                        }
                        break;
                    case STRING:
                        {
                            /*error*/
                            insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede dividir Entero con Cadena");
                        }
                        break;
                    case BOOL:
                        {
                            r.tipo = INT;
                            QString val = QString::number(boolenao_to_int(op2.valor));
                            double result = 0.0;
                            if(diferente_cero(val)){
                                result = op1.valor.toDouble() / boolenao_to_int(op2.valor);
                                r.valor = QString::number(result);
                            }
                        }
                        break;
                    case CHAR:
                        {
                            r.tipo = DOUBLE;
                            double result = op1.valor.toDouble() / char_to_int(op2.valor);
                            r.valor = QString::number(result);
                        }
                        break;
                    default:
                        {
                            /*Aqui debe ir el código para reportar el error de tipos*/
                        }
                    }
                }
                break;
                case DOUBLE:
            {
                switch (op2.tipo)
                {
                    case INT:
                        {
                            r.tipo = DOUBLE;
                            double result = 0.0;
                            if(diferente_cero(op2.valor)){
                                result = op1.valor.toDouble() / op2.valor.toDouble();
                                r.valor = QString::number(result);
                            }
                        }
                        break;
                    case DOUBLE:
                        {
                            r.tipo = DOUBLE;
                            double result = 0.0;
                            if(diferente_cero(op2.valor)){
                                result = op1.valor.toDouble() / op2.valor.toDouble();
                                r.valor = QString::number(result);
                            }
                        }
                        break;
                    case STRING:
                        {
                            /*error*/
                            insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede dividir Doble con Cadena");
                        }
                        break;
                    case BOOL:
                        {
                            r.tipo = DOUBLE;
                            QString val = QString::number(boolenao_to_int(op2.valor));
                            double result = 0.0;
                            if(diferente_cero(val)){
                                result = op1.valor.toDouble() / boolenao_to_int(op2.valor);
                                r.valor = QString::number(result);
                            }
                        }
                        break;
                case CHAR:
                    {
                        r.tipo = DOUBLE;
                        double result = op1.valor.toDouble() / char_to_int(op2.valor);
                        r.valor = QString::number(result);
                    }
                    break;
                    default:
                        {
                            /*Aqui debe ir el código para reportar el error de tipos*/
                        }
                    break;
                }
            }
                break;
                case STRING:
            {
                switch (op2.tipo)
                {
                    case INT:
                        {
                            /*error*/
                            insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede dividir Cadena con Entero");
                        }
                        break;
                    case DOUBLE:
                        {
                            /*error*/
                            insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede dividir Cadena con Doble");
                        }
                        break;
                    case STRING:
                        {
                            /*error*/
                            insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede dividir Cadena con Cadena");
                        }
                        break;
                    case BOOL:
                        {
                            /*error*/
                            insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede dividir cadena con booleano");
                        }
                        break;
                    case CHAR:
                        {
                            /*error*/
                            insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede dividir Cadena con Caracter");
                        }
                        break;
                    default:
                        {
                            /*Aqui debe ir el código para reportar el error de tipos*/
                        }
                        break;
                }
            }
                break;
                case BOOL:
    {
        switch (op2.tipo)
        {
            case INT:
                {
                    r.tipo = DOUBLE;
                    double result = 0.0;
                    if(diferente_cero(op2.valor)){
                        result = (double)boolenao_to_int(op1.valor) / op2.valor.toDouble();
                        r.valor = QString::number(result);
                    }
                }
                    break;
            case DOUBLE:
                {
                    r.tipo = DOUBLE;
                    double result = 0.0;
                    if(diferente_cero(op2.valor)){
                        result = (double)boolenao_to_int(op1.valor) / op2.valor.toDouble();
                        r.valor = QString::number(result);
                    }
                }
                    break;
            case STRING:
                {
                    /*error*/
                    insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede dividir Boolenao con Cadena");
                }
                break;
        case BOOL:
            {
                /*error*/
                insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede dividir Boolenao entre Booleano");
            }
            break;
        case CHAR:
            {
                r.tipo = DOUBLE;
                double result = (double)boolenao_to_int(op1.valor) / (double)char_to_int(op2.valor);
                r.valor = QString::number(result);
            }
            break;
            default:
                {
                    /*Aqui debe ir el código para reportar el error de tipos*/
                }
            break;
        }
    }
                break;
                case CHAR:
            {
                switch (op2.tipo)
                    {
                        case INT:
                            {
                                r.tipo = DOUBLE;
                                double result = 0.0;
                                if(diferente_cero(op2.valor)){
                                    result = (double)char_to_int(op1.valor) / op2.valor.toDouble();
                                    r.valor = QString::number(result);
                                }
                            }
                            break;
                        case DOUBLE:
                            {
                                r.tipo = DOUBLE;
                                double result = 0.0;
                                if(diferente_cero(op2.valor)){
                                    result = (double)char_to_int(op1.valor) / op2.valor.toDouble();
                                r.valor = QString::number(result);
                                }
                            }
                            break;
                        case STRING:
                            {
                                /*error*/
                                insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede dividir Caracter con cadena");
                            }
                            break;
                        case BOOL:
                            {
                                r.tipo = INT;
                                QString val = QString::number(boolenao_to_int(op2.valor));
                                double result = 0.0;
                                if(diferente_cero(val)){
                                    result = (double)char_to_int(op1.valor)/ boolenao_to_int(op2.valor);
                                    r.valor = QString::number(result);
                                }
                            }
                            break;
                        case CHAR:
                            {
                                r.tipo = DOUBLE;
                                double result = (double)char_to_int(op1.valor) / (double)char_to_int(op2.valor);
                                r.valor = QString::number(result);
                            }
                        default:
                            {
                                /*Aqui debe ir el código para reportar el error de tipos*/
                            }
                            break;
                    }
            }
                break;
            }
    }
            break;
        case POTENCIA:
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = op_artimetica(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = op_artimetica(&der);
        switch (op1.tipo)
            {
                case INT:
                    {
                    switch (op2.tipo)
                    {
                    case INT:
                        {
                            r.tipo = INT;
                            double result = pow(op1.valor.toDouble(), op2.valor.toDouble());
                            r.valor = QString::number(result);
                        }
                        break;
                    case DOUBLE:
                        {
                            r.tipo = DOUBLE;
                            double result = pow(op1.valor.toDouble(), op2.valor.toDouble());
                            r.valor = QString::number(result);
                        }
                        break;
                    case STRING:
                        {
                            /*error*/
                            insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede potenciar Entero con Cadena");
                        }
                        break;
                    case BOOL:
                        {
                            r.tipo = INT;
                            int result = pow(op1.valor.toInt(), boolenao_to_int(op2.valor));
                            r.valor = QString::number(result);
                        }
                        break;
                    case CHAR:
                        {
                            r.tipo = INT;
                            double result = pow(op1.valor.toDouble(), (double)(char_to_int(op2.valor))*1);
                            r.valor = QString::number(result);
                        }
                        break;
                    default:
                        {
                            /*Aqui debe ir el código para reportar el error de tipos*/
                        }
                    }
                }
                break;
                case DOUBLE:
            {
                switch (op2.tipo)
                {
                    case INT:
                        {
                            r.tipo = DOUBLE;
                            double result = pow(op1.valor.toDouble(), op2.valor.toDouble());
                            r.valor = QString::number(result);
                        }
                        break;
                    case DOUBLE:
                        {
                            r.tipo = DOUBLE;
                            double result = pow(op1.valor.toDouble(), op2.valor.toDouble());
                            r.valor = QString::number(result);
                        }
                        break;
                    case STRING:
                        {
                            /*error*/
                            insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede potenciar Doble con Cadena");
                        }
                        break;
                    case BOOL:
                        {
                            r.tipo = DOUBLE;
                            double result = pow(op1.valor.toDouble(), (double)boolenao_to_int(op2.valor));
                            r.valor = QString::number(result);
                        }
                        break;
                case CHAR:
                    {
                        r.tipo = DOUBLE;
                        double result = pow(op1.valor.toDouble(), (double)(char_to_int(op2.valor))*1);
                        r.valor = QString::number(result);
                    }
                    break;
                    default:
                        {
                            /*Aqui debe ir el código para reportar el error de tipos*/
                        }
                    break;
                }
            }
                break;
                case STRING:
            {
                switch (op2.tipo)
                {
                    case INT:
                        {
                            /*error*/
                            insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede potenciar Cadena con Entero");
                        }
                        break;
                    case DOUBLE:
                        {
                            /*error*/
                            insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede potenciar Cadena con Doble");
                        }
                        break;
                    case STRING:
                        {
                            /*error*/
                            insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede potenciar Cadena con Cadena");
                        }
                        break;
                    case BOOL:
                        {
                            /*error*/
                            insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede potenciar cadena con booleano");
                        }
                        break;
                    case CHAR:
                        {
                            /*error*/
                            insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede potenciar Cadena con Caracter");
                        }
                        break;
                    default:
                        {
                            /*Aqui debe ir el código para reportar el error de tipos*/
                        }
                        break;
                }
            }
                break;
                case BOOL:
    {
        switch (op2.tipo)
        {
            case INT:
                {
                    r.tipo =INT;
                    int result = pow(boolenao_to_int(op1.valor), op2.valor.toInt());
                    r.valor = QString::number(result);
                }
                    break;
            case DOUBLE:
                {
                    r.tipo = DOUBLE;
                    double result = pow(boolenao_to_int(op1.valor), op2.valor.toDouble());
                    r.valor = QString::number(result);
                }
                    break;
            case STRING:
                {
                    /*error*/
                    insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede potenciar Boolenao con Cadena");
                }
                break;
        case BOOL:
            {
                /*error*/
                insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede potenciar Booleanos entre si");
            }
            break;
        case CHAR:
            {
                r.tipo =INT;
                int result = pow(boolenao_to_int(op1.valor) , char_to_int(op2.valor));
                r.valor = QString::number(result);
            }
            break;
            default:
                {
                    /*Aqui debe ir el código para reportar el error de tipos*/
                }
            break;
        }
    }
                break;
                case CHAR:
            {
                switch (op2.tipo)
                    {
                        case INT:
                            {
                                r.tipo = INT;
                                double result = pow(char_to_int(op1.valor), op2.valor.toInt());
                                r.valor = QString::number(result);
                            }
                            break;
                        case DOUBLE:
                            {
                                r.tipo = DOUBLE;
                                double result = pow((double)(char_to_int(op1.valor)), op2.valor.toDouble());
                                r.valor = QString::number(result);
                            }
                            break;
                        case STRING:
                            {
                                /*error*/
                                insertarErrSem(op1.linea, op1.columna, "Error semantico", "no se puede potenciar Caracter con cadena");
                            }
                            break;
                        case BOOL:
                            {
                                r.tipo = INT;
                                int result = pow(char_to_int(op1.valor), boolenao_to_int(op2.valor));
                                r.valor = QString::number(result);
                            }
                            break;
                        case CHAR:
                            {
                                r.tipo = INT;
                                double result = pow(char_to_int(op1.valor) , char_to_int(op2.valor));
                                r.valor = QString::number(result);
                            }
                        default:
                            {
                                /*Aqui debe ir el código para reportar el error de tipos*/
                            }
                            break;
                    }
            }
                break;
            }
    }
            break;
        default:
        {
            r = op_logicaYrelacional(raiz);
        }
            break;

    }

    switch (r.tipo) {
    case INT:
        r.tipo_var = "entero";
        break;
    case DOUBLE:
        r.tipo_var = "doble";
        break;
    case STRING:
        r.tipo_var = "cadena";
        break;
    case CHAR:
        r.tipo_var = "caracter";
        break;
    case BOOL:
        r.tipo_var = "booleano";
        if(r.valor == "true"){
            r.flag = true;
        }else{
            r.flag = false;
        }
        break;
    }

    return r;
}

Resultado primerRecorrido:: buscar_id (NodoAST *raiz){
    Resultado r = Resultado();
    bool flag = true;
    /*busca el id en la lista de variables locales */
    for(int x = Vlocal.length()-1; x >=0 ; x--){
        /*busca el id solo dentro del metodo*/
        if("FUNCION" == Vlocal[x].rol){
            break;  /* deja de buscar el id dentro del metodo o funcion */
        }

        if(raiz->valor == Vlocal[x].id){

            if("objeto" == Vlocal[x].rol){/*busca el nodo guardado en lsa varibles locales*/
                r.nodo = Vlocal[x].raiz;
                r.tipo_var = Vlocal[x].tipo;
                r.valor = Vlocal[x].id;
                return r;
                break;
            }
            if("arreglo" != Vlocal[x].rol){
                flag = false;
                if(Vlocal[x].tipo.toLower() == "entero"){
                    r.tipo = INT;
                }else if(Vlocal[x].tipo.toLower() == "doble"){
                    r.tipo = DOUBLE;
                }else if(Vlocal[x].tipo.toLower() == "cadena"){
                    r.tipo = STRING;
                }else if(Vlocal[x].tipo.toLower() == "caracter"){
                    r.tipo = CHAR;
                }else if(Vlocal[x].tipo.toLower() == "booleano"){
                    r.tipo = BOOL;
                }
                r.valor = Vlocal[x].valor;
                r.linea = Vlocal[x].linea;
                r.columna = Vlocal[x].columna;
                break;
            }
            break;
        }
    }
    /*busca el id en la lista de variables globaels*/
    if(flag){
        for(int x = Vglobal.length()-1; x >=0 ; x--){
            if(raiz->valor == Vglobal[x].id){

                flag = false;
                if("arreglo" != Vglobal[x].rol){
                    if(Vglobal[x].tipo.toLower() == "entero"){
                        r.tipo = INT;
                    }else if(Vglobal[x].tipo.toLower() == "doble"){
                        r.tipo = DOUBLE;
                    }else if(Vglobal[x].tipo.toLower() == "cadena"){
                        r.tipo = STRING;
                    }else if(Vglobal[x].tipo.toLower() == "caracter"){
                        r.tipo = CHAR;
                    }else if(Vglobal[x].tipo.toLower() == "booleano"){
                        r.tipo = BOOL;
                    }
                    r.valor = Vglobal[x].valor;
                    r.linea = Vglobal[x].linea;
                    r.columna = Vglobal[x].columna;
                    break;
                }
                break;
            }
        }
    }
    /*buscas el id en la lista de objetos*/
    if(flag){

        r = existe_objeto(raiz->valor, raiz->linea);
        flag = !r.flag;
    }

    /*si no existe el id entonces arroja un error en consola*/
    if(flag){
        insertarErrSem(raiz->linea, raiz->columna, "error semantico", "la variable: " +raiz->valor + " no se ha declarado");
    }

    return r;
}

void primerRecorrido:: metodo_principla (){
    int contador = 0;
    NodoAST *nodo;
    bool salir = false;
    for(int x = 0; x < misClases.length(); x++){
        std::cout<<endl<<misClases[x].idClase.toStdString();
        misFunciones.clear();
        Vglobal.clear();
        segundo_recorrdio(&misClases[x].NodoClase);
        for(int y = 0; y < misFunciones.size(); y++){
            if("principal" == misFunciones[y].id.toLower()){
                contador++;
                nodo = &misFunciones[y].raiz;
                salir = true;
                break;
            }
        }
        if(salir){
            break;
        }
    }


    if(contador == 1){
        tercer_recorrdio(nodo);

        cout<<"No. elementos en la lsita: "<<Vlocal.size()<<endl;
    }else if(contador == 0){
        insertarErrSem(0, 0 , "error semantico", "no existe el metodo < principal > DEBE CREAR EL METODO");
    }else{
        insertarErrSem(0, 0 , "error semantico", "no debe existir varias veces el metodo < principal >");
    }
}

Resultado primerRecorrido:: buscar_metod_function (QString id, QList<tabla_Var_local> parametros){
    Resultado r = Resultado();
    bool exist_function = false;
    bool equal_parametro = false;
    bool equal_type = false;

    for (int fun = misFunciones.size()-1; fun >= 0; fun--) { /*ejecutar la lista de funciones*/
        if(id == misFunciones[fun].id){ /*verificar si existe la funcion */
            exist_function = true;
            tipo_funcion = misFunciones[fun].tipo;
            if(parametros.length() == misFunciones[fun].misParametros.length()){ /*si los parametros tienen la misma dimencion*/
                equal_parametro = true;
                insert_entorno(misFunciones[fun].linea, misFunciones[fun].columna, "FUNCION", misFunciones[fun].visibilidad, misFunciones[fun].tipo, id);
                for(int pa = 0; pa < misFunciones[fun].misParametros.length(); pa++){ /*recorrer parametros de la funcion*/
                    if(parametros[pa].tipo == misFunciones[fun].misParametros[pa].tipo){/*verificar el tipo de parametros*/
                        equal_type  = true;

                        QString  tipovar = misFunciones[fun].misParametros[pa].tipo;
                        if(tipovar == "entero" || tipovar == "doble" || tipovar == "cadena" || tipovar == "caracter" || tipovar == "arreglo"){
                            struct tabla_Var_local tmp;
                            tmp.linea = misFunciones[fun].misParametros[pa].linea;
                            tmp.columna = misFunciones[fun].misParametros[pa].columna;
                            tmp.rol = "varaible";
                            tmp.valor = parametros[pa].valor;
                            tmp.id = misFunciones[fun].misParametros[pa].id;
                            tmp.tipo = misFunciones[fun].misParametros[pa].tipo;
                            Vlocal.append(tmp);
                        }else{
                            struct tabla_clase aux;
                            aux.linea = misFunciones[fun].misParametros[pa].linea;
                            aux.columna = misFunciones[fun].misParametros[pa].columna;
                            aux.idClase = misFunciones[fun].misParametros[pa].id;
                            aux.tipo = parametros[pa].tipo;
                            aux.NodoClase = existe_objeto(parametros[pa].valor, misFunciones[fun].misParametros[pa].linea).nodo;
                            objetos.append(aux);
                        }



                        //Tabla_simbolo.append(tmp);
                    }
                    if(!equal_type){
                        insertarErrSem(misFunciones[fun].misParametros[pa].linea,misFunciones[fun].misParametros[pa].columna, "error semantico: ", "los parametros de la funcion < "+id+" > no son del mismo tipo");
                    }
                }
                if(!equal_parametro){
                    insertarErrSem(0,0, "error semantico: ", " la lista de parametros de la funcion < "+id+" > no coinciden, elimine o agrue mas parametros");
                }
                misParametro.clear();
                if(misFunciones[fun].tipo == "void"){
                    tercer_recorrdio(&misFunciones[fun].raiz);
                    if(flag_retornar){
                        insertarErrSem(0,0, "error semantico: ", " el metodo < "+id+" > no puede tener rotorno");
                    }
                    flag_retornar = false;
                    //tipo_funcion = "";
                }else{
                    r = tercer_recorrdio(&misFunciones[fun].raiz);
                    flag_retornar = false;
                    //tipo_funcion = "";
                }

                entorno("FUNCION");
                break;
            }
            break;
        }
    }

    if(!exist_function){
        insertarErrSem(0,0, "error semantico: ", "la funcion < "+id+" > no existe");
    }
    return miRetorno;
}

void primerRecorrido:: limpiar_listas(){
    /*para vaciar memoria*/
    misFunciones.clear();
    esemantico.clear();
    Vglobal.clear();
    Vlocal.clear();
    Tabla_simbolo.clear();
    misParametro.clear();
    misClases.clear();
    objetos.clear();
    notificacion.clear();
    /*fin del vaciado*/
}

/*verifica si existe el ID de la clase a instanciar*/
Resultado primerRecorrido:: existe_clase(QString id, int linea){
    Resultado r = Resultado();
    for(int x = 0; x < misClases.length(); x++){
        if(id == misClases[x].idClase){
            r.nodo = misClases[x].NodoClase;
            r.flag = true;
            return r;
        }
    }
    insertarErrSem(linea, 0, "error semantico", "la clase < "+id+" > no existe");
    return r;
}

/*busca el objeto y lo retorna*/
Resultado primerRecorrido:: existe_objeto(QString id, int linea){
    Resultado r = Resultado();
    for(int x = 0; x < objetos.length(); x++){
        if(id == objetos[x].idClase){
            r.nodo = objetos[x].NodoClase;
            r.valor = objetos[x].idClase;
            r.tipo_var = objetos[x].tipo;
            r.flag = true;
            return r;
        }
    }
    insertarErrSem(linea, 0, "error semantico", " el objeto < "+id+" > no se ha instanciado");
    return r;
}

void primerRecorrido:: entorno(QString cadena){
    for(int x = Vlocal.size()-1; x >= 0; x--){
        if(cadena == Vlocal[x].rol){
            Vlocal.removeAt(x);
            break;
        }
        Vlocal.removeAt(x);
    }
}

void primerRecorrido:: insert_entorno(int linea, int columna, QString rol, QString visibilidad, QString tipo, QString id){
    struct tabla_Var_local aux;
    aux.linea = linea;
    aux.columna = columna;
    aux.rol = rol;
    aux.visibilidad = visibilidad;
    aux.tipo = tipo;
    aux.id = id;
    //Tabla_simbolo.append(aux);
    Vlocal.append(aux);
}

/*inserta entorno en la lista de variables globales*/
void primerRecorrido:: insert_entorno_global(int linea, int columna, QString rol, QString visibilidad, QString tipo, QString id){
    struct tabla_Var_local aux;
    aux.linea = linea;
    aux.columna = columna;
    aux.rol = rol;
    aux.visibilidad = visibilidad;
    aux.tipo = tipo;
    aux.id = id;
    //Tabla_simbolo.append(aux);
    Vglobal.append(aux);

    static tabla_met_fun tmp;
    tmp.tipo = rol;
    misFunciones.append(tmp);
}

/* elimina entorno de las variables globales*/
void primerRecorrido:: entorno_global(QString cadena){
    for(int x = Vglobal.size()-1; x >= 0; x--){
        if(cadena == Vglobal[x].rol){
            Vglobal.removeAt(x);
            break;
        }
        Vglobal.removeAt(x);
    }
    /*elimina tambien las funciones*/
    for(int x = misFunciones.size()-1; x >= 0; x--){
        if(cadena == misFunciones[x].tipo){
            misFunciones.removeAt(x);
            break;
        }
        misFunciones.removeAt(x);
    }
}

void primerRecorrido:: insert_aument_decremet(QString id, QString valor){
    for(int x = Vlocal.size()-1; x >=0; x--){
        if(id == Vlocal[x].id){
            Vlocal[x].valor = valor;
            break;
        }
    }
}


Resultado primerRecorrido::reasignar_valores_clase_global(QString id_objeto, QString idVar, Resultado misOperaciones){
   Resultado r = Resultado();
    /*asigna nuevo valor a variables de la clase */
    for(int x = 0; x < objetos.length(); x++){
        if(id_objeto == objetos[x].idClase){
            for (int var = 0; var < objetos[x].NodoClase.hijos.length(); ++var) {
                if(objetos[x].NodoClase.hijos[var].tipo == "VAR_DECLARACION"){
                    if(objetos[x].NodoClase.hijos[var].hijos[0].valor.toLower() != "arreglo" ){
                        if(objetos[x].NodoClase.hijos[var].hijos[1].hijos[0].hijos[0].valor == idVar){
                            /*si la operacion es booleana*/
                            if(misOperaciones.tipo_var == "booleano"){
                                if(misOperaciones.flag){
                                    NodoAST *nodo = new NodoAST(misOperaciones.linea, misOperaciones.columna, "booleano", "true");
                                    objetos[x].NodoClase.hijos[var].add(*nodo);
                                }else{
                                    NodoAST *nodo = new NodoAST(misOperaciones.linea, misOperaciones.columna, "booleano", "false");
                                    objetos[x].NodoClase.hijos[var].add(*nodo);
                                }
                            }else{
                                NodoAST *nodo = new NodoAST(misOperaciones.linea, misOperaciones.columna, misOperaciones.tipo_var, misOperaciones.valor);
                                objetos[x].NodoClase.hijos[var].add(*nodo);
                            }
                            std::cout<<endl<<" tiene que servir perro "<<objetos[x].NodoClase.hijos[var].hijos[2].valor.toStdString()<<"  exelente \n";
                            id_objeto = "";
                            break;
                        }
                    }

                }
            }
            break;
        }
    }
    return r;
}


void primerRecorrido::bool_to_false(){

    for(int x = misClases.size()-1; x >= 0; x--){
            for (int var = misClases[x].NodoClase.hijos.size() -1; var >=0 ; var--) {
                    if(misClases[x].NodoClase.hijos[var].tipo == "VAR_DECLARACION"){
                        if(misClases[x].NodoClase.hijos[var].hijos[0].valor.toLower() == "booleano" ){

                                    NodoAST *nodo = new NodoAST(misClases[x].NodoClase.hijos[var].hijos[0].linea, misClases[x].NodoClase.hijos[var].hijos[0].columna, "booleano", "false");
                                    misClases[x].NodoClase.hijos[var].add(*nodo);

                                    std::cout<<endl<<"sirve perro "<<misClases[x].NodoClase.hijos[var].hijos[2].valor.toStdString()<<"  \n";
                        }

                    }
            }

    }
}
