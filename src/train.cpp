// Copyright 2022 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCar(bool light) {
  Car* car = new Car;
  car->light = light;
  if (!first) {
    car->next = car;
    car->prev = car;
    first = car;
  } else {
    Car* last = first->prev;
    car->next = first;
    car->prev = last;
    last->next = car;
    first->prev = car;
  }
}

int Train::getLength() {
  if (!first) {
    return 0;
  }
  countOp = 0;
  int len = 1;
  Car* cur = first;
  countOp++;
  while (cur->next != first) {
    cur = cur->next;
    countOp++;
    countOp++;
    ++len;
  }
  countOp++;
  return len;
}

int Train::getOpCount() {
  return countOp;
}
