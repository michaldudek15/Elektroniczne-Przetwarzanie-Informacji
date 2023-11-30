#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

const int intMax = 2147483647;
const int maxSize = 100;


struct QueueEl
{
	
    int priority, data;
};


class priorityqueue
{
    private:
        QueueEl T[ maxSize ];
        int n;

    public:
        priorityqueue( );
        ~priorityqueue( );
        bool empty ( void );
        int findmaxdata ( void );
        int findmaxpriority ( void );
        void insert ( int priority, int data );
        void deletemax ( void );
        void print ( void);
};


priorityqueue::priorityqueue( )
{
    n=0;
}

priorityqueue::~priorityqueue( )
{

}


bool priorityqueue::empty ( void )
{
    return !n;
}

int priorityqueue::findmaxdata ( void )
{
    if (n) return T[1].data;
    else        return intMax;
}

int priorityqueue::findmaxpriority ( void )
{
    if (n) return T[1].priority;
    else        return intMax;
}

void priorityqueue::insert ( int priority, int data )
{
    int i, j;

    n++;
    i=n;

	//do T[i] wstaw element z argumentu funkcji

    //do j wstaw ojca i (ze wzoru)

    //dopóki (i nie jest korzeniem oraz priorytet elementu wstawianego jest wiêkszy od priorytetu elementu pod indeksem j (to ojciec)
	//    {
   	//	  zamieñ T[i] i T[j] miejscami
    // 	  do i wstaw j
    //    do j wstaw ojca i
    //    }

}


void priorityqueue::deletemax ( void )
{
    int i, d, p, older; //starszy syn

        p = T [ n ].priority;
        d = T [ n ].data;

        n--;

    if()//je¿eli kopiec nie jest pusty
    {

        i=1;
        T [ i ].priority = p;
        T [ i ].data = d;

        while( i < n )
        {
			// do older wstaw indeks starszego syna (pilnuj czy s¹ obaj synowie)
			// je¿eli p jest mniejsze od priorytetu starszego syna
            //{
      			//zamieñ miejscami wêze³ spod indeksu i z jego straszym synem
      			//do i wstaw indeks starszego syna
      		//}
      		// w przeciwnym wypadku wychodzimy z pêtli np. i=n; lub break;
        }
    }
}


int main( )
{
    priorityqueue Q;
    int i, p, v;
    
    setlocale(LC_CTYPE, "Polish");

    srand ( time ( NULL ) );

    cout << "wprowadzone elementy w postaci element:priorytet\n";
    
    for( i = 1; i <= 10; i++ )
    {
        v = i;
        p = rand( ) % 100;
        cout << v << "|" << p << endl;
        Q.insert (p, v);
    }
    
    //¿eby sprawdziæ czy dzia³a samo insert nale¿y usun¹æ poni¿sze
	//dodaæ wypisywanie tablicy i sprawdziæ (rêcznie) czy jest sep³niony warunek kopca

    cout << "\n" << "kolejka priorytetowa w postaci element:priorytet\n";

    while ( !Q.empty( ) )
   {
       cout << Q.findmaxdata( ) << "|" << Q.findmaxpriority( ) << endl;
       Q.deletemax( );
   }
}
