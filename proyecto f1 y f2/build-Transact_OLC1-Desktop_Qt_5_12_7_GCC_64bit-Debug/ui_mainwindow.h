/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actioncrear;
    QAction *actionabrir;
    QAction *actionguardar;
    QAction *actionguardar_como;
    QAction *actioncrear_pesta_a;
    QAction *actioneliminar_pesta_a;
    QAction *actionerror_lexico;
    QAction *actionerror_sintactico;
    QAction *actionerror_semantico;
    QAction *actionAST;
    QAction *actionejecutar;
    QWidget *centralWidget;
    QTabWidget *tabla_simbolo;
    QWidget *tab;
    QPlainTextEdit *txtConsola;
    QWidget *tab_2;
    QTableWidget *tblVariables;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QPlainTextEdit *txtEditor;
    QWidget *tab_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuarchivo;
    QMenu *menureportes;
    QMenu *menucompilar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1157, 836);
        actioncrear = new QAction(MainWindow);
        actioncrear->setObjectName(QString::fromUtf8("actioncrear"));
        actionabrir = new QAction(MainWindow);
        actionabrir->setObjectName(QString::fromUtf8("actionabrir"));
        actionguardar = new QAction(MainWindow);
        actionguardar->setObjectName(QString::fromUtf8("actionguardar"));
        actionguardar_como = new QAction(MainWindow);
        actionguardar_como->setObjectName(QString::fromUtf8("actionguardar_como"));
        actioncrear_pesta_a = new QAction(MainWindow);
        actioncrear_pesta_a->setObjectName(QString::fromUtf8("actioncrear_pesta_a"));
        actioneliminar_pesta_a = new QAction(MainWindow);
        actioneliminar_pesta_a->setObjectName(QString::fromUtf8("actioneliminar_pesta_a"));
        actionerror_lexico = new QAction(MainWindow);
        actionerror_lexico->setObjectName(QString::fromUtf8("actionerror_lexico"));
        actionerror_sintactico = new QAction(MainWindow);
        actionerror_sintactico->setObjectName(QString::fromUtf8("actionerror_sintactico"));
        actionerror_semantico = new QAction(MainWindow);
        actionerror_semantico->setObjectName(QString::fromUtf8("actionerror_semantico"));
        actionAST = new QAction(MainWindow);
        actionAST->setObjectName(QString::fromUtf8("actionAST"));
        actionejecutar = new QAction(MainWindow);
        actionejecutar->setObjectName(QString::fromUtf8("actionejecutar"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabla_simbolo = new QTabWidget(centralWidget);
        tabla_simbolo->setObjectName(QString::fromUtf8("tabla_simbolo"));
        tabla_simbolo->setGeometry(QRect(0, 560, 1161, 211));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        txtConsola = new QPlainTextEdit(tab);
        txtConsola->setObjectName(QString::fromUtf8("txtConsola"));
        txtConsola->setGeometry(QRect(0, 0, 1151, 181));
        QFont font;
        font.setFamily(QString::fromUtf8("aakar"));
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        txtConsola->setFont(font);
        tabla_simbolo->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tblVariables = new QTableWidget(tab_2);
        tblVariables->setObjectName(QString::fromUtf8("tblVariables"));
        tblVariables->setGeometry(QRect(0, 0, 1151, 181));
        tabla_simbolo->addTab(tab_2, QString());
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 1161, 561));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        txtEditor = new QPlainTextEdit(tab_3);
        txtEditor->setObjectName(QString::fromUtf8("txtEditor"));
        txtEditor->setGeometry(QRect(0, 0, 1151, 531));
        QFont font1;
        font1.setFamily(QString::fromUtf8("aakar"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        txtEditor->setFont(font1);
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget_2->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1157, 22));
        menuarchivo = new QMenu(menuBar);
        menuarchivo->setObjectName(QString::fromUtf8("menuarchivo"));
        menureportes = new QMenu(menuBar);
        menureportes->setObjectName(QString::fromUtf8("menureportes"));
        menucompilar = new QMenu(menuBar);
        menucompilar->setObjectName(QString::fromUtf8("menucompilar"));
        MainWindow->setMenuBar(menuBar);

        mainToolBar->addSeparator();
        menuBar->addAction(menuarchivo->menuAction());
        menuBar->addAction(menureportes->menuAction());
        menuBar->addAction(menucompilar->menuAction());
        menuarchivo->addAction(actioncrear);
        menuarchivo->addAction(actionabrir);
        menuarchivo->addAction(actionguardar);
        menuarchivo->addAction(actionguardar_como);
        menuarchivo->addAction(actioncrear_pesta_a);
        menuarchivo->addAction(actioneliminar_pesta_a);
        menureportes->addAction(actionerror_lexico);
        menureportes->addAction(actionerror_sintactico);
        menureportes->addAction(actionerror_semantico);
        menureportes->addAction(actionAST);
        menucompilar->addAction(actionejecutar);

        retranslateUi(MainWindow);

        tabla_simbolo->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Organizacion de Lenguajes y compiladores 1", nullptr));
        actioncrear->setText(QApplication::translate("MainWindow", "crear", nullptr));
        actionabrir->setText(QApplication::translate("MainWindow", "abrir", nullptr));
        actionguardar->setText(QApplication::translate("MainWindow", "guardar", nullptr));
        actionguardar_como->setText(QApplication::translate("MainWindow", "guardar como", nullptr));
        actioncrear_pesta_a->setText(QApplication::translate("MainWindow", "crear pesta\303\261a", nullptr));
        actioneliminar_pesta_a->setText(QApplication::translate("MainWindow", "eliminar pesta\303\261a", nullptr));
        actionerror_lexico->setText(QApplication::translate("MainWindow", "error lexico", nullptr));
        actionerror_sintactico->setText(QApplication::translate("MainWindow", "error sintactico", nullptr));
        actionerror_semantico->setText(QApplication::translate("MainWindow", "error semantico", nullptr));
        actionAST->setText(QApplication::translate("MainWindow", "AST", nullptr));
        actionejecutar->setText(QApplication::translate("MainWindow", "ejecutar", nullptr));
        tabla_simbolo->setTabText(tabla_simbolo->indexOf(tab), QApplication::translate("MainWindow", "consola", nullptr));
        tabla_simbolo->setTabText(tabla_simbolo->indexOf(tab_2), QApplication::translate("MainWindow", "tabla simbolo", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "pesta\303\261a", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "pesta\303\261a", nullptr));
        menuarchivo->setTitle(QApplication::translate("MainWindow", "archivo", nullptr));
        menureportes->setTitle(QApplication::translate("MainWindow", "reportes", nullptr));
        menucompilar->setTitle(QApplication::translate("MainWindow", "compilar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
