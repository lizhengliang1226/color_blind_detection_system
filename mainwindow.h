#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void setAnswer();
    void setAnswerDefaultStyle();
    int getIndex(int flag);
private slots:
    void nextPic();
    void prevPic();
    void onEnter();
    void setA();
    void setB();
    void setC();
    void resultsInit();
private:
    Ui::MainWindow *ui;
    void initArr();
    //图片索引
    int index;
    //答案被选中的样式
    QString selectedStyle="background-color:rgb(89, 124, 255);border:2px solid #ccc;";
    //答案的默认样式
    QString defaultStyle="background-color: rgb(194, 180, 195);border:2px solid #ccc;";
    QString results[15];
    QString images[15] = {":/pic/images/3.jpg",
                       ":/pic/images/36.jpg",
                       ":/pic/images/5.jpg",
                       ":/pic/images/6.jpg",
                       ":/pic/images/66.jpg",
                       ":/pic/images/809.jpg",
                       ":/pic/images/890.jpg",
                       ":/pic/images/9.jpg",
                       ":/pic/images/RED.jpg",":/pic/images/五角星.jpg",":/pic/images/圆形.jpg",":/pic/images/蜻蜓.jpg",":/pic/images/蝴蝶.jpg",":/pic/images/金鱼.jpg",":/pic/images/马.jpg"};


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
