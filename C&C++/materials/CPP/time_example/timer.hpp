#pragma once

#include <chrono>

namespace s21 {

class timer_ {
  using clock = std::chrono::steady_clock;

 public:
  static constexpr int MAX_SPEED = 9;  // from 0 to 9 - 10 speeds
 private:
  static constexpr size_t SPEED_TO_INTERVAL[10] = {500, 450, 400, 375, 350,
                                                  325, 300, 250, 200, 100};

  clock::time_point last_update;

  int speed = 0;

 public:
  timer_();

  void setSpeed(size_t speed);
  void updateSpeed();
  int getSpeed() const;
  size_t getMovesNumber();
  void reset();
  void totalReset();
};

}  // namespace s21