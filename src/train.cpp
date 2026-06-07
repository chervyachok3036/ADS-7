#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

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
  if (!first) return 0;
  countOp = 0;
  Car* cur = first;

  while (cur->light) {
    cur->light = false;
    cur = cur->next;
    const Car* tmp = first;
    while (tmp != cur) {
      ++countOp;
      tmp = tmp->next;
      ++countOp;
    }
  }

  int len = 0;
  cur = first;
  while (!cur->light) {
    cur->light = true;
    ++countOp;
    cur = cur->next;
    ++countOp;
    ++len;
  }

  return len;
}

int Train::getOpCount() {
  return countOp;
}
