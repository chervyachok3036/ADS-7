// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
  Train train;
  int count = 60; // кол-во вагонов
  while (count--)
    train.addCar(false);

  if (train.getLength() != 60) {
    return 0;
  }
  std::ofstream fout("data.txt");
  std::srand(std::time(nullptr));

  for (int n = 10; n <= 500; n += 10) {
    Train offT, onT, rndT;
    for (int i = 0; i < n; i++) {
      offT.addCar(false);
    }
    for (int i = 0; i < n; i++) {
      onT.addCar(true);
    }
    for (int i = 0; i < n; i++) {
      rndT.addCar(std::rand() % 2);
    }
    offT.getLength();
    onT.getLength();
    rndT.getLength();

    fout << n << " "
      << offT.getOpCount() << " "
      << onT.getOpCount() << " "
      << rndT.getOpCount() << "\n";

    std::cout << n << std::endl;
  }

  fout.close();
  return 0;
}
