#ifndef PVDSYSTEM_H
#define PVDSYSTEM_H

class Canvas;

class PVDSystem
{
public:
    PVDSystem();

    Canvas *getCanvas() const;

private:
    Canvas *canvas = nullptr;
};

#endif // PVDSYSTEM_H
