/********************************************************************************
** Form generated from reading UI file 'BenchmarkingWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BENCHMARKINGWIDGET_H
#define UI_BENCHMARKINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "src/view/gui/qtUtil/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_BenchmarkingWidget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QCustomPlot *plotTimeWidget;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *speedUpGroupBox;
    QGridLayout *gridLayout_3;
    QLabel *tpWeightedLabel;
    QLabel *ms2_2;
    QLabel *fpsWeighted;
    QLabel *tpWeighted;
    QLabel *fpsLabel_2;
    QLabel *fpsLabel;
    QLabel *fps;
    QLabel *tpProcessingLabel;
    QLabel *tpProccesing;
    QLabel *ms2;
    QCustomPlot *plotFPSWidget;

    void setupUi(QWidget *BenchmarkingWidget)
    {
        if (BenchmarkingWidget->objectName().isEmpty())
            BenchmarkingWidget->setObjectName(QStringLiteral("BenchmarkingWidget"));
        BenchmarkingWidget->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BenchmarkingWidget->sizePolicy().hasHeightForWidth());
        BenchmarkingWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(BenchmarkingWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plotTimeWidget = new QCustomPlot(BenchmarkingWidget);
        plotTimeWidget->setObjectName(QStringLiteral("plotTimeWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plotTimeWidget->sizePolicy().hasHeightForWidth());
        plotTimeWidget->setSizePolicy(sizePolicy1);
        plotTimeWidget->setMaximumSize(QSize(800, 400));

        verticalLayout->addWidget(plotTimeWidget);


        gridLayout->addLayout(verticalLayout, 0, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        speedUpGroupBox = new QGroupBox(BenchmarkingWidget);
        speedUpGroupBox->setObjectName(QStringLiteral("speedUpGroupBox"));
        speedUpGroupBox->setFlat(true);
        gridLayout_3 = new QGridLayout(speedUpGroupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tpWeightedLabel = new QLabel(speedUpGroupBox);
        tpWeightedLabel->setObjectName(QStringLiteral("tpWeightedLabel"));
        tpWeightedLabel->setLayoutDirection(Qt::RightToLeft);
        tpWeightedLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(tpWeightedLabel, 2, 0, 1, 1);

        ms2_2 = new QLabel(speedUpGroupBox);
        ms2_2->setObjectName(QStringLiteral("ms2_2"));

        gridLayout_3->addWidget(ms2_2, 2, 2, 1, 1);

        fpsWeighted = new QLabel(speedUpGroupBox);
        fpsWeighted->setObjectName(QStringLiteral("fpsWeighted"));
        fpsWeighted->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(fpsWeighted, 0, 1, 1, 1);

        tpWeighted = new QLabel(speedUpGroupBox);
        tpWeighted->setObjectName(QStringLiteral("tpWeighted"));
        tpWeighted->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(tpWeighted, 2, 1, 1, 1);

        fpsLabel_2 = new QLabel(speedUpGroupBox);
        fpsLabel_2->setObjectName(QStringLiteral("fpsLabel_2"));
        fpsLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(fpsLabel_2, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(speedUpGroupBox);

        fpsLabel = new QLabel(BenchmarkingWidget);
        fpsLabel->setObjectName(QStringLiteral("fpsLabel"));
        fpsLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(fpsLabel);

        fps = new QLabel(BenchmarkingWidget);
        fps->setObjectName(QStringLiteral("fps"));

        horizontalLayout_2->addWidget(fps);

        tpProcessingLabel = new QLabel(BenchmarkingWidget);
        tpProcessingLabel->setObjectName(QStringLiteral("tpProcessingLabel"));
        tpProcessingLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(tpProcessingLabel);

        tpProccesing = new QLabel(BenchmarkingWidget);
        tpProccesing->setObjectName(QStringLiteral("tpProccesing"));
        tpProccesing->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(tpProccesing);

        ms2 = new QLabel(BenchmarkingWidget);
        ms2->setObjectName(QStringLiteral("ms2"));

        horizontalLayout_2->addWidget(ms2);


        gridLayout->addLayout(horizontalLayout_2, 6, 2, 1, 1);

        plotFPSWidget = new QCustomPlot(BenchmarkingWidget);
        plotFPSWidget->setObjectName(QStringLiteral("plotFPSWidget"));
        plotFPSWidget->setMaximumSize(QSize(800, 400));

        gridLayout->addWidget(plotFPSWidget, 1, 2, 1, 1);


        retranslateUi(BenchmarkingWidget);

        QMetaObject::connectSlotsByName(BenchmarkingWidget);
    } // setupUi

    void retranslateUi(QWidget *BenchmarkingWidget)
    {
        BenchmarkingWidget->setWindowTitle(QApplication::translate("BenchmarkingWidget", "Dialog", 0));
        speedUpGroupBox->setTitle(QApplication::translate("BenchmarkingWidget", "Resume", 0));
        tpWeightedLabel->setText(QApplication::translate("BenchmarkingWidget", "T.Weighted:", 0));
        ms2_2->setText(QApplication::translate("BenchmarkingWidget", "ms", 0));
        fpsWeighted->setText(QApplication::translate("BenchmarkingWidget", "0", 0));
        tpWeighted->setText(QApplication::translate("BenchmarkingWidget", "0", 0));
        fpsLabel_2->setText(QApplication::translate("BenchmarkingWidget", "FPS Weighted:", 0));
        fpsLabel->setText(QApplication::translate("BenchmarkingWidget", "FPS:", 0));
        fps->setText(QApplication::translate("BenchmarkingWidget", "0", 0));
        tpProcessingLabel->setText(QApplication::translate("BenchmarkingWidget", "T. Processing:", 0));
        tpProccesing->setText(QApplication::translate("BenchmarkingWidget", "0", 0));
        ms2->setText(QApplication::translate("BenchmarkingWidget", "ms", 0));
    } // retranslateUi

};

namespace Ui {
    class BenchmarkingWidget: public Ui_BenchmarkingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BENCHMARKINGWIDGET_H
