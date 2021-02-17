#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionejecutar_triggered();

    void on_tabla_simbolo_tabBarClicked(int index);

    void metodo_tabla();

    void on_actionabrir_triggered();

    void on_actioncrear_triggered();

    void on_actionguardar_como_triggered();

    void on_actionguardar_triggered();

    //void on_actionAST_triggered();

private:
    Ui::MainWindow *ui;
    QString curFile;
    void guardar_archivo();
    void crear_archivo();
    void mostar_notificacion();
};

#endif // MAINWINDOW_H
