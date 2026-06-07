// Copyright 2022 NNTU-CS
#include "train.h"

Train::Train() : count_op_(0), first_(nullptr) {}

void Train::addCar(bool light) {
  Car* car = new Car;
  car->light = light;
  if (!first_) {
    car->next = car;
    car->prev = car;
    first_ = car;
  } else {
    Car* last = first_->prev;
    car->next = first_;
    car->prev = last;
    last->next = car;
    first_->prev = car;
  }
}

int Train::getLength() {
  if (!first_) return 0;
  count_op_ = 0;
  Car* cur = first_;
  while (cur->light) {
    cur->light = false;
    cur = cur->next;
    const Car* tmp = first_;
    while (tmp != cur) {
      ++count_op_;
      tmp = tmp->next;
      ++count_op_;
    }
  }
  int len = 0;
  cur = first_;
  while (!cur->light) {
    cur->light = true;
    ++count_op_;
    cur = cur->next;
    ++count_op_;
    ++len;
  }
  return len;
}

int Train::getOpCount() const {
  return count_op_;
}
