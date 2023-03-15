
#ifndef SYS_H
#define SYS_H

#include <windows.h>

// graphics type
#define CONSOLE   1
#define OPENGL    0

// simulation type
#define SIM  1
#define GAME 0

// function prototypes
c_Simulation& sys_init(c_Simulation& SimulationObject);
void sys_run(void);

void parse_setup_file(c_Simulation& SimulationObject);


// simulation class
class c_Simulation
{
  public:
    int i_SimType;

    // domain class
    class c_Domain
    {
      public:
        int i_Dur;
        int i_DimX;
        float f_Ex[];
        float f_Bx[];
    };

    // source class
    class c_Source
    {
      public:
        float f_X;
        float f_Vx;
        float f_Ax;
        float f_Q;
        float f_M;
        float f_Ex;
        float f_Bx;
        float f_Fx;
    };
};

#endif
