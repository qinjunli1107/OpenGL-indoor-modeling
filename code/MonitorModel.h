#ifndef MonitorModel_h
#define MonitorModel_h

#include <stdio.h>
#include "ObjModel.h"


class MonitorModel:public ObjModel {
private:
    bool playing = false;
    
public:
    void    setVideo(string mtl, int nFrame, string pic);
    void    play(){ playing = true; }
    void    pause(){ playing = false; }
    void    draw();
};

#endif 
