/*
*    Copyright (c) 2018 Shing Liu All Rights Reserved.
*
*           File : occQt.h
*         Author : Shing Liu(eryar@163.com)
*           Date : 2018-01-08 20:00
*        Version : OpenCASCADE7.2.0 & Qt5.7.1
*
*    Description : OpenCASCADE in Qt.
*/

#ifndef OCCQT_H
#define OCCQT_H

#include "ui_occQt.h"

#include <AIS_InteractiveContext.hxx>

#include <AIS_Shape.hxx>

#include <QThread>
#include <QTimer>
#include <QDebug>

class OccView;

class Thread: public QThread{
    Q_OBJECT
public:
    Thread(OccView* view, AIS_Shape* AIS_0,
           AIS_Shape* AIS_1, int TIME);
    ~Thread();

    void run();

private:

    OccView* myView;
    Handle(AIS_Shape) ais0, ais1;

    QTimer timer;

    gp_Trsf myTrsf0, myTrsf1;


    int count = 0;
    int i = 0;
public: signals:

public slots:
    void UP();
};


//! Qt main window which include OpenCASCADE for its central widget.
class occQt : public QMainWindow
{
    Q_OBJECT

public:
    //! constructor/destructor.
    occQt(QWidget *parent = nullptr);
    ~occQt();

protected:
    //! create all the actions.
    void createActions(void);

    //! create all the menus.
    void createMenus(void);

    //! create the toolbar.
    void createToolBars(void);

    //! make cylindrical helix.
    void makeCylindricalHelix(void);

    //! make conical helix.
    void makeConicalHelix(void);

    //! make toroidal helix.
    void makeToroidalHelix(void);

private slots:
    //! show about box.
    void about(void);

    //! make box test.
    void makeBox(void);

    //! make cone test.
    void makeCone(void);

    //! make sphere test.
    void makeSphere(void);

    //! make cylinder test.
    void makeCylinder(void);

    //! make torus test.
    void makeTorus(void);

    //! fillet test.
    void makeFillet(void);

    //! chamfer test.
    void makeChamfer(void);

    //! test extrude algorithm.
    void makeExtrude(void);

    //! test revol algorithm.
    void makeRevol(void);

    //! test loft algorithm.
    void makeLoft(void);

    //! test boolean operation cut.
    void testCut(void);

    //! test boolean operation fuse.
    void testFuse(void);

    //! test boolean operation common.
    void testCommon(void);

    //! test helix shapes.
    void testHelix(void);

private:
    Ui::occQtClass ui;

    // wrapped the widget for occ.
    OccView* myOccView;

    QThread* t1;
};

#endif // OCCQT_H
