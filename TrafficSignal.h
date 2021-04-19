#include<stdlib.h>
#include<iostream>
#include<map>
#include<chrono>
#include<thread>

class TrafficSignal
{
     std::map<char,int> Direction;
     bool flag;
     int time;
     int Greensignaltime;
     int Redsignaltime;
     int Ambersignaltime;
   public:
           TrafficSignal();
          ~TrafficSignal();
           void Reset();
           void State();
           void Pause();
           void Open();
           void Wait(int time);
};
