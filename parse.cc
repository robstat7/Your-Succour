#include"header.hpp"
void parse()
{
    fstream fraw(".rawdata.dat",ios::in|ios::out);
    ofstream fp(".data.dat");
    char word[10000];
    fraw.seekg(5500,ios::beg);

    while(!fraw.eof())
    {
	fraw.getline(word,10000);
	if(word[62]=='s' && word[63]=='=')
	{
	    int i=64;
	    while(word[i]!='@')
		fp<<word[i++];

	    fp<<'\n';
	}
    }

    fraw.close();
    fp.close();
}
