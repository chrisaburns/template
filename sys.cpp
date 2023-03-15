
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "sys.h"
#include "graphics.h"
#include "app.h"

c_Simulation& sys_init()
{
  // read user file for simulation setup details
  parse_setup_file();

  // instantiate simulation, domain, and source classes


  // initialize graphics (console, openGL, etc.)
  std::cout << std::endl;
  std::cout<< "Initializing graphics... ";
  #if CONSOLE
    console_init();
  #elif OPENGL
    openGL_init();
  #endif

  // initialize application (ESS, MSS, etc.)
  std::cout << "Initializing application... ";
  #if SIM
    sim_init();
  #elif GAME
    game_init();
  #endif

  return o_Sim1;
}


void sys_run()
{
  // run application
  std::cout << "Preparing application... ";
  #if SIM
    sim_run();
  #elif GAME
    game_run();
  #endif
}


void parse_setup_file(c_Simulation& SimulationObject)
{
  int sim_type = 0;
  std::string data[9];
  std::ifstream setupfile("setup.txt");
  if(setupfile.is_open())
  {
    for(int i = 0; i < 9; i++)
    {
      setupfile >> data[i];
    }
    setupfile.close();
  }
  else
  {
      std::cout << std::endl;
      std::cout << "User setup unavailable. ";
      std::cout << " Does setup.txt exist?" << std::endl;
  }

  // parse user data and set up simulation parameters
  if(data[0] == "ess")
  {
    o_Sim1.i_SimType = 1;
  }
  else if(data[0] == "mss")
  {
    o_Sim1.i_SimType = 2;
  }
  else if(data[0] == "eds")
  {
    o_Sim1.i_SimType = 3;
  }
}
