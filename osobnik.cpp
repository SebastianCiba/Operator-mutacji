#include <cmath>
#include <cstdlib>
#include <time.h>
#include "osobnik.h"

double Osobnik::gett_x1()
{
    return x1;
}

double Osobnik::gett_x2()
{
    return x2;
}

char Osobnik::gett_znak1()
{
    if(znak1 == 0)
    return '-';
    else return ' ';
}

char Osobnik::gett_znak2()
{
    if(znak2 == 0)
    return '-';
    else return ' ';
}

void Osobnik::Kopiuj(Osobnik os)
{
    this->x1 = os.x1;
    this->x2 = os.x2;
    this->znak1 = os.znak1;
    this->znak2 = os.znak2;
}


double Osobnik::DeJonga()
{
/*
    double z1, z2;
    if(znak1 == 0)
        z1 = x1;
    else
        z1 = - x1;

    if(znak2 == 0)
        z2 = x2;
    else
        z2 = - x2;
*/
    return x1 * x1 + x2 * x2;
}



double Osobnik::FSRP()
{
    double z1, z2;
    if(znak1 == 0)
        z1 = x1;
    else
        z1 = -x1;

    if(znak2 == 0)
        z2 = x2;
    else
        z2 = -x2;
    return z1 * z1 + abs(z2 * z2 * z2);
}


double Osobnik::Rosenbrocka()
{
    double z1, z2;
    if(znak1 == 0)
        z1 = x1;
    else
        z1 = -x1;

    if(znak2 == 0)
        z2 = x2;
    else
        z2 = -x2;
    return (1 - z1)*(1 - z1) + 100 * (z2 - z1 * z1)*(z2 - z1 * z1);
}


double Osobnik::Rastrigina()
{
    double z1, z2;
    if(znak1 == 0)
        z1 = x1;
    else
        z1 = -x1;

    if(znak2 == 0)
        z2 = x2;
    else
        z2 = -x2;
    return 20 + (z1 * z1 - 10 * cos(2 * M_PI * z1))+(z2 * z2 - 10 * cos(2 * M_PI * z2));
}


/*
//-500 do 500
double Schwefela(double x1, double x2)
{
    double z1, z2;
    if(znak1 == 0)
        z1 = x1;
    else
        z1 = -x1;

    if(znak2 == 0)
        z2 = x2;
    else
        z2 = -x2;
        return -z1*sin(sqrt(abs(z1)))-z2*sin(sqrt(abs(z2)));
}
*/

//The Michalewicz function
//f12(x)=-sum(sin(x(i))·(sin(i·x(i)^2/pi))^(2·m)), i=1:n, m=10 0<=x(i)<=pi.

void Osobnik::Selekcja()
{
    x1 = 0.0;
    x2 = 0.0;
    znak1 = 0;
    znak2 = 0;
}

Osobnik Osobnik::Krzyzowanie(Osobnik R1, Osobnik R2)
{
    Osobnik Potomek;
    Potomek.x1 = R1.x1;
    Potomek.x2 = R2.x2;
    Potomek.znak1 = R1.znak1;
    Potomek.znak2 = R2.znak2;
    return Potomek;
}

double Osobnik::ZamienCyfre(double liczba, int poz, int war)
{
    int c0, c1, c2, c3;
    int l = liczba * 1000;
    c3 = l % 10;
    l /= 10;
    c2 = l % 10;
    l /= 10;
    c1 = l % 10;
    l /= 10;
    c0 = l % 10;
    if (poz == 0)
        c0 = war;
    else if (poz == 1)
        c1 = war;
    else if (poz == 2)
        c2 = war;
    else if (poz == 3)
        c3 = war;
    return (c0 * 1000 + c1 * 100 + c2 * 10 + c3) / 1000.0;
}

void Osobnik::Rownomierna()
{
    //pierwsza zmienna
    bool przedzial = false;
    int pozycja;
    int wartosc;
    while (przedzial == false)
    {
        pozycja = rand() % 4;
        wartosc = rand() % 10;
        x1 = ZamienCyfre(x1, pozycja, wartosc);
        if (x1 <= 5.12)
            przedzial = true;
        else
            przedzial = false;
    }

    //druga zmienna
    przedzial = false;
    while (przedzial == false)
    {
        pozycja = rand() % 4;
        wartosc = rand() % 10;
        x2 = ZamienCyfre(x2, pozycja, wartosc);
        if (x2 <= 5.12)
            przedzial = true;
        else
            przedzial = false;
    }
}

void Osobnik::Brzegowa()
{
    x1 *= 100;
    x1 = round(x1);
    x1 /= 100;

    x2 *= 100;
    x2 = round(x2);
    x2 /= 100;
}

Osobnik Osobnik::WymianaDeJonga(Osobnik os)
{
    double x = (rand() % 5120) / 1000.0;
    double y = (rand() % 5120) / 1000.0;
    bool zn1 = rand() % 2;
    bool zn2 = rand() % 2;
    Osobnik nowy(x, y, zn1, zn2);
    if (nowy.DeJonga() > os.DeJonga())
        return nowy;
    else
        return os;
}

Osobnik Osobnik::WymianaFSRP(Osobnik os)
{
    double x = (rand() % 5120) / 1000.0;
    double y = (rand() % 5120) / 1000.0;
    bool zn1 = rand() % 2;
    bool zn2 = rand() % 2;
    Osobnik nowy(x, y, zn1, zn2);
    if (nowy.FSRP() > os.FSRP())
        return nowy;
    else
        return os;
}

Osobnik Osobnik::WymianaRosenbrocka(Osobnik os)
{
    double x = (rand() % 5120) / 1000.0;
    double y = (rand() % 5120) / 1000.0;
    bool zn1 = rand() % 2;
    bool zn2 = rand() % 2;
    Osobnik nowy(x, y, zn1, zn2);
    if (nowy.Rosenbrocka() > os.Rosenbrocka())
        return nowy;
    else
        return os;
}

Osobnik Osobnik::WymianaRastrigina(Osobnik os)
{
    double x = (rand() % 5120) / 1000.0;
    double y = (rand() % 5120) / 1000.0;
    bool zn1 = rand() % 2;
    bool zn2 = rand() % 2;
    Osobnik nowy(x, y, zn1, zn2);
    if (nowy.Rastrigina() > os.Rastrigina())
        return nowy;
    else
        return os;
}

Osobnik Osobnik::WspinaczkowaDeJonga(Osobnik os)
{
    Osobnik os1(os.x1+0.01, os.x2, os.znak1, os.znak2);
    Osobnik os2(os.x1-0.01, os.x2, os.znak1, os.znak2);
    Osobnik os3(os.x1, os.x2+0.01, os.znak1, os.znak2);
    Osobnik os4(os.x1, os.x2-0.01, os.znak1, os.znak2);
    Osobnik wynik;
    double Test_os1 = os1.DeJonga();
    double Test_os2 = os2.DeJonga();
    double Test_os3 = os3.DeJonga();
    double Test_os4 = os4.DeJonga();
    double max = Test_os1;

    if(Test_os2 > max)
    {	max = Test_os2;
        wynik.Kopiuj(os2);
    }
    if(Test_os3 > max)
    {
        max = Test_os3;
        wynik.Kopiuj(os3);
    }
    if(Test_os4 > max)
    {
        max = Test_os4;
        wynik.Kopiuj(os4);
    }
    else
        wynik.Kopiuj(os1);
    return wynik;
}

Osobnik Osobnik::WspinaczkowaFSRP(Osobnik os)
{
    Osobnik os1(os.x1+0.01, os.x2, os.znak1, os.znak2);
    Osobnik os2(os.x1-0.01, os.x2, os.znak1, os.znak2);
    Osobnik os3(os.x1, os.x2+0.01, os.znak1, os.znak2);
    Osobnik os4(os.x1, os.x2-0.01, os.znak1, os.znak2);
    Osobnik wynik;
    double max = os1.FSRP();
    wynik.Kopiuj(os1);
    if(os2.FSRP() > max)
    {	max = os2.FSRP();
        wynik.Kopiuj(os2);
    }
    if(os3.FSRP() > max)
    {
        max = os3.FSRP();
        wynik.Kopiuj(os3);
    }
    if(os4.FSRP() > max)
    {
        max = os4.FSRP();
        wynik.Kopiuj(os4);
    }
    return wynik;
}

Osobnik Osobnik::WspinaczkowaRosenbrocka(Osobnik os)
{
    Osobnik os1(os.x1+0.01, os.x2, os.znak1, os.znak2);
    Osobnik os2(os.x1-0.01, os.x2, os.znak1, os.znak2);
    Osobnik os3(os.x1, os.x2+0.01, os.znak1, os.znak2);
    Osobnik os4(os.x1, os.x2-0.01, os.znak1, os.znak2);
    Osobnik wynik;
    double Test_os1 = os1.Rosenbrocka();
    double Test_os2 = os2.Rosenbrocka();
    double Test_os3 = os3.Rosenbrocka();
    double Test_os4 = os4.Rosenbrocka();
    double max = Test_os1;
    wynik.Kopiuj(os1);
    if(Test_os2 > max)
    {	max = Test_os2;
        wynik.Kopiuj(os2);
    }
    if(Test_os3 > max)
    {
        max = Test_os3;
        wynik.Kopiuj(os3);
    }
    if(Test_os4 > max)
    {
        max = Test_os4;
        wynik.Kopiuj(os4);
    }
    return wynik;
}

Osobnik Osobnik::WspinaczkowaRastrigina(Osobnik os)
{
    Osobnik os1(os.x1+0.01, os.x2, os.znak1, os.znak2);
    Osobnik os2(os.x1-0.01, os.x2, os.znak1, os.znak2);
    Osobnik os3(os.x1, os.x2+0.01, os.znak1, os.znak2);
    Osobnik os4(os.x1, os.x2-0.01, os.znak1, os.znak2);
    Osobnik wynik;
    double Test_os1 = os1.Rastrigina();
    double Test_os2 = os2.Rastrigina();
    double Test_os3 = os3.Rastrigina();
    double Test_os4 = os4.Rastrigina();
    double max = Test_os1;

    if(Test_os2 > max)
        max = Test_os2;
    if(Test_os3 > max)
        max = Test_os3;
    if(Test_os4 > max)
        max = Test_os4;

    if(max == Test_os1)
        wynik.Kopiuj(os1);
    else if(max == Test_os2)
        wynik.Kopiuj(os2);
    else if(max == Test_os3)
        wynik.Kopiuj(os3);
    else if(max == Test_os4)
        wynik.Kopiuj(os4);
    return wynik;
}
