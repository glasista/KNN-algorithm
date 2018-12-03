/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOtw_rz_Plik;
    QAction *actionInformacje;
    QAction *actionZapisz_wykres;
    QAction *actionZamknij;
    QWidget *centralWidget;
    QCustomPlot *widget;
    QPushButton *update;
    QSpinBox *spinBox;
    QPushButton *Calculate;
    QGroupBox *groupBox;
    QRadioButton *cityblock;
    QRadioButton *canbeer;
    QRadioButton *euklides;
    QPushButton *AddPoint;
    QDoubleSpinBox *XspinBox;
    QDoubleSpinBox *YspinBox;
    QLineEdit *categoryEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QCheckBox *isPrediction;
    QMenuBar *menuBar;
    QMenu *menuPlik;
    QMenu *menuPomoc;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1025, 488);
        MainWindow->setDocumentMode(false);
        actionOtw_rz_Plik = new QAction(MainWindow);
        actionOtw_rz_Plik->setObjectName(QStringLiteral("actionOtw_rz_Plik"));
        actionInformacje = new QAction(MainWindow);
        actionInformacje->setObjectName(QStringLiteral("actionInformacje"));
        actionZapisz_wykres = new QAction(MainWindow);
        actionZapisz_wykres->setObjectName(QStringLiteral("actionZapisz_wykres"));
        actionZamknij = new QAction(MainWindow);
        actionZamknij->setObjectName(QStringLiteral("actionZamknij"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        widget = new QCustomPlot(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(true);
        widget->setGeometry(QRect(300, 20, 711, 401));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setLayoutDirection(Qt::LeftToRight);
        update = new QPushButton(centralWidget);
        update->setObjectName(QStringLiteral("update"));
        update->setGeometry(QRect(190, 350, 93, 28));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(100, 400, 42, 22));
        spinBox->setMinimum(1);
        spinBox->setValue(1);
        Calculate = new QPushButton(centralWidget);
        Calculate->setObjectName(QStringLiteral("Calculate"));
        Calculate->setGeometry(QRect(190, 390, 93, 28));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 221, 171));
        cityblock = new QRadioButton(groupBox);
        cityblock->setObjectName(QStringLiteral("cityblock"));
        cityblock->setGeometry(QRect(20, 80, 111, 20));
        canbeer = new QRadioButton(groupBox);
        canbeer->setObjectName(QStringLiteral("canbeer"));
        canbeer->setGeometry(QRect(20, 50, 121, 20));
        euklides = new QRadioButton(groupBox);
        euklides->setObjectName(QStringLiteral("euklides"));
        euklides->setGeometry(QRect(20, 20, 151, 20));
        euklides->setChecked(true);
        AddPoint = new QPushButton(centralWidget);
        AddPoint->setObjectName(QStringLiteral("AddPoint"));
        AddPoint->setGeometry(QRect(210, 210, 71, 71));
        XspinBox = new QDoubleSpinBox(centralWidget);
        XspinBox->setObjectName(QStringLiteral("XspinBox"));
        XspinBox->setGeometry(QRect(110, 210, 81, 22));
        XspinBox->setMinimum(-1000);
        XspinBox->setMaximum(1000);
        YspinBox = new QDoubleSpinBox(centralWidget);
        YspinBox->setObjectName(QStringLiteral("YspinBox"));
        YspinBox->setGeometry(QRect(110, 240, 81, 22));
        YspinBox->setMinimum(-1000);
        YspinBox->setMaximum(1000);
        categoryEdit = new QLineEdit(centralWidget);
        categoryEdit->setObjectName(QStringLiteral("categoryEdit"));
        categoryEdit->setEnabled(true);
        categoryEdit->setGeometry(QRect(110, 290, 171, 22));
        categoryEdit->setDragEnabled(false);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 400, 81, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 210, 91, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 240, 71, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 290, 71, 16));
        isPrediction = new QCheckBox(centralWidget);
        isPrediction->setObjectName(QStringLiteral("isPrediction"));
        isPrediction->setGeometry(QRect(30, 320, 221, 20));
        isPrediction->setChecked(false);
        isPrediction->setTristate(false);
        MainWindow->setCentralWidget(centralWidget);
        update->raise();
        spinBox->raise();
        Calculate->raise();
        groupBox->raise();
        AddPoint->raise();
        XspinBox->raise();
        YspinBox->raise();
        categoryEdit->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        isPrediction->raise();
        widget->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1025, 26));
        menuPlik = new QMenu(menuBar);
        menuPlik->setObjectName(QStringLiteral("menuPlik"));
        menuPomoc = new QMenu(menuBar);
        menuPomoc->setObjectName(QStringLiteral("menuPomoc"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuPlik->menuAction());
        menuBar->addAction(menuPomoc->menuAction());
        menuPlik->addAction(actionOtw_rz_Plik);
        menuPlik->addAction(actionZapisz_wykres);
        menuPlik->addAction(actionZamknij);
        menuPomoc->addAction(actionInformacje);

        retranslateUi(MainWindow);
        QObject::connect(widget, SIGNAL(plotClick(QMouseEvent*)), widget, SLOT(update()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "KNN algorithm", Q_NULLPTR));
        actionOtw_rz_Plik->setText(QApplication::translate("MainWindow", "Otw\303\263rz Plik", Q_NULLPTR));
        actionInformacje->setText(QApplication::translate("MainWindow", "O programie", Q_NULLPTR));
        actionZapisz_wykres->setText(QApplication::translate("MainWindow", "Zapisz wykres", Q_NULLPTR));
        actionZamknij->setText(QApplication::translate("MainWindow", "Zamknij", Q_NULLPTR));
        update->setText(QApplication::translate("MainWindow", "Aktualizuj", Q_NULLPTR));
        Calculate->setText(QApplication::translate("MainWindow", "Oblicz", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Miara odleg\305\202o\305\233ci", Q_NULLPTR));
        cityblock->setText(QApplication::translate("MainWindow", "Odl. city-block", Q_NULLPTR));
        canbeer->setText(QApplication::translate("MainWindow", "Odl. Canbeera", Q_NULLPTR));
        euklides->setText(QApplication::translate("MainWindow", "Odl. Euklidesowa", Q_NULLPTR));
        AddPoint->setText(QApplication::translate("MainWindow", "Dodaj ", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Parametr k", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Warto\305\233\304\207 X", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Warto\305\233\304\207 Y", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Kategoria", Q_NULLPTR));
        isPrediction->setText(QApplication::translate("MainWindow", "Przewidywanie kategorii punktu", Q_NULLPTR));
        menuPlik->setTitle(QApplication::translate("MainWindow", "Plik", Q_NULLPTR));
        menuPomoc->setTitle(QApplication::translate("MainWindow", "Pomoc", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
