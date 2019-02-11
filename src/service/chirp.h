#include <optional>
#include <string>

#include "timestamp.h"

// Wrapper object for Chirp message
class Chirp {
 public:
  // Default constructor for Chirp object, used on failure
  Chirp();

  // Constructor for Chirp object
  Chirp(const std::string& uname, const std::string& text, const std::optional<std::string>& parent_id);
  
  // Getter for `username_`
  std::string username();

  // Getter for `text_`
  std::string text();

  // Getter for `id_`
  std::string id();

  // Getter for `parent_id`
  std::string parent_id();

  // Getter for `time_`
  Timestamp time();

  // Helper method to convert Chirp into a string for GRPC transfer
  std::string to_string();

 private:
   std::string username_;
   std::string text_;
   std::string id_;
   std::string parent_id_;
   Timestamp time_;
};
