#include "Header.h"

using namespace std;

Site::Site(int i, int j)
{
  I=i;
  J=j;
  Ineigh=ISiteAdjacency(I,J);
  Jneigh=JSiteAdjacency(I,J);
  
}

vector<int> Site::g_nodes_to_create() const
{
  return g_nodes_from_site(I,J);
}

int Site::g_I() const{return I;}
int Site::g_J() const{return J;}