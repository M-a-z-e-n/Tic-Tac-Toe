// Libraries
#include <bits/stdc++.h>
using namespace std;

void draw(char arr[4][4]);

int main(){

    char arr[4][4] = {0} ;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            arr[i][j] = '.' ;
        }
    }

    bool win = 0;
    cout << "Which player want to start ? \n";
    cout << "( X ) or ( O ) \n";
    string cc;
    cin >> cc;
    while ( cc.size() > 1 || (cc[0] != 'X' && cc[0] != 'O' && cc[0] != 'x' && cc[0] != 'o') ) {
        cout << "the character been entered isn't valid , please choose between ( X ) or ( O ) \n";
        cin >> cc;
    }

    bool ch;
    ch = (cc[0] == 'X' || cc[0] == 'x');

    bool player = 1;

    for (int i = 0; i < 16 ; ++i) {

        int row , col;
        cout << "Player " << ( player ? 1 : 2 ) << " Enter the Row & Column for your next move \n";
        cin >> row >> col;

        while( row < 1 || row > 4 || col < 1 || col > 4 ){
            cout << "Out of bounds! , try another one :\n";
            cin >> row >> col ;
        }

        while( arr[row-1][col-1] != '.' ){
            cout << "It's an occupied position! try another one :\n";
            cin >> row >> col ;
        }

        if ( ch ) {
            arr[row - 1][col - 1] = 'X';
        } else {
            arr[row - 1][col - 1] = 'O';
        }

        draw(arr);

        char c ;

        if( ch ) c = 'X';
        else c = 'O';

        bool a = 1 , b = 1 , z = 1 , d = 1;

        for (int j = 0; j < 4; ++j) {
            if( arr[j][col - 1] != c ) a = 0;
            if( arr[row - 1][j] != c ) b = 0;
        }

        for (int j = 0; j < 4; ++j) {
            if( arr[j][j] != c ) z = 0;
        }

        for (int j = 0 , k = 3 ; j < 4 , k >= 0 ; ++j , k-- ) {
            if( arr[j][k] != c ) d = 0;
        }

        if( a || b || z || d ){
            player ? (cout << "Player 1 Wins \n") : (cout << "Player 2 Wins \n")  ;
            win = 1;
            break ;
        }

        ch = !ch;
        player = !player;

    }
    if(!win) cout << "Draw\n";

    cout<<"Do u want to play again (y/n) ? : ";
    char again ; cin >> again ;
    if( again == 'Y' || again == 'y' )
        main();
    else
        return 0;
}

void draw(char arr[4][4])
{
    for(int i = 0; i < 4;i++)
    {
        for(int j = 0; j < 4; j++) {
            cout << ' ' << arr[i][j] ;
            if (j != 3) cout << " |";
        }
        cout<<endl;
    }
}
