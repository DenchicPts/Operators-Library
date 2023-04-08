#pragma once

#include <iostream>
#include <type_traits>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "OperVector.h"
#include "OperSet.h"
#include "OperMap.h"

using namespace std;

map<string, int> wordCounter(ifstream& file, string& punctuation);