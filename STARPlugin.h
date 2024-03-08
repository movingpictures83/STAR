#ifndef STARPLUGIN_H
#define STARPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include "Tool.h"
#include <string>

class STARPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "STAR";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
