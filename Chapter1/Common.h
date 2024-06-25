#ifndef COMMON_H
#define COMMON_H

#include <QWidget>
#include <QMenu>
#include <QStatusBar>
#include <QMainWindow>
#include <QSaveFile>
#include <QFile>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QTextEdit>
#include <QTextDocument>
#include <QTextBlockUserData>
#include <QLineEdit>
#include <QDockWidget>
#include <QListView>
#include <QStyleFactory>
#include <QScrollBar>
#include <QPageSize>
#include <QPainter>
#include <QGraphicsProxyWidget>
#include <QGraphicsObject>
#include <QGraphicsSceneMouseEvent>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QTextCursor>
#include <QTextBlock>
#include <QVBoxLayout>
#include <QSize>
#include <QSizeF>
#include <QSyntaxHighlighter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QEvent>
#include <QUuid>
#include <QUndoStack>
#include <QTimer>
#include <QAbstractTextDocumentLayout>
#include <QtStateMachine/QStateMachine>
#include <QtStateMachine/QState>
#include <QtStateMachine/QSignalTransition>
#include <QUndoView>
#include <QFileDialog>

//forward statements
class AreaObject;
class CentralWidget;
class TextEdit;
class TextDocument;
class Bullet;
class BulletLine;
class BulletUserData;
class BulletDocumentLayout;
class CollapseBullet;
class MainWindow;
class MenuItem;
class GraphicsView;
class GraphicsScene;
class LineEdit;
class ListView;
class ListModel;
class InsertBullet;
class GlobalMenu;
class SyntaxHighlighter;
class QPropertyAnimation;
class QTextDocument;
class QTextBlock;
class QPushButton;

constexpr auto Left = QTextCursor::Left;
constexpr auto Right = QTextCursor::Right;
constexpr auto Up = QTextCursor::Up;
constexpr auto Down = QTextCursor::Down;
constexpr auto Start = QTextCursor::Start;
constexpr auto End = QTextCursor::End;
constexpr auto PreviousBlock = QTextCursor::PreviousBlock;
constexpr auto NextBlock = QTextCursor::NextBlock;
constexpr auto EndOfBlock = QTextCursor::EndOfBlock;
constexpr auto NextCharacter = QTextCursor::NextCharacter;
constexpr auto MoveAnchor = QTextCursor::MoveAnchor;
constexpr auto KeepAnchor = QTextCursor::KeepAnchor;

constexpr QColor PureBlack = QColor(0, 0, 0);
constexpr QColor CosmicBlue = QColor(0, 45, 95);
constexpr QColor MistyBlue = QColor(153, 169, 206);
constexpr QColor SilkyBlue = QColor(205, 215, 234);
constexpr QColor MoonLight = QColor(245, 242, 192, 100);
constexpr QColor PowderSnow = QColor(234, 242, 251);
constexpr QColor EternalBlue = QColor(53, 109, 181);
constexpr QColor WhiteCloud = QColor(245, 251, 254,200);
constexpr QColor BrilliantSky = QColor(220, 237, 240, 200);
constexpr QColor WhitePeach = QColor(252, 232, 220, 100);
constexpr QColor BritainFog = QColor(174, 165, 161);
constexpr QColor DiamondLight = QColor(230, 238, 247, 100);

namespace Common
{

enum class UndoId{
    AppendTextUndoCommandID,
    InputMethodUndoCommandID,
    InsertBlockUndoCommandID,
    TabUndoCommandID,
    BackTabUndoCommandID,
    AddNoteUndoCommandID,
    SwitchBulletUndoCommandID,
    DropBulletUndoCommandID,
    DropBulletsUndoCommandID,
    TransitionUndoCommandID,
    BackTransitionUndoCommandID,
    BackspaceUndoCommandID,
    DeleteBulletsUndoCommandID,
    LoadUndoCommandID
};

extern int NormalUserState;
extern int TitleUserState; //unused;
extern int NoteUserState;

extern int BulletRole;

extern int bulletIndent;
extern int bulletWidth;
extern int bulletHeight;

extern int collapseBulletIndent;
extern int menuIndent;

extern int Difference;
extern int CurrentOwnerBlockNumber;
extern bool SelectionHasNote;
extern int AberageLineHeight;

extern int StartValue;
extern int EndValue;
extern int Duration;
extern const char* PropertyName;

extern int BulletType;
extern int MenuItemType;
extern int AreaObjectType;
extern int CollapseBulletType;
extern QGradient PremiumWhite;
extern QGradient SolidStone;
extern QString m_previousUUID;
extern MainWindow* m_mainWindow;
extern TextEdit* m_textEdit;
extern TextDocument* m_document;
extern BulletDocumentLayout* m_documentLayout;
extern GraphicsScene* m_graphicsScene;
extern GraphicsView* m_graphicsView;
extern ListView* m_listView;
extern ListModel* m_listModel;
extern LineEdit* m_lineEdit;
extern GlobalMenu* m_globalMenu;
extern MenuItem* m_menuItem;
extern SyntaxHighlighter* m_syntaxHighlighter;
extern AreaObject* m_areaObject;
extern QGraphicsPathItem* m_graphicsPathItem;
extern QRubberBand* m_rubberBand;
extern QSizeF A4F;
extern QSize  A4;
extern QList<QGraphicsPathItem*>
    m_pathItems;
extern QList<QTextEdit::ExtraSelection>
    m_extraSelections;


extern QAbstractTextDocumentLayout::Selection Selection;
extern QAbstractTextDocumentLayout::PaintContext PaintContext;


extern void  setCobn(int cobn);
extern int  cobn();
extern void  setDiff(int diff);
extern int  diff();
extern void  setShn(bool shn);
extern bool  shn();
extern void  setMainWindow(MainWindow* mainWindow);
extern void  setTextEdit(TextEdit* textEdit);
extern void  setTextDocument(TextDocument* doc);
extern void  setTextDocumentLayout (
    BulletDocumentLayout* docl
    );
extern void  setGraphicsScene(GraphicsScene* scene);
extern void  setGraphicsView(GraphicsView* view);
extern void  setLineEdit(LineEdit* lineEdit);
extern void  setGlobalMenu(GlobalMenu* globalMenu);
extern void  setMenuItem(MenuItem* menuItem);
extern void  setListView(ListView* listView);
extern void  setListModel(ListModel* listModel);
extern void  setSyntaxHighlighter(
    SyntaxHighlighter* syntaxHighlighter);
extern void  setAreaObject(
    AreaObject* areaObject);
extern void  setGraphicsPathItem(
    QGraphicsPathItem* pathItem);
extern void  setRubberBand(QRubberBand* rubberBand);
extern void drawSelectedArea(
    QGraphicsSceneMouseEvent* event);
extern void flagUpdate();
extern MainWindow* mainWindow();
extern TextEdit* textEdit();
extern TextDocument* document();
extern BulletDocumentLayout* documentLayout();
extern GraphicsScene* scene();
extern GraphicsView* view();
extern LineEdit* lineEdit();
extern ListView* listView();
extern ListModel* listModel();
extern GlobalMenu* globalMenu();
extern MenuItem* menuItem();
extern QRubberBand* rubberBand();
extern SyntaxHighlighter* syntaxHighlighter();
extern AreaObject* areaObject();
extern QGraphicsPathItem* graphicsPathItem();
extern void setSelectionCursor(QTextCursor cursor);
extern void setSelectionFormat(QTextCharFormat format);
extern int  selectionStart();
extern int  selectionEnd();
extern QTextCursor selectionCursor();
extern QTextCharFormat selectionFormat();
extern QAbstractTextDocumentLayout* baseDocumentLayout();
extern QRectF baseBlockBoundingRect(
    const QTextBlock& block);
extern QRectF blockBoundingRect(
    const QTextBlock& block);
extern int hitTest(
    QPointF point,
    Qt::HitTestAccuracy hitTest=Qt::FuzzyHit);
extern BulletUserData* blockUserData(
    const QTextBlock& block);
extern QMap<QString, Bullet*> maps;
extern int blockCount();
extern QTextBlock findBlockByNumber(int num);
extern QTextBlock findBlock(int num);
extern void rehighlightBlock(const QTextBlock& block);
extern QTextBlock lastBlockOf(int num);
extern void setDestBullet(QTextCursor tc,
                          const QTextBlock &oldBlock);
extern int blockIndent(const QTextBlock& block);
extern Bullet* bullet(const QTextBlock& block);
}

#endif // COMMON_H



