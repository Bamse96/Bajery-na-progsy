#include <iostream>
#include <stdlib.h>

using namespace std;

class Bron
{
public:
    virtual void obrona()=0;
    virtual void atak()=0;

    virtual ~Bron(){}

};

class MieczStalowy: public Bron
{
public:
    void atak(){cout<<"Atak mieczem stalowym."<<endl;}
    void obrona(){cout<<"Obrona mieczem stalowym."<<endl;}

    ~MieczStalowy(){}
};

class MieczSrebrny: public Bron
{
public:
    void atak(){cout<<"Atak mieczem srebrnym."<<endl;}
    void obrona(){cout<<"Obrona mieczem srebrnym."<<endl;}

    ~MieczSrebrny(){}
};

class Kusza: public Bron
{
public:
    void atak(){cout<<"Atak Kusza."<<endl;}
    void obrona(){cout<<"Obrona Kusza."<<endl;}

    ~Kusza(){}
};

int wybor()
{
    int rodzaj_broni=0;

    while(rodzaj_broni!=1&&rodzaj_broni!=2&&rodzaj_broni!=3)
    {

        cout<<"Wybierz bron: 1 Miecz Stalowy, 2 Miecz Srebrny, 3 Kusza. "<<endl;
        cin>>rodzaj_broni;

        if(rodzaj_broni!=1&&rodzaj_broni!=2&&rodzaj_broni!=3)
            cout<<"Nie wybrano broni!"<<endl;

    }



    return rodzaj_broni;
}

Bron* ustaw_wskaznik(int wybor_broni)
{
    Bron* wsk;

    if(wybor_broni==1)
        wsk=new MieczStalowy;
    else if(wybor_broni==2)
        wsk= new MieczSrebrny;
    else if(wybor_broni==3)
        wsk= new Kusza;
    else
    {
        cout<<"Cos popsules D:"<<endl;
        exit(EXIT_FAILURE);
    }

    return wsk;
}

int main()
{
    Bron* wsk;
    int wybor_broni=wybor();

    wsk=ustaw_wskaznik(wybor_broni);

    wsk->atak();
    wsk->obrona();


return 0;
}
