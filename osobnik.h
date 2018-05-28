#ifndef OSOBNIK_H
#define OSOBNIK_H

class Osobnik
{
private:
    double x1;
    double x2;
    bool znak1; // 0 dla + i 1 dla -
    bool znak2; // 0 dla + i 1 dla -
public:

    Osobnik() : x1(0), x2(0), znak1(0), znak2(0) {}
    Osobnik(double x, double y, bool zn1, bool zn2) : x1(x), x2(y), znak1(zn1), znak2(zn2) {}
    Osobnik(Osobnik &os) : x1(os.x1), x2(os.x2), znak1(os.znak1), znak2(os.znak2) {}

    double gett_x1();
    double gett_x2();
    char gett_znak1();
    char gett_znak2();

    void Kopiuj(Osobnik os);

    //funkce testujące
    double DeJonga();
    double FSRP(); //Suma różnych potęg
    double Rosenbrocka();
    double Rastrigina();
    void Selekcja();

    Osobnik Krzyzowanie(Osobnik R1, Osobnik R2);

    double ZamienCyfre(double liczba, int poz, int war);

    //operatory mutacji
    void Rownomierna();
    void Brzegowa();
    Osobnik WymianaDeJonga(Osobnik os);
    Osobnik WymianaFSRP(Osobnik os);
    Osobnik WymianaRosenbrocka(Osobnik os);
    Osobnik WymianaRastrigina(Osobnik os);
    Osobnik WspinaczkowaDeJonga(Osobnik os);
    Osobnik WspinaczkowaFSRP(Osobnik os);
    Osobnik WspinaczkowaRosenbrocka(Osobnik os);
    Osobnik WspinaczkowaRastrigina(Osobnik os);
};

#endif // OSOBNIK_H
