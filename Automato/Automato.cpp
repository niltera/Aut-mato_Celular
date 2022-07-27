#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int i,j,in1,in2,a1,a2;
    char q;

    cout<<"Escolha o tamanho da matriz EX: 5x5 "<<endl;
    cin>>in1>>q>>in2;
    
	cout<<"Escolha a celula de inicio EX: 2x2 "<<endl;
    cin>>a1>>q>>a2;
    
	a1-=1;
    a2-=1;
    
	int A[in1][in2], B[in1][in2];

	for(int i2 = 0; i2 < in1; i2++) //escrevendo a matriz e inicializando as celulas
	{
		cout << endl;
		for(int j2 = 0; j2 < in2; j2++)
		{
			A[i2][j2] = 0;
			B[i2][j2]= 0;

			if(i2 == a1 && j2 == a2)
			{
				A[i2][j2] = 2;
				B[i2][j2]= 2;
			}
			cout << A[i2][j2] << "\t";
		}
	}
	
	cout << "\nInsira qualquer tecla e em seguida pressione ENTER para iniciar a derivação" << endl;
	cin >> q;

	do
	{
				for(i = 0; i <in1 ; i++) //lendo as linhas da matriz A e B
				{
					cout << "\n\t";
					for(j = 0; j < in2; j++) //lendo as colunas da matriz A e B
					{
						switch (A[i][j]) //comparando as matrizes e modificando 
						{
						case 0:
							if(((A[i-1][j]==2)&&((i-1)!=(in1-in1-1))) 
							|| ((A[i + 1][j] == 2)&&((i+1)!=(in1+1)))
							|| ((A[i][j - 1] == 2)&&((j-1)!=(in2-in2-1))) 
							|| ((A[i][j + 1] == 2)&&((j+1)!=(in2))))	//expressão logica para implantar as regras
							{
								B[i][j] = 2;
							}
							break;
						case 1:
							B[i][j] = 0;
							break;
						case 2:
							B[i][j] = 1;
							break;
						}
						cout << B[i][j] << "\t"; //Retorna a matriz resultante
					}
				}

        for(int h=0;h<in1;h++) //atualizando primeira matriz
        {
            for(int k=0;k<in2;k++)
            {
                A[h][k] = B[h][k];
            }
        }
		cout << "\n\n\n[1] + ENTER para próxima derivação\n[0] + ENTER para parar" << endl;
		cin >> q;
		
	}while ((q != '0')&&(q == '1'));
}
