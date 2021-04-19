
#include"TrafficSignal.h"
#include<chrono>

TrafficSignal::TrafficSignal()
{
    Greensignaltime=8;
    Redsignaltime=2;
    Ambersignaltime=2;
    flag=true;
    Reset();
}

TrafficSignal::~TrafficSignal()
{

}
void TrafficSignal::Reset()
{
    std::cout<<"All stop phase active \n"<<std::endl;
    Direction['N']=0;
    Direction['S']=0;
    Direction['E']=0;
    Direction['W']=0;
    State();
    Wait(Redsignaltime);

}

void TrafficSignal::State()
{
    for (auto i = Direction.begin(); i != Direction.end(); i++)
    {
        if(i->second==0)
            std::cout<<i->first<< " IS RED "<<std::endl;
        else if(i->second==1)
            std::cout<<i->first<< " IS GREEN "<<std::endl;
        else
            std::cout<<i->first<< " IS AMBER "<<std::endl;
    }
    std::cout<<"\n";

}

void TrafficSignal::Pause()
{
    std::cout<<"Amber signal active \n"<<std::endl;
    for (auto i = Direction.begin(); i != Direction.end(); i++)
    {
       if(i->second==1)
           Direction[i->first]=2;
    }
    State();
    Wait(Ambersignaltime);
    Reset();

}

void TrafficSignal::Open()
{

   std::cout<<"Green signal active for ";
   if(flag)
   {
      Direction['N']=1;
      Direction['S']=1;
      flag=false;
      std::cout<<"Road 1\n"<<std::endl;
   }
   else
   {
      Direction['E']=1;
      Direction['W']=1;
      flag=true;
      std::cout<<"Road 2\n"<<std::endl;
   }
   State();
   Wait(Greensignaltime);

}

void TrafficSignal::Wait(int time)
{
  while(time-->0)
  {
    std::cout<<"Waiting for "<<time+1<<" Seconds...\n"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

}
