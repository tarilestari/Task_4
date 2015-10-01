#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "list.h"
#include "player.h"
using namespace std;

void input_music (infotype &x)
{
    cout<<"=====IMPORT MUSIC====="<<endl;
    cout<<"Input music name (.wav) : ";
    cin>>x.name;
    cout<<"Input music location (write - for default location) : ";
    cin>>x.location;
    cout<<"======================"<<endl;
    if(x.location=="-")
        x.location="";
}

void print_info (list L)
{
    address Q;

    Q=first(L);
    if (Q!=NULL)
    {
        cout<<"=====VIEW PLAYLIST====="<<endl;
        cout<<info(Q).id<<" "<<info(Q).name<<endl;
        Q=next(Q);
        while(Q!=first(L))
        {
            cout<<info(Q).id<<" "<<info(Q).name<<endl;
            Q=next(Q);
        }
    }
    else
    {
        cout<<"=====VIEW PLAYLIST====="<<endl;
        cout<<"No music"<<endl;
    }
}

void play_prev (address &P)
{
    P=prev(P);
    play_music(P);
}

void play_last_played (address &P)
{
    play_music(P);
}

void play_repeat (list &L, address P)
{
    int n;

    cout<<"Repeat untuk : ";
    cin>>n;
    while (n>0)
    {
        P=first(L);
        play_music(P);
        play_next(P);
        while (P!=last(L))
        {
            play_next(P);
        }
        n--;
    }
}
