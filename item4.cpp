
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
    
    //case 4
    k = 9;
    if(!ConcatRemove(s, t, k))
        {
        printf("teste 4;ok\n");
        }
    else
        {
        printf("teste 4;failed\n");
        }
    
    //case 5
    k = 99;
    if(ConcatRemove(s, t, k))
        {
        printf("teste 5;ok\n");
        }
    else
        {
        printf("teste 5;failed\n");
        }
    
    //case 6
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
    
    //case 7
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