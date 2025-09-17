#include "globals.h"

Font mechaFont{};

std::mt19937 rng(std::random_device{}());

TimerManager timerManager{};

int gameWidth{640};
int gameHeight{640};