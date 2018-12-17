
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

const int MAX_LEN = 100;
// string dict[] = { "this", "i", "saw", "is", "awesome", "some" } ;

string dict[] = { "ab", "abc", "d", "de", "ef" } ;

bool searchDict (string t)
{
        int size = sizeof(dict)/sizeof(dict[0]) ;
        if ( find (dict, dict + size, t) != dict+size )
                return true;
        return false;
}

void printSpacedWords (bool dict[][MAX_LEN], bool word[][MAX_LEN], vector < vector<int> > path ,
                                           string s, int start, int end)
{
        if ( end == 0)
                return ;

        int k = path [start][end];
        string t ;

        if ( dict [start][k] ) {
                t = s.substr (start, k-start+1) ;
                cout << t << " " ;
        }
        else
                printSpacedWords (dict, word, path, s, start, k) ;

        if ( dict [k+1][end] ) {
                t = s.substr (k+1, end-k) ;
                cout << t << " " ;
        }
        else
                printSpacedWords (dict, word, path, s, k+1, end) ;
}

int main()
{
        bool word [MAX_LEN] [MAX_LEN] = {0};
        bool dict [MAX_LEN] [MAX_LEN] = {0};
        string s ;
        cin >> s;
        int n = s.size() ;

        vector < vector<int> > path ( n, vector<int> (n, -1) ) ;

        //populate dict[][]
        for(int i = 0; i < n; i++)
        {
                for(int j = i; j < n; j++) {
                        string t = s.substr (i, j-i+1) ;
                        dict[i][j] = searchDict (t);
                        if ( dict[i][j] )
                                path [i][j] = i  ;
                }
        }

        //populate word[][] for substring of length 1
        for(int i = 0; i < n; i++)
                word [i][i] = dict [i][i];

        for(int len = 2; len <= n; len++)
                for(int i = 0; i <= n-len; i++)
                {
                        int j = i + len - 1;
                        word [i][j] = dict [i][j] ;

                        for(int k=i; k < j; k++)
                                if ( word [i][k] && word [k+1][j] )
                                {
                                        word [i][j] = true ;
                                        path [i][j] = k ;
                                }
                }

        printSpacedWords (dict, word, path, s, 0, n-1);

        return 0;
}