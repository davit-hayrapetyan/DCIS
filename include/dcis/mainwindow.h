#ifndef DCIS_UI_MAINWINDOW_H_
#define DCIS_UI_MAINWINDOW_H_

// App headers
#include <net/client.h>
#include <gui/console.h>
#include <gui/graphview.h>
#include <gui/graphinfo.h>
#include <utils/debugstream.h>
#include <gui/elementpropertiestable.h>

// QT headers
#include <QMenu>
#include <QLabel>
#include <QFrame>
#include <QWidget>
#include <QSlider>
#include <QAction>
#include <QVariant>
#include <QMenuBar>
#include <QLineEdit>
#include <QSplitter>
#include <QTextEdit>
#include <QStatusBar>
#include <QPushButton>
#include <QSpacerItem>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <QStackedWidget>
#include <QGeoCoordinate>

#include <QVBoxLayout>

namespace dcis::gui {
using namespace common;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void setupUi();
    void setWorkspaceEnabled(bool enable);

    Console* getConsole() const;

protected:
    void resizeEvent(QResizeEvent* event) override;

public slots:
    void onUpload();
    void onCreateGrid();
    void onClearCycles();
    void onGenerateGraph();
    void onStartExploration();
    void onStartAttack();
    void onConnectBtnClicked();
    void onGraphChanged();
    void onUpdateGraph(const QJsonDocument& json);

    void onSaveGraph();
    void onLoadGraph();

private:
    void createMenu();
    void createToolBar();
    void createEntryWidget();
    void createWorkingWiget();
    void createGraphInfoWidget();

private:
    QAction* actSave_;
    QAction* actExit_;
    QAction* actSaveAs_;
    QAction* actCredits_;
    QAction* actNewGraph_;
    QAction* actOpenGraph_;
    QAction* actionBFS_;
    QAction* actionDFS_;
    QAction* actAddNode_;
    QAction* actAddEdge_;
    QAction* actDelNode_;
    QAction* actDelEdge_;
    QAction* actEditEdge_;

    QMenu* menuFile_;
    QMenu* menuGraph_;
    QMenu* menuAdd_;
    QMenu* menuEdit_;
    QMenu* menuDelete_;
    QMenu* menuAlgorithms_;

    QMenuBar* menuBar_;
    QToolBar* toolBar_;

    QDockWidget* dockWidget_;
    QStackedWidget* centralWidget_;

    QLabel* backgroundLabel_;
    QLineEdit*   ipLineEdit_;
    QLineEdit*   portLineEdit_;
    QPushButton* connectButton_;
    QWidget*     entryWidget_ = nullptr;

    Console* console_;
    QWidget* workingWidget_;

    client::Client* client_;
    GraphInfo* graphInfo_;
    GraphView* graphView_;

    QString currentFilePath_ = "";

    QString leftTop_;
    QString rightBottom_;
    ElementPropertiesTable* elementPropertiesTable_;
};

} // end namespace dcis::ui
#endif // DCIS_UI_MAINWINDOW_H_
