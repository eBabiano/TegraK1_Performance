/********************************************************************************
** Form generated from reading UI file 'BackgroundSubstractorWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKGROUNDSUBSTRACTORWIDGET_H
#define UI_BACKGROUNDSUBSTRACTORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BackgroundSubstractorWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *backgroundLayout;
    QLabel *label;
    QSlider *horizontalSlider;

    void setupUi(QWidget *BackgroundSubstractorWidget)
    {
        if (BackgroundSubstractorWidget->objectName().isEmpty())
            BackgroundSubstractorWidget->setObjectName(QStringLiteral("BackgroundSubstractorWidget"));
        BackgroundSubstractorWidget->resize(400, 300);
        horizontalLayout = new QHBoxLayout(BackgroundSubstractorWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        backgroundLayout = new QVBoxLayout();
        backgroundLayout->setObjectName(QStringLiteral("backgroundLayout"));
        label = new QLabel(BackgroundSubstractorWidget);
        label->setObjectName(QStringLiteral("label"));

        backgroundLayout->addWidget(label);

        horizontalSlider = new QSlider(BackgroundSubstractorWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);

        backgroundLayout->addWidget(horizontalSlider);


        horizontalLayout->addLayout(backgroundLayout);


        retranslateUi(BackgroundSubstractorWidget);

        QMetaObject::connectSlotsByName(BackgroundSubstractorWidget);
    } // setupUi

    void retranslateUi(QWidget *BackgroundSubstractorWidget)
    {
        BackgroundSubstractorWidget->setWindowTitle(QApplication::translate("BackgroundSubstractorWidget", "Form", 0));
        label->setText(QApplication::translate("BackgroundSubstractorWidget", "Background Substractor", 0));
    } // retranslateUi

};

namespace Ui {
    class BackgroundSubstractorWidget: public Ui_BackgroundSubstractorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKGROUNDSUBSTRACTORWIDGET_H
