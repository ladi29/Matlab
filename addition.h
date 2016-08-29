#ifndef ADDITION_H
#define ADDITION_H

#include <QWidget>

namespace Ui {
class addition;
}

class addition : public QWidget
{
    Q_OBJECT

public:
    char Eingabefeld[200];          //maximale Eingabefeld
    explicit addition(QWidget *parent = 0);
    ~addition();

private slots:
    //FOR THE DIGITS!
    void on_Button_1_clicked();
    void on_Button_2_clicked();
    void on_Button_3_clicked();
    void on_Button_4_clicked();
    void on_Button_5_clicked();
    void on_Button_6_clicked();
    void on_Button_7_clicked();
    void on_Button_8_clicked();
    void on_Button_9_clicked();
    void on_Button_0_clicked();

    //FOR THE OPERANDS!
    void on_Button_add_clicked();
    void on_Button_modulos_clicked();
    void on_Button_multiply_clicked();
    void on_Button_subtract_clicked();
    void on_Button_power_clicked();
    void on_Button_divide_clicked();
    void on_Button_equal_clicked();

    //FOR THE CALCULATION
    int calc(int op, int x, int y);
    int zahl(int zahl1, int zahl2);
    int low_high(int op);
    int aundb(int anfang, int ende);

private:
    Ui::addition *ui;
    unsigned int index;
    unsigned int to;
    int input_length;
    char input[100];
};

#endif // ADDITION_H
