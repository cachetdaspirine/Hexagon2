#include "Header.h"


extern "C"
{
  void* CreateSystem(int* array, int LX, int LY)
  {
    return new(std::nothrow) System(array,LX,LY);
  }
  void DeleteSystem(void* ptr)
  {
    System* system = reinterpret_cast<System* >(ptr);    
    delete system;
  }
  void UpdateSystemEnergy(void* ptr,int* array, int LX, int LY)
  {
    try
      {
    	System* system = reinterpret_cast<System* >(ptr);
	system->UpdateEnergy(array,LX,LY);
      }
    catch(int e){cout<<"Error "<<e<<"\n";}
  }
  void SetElasticConstant(double Kmain, double Kcoupling, void* ptr)
  {
    try
      {
	System* system = reinterpret_cast<System* >(ptr);
	system->K1=Kmain;
	system->K2=Kcoupling;
      }
    catch(int e){cout<<"Error "<<e<<"\n";}
  }
  double GetSystemEnergy(void* ptr)
  {
    try
      {
	System* system = reinterpret_cast<System *>(ptr);
	return system->get_Energy();
      }
    catch(int e)
      {cout<<"Error "<<e<<"\n";}
  }
  void OutputSystemSite(void* ptr, char* filename)
  {
    try
      {
	System* system = reinterpret_cast<System *>(ptr);
	system->OutputSite(filename);
      }
    catch(int e){cout<<"error : "<<e<<"\n";}
  }
  void OutputSystemSpring(void* ptr, char* filename)
  {
    try
      {
	System* system = reinterpret_cast<System *>(ptr);
	system->OutputSpring(filename);
      }
    catch(int e){cout<<"error : "<<e<<"\n";}
  }
}
