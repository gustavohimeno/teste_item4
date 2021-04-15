#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

/* função que retorna o mínimo de operações necessários para transformar
uma string em outra removendo e inserindo caracteres no seu fim */
int min_ops(string first, string sec, int i, int j, int &count)
    {
    int min_ops = 0;
    
    for(count = 0; count < i; count++)
        {
        if(first[count] != sec[count])
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
    int i = s.size()-1;
    int j = t.size()-1;
    
    //when k bigger than (i+j) I can remove all characters and concat all the new
    if(k > i+j)
        {
        return true;
        }
    
    //when k smaller than (i+j) i have to analyse the minimum operations necessary to convert
    int count = 0;
    int ops = min_ops(s, t, i, j, count);
    if(ops == k)
        {
        return true;
        }
    if(ops > k)
        {
        return false;
        }
    
    //when ops < k, I have 2 alternatives: 1- concat and remove, 2- remove when the string is empty
    if((k-ops)%2 == 0)
        {
        return true;
        }
    if(count == 0)
        {
        return true;
        }
    return false;
    }


int main()
    {
    string s = "abc\n";
    string t = "def\n";
    int k = 6;

    //case 1
    if(ConcatRemove(s, t, k))
        {
        printf("teste 1;ok\n");
        }
    else
        {
        printf("teste 1;failed\n");
        }
    
    //case 2
    k = 5;
    if(!ConcatRemove(s, t, k))
        {
        printf("teste 2;ok\n");
        }
    else
        {
        printf("teste 2;failed\n");
        }
    
    //case 3
    s = "blablablabla\n";
    t = "blablabcde\n";
    k = 8;
    if(ConcatRemove(s, t, k))
        {
        printf("teste 3;ok\n");
        }
    else
        {
        printf("teste 3;failed\n");
        }
    
    //case 4 - test for 1 operation more than the minimum, it cannot be transformed
    k = 9;
    if(!ConcatRemove(s, t, k))
        {
        printf("teste 4;ok\n");
        }
    else
        {
        printf("teste 4;failed\n");
        }
    
    //case 5 - test for k very high
    k = 99;
    if(ConcatRemove(s, t, k))
        {
        printf("teste 5;ok\n");
        }
    else
        {
        printf("teste 5;failed\n");
        }
    
    //case 6 - s and t are the same strings, 1 operation, it cannot be transformed
    s = "teste\n";
    t = "teste\n";
    k = 1;
    if(!ConcatRemove(s, t, k))
        {
        printf("teste 6;ok\n");
        }
    else
        {
        printf("teste 6;failed\n");
        }
    
    //case 7 - s and t are the same strings, 2 operations, 1 concat and 1 remove, it can be transformed
    k = 2;
    if(ConcatRemove(s, t, k))
        {
        printf("teste 7;ok\n");
        }
    else
        {
        printf("teste 7;failed\n");
        }
    return 0;
	}