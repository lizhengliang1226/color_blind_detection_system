#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void systemInit();
    void setAnswerBtnValue();
    void setAnswerBtnDefaultStyle();
    void setQId();
    void setAnswerBtnStyle();
    void resultsInit();
private slots:
    void onClickNextPic();
    void onClickPrevPic();
    void onClickGetResult();
    void onClickA();
    void onClickB();
    void onClickC();
private:
    bool img_chang;
    QPoint start_point;
private:
    //按下
    void mousePressEvent(QMouseEvent*);
    //弹起
    void mouseReleaseEvent(QMouseEvent*);

private:
    Ui::MainWindow *ui;
    //图片索引
    int index;

    //答案被选中的样式
    QString selectedStyle="background-color:rgb(89, 124, 255);border:2px solid #ccc;";
    //答案的默认样式
    QString defaultStyle="background-color: rgb(194, 180, 195);border:2px solid #ccc;";
    QString styles[3]={"QPushButton#btn_a{"+selectedStyle+"}QPushButton#btn_b,QPushButton#btn_c{"+defaultStyle+"}",
                       "QPushButton#btn_b{"+selectedStyle+"}QPushButton#btn_a,QPushButton#btn_c{"+defaultStyle+"}",
                       "QPushButton#btn_c{"+selectedStyle+"}QPushButton#btn_b,QPushButton#btn_a{"+defaultStyle+"}"};
    //保存用户选择结果的数组
    QString results[15];
    //保存图片路径的数组
    QString images[15] = {":/pic/images/3.jpg",
                       ":/pic/images/36.jpg",
                       ":/pic/images/5.jpg",
                       ":/pic/images/6.jpg",
                       ":/pic/images/66.jpg",
                       ":/pic/images/809.jpg",
                       ":/pic/images/890.jpg",
                       ":/pic/images/9.jpg",
                       ":/pic/images/RED.jpg",":/pic/images/五角星.jpg",":/pic/images/圆形.jpg",":/pic/images/蜻蜓.jpg",":/pic/images/蝴蝶.jpg",":/pic/images/金鱼.jpg",":/pic/images/马.jpg"};

    //保存答案的数组
    QString answer[15][3]={{"9","6","3"},
                            {"86","63","36"},
                            {"0","6","5"},
                            {"9","0","6"},
                            {"96","16","66"},
                            {"889","099","809"},
                            {"899","088","890"},
                            {"3","6","9"},
                            {"RDD","RAD","RED"},
                            {"三角形","五边形","五角星"},
                            {"菱形","正方形","圆形"},
                            {"蜜蜂","蝴蝶","蜻蜓"},
                            {"燕子","黄蜂","蝴蝶"},
                            {"鸭子","鸡","金鱼"},
                            {"牛","车","马"}};
};
#endif // MAINWINDOW_H
