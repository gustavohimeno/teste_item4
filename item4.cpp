#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

/* função que retorna o mínimo de operações necessários para transformar
uma string em outra removendo e inserindo caracteres no seu fim */
int min_ops(string prim, string seg)
    {
    int min_ops = 0;
    int i = prim.size()-1;
    int j = seg.size()-1;
    //
    for(int count = 0; count < i; count++)
        {
        if(prim[count] != seg[count])
            {
            min_ops = i + j - 2*count;
            return min_ops;
            }
        }
    return min_ops;
    }


/* função que retorna se é possível realizar a transformação de uma string em 
outra dado um número k máximo de operações */
bool ConcatRemove(string s, string t, int k)
    {
    int ops = min_ops(s,t);
    if(ops <= k)
        {
        return true;
        }
    else
        {
        return false;
        }
    }


int main()
    {
    string s = "abc\n";
    string t = "def\n";
    int k = 6;

    //testa a função ConcatRemove e retorna se passou no teste - caso 1
    if(ConcatRemove(s, t, k))
        {
        printf("teste 1;ok\n");
        }
    else
        {
        printf("teste 1;falhou\n");
        }
    
    //testa a função ConcatRemove e retorna se passou no teste - caso 2
    k = 5;
    if(!ConcatRemove(s, t, k))
        {
        printf("teste 2;ok\n");
        }
    else
        {
        printf("teste 2;falhou\n");
        }
    
    }
