#include "Common.h"
#include "TextDocument.h"
#include "TextEdit.h"
#include "GraphicsView.h"
#include "GraphicsScene.h"
#include "ListView.h"
#include "LineEdit.h"
#include "MainWindow.h"

namespace Common {

QGradient PremiumWhite =
    QGradient(QGradient::PremiumWhite);
QGradient SolidStone =
    QGradient(QGradient::SolidStone);
TextEdit* m_textEdit = nullptr;
MainWindow* m_mainWindow = nullptr;
TextDocument* m_textDocument = nullptr;
BulletDocumentLayout* m_documentLayout = nullptr;
GraphicsScene* m_graphicsScene = nullptr;
GraphicsView* m_graphicsView = nullptr;
ListView* m_listView = nullptr;
ListModel* m_listModel = nullptr;
LineEdit* m_lineEdit = nullptr;
GlobalMenu* m_globalMenu = nullptr;
MenuItem* m_menuItem = nullptr;
QRubberBand* m_rubberBand = nullptr;
SyntaxHighlighter* m_syntaxHighlighter = nullptr;
AreaObject* m_areaObject = nullptr;
QGraphicsPathItem* m_graphicsPathItem = nullptr;
QSizeF A4F = QPageSize(QPageSize::A4)
                 .size(QPageSize::Point);
QSize  A4  = A4F.toSize();
QList<QGraphicsPathItem*> m_pathItems = {};
QList<QTextEdit::ExtraSelection> m_extraSelections = {};
int TitleUserState = 0;//unused;
int NormalUserState = -1;
int NoteUserState = 1;

int BulletRole = Qt::UserRole;

int bulletIndent = 30;
int bulletWidth = 10;
int bulletHeight = 10;

int collapseBulletIndent = bulletIndent + 20;
int menuIndent = bulletIndent + 30;

int Difference = 0;
int CurrentOwnerBlockNumber = 0;
bool SelectionHasNote = false;
int AberageLineHeight = 30;

int StartValue = 0;
int EndValue = 30;
int Duration = 500;
const char* PropertyName = "m_fixedHeight";
QString m_previousUUID = QUuid::createUuid().toString();
int BulletType = QGraphicsObject::UserType;
int CollapseBulletType = QGraphicsObject::UserType+1;
int MenuItemType = QGraphicsObject::UserType+2;
int AreaObjectType = QGraphicsObject::UserType+3;

QAbstractTextDocumentLayout::Selection Selection
    = QAbstractTextDocumentLayout::Selection();
QAbstractTextDocumentLayout::PaintContext PaintContext
    = QAbstractTextDocumentLayout::PaintContext();

QMap<QString, Bullet*> maps = {};

void setCobn(int cobn)
{
    CurrentOwnerBlockNumber = cobn;
}
int cobn()
{
    return CurrentOwnerBlockNumber;
}

void setDiff(int diff)
{
    Difference = diff;
}

int diff()
{
    return Difference;
}

void setShn(bool shn)
{
    SelectionHasNote = shn;
}

bool shn()
{
    return SelectionHasNote;
}

void setTextEdit(TextEdit *textEdit)
{
    m_textEdit = textEdit;
}

void setTextDocument(TextDocument *doc)
{
    m_textDocument = doc;
}

void setTextDocumentLayout(
    BulletDocumentLayout *docl)
{
    m_documentLayout = docl;
}

void setGraphicsScene(GraphicsScene *scene)
{
    m_graphicsScene = scene;
}

void setGraphicsView(GraphicsView *view)
{
    m_graphicsView = view;
}

TextEdit *textEdit()
{
    return m_textEdit;
}

TextDocument *document()
{
    return m_textDocument;
}

BulletDocumentLayout *documentLayout()
{
    return m_documentLayout;
}

GraphicsScene *scene()
{
    return m_graphicsScene;
}

GraphicsView *view()
{
    return m_graphicsView;
}

void setLineEdit(LineEdit *lineEdit)
{
    m_lineEdit = lineEdit;
}

LineEdit *lineEdit()
{
    return m_lineEdit;
}

QRectF baseBlockBoundingRect(
    const QTextBlock &block)
{

    return baseDocumentLayout()->
        blockBoundingRect(block);
}

QAbstractTextDocumentLayout *baseDocumentLayout()
{

    return document()->documentLayout();
}

int blockCount()
{
    return document()->blockCount();
}

QTextBlock findBlockByNumber(int num)
{
    return document()->findBlockByNumber(num);
}

QTextBlock findBlock(int num)
{
    return document()->findBlock(num);
}

int selectionStart()
{
    return selectionCursor().selectionStart();
}

int selectionEnd()
{
    return selectionCursor().selectionEnd();
}

QTextCursor selectionCursor()
{
    return Selection.cursor;
}

void setSelectionCursor(QTextCursor cursor)
{
    Selection.cursor = cursor;
}

void setSelectionFormat(QTextCharFormat format)
{
    Selection.format = format;
}

QTextCharFormat selectionFormat()
{
    return Selection.format;
}

void setGlobalMenu(GlobalMenu *globalMenu)
{
    m_globalMenu = globalMenu;
}

GlobalMenu *globalMenu()
{
    return m_globalMenu;
}

void setMenuItem(MenuItem *menuItem)
{
    m_menuItem = menuItem;
}

MenuItem *menuItem()
{
    return m_menuItem;
}

void setSyntaxHighlighter(
    SyntaxHighlighter *syntaxHighlighter)
{
    m_syntaxHighlighter = syntaxHighlighter;
}

SyntaxHighlighter *syntaxHighlighter()
{
    return m_syntaxHighlighter;
}

void setListModel(ListModel* listModel)
{
    m_listModel = listModel;
}

ListModel* listModel()
{
    return m_listModel;
}

void setListView(ListView *listView)
{
    m_listView = listView;
}

ListView *listView()
{
    return m_listView;
}

void setAreaObject(AreaObject *areaObject)
{
    m_areaObject = areaObject;
}

AreaObject *areaObject()
{
    return m_areaObject;
}

QTextBlock lastBlockOf(int num)
{
    QTextBlock block = findBlockByNumber(num);
    QTextCursor tc = QTextCursor(block);
    int indent = tc.blockFormat().indent();
    while (tc.movePosition(NextBlock, MoveAnchor))
    {
        int _indent = tc.blockFormat().indent();
        if (indent < _indent)
        {
            continue;
        }
        else
        {
            tc.movePosition(PreviousBlock, MoveAnchor);
            break;
        }
        if (Common::document()->lastBlock() == tc.block())
        {
            return tc.block();
        }
    }
    return tc.block();
}

void setGraphicsPathItem(QGraphicsPathItem *pathItem)
{
    m_graphicsPathItem = pathItem;
}

QGraphicsPathItem *graphicsPathItem()
{
    return m_graphicsPathItem;
}

int blockIndent(const QTextBlock &block)
{
    return block.blockFormat().indent();
}

void setRubberBand(QRubberBand *rubberBand)
{
    m_rubberBand = rubberBand;
}

QRubberBand *rubberBand()
{
    return m_rubberBand;
}

void setMainWindow(MainWindow *mainWindow)
{
    m_mainWindow = mainWindow;
}

MainWindow *mainWindow()
{
    return m_mainWindow;
}
}


