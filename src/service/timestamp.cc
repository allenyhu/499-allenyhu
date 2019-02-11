#include "timestamp.h"

Timestamp::Timestamp() {
  timeval t;
  gettimeofday(&t, nullptr);
  seconds_ = t.tv_sec;
  useconds_ = t.tv_usec;
}

int Timestamp::seconds() {
  return seconds_;
}

int Timestamp::useconds() {
  return useconds_;
}
