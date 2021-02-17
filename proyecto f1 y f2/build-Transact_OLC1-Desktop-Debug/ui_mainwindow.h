/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1157, 836);
        actioncrear = new QAction(MainWindow);
        actioncrear->setObjectName(QStringLiteral("actioncrear"));
        actionabrir = new QAction(MainWindow);
        actionabrir->setObjectName(QStringLiteral("actionabrir"));
        actionguardar = new QAction(MainWindow);
        actionguardar->setObjectName(QStringLiteral("actionguardar"));
        actionguardar_como = new QAction(MainWindow);
        actionguardar_como->setObjectName(QStringLiteral("actionguardar_como"));
        actioncrear_pesta_a = new QAction(MainWindow);
        actioncrear_pesta_a->setObjectName(QStringLiteral("actioncrear_pesta_a"));
        actioneliminar_pesta_a = new QAction(MainWindow);
        actioneliminar_pesta_a->setObjectName(QStringLiteral("actioneliminar_pesta_a"));
        actionerror_lexico = new QAction(MainWindow);
        actionerror_lexico->setObjectName(QStringLiteral("actionerror_lexico"));
        actionerror_sintactico = new QAction(MainWindow);
        actionerror_sintactico->setObjectName(QStringLiteral("actionerror_sintactico"));
        actionerror_semantico = new QAction(MainWindow);
        actionerror_semantico->setObjectName(QStringLiteral("actionerror_semantico"));
        actionAST = new QAction(MainWindow);
        actionAST->setObjectName(QStringLiteral("actionAST"));
        actionejecutar = new QAction(MainWindow);
        actionejecutar->setObjectName(QStringLiteral("actionejecutar"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabla_simbolo = new QTabWidget(centralWidget);
        tabla_simbolo->setObjectName(QStringLiteral("tabla_simbolo"));
        tabla_simbolo->setGeometry(QRect(0, 560, 1161, 211));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        txtConsola = new QPlainTextEdit(tab);
        txtConsola->setObjectName(QStringLiteral("txtConsola"));
        txtConsola->setGeometry(QRect(0, 0, 1151, 181));
        QFont font;
        font.setFamily(QStringLiteral("aakar"));
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        txtConsola->setFont(font);
        tabla_simbolo->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tblVariables = new QTableWidget(tab_2);
        tblVariables->setObjectName(QStringLiteral("tblVariables"));
        tblVariables->setGeometry(QRect(0, 0, 1151, 181));
        tabla_simbolo->addTab(tab_2, QString());
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 1161, 561));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        txtEditor = new QPlainTextEdit(tab_3);
        txtEditor->setObjectName(QStringLiteral("txtEditor"));
        txtEditor->setGeometry(QRect(0, 0, 1151, 531));
        QFont font1;
        font1.setFamily(QStringLiteral("aakar"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        txtEditor->setFont(font1);
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget_2->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1157, 22));
        menuarchivo = new QMenu(menuBar);
        menuarchivo->setObjectName(QStringLiteral("menuarchivo"));
        menureportes = new QMenu(menuBar);
        menureportes->setObjectName(QStringLiteral("menureportes"));
        menucompilar = new QMenu(menuBar);
        menucompilar->setObjectName(QStringLiteral("menucompilar"));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Organizacion de Lenguajes y compiladores 1", Q_NULLPTR));
        actioncrear->setText(QApplication::translate("MainWindow", "crear", Q_NULLPTR));
        actionabrir->setText(QApplication::translate("MainWindow", "abrir", Q_NULLPTR));
        actionguardar->setText(QApplication::translate("MainWindow", "guardar", Q_NULLPTR));
        actionguardar_como->setText(QApplication::translate("MainWindow", "guardar como", Q_NULLPTR));
        actioncrear_pesta_a->setText(QApplication::translate("MainWindow", "crear pesta\303\261a", Q_NULLPTR));
        actioneliminar_pesta_a->setText(QApplication::translate("MainWindow", "eliminar pesta\303\261a", Q_NULLPTR));
        actionerror_lexico->setText(QApplication::translate("MainWindow", "error lexico", Q_NULLPTR));
        actionerror_sintactico->setText(QApplication::translate("MainWindow", "error sintactico", Q_NULLPTR));
        actionerror_semantico->setText(QApplication::translate("MainWindow", "error semantico", Q_NULLPTR));
        actionAST->setText(QApplication::translate("MainWindow", "AST", Q_NULLPTR));
        actionejecutar->setText(QApplication::translate("MainWindow", "ejecutar", Q_NULLPTR));
        tabla_simbolo->setTabText(tabla_simbolo->indexOf(tab), QApplication::translate("MainWindow", "consola", Q_NULLPTR));
        tabla_simbolo->setTabText(tabla_simbolo->indexOf(tab_2), QApplication::translate("MainWindow", "tabla simbolo", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "pesta\303\261a", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "pesta\303\261a", Q_NULLPTR));
        menuarchivo->setTitle(QApplication::translate("MainWindow", "archivo", Q_NULLPTR));
        menureportes->setTitle(QApplication::translate("MainWindow", "reportes", Q_NULLPTR));
        menucompilar->setTitle(QApplication::translate("MainWindow", "compilar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
