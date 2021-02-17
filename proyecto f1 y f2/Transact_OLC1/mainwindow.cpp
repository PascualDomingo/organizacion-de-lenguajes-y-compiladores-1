#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qstring.h>
#include <qdebug.h>
#include <parser.h>  // Nuestro parser
#include <scanner.h>  // Nuestro scanner
#include <NodoAST.h>   //Nuestra clase nodo
#include <graficador.h> // Graficador
#include <primerrecorrido.h>
#include <QLinkedList>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

extern int yyparse(); //
extern NodoAST *raiz; // Raiz del arbol
extern int linea; // Linea del token
extern int columna; // Columna de los tokens
extern int yylineno;

/*Instanciamos nuestro interprete y le enviamos nuestro arbol para ejecutarse.*/
primerRecorrido * interprete = new primerRecorrido();


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionejecutar_triggered()
{
    interprete->limpiar_listas(); // se envia para que elimine todas las listas llenas
    QString programa = ui->txtEditor->toPlainText();
    YY_BUFFER_STATE buffer = yy_scan_string(programa.toUtf8().constData());

        /*Limpiamos los contadores
        ya que son variables globales*/
        linea = 0;
        columna = 0;
        yylineno = 0;

        if(yyparse()==0) // Si nos da un número negativo, signifca error.
        {
            /*Instanciamos un graficador y graficamos */
            graficador *graf = new graficador(raiz);
            graf->generarImagen();
            /*inicio comentcion*/
           // interprete->bool_to_false(raiz); /*convierte todas las vareables boolenas golbales en FALSO*/
            interprete->primer_recorrdio(raiz); /* se ejecutara la funcion de primer recorrido para guardar mis clases*/
            //interprete->segundo_recorrdio(raiz); //se envia el arbol para ejecurar y guardar metodos y variables globales
            interprete->metodo_principla(); //se envia el arbol para ejecurar el metodo principal
            ui->txtConsola->setPlainText(interprete->resultado);
            int var = interprete->esemantico.length();
            QString salida = ""; //imprimirerror semantico
            for(int i=0; i< interprete->esemantico.length(); i++){
                salida += "linea: "+QString::number((interprete->esemantico).at(i).linea) +", "+"columna: "+QString::number((interprete->esemantico).at(i).columna)+", "+(interprete->esemantico).at(i).tipo+", " +(interprete->esemantico).at(i).detalle+"\n";
            }
            if(salida != ""){
                ui->txtConsola->setPlainText(salida);
            }
            /*fin comentacion */
            metodo_tabla();
            interprete->resultado = "";
        }

        mostar_notificacion();
}

void MainWindow::on_tabla_simbolo_tabBarClicked(int index)
{
    metodo_tabla();
}

void MainWindow::metodo_tabla(){
    ui->tblVariables->setRowCount(0);//limpia todas las filas de la tabla
    QStringList cabecera;
    ui->tblVariables->setColumnCount(7);
    //cabecera de la tabla
    cabecera <<"linea"<<"columna"<<"rol"<<"visibilidad"<<"tipo"<<"identificador"<<"valor";
    ui->tblVariables->setHorizontalHeaderLabels(cabecera); //cabecera de la tabla

    ui->tblVariables->setColumnWidth(0,80); //tamanio de celda
    ui->tblVariables->setColumnWidth(1,80);
    ui->tblVariables->setColumnWidth(2,150);
    ui->tblVariables->setColumnWidth(3,150);
    ui->tblVariables->setColumnWidth(4,150);
    ui->tblVariables->setColumnWidth(5,250);
    ui->tblVariables->setColumnWidth(6,250);

    //insertar elemento en la tabla

    int col1;
    int col2;
    for(int i=0; i< interprete->Tabla_simbolo.length(); i++){
        col1 = (interprete->Tabla_simbolo).at(i).linea;
        col2 = (interprete->Tabla_simbolo).at(i).columna;
        QString qs1 = QString::number(col1); //parsea int a qstring
        QString qs2 = QString::number(col2);
        QString qs3 = (interprete->Tabla_simbolo).at(i).rol;
        QString qs4 = (interprete->Tabla_simbolo).at(i).visibilidad;
        QString qs5 = (interprete->Tabla_simbolo).at(i).tipo;
        QString qs6 = (interprete->Tabla_simbolo).at(i).id;
        QString qs7 = (interprete->Tabla_simbolo).at(i).valor;

        ui->tblVariables->insertRow(ui->tblVariables->rowCount());
        ui->tblVariables->setItem(ui->tblVariables->rowCount()-1, 0, new QTableWidgetItem(qs1));
        ui->tblVariables->setItem(ui->tblVariables->rowCount()-1, 1, new QTableWidgetItem(qs2));
        ui->tblVariables->setItem(ui->tblVariables->rowCount()-1, 2, new QTableWidgetItem(qs3));
        ui->tblVariables->setItem(ui->tblVariables->rowCount()-1, 3, new QTableWidgetItem(qs4));
        ui->tblVariables->setItem(ui->tblVariables->rowCount()-1, 4, new QTableWidgetItem(qs5));
        ui->tblVariables->setItem(ui->tblVariables->rowCount()-1, 5, new QTableWidgetItem(qs6));
        ui->tblVariables->setItem(ui->tblVariables->rowCount()-1, 6, new QTableWidgetItem(qs7));
    }

}

void MainWindow::on_actionabrir_triggered()
{
    QString nombreArchivo = QFileDialog::getOpenFileName(
                        this,
                        "KUINN - Open file",
                        "Documents",
                        "Text Files (*.tr);;All files(*,*)");

            if(!nombreArchivo.isEmpty()){
                QFile file(nombreArchivo);
                if(file.open(QFile::ReadOnly)){
                    curFile = nombreArchivo;
                    ui->txtEditor->setPlainText(file.readAll());
                }else{
                    QMessageBox::warning(
                                this,
                                "KUINN",
                                tr("no se pudo abrir el archivo %1.\nError: %2")
                                .arg(nombreArchivo)
                                .arg(file.errorString())
                                );
                }
            }
}

void MainWindow::on_actioncrear_triggered()
{
    on_actionguardar_triggered();
        ui->txtEditor->setPlainText("");
        curFile = "";
}

void MainWindow::on_actionguardar_como_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                    this,
                    "KUINN - Save as",
                    "Documents",
                    "Text Files (*.fi);;All files(*,*)");

        if(!nombreArchivo.isEmpty()){
            curFile = nombreArchivo;
            guardar_archivo();

        }
}

void MainWindow::guardar_archivo(){
    QFile file(curFile);
    if(file.open(QFile::WriteOnly)){
        file.write(ui->txtEditor->toPlainText().toUtf8());
    }else{
        QMessageBox::warning(this,
                             "Home",
                             tr("no se puede escribir el archivo %1.\nError: %2")
                             .arg(curFile)
                             .arg(file.errorString()));
    }
}

void MainWindow::on_actionguardar_triggered()
{
    if(curFile.isEmpty()){
            on_actionguardar_como_triggered();
        }else{
            guardar_archivo();
        }
}

void MainWindow::mostar_notificacion(){
    for(int i = 0; i< interprete->notificacion.length(); i++){
        QMessageBox::information(this, interprete->notificacion.at(i).titulo+"     ", interprete->notificacion.at(i).mensaje);
    }
}
