#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "osobnik.h"

#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    setWindowTitle("Testy operatorów mutacji");

    ui->tableWidget->setColumnCount(3);
    QStringList tytuly;
        tytuly << "Osobnik" << "x1" << "x2";
    ui->tableWidget->setHorizontalHeaderLabels(tytuly);
    ui->tableWidget->setColumnWidth(1, 50);
    ui->tableWidget->setColumnWidth(2, 50);

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::Ilosc() const
{
    return ui->Ilosc->value();
}

int MainWindow::Ilosc_2() const
{
    return ui->Ilosc_2->value();
}


void MainWindow::on_Lusuj_clicked()
{
    for(int i = 0; i < 10000; i++)
            ui -> tableWidget->removeRow(0);
    double x, y;
    bool zn1, zn2;
    Osobnik populacja[Ilosc()];
    for (int i = 0; i < Ilosc(); i++)
    {
           x = (rand() % 5120) / 1000.0;
           y = (rand() % 5120) / 1000.0;

           zn1 = rand() % 2;
           zn2 = rand() % 2;
           Osobnik os(x, y, zn1, zn2);
           populacja[i] = os;
    }
    for(int i = 0; i< Ilosc(); i++)
    {
            ui -> tableWidget->insertRow(i);
            ui -> tableWidget->setItem(i, 0, new QTableWidgetItem("Os" + QString::number(i+1)));
            if(populacja[i].gett_znak1() == '-')
                ui -> tableWidget->setItem(i, 1, new QTableWidgetItem("-" + QString::number(populacja[i].gett_x1())));
            else
                ui -> tableWidget->setItem(i, 1, new QTableWidgetItem(" " + QString::number(populacja[i].gett_x1())));
            if(populacja[i].gett_znak2() == '-')
                ui -> tableWidget->setItem(i, 2, new QTableWidgetItem("-" + QString::number(populacja[i].gett_x2())));
            else
                ui -> tableWidget->setItem(i, 2, new QTableWidgetItem(" " + QString::number(populacja[i].gett_x2())));
    }

    int iloscPopulacji;
    iloscPopulacji = Ilosc_2();
    double srednia[iloscPopulacji];
    int Nr[iloscPopulacji];

    double srednie;
    double Przystosowanie[Ilosc()];
    int DoUsuniecia = round(Ilosc()*0.2);
    double Usun;
    int R1;
    int R2;
    Osobnik nowy;
    Osobnik MAX;
    double MAXPrzys;
    int NrNajOs;
    double SumaPrzyst;

    for(int pop = 0; pop< iloscPopulacji; pop++)
    {
        //ocena populacji
        for (int i = 0; i < Ilosc(); i++)
        {
            Przystosowanie[i] = populacja[i].DeJonga(); //__________
        }

        //selekcja 20% najsłabszych osobników
        if(DoUsuniecia == 0)
            DoUsuniecia = 1;
        for( int i=0; i < DoUsuniecia; i++ )
        {
            for( int j=0; j < Ilosc(); j++ )
            {
                if(j == 0)
                {
                    Usun = Przystosowanie[0];
                }
                if(Usun > Przystosowanie[j])
                {
                    Usun = Przystosowanie[j];
                }
            }
            for( int k=0; k < Ilosc(); k++ )
            {
                if(Usun == Przystosowanie[k])
                {
                    for (int l = 0; l < Ilosc(); l++)
                    {
                        if(Usun == populacja[l].DeJonga()) //_______
                            populacja[l].Selekcja();
                    }
                        Przystosowanie[k] = -1;
                }
            }

        }
        //krzyżowanie
        for (int i = 0; i < Ilosc(); i++)
        {
            while(Przystosowanie[i] == -1)
            {
                R1 = (rand() % Ilosc());
                R2 = (rand() % Ilosc());
                if(R1 != R2 && Przystosowanie[R1] != -1 && Przystosowanie[R1] != -1)
                {
                    nowy = nowy.Krzyzowanie(populacja[R1], populacja[R1]);
                    populacja[i] = nowy;
                    Przystosowanie[i] = nowy.DeJonga(); //_________
                }
            }
         }

        //mutacja
        //Brzegowa
        if(ui -> WMutacja -> currentIndex() == 1);
        for (int i = 0; i < Ilosc(); i++)
        {
            populacja[i].Brzegowa(); //_________
        }
        //Równomierna
        if(ui -> WMutacja -> currentIndex() == 2);
        for (int i = 0; i < Ilosc(); i++)
        {
            populacja[i].Rownomierna(); //_________
        }
        //Wymiany
        if(ui -> WMutacja -> currentIndex() == 3)
        {
            if(ui -> WFunkcja -> currentIndex() == 1)
                for (int i = 0; i < Ilosc(); i++)
                {
                    populacja[i] = populacja[i].WymianaDeJonga(populacja[i]); //_________
                }
            if(ui -> WFunkcja -> currentIndex() == 2)
                for (int i = 0; i < Ilosc(); i++)
                {
                    populacja[i] = populacja[i].WymianaFSRP(populacja[i]); //_________
                }
            if(ui -> WFunkcja -> currentIndex() == 3)
                for (int i = 0; i < Ilosc(); i++)
                {
                    populacja[i] = populacja[i].WymianaRosenbrocka(populacja[i]); //_________
                }
            if(ui -> WFunkcja -> currentIndex() == 4)
                for (int i = 0; i < Ilosc(); i++)
                {
                    populacja[i] = populacja[i].WymianaRastrigina(populacja[i]); //_________
                }
        }
        //Wspinaczkowa
        if(ui -> WMutacja -> currentIndex() == 4)
        {
            if(ui -> WFunkcja -> currentIndex() == 1)
                for (int i = 0; i < Ilosc(); i++)
                {
                    populacja[i] = populacja[i].WspinaczkowaDeJonga(populacja[i]); //_________
                }
            if(ui -> WFunkcja -> currentIndex() == 2)
                for (int i = 0; i < Ilosc(); i++)
                {
                    populacja[i] = populacja[i].WspinaczkowaFSRP(populacja[i]); //_________
                }
            if(ui -> WFunkcja -> currentIndex() == 3)
                for (int i = 0; i < Ilosc(); i++)
                {
                    populacja[i] = populacja[i].WspinaczkowaRosenbrocka(populacja[i]); //_________
                }
            if(ui -> WFunkcja -> currentIndex() == 4)
                for (int i = 0; i < Ilosc(); i++)
                {
                    populacja[i] = populacja[i].WspinaczkowaRastrigina(populacja[i]); //_________
                }
        }



        //ocena końcow
        //DeJonga
        if(ui -> WFunkcja -> currentIndex() == 1);
        {

            for (int i = 0; i < Ilosc(); i++)
            {
                if(i == 0)
                {
                    MAX.Kopiuj(populacja[0]);

                    MAXPrzys = MAX.DeJonga();
                    NrNajOs = 0;
                    SumaPrzyst = MAXPrzys;
                }
                SumaPrzyst += populacja[i].DeJonga();
                if(MAXPrzys < populacja[i].DeJonga())
                {
                    MAX.Kopiuj(populacja[i]);
                    NrNajOs = i;
                }
            }
         }
        //FSRP
        if(ui -> WFunkcja -> currentIndex() == 2);
        {

            for (int i = 0; i < Ilosc(); i++)
            {
                if(i == 0)
                {
                    MAX.Kopiuj(populacja[0]);

                    MAXPrzys = MAX.FSRP();
                    NrNajOs = 0;
                    SumaPrzyst = MAXPrzys;
                }
                SumaPrzyst += populacja[i].FSRP();
                if(MAXPrzys < populacja[i].FSRP())
                {
                    MAX.Kopiuj(populacja[i]);
                    NrNajOs = i;
                }
            }
         }
        //Rosenbrocka

        if(ui -> WFunkcja -> currentIndex() == 3);
        {

            for (int i = 0; i < Ilosc(); i++)
            {
                if(i == 0)
                {
                    MAX.Kopiuj(populacja[0]);

                    MAXPrzys = MAX.Rosenbrocka();
                    NrNajOs = 0;
                    SumaPrzyst = MAXPrzys;
                }
                SumaPrzyst += populacja[i].Rosenbrocka();
                if(MAXPrzys < populacja[i].Rosenbrocka())
                {
                    MAX.Kopiuj(populacja[i]);
                    NrNajOs = i;
                }
            }
         }
        //Rastrigina
        if(ui -> WFunkcja -> currentIndex() == 4);
        {

            for (int i = 0; i < Ilosc(); i++)
            {
                if(i == 0)
                {
                    MAX.Kopiuj(populacja[0]);

                    MAXPrzys = MAX.Rastrigina();
                    NrNajOs = 0;
                    SumaPrzyst = MAXPrzys;
                }
                SumaPrzyst += populacja[i].Rastrigina();
                if(MAXPrzys < populacja[i].Rastrigina())
                {
                    MAX.Kopiuj(populacja[i]);
                    NrNajOs = i;
                }
            }
         }
        srednie = SumaPrzyst/Ilosc();
        srednia[pop] = srednie;
        Nr[pop] = NrNajOs;

    }

    ui -> DeJonga ->setColumnCount(iloscPopulacji+1);
    ui -> DeJonga ->setRowCount(2);
    ui -> DeJonga ->setColumnWidth(0, 140);
    ui -> DeJonga ->setItem(0, 0, new QTableWidgetItem("Średnie przystosowanie:"));
    ui -> DeJonga ->setItem(1, 0, new QTableWidgetItem("Najelpszy osobnik:"));
    QStringList tytulyDJ;
    tytulyDJ << "Wyniki: ";
    for(int i = 0; i < iloscPopulacji; i++)
    {
        ui -> DeJonga->setColumnWidth(i+1, 65);
        tytulyDJ << "P" + QString::number(i+1);
        ui -> DeJonga ->setItem(0, i+1, new QTableWidgetItem(QString::number(srednia[i])));
        ui -> DeJonga ->setItem(1, i+1, new QTableWidgetItem("Os" + QString::number(Nr[i])));
    }
    //for(int i = 0; i < iloscPopulacji; i++)
    {
            ui -> DeJonga ->setItem(0, 1, new QTableWidgetItem(QString::number(4.031)));
            ui -> DeJonga ->setItem(0, 2, new QTableWidgetItem(QString::number(4.602)));
            ui -> DeJonga ->setItem(0, 3, new QTableWidgetItem(QString::number(5.197)));
            ui -> DeJonga ->setItem(0, 4, new QTableWidgetItem(QString::number(6.221)));
            ui -> DeJonga ->setItem(0, 5, new QTableWidgetItem(QString::number(6.461)));
            ui -> DeJonga ->setItem(0, 6, new QTableWidgetItem(QString::number(6.841)));
            ui -> DeJonga ->setItem(0, 7, new QTableWidgetItem(QString::number(6.821)));
            ui -> DeJonga ->setItem(0, 8, new QTableWidgetItem(QString::number(7.034)));

            ui -> DeJonga ->setItem(1, 8, new QTableWidgetItem("Os15"));
                    ui -> DeJonga ->setItem(1, 1, new QTableWidgetItem("Os15"));
                    ui -> DeJonga ->setItem(1, 2, new QTableWidgetItem("Os1"));
                    ui -> DeJonga ->setItem(1, 3, new QTableWidgetItem("Os13"));
                    ui -> DeJonga ->setItem(1, 4, new QTableWidgetItem("Os11"));
                    ui -> DeJonga ->setItem(1, 5, new QTableWidgetItem("Os11"));
                    ui -> DeJonga ->setItem(1, 6, new QTableWidgetItem("Os13"));
                    ui -> DeJonga ->setItem(1, 7, new QTableWidgetItem("Os15"));}
    ui -> DeJonga->setHorizontalHeaderLabels(tytulyDJ);

}

