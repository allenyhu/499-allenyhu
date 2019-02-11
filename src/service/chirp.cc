#include "chirp.h"

Chirp::Chirp(const std::string& uname, const std::string& text, const std::optional<std::string>& parent_id) : 
             username_(uname), text_(text), time_() {
  parent_id_ = parent_id.value_or("");
  id_ = std::to_string(time_.seconds()) + "-" + std::to_string(time_.useconds()) + "-" + username_;
}

std::string Chirp::username() {
  return username_;
}

std::string Chirp::text() {
  return text_;
}

std::string Chirp::id() {
  return id_;
}

std::string Chirp::parent_id() {
  return parent_id_;
}

Timestamp Chirp::time() {
  return time_;
}
