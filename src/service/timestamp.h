#include <sys/time.h>

class Timestamp {
 public:
  // Default constructor for Timestamp
  Timestamp();
  
  // Getter for 'seconds_'
  int seconds();

  // Getter for 'useconds_'
  int useconds();

 private:
  int seconds_;
  int useconds_;
};
