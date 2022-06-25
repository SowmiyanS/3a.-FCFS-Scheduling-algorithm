#include <stdio.h>
#define SIZE 20
/*
Get No of processes 
Get their arrival time and burst time
calculate Turnaround time and Waiting time
Turnaround time = completion time - arrival time
Waiting time = turnaround time - burst time
Display
SIMPLE ;)
*/
//I want this program to be broken into lot of functions
//So There will be a main function and FCFS

float FCFS(int,float[],float[]);
void C_Time(int,float[],float[]);
void Display(int,float[],float[],float,float);
float Completion_Time[SIZE];
int main(void)
{
  float Arrival_Time[SIZE],Burst_Time[SIZE];
  int no_processes;
  printf("Enter the no. of processes : ");
  scanf("%d",&no_processes);
  for(int i = 0;i < no_processes;i++)
  {
    printf("Enter the Arrival time of process no. %d : ",i+1);
    scanf("%f",&Arrival_Time[i]);
    printf("Enter the Burst time of process no. %d : ",i+1);
    scanf("%f",&Burst_Time[i]);
  }
  //Calling the FCFS function
  FCFS(no_processes,Arrival_Time,Burst_Time);
  return 0;
}

float FCFS(int no_processes,float Arrival_Time[],float Burst_Time[])
{
  float Turnaround_Time[SIZE];
  float Waiting_time[SIZE];
  float Average_Turnaround_Time;
  float Average_Waiting_Time;
  C_Time(no_processes,Arrival_Time,Burst_Time);
  for(int i = 0;i < no_processes;i++)
  {
    Turnaround_Time[i] = fabs(Completion_Time[i] - Arrival_Time[i]);
    Waiting_time[i] = fabs(Turnaround_Time[i] - Burst_Time[i]);
    //Calculating Average Turnaround and waiing Time
    Average_Turnaround_Time = Average_Turnaround_Time + Turnaround_Time[i];
    Average_Waiting_Time = Average_Waiting_Time + Waiting_time[i];
  }
  Average_Turnaround_Time = Average_Turnaround_Time / no_processes;
  Average_Waiting_Time = Average_Waiting_Time / no_processes;
    Display(no_processes,Turnaround_Time,Waiting_time,Average_Turnaround_Time,Average_Waiting_Time);
}

void C_Time(int no_processes,float Arrival_Time[],float Burst_Time[])
{
  float Completion_Time[SIZE];
  Completion_Time[0] = Burst_Time[0];
  for(int i = 1;i < no_processes;i++)
  {
    Completion_Time[i] = Completion_Time[i-1];
    for(int j = 0;j < no_processes;j++)
    {
      if(Arrival_Time[i] > Arrival_Time[j])
      {
        Completion_Time[i] = fabs(Completion_Time[i] + Burst_Time[j]);
      }
    }
    if(Arrival_Time[i] > Completion_Time[i-1])
    {
      Completion_Time[i] = fabs(Completion_Time[i] + (Completion_Time[i] - Arrival_Time[i]));
    }
  }
}

void Display(int no_processes,float Turnaround_Time[],float Waiting_Time[],float Average_Turnaround_Time,float Average_Waiting_Time)
{
  printf("Process\tWaiting Time\tTurnaround Time\n");
  for(int i = 0;i < no_processes;i++)
  {
    printf("   %d   \t    %f    \t     %f     \n",i+1,Waiting_Time[i],Turnaround_Time[i]);
  }
  printf("The Average Waiting Time : %d\n",Average_Waiting_Time);
  printf("The Average Turnaround Time : %d\n",Average_Turnaround_Time);
}






