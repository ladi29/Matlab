#include "addition.h"
#include "ui_addition.h"
#include "math.h"
#include"string.h"

addition::addition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addition){
        ui->setupUi(this);
        index = 0;
        to = 0;
        input_length = 0;
    }


addition::~addition(){
    delete ui;
    }


int calc(int op, int x, int y){
    switch (op) {
    case '+':   return x + y;
    case '-':   return x - y;
    case '*':   return x * y;
    case'^':	return pow(x,y);
    case '/':   return x / y;
    case '%':  	return x % y;
    }
    return 0;
}


//IMPLEMENTATION OF THE FUNCTION OF NUMBERS CLICKED!
//WHEN DIGIT 1 IS PRESSED!
void addition::on_Button_1_clicked(){
    ui-> lineEdit_Eingabezahl->setText(ui->lineEdit_Eingabezahl->text()+"1");}

//WHEN DIGIT 2 IS PRESSED!
void addition::on_Button_2_clicked(){
    ui-> lineEdit_Eingabezahl->setText(ui->lineEdit_Eingabezahl->text()+"2");}

//WHEN DIGIT 3 IS PRESSED!
void addition::on_Button_3_clicked(){
    ui-> lineEdit_Eingabezahl->setText(ui->lineEdit_Eingabezahl->text()+"3");}

//WHEN DIGIT 4 IS PRESSED!
void addition::on_Button_4_clicked(){
    ui-> lineEdit_Eingabezahl->setText(ui->lineEdit_Eingabezahl->text()+"4");}

//WHEN DIGIT 5 IS PRESSED!
void addition::on_Button_5_clicked(){
    ui-> lineEdit_Eingabezahl->setText(ui->lineEdit_Eingabezahl->text()+"5");}

//WHEN DIGIT 6 IS PRESSED!
void addition::on_Button_6_clicked(){
    ui-> lineEdit_Eingabezahl->setText(ui->lineEdit_Eingabezahl->text()+"6");}

//WHEN DIGIT 7 IS PRESSED!
void addition::on_Button_7_clicked(){
    ui-> lineEdit_Eingabezahl->setText(ui->lineEdit_Eingabezahl->text()+"7");}

//WHEN DIGIT 8 IS PRESSED!
void addition::on_Button_8_clicked(){
    ui-> lineEdit_Eingabezahl->setText(ui->lineEdit_Eingabezahl->text()+"8");}

//WHEN DIGIT 9 IS PRESSED!
void addition::on_Button_9_clicked(){
    ui-> lineEdit_Eingabezahl->setText(ui->lineEdit_Eingabezahl->text()+"9");}

//WHEN DIGIT 0 IS PRESSED!
void addition::on_Button_0_clicked(){
    ui-> lineEdit_Eingabezahl->setText(ui->lineEdit_Eingabezahl->text()+"0");}


//IMPLEMENTATION OF THE FUNCTION OF OPERATORS CLICKED!
//WHEN PLUS IS PRESSED!
void addition::on_Button_add_clicked(){
    ui-> lineEdit_Eingabezahl->setText(ui->lineEdit_Eingabezahl->text()+"+");}

//WHEN MINUS IS PRESSED!
void addition::on_Button_subtract_clicked(){
    ui-> lineEdit_Eingabezahl->setText(ui->lineEdit_Eingabezahl->text()+"-");}

//WHEN MULTIPLY IS PRESSED!
void addition::on_Button_multiply_clicked(){
    ui-> lineEdit_Eingabezahl->setText(ui->lineEdit_Eingabezahl->text()+"*");}

//WHEN DIVISION IS PRESSED!
void addition::on_Button_divide_clicked(){
    ui-> lineEdit_Eingabezahl->setText(ui->lineEdit_Eingabezahl->text()+"/");}

//WHEN MODULOS IS PRESSED!
void addition::on_Button_modulos_clicked(){
    ui-> lineEdit_Eingabezahl->setText(ui->lineEdit_Eingabezahl->text()+"%");}

//WHEN POWER IS PRESSED!
void addition::on_Button_power_clicked(){
    ui-> lineEdit_Eingabezahl->setText(ui->lineEdit_Eingabezahl->text()+"^");}




//THE CALCULATION STARTS NOW IF THE EQUAL BUTTON IS CLICKED
void addition::on_Button_equal_clicked(){
    QString Eingabefeld= ui->lineEdit_Eingabezahl->text();      //Eingabefeld ist das was im GUI eingegeben worden ist
    char *cStr = Eingabefeld.toUtf8().data();                   //Dafür müssen wir den Qstring konvertieren
    strcpy(input, cStr);                                        //Das Konvertierte wird nun in input gespeichert
    input_length = strlen(input);

    for(to = 0, index = 0 ; index<=input_length ; index++){     //Entfernung aller Leerzeichen!!!
        if(*(input+index) != ' ')
            *(input+to++) = *(input+index);
    }

    int result = aundb(0, strlen(input) - 1);   //strlen gibt die Anzahl in reellen Werte an. Da wir aber das erste Element
    QString s = QString::number(result);        //im Code immer als 0 haben müssen wir den strlen-1 machen.
    ui->lineEdit_Test->setText(s);              //Auch haben wir den Qstring in eine Zahl konvertiert
}


/*Funktion zum Verrechnen der Zahlen miteinander*/
int addition::calc(int op, int x, int y){
        switch (op) {
        case '+':   return x + y;
        case '-':   return x - y;
        case '*':   return x * y;
        case'^':	return pow(x,y);
        case '/':   return x / y;
        case '%':  	return x % y;
        }
        return 0;
}


/*Zum zusammenfassen der einzelnen Elemente der Teilstring zu einer einzelnen Zahl*/
int addition::zahl(int zahl1, int zahl2){
    int ziffer = 0;
    int i;
    for(i = zahl1; i <= zahl2; i++) {
        int n = input[i] - '0';
        if (n < 0 || n > 9) return -1;      //falls ein Buchstabe eingegeben wurde, wird das Programm mit return -1 beendet!
        ziffer = 10 * ziffer + n;           //Bsp. 23, die erste Ziffer ist 2, muss aber *10 genommen werden
    }                                       //Wir arbeiten im Zehnersystem
    return ziffer;
}

/*Funktion die den Operanden Werte und somit Priorität zuweist*/
int addition::low_high(int op){
    switch (op) {
    case '+':   return 1;
    case '-':   return 1;
    case '*':   return 2;
    case '^':	return 2;
    case '/':   return 2;
    case '%':	return 2;
    }
return 0;
}


int addition::aundb(int anfang, int ende){
    int i;
    int oper = -1;
    if (anfang > ende) return 0;

    for(i = anfang; i <= ende; i++) {
        int c = input[i];
        int n = low_high(c);
        if (n && (oper < 0 || n < low_high(input[oper]))) {  //Überprüfung der Rangordnung zwischen den Operanden
            oper = i;                                        //Speicherung des Indexes an dem sich der Operand befindet
        }
    }

    if (oper >= 0) {                                         //Der String wird an der Stelle des Operanden gesplittet
        int a = aundb(anfang, oper - 1);                     //Funktion ruft sich selbst auf -> Rekursion
        int b = aundb(oper + 1, ende);
        int res =  calc(input[oper], a, b);                  //Berrechnung der entdeckten Zahlen
        return res;
    }
    else {
        int res = zahl(anfang, ende);
        if (res < 0) { exit(1); }                            //falls kein Operand entdeckt wurde und kein Zwischenergebnis vorliegt ist die
            else {return res; }                              //eingegeben Gleichung ungültig und das Program wird mithilfe von exit beendet!
        }
        return 0;
    }

